C Copyright(c) 1998, Space Science and Engineering Center, UW-Madison
C Refer to "McIDAS Software Acquisition and Distribution Policies"
C in the file  mcidas/data/license.txt

C *** $Id: nvxgmsx.dlm,v 1.1 2000/06/26 15:51:49 daves Exp $ ***

      FUNCTION NVXINI(IFUNC,IPARMS)



      INTEGER IFUNC
      INTEGER IPARMS(*)
      INTEGER OFFSET1
      INTEGER OFFSET2
      CHARACTER*4 CLIT
      CHARACTER FORM*5
      CHARACTER CPARMS(3200)*1
      COMMON/GMSNAVCOM/NAVTYPE


      IF (IFUNC .EQ. 1) THEN


c* Remove "MORE" from every 128th word before initilizing
c* mapping common block.

        OFFSET1 = 4
        OFFSET2 = 0

        CALL MOVC(504,IPARMS,OFFSET1,CPARMS,OFFSET2)
        OFFSET1 = OFFSET1 + 508
        OFFSET2 = OFFSET2 + 504

      DO 100 i = 1, 4
        CALL MOVC(508,IPARMS,OFFSET1,CPARMS,OFFSET2)
        OFFSET1 = OFFSET1 + 512
        OFFSET2 = OFFSET2 + 508
100   continue


        FORM = 'short'
        CALL DECODE_OA_BLOCK(CPARMS,FORM)


      ELSE IF (IFUNC.EQ.2) THEN
         IF(INDEX(CLIT(IPARMS(1)),'XY').NE.0) NAVTYPE=1
         IF(INDEX(CLIT(IPARMS(1)),'LL').NE.0) NAVTYPE=2
      ENDIF


      NVXINI = 0
      RETURN
      END

      FUNCTION NVXSAE(LIN,ELE,DUM1,LAT,LON,Z)
 
      INTEGER*4    IRET 
      INTEGER*4    MODE 
      COMMON/GMSNAVCOM/NAVTYPE
      REAL*4       RINF(8)
      REAL*8       DSCT
      REAL LAT
      REAL LON
      REAL ELE
      REAL LIN
      REAL DUM1
      REAL Z
      REAL LATLON(2)
      REAL SUBLAT
      REAL SUBLON
      REAL YLAT
      REAL YLON

        MODE=-1

        CALL SUBLATLON(LATLON)
        SUBLAT = LATLON(1) 
        SUBLON = LATLON(2) 
        CALL MGIVSR(MODE,ELE,LIN,LON,LAT,0.0,RINF,DSCT,IRET)
        IF(IRET .NE. 0)GOTO 100
        IF(ABS(LON) .GT. 180.)GOTO 100
        LON = -1.*LON
      IF((LON .GT. 90.-SUBLON).AND.(LON .LT. 270.-SUBLON))GOTO 100


      IF(NAVTYPE.EQ.1) THEN
         YLAT=LAT
         YLON=LON
         CALL LLCART(YLAT,YLON,LAT,LON,Z)
      ENDIF

      NVXSAE = 0
      RETURN

100   NVXSAE = -1
      RETURN
      END


      FUNCTION NVXEAS(INLAT,INLON,Z,LIN,ELE,DUM1)
      INTEGER MODE
      INTEGER*4    IRET 
      COMMON/GMSNAVCOM/NAVTYPE
      REAL*4       RINF(8)
      REAL*8       DSCT
      REAL       INLAT
      REAL       INLON
      REAL       LAT
      REAL       LON
      REAL       LIN
      REAL       ELE
      REAL DUM1
      REAL LATLON(2)
      REAL SUBLAT
      REAL SUBLON
      REAL X
      REAL Y
      REAL Z

      LAT=INLAT
      LON=INLON

      IF(NAVTYPE.EQ.1) THEN
         X=LAT
         Y=LON
         CALL CARTLL(X,Y,Z,LAT,LON)
      ENDIF

      MODE=1

      CALL SUBLATLON(LATLON)
      SUBLAT = LATLON(1)
      SUBLON = LATLON(2)
      IF( ABS(LAT).GT.90 ) GOTO 100
      IF( ABS(LON).GT. 180 ) GOTO 100
      IF( LON.GT.90.-SUBLON .AND. LON.LT.270.-SUBLON) GOTO 100
      LON=-1.0*LON

        CALL MGIVSR(MODE,ELE,LIN,LON,LAT,0.0,RINF,DSCT,IRET)
        IF(IRET .NE. 0)GOTO 100

      NVXEAS = 0
      RETURN
100   NVXEAS = -1
      RETURN
      END


      FUNCTION NVXOPT(IFUNC,XIN,XOUT)
C
C IFUNC= 'SPOS'    SUBSATELLITE LAT/LON
C
C        XIN - NOT USED
C        XOUT - 1. SUB-SATELLITE LATITUDE
C             - 2. SUB-SATELLITE LONGITUDE
C
C
C IFUNC= 'ANG '   ANGLES
C
C        XIN - 1. SSYYDDD
C              2. TIME (HOURS)
C              3. LATITUDE
C              4. LONGITUDE (***** WEST NEGATIVE *****)
C        XOUT- 1. SATELLITE ANGLE
C              2. SUN ANGLE
C              3. RELATIVE ANGLE
C
C
C
C IFUNC= 'HGT '   INPUT HEIGHT FOR PARALLAX
C
C        XIN - 1. HEIGHT (KM)
C
      REAL*4 XIN(*),XOUT(*)
      CHARACTER*4 CLIT,CFUNC
      CFUNC=CLIT(IFUNC)
      NVXOPT=0
      IF(CFUNC.EQ.'SPOS') THEN
         CALL SUBLATLON(XOUT)
         CALL SDEST('IN NVX OPT USING --- SPOS',0)
      ELSE IF(CFUNC.EQ.'ANG ') THEN
         CALL SDEST('IN NVX OPT USING --- ANG ',0)
      ELSE IF(CFUNC.EQ.'HGT ') THEN
         CALL SDEST('IN NVX OPT USING --- HGT ',0)
      ELSE
         NVXOPT=1
      ENDIF
      RETURN
      END
C
C
C
C
C-----SUBSIDIARY SUBPROGRAMS
C
C
C
      FUNCTION ICON1(YYMMDD)
C
C     CONVERTS YYMMDD TO YYDDD
C
      IMPLICIT INTEGER(A-Z)
      DIMENSION NUM(12)
      DATA NUM/0,31,59,90,120,151,181,212,243,273,304,334/
C
      YEAR=MOD(YYMMDD/10000,100)
      MONTH=MOD(YYMMDD/100,100)
      DAY=MOD(YYMMDD,100)
      IF(MONTH.LT.0.OR.MONTH.GT.12)MONTH=1
      JULDAY=DAY+NUM(MONTH)
      IF(MOD(YEAR,4).EQ.0.AND.MONTH.GT.2) JULDAY=JULDAY+1
      ICON1=1000*YEAR+JULDAY
      RETURN
      END
C
C MRNLLXYZ MB   09/15/83; BYPASS GEOLAT & MAKE WEST = +
C MRLLXYZ  MB    7/09/82;  CNVERT LAT/LON TO/FROM EARTH-CENTERED X,Y,Z
      SUBROUTINE NLLXYZ(XLAT,XLON,X,Y,Z)
C-----CONVERT LAT,LON TO EARTH CENTERED X,Y,Z
C     (DALY, 1978)
C-----XLAT,XLON ARE IN DEGREES, WITH NORTH AND WEST POSITIVE
C-----X,Y,Z ARE GIVEN IN KM. THEY ARE THE COORDINATES IN A RECTANGULAR
C        FRAME WITH ORIGIN AT THE EARTH CENTER, WHOSE POSITIVE
C        X-AXIS PIERCES THE EQUATOR AT LON 0 DEG, WHOSE POSITIVE Y-AXIS
C        PIERCES THE EQUATOR AT LON 90 DEG, AND WHOSE POSITIVE Z-AXIS
C        INTERSECTS THE NORTH POLE.
      AB=40546851.22
      ASQ=40683833.48
      BSQ=40410330.18
      R=6371.221
      RSQ=R*R
      RDPDG=1.745329252E-02
      YLAT=RDPDG*XLAT
C-----CONVERT TO GEOCENTRIC (SPHERICAL) LATITUDE
CCC     YLAT=GEOLAT(YLAT,1)
      YLAT=ATAN2(BSQ*SIN(YLAT),ASQ*COS(YLAT))
      YLON=-RDPDG*XLON
      SNLT=SIN(YLAT)
      CSLT=COS(YLAT)
      CSLN=COS(YLON)
      SNLN=SIN(YLON)
      TNLT=(SNLT/CSLT)**2
      R=AB*SQRT((1.0+TNLT)/(BSQ+ASQ*TNLT))
      X=R*CSLT*CSLN
      Y=R*CSLT*SNLN
      Z=R*SNLT
      RETURN
      END
      SUBROUTINE NXYZLL(X,Y,Z,XLAT,XLON)
C-----CONVERT EARTH-CENTERED X,Y,Z TO LAT & LON
C-----X,Y,Z ARE GIVEN IN KM. THEY ARE THE COORDINATES IN A RECTANGULAR
C        COORDINATE SYSTEM WITH ORIGIN AT THE EARTH CENTER, WHOSE POS.
C        X-AXIS PIERCES THE EQUATOR AT LON 0 DEG, WHOSE POSITIVE Y-AXIS
C        PIERCES THE EQUATOR AT LON 90 DEG, AND WHOSE POSITIVE Z-AXIS
C        INTERSECTS THE NORTH POLE.
C-----XLAT,XLON ARE IN DEGREES, WITH NORTH AND WEST POSITIVE
C
      ASQ=40683833.48
      BSQ=40410330.18
      RDPDG=1.745329252E-02
C
      XLAT=100.0
      XLON=200.0
      IF(X.EQ.0..AND.Y.EQ.0..AND.Z.EQ.0.) GO TO 90
      A=ATAN(Z/SQRT(X*X+Y*Y))
C-----CONVERT TO GEODETIC LATITUDE
CCC     XLAT=GEOLAT(ATAN(Z/SQRT(X*X+Y*Y)),2)/RDPDG
      XLAT=ATAN2(ASQ*SIN(A),BSQ*COS(A))/RDPDG
      XLON=-ATAN2(Y,X)/RDPDG
   90 RETURN
      END
