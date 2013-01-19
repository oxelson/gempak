      SUBROUTINE UNPK_SECT3(KFILDO,IPACK,ND5,IS3,NS3,L3264B,
     1                      LOCN,IPOS,NX,NY,EXISTS,BOUST,IER,
     2                      ISEVERE,*)
C
C        MARCH    2000   LAWRENCE   GSC/TDL   ORIGINAL CODING
C        JANUARY  2001   GLAHN      COMMENTS; CHANGED IER = 14 TO
C                                   303 AND IER = 99 TO 399
C        FEBRUARY 2001   GLAHN      CHECKED SIZE OF NS3; COMMENTS
C        MARCH    2001   LAWRENCE   CHANGED HOW THE ROUTINE EXITS
C                                   IF IT DETERMINES THAT THERE IS
C                                   NO SECTION 3.  A NON-FATAL RETURN
C                                   IS NEEDED. 
C        NOVEMBER 2001   GLAHN      MOVED ISEVERE=2 UP TO BEGINNING
C
C        PURPOSE
C            UNPACKS SECTION 3, THE GRID DEFINITION SECTION, OF A
C            GRIB2 MESSAGE.
C
C            THIS ROUTINE IS CAPABLE OF UNPACKING THE FOLLOWING
C            GRID DEFINITION TEMPLATES:
C               TEMPLATE 3.0   EQUIDISTANT CYLINDRICAL LATITUDE/LONGITUDE
C               TEMPLATE 3.10  MERCATOR
C               TEMPLATE 3.20  POLAR STEREOGRAPHIC
C               TEMPLATE 3.30  LAMBERT
C               TEMPLATE 3.90  ORTHOGRAPHIC SPACE VIEW
C               TEMPLATE 3.110 EQUATORIAL AZIMUTHAL EQUIDISTANT
C               TEMPLATE 3.120 AZIMUTH-RANGE (RADAR)
C
C        DATA SET USE
C           KFILDO - UNIT NUMBER FOR OUTPUT (PRINT) FILE. (OUTPUT)
C
C        VARIABLES
C              KFILDO = UNIT NUMBER FOR OUTPUT (PRINT) FILE. (INPUT)
C            IPACK(J) = THE ARRAY THAT HOLDS THE ACTUAL PACKED MESSAGE
C                       (J=1,ND5). (INPUT/OUTPUT)
C                 ND5 = THE SIZE OF THE ARRAY IPACK( ). (INPUT)
C              IS3(J) = THE GRID DEFINITION DATA THAT IS UNPACKED
C                       FROM IPACK( ) IS PLACED INTO THIS ARRAY
C                       (J=1,NS3).  (INPUT)
C                 NS3 = SIZE OF IS3( ). (INPUT)
C              L3264B = THE INTEGER WORD LENGTH IN BITS OF THE MACHINE
C                       BEING USED. VALUES OF 32 AND 64 ARE
C                       ACCOMMODATED. (INPUT)
C                LOCN = THE WORD POSITION FROM WHICH TO UNPACK THE
C                       NEXT VALUE. (INPUT/OUTPUT)
C                IPOS = THE BIT POSITION IN LOCN FROM WHICH TO START
C                       UNPACKING THE NEXT VALUE.  (INPUT/OUTPUT)
C                  NX = THE NUMBER OF COLUMNS IN THE PRODUCT.
C                  NY = THE NUMBER OF ROWS IN THE PRODUCT.
C              EXISTS = .TRUE. IF SECTION 3 EXISTS IN THIS GRIB2
C                          MESSAGE.
C                       .FALSE. IF SECTION 3 DOESN'T EXIST IN THIS
C                        GRIB2 MESSAGE. (LOGICAL) (OUTPUT)
C               BOUST = .TRUE. IF THE DATA FIELD WAS SCANNED
C                       BOUSTROPHEDONICALLY. .FALSE. OTHERWISE.
C                       (LOGICAL) (OUTPUT)
C                 IER = RETURN STATUS CODE. (OUTPUT)
C                         0 = GOOD RETURN.
C                       6-8 = ERROR CODES GENERATED BY PKBG. SEE THE
C                             DOCUMENTATION IN THE UNPKBG ROUTINE.
C                       300 = IS3(5) DOES NOT INDICATE SECTION 3.
C                       302 = IS3( ) HAS NOT BEEN DIMENSIONED LARGE
C                             ENOUGH TO CONTAIN THE ENTIRE TEMPLATE. 
C                       303 = UNSUPPORTED GRID TEMPLATE INDICATED 
C                             BY IS3(13).
C                       307 = UNRECOGNIZED OR UNSUPPORTED SHAPE OF
C                             EARTH CODE IN IS3(15) RETURNED FROM
C                             UNEARTH CALLED FROM TEMPLATE UNPACKING
C                             ROUTINES.
C                       399 = UNEXPECTED END OF MESSAGE.
C             ISEVERE = THE SEVERITY LEVEL OF THE ERROR.  THE ONLY
C                       VALUE RETUNED IS:
C                       2 = A FATAL ERROR  (OUTPUT)
C                   * = ALTERNATE RETURN WHEN IER NE 0.
C
C             LOCAL VARIABLES
C             LOCN3_1 = SAVES THE WORD POSITION LOCN IN IPACK
C                       UPON ENTRY TO STORE BACK TO LOCN IN CASE
C                       THERE IS A FATAL ERROR.
C             IPOS3_1 = SAVES THE BIT POSITION IPOS IN LOCN
C                       UPON ENTRY TO STORE BACK TO IPOS IN CASE
C                       THERE IS A FATAL ERROR.
C               LSECT = CONTAINS THE LENGTH OF SECTION 3
C                       AS UNPACKED FROM THE FIRST FOUR
C                       BYTES IN THE SECTION.
C               NSECT = SECTION NUMBER.
C                   K = A LOOPING INDEX VARIABLE.
C                   N = L3264B = THE INTEGER WORD LENGTH IN BITS OF
C                       THE MACHINE BEING USED. VALUES OF 32 AND
C                       64 ARE ACCOMMODATED.
C
C        NON SYSTEM SUBROUTINES CALLED
C           ENDOMESS, UNPKBG, UNPK_AZIMUTH, UNPK_CYLINDER,
C           UNPK_EQUATOR, UNPK_LAMBERT, UNPK_MERCATOR,
C           UNPK_POLSTER, UNPK_ORTHOGRAPHIC
C
      LOGICAL BOUST,EXISTS,ENDOMESS
C
      DIMENSION IPACK(ND5),IS3(NS3)
C
      N=L3264B
      IER=0
C
C        ALL ERRORS GENERATED BY THIS ROUTINE ARE FATAL.
      ISEVERE=2
C
C        CHECK SIZE OF IS3( ).
C
      IF(NS3.LT.13)THEN
         IER=302
         GO TO 900
      ENDIF
C
      EXISTS=.TRUE.
C
C        UNPACK SECTION LENGTH, LSECT.
      LOCN3_1=LOCN
      IPOS3_1=IPOS
      CALL UNPKBG(KFILDO,IPACK,ND5,LOCN,IPOS,LSECT,32,N,IER,*900) 
C
C        CHECK FOR AN UNEXPECTED END OF MESSAGE,
C        ACCOMMODATING FOR A 64-BIT WORD.
C
      IF(ENDOMESS(LSECT,N))THEN
         IER=399
         GO TO 900
      ENDIF
C
C        UNPACK THE SECTION NUMBER. CHECK TO MAKE SURE THAT
C        THIS IS SECTION 3.
      CALL UNPKBG(KFILDO,IPACK,ND5,LOCN,IPOS,NSECT,8,N,IER,*900)
C
      IF(NSECT.NE.3)THEN
         EXISTS=.FALSE.
         LOCN=LOCN3_1
         IPOS=IPOS3_1
         GO TO 900
      ENDIF
C
      DO K=1,NS3
         IS3(K)=0
      ENDDO
C
      IS3(1)=LSECT
      IS3(5)=NSECT
C
C        UNPACK THE SOURCE OF GRID DEFINITION
      CALL UNPKBG(KFILDO,IPACK,ND5,LOCN,IPOS,IS3(6),8,N,IER,*900)
C
C        UNPACK THE NUMBER OF DATA POINTS
      CALL UNPKBG(KFILDO,IPACK,ND5,LOCN,IPOS,IS3(7),32,N,IER,*900)
C
C        UNPACK THE NUMBER OF OCTETS FOR OPTIONAL LIST OF NUMBERS
C        DEFINING NUMBER OF POINTS.
      CALL UNPKBG(KFILDO,IPACK,ND5,LOCN,IPOS,IS3(11),8,N,IER,*900)
C
C        UNPACK THE INTERPRETATION OF LIST OF NUMBERS DEFINING
C        NUMBER OF POINTS. 
      CALL UNPKBG(KFILDO,IPACK,ND5,LOCN,IPOS,IS3(12),8,N,IER,*900)
C
C        UNPACK GRID DEFINITION TEMPLATE NUMBER
      CALL UNPKBG(KFILDO,IPACK,ND5,LOCN,IPOS,IS3(13),16,N,IER,*900)
C
C        UNPACK THE VALUES FOR THE TYPE OF PROJECTION THE
C        GRID IS ON.
C
c      SELECT CASE (IS3(13))
C
c      CASE(0)
       IF (IS3(13).EQ.0) THEN
C
C           THIS IS A LATITUDE/LONGITUDE (OR EQUIDISTANT CYLINDRICAL)
C           PROJECTION.
         CALL UNPK_CYLINDER(KFILDO,IPACK,ND5,IS3,NS3,N,LOCN,IPOS,
     1                      BOUST,IER,*900)
         NX=IS3(31)
         NY=IS3(35)
C
c      CASE(10)
       ELSEIF (IS3(13).EQ.10) THEN
C
C           THIS IS A MERCATOR PROJECTION
         CALL UNPK_MERCATOR(KFILDO,IPACK,ND5,IS3,NS3,N,LOCN,IPOS,
     1                     BOUST,IER,*900)
         NX=IS3(31)
         NY=IS3(35)
C
c      CASE (20)
       ELSEIF (IS3(13).EQ.20) THEN
C
C           POLAR STEREOGRAPHIC MAP PROJECTION.
         CALL UNPK_POLSTER(KFILDO,IPACK,ND5,IS3,NS3,N,LOCN,IPOS,
     1                     BOUST,IER,*900)
         NX=IS3(31)
         NY=IS3(35)
C
c      CASE(30)
       ELSEIF (IS3(13).EQ.30) THEN
C
C           THIS IS A LAMBERT CONFORMAL PROJECTION
         CALL UNPK_LAMBERT(KFILDO,IPACK,ND5,IS3,NS3,N,LOCN,IPOS, 
     1                     BOUST,IER,*900)
         NX=IS3(31)
         NY=IS3(35)
C
c      CASE(90)
       ELSEIF (IS3(13).EQ.90) THEN
C
C           THIS IS A SPACE VIEW PERSPECTIVE OR ORTHOGRAPHIC
C           PROJECTION.
         CALL UNPK_ORTHOGRAPHIC(KFILDO,IPACK,ND5,IS3,NS3,N,LOCN,
     1                          IPOS,BOUST,IER,*900)
         NX=IS3(31)
         NY=IS3(35)
C
c      CASE(110)
       ELSEIF (IS3(13).EQ.110) THEN
C
C           EQUATORIAL AZIMUTHAL EQUIDISTANT PROJECTION
         CALL UNPK_EQUATOR(KFILDO,IPACK,ND5,IS3,NS3,N,LOCN,IPOS,
     1                     BOUST,IER,*900)
         NX=IS3(31)
         NY=IS3(35)
C
c      CASE(120)
       ELSEIF (IS3(13).EQ.120) THEN
C
C           AZIMUTHAL RANGE PROJECTION
         CALL UNPK_AZIMUTH(KFILDO,IPACK,ND5,IS3,NS3,N,LOCN,IPOS,
     1                     BOUST,IER,*900)
         NX=IS3(15)
         NY=IS3(19)
C
c      CASE DEFAULT
       ELSE
C
C           THE MAP PROJECTION IS NOT SUPPORTED.
         IER=303
C
c      END SELECT
       ENDIF
C
C       ERROR RETURN SECTION
 900  IF(IER.NE.0)RETURN 1
C
      RETURN
      END
