      FUNCTION IUPM(CBAY,NBITS)

C$$$  SUBPROGRAM DOCUMENTATION BLOCK
C
C SUBPROGRAM:    IUPM
C   PRGMMR: WOOLLEN          ORG: NP20       DATE: 1994-01-06
C
C ABSTRACT: THIS FUNCTION UNPACKS AND RETURNS A BINARY INTEGER WORD
C   CONTAINED WITHIN NBITS BITS OF A CHARACTER STRING CBAY, STARTING
C   WITH THE FIRST BIT OF THE FIRST BYTE OF CBAY.
C
C PROGRAM HISTORY LOG:
C 1994-01-06  J. WOOLLEN -- ORIGINAL AUTHOR
C 1998-07-08  J. WOOLLEN -- REPLACED CALL TO CRAY LIBRARY ROUTINE
C                           "ABORT" WITH CALL TO NEW INTERNAL BUFRLIB
C                           ROUTINE "BORT"
C 2003-11-04  J. ATOR    -- ADDED DOCUMENTATION
C 2003-11-04  J. WOOLLEN -- BIG-ENDIAN/LITTLE-ENDIAN INDEPENDENT (WAS
C                           IN DECODER VERSION)
C 2003-11-04  S. BENDER  -- ADDED REMARKS/BUFRLIB ROUTINE
C                           INTERDEPENDENCIES
C 2003-11-04  D. KEYSER  -- UNIFIED/PORTABLE FOR WRF; ADDED HISTORY
C                           DOCUMENTATION; OUTPUTS MORE COMPLETE
C                           DIAGNOSTIC INFO WHEN ROUTINE TERMINATES
C                           ABNORMALLY
C
C USAGE:    IUPM (CBAY, NBITS)
C   INPUT ARGUMENT LIST:
C     CBAY     - CHARACTER*8: CHARACTER STRING CONTAINING PACKED
C                INTEGER
C     NBITS    - INTEGER: NUMBER OF BITS WITHIN CBAY TO BE UNPACKED
C
C   OUTPUT ARGUMENT LIST:
C     IUPM     - INTEGER: UNPACKED INTEGER WORD
C
C REMARKS:
C    THIS ROUTINE CALLS:        BORT     IREV
C    THIS ROUTINE IS CALLED BY: CHRTRNA  CRBMG    DXMINI   PKC
C                               PKTDD    RDBFDX   UPC      UPTDD
C                               WRDLEN   WRITDX
C                               Normally not called by any application
C                               programs.
C
C ATTRIBUTES:
C   LANGUAGE: FORTRAN 77
C   MACHINE:  PORTABLE TO ALL PLATFORMS
C
C$$$

      COMMON /HRDWRD/ NBYTW,NBITW,NREV,IORD(8)

      CHARACTER*128 BORT_STR
      CHARACTER*8   CBAY
      CHARACTER*8   CINT
      DIMENSION     INT(2)
      EQUIVALENCE   (CINT,INT)

C----------------------------------------------------------------------
C----------------------------------------------------------------------

      IF(NBITS.GT.NBITW) GOTO 900
      CINT = CBAY
      INT(1) = IREV(INT(1))
      IUPM = ISHFT(INT(1),NBITS-NBITW)

C  EXITS
C  -----

      RETURN
900   WRITE(BORT_STR,'("BUFRLIB: IUPM - NUMBER OF BITS BEING UNPACKED'//
     . ', NBITS (",I4,"), IS > THE INTEGER WORD LENGTH ON THIS '//
     . 'MACHINE, NBITW (",I3,")")') NBITS,NBITW
      CALL BORT(BORT_STR)
      END
