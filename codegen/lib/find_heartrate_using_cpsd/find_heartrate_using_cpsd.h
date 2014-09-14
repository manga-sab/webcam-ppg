/*
 * find_heartrate_using_cpsd.h
 *
 * Code generation for function 'find_heartrate_using_cpsd'
 *
 * C source code generated on: Sun Jul 13 22:39:32 2014
 *
 */

#ifndef __FIND_HEARTRATE_USING_CPSD_H__
#define __FIND_HEARTRATE_USING_CPSD_H__
/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rtwtypes.h"
#include "find_heartrate_using_cpsd_types.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern void find_heartrate_using_cpsd(const real_T ir[101], real_T sampling_rate, real_T hrtrate_data[4096], int32_T hrtrate_sizes[1]);
extern void find_heartrate_using_cpsd_initialize(void);
extern void find_heartrate_using_cpsd_terminate(void);
#endif
/* End of code generation (find_heartrate_using_cpsd.h) */
