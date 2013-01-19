	SUBROUTINE HGTPNT  (  ityp, ix, iy, iret )
C************************************************************************
C* HGTPNT - XWP 							*
C*									*
C* This subroutine returns the requested number of points from the 	*
C* cursor position when the mouse button is pressed.			*
C*									*
C* HGTPNT  ( ITYP, IX, IY, IRET )					*
C*									*
C* Input parameters:							*
C*	ITYP		INTEGER		Type of cursor			*
C*					   1 = point, NP = 1		*
C*					   2 = line,  NP = 2		*
C*					   2 = box,   NP = 2		*
C*									*
C* Output parameters:							*
C*	IX (NP)		INTEGER		X coordinates			*
C*	IY (NP)		INTEGER		Y coordinates			*
C*	IRET		INTEGER		Return code			*
C**									*
C* Log:									*
C* J. Chou/EAI		 6/93						*
C* S. Jacobs/EAI	 6/93	Clean up				*
C* S. Jacobs/EAI	 9/93	Added ITYP				*
C* S. Jacobs/NMC	 7/94	General clean up			*
C* S. Jacobs/NCEP	10/96	Added checks for sub-devices		*
C* S. Maxwell/GSC        6/97   Documentation changes                   *
C* S. Jacobs/NCEP	 6/98	Removed NP from calling sequence	*
C************************************************************************
	INCLUDE		'DEVCHR.CMN'
	INCLUDE		'ERROR.PRM'
C*
	INTEGER		ix ( * ), iy ( * )
C------------------------------------------------------------------------
	iret = NORMAL
C
C*	Check the requested device.
C
	IF  ( ( ddev .eq. 'XW' ) .or. ( ddev .eq. 'XWP' ) )  THEN
C
C*	    Get the cursor information.
C
	    CALL XGTPNT ( ityp, ix, iy, iret )
	END IF
C*
	RETURN
	END
