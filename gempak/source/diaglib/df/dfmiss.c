#include "df.h"

void df_miss ( int *iret )
/************************************************************************
 * df_miss								*
 *									*
 * This subroutine sets a scalar grid missing value to a new value.	*
 *									*
 * df_miss ( iret )							*
 *									*
 * Output parameters:							*
 *	*iret		int		Return code			*
 *					As for DG_GETS			*
 **									*
 * Log:									*
 * S. Chiswell/Unidata	06/02	Created					*
 * K. Brill/HPC		11/02	Eliminate use of the SUBA logical array	*
 * R. Tian/SAIC		11/05	Recoded from Fortran			*
 ************************************************************************/
{
    int num1, num2, num, kxd, kyd, ksub1, ksub2, i, im1, zero, ier;
    float *gnum1, *gnum2, *gnum, dg1, dg2;
/*----------------------------------------------------------------------*/
    *iret = 0;
    zero = 0;

    dg_ssub ( iret );

    /*
     * Get the two grids from the stack.
     */
    dg_gets ( &num1, iret );
    if ( *iret != 0 ) return;
    dg_gets ( &num2, iret );
    if ( *iret != 0 ) return;

    /*
     * Get a new grid number and process the grids.
     */
    dg_nxts ( &num, iret );
    if ( *iret != 0 ) return;

    /*
     * Grid number to grid.
     */
    dg_getg ( &num1, &gnum1, &kxd, &kyd, &ksub1, &ksub2, iret );
    dg_getg ( &num2, &gnum2, &kxd, &kyd, &ksub1, &ksub2, iret );
    dg_getg ( &num,  &gnum,  &kxd, &kyd, &ksub1, &ksub2, iret );

    for ( i = ksub1; i <= ksub2; i++ ) {
	im1 = i - 1;
	dg1 = gnum1[im1];
	dg2 = gnum2[im1];
	if ( ERMISS (dg1) ) {
	    gnum[im1] = dg2;
	} else {
	    gnum[im1] = dg1;
	}
    }

    /*
     * Make a name of the form 'MISS'//S1//S2 and update header;
     * update stack.
     */
    dg_updh ( "MISS", &num, &num1, &num2, iret );
    dg_puts ( &num, iret );
    dg_esub ( &num, &zero, &zero, &zero, &ier );
    if ( ier != 0 ) *iret = ier;

    return;
}
