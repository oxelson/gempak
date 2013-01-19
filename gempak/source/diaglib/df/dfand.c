#include "df.h"

void df_and ( const int *nargs, int *iret )
/************************************************************************
 * df_and								*
 *									*
 * This subroutine evaluates the AND logical function for all of nargs	*
 * input arguments.  If all arguments are greater than 0 at a grid	*
 * point, DF_AND returns a 1; otherwise, it returns a 0 at that grid	*
 * point.  If any one of the input arguments is missing at a point,	*
 * DF_AND returns a missing value.					*
 *									*
 * df_and (nargs, iret)							*
 *									*
 * Input parameters:							*
 *	*nargs		const int	Number of input parameters	*
 *									*
 * Output parameters:							*
 * 	*iret		int		Return code			*
 *					0 - normal return		*
 **									*
 * Log:									*
 * m.gamazaychikov/SAIC	09/05						*
 * R. Tian/SAIC		10/05	Recoded from Fortran			*
 ************************************************************************/
{
    int num, num1, kxd, kyd, ksub1, ksub2, iarg, fidx, cidx, zero, ier;
    float *gnum, *gnum1, dg1, dgo;
/*----------------------------------------------------------------------*/
    *iret = 0;
    zero = 0;

    dg_ssub ( iret );

    /*
     * Get the output grid and initialize it to zero.
     */
    dg_nxts ( &num, iret );
    if ( *iret != 0 ) return;
    dg_getg ( &num, &gnum, &kxd, &kyd, &ksub1, &ksub2, iret );
    for ( fidx = ksub1; fidx <= ksub2; fidx++ ) {
	cidx = fidx - 1;
        gnum[cidx] = 0.;
    }

    /*
     * Loop over all NARGS input arguments.
     */
    for ( iarg = 0; iarg < *nargs; iarg++ ) {
	dg_gets ( &num1, iret );
	if ( *iret != 0 ) return;
	dg_getg ( &num1, &gnum1, &kxd, &kyd, &ksub1, &ksub2, iret );
	for ( fidx = ksub1; fidx <= ksub2; fidx++ ) {
	    cidx = fidx - 1;
            dg1 = gnum1[cidx];
            dgo = gnum[cidx];
            if ( ERMISS ( dg1 ) || ERMISS ( dgo ) ) {
                gnum[cidx] = RMISSD;
            } else if ( dg1 > 0.0 ) {
	        gnum[cidx] += 1;
	    }
        }
    }

    /*
     * Do one more loop for all grid points to set the output grid
     * to 1 wherever cast to int of its value is equal to NARGS.    
     */
    for ( fidx = ksub1; fidx <= ksub2; fidx++ ) {
	cidx = fidx - 1;
	dgo = gnum[cidx];
	if ( ! ERMISS ( dgo ) ) {
	    if ( G_NINT ( dgo ) == *nargs ) {
                gnum[cidx] = 1.0;
            } else {
                gnum[cidx] = 0.0;
            }
	}
    }	 

    /*
     * Get a name of the form 'AND'//'last arg' and update header;
     * update stack.
     */
    dg_updh ( "AND", &num, &num1, &zero, iret );
    dg_puts ( &num, iret );
    dg_esub ( &num, &zero, &zero, &zero, &ier );
    if ( ier != 0 ) *iret = ier;

    return;
}
