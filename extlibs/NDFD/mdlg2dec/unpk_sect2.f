      SUBROUTINE UNPK_SECT2(KFILDO,IPACK,ND5,IS2,NS2,RDAT,NRDAT,IDAT,
     1                      NIDAT,L3264B,LOCN,IPOS,EXISTS,IER,
     2                      ISEVERE,*)
C
C        FEBRUARY 2001   LAWRENCE   GSC/MDL  ORIGINAL CODING
C        NOVEMBER 2001   GLAHN   CHECKED IER AFTER CALL TO UNPKLXBM;
C                                MOVED ISEVERE=2 UP TO BEGINNING
C
C        PURPOSE
C            UNPACKS SECTION 2, THE LOCAL USE SECTION, OF A
C            GRIB2 MESSAGE.  SECTION 2 IS OPTIONAL.
C
C            THIS ROUTINE EXPECTS THE PACKED DATA IN SECTION 2 OF
C            THE GRIB2 MESSAGE TO HAVE THE FOLLOWING FORMAT:
C            SECTION 2 OCTET(S)   DESCRIPTION
C            1-4                  TOTAL LENGTH OF SECTION 2
C            5                    SECTION NUMBER (2)
C            6                    SECTION 2 FORMAT VERSION NUMBER
C            7-8                  TOTAL NUMBER OF DATA GROUPS IN
C                                 THE LOCAL USE SECTION (N)
C            9-12                 NUMBER OF VALUES IN FIRST
C                                 GROUP OF LOCAL USE DATA (N1)
C            13-16                REFERENCE VALUE OF FIRST GROUP OF
C                                 DATA
C            17-18                DECIMAL SCALE FACTOR
C            19                   NUMBER OF BITS USED TO PACK EACH
C                                 VALUE OF THE FIRST GROUP OF DATA
C            20                   TYPE OF DATA IN FIRST GROUP OF DATA
C                                 ("0" = FLOATING POINT, "1" =
C                                 INTEGER)
C            21-NN                THE VALUES OF THE FIRST GROUP OF
C                                 DATA PACKED USING THE SIMPLE PACKING
C                                 METHOD
C            (NN+1)-(NN+4)        THE NUMBER OF VALUES IN THE SECOND
C                                 GROUP OF DATA
C            (NN+5)-(NN+8)        THE REFERENCE VALUE OF THE SECOND
C                                 GROUP OF DATA
C            (NN+9)-(NN+10)       THE DECIMAL SCALE FACTOR OF THE
C                                 SECOND GROUP OF DATA
C            (NN+11)              THE NUMBER OF BITS USED TO PACK EACH
C                                 VALUE OF THE SECOND GROUP OF DATA
C            (NN+12)              TYPE OF DATA IN THE SECOND GROUP OF
C                                 DATA ("0" = FLOATING POINT, "1" =
C                                 INTEGER)
C            (NN+13) - MM         THE SECOND GROUP OF DATA PACKED
C                                 USING THE SIMPLE PACKING METHOD
C
C            THIS PATTERN REPEATS ITSELF FOR EACH OF THE N GROUPS
C            OF LOCAL USE DATA SPECIFIED IN OCTETS 7-8 OF THIS
C            SECTION.
C
C            THIS ROUTINE ALLOWS THE FOR THE EXISTENCE OF BOTH
C            INTEGER AND FLOATING POINT GROUPS OF LOCAL USE DATA
C            IN SECTION 2 OF THE GRIB2 MESSAGE BEING UNPACKED.  EACH
C            OF THESE GROUPS OF DATA (THE NUMBER OF WHICH IS SPECIFIED
C            BY OCTETS 6-7 OF SECTION 2) IS UNPACKED USING THE  
C            SIMPLE UNPACKING METHOD.  UNPACKED GROUPS OF INTEGER
C            LOCAL USE DATA ARE PLACED INTO THE IDAT( ) ARRAY.
C            UNPACKED GROUPS OF FLOATING POINT LOCAL USE DATA ARE
C            PLACED INTO THE RDAT( ) ARRAY.  THE UNPACKED GROUPS OF
C            LOCAL USE DATA ARE RETURNED TO THE USER IN THE IDAT( )
C            AND RDAT( ) ARRAYS USING THE FOLLOWING FORMAT:
C
C            FOR 1 TO K GROUPS OF DATA:
C
C            RDAT(1)        = NUMBER OF VALUES IN THE FIRST GROUP
C                             OF LOCAL USE DATA (N1)
C            RDAT(2)        = THE DECIMAL SCALE FACTOR USED IN
C                             UNPACKING THE FIRST GROUP OF LOCAL USE
C                             DATA.
C            RDAT(3)
C            -RDAT(N1+2)    = FIRST GROUP OF LOCAL USE DATA VALUES
C            RDAT(N1+3))    = NUMBER OF VALUES IN THE SECOND GROUP OF
C                             LOCAL USE DATA (N2)
C            RDAT(N1+4)     = THE DECIMAL SCALE FACTOR USED IN 
C                             UNPACKING THE SECOND GROUP OF LOCAL USE
C                             DATA.
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
C                                                FACTOR USED IN
C                                                UNPACKING THE Kth
C                                                GROUP OF DATA
C            RDAT((K-1)*2+3+N1+N2+...+N(k-1)) -
C            RDAT((K-1)*2+N1+N2+...+N(k-1)+Nk) = THE NUMBER OF
C                                                VALUES IN THE Kth
C                                                GROUP OF DATA
C            RDAT((K-1)*2+1+N1+N2+...+Nk)      = 0 NO MORE DATA
C
C            ALTHOUGH THE RDAT( ) ARRAY WAS USED IN THE EXAMPLE
C            ABOVE, THE SAME FORMAT APPLIES TO THE LOCAL USE DATA
C            STORED IN THE IDAT( ) ARRAY. 
C            
C            SINCE SECTION 2 IS OPTIONAL, IT IS POSSIBLE THAT
C            THERE IS NO LOCAL USE DATA PRESENT IN THE GRIB2
C            MESSAGE.  IN THE CASE WHERE THERE IS NO SECTION 2
C            PACKED IN THE MESSAGE, THE "EXISTS" CALLING 
C            ARGUMENT (SEE BELOW) WILL BE SET TO .FALSE., THE
C            VALUES OF IDAT(1) AND RDAT(1) WILL BE "0", AND THE 
C            LENGTH OF SECTION 2 SPECIFIED BY IS2(1) WILL BE
C            "0".
C
C            BEFORE THIS ROUTINE ATTEMPTS TO UNPACK THE DATA IN
C            SECTION 2, IT CHECKS TO MAKE SURE THAT THE DATA 
C            IS IN A FORMAT THAT THIS ROUTINE CAN INTERPRET.
C            IT DOES THIS BY CHECKING THE VERSION NUMBER CONTAINED
C            IN OCTET 6 OF SECTION 2.  IF THIS VERSION NUMBER IS
C            NOT "1", THEN IT RETURNS A NON-FATAL ERROR CODE OF
C            208 INDICATING THAT THERE WAS DATA IN THE LOCAL
C            USE SECTION, BUT IT WAS SKIPPED AND NOT UNPACKED.
C            
C        DATA SET USE
C           KFILDO - UNIT NUMBER FOR OUTPUT (PRINT) FILE. (OUTPUT)
C
C        VARIABLES
C              KFILDO = UNIT NUMBER FOR OUTPUT (PRINT) FILE. (INPUT)
C            IPACK(J) = THE ARRAY THAT HOLDS THE ACTUAL PACKED MESSAGE
C                       (J=1,ND5). (INPUT)
C                 ND5 = THE SIZE OF THE ARRAY IPACK( ). (INPUT)
C              IS2(J) = CONTAINS THE SIZE OF SECTION 2 IN ELEMENTS
C                       1-4, THE SECTION NUMBER "2" IN ELEMENT 5,
C                       AND THE TOTAL NUMBER OF DATA GROUPS PACKED IN
C                       SECTION 2 IN ELEMENT 6 (J=1,NS2).  (OUTPUT)
C                 NS2 = SIZE OF IS2( ). SHOULD BE AT LEAST "6". (INPUT)
C             RDAT(J) = THE ARRAY CONTAINING THE LOCAL USE GROUPS
C                       CONSISTING OF FLOATING POINT DATA UNPACKED
C                       FROM SECTION 2 (J=1,NRDAT).  (OUTPUT)
C               NRDAT = THE DIMENSION OF THE RDAT( ) ARRAY.  (INPUT)
C             IDAT(J) = THE ARRAY CONTAINING THE LOCAL USE GROUPS
C                       CONSISTING OF INTEGER DATA UNPACKED FROM 
C                       SECTION 2 (J=1,NIDAT).  (OUTPUT) 
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
C                        6-8 = ERROR CODES GENERATED BY UNPKBG AND
C                              UNPKLXBM. SEE THE DOCUMENTATION IN
C                              THE UNPKBG AND UNPKLXBM ROUTINES.
C                          9 = ERROR CODE GENERATED BY UNPKLXBM. SEE
C                              THE DOCUMENTATION IN THE UNPKLXBM
C                              ROUTINE.
C                        202 = IS2( ) HAS NOT BEEN DIMENSIONED LARGE
C                              ENOUGH TO CONTAIN THE ENTIRE TEMPLATE.
C                        204 = THE NUMBER LOCAL USE DATA GROUPS 
C                              SPECIFIED IN OCTET 6 OF SECTION 2 
C                              IS 0.
C                        206 = INVALID DATA TYPE INDICATOR VALUE
C                              IN SECTION 2.
C                        208 = THE DATA IN SECTION 2 HAS AN
C                              UNRECOGNIZED FORMAT.  IT HAS
C                              BEEN SKIPPED AND NOT UNPACKED
C                              (NON-FATAL ERROR RETURN).
C                        299 = UNEXPECTED END OF MESSAGE.
C             ISEVERE = THE SEVERITY LEVEL OF THE ERROR.
C                       1 = A WARNING.  A NON-FATAL ERROR (OUTPUT)
C                       2 = A FATAL ERROR  (OUTPUT)
C                   * = ALTERNATE ERROR RETURN.
C
C             LOCAL VARIABLES
C             IBMP(J) = THIS IS A DUMMY ARRAY USED IN PLACE OF
C                       THE BITMAP ARRAY ARGUMENT OF THE UNPKLXBM
C                       ROUTINE.  A BITMAP IS NOT USED WHILE UNPACKING
C                       LOCAL USE DATA FROM SECTION 2
C                       (J=1,NIDAT+NRDAT).
C               IFILL = CONTAINS THE NUMBER OF BITS PADDING THE
C                       END OF A PACKED GROUP OF LOCAL USE DATA
C                       FROM AN OCTET BOUNDARY.  
C              IGROUP = THE NUMBER OF GROUPS OF LOCAL USE DATA PACKED
C                       INTO SECTION 2 OF THE GRIB2 MESSAGE.
C               INDEX = A VARIABLE USED TO KEEP TRACK OF THE POSITION
C                       IN THE IDAT( ) ARRAY TO PLACE THE NEXT LOCAL
C                       USE DATA VALUE. 
C             IPOS2_1 = SAVES THE BIT POSITION IPOS IN LOCN
C                       UPON ENTRY TO STORE BACK TO IPOS IN CASE
C                       THERE IS NO SECTION 2 IN THE GRIB2 MESSAGE.
C               ISIZE = THE NUMBER OF VALUES IN THE GROUP OF LOCAL
C                       USE DATA CURRENTLY BEING UNPACKED.
C               ITYPE = THE TYPE OF THE VALUES IN THE GROUP OF
C                       LOCAL USE DATA CURRENTLY BEING UNPACKED.
C              IVALUE = EQUIVALENCED TO RVALUE.  USED TO RETRIEVE
C                       A FLOATING POINT REPRESENTATION OF A 
C                       FOUR BYTE INTEGER UNPACKED FROM THE GRIB2
C                       MESSAGE. 
C            IVERSION = THE VERSION NUMBER OF THE SECTION 2 FORMAT.
C                       THIS ROUTINE IS DESIGNED TO UNPACK VERSION
C                       1.
C                 J,K = LOOP INDEXES.
C               KNDEX = A VARIABLE USED TO KEEP TRACK OF THE POSITION
C                       IN THE RDAT( ) ARRAY TO STORE THE NEXT LOCAL
C                       USE DATA VALUE.
C             LOCN2_1 = SAVES THE WORD POSITION LOCN IN IPACK
C                       UPON ENTRY TO STORE BACK TO LOCN IN CASE
C                       THERE IS NO SECTION 2 IN THE GRIB2 MESSAGE.
C               LSECT = THE LENGTH OF SECTION 2.
C                   N = AN ALIAS FOR L3264B (SEE ABOVE).
C                NBIT = THE NUMBER OF BITS THAT WERE USED TO PACK
C                       EACH VALUE OF A LOCAL USE DATA GROUP.
C               NSECT = THE NUMBER OF THE SECTION THAT IS BEING
C                       UNPACKED.  IF THERE IS A SECTION 2 IN THIS
C                       GRIB2 MESSAGE, THEN THIS SHOULD HAVE A VALUE
C                       OF "2".
C                 REF = THE SMALLEST VALUE IN A GROUP OF LOCAL USE
C                       DATA VALUES.
C            RTEMP(J) = PROVIDES TEMPORARY STORAGE OF UNPACKED
C                       LOCAL USE DATA BEFORE IT IS COPIED INTO
C                       EITHER THE RDAT( ) OR IDAT( ) ARRAYS
C                       (J=1,NIDAT+NRDAT).
C              RVALUE = EQUIVALENCED TO IVALUE. USED TO RETRIEVE 
C                       THE FLOATING POINT REFERENCE VALUE (SEE "REF"
C                       ABOVE).
C              SCAL10 = THE DECIMAL SCALING FACTOR.
C               SCAL2 = THE BINARY SCALING FACTOR.  WHEN RETRIEVING
C                       DATA FROM SECTION 2, THIS WILL ALWAYS BE
C                       1.0 .
C
C        NON SYSTEM SUBROUTINES CALLED
C           ENDOMESS,UNPKBG,UNPKLXBM 
C
      LOGICAL ENDOMESS,EXISTS
C
      DIMENSION IDAT(NIDAT),IPACK(ND5),IS2(NS2),RDAT(NRDAT)
c      DIMENSION IBMP(NIDAT+NRDAT),RTEMP(NIDAT+NRDAT)  
      DIMENSION IBMP(100000),RTEMP(100000)  
C
      EQUIVALENCE(RVALUE,IVALUE)
      N=L3264B
      IER=0
C
C        NEARLY ALL ERRORS GENERATED BY THIS ROUTINE ARE FATAL.
      ISEVERE=2
C
C        CHECK THE SIZE OF IS2( ).  IT MUST BE AT LEAST 7 ELEMENTS
C        LARGE.  THE IS2( ) ARRAY IS ONLY USED TO RETURN THE SECTION 
C        SIZE, SECTION NUMBER, AND THE TOTAL NUMBER OF LOCAL USE
C        DATA GROUPS TO THE CALLER OF THIS ROUTINE.
      IF(NS2.LT.7)THEN
         IER=202
         GOTO 900
      ENDIF
C
      EXISTS=.TRUE.
C
      LOCN2_1=LOCN
      IPOS2_1=IPOS
C
C        UNPACK THE LENGTH OF THE SECTION.
      CALL UNPKBG(KFILDO,IPACK,ND5,LOCN,IPOS,LSECT,32,N,IER,*900)
C
C        CHECK FOR AN UNEXPECTED END OF MESSAGE.
      IF(ENDOMESS(LSECT,N))THEN
         IER=299
         GO TO 900
      ENDIF
C
C        UNPACK THE SECTION NUMBER.  CHECK TO SEE IF THIS IS
C        SECTION 2.
C
      CALL UNPKBG(KFILDO,IPACK,ND5,LOCN,IPOS,NSECT,8,N,IER,*900)
C
C        IS THIS SECTION 2?
      IF(NSECT.NE.2)THEN
         EXISTS=.FALSE.
         LOCN=LOCN2_1
         IPOS=IPOS2_1
         IS2(1)=0
         IDAT(1)=0
         RDAT(1)=0
         GO TO 900
      ENDIF
C
C        INITIALIZE THE IS2( ) ARRAY.
      DO 10 K=1,NS2
         IS2(K)=0
 10   CONTINUE
C
C        INITIALIZE THE IDAT( ) ARRAY.
      DO 20 K=1,NIDAT
         IDAT(K)=0
 20   CONTINUE      
C
C        INTIALIZE THE RDAT( ) ARRAY.
      DO 30 K=1,NRDAT
         RDAT(K)=0.
 30   CONTINUE      
C
      IS2(1)=LSECT
      IS2(5)=NSECT
C
C        UNPACK THE VERSION NUMBER OF THE SECTION 2 FORMAT.
      CALL UNPKBG(KFILDO,IPACK,ND5,LOCN,IPOS,IVERSION,8,N,IER,*900)
C
      IF(IVERSION.NE.1)THEN
         IER=208
         GOTO 910
      ENDIF
C
C        UNPACK THE TOTAL NUMBER OF LOCAL USE DATA GROUPS CONTAINED
C        WITHIN THIS PRODUCT.
      CALL UNPKBG(KFILDO,IPACK,ND5,LOCN,IPOS,IGROUP,16,N,IER,*900)
C
      IF(IGROUP.LE.0)THEN
         IER=204
         GOTO 900
      ENDIF
C
      IS2(6)=IGROUP
C
C        LOOP OVER AND UNPACK EACH GROUP OF LOCAL USE DATA
C        STORED IN SECTION 2 OF THIS GRIB2 MESSAGE.
      INDEX = 1
      KNDEX = 1
C
      DO 40 K=1,IGROUP
C
C           UNPACK THE NUMBER OF VALUES IN THE CURRENT GROUP
C           OF LOCAL USE DATA BEING RETRIEVED. 
         CALL UNPKBG(KFILDO,IPACK,ND5,LOCN,IPOS,ISIZE,32,N,IER,*900)
C
C           UNPACK THE REFERENCE VALUE OF THE CURRENT GROUP
C           OF LOCAL USE DATA BEING RETRIEVED. 
         CALL UNPKBG(KFILDO,IPACK,ND5,LOCN,IPOS,IVALUE,32,N,IER,*900)
         REF=RDIEEE(RVALUE)
C
C           UNPACK THE DECIMAL SCALE FACTOR OF THE CURRENT
C           GROUP OF LOCAL USE DATA BEING RETRIEVED.
         CALL UNPKBG(KFILDO,IPACK,ND5,LOCN,IPOS,ID,16,N,IER,*900)
C
C           UNPACK THE NUMBER OF BITS THAT WAS NEEDED TO PACK EACH
C           OF THE DATA VALUES IN THIS GROUP OF LOCAL USE DATA.
         CALL UNPKBG(KFILDO,IPACK,ND5,LOCN,IPOS,NBIT,8,N,IER,*900)
C
C           UNPACK THE TYPE OF THE VALUES CONTAINED WITHIN THIS 
C           GROUP OF LOCAL USE DATA. 
         CALL UNPKBG(KFILDO,IPACK,ND5,LOCN,IPOS,ITYPE,8,N,IER,*900)
C
C           DEPENDING ON THE TYPE OF DATA, UNPACK THE INFORMATION
C           INTO IDAT( ) OR RDAT( ).
C
         IF(ITYPE.EQ.0)THEN
C
C              FLOATING POINT DATA.  CHECK TO SEE IF RDAT( ) HAS BEEN
C              DIMENSIONED LARGE ENOUGH TO CONTAIN THE DATA IN THIS
C              GROUP PLUS ONE ADDITIONAL ELEMENT TO CONTAIN THE
C              THE SIZE OF THE NEXT DATA GROUP.
            IF(NRDAT.LT.(ISIZE+KNDEX+2))THEN
               IER=202
               GOTO 900
            ENDIF
C
            RDAT(KNDEX)=FLOAT(ISIZE)
            KNDEX=KNDEX+1
            RDAT(KNDEX)=FLOAT(ID)
            KNDEX=KNDEX+1
C
C              UNPACK THE DATA USING THE SIMPLE UNPACKING METHOD.
            SCAL10=10.**ID
            SCAL2=1.0
            CALL UNPKLXBM(KFILDO,IPACK,ND5,LOCN,IPOS,RTEMP,IBMP,ISIZE,
     1                    NBIT,0.,REF,0,1,SCAL10,SCAL2,.TRUE.,N,
     2                    IER)
            IF(IER.NE.0)GO TO 900
C
C              COPY THE LOCAL USE DATA FOR THIS GROUP FROM RTEMP( )
C              INTO RDAT( ).
            DO 50 J=1,ISIZE
               RDAT(KNDEX)=RTEMP(J)
               KNDEX=KNDEX+1
 50         CONTINUE
C
         ELSEIF(ITYPE.EQ.1)THEN
C
C              INTEGER DATA.  CHECK TO SEE IF IDAT( ) HAS BEEN
C              DIMENSIONED LARGE ENOUGH TO CONTAIN THE DATA IN THIS
C              GROUP PLUS ONE ADDITIONAL ELEMENT TO CONTAIN THE
C              THE SIZE OF THE NEXT DATA GROUP.
            IF(NIDAT.LT.(ISIZE+INDEX+2))THEN
               IER=202
               GOTO 900
            ENDIF
C
            IDAT(INDEX)=ISIZE
            INDEX=INDEX+1
            IDAT(INDEX)=ID
            INDEX=INDEX+1
C
C              UNPACK THE DATA USING THE SIMPLE UNPACKING METHOD.
            SCAL10=10.**ID
            SCAL2=1.0
            CALL UNPKLXBM(KFILDO,IPACK,ND5,LOCN,IPOS,RTEMP,IBMP,ISIZE,
     1                    NBIT,0.,REF,0,1,SCAL10,SCAL2,.TRUE.,N,
     2                    IER)
            IF(IER.NE.0)GO TO 900
C
C              COPY THE LOCAL USE DATA FOR THIS GROUP FROM RTEMP( )
C              INTO IDAT( ).
            DO 60 J=1,ISIZE
               IDAT(INDEX)=INT(RTEMP(J))
               INDEX=INDEX+1
 60         CONTINUE
C
         ELSE
C        
C              INVALID DATA TYPE INDICATOR VALUE.
            IER=206
            GOTO 900
         ENDIF 
C
C           DETERMINE IF SOME TRAILING BITS NEED TO BE 
C           UNPACKED BECAUSE THE PACKED DATA GROUP DID NOT
C           OCCUPY A WHOLE NUMBER OF OCTETS.
         IFILL=MOD(33-IPOS,8)
C
         IF(IFILL.NE.0)THEN
            CALL UNPKBG(KFILDO,IPACK,ND5,LOCN,IPOS,ITRASH,IFILL,
     1                  N,IER,*900)
         ENDIF
C
 40   CONTINUE
C
C        ERROR RETURN SECTION
C
 900  IF(IER.NE.0)RETURN 1
C
 910  RETURN
      END
