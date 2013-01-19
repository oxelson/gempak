	SUBROUTINE HENDD  ( ieop, iret )
C************************************************************************
C* HENDD - VG								*
C*									*
C* This subroutine must be the last subroutine called by any program 	*
C* that uses GEMPLT.  It will flush internal buffers if necessary in the*
C* device driver.  The DEVICE subprocess may be retained so that the 	*
C* current definitions are available in later programs.			*
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
C* J. Wu/GSC	02/01   	Created based on hendd.f for PS device	*
C************************************************************************
C------------------------------------------------------------------------
	CALL VENDD ( ieop, iret )
C*
	RETURN
	END
