/*
 * EXAMPLE 7: Delayed Replication of Table D descriptor.  Even though a 
 *   Table D descriptors represents more that one Table B descriptor, as far
 *   replication is concerned, it counts as only one descriptor.  The oreder 
 *   of preference is replication first then expansion of Table D descriptors.
 */

#include <mel_bufr.h>           /* BUFR library include file */

#if PROTOTYPE_NEEDED

int main( void )

#else

int main( )

#endif
{
    BUFR_Info_t bufr_info;  /* Largely Section 1 information. */
    float *values;        /* array of data values  */
    int   *fxy_i;         /*  array of decimal FXYs  */
    FXY_t *fxy;           /*  array of packed FXYs   */
    int   num_vals;         /*  number of values in array */
    int   i;                /*  loop counter */
    float *fpr;
    int   *ipr;
    FXY_t *xpr;
    FILE  *fd;
    int   NUM_FXYS;         /* number of FXYs          */

    printf("\n *************************** \n");
    printf(" *       EXAMPLE 7         *\n");
    printf(" *   Delayed Replication   *\n"); 
    printf(" *  of Table D Descriptor  *\n");   
    printf(" *                         * \n"); 
    printf(" *   FXY_Pack_Dec          *\n"); 
    printf(" *   BUFR_Put_Array        *\n");   
    printf(" *************************** \n"); 
    
    /********************************************************/
    /*             read FXYs and data                       */
    /********************************************************/

    /* open FXY file */
    fd = fopen("exam7.fxy","r");

    /* how many FXYs ?? */
    fscanf(fd,"%d",&NUM_FXYS);
    printf(" NUM_FXYS = %d\n",NUM_FXYS);

    /* allocate memory of FXY input */
    fxy_i = (int *)malloc ( (uint_t)NUM_FXYS * sizeof(int));
    
    /* allocate memory for packed FXYs */
    fxy = (FXY_t *)malloc( (uint_t)NUM_FXYS * sizeof(FXY_t));
    
    /* read FXYs */
    printf(" echo of FXYs read\n");
    ipr = fxy_i;
    for (i=0; i<NUM_FXYS; i++){
      fscanf(fd,"%d",ipr);
      printf(" %06d\n",*ipr++);
      fflush(stdout);
    }
    /* close FXY file */
    fclose(fd);
    
    /* open data file */
    fd = fopen("exam7.dat","r");

    /* read number of data values to be read including       */
    /* replication factors.                                  */

     fscanf(fd,"%d",&num_vals);

    /* Because we are using delayed replication, the replication     */
    /* count must be included in the data array.  However this has   */
    /* already been allowed for in the the replaction count is       */
    /* in the data read                                              */
    
    values = (float *)malloc( sizeof(float) * (uint_t)num_vals);
    fpr = values;
    /*****  end memory allocation *****/
    
    /* read data set */
    printf(" echo of data read\n");
    for ( i=0; i< num_vals; i++){
       fscanf(fd,"%f",fpr);
       printf(" i=%d  value=%.1f\n",i,*fpr++);
    }
    
    fclose(fd);
 
    /************************************************************/
    /* enter values into message */

    /* Initialize the BUFR information structure. */

    if( BUFR_Info_Init( &bufr_info ) )
    {
        BUFR_perror( "main" );
        return 1;
    }
    
    bufr_info.BUFR_MasterTable            =  0; /* Use WMO standard */
    bufr_info.BUFR_Edition            =  3; /* Use WMO standard */
    bufr_info.OriginatingCenter           = 128; /* FNOC Monterey, CA */
    bufr_info.UpdateSequenceNumber        =  0; /* 0 for original message */
    bufr_info.DataCategory                =  0; /* Surface land data */
    bufr_info.DataSubCategory             =  0; /* BUFR message sub-type */
    bufr_info.VersionNumberOfMasterTables = 5;
    bufr_info.VersionNumberOfLocalTables  =  0;
    bufr_info.MinorLocalVersion          = 0;
    bufr_info.Year                        = 95;
    bufr_info.Month                       = 12;
    bufr_info.Day                         = 31;
    bufr_info.Hour                        = 23;
    bufr_info.Minute                      = 59;
    bufr_info.ObservedData                =  1;

    Set_Flag(NoAuto_FTP);
    Set_Flag(Allow_Dup_Tab_Entry);
    Set_Flag(No_Warn_Dup_Tab_Entry);
    
    /* Initialize BUFR message.  Read standard tables. */

    if( BUFR_Init(&bufr_info, "ex7.enc", ENCODING) )
    {
        BUFR_perror( "main" );  /* Print reason for failure to stderr. */
        return 1;
    }

    /***************  pack FXYs  **************/
    /*  pack replication FXY              */
    /*  using delayed replication, therefore the replication count */
    /*  is in the data array.  The FXY for delayed replication of  */
    /*  4 FXY is 1-04-000.  The 000 indicates delayed replication. */ 
    /*  The delayed replication FXY must be followed by a count    */
    /*  descriptor (0-31-001 or 0-31-002).  This example uses      */
    /*  0-31-001 (see exam5.fxy) (single byte count)               */    
   
    /* pack FXYs for data */
    ipr = fxy_i;
    xpr = fxy;
    for ( i=0; i<NUM_FXYS; i++)
       *xpr++ = FXY_Pack_Dec( *ipr++);

    /* Enter array of data into bufr message */
    if ( BUFR_Put_Array( values, num_vals, DT_FLOAT, fxy, NUM_FXYS) ){
      BUFR_perror(" Error on call to BUFR_Put_Array in main");
      return 1;
    }

    /* create message  */
    if( BUFR_Encode( &bufr_info ) )
    {
        BUFR_perror( "main" );
        BUFR_Destroy(1);
        return 1;
    }

    BUFR_Destroy(1);
    free (fxy);
    free (fxy_i);
    free (values);
    return 0;
}
