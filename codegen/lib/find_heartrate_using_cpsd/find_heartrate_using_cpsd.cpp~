/*
 * find_heartrate_using_cpsd.cpp
 *
 * Code generation for function 'find_heartrate_using_cpsd'
 *
 * C source code generated on: Sun Jul 13 22:39:32 2014
 *
 */

/* Include files */
#include "find_heartrate_using_cpsd.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void b_abs(const creal_T x[4096], real_T y[4096]);
static real_T b_max(const real_T varargin_1[4096]);
static void fft(const real_T x[101], creal_T y[4096]);
static void power(const real_T a[4096], real_T b, real_T y[4096]);

/* Function Definitions */
static void b_abs(const creal_T x[4096], real_T y[4096])
{
  int32_T k;
  real_T a;
  real_T b;
  for (k = 0; k < 4096; k++) {
    a = fabs(x[k].re);
    b = fabs(x[k].im);
    if (a < b) {
      a /= b;
      a = sqrt(a * a + 1.0) * b;
    } else if (a > b) {
      b /= a;
      a *= sqrt(b * b + 1.0);
    } else {
      a *= 1.4142135623730951;
    }

    y[k] = a;
  }
}

static real_T b_max(const real_T varargin_1[4096])
{
  real_T maxval;
  int32_T ix;
  maxval = varargin_1[0];
  for (ix = 0; ix < 4095; ix++) {
    if (varargin_1[ix + 1] > maxval) {
      maxval = varargin_1[ix + 1];
    }
  }

  return maxval;
}

static void fft(const real_T x[101], creal_T y[4096])
{
  int32_T i;
  real_T costab1q[1025];
  int32_T k;
  real_T costab[2049];
  real_T sintab[2049];
  int32_T ix;
  uint32_T ju;
  int32_T iy;
  uint32_T n;
  boolean_T tst;
  real_T temp_re;
  int32_T iDelta;
  int32_T iDelta2;
  int32_T iheight;
  real_T temp_im;
  int32_T ihi;
  for (i = 0; i < 4096; i++) {
    y[i].re = 0.0;
    y[i].im = 0.0;
  }

  costab1q[0] = 1.0;
  for (k = 0; k < 512; k++) {
    costab1q[k + 1] = cos(0.0015339807878856412 * ((real_T)k + 1.0));
  }

  for (k = 0; k < 511; k++) {
    costab1q[k + 513] = sin(0.0015339807878856412 * (1024.0 - ((real_T)k + 513.0)));
  }

  costab1q[1024] = 0.0;
  costab[0] = 1.0;
  sintab[0] = 0.0;
  for (k = 0; k < 1024; k++) {
    costab[k + 1] = costab1q[k + 1];
    sintab[k + 1] = -costab1q[1023 - k];
  }

  for (k = 0; k < 1024; k++) {
    costab[k + 1025] = -costab1q[1023 - k];
    sintab[k + 1025] = -costab1q[k + 1];
  }

  ix = 0;
  ju = 0U;
  iy = 0;
  for (i = 0; i < 100; i++) {
    y[iy].re = x[ix];
    y[iy].im = 0.0;
    n = 4096U;
    tst = TRUE;
    while (tst) {
      n >>= 1U;
      ju ^= n;
      tst = ((int32_T)(ju & n) == 0);
    }

    iy = (int32_T)ju;
    ix++;
  }

  y[iy].re = x[ix];
  y[iy].im = 0.0;
  for (i = 0; i < 4096; i += 2) {
    temp_re = y[i + 1].re;
    y[i + 1].re = y[i].re - y[i + 1].re;
    y[i + 1].im = 0.0;
    y[i].re += temp_re;
    y[i].im = 0.0;
  }

  iDelta = 2;
  iDelta2 = 4;
  k = 1024;
  iheight = 4093;
  while (k > 0) {
    for (i = 0; i < iheight; i += iDelta2) {
      ix = i + iDelta;
      temp_re = y[ix].re;
      temp_im = y[ix].im;
      y[i + iDelta].re = y[i].re - y[ix].re;
      y[i + iDelta].im = y[i].im - y[ix].im;
      y[i].re += temp_re;
      y[i].im += temp_im;
    }

    ix = 1;
    for (iy = k; iy < 2048; iy += k) {
      i = ix;
      ihi = ix + iheight;
      while (i < ihi) {
        temp_re = costab[iy] * y[i + iDelta].re - sintab[iy] * y[i + iDelta].im;
        temp_im = costab[iy] * y[i + iDelta].im + sintab[iy] * y[i + iDelta].re;
        y[i + iDelta].re = y[i].re - temp_re;
        y[i + iDelta].im = y[i].im - temp_im;
        y[i].re += temp_re;
        y[i].im += temp_im;
        i += iDelta2;
      }

      ix++;
    }

    k /= 2;
    iDelta = iDelta2;
    iDelta2 <<= 1;
    iheight -= iDelta;
  }
}

static void power(const real_T a[4096], real_T b, real_T y[4096])
{
  int32_T k;
  real_T u0;
  for (k = 0; k < 4096; k++) {
    u0 = a[k];
    u0 = pow(u0, 2.0);
    y[k] = u0;
  }
}

void find_heartrate_using_cpsd(const real_T ir[101], real_T sampling_rate,
  real_T hrtrate_data[4096], int32_T hrtrate_sizes[1])
{
  int32_T i;
  static const real_T dv0[101] = { 0.94030619331915721, 0.94263489153446212,
    0.94491934092823437, 0.94715937251030957, 0.949354820552551,
    0.951505522602565, 0.95361131949714872, 0.95567205537546518,
    0.95768757769194468, 0.95965773722891334, 0.96158238810894914,
    0.96346138780695978, 0.96529459716198218, 0.96708188038870846,
    0.9688231050887306, 0.97051814226150357, 0.97216686631503046,
    0.97376915507626516, 0.97532488980123189, 0.97683395518486049,
    0.97829623937053889, 0.979711633959379, 0.98108003401919908,
    0.98240133809321417, 0.98367544820844455, 0.98490226988383245,
    0.98608171213807161, 0.98721368749714478, 0.98829811200157447,
    0.98933490521337852, 0.99032399022273765, 0.99126529365436755,
    0.99215874567360307, 0.99300427999218255, 0.99380183387374443,
    0.99455134813902557, 0.99525276717076816, 0.995906038918327,
    0.99651111490198685, 0.99706795021697914, 0.99757650353720417,
    0.99803673711865926, 0.99844861680256281, 0.99881211201819209,
    0.99912719578541165, 0.99939384471691406, 0.9996120390201565,
    0.99978176249900286, 0.99990300255506515, 0.99997575018874951, 1.0,
    0.99997575018874951, 0.99990300255506515, 0.99978176249900286,
    0.9996120390201565, 0.99939384471691406, 0.99912719578541165,
    0.99881211201819209, 0.99844861680256281, 0.99803673711865926,
    0.99757650353720417, 0.99706795021697914, 0.99651111490198685,
    0.995906038918327, 0.99525276717076816, 0.99455134813902557,
    0.99380183387374443, 0.99300427999218255, 0.99215874567360307,
    0.99126529365436755, 0.99032399022273765, 0.98933490521337852,
    0.98829811200157447, 0.98721368749714478, 0.98608171213807161,
    0.98490226988383245, 0.98367544820844455, 0.98240133809321417,
    0.98108003401919908, 0.979711633959379, 0.97829623937053889,
    0.97683395518486049, 0.97532488980123189, 0.97376915507626516,
    0.97216686631503046, 0.97051814226150357, 0.9688231050887306,
    0.96708188038870846, 0.96529459716198218, 0.96346138780695978,
    0.96158238810894914, 0.95965773722891334, 0.95768757769194468,
    0.95567205537546518, 0.95361131949714872, 0.951505522602565,
    0.949354820552551, 0.94715937251030957, 0.94491934092823437,
    0.94263489153446212, 0.94030619331915721 };

  real_T b_ir[101];
  creal_T dcv0[4096];
  real_T a[4096];
  real_T b_a[4096];
  boolean_T x[4096];
  int32_T idx;
  boolean_T exitg1;
  boolean_T guard1 = FALSE;
  int32_T i0;
  int16_T b_hrtrate_data[4096];

  /* def_length=2^(ceil(log2(length(ir)/8))); */
  /* [a b]=cpsd(ir,ir,[],[],fft_scl*def_length,sampling_rate,'onesided'); */
  for (i = 0; i < 101; i++) {
    b_ir[i] = ir[i] * dv0[i];
  }

  fft(b_ir, dcv0);
  b_abs(dcv0, a);
  memcpy((void *)&b_a[0], (void *)&a[0], sizeof(real_T) << 12);
  power(b_a, 2.0, a);
  for (i = 0; i < 4096; i++) {
    x[i] = (a[i] == b_max(a));
  }

  idx = 0;
  hrtrate_sizes[0] = 4096;
  i = 1;
  exitg1 = 0U;
  while ((exitg1 == 0U) && (i <= 4096)) {
    guard1 = FALSE;
    if (x[i - 1]) {
      idx++;
      hrtrate_data[idx - 1] = (real_T)i;
      if (idx >= 4096) {
        exitg1 = 1U;
      } else {
        guard1 = TRUE;
      }
    } else {
      guard1 = TRUE;
    }

    if (guard1 == TRUE) {
      i++;
    }
  }

  if (1 > idx) {
    idx = 0;
  }

  i = idx - 1;
  for (i0 = 0; i0 <= i; i0++) {
    b_hrtrate_data[i0] = (int16_T)hrtrate_data[i0];
  }

  hrtrate_sizes[0] = idx;
  i = idx - 1;
  for (i0 = 0; i0 <= i; i0++) {
    hrtrate_data[i0] = (real_T)b_hrtrate_data[i0];
  }

  i = hrtrate_sizes[0] - 1;
  for (i0 = 0; i0 <= i; i0++) {
    hrtrate_data[i0] = hrtrate_data[i0] / 4096.0 * 60.0 * sampling_rate;
  }
}

void find_heartrate_using_cpsd_initialize(void)
{
}

void find_heartrate_using_cpsd_terminate(void)
{
  /* (no terminate code required) */
}

/* End of code generation (find_heartrate_using_cpsd.cpp) */
