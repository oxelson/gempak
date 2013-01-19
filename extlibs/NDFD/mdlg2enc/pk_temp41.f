      SUBROUTINE PK_TEMP41(KFILDO,IPACK,ND5,IS4,NS4,L3264B,
     1                     LOCN,IPOS,IER,*)
C
C        MARCH   2000   LAWRENCE   GSC/TDL   ORIGINAL CODING
C        JANUARY 2001   GLAHN      COMMENTS; IER = 403 CHANGED TO 402
C
C        PURPOSE
C            PACK TEMPLATE 4.1 INTO PRODUCT DEFINITION SECTION
C            OF A GRIB 2 MESSAGE.  TEMPLATE 4.1 IS FOR
C            AN INDIVIDUAL ENSEMBLE FORECAST, CONTROL AND 
C            PERTURBED, AT A HORIZONTAL LEVEL OR IN A
C            HORIZONTAL LEVEL OR IN A HORIZONTAL LAYER AT
C            A POINT IN TIME. IT IS THE RESPONSIBILITY OF 
C            THE CALLING ROUTINE TO PACK THE FIRST 9 OCTETS
C            IN SECTION 4.
C
C        DATA SET USE
C           KFILDO - UNIT NUMBER FOR OUTPUT (PRINT) FILE. (OUTPUT)
C
C        VARIABLES
C              KFILDO = UNIT NUMBER FOR OUTPUT (PRINT) FILE. (INPUT)
C            IPACK(J) = THE ARRAY THAT HOLDS THE ACTUAL PACKED MESSAGE
C                       (J=1,ND5). (INPUT/OUTPUT)
C                 ND5 = THE SIZE OF THE ARRAY IPACK( ). (INPUT)
C              IS4(J) = CONTAINS THE PRODUCT DEFINITION INFORMATION 
C                       FOR TEMPLATE 4.1 (IN ELEMENTS 10 THROUGH 37)
C                       THAT WILL BE PACKED INTO IPACK( ) (J=1,NS4).
C                       (INPUT)
C                 NS4 = SIZE OF IS4( ). (INPUT) 
C              L3264B = THE INTEGER WORD LENGTH IN BITS OF THE MACHINE
C                       BEING USED. VALUES OF 32 AND 64 ARE
C                       ACCOMMODATED. (INPUT)
C                LOCN = THE WORD POSITION TO PLACE THE NEXT VALUE.
C                       (INPUT/OUTPUT)
C                IPOS = THE BIT POSITION IN LOCN TO START PLACING
C                       THE NEXT VALUE. (INPUT/OUTPUT)
C                 IER = RETURN STATUS CODE. (OUTPUT)
C                        0 = GOOD RETURN.
C                       1-4 = ERROR CODES GENERATED BY PKBG. SEE THE 
C                             DOCUMENTATION IN THE PKBG ROUTINE.
C                       402 = IS4( ) HAS NOT BEEN DIMENSIONED LARGE
C                             ENOUGH TO CONTAIN THE ENTIRE TEMPLATE. 
C                   * = ALTERNATE RETURN WHEN IER NE 0. 
C
C             LOCAL VARIABLES
C             MINSIZE = THE SMALLEST ALLOWABLE DIMENSION FOR IS4( ).
C                   N = L3264B = THE INTEGER WORD LENGTH IN BITS OF
C                       THE MACHINE BEING USED. VALUES OF 32 AND
C                       64 ARE ACCOMMODATED.
C
C        NON SYSTEM SUBROUTINES CALLED
C           PKBG
C
      PARAMETER(MINSIZE=37)
C
      DIMENSION IPACK(ND5),IS4(NS4)
C
      N=L3264B
      IER=0
C
C        CHECK THE DIMENSIONS OF IS4( ).
      IF(NS4.LT.MINSIZE)THEN
D        WRITE(KFILDO,10)NS4,MINSIZE
D10      FORMAT(/' IS4( ) IS CURRENTLY DIMENSIONED TO CONTAIN'/
D    1           ' NS4=',I4,' ELEMENTS. THIS ARRAY MUST BE'/
D    2           ' DIMENSIONED TO AT LEAST ',I4,' ELEMENTS'/
D    3           ' TO CONTAIN ALL OF THE DATA IN PRODUCT'/
D    4           ' DEFINITION TEMPLATE 4.1.'/)
         IER=402
      ELSE
C
C           SINCE THIS TEMPLATE SHARES THE SAME INFORMATION
C           AS TEMPLATE 4.0, CALL THE PK_TEMP40 ROUTINE
         CALL PK_TEMP40(KFILDO,IPACK,ND5,IS4,NS4,L3264B,LOCN,IPOS,
     1                  IER,*900)
C
C           PACK THE TYPE OF ENSEMBLE FORECAST
         CALL PKBG(KFILDO,IPACK,ND5,LOCN,IPOS,IS4(35),8,N,IER,*900)
C
C           PACK THE PERTURBATION NUMBER
         CALL PKBG(KFILDO,IPACK,ND5,LOCN,IPOS,IS4(36),8,N,IER,*900)
C
C           PACK THE NUMBER OF FORECASTS IN ENSEMBLE
         CALL PKBG(KFILDO,IPACK,ND5,LOCN,IPOS,IS4(37),8,N,IER,*900)
C
      ENDIF
C
C       ERROR RETURN SECTION
 900  IF(IER.NE.0)RETURN 1
C
      RETURN
      END
