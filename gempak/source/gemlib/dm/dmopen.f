	SUBROUTINE DM_OPEN ( filnam, wrtflg, shrflg, iflno, iftype, 
     +                       ifsrce, nrow, ncol, nprt, nfhdrs, iret )
C************************************************************************
C* DM_OPEN								*
C*									*
C* This subroutine opens a data management (DM) file.			*
C*									*
C* DM_OPEN  ( FILNAM, WRTFLG, SHRFLG, IFLNO, IFTYPE, IFSRCE, NROW, 	*
C*            NCOL,   NPRT,   NFHDRS, IRET )				*
C*									*
C* Input parameters:							*
C*	FILNAM		CHAR*		File name			*
C*	WRTFLG		LOGICAL		Write access flag		*
C*	SHRFLG		LOGICAL		Shared file flag		*
C*									*
C* Output parameters:							*
C*	IFLNO		INTEGER		File number			*
C*	IFTYPE		INTEGER		File type			*
C*	IFSRCE		INTEGER		File source			*
C*	NROW		INTEGER		Number of rows			*
C*	NCOL		INTEGER		Number of columns		*
C*	NPRT		INTEGER		Number of parts			*
C*	NFHDRS		INTEGER		Number of file headers		*
C*	IRET		INTEGER		Return code			*
C*					  0 = normal return		*
C*					 -2 = file cannot be opened	*
C*					 -3 = too many files open	*
C*					 -6 = write error		*
C*					 -7 = read error		*
C*					-23 = wrong machine type	*
C*					-32 = invalid machine for write	*
C**									*
C* Log:									*
C* M. desJardins/GSFC	 5/87						*
C* M. desJardins/GSFC	 7/87	Added record length to OPEN		*
C* M. desJardins/GSFC	 5/90	Check for files from other machines	*
C* M. desJardins/NMC	 4/91	Write to files from other machines	*
C* M. desJardins/NMC	 5/91	Flags for machine types			*
C* S. Jacobs/EAI	 8/92	Added check for ULTRIX machine		*
C* K. Brill/NMC		 5/93	Added check for HP machine		*
C* S. Jacobs/EAI	10/93	Added check for ALPHA machine		*
C* S. Jacobs/NCEP	 2/01	Made MTLNUX a separate machine type	*
C* T. Lee/SAIC		 2/05	Handle error message			*
C* m. gamazaychikov/CWS 04/11   Add code for A2DB connectivity          *
C************************************************************************
	INCLUDE		'GEMPRM.PRM'
	INCLUDE		'GMBDTA.CMN'
	INCLUDE		'dmcmn.cmn'
	INCLUDE		'dbcmn.cmn'
C
	CHARACTER*(*)	filnam
	LOGICAL		wrtflg, shrflg
        CHARACTER       carr1(25)*20, carr2(2)*20
C------------------------------------------------------------------------
C*	Get a file number for this file.  Return if there are no more
C*	file numbers.
C
	CALL DM_GETF  ( iflno, iret )
	IF  ( iret .ne. 0 ) RETURN
C
C*	Open the file.  For open error, print error message and return.
C
	IF  ( wrtflg .and. shrflg )  THEN
	    CALL FL_DSOP  ( filnam, MBLKSZ, lun, iret )
	    kshare ( iflno ) = .true.
	  ELSE
	    CALL FL_DOPN  ( filnam, MBLKSZ, wrtflg, lun, iret )
	    kshare ( iflno ) = .false.
	END IF
	IF  ( iret .eq. 0 )  THEN
	    lundm  (iflno) = lun
	    wflag  (iflno) = wrtflg
	  ELSE
	    CALL ST_LSTR ( filnam, nf, ier )
	    CALL ER_WMSG ( 'FL', iret, filnam (:nf), ier )
	    iret = -2
	    RETURN
	END IF
C
C*	Read the file label into common.
C
	CALL DM_RLBL ( iflno, iret )
	IF  ( iret .ne. 0 ) GOTO 900
C
C*      Prepare needed output parms for DB source and return
C
        IF ( dbread ) THEN
           IF ( INDEX(dbdatasrc,'metar') .gt. 0 )  THEN
                iftype = MFSF
                ifsrce = 102
             ELSE IF ( INDEX(dbdatasrc,'bufrua') .gt. 0 ) THEN
                iftype = MFSN
                ifsrce = 102
             ELSE IF ( INDEX(dbdatasrc,'grid') .gt. 0 ) THEN
                iftype = MFGD
                ifsrce = 6
C
C*              Get the grid name from the file name
C
C
C*              changed the number of expected from 2 to 25
C
c                CALL ST_CLST ( filnam, '/', ' ', 2, carr1,
                CALL ST_CLST ( filnam, '/', ' ', 25, carr1,
     +                         num, ier )
c                IF ( ier .eq. 0 .and. num .eq. 2 ) THEN
                IF ( ier .eq. 0 ) THEN
                   
                   CALL ST_CLST ( carr1(num), '_', ' ', 2, carr2,
     +                            num2, ier )
                ELSE 
C
C*                 TODO - improve the error handling
C  
                   iret = -1
                   RETURN
                END IF
                IF ( num2 .eq. 2 ) THEN
c                   CALL ST_LCUC ( carr2(1), dbmodel, ier )
                   CALL ST_LSTR ( carr2(1), icarr2, ier )
                   dbmodel=carr2(1)(:icarr2)
                ELSE
C
C*                 TODO - improve the error handling
C
                   iret = -1
                   RETURN
                END IF
           END IF
           nrow   = 100
           ncol   = 25
           nprt   = 10
           nfhdrs = 3
           RETURN
        END IF
C
C*	Check that this is a valid machine.
C
	IF  ( ( kmachn ( iflno ) .ne. MTMACH ) .and.
     +	      ( kmachn ( iflno ) .ne. MTVAX  ) .and.
     +	      ( kmachn ( iflno ) .ne. MTSUN  ) .and.
     +	      ( kmachn ( iflno ) .ne. MTAPOL ) .and.
     +	      ( kmachn ( iflno ) .ne. MTIRIS ) .and.
     +	      ( kmachn ( iflno ) .ne. MTIGPH ) .and.
     +	      ( kmachn ( iflno ) .ne. MTULTX ) .and.
     +	      ( kmachn ( iflno ) .ne. MTIBM  ) .and.
     +        ( kmachn ( iflno ) .ne. MTHP   ) .and.
     +        ( kmachn ( iflno ) .ne. MTLNUX ) .and.
     +	      ( kmachn ( iflno ) .ne. MTALPH ) )  THEN
	    IF  ( wrtflg )  THEN
		iret = -32
		CALL ST_LSTR ( filnam, nf, ier )
		CALL ER_WMSG  ( 'DM', iret, filnam (:nf), ier )
		RETURN
	    END IF
	END IF
C
C*	Read the data management record.
C
	CALL DM_RDMG ( iflno, iret )
C
C*	Read all keys from the file into common.
C
	CALL DM_RKEY ( iflno, iret )
	IF  ( iret .ne. 0 ) GOTO 900
C
C*	Read headers from file.
C
	CALL DM_RHDA ( iflno, iret )
	IF  ( iret .ne. 0 ) GOTO 900
C
C*	Read part information.
C
	CALL DM_RPRT ( iflno, iret )
	IF  ( iret .ne. 0 ) GOTO 900
C
C*	Read file information.
C
	CALL DM_RFIL ( iflno, iret )
	IF  ( iret .ne. 0 ) GOTO 900
C
C*	Set search information in common.
C
	srcflg ( iflno ) = .false.
	nsrch  ( iflno ) =  0
	ksrow  ( iflno ) =  0
	kscol  ( iflno ) = 0
C
C*	Return number of rows, columns and parts.
C
	nrow   = krow ( iflno )
	ncol   = kcol ( iflno )
	nprt   = kprt ( iflno )
	nfhdrs = kfhdrs ( iflno )
C
C*	Return file type and source.
C
	iftype = kftype ( iflno )
	ifsrce = kfsrce ( iflno )
C
	GOTO 999
C
C*	Close file if an error was encountered.
C
900	CONTINUE
	CALL DM_CLOS ( iflno, ier )
C*
999	CONTINUE
	RETURN
	END
