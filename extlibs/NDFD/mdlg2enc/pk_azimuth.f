      SUBROUTINE PK_AZIMUTH(KFILDO,IPACK,ND5,IS3,NS3,IPKOPT,L3264B,
     1                      LOCN,IPOS,IER,*)
C
C        MARCH    2000   LAWRENCE  GSC/TDL   ORIGINAL CODING
C        JANUARY  2001   GLAHN     COMMENTS; IER = 303 CHANGED TO 304;
C                                  ADDED CHECK FOR SIZE OF IS3( );
C        FEBRUARY 2001   GLAHN/LAWRENCE CHANGED J=39+4*(K-1)
C                                  TO J=40+4*(K-1)
C
C        PURPOSE
C            PACKS TEMPLATE 3.120, AN AZIMUTH-RANGE PROJECTION
C            TEMPLATE, IN SECTION 3 OF A GRIB2 MESSAGE. IT IS
C            THE RESPONSIBILITY OF THE CALLING ROUTINE TO PACK 
C            THE FIRST 13 OCTETS IN SECTION 3.
C
C        DATA SET USE
C           KFILDO - UNIT NUMBER FOR OUTPUT (PRINT) FILE. (OUTPUT)
C
C        VARIABLES
C              KFILDO = UNIT NUMBER FOR OUTPUT (PRINT) FILE. (INPUT)
C            IPACK(J) = THE ARRAY THAT HOLDS THE ACTUAL PACKED MESSAGE
C                       (J=1,ND5). (INPUT/OUTPUT)
C                 ND5 = THE SIZE OF THE ARRAY IPACK( ). (INPUT)
C              IS3(J) = CONTAINS THE AZIMUTH-RANGE PROJECTION
C                       INFORMATION (IN ELEMENTS 15 THROUGH 39+4(Nr-1)
C                       WHERE Nr IS THE NUMBER OF RADIALS IN THE
C                       PROJECTION) THAT WILL BE PACKED INTO IPACK( )
C                       (J=1,NS3). (INPUT)
C                 NS3 = SIZE OF IS3( ). (INPUT) 
C              IPKOPT = PACKING INDICATOR:
C                       0 = ERROR, DON'T PACK
C                       1 = PACK IA( ), SIMPLE
C                       2 = PACK IA( ) AND IB( ), SIMPLE
C                       3 = PACK COMPLEX OR SPATIAL DIFFERENCING
C                       4 = PACK COMPLEX.
C                       (INPUT)
C              L3264B = THE INTEGER WORD LENGTH IN BITS OF THE MACHINE
C                       BEING USED. VALUES OF 32 AND 64 ARE
C                       ACCOMMODATED. (INPUT)
C                LOCN = THE WORD POSITION TO PLACE THE NEXT VALUE.
C                       (INPUT/OUTPUT)
C                IPOS = THE BIT POSITION IN LOCN TO START PLACING
C                       THE NEXT VALUE. (INPUT/OUTPUT)
C                 IER = RETURN STATUS CODE. (OUTPUT)
C                         0 = GOOD RETURN.
C                       1-4 = ERROR CODES GENERATED BY PKBG. SEE THE 
C                             DOCUMENTATION IN THE PKBG ROUTINE.
C                       302 = IS3( ) HAS NOT BEEN DIMENSIONED LARGE
C                             ENOUGH TO CONTAIN THE ENTIRE TEMPLATE. 
C                       304 = IS3(13) DOES NOT INDICATE POLAR
C                             STEREOGRAPHIC MAP PROJECTION; 
C                             INCORRECTLY CALLED SUBROUTINE. 
C                   * = ALTERNATE RETURN WHEN IER .NE. 0.
C
C             LOCAL VARIABLES
C               ISIGN = A FLAG INDICATING WHETHER A VALUE TO BE
C                       PACKED IS POSITIVE OR NEGATIVE. 
C                   J = ARRAY INDEXING VARIABLE.
C                   K = LOOPING VARIABLE.
C                   N = L3264B = THE INTEGER WORD LENGTH IN BITS OF 
C                       THE MACHINE BEING USED. VALUES OF 32 AND
C                       64 ARE ACCOMMODATED. 
C             MINSIZE = THE SMALLEST ALLOWABLE DIMENSION FOR IS3( ).
C
C        NON SYSTEM SUBROUTINES CALLED
C           PKBG
C
      PARAMETER(MINSIZE=39)
C
      DIMENSION IPACK(ND5),IS3(NS3)
C
      N=L3264B
      IER=0
C
C        CHECK TO MAKE SURE THAT THE USER WANTS TO PROCESS
C        AN AZIMUTH-RANGE PROJECTION.  CHECK FOR NS3 GE 13
C        ASSURES A VALUE FOR IS3(13). 
C
      IF(NS3.GE.13)THEN
C
         IF(IS3(13).NE.120)THEN
D           WRITE(KFILDO,10)IS3(13)
D10         FORMAT(/' MAP PROJECTION CODE ',I4,' INDICATED BY IS3(13)'/
D    1              ' IS NOT AZIMUTH-RANGE. PLEASE REFER TO'/
D    2              ' THE GRIB2 DOCUMENTATION TO DETERMINE THE'/
D    3              ' CORRECT MAP PROJECTION PACKER TO CALL.'/) 
            IER=304
            GO TO 900
         ENDIF
C
      ENDIF
C
C        CHECK THE DIMENSIONS OF IS3( ).  CHECK FOR NS3 GE 19
C        ASSURES A VALUE FOR IS3(19).
C
      IF(NS3.GE.19)THEN
C
         IF(NS3.LT.(MINSIZE+4*(IS3(19)-1)))THEN
            IER=302
            GO TO 900
         ENDIF
C
      ELSE
         IER=302
         GO TO 900
      ENDIF
C
C        PACK THE NUMBER OF DATA BINS ALONG THE RADIALS (Nb).
      CALL PKBG(KFILDO,IPACK,ND5,LOCN,IPOS,IS3(15),32,N,IER,*900)
C
C        PACK THE NUMBER OF RADIALS IN THE PRODUCT (Nr).
      CALL PKBG(KFILDO,IPACK,ND5,LOCN,IPOS,IS3(19),32,N,IER,*900)
C
C        PACK THE LATITUDE & LONGITUDE OF THE CENTER POINT
      ISIGN=0
      IF(IS3(23).LT.0)ISIGN=1
      CALL PKBG(KFILDO,IPACK,ND5,LOCN,IPOS,ISIGN,1,N,IER,*900)
      CALL PKBG(KFILDO,IPACK,ND5,LOCN,IPOS,ABS(IS3(23)),
     1          31,N,IER,*900)
      ISIGN=0
      IF(IS3(27).LT.0) ISIGN=1
      CALL PKBG(KFILDO,IPACK,ND5,LOCN,IPOS,ISIGN,1,N,IER,*900)
      CALL PKBG(KFILDO,IPACK,ND5,LOCN,IPOS,ABS(IS3(27)),
     1          31,N,IER,*900)
C
C        PACK THE SPACING OF BINS ALONG THE RADIALS
      CALL PKBG(KFILDO,IPACK,ND5,LOCN,IPOS,IS3(31),32,N,IER,*900)
C
C        PACK THE OFFSET FROM THE ORIGIN TO THE INNER BOUND.
      CALL PKBG(KFILDO,IPACK,ND5,LOCN,IPOS,IS3(35),32,N,IER,*900)
C
C        PACK THE SCANNING MODE. CHECK TO SEE IF THE DATA POINTS
C        HAVE BEEN ORDERED BOUSTROPHEDONICALLY. IF SO, SET BIT 4
C        TO 1 IN THE SCANNING MODE OCTET.
C
      IF((IPKOPT.EQ.3).OR.(IPKOPT.EQ.4))THEN
         IS3(39)=IOR(IS3(39),6)
      ELSE
         IS3(39)=IAND(IS3(39),239)
      ENDIF
C
      CALL PKBG(KFILDO,IPACK,ND5,LOCN,IPOS,IS3(39),8,N,IER,*900)
C
C        PACK THE STARTING AZIMUTH AND AZIMUTHAL WIDTH
C        FOR EACH OF THE RADIALS (THE IS3(19) VALUE)
C
      DO K=1,IS3(19)
         J = 40 + 4*(K-1)
         CALL PKBG(KFILDO,IPACK,ND5,LOCN,IPOS,IS3(J),16,N,IER,*900)
         ISIGN=0
         IF(IS3(J+2).LT.0)ISIGN=1
         CALL PKBG(KFILDO,IPACK,ND5,LOCN,IPOS,ISIGN,1,N,IER,*900)
         CALL PKBG(KFILDO,IPACK,ND5,LOCN,IPOS,ABS(IS3(J+2)),
     1             15,N,IER,*900)
      ENDDO 
C
C        ERROR RETURN SECTION
C
 900  IF(IER.NE.0)RETURN 1
C
      RETURN
      END
