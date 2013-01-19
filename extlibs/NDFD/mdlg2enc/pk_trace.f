      SUBROUTINE PK_TRACE(KFILDO,JER,NDIER,KIER,NERR,ISEVERE)
C
C        JUNE    2000   LAWRENCE   ERROR POSTING AND TRACING FOR GRIB2
C        JANUARY 2001   GLAHN      COMMENTS; ADDED KIER=KIER-1; 
C                                  CHANGED IER TO JER
C 
C        PURPOSE 
C            INSERTS AN ERROR CODE AND ITS SEVERITY INTO JER( , ).
C            INSERTS 999 WHEN JER( , ) IS FULL.  IN THAT CASE,  
C            TWO ERROR CODES ARE LOST.  SINCE THE PROGRAM PROCEEDS,
C            MORE MAY BE LOST BEFORE PROGRAM COMPLETION.
C
C        DATA SET USE 
C           KFILDO - UNIT NUMBER FOR OUTPUT (PRINT) FILE. (OUTPUT) 
C
C        VARIABLES 
C             KFILDO = UNIT NUMBER FOR OUTPUT (PRINT) FILE.  (INPUT)
C           JER(J,K) = ARRAY OF ERRORS (J=1,NDIER) (K=1,2)
C                      (INPUT/OUTPUT)
C              NDIER = FIRST DIMENSION OF JER( , ). THE MAXIMUM NUMBER
C                      OF ERRORS ALLOWED TO BE REPORTED IN JER( , ).
C                      (INPUT)
C               KIER = NUMBER OF VALUES IN JER( , ) UPON EXIT.
C                      (INPUT/OUTPUT)
C               NERR = VALUE TO INSERT INTO JER(KIER,1).  (INPUT)
C            ISEVERE = THE SEVERITY LEVEL OF THE DIAGNOSTIC TO
C                      INSERT INTO JER(KIER,2).  (INPUT)
C                      VALID SEVERITY LEVELS ARE:
C                      0 = NOT AN ERROR
C                      1 = WARNING
C                      2 = FATAL
C
C       LOCAL VARIABLES
C               NONE
C
C        NON SYSTEM SUBROUTINES CALLED 
C           NONE
C
      DIMENSION JER(NDIER,2)
C
      KIER=KIER+1
C
      IF(KIER.LE.NDIER)THEN
         JER(KIER,1)=NERR
         JER(KIER,2)=ISEVERE
      ELSE
         KIER=KIER-1
         JER(KIER,1)=999
         JER(KIER,2)=2
      ENDIF
C
      RETURN
      END
