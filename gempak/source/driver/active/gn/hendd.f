	SUBROUTINE HENDD  ( ieop, iret )
C************************************************************************
C* HENDD - GN								*
C*									*
C* This subroutine must be the last subroutine called by any program 	*
C* that uses GEMPLT.  It will flush internal buffers if necessary in	*
C* the device driver.  The DEVICE subprocess may be retained so that	*
C* the current definitions are available in later programs.		*
C*									*
C* HENDD  ( IEOP, IRET )						*
C*									*
C* Input parameters:							*
C*	IEOP		INTEGER		End plotting flag		*
C*					  0 = retain subprocess		*
C*					  1 = stop subprocess		*
C*									*
C* Output parameters:							*
C*	IRET		INTEGER		Return code			*
C**									*
C* Log:                                                                 *
C* S. Maxwell/GSC        6/97   Documentation changes                   *
C************************************************************************
	INCLUDE		'ERROR.PRM'
C------------------------------------------------------------------------
	iret = NORMAL
C*
	RETURN
	END
