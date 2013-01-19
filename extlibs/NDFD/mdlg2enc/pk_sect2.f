      SUBROUTINE PK_SECT2(KFILDO,IPACK,ND5,RDAT,NRDAT,IDAT,NIDAT,
     1                    L3264B,LOCN,IPOS,EXISTS,IER,ISEVERE,*) 
C
C        FEBRUARY 2001   LAWRENCE    GSC/MDL      ORIGINAL CODING
C        NOVEMBER 2001   GLAHN   REARRANGED DIMENSIONS
C        JANUARY  2002   GLAHN   CHANGED INT( ) TO NINT( ) 
C
C        PURPOSE
C            PACKS SECTION 2, THE LOCAL USE SECTION, OF A GRIB2
C            MESSAGE.  SECTION 2 IS OPTIONAL. 
C
C            THIS ROUTINE ALLOWS THE USER TO PACK INTEGER
C            AND/OR FLOATING POINT GROUPS OF LOCAL USE DATA
C            INTO SECTION 2 OF THE GRIB2 MESSAGE.  EACH GROUP OF
C            DATA IS PACKED INTO SECTION 2 USING THE SIMPLE PACKING
C            METHOD.  THE USER MUST SPECIFY THE DECIMAL SCALE FACTOR
C            TO USE IN PACKING EACH GROUP OF DATA.  FOR SIMPLICITY,
C            THE BINARY SCALE FACTOR IS NOT USED WHEN PACKING DATA
C            INTO THE LOCAL USE SECTION.
C
C            THE FLOATING POINT LOCAL USE SECTION DATA TO BE PACKED
C            INTO THE GRIB2 MESSAGE IS PASSED INTO THIS ROUTINE
C            THROUGH THE RDAT( ) ARRAY CALLING ARGUMENT.  LIKEWISE,
C            THE INTEGER LOCAL USE SECTION DATA IS PASSED INTO THIS
C            ROUTINE THROUGH THE IDAT( ) ARRAY CALLING ARGUMENT. 
C            EACH GROUP OF LOCAL USE DATA STORED INTO THE RDAT( )
C            AND IDAT( ) ARRAYS MUST BE PRECEDED BY THE NUMBER OF 
C            VALUES IT CONTAINS AND THE DECIMAL SCALE FACTOR TO USE
C            IN PACKING THE GROUP'S DATA.  THE END OF THE LOCAL USE
C            DATA IN THE RDAT( ) AND IDAT( ) ARRAYS IS SIGNALED BY
C            PLACING A VALUE OF "0" IN THE ARRAY ELEMENT IMMEDIATELY
C            FOLLOWING THE LAST DATA VALUE OF THE LAST GROUP OF LOCAL
C            USE DATA.  THE DATA IN THE RDAT( ) AND IDAT( ) ARRAYS
C            MUST BE ARRANGED BY THE CALLER OF THIS ROUTINE AS
C            FOLLOWS:
C
C            FOR 1 TO K GROUPS OF DATA: 
C
C            RDAT(1)        = NUMBER OF VALUES IN THE FIRST GROUP
C                             OF LOCAL USE DATA (N1)
C            RDAT(2)        = THE DECIMAL SCALE FACTOR TO USE IN
C                             PACKING THE FIRST GROUP OF LOCAL USE
C                             DATA (MUST BE A WHOLE NUMBER)
C            RDAT(3)
C            -RDAT(N1+2)    = FIRST GROUP OF LOCAL USE DATA VALUES
C            RDAT(N1+3))    = NUMBER OF VALUES IN THE SECOND GROUP OF
C                             LOCAL USE DATA (N2)
C            RDAT(N1+4)     = THE DECIMAL SCALE FACTOR TO USE IN PACKING
C                             THE SECOND GROUP OF LOCAL USE DATA (MUST 
C                             BE A WHOLE NUMBER)
C            RDAT(N1+5)
C            -RDAT(N1+N2+4) = SECOND GROUP OF LOCAL USE DATA
C                             VALUES 
C
C                               ........
C
C            RDAT((K-1)*2+1+N1+N2+...+N(k-1))  = NUMBER OF VALUES IN
C                                                THE Kth GROUP OF DATA
C                                                (Nk)
C            RDAT((K-1)*2+2+N1+N2+...+N(k-1))  = THE DECIMAL SCALE
C                                                FACTOR TO USE IN
C                                                PACKING THE Kth GROUP
C                                                OF DATA 
C            RDAT((K-1)*2+3+N1+N2+...+N(k-1)) - 
C            RDAT((K-1)*2+N1+N2+...+N(k-1)+Nk) = THE NUMBER OF
C                                                VALUES IN THE Kth
C                                                GROUP OF DATA   
C            RDAT((K-1)*2+1+N1+N2+...+Nk)      = 0  NO MORE DATA
C
C            IF THE CALLER IS NOT SUPPLYING ANY LOCAL USE 
C            DATA TO PACK INTO THE GRIB2 MESSAGE, THEN HE MUST 
C            MAKE SURE THAT RDAT(1) AND IDAT(1) ARE BOTH EQUAL 
C            TO "0".  IN THAT CASE, A SECTION 2 WILL NOT BE PACKED
C            INTO THE GRIB2 MESSAGE.
C
C            THE LOCAL USE DATA IS PACKED INTO THE MESSAGE USING THE
C            FOLLOWING FORMAT:
C
C            SECTION 2 OCTET(S)   DESCRIPTION
C            1-4                  TOTAL LENGTH OF SECTION 2
C            5                    SECTION NUMBER (2)
C            6                    SECTION 2 FORMAT VERSION NUMBER
C                                 THE CURRENT VERSION IS 1.
C            7-8                  TOTAL NUMBER OF DATA GROUPS IN
C                                 THE LOCAL USE SECTION (N)
C            9-12                 NUMBER OF VALUES IN FIRST
C                                 GROUP OF LOCAL USE DATA (N1) 
C            13-16                REFERENCE VALUE OF FIRST GROUP OF
C                                 DATA 
C            17-18                DECIMAL SCALE FACTOR
C            19                   NUMBER OF BITS TO PACK EACH VALUE
C                                 OF THE FIRST GROUP OF DATA WITH
C            20                   TYPE OF DATA IN FIRST GROUP
C                                 ("0" = FLOATING POINT, "1" =
C                                 INTEGER)
C            21-NN                THE FIRST GROUP OF DATA PACKED
C                                 USING THE SIMPLE PACKING METHOD
C            (NN+1)-(NN+4)        THE NUMBER OF VALUES IN THE SECOND
C                                 GROUP OF DATA
C            (NN+5)-(NN+8)        THE REFERENCE VALUE OF THE SECOND
C                                 GROUP OF DATA
C            (NN+9)-(NN+10)       THE DECIMAL SCALE FACTOR OF THE
C                                 SECOND GROUP OF DATA
C            (NN+11)              THE NUMBER OF BITS TO PACK EACH VALUE
C                                 OF THE SECOND GROUP OF DATA WITH
C            (NN+12)              TYPE OF DATA IN THE SECOND GROUP
C                                 ("0" = FLOATING POINT, "1" = 
C                                 INTEGER)
C            (NN+13) - MM         THE SECOND GROUP OF DATA PACKED
C                                 USING THE SIMPLE PACKING METHOD
C       
C            THIS PATTERN REPEATS ITSELF FOR EACH OF THE N GROUPS 
C            OF LOCAL USE DATA SPECIFIED IN OCTETS 7-8 OF THIS 
C            SECTION.
C
C        DATA SET USE
C           KFILDO - UNIT NUMBER FOR OUTPUT (PRINT) FILE.  (OUTPUT)
C
C        VARIABLES
C              KFILDO = UNIT NUMBER FOR OUTPUT (PRINT) FILE.  (INPUT)
C            IPACK(J) = THE ARRAY THAT HOLDS THE ACTUAL PACKED 
C                       MESSAGE (J=1,ND5).  (INPUT/OUTPUT)
C                 ND5 = THE SIZE OF THE ARRAY IPACK( ).  (INPUT)
C             RDAT(J) = THE ARRAY CONTAINING THE LOCAL USE GROUPS
C                       CONSISTING OF FLOATING POINT DATA (J=1,NRDAT).
C                       (INPUT)
C               NRDAT = THE DIMENSION OF THE RDAT( ) ARRAY.  (INPUT)
C             IDAT(J) = THE ARRAY CONTAINING THE LOCAL USE GROUPS
C                       CONSISTING OF INTEGER DATA (J=1,NIDAT).
C                       (INPUT)
C               NIDAT = THE DIMENSION OF THE IDAT( ) ARRAY.  (INPUT)
C              L3264B = THE INTEGER WORD LENGTH IN BITS OF THE
C                       MACHINE BEING USED.  VALUES OF 32 AND 64 ARE
C                       ACCOMODATED.  (INPUT)
C                LOCN = THE WORD POSITION TO PLACE THE NEXT VALUE.
C                       (INPUT/OUTPUT)
C                IPOS = THE BIT POSITION IN LOCN TO START PLACING
C                       THE NEXT VALUE.  (INPUT/OUTPUT)
C              EXISTS = INDICATES TO THE CALLING ROUTINE WHETHER OR NOT
C                       SECTION 2 EXISTS (LOGICAL).  (OUTPUT)
C                 IER = RETURN STATUS CODE. (OUTPUT)
C                        0 = GOOD RETURN.
C                      1-4 = ERROR CODES GENERATED BY PKBG. SEE THE
C                            DOCUMENTATION IN THE PKBG ROUTINE.
C                      5,6 = ERROR CODES GENERATED BY LENGTH FUNCTION.
C                            SEE THE DOCUMENTATION FOR THE LENGTH
C                            FUNCTION.
C                      202 = THE IDAT( ) OR RDAT( ) ARRAY WAS NOT
C                            DIMENSIONED LARGE ENOUGH TO CONTAIN
C                            THE LOCAL USE DATA. 
C             ISEVERE = THE SEVERITY LEVEL OF THE ERROR.  THE ONLY
C                       VALUE RETUNED IS:
C                       2 = A FATAL ERROR  (OUTPUT)
C                   * = ALTERNATE ERROR RETURN.
C
C             LOCAL VARIABLES
C                IBIT = THE NUMBER OF BITS REQUIRED TO PACK EACH 
C                       VALUE IN ONE LOCAL DATA GROUP USING THE
C                       SIMPLE PACKING METHOD.
C                  ID = THE DECIMAL SCALE FACTOR FOR ONE LOCAL
C                       DATA GROUP.  THIS IS SPECIFIED BY THE USER
C                       FOR EACH GROUP IN THE IDAT( ) AND RDAT( )
C                       ARRAYS. 
C              IGROUP = KEEPS A COUNT OF THE NUMBER OF GROUPS OF 
C                       LOCAL USE DATA PACKED INTO SECTION 2 OF THE
C                       GRIB2 MESSAGE.
C               INDEX = USED TO KEEP TRACK OF WHICH DATA VALUE IS
C                       CURRENTLY BEING PROCESSED IN THE IDAT( )
C                       OR RDAT( ) ARRAY. 
C              INTDAT = FLAG INDICATING IF THERE ARE ANY LOCAL INTEGER 
C                       DATA GROUPS TO BE PACKED.  (LOGICAL) 
C             IPOS2_1 = SAVES THE BIT POSITION IN LOCN2_1 TO STORE THE  
C                       LENGTH OF SECTION 2.
C             IPOS2_7 = SAVES THE BIT POSITION IN LOCN2_7 TO STORE THE
C                       TOTAL NUMBER OF LOCAL USE DATA GROUPS PACKED
C                       INTO SECTION 2.
C            IPOS2_19 = SAVES THE BIT POSITION IN LOCN2_19 TO STORE THE
C                       NUMBER OF BITS REQUIRED TO PACK EACH VALUE OF
C                       A LOCAL USE DATA GROUP.
C            ITEMP(J) = ARRAY TO CONTAIN A LOCAL USE DATA GROUP
C                       CONSISTING OF INTEGER VALUES.  THIS ARRAY IS
C                       USED TO PASS THE DATA TO THE SIMPLE PACKING
C                       ROUTINE (J=1,NIDAT).   
C              IVALUE = THIS IS EQUIVALENCED TO RVALUE.  IT IS USED TO
C                       PACK THE BIT PATTERN OF A FLOATING POINT 
C                       VALUE INTO THE GRIB2 MESSAGE.
C            IVERSION = THE VERSION NUMBER OF THE SECTION 2 FORMAT.
C                       THIS ROUTINE IS DESIGNED TO PACK VERSION 1.
C               IZERO = CONTAINS A VALUE OF "0" TO BE PACKED INTO THE
C                       GRIB2 MESSAGE.
C                  IX = THIS IS A LOOP INDEXING VARIABLE.
C             LOCN2_1 = SAVES THE WORD POSITION IN IPACK TO STORE
C                       THE LENGTH OF SECTION 2. 
C             LOCN2_7 = SAVES THE WORD POSITION IN IPACK TO STORE
C                       THE TOTAL NUMBER OF LOCAL USE DATA GROUPS
C                       PACKED INTO SECTION 2. 
C            LOCN2_19 = SAVES THE WORD POSITION IN IPACK TO STORE THE
C                       NUMBER OF BITS REQUIRED TO PACK EACH VALUE
C                       OF A LOCAL USE DATA GROUP.
C                MINA = THE MINIMUM VALUE OF A GROUP OF INTEGER LOCAL
C                       USE DATA. 
C                   N = A SHORT-HAND REPRESENTATION OF L3264B.
C             REALDAT = A FLAG INDICATING IF THERE ARE ANY LOCAL
C                       USE DATA GROUPS OF FLOATING POINT VALUES
C                       TO PACK.  (LOGICAL) 
C               RMINA = THE MINIMUM VALUE OF A GROUP OF FLOATING 
C                       POINT LOCAL USE DATA.
C            RTEMP(J) = AN ARRAY TO TEMPORARILY CONTAIN ONE LOCAL USE
C                       GROUP OF FLOATING POINT DATA (J=1,NRDAT). 
C              RVALUE = THIS IS EQUIVALENCED TO IVALUE.  IT IS USED
C                       TO PACK THE BIT PATTERN OF A FLOATING POINT
C                       VALUE INTO THE GRIB2 MESSAGE. 
C
C        NON SYSTEM SUBROUTINES CALLED
C           LENGTH,PKBG,PK_SMPLE,PREP_SECT2_INT,PREP_SECT2_REAL
C           
C
      LOGICAL EXISTS,INTDAT,REALDAT
C
      DIMENSION IDAT(NIDAT),RDAT(NRDAT)
      DIMENSION IPACK(ND5)
C      DIMENSION ITEMP(NIDAT),RTEMP(NRDAT)
      DIMENSION ITEMP(100000),RTEMP(100000)
C        ITEMP( ) AND RTEMP( ) ARE AUTOMATIC ARRAYS.
C
      DATA IVERSION/1/
      DATA IZERO/0/
C
      EQUIVALENCE(RVALUE,IVALUE)
C
      EXISTS=.FALSE.
      INTDAT=.FALSE.
      REALDAT=.FALSE.
C
      N=L3264B
      IER=0
      IGROUP=0
C
C        ALL ERRORS GENERATED BY THIS ROUTINE ARE FATAL.
      ISEVERE=2
C
C        CHECK TO DETERMINE IF DATA EXISTS FOR THIS SECTION.
      IF(IDAT(1).NE.0)INTDAT=.TRUE.
      IF(RDAT(1).NE.0)REALDAT=.TRUE.
C
      IF(INTDAT.OR.REALDAT)THEN
C
C           THERE IS LOCAL USE DATA TO BE PACKED INTO THE LOCAL
C           USE SECTION OF THE GRIB2 MESSAGE.
         EXISTS=.TRUE.
C
C           BYTES 1-4 OF SECTION 2 MUST BE FILLED IN LATER WITH
C           THE RECORD LENGTH IN BYTES.  LOC2_1 AND IPOS2_1 HOLD THE
C           LOCATION. 
         LOCN2_1=LOCN
         IPOS2_1=IPOS
         CALL PKBG(KFILDO,IPACK,ND5,LOCN,IPOS,IZERO,32,N,IER,*900)
C
C           PACK THE NUMBER OF THE SECTION.
         CALL PKBG(KFILDO,IPACK,ND5,LOCN,IPOS,2,8,N,IER,*900)
C
C           PACK THE VERSION NUMBER OF THE FORMAT OF THE LOCAL
C           USE DATA.
         CALL PKBG(KFILDO,IPACK,ND5,LOCN,IPOS,IVERSION,8,N,IER,*900)
C
C           SAVE THE POSITION OF OCTETS 7-8 OF SECTION 2.
C           THESE OCTETS WILL BE FILLED IN LATER WITH
C           THE TOTAL NUMBER OF LOCAL USE DATA GROUPS PACKED
C           INTO THIS SECTION. 
         LOCN2_7=LOCN
         IPOS2_7=IPOS
         CALL PKBG(KFILDO,IPACK,ND5,LOCN,IPOS,IZERO,16,N,IER,*900)
C
         IF(INTDAT)THEN
C
C             PACK THE INTEGER LOCAL USE DATA INTO 
C             SECTION 2 FIRST.
           ISIZE=IDAT(1)
           INDEX=1
C
           DO WHILE(ISIZE.GT.0)
C
C                HAS IDAT( ) BEEN DIMENSIONED LARGE ENOUGH?
              IF(NIDAT.LT.(ISIZE+INDEX+2))THEN
                 IER=202
                 GOTO 900
              ENDIF
C
              INDEX=INDEX+1
C
C                RETRIEVE THE DECIMAL SCALE FACTOR.
              ID=IDAT(INDEX)
              INDEX=INDEX+1
C
C                COPY THE LOCAL USE DATA INTO THE ITEMP( ) ARRAY.
              DO 10 IX=1,ISIZE
                 ITEMP(IX)=IDAT(INDEX)
                 INDEX=INDEX+1
 10           CONTINUE
C
C                PREPARE THE DATA IN THE ITEMP( ) ARRAY
C                TO BE PACKED.
              CALL PREP_SECT2_INT(ITEMP,ISIZE,0,ID,MINA)
C
C                PACK THE NUMBER OF VALUES IN THE GROUP.
              CALL PKBG(KFILDO,IPACK,ND5,LOCN,IPOS,ISIZE,32,N,IER,*900)
C
C                PACK THE REFERENCE VALUE OF THE GROUP.
              RMINA=FLOAT(MINA)
              RVALUE=FMKIEEE(RMINA)
              CALL PKBG(KFILDO,IPACK,ND5,LOCN,IPOS,IVALUE,32,N,
     1                  IER,*900)
C
C                PACK THE DECIMAL SCALE FACTOR.
              CALL PKBG(KFILDO,IPACK,ND5,LOCN,IPOS,ID,16,N,IER,*900)
C
C                SAVE THE LOCATION OF THE OCTET TO CONTAIN
C                THE NUMBER OF BITS REQUIRED TO PACK EACH 
C                VALUE OF THE GROUP OF LOCAL USE DATA.
              LOCN2_19 = LOCN
              IPOS2_19 = IPOS
              CALL PKBG(KFILDO,IPACK,ND5,LOCN,IPOS,IZERO,8,N,IER,*900)
C
C                PACK THE TYPE OF THE LOCAL USE DATA. 
              CALL PKBG(KFILDO,IPACK,ND5,LOCN,IPOS,1,8,N,IER,*900)
C
C                PACK THE DATA USING THE SIMPLE PACKING METHOD.
              CALL PK_SMPLE(KFILDO,ITEMP,ISIZE,IPACK,ND5,LOCN,IPOS,
     1                      IBIT,L3264B,IER,*900)
C
C                PACK THE NUMBER OF BITS NECESSARY TO CONTAIN THE
C                LARGEST VALUE IN THE DATA FIELD.
              CALL PKBG(KFILDO,IPACK,ND5,LOCN2_19,IPOS2_19,IBIT,8,N,
     1                  IER,*900)
C
C                INCREMENT THE NUMBER OF GROUPS AND RETRIEVE THE SIZE
C                OF THE NEXT GROUP OF LOCAL USE DATA TO BE PACKED.
              IGROUP=IGROUP+1
              ISIZE=IDAT(INDEX)
           ENDDO
         ENDIF
C
         IF(REALDAT)THEN
C
C             PACK THE FLOATING POINT LOCAL USE DATA.
           ISIZE=NINT(RDAT(1))
           INDEX=1
C
           DO WHILE(ISIZE.GT.0)
C
C                HAS RDAT( ) BEEN DIMENSIONED LARGE ENOUGH?
              IF(NRDAT.LT.(ISIZE+INDEX+2))THEN
                 IER=202
                 GOTO 900
              ENDIF
C
              INDEX=INDEX+1
C
C                RETRIEVE THE DECIMAL SCALING FACTOR.
              ID=NINT(RDAT(INDEX))
              INDEX=INDEX+1
C
C                COPY THE DATA INTO THE RTEMP( ) ARRAY.
              DO 20 IX=1,ISIZE
                 RTEMP(IX)=RDAT(INDEX)
                 INDEX=INDEX+1
 20           CONTINUE
C
C                PREPARE THE DATA IN THE RTEMP( ) ARRAY.  THE
C                SCALED DATA IS RETURNED IN THE INTEGER ARRAY
C                ITEMP( ).  
              CALL PREP_SECT2_REAL(RTEMP,ITEMP,ISIZE,0,ID,RMINA)
C
C                PACK THE NUMBER OF VALUES IN THE GROUP.
              CALL PKBG(KFILDO,IPACK,ND5,LOCN,IPOS,ISIZE,32,N,IER,*900)
C
C                PACK THE REFERENCE VALUE OF THE GROUP.
              RVALUE=FMKIEEE(RMINA)
              CALL PKBG(KFILDO,IPACK,ND5,LOCN,IPOS,IVALUE,32,N,
     1                  IER,*900)
C
C                PACK THE DECIMAL SCALE FACTOR.
              CALL PKBG(KFILDO,IPACK,ND5,LOCN,IPOS,ID,16,N,IER,*900)
C 
C                SAVE THE LOCATION OF THE OCTET TO CONTAIN
C                THE NUMBER OF BITS REQUIRED TO PACK EACH 
C                VALUE OF THE GROUP OF LOCAL USE DATA.
              LOCN2_19 = LOCN
              IPOS2_19 = IPOS
              CALL PKBG(KFILDO,IPACK,ND5,LOCN,IPOS,IZERO,8,N,IER,*900)
C
C                PACK THE TYPE OF THE LOCAL USE DATA. 
              CALL PKBG(KFILDO,IPACK,ND5,LOCN,IPOS,0,8,N,IER,*900)
C
C                PACK THE DATA USING THE SIMPLE PACKING METHOD.
              CALL PK_SMPLE(KFILDO,ITEMP,ISIZE,IPACK,ND5,LOCN,IPOS,
     1                      IBIT,L3264B,IER,*900)
C
C                PACK THE NUMBER OF BITS NECESSARY TO CONTAIN THE
C                LARGEST VALUE IN THE DATA FIELD.
              CALL PKBG(KFILDO,IPACK,ND5,LOCN2_19,IPOS2_19,IBIT,8,N,
     1                  IER,*900)
C
C                INCREMENT THE GROUP COUNT AND RETRIEVE THE SIZE OF
C                THE NEXT GROUP OF LOCAL USE DATA TO BE PACKED.
              IGROUP=IGROUP+1
              ISIZE=NINT(RDAT(INDEX))
C
           ENDDO
         ENDIF
C
C           PACK THE TOTAL NUMBER OF GROUPS INTO OCTETS 6-7 OF 
C           SECTION 2. 
         CALL PKBG(KFILDO,IPACK,ND5,LOCN2_7,IPOS2_7,IGROUP,16,N,
     1             IER,*900)
C
C           COMPUTE THE LENGTH OF THE SECTION AND PACK IT.  LOCN2_1 AND
C           IPOS2_1 REPRESENT THE LENGTH OF THE RECORD BEFORE
C           SECTION 2.  8 IS THE NUMBER OF BITS IN A BYTE, AND EACH
C           SECTION ENDS AT THE END OF A BYTE.
         ISIZE=LENGTH(KFILDO,IPACK,ND5,L3264B,LOCN2_1,IPOS2_1,LOCN,
     1                 IPOS,IER)
      ENDIF          
C
C        ERROR RETURN SECTION
 900  IF(IER.NE.0)RETURN 1
C
      RETURN
      END
