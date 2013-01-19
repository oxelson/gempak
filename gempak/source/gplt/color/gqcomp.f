	SUBROUTINE GQCOMP ( icolr, color, ired, igreen, iblue, xname,
     +			    iret )
C************************************************************************
C* GQCOMP								*
C*									*
C* This subroutine returns the red, green, and blue components of a	*
C* color.  The color components are defined in the range 0 - 255.  If	*
C* the color was defined by name, the GEMPAK color name is also		*
C* returned.  The X Window System color name is returned if it is	*
C* available.								*
C*									*
C* GQCOMP  ( ICOLR, COLOR, IRED, IGREEN, IBLUE, XNAME, IRET )		*
C*									*
C* Input parameters:							*
C* 	ICOLR		INTEGER		Color number			*
C*									*
C* Output parameters:							*
C*	COLOR		CHAR*		GEMPAK color name		*
C*	IRED		INTEGER		Red color component		*
C*	IGREEN		INTEGER		Green color component		*
C*	IBLUE		INTEGER		Blue color component		*
C*	XNAME		CHAR*		X Window System color name	*
C*	IRET		INTEGER 	Return code			*
C**									*
C* Log:									*
C* I. Graffman/RDS	 8/85						*
C* M. desJardins/GSFC	 5/88	Documentation				*
C* G. Krueger/EAI	11/95	Removed HLS;Added XNAME;Mod. RGB range	*
C************************************************************************
	INCLUDE 	'ERROR.PRM'
C*
	CHARACTER*(*) 	color, xname
C-----------------------------------------------------------------------
	CALL DQCOMP ( icolr, color, ired, igreen, iblue, xname, iret )
C*
	RETURN
	END
