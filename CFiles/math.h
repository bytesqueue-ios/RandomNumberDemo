#include <stdio.h>
#include "gmp.h"
#include "mpfr.h"
#include <stdlib.h>
#include <time.h>
#include <assert.h>

mpfr_rnd_t ROUNDING = GMP_RNDZ;

void Factorial(mpfr_ptr answer, mpfr_srcptr n, size_t prec);

// TODO : Add to all functions, 5.13 Exception Related Functions
void assertFlagsNonZero() {
    // 0, flag is not set
    // 1, flag is set
    assert(mpfr_underflow_p() == 0);
    assert(mpfr_overflow_p() == 0);
    assert(mpfr_divby0_p() == 0);
    assert(mpfr_nanflag_p() == 0);
    // assert(mpfr_inexflag_p() == 0); // 2String conversion is inexact
    assert(mpfr_erangeflag_p() == 0);
}

char *sin_t(unsigned long int num, unsigned long int timestamp, unsigned long int mPrec)
{
    mpfr_clear_flags(); // clear all exception flags
     
    size_t prec = mPrec;
    mpfr_t x, ts, x_trig;

    mpfr_init2(x, prec);                                // prec bit precision, (i.e length)
    mpfr_init2(ts, prec);                               // prec bit precision, (i.e length)
    mpfr_init2(x_trig, prec);                           // prec bit precision, (i.e length)

    mpfr_set_ui(x, num, ROUNDING);                      // Assignment
    mpfr_set_ui(ts, timestamp, ROUNDING);               // Assignment

    mpfr_div(x, ts, x, ROUNDING);                       // x * timestamp, store in x
    mpfr_sin(x_trig, x, ROUNDING);                      // trigFunc(x*ts)
    
    // Parameters to extract number string
    char *result = NULL;
    mpfr_exp_t y;

    result = mpfr_get_str(NULL, &y, 10, prec, x_trig, ROUNDING);

    mpfr_clear(x);                                      // free pointer, consumed
    mpfr_clear(ts);                                     // free pointer, consumed
    mpfr_clear(x_trig);                                 // free pointer, consumed
    mpfr_free_cache();                                  // free the cache for constants like pi 

    assertFlagsNonZero();

    return result;
}

char *cos_t(unsigned long int num, unsigned long int timestamp, unsigned long int mPrec)
{
    mpfr_clear_flags(); // clear all exception flags

    size_t prec = mPrec;
    mpfr_t x, ts, x_trig;

    mpfr_init2(x, prec);                                // prec bit precision, (i.e length)
    mpfr_init2(ts, prec);                               // prec bit precision, (i.e length)
    mpfr_init2(x_trig, prec);                           // prec bit precision, (i.e length)

    mpfr_set_ui(x, num, ROUNDING);                      // Assignment
    mpfr_set_ui(ts, timestamp, ROUNDING);               // Assignment

    mpfr_div(x, ts, x, ROUNDING);                       // x * timestamp, store in x
    mpfr_cos(x_trig, x, ROUNDING);                      // trigFunc(x*ts)
    
    mpfr_clear(ts);                                     // free pointer, consumed
    mpfr_clear(x);                                      // free pointer, consumed
    
    // Parameters to extract number string
    char *result = NULL;
    mpfr_exp_t y;
    result = mpfr_get_str(NULL, &y, 10, prec, x_trig, ROUNDING);

    mpfr_clear(x_trig);                                 // free pointer, consumed
    mpfr_free_cache();                                  // free the cache for constants like pi 

    assertFlagsNonZero();
    
    return result;
}

char *tan_t(unsigned long int num, unsigned long int timestamp, unsigned long int mPrec)
{
    size_t prec = mPrec;
    mpfr_t x, ts, x_trig;

    mpfr_init2(x, prec);                                // prec bit precision, (i.e length)
    mpfr_init2(ts, prec);                               // prec bit precision, (i.e length)
    mpfr_init2(x_trig, prec);                           // prec bit precision, (i.e length)

    mpfr_set_ui(x, num, ROUNDING);                      // Assignment
    mpfr_set_ui(ts, timestamp, ROUNDING);               // Assignment

    mpfr_div(x, ts, x, ROUNDING);                       // x * timestamp, store in x
    mpfr_clear(ts);                                     // free pointer, consumed
    mpfr_tan(x_trig, x, ROUNDING);                      // trigFunc(x*ts)
    mpfr_clear(x);                                      // free pointer, consumed
    
    // Parameters to extract number string
    char *result = NULL;
    mpfr_exp_t y;
    result = mpfr_get_str(NULL, &y, 10, prec, x_trig, ROUNDING);

    mpfr_clear(x_trig);                                 // free pointer, consumed
    mpfr_free_cache();                                  // free the cache for constants like pi 

    assertFlagsNonZero();
    
    return result;
}

char *sec_t(unsigned long int num, unsigned long int timestamp, unsigned long int mPrec)
{
    mpfr_clear_flags(); // clear all exception flags

    size_t prec = mPrec;
    mpfr_t x, ts, x_trig;

    mpfr_init2(x, prec);                                // prec bit precision, (i.e length)
    mpfr_init2(ts, prec);                               // prec bit precision, (i.e length)
    mpfr_init2(x_trig, prec);                           // prec bit precision, (i.e length)

    mpfr_set_ui(x, num, ROUNDING);                      // Assignment
    mpfr_set_ui(ts, timestamp, ROUNDING);               // Assignment

    mpfr_div(x, ts, x, ROUNDING);                       // x * timestamp, store in x
    mpfr_clear(ts);                                     // free pointer, consumed
    mpfr_sec(x_trig, x, ROUNDING);                      // trigFunc(x*ts)
    mpfr_clear(x);                                      // free pointer, consumed
    
    // Parameters to extract number string
    char *result = NULL;
    mpfr_exp_t y;
    result = mpfr_get_str(NULL, &y, 10, prec, x_trig, ROUNDING);

    mpfr_clear(x_trig);                                 // free pointer, consumed
    mpfr_free_cache();                                  // free the cache for constants like pi 

    assertFlagsNonZero();
    
    return result;
}

char *csc_t(unsigned long int num, unsigned long int timestamp, unsigned long int mPrec)
{
    mpfr_clear_flags(); // clear all exception flags

    size_t prec = mPrec;
    mpfr_t x, ts, x_trig;

    mpfr_init2(x, prec);                                // prec bit precision, (i.e length)
    mpfr_init2(ts, prec);                               // prec bit precision, (i.e length)
    mpfr_init2(x_trig, prec);                           // prec bit precision, (i.e length)

    mpfr_set_ui(x, num, ROUNDING);                      // Assignment
    mpfr_set_ui(ts, timestamp, ROUNDING);               // Assignment

    mpfr_div(x, ts, x, ROUNDING);                       // x * timestamp, store in x
    mpfr_clear(ts);                                     // free pointer, consumed
    mpfr_csc(x_trig, x, ROUNDING);                      // trigFunc(x*ts)
    mpfr_clear(x);                                      // free pointer, consumed
    
    // Parameters to extract number string
    char *result = NULL;
    mpfr_exp_t y;
    result = mpfr_get_str(NULL, &y, 10, prec, x_trig, ROUNDING);

    mpfr_clear(x_trig);                                 // free pointer, consumed
    mpfr_free_cache();                                  // free the cache for constants like pi 

    assertFlagsNonZero();
    
    return result;
}

char *cot_t(unsigned long int num, unsigned long int timestamp, unsigned long int mPrec)
{
    mpfr_clear_flags(); // clear all exception flags

    size_t prec = mPrec;
    mpfr_t x, ts, x_trig;

    mpfr_init2(x, prec);                                // prec bit precision, (i.e length)
    mpfr_init2(ts, prec);                               // prec bit precision, (i.e length)
    mpfr_init2(x_trig, prec);                           // prec bit precision, (i.e length)

    mpfr_set_ui(x, num, ROUNDING);                      // Assignment
    mpfr_set_ui(ts, timestamp, ROUNDING);               // Assignment

    mpfr_div(x, ts, x, ROUNDING);                       // x * timestamp, store in x
    mpfr_clear(ts);                                     // free pointer, consumed
    mpfr_cot(x_trig, x, ROUNDING);                      // trigFunc(x*ts)
    mpfr_clear(x);                                      // free pointer, consumed
    
    // Parameters to extract number string
    char *result = NULL;
    mpfr_exp_t y;
    result = mpfr_get_str(NULL, &y, 10, prec, x_trig, ROUNDING);

    mpfr_clear(x_trig);                                 // free pointer, consumed
    mpfr_free_cache();                                  // free the cache for constants like pi 

    assertFlagsNonZero();
    
    return result;
}

char *horizontal(unsigned long int timestamp, unsigned long int p, unsigned long int t, unsigned long int mPrec)
{
    mpfr_clear_flags(); // clear all exception flags
     
    size_t prec = mPrec;
    mpfr_t prime, tempo, ts;

    mpfr_init2(ts, prec);                               // prec bit precision, (i.e length)
    mpfr_init2(prime, prec);                            // prec bit precision, (i.e length)
    mpfr_init2(tempo, prec);                            // prec bit precision, (i.e length)

    mpfr_set_ui(ts, timestamp, ROUNDING);               // Assignment
    mpfr_set_ui(prime, p, ROUNDING);                    // Assignment
    mpfr_set_ui(tempo, t, ROUNDING);                    // Assignment
 
    mpfr_mul(ts, ts, prime, ROUNDING);                  // sqrt(N)
    mpfr_mul(ts, ts, tempo, ROUNDING);                  // sqrt(N)
    mpfr_sqrt(ts, ts, ROUNDING);

    // Parameters to extract number string
    char *result = NULL;
    mpfr_exp_t y;

    result = mpfr_get_str(NULL, &y, 10, prec, ts, ROUNDING);

    mpfr_clear(ts);                                     // free pointer, consumed
    mpfr_clear(prime);                                  // free pointer, consumed
    mpfr_clear(tempo);                                  // free pointer, consumed

    mpfr_free_cache();                                  // free the cache for constants like pi 

    return result;
}

char *vertical(unsigned long int num, unsigned long int timestamp, unsigned long int mPrec, unsigned long int prime)
{
    mpfr_clear_flags(); // clear all exception flags
     
    size_t prec = mPrec;
    mpfr_t x, ts, sqrt;

    mpfr_init2(x, prec);                                // prec bit precision, (i.e length)
    mpfr_init2(ts, prec);                               // prec bit precision, (i.e length)
    mpfr_init2(sqrt, prec);                             // prec bit precision, (i.e length)

    mpfr_set_ui(x, num, ROUNDING);                      // Assignment
    mpfr_set_ui(ts, timestamp, ROUNDING);               // Assignment

    mpfr_sqrt(sqrt, ts, ROUNDING);                      // sqrt(N)
    mpfr_mul(x, x, sqrt, ROUNDING);                     // 432 * sqrt(N)

    // Parameters to extract number string
    char *result = NULL;
    mpfr_exp_t y;

    result = mpfr_get_str(NULL, &y, 10, prec, sqrt, ROUNDING);

    mpfr_clear(x);                                      // free pointer, consumed
    mpfr_clear(ts);                                     // free pointer, consumed
    mpfr_clear(sqrt);                                   // free pointer, consumed
    mpfr_free_cache();                                  // free the cache for constants like pi 

    return result;
}
