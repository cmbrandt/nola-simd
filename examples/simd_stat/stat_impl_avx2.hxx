// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#ifndef NOLA_STAT_IMPL_AVX2_HXX
#define NOLA_STAT_IMPL_AVX2_HXX

#include <cmath>
#include <nola/simd.hxx>


namespace nola
{


//----------------------------------------------------------------------------//
// Declarations


template <Integer I, Real R>
inline R
arithmetic_mean_avx2(I n, R const x[ ]);

template <Integer I, Real R>
inline R
variance_avx2(I n, R const x[ ]);

template <Integer I, Real R>
inline R
standard_deviation_avx2(I n, R const x[ ]);

template <Integer I, Real R>
inline R
covariance_avx2(I n, R const x[ ], R const y[ ]);

template <Integer I, Real R>
inline R
correlation_avx2(I n, R const x[ ], R const y[ ]);


//----------------------------------------------------------------------------//
// Definitions


// Arithmetic Mean

template <Integer I, Real R>
inline R
arithmetic_mean_avx2(I n, R const x[ ])
{
  constexpr I w = nola::simd::avx2_width<I, R>();
  I m = n % w;

  R sum{0.0};
  
  for (I i{0}; i < m; ++i)
    sum += x[i];

  if (n < m)
    return sum / n;

  auto sumv = nola::simd::avx2_set_zero<R>();

  for (I i{m}; i < n; i += w) {
    auto xv = nola::simd::avx2_load(&x[i]);
    sumv    = nola::simd::avx2_add(sumv, xv);
  }

  sum = sum + nola::simd::avx2_reduce(sumv);
  return sum / n;
}


// Variance

template <Integer I, Real R>
inline R
variance_avx2(I n, R const x[ ])
{
  // Compute the mean of the sequence
  constexpr I w = nola::simd::avx2_width<I, R>();
  I m = n % w;

  R sum{0.0};
  
  for (I i{0}; i < m; ++i)
    sum += x[i];

  if (n >= m) {
    auto sumv = nola::simd::avx2_set_zero<R>();

    for (I i{m}; i < n; i += w) {
      auto xv = nola::simd::avx2_load(&x[i]);
      sumv    = nola::simd::avx2_add(sumv, xv);
    }

    sum = sum + nola::simd::avx2_reduce(sumv);
  }

  R mean = sum / n;

  // Compute and return the variance of the sequence
  sum = 0.0;

  for (I i = 0; i < m; ++i) {
    R center = x[i] - mean;
    sum += center * center;
  }

  if (n >= m) {
    auto meanv = nola::simd::avx2_set_scalar(mean);
    auto sumv  = nola::simd::avx2_set_zero<R>();

    for (int i{m}; i < n; i += w) {
      auto xv      = nola::simd::avx2_load(&x[i]);
      auto centerv = nola::simd::avx2_sub(xv, meanv);
      sumv         = nola::simd::avx2_fma(centerv, centerv, sumv);
    }

    sum = sum + nola::simd::avx2_reduce(sumv);
  }

  return sum / (n - 1);
}


// Standard Deviation

template <Integer I, Real R>
inline R
standard_deviation_avx2(I n, R const x[ ])
{
  // Compute the mean of the sequence
  constexpr I w = nola::simd::avx2_width<I, R>();
  I m = n % w;

  R sum{0.0};
  
  for (I i{0}; i < m; ++i)
    sum += x[i];

  if (n >= m) {
    auto sumv = nola::simd::avx2_set_zero<R>();

    for (I i{m}; i < n; i += w) {
      auto xv = nola::simd::avx2_load(&x[i]);
      sumv    = nola::simd::avx2_add(sumv, xv);
    }

    sum = sum + nola::simd::avx2_reduce(sumv);
  }

  R mean = sum / n;

  // Compute and return the variance of the sequence
  sum = 0.0;

  for (I i = 0; i < m; ++i) {
    R center = x[i] - mean;
    sum += center * center;
  }

  if (n >= m) {
    auto meanv = nola::simd::avx2_set_scalar(mean);
    auto tempv = nola::simd::avx2_set_zero<R>();

    for (int i{m}; i < n; i += w) {
      auto xv    = nola::simd::avx2_load(&x[i]);
      auto centv = nola::simd::avx2_sub(xv, meanv);
      tempv      = nola::simd::avx2_fma(centv, centv, tempv);
    }

    sum = sum + nola::simd::avx2_reduce(tempv);
  }

  R var = sum / (n - 1);

  // Compute and return the standard deviation of the sequence
  return std::sqrt(var);
}


// Covariance

template <Integer I, Real R>
inline R
covariance_avx2(I n, R const x[ ], R const y[ ])
{
  // Compute the mean of the two sequences
  constexpr I w = nola::simd::avx2_width<I, R>();
  I m = n % w;

  R sum1{0.0};
  R sum2{0.0};
  
  for (I i{0}; i < m; ++i) {
    sum1 += x[i];
    sum2 += y[i];
  }

  if (n >= m) {
    auto sum_xv = nola::simd::avx2_set_zero<R>();
    auto sum_yv = nola::simd::avx2_set_zero<R>();

    for (I i{m}; i < n; i += w) {
      auto xv = nola::simd::avx2_load(&x[i]);
      sum_xv  = nola::simd::avx2_add(sum_xv, xv);
      auto yv = nola::simd::avx2_load(&y[i]);
      sum_yv  = nola::simd::avx2_add(sum_yv, yv);
    }

    sum1 = sum1 + nola::simd::avx2_reduce(sum_xv);
    sum2 = sum2 + nola::simd::avx2_reduce(sum_yv);
  }

  R x_mean = sum1 / n;
  R y_mean = sum2 / n;

  // Compute the covariance of the two sequences
  sum1 = 0.0;

  for (I i = 0; i < m; ++i) {
    R x_center = x[i] - x_mean;
    R y_center = y[i] - y_mean;
    sum1 += x_center * y_center;
  }

  if (n >= m) {
    auto mean_xv = nola::simd::avx2_set_scalar(x_mean);
    auto mean_yv = nola::simd::avx2_set_scalar(y_mean);
    auto sumv    = nola::simd::avx2_set_zero<R>();

    for (int i{m}; i < n; i += w) {
      auto xv        = nola::simd::avx2_load(&x[i]);
      auto center_xv = nola::simd::avx2_sub(xv, mean_xv);
      auto yv        = nola::simd::avx2_load(&y[i]);
      auto center_yv = nola::simd::avx2_sub(yv, mean_yv);
      sumv           = nola::simd::avx2_fma(center_xv, center_yv, sumv);
    }

    sum1 = sum1 + nola::simd::avx2_reduce(sumv);
  }

  return sum1 / (n - 1);
}


// Correlation

template <Integer I, Real R>
inline R
correlation_avx2(I n, R const x[ ], R const y[ ])
{
  // Compute the mean of the two sequences
  constexpr I w = nola::simd::avx2_width<I, R>();
  I m = n % w;

  R sum1{0.0};
  R sum2{0.0};
  
  for (I i{0}; i < m; ++i) {
    sum1 += x[i];
    sum2 += y[i];
  }

  if (n >= m) {
    auto sum_xv = nola::simd::avx2_set_zero<R>();
    auto sum_yv = nola::simd::avx2_set_zero<R>();

    for (I i{m}; i < n; i += w) {
      auto xv = nola::simd::avx2_load(&x[i]);
      sum_xv  = nola::simd::avx2_add(sum_xv, xv);
      auto yv = nola::simd::avx2_load(&y[i]);
      sum_yv  = nola::simd::avx2_add(sum_yv, yv);
    }

    sum1 = sum1 + nola::simd::avx2_reduce(sum_xv);
    sum2 = sum2 + nola::simd::avx2_reduce(sum_yv);
  }

  R x_mean = sum1 / n;
  R y_mean = sum2 / n;



  // Compute and return the variance of the first sequence
  sum1 = 0.0;
  sum2 = 0.0;

  for (I i = 0; i < m; ++i) {
    R x_center = x[i] - x_mean;
    sum1 += x_center * x_center;
    R y_center = y[i] - y_center;
    sum2 += y_center * y_center;
  }

  if (n >= m) {
    auto xv_mean = nola::simd::avx2_set_scalar(x_mean);
    auto yv_mean = nola::simd::avx2_set_scalar(y_mean);
    auto tempv = nola::simd::avx2_set_zero<R>();

    for (int i{m}; i < n; i += w) {
      auto xv        = nola::simd::avx2_load(&x[i]);
      auto xv_center = nola::simd::avx2_sub(xv, xv_mean);
      auto yv        = nola::simd::avx2_load(&y[i]);
      auto yv_center = nola::simd::avx2_sub(yv, yv_mean);
      tempv          = nola::simd::avx2_fma(xv_center, yv_center, tempv);
    }

    sum1 = sum1 + nola::simd::avx2_reduce(tempv);
  }

  R x_var = sum1 / (n - 1);
  R y_var = sum2 / (n - 1);

/*
  // Compute and return the variance of the first sequence
  sum1 = 0.0;

  for (I i = 0; i < m; ++i) {
    R center = x[i] - x_mean;
    sum1 += center * center;
  }

  if (n >= m) {
    auto meanv = nola::simd::avx2_set_scalar(x_mean);
    auto tempv = nola::simd::avx2_set_zero<R>();

    for (int i{m}; i < n; i += w) {
      auto xv    = nola::simd::avx2_load(&x[i]);
      auto centv = nola::simd::avx2_sub(xv, meanv);
      tempv      = nola::simd::avx2_fma(centv, centv, tempv);
    }

    sum1 = sum1 + nola::simd::avx2_reduce(tempv);
  }

  R x_var = sum1 / (n - 1);



  // Compute and return the variance of the second sequence
  sum1 = 0.0;

  for (I i = 0; i < m; ++i) {
    R center = y[i] - y_mean;
    sum1 += center * center;
  }

  if (n >= m) {
    auto meanv = nola::simd::avx2_set_scalar(y_mean);
    auto tempv = nola::simd::avx2_set_zero<R>();

    for (int i{m}; i < n; i += w) {
      auto yv    = nola::simd::avx2_load(&y[i]);
      auto centv = nola::simd::avx2_sub(yv, meanv);
      tempv      = nola::simd::avx2_fma(centv, centv, tempv);
    }

    sum1 = sum1 + nola::simd::avx2_reduce(tempv);
  }

  R y_var = sum1 / (n - 1);
*/

  // Compute the standard deviation of the two sequences
  R x_std = std::sqrt(x_var);
  R y_std = std::sqrt(y_var);

  // Compute and return the correlation of the two sequences
  sum1 = 0.0;

  for (I i = 0; i < n; ++i) {
    R x_center = x[i] - x_mean;
    R y_center = y[i] - y_mean;
    sum1 += x_center * y_center;
  }

  R cov = sum1 / (n - 1);
  return cov / (x_std * y_std);
}


}


#endif