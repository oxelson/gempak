      SUBROUTINE UNEARTH(KFILDO,IPACK,ND5,IS3,NS3,L3264B,
     1                   LOCN,IPOS,IER,*)
C
C        MARCH    2000   LAWRENCE  GSC/TDL   ORIGINAL CODING
C        JANUARY  2001   GLAHN     COMMENTS; CHANGED IER = 24 TO 307;
C                                  ADDED * RETURN
C        FEBRUARY 2001   GLAHN     COMMENTS; REMOVED GO TO 900
C
C        PURPOSE
C            UNPACKS INFORMATION PERTAINING TO THE SHAPE OF 
C            THE EARTH FROM SECTION 3 OF A GRIB2 MESSAGE.
C            THE INFORMATION THAT THIS ROUTINE PROCESSES IS BASED
C            ON TABLE 3.2 OF THE WMO GRIB2 DOCUMENTATION AND IS
C            REQUIRED BY MANY OF THE MAP TEMPLATES IN SECTION 3.
C
C        DATA SET USE
C           KFILDO - UNIT NUMBER FOR OUTPUT (PRINT) FILE. (OUTPUT)
C
C        VARIABLES
C              KFILDO = UNIT NUMBER FOR OUTPUT (PRINT) FILE. (INPUT)
C            IPACK(J) = THE ARRAY THAT HOLDS THE ACTUAL PACKED MESSAGE
C                       (J=1,ND5). (INPUT)
C                 ND5 = THE SIZE OF THE ARRAY IPACK( ). (INPUT)
C              IS3(J) = THE EARTH-SHAPE INFORMATION IS UNPACKED
C                       INTO ELEMENTS 15 THROUGH 27 OF THIS ARRAY
C                       FROM THE GRIB2 MESSAGE IN IPACK( ) (J=1,NS3).
C                       (OUTPUT)
C                 NS3 = SIZE OF IS3( ). (INPUT)
C              L3264B = THE INTEGER WORD LENGTH IN BITS OF THE MACHINE
C                       BEING USED. VALUES OF 32 AND 64 ARE
C                       ACCOMMODATED. (INPUT)
C                LOCN = THE WORD POSITION FROM WHICH TO UNPACK THE
C                       NEXT VALUE. (INPUT/OUTPUT)
C                IPOS = THE BIT POSITION IN LOCN FROM WHICH TO START
C                       UNPACKING THE NEXT VALUE.  (INPUT/OUTPUT)
C                 IER = RETURN STATUS CODE. (OUTPUT)
C                         0 = GOOD RETURN.
C                       6-8 = ERROR CODES GENERATED BY UNPKBG. SEE THE
C                             DOCUMENTATION IN THE UNPKBG ROUTINE.
C                       307 = UNRECOGNIZED OR UNSUPPORTED SHAPE OF
C                             EARTH CODE IN IS3(15).
C                   * = ALTERNATE RETURN WHEN IER NE 0. 
C
C             LOCAL VARIABLES
C              ITRASH = CONTAINS UNNEEDED UNPACKED DATA FROM THE
C                       GRIB2 MESSAGE.
C                   N = L3264B = THE INTEGER WORD LENGTH IN BITS OF
C                       THE MACHINE BEING USED. VALUES OF 32 AND
C                       64 ARE ACCOMMODATED.
C
C        NON-SYSTEM SUBROUTINES CALLED
C           UNPKBG
C
      DIMENSION IPACK(ND5),IS3(NS3)
C
      N=L3264B
      IER=0
C
C        UNPACK THE SHAPE OF THE EARTH.
      CALL UNPKBG(KFILDO,IPACK,ND5,LOCN,IPOS,IS3(15),8,N,IER,*900)
C
C        DEPENDING ON THE SHAPE OF THE EARTH THAT THE
C        USER HAS CHOSEN, UNPACK THE APPROPRIATE SCALE
C        FACTOR AND VALUE FOR THE RADIUS OF THE EARTH.
      IF((IS3(15).EQ.0).OR.(IS3(15).EQ.1))THEN
C
C           UNPACK THE SCALE FACTOR OF THE RADIUS OF THE
C           SPHERICAL EARTH AND THE SCALED RADIUS OF THE
C           SPHERICAL EARTH.
         CALL UNPKBG(KFILDO,IPACK,ND5,LOCN,IPOS,IS3(16),8,N,
     1               IER,*900)
         CALL UNPKBG(KFILDO,IPACK,ND5,LOCN,IPOS,IS3(17),
     1               32,N,IER,*900)
C
C           UNPACK THE ZEROED-OUT OCTETS THAT WOULD HAVE CONTAINED
C           THE OBLATE SPHEROID EARTH DATA. 
         CALL UNPKBG(KFILDO,IPACK,ND5,LOCN,IPOS,ITRASH,32,N,IER,*900)
         CALL UNPKBG(KFILDO,IPACK,ND5,LOCN,IPOS,ITRASH,32,N,IER,*900)
         CALL UNPKBG(KFILDO,IPACK,ND5,LOCN,IPOS,ITRASH,16,N,IER,*900)
C
      ELSE IF((IS3(15).EQ.2).OR.(IS3(15).EQ.3))THEN
C
C           UNPACK THE ZEROED-OUT OCTETS THAT WOULD HAVE
C           BEEN USED TO STORE THE SPHERICAL EARTH INFORMATION.
         CALL UNPKBG(KFILDO,IPACK,ND5,LOCN,IPOS,ITRASH,32,N,IER,*900)
         CALL UNPKBG(KFILDO,IPACK,ND5,LOCN,IPOS,ITRASH,8,N,IER,*900)
C
C           UNPACK THE SCALE FACTOR OF THE MAJOR AND MINOR
C           AXES OF AN OBLATE SPHEROID EARTH ALONG WITH
C           WITH THEIR SCALED VALUES.
         CALL UNPKBG(KFILDO,IPACK,ND5,LOCN,IPOS,IS3(21),8,N,
     1               IER,*900)
         CALL UNPKBG(KFILDO,IPACK,ND5,LOCN,IPOS,IS3(22),
     1               32,N,IER,*900)
         CALL UNPKBG(KFILDO,IPACK,ND5,LOCN,IPOS,IS3(26),8,N,
     1               IER,*900)
         CALL UNPKBG(KFILDO,IPACK,ND5,LOCN,IPOS,IS3(27),
     1               32,N,IER,*900)
C
      ELSE
C           AN INVALID OR UNSUPPORTED CODE FOR THE SHAPE OF
C           THE EARTH HAS BEEN PACKED INTO THE GRIB2 MESSAGE.
         IER=307
      ENDIF
C
C       ERROR RETURN SECTION.
C
 900  IF(IER.NE.0)RETURN1
C
      RETURN
      END
