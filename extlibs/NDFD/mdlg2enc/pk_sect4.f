      SUBROUTINE PK_SECT4(KFILDO,IPACK,ND5,IS4,NS4,L3264B,
     1                    LOCN,IPOS,IER,ISEVERE,*)
C
C        MARCH    2000   LAWRENCE  GSC/TDL   ORIGINAL CODING
C        JANUARY  2001   GLAHN     COMMENTS; ELIMINATED DUPLICATE
C                                  LOC4 AND IPOS4 INITIALIZATION;
C                                  ADDED TEST FOR SIZE OF IS4( )
C        FEBRUARY 2001   GLAHN/LAWRENCE ADDED TEMPLATE NAMES
C        JULY     2002   RUDACK    ADDED ADDTIONAL CASE STATEMENT TO
C                                  ACCOMMODATE TEMPLATE 4.9.
C
C        PURPOSE
C            PACKS SECTION 4, THE PRODUCT DEFINITION SECTION,
C            OF A GRIB2 MESSAGE.
C
C            THIS ROUTINE IS CAPABLE OF PACKING THE FOLLOWING
C            PRODUCT DEFINITION TEMPLATES:
C               TEMPLATE 4.0  ANALYSIS OR FORECAST AT A LEVEL AND POINT
C               TEMPLATE 4.1  INDIVIDUAL EMSEMBLE
C               TEMPLATE 4.2  DERIVED FORECAST BASED ON ENSEMBLES
C               TEMPLATE 4.8  AVERAGE, ACCUMULATION, EXTREMES
C               TEMPLATE 4.9  PROBABILITY FORECASTS AT A HORIZONTAL LEVEL
C               TEMPLATE 4.20 RADAR
C               TEMPLATE 4.30 SATELLITE
C
C        DATA SET USE
C           KFILDO - UNIT NUMBER FOR OUTPUT (PRINT) FILE. (OUTPUT)
C
C        VARIABLES
C              KFILDO = UNIT NUMBER FOR OUTPUT (PRINT) FILE. (INPUT)
C            IPACK(J) = THE ARRAY THAT HOLDS THE ACTUAL PACKED MESSAGE
C                       (J=1,ND5). (INPUT/OUTPUT)
C                 ND5 = THE SIZE OF THE ARRAY IPACK( ). (INPUT)
C              IS4(J) = CONTAINS THE GRID DEFINITION DATA THAT
C                       WILL BE PACKED INTO IPACK( ) (J=1,NS4).
C                       (INPUT)
C                 NS4 = SIZE OF IS4( ). (INPUT/OUTPUT)
C              L3264B = THE INTEGER WORD LENGTH IN BITS OF THE MACHINE
C                       BEING USED. VALUES OF 32 AND 64 ARE
C                       ACCOMMODATED. (INPUT)
C                LOCN = THE WORD POSITION TO PLACE THE NEXT VALUE.
C                       (INPUT/OUTPUT)
C                IPOS = THE BIT POSITION IN LOCN TO START PLACING
C                       THE NEXT VALUE. (INPUT/OUTPUT)
C                 IER = RETURN STATUS CODE. (OUTPUT)
C                         0 = GOOD RETURN.
C                        1-4 = ERROR CODES GENERATED BY PKBG. SEE THE 
C                              DOCUMENTATION IN THE PKBG ROUTINE.
C                        5,6 = ERROR CODE GENERATED BY THE LENGTH
C                              FUNCTION. SEE THE DOCUMENTATION FOR THE
C                              LENGTH FUNCTION.
C                        401 = IS4(5) DOES NOT INDICATE SECTION 4.
C                        402 = IS4( ) HAS NOT BEEN DIMENSION LARGE ENOUGH
C                              TO CONTAIN THE ENTIRE TEMPLATE INDICATED
C                              BY THE CODE IN IS4(6).  RETURNED BY
C                              ROUTINES LIKE PK_TEMP40.
C                        403 = IS4(8) DOES NOT CONTAIN A SUPPORTED 
C                              TEMPLATE NUMBER.
C             ISEVERE = THE SEVERITY LEVEL OF THE ERROR.  THE ONLY
C                       VALUE RETUNED IS:
C                       2 = A FATAL ERROR  (OUTPUT)
C                   * = ALTERNATE RETURN WHEN IER NE 0.
C
C             LOCAL VARIABLES
C                LOC4 = SAVES THE WORD POSITION IN IPACK
C                       TO STORE THE LENGTH OF SECTION 4
C                       AFTER THE ROUTINE IS DONE PACKING 
C                       DATA INTO THE SECTION.
C               IPOS4 = SAVES THE BIT POSITION IN LOC4
C                       TO STORE THE LENGTH OF SECTION 4
C                       AFTER THE ROUTINE IS DONE PACKING
C                       DATA INTO THE SECTION.
C               IZERO = CONTAINS THE VALUE '0'.  THIS IS USED IN THE
C                       CODE SIMPLY TO EMPHASIZE THAT A CERTAIN 
C                       GROUP OF OCTETS IN THE MESSAGE ARE BEING 
C                       ZEROED OUT.
C                   K = A LOOPING INDEX VARIABLE.
C                   N = L3264B = THE INTEGER WORD LENGTH IN BITS OF
C                       THE MACHINE BEING USED. VALUES OF 32 AND
C                       64 ARE ACCOMMODATED.
C
C        NON SYSTEM SUBROUTINES CALLED
C           LENGTH, PK_TEMP40, PK_TEMP41, PK_TEMP42, PK_TEMP48, PK_TEMP420,
C           PK_TEMP430, PK_TEMP49, PKBG
C
      PARAMETER(MINSIZE=8)
C
      DIMENSION IPACK(ND5),IS4(NS4)
C
      DATA IZERO/0/
C
      N=L3264B
      IER=0
C
      LOC4=LOCN
      IPOS4=IPOS
C
C        ALL ERRORS GENERATED BY THIS ROUTINE ARE FATAL.
C
      ISEVERE=2
C
C        CHECK MINIMUM SIZE OF IS4( ).  TEMPLATE SIZES CHECKED
C        IN TEMPLATE SUBROUTINES.
C
      IF(NS4.LT.MINSIZE)THEN
         IER=402
         GO TO 900
      ENDIF
C
C        CHECK TO MAKE SURE THAT DATA HAS BEEN PROVIDED FOR 
C        SECTION 4.  THERE MUST ALWAYS BE A SECTION 4.
C
      IF(IS4(5).NE.4)THEN
         IER=401
      ELSE
C           BYTES 1-4 MUST BE FILLED IN LATER WITH THE RECORD LENGTH
C           IN BYTES; BELOW STATEMENT HOLDS THE PLACE.  LOC4 AND IPOS4
C           HOLD THE LOCATION.
         CALL PKBG(KFILDO,IPACK,ND5,LOCN,IPOS,IZERO,32,N,IER,*900)
C
C           PACK THE SECTION NUMBER, IN THIS CASE 4.
         CALL PKBG(KFILDO,IPACK,ND5,LOCN,IPOS,4,8,N,IER,*900)
C
C           PACK THE NUMBER OF COORDINATES VALUES AFTER TEMPLATE.
         CALL PKBG(KFILDO,IPACK,ND5,LOCN,IPOS,IS4(6),16,N,IER,*900)
C
C           PACK THE PRODUCT DEFINITION TEMPLATE.
         CALL PKBG(KFILDO,IPACK,ND5,LOCN,IPOS,IS4(8),16,N,IER,*900)
C
C           PACK THE DATA REPRESENTATION TEMPLATE.
c         SELECT CASE (IS4(8))
c            CASE (0)
C
         IF (IS4(8).eq.0) THEN
C
C                 ANALYSIS OR FORECAST AT A HORIZONTAL LEVEL OR IN A
C                 HORIZONTAL LAYER AT A POINT IN TIME.
               CALL PK_TEMP40(KFILDO,IPACK,ND5,IS4,NS4,N,LOCN,
     1                        IPOS,IER,*900)
C
c            CASE (1)
             ELSEIF (IS4(8).eq.1) THEN
C
C                 INDIVIDUAL ENSEMBLE FORECAST, CONTROL AND PERTURBED,
C                 AT A HORIZONTAL LEVEL OR IN A HORIZONTAL LAYER AT A
C                 POINT IN TIME.
               CALL PK_TEMP41(KFILDO,IPACK,ND5,IS4,NS4,N,LOCN,
     1                        IPOS,IER,*900)
C
c            CASE(2)
             ELSEIF (IS4(8).eq.2) THEN
C
C                 DERIVED FORECAST BASED ON ALL ENSEMBLE MEMBERS AT
C                 A HORIZONTAL LEVEL OR IN A HORIZONTAL LAYER AT A
C                 POINT IN TIME.
               CALL PK_TEMP42(KFILDO,IPACK,ND5,IS4,NS4,N,LOCN,
     1                        IPOS,IER,*900)
C
c            CASE(8)
             ELSEIF (IS4(8).eq.8) THEN
C
C                 AVERAGE, ACCUMULATION, AND/OR EXTREME VALUES AT A
C                 HORIZONTAL LEVEL OR IN A HORIZONTAL LAYER IN A
C                 CONTINUOUS OR NON-CONTINUOUS TIME INTERVAL
               CALL PK_TEMP48(KFILDO,IPACK,ND5,IS4,NS4,N,LOCN,
     1                        IPOS,IER,*900)
C
c            CASE(9)
             ELSEIF (IS4(8).eq.9) THEN
C
C               A PROBABILITY FORECAST AT A HORIZONTAL LEVEL
C               OR IN A HORIZONTAL LAYER IN A CONTINUOUS OR
C               NON-CONTINUOUS TIME INTERVAL. (TEMPLATE 4.9)
C               (POP12)
               CALL PK_TEMP49(KFILDO,IPACK,ND5,IS4,NS4,N,LOCN,
     1                        IPOS,IER,*900)
C
c            CASE(20)
             ELSEIF (IS4(8).eq.20) THEN
C
C                 A RADAR PRODUCT.
               CALL PK_TEMP420(KFILDO,IPACK,ND5,IS4,NS4,N,LOCN,
     1                         IPOS,IER,*900)
C
c            CASE(30)
             ELSEIF (IS4(8).eq.30) THEN
C
C                 A SATELLITE PRODUCT.
               CALL PK_TEMP430(KFILDO,IPACK,ND5,IS4,NS4,N,LOCN,
     1                         IPOS,IER,*900)
C
c            CASE DEFAULT
             ELSE
C
C                 THE PRODUCT TEMPLATE IS UNRECOGNIZED
               IER=403
               GO TO 900
C         END SELECT      
         ENDIF     
C   
C           COMPUTE THE LENGTH OF THE SECTION AND PACK IT.
         IS4(1)=LENGTH(KFILDO,IPACK,ND5,L3264B,LOC4,IPOS4,LOCN,
     1                 IPOS,IER)
C
      ENDIF
C
C        ERROR RETURN SECTION
 900  IF(IER.NE.0)RETURN 1 
C
      RETURN
      END
