	SUBROUTINE HSCRGB  ( icolr, irrr, iggg, ibbb, iret )
C************************************************************************
C* HSCRGB - XW								*
C*									*
C* This subroutine defines the color components of a color by		*
C* specifying the values of red, green, and blue.  The color components	*
C* must be in the range 0 - 255.					*
C*									*
C* HSCRGB  ( ICOLR, IRRR, IGGG, IBBB, IRET )				*
C*									*
C* Input parameters:							*
C* 	ICOLR		INTEGER		Color number			*
C*	IRRR		INTEGER		Red color component		*
C*	IGGG		INTEGER		Green color component		*
C*	IBBB		INTEGER		Blue color component		*
C*									*
C* Output parameters:							*
C*	IRET		INTEGER		Return code			*
C**									*
C* Log:									*
C* J. Whistler/SSAI	 8/91	XW device driver			*
C* M. desJardins/NMC	01/91	GEMPAK 5.1				*
C* S. Jacobs/NMC	 7/94	General clean up			*
C* G. Krueger/EAI	11/95	Changed RGB range from 0-1 to 0-255.	*
C* S. Maxwell/GSC        6/97   Documentation changes                   *
C************************************************************************
C-----------------------------------------------------------------------
C*	Set the color components.
C
	CALL XSCRGB ( 0, icolr, irrr, iggg, ibbb, iret )
C*
	RETURN
	END
