// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#ifndef NOLA_STAT_AVX512_IMPL_HXX
#define NOLA_STAT_AVX512_IMPL_HXX

#include <cmath>
#include <nola/simd.hxx>


namespace nola
{


//----------------------------------------------------------------------------//
// Declarations


template <Integer I, Real R>
inline R
arithmetic_mean_avx512(I n, R const x[ ]);

template <Integer I, Real R>
inline R
variance_avx512(I n, R const x[ ]);

template <Integer I, Real R>
inline R
standard_deviation_avx512(I n, R const x[ ]);

template <Integer I, Real R>
inline R
covariance_avx512(I n, R const x[ ], R const y[ ]);

template <Integer I, Real R>
inline R
correlation_avx512(I n, R const x[ ], R const y[ ]);


//----------------------------------------------------------------------------//
// Definitions


// Arithmetic Mean

template <Integer I, Real R>
inline R
arithmetic_mean_avx512(I n, R const x[ ])
{
  constexpr I w = nola::simd::avx512_width<I, R>();
  I m = n % w;

  R sum{0.0};
  
  for (I i{0}; i < m; ++i)
    sum += x[i];

  if (n < m)
    return sum / n;

  auto temp = nola::simd::avx512_set_zero<R>();

  for (I i{m}; i < n; i += w) {
    auto xv = nola::simd::avx512_load(&x[i]);
    temp    = nola::simd::avx512_add(temp, xv);
  }

  sum = sum + nola::simd::avx512_reduce(temp);
  return sum / n;
}


// Variance

template <Integer I, Real R>
inline R
variance_avx512(I n, R const x[ ])
{
  // Compute the mean of the sequence
  constexpr I w = nola::simd::avx512_width<I, R>();
  I m = n % w;

  R sum{0.0};
  
  for (I i{0}; i < m; ++i)
    sum += x[i];

  if (n >= m) {
    auto tempv = nola::simd::avx512_set_zero<R>();

    for (I i{m}; i < n; i += w) {
      auto xv = nola::simd::avx512_load(&x[i]);
      tempv   = nola::simd::avx512_add(tempv, xv);
    }

    sum = sum + nola::simd::avx512_reduce(tempv);
  }

  R mean = sum / n;

  // Compute and return the variance of the sequence
  sum = 0.0;

  for (I i = 0; i < m; ++i) {
    R center = x[i] - mean;
    sum += center * center;
  }

  if (n >= m) {
    auto meanv = nola::simd::avx512_set_scalar(mean);
    auto tempv = nola::simd::avx512_set_zero<R>();

    for (int i{m}; i < n; i += w) {
      auto xv    = nola::simd::avx512_load(&x[i]);
      auto centv = nola::simd::avx512_sub(xv, meanv);
      tempv      = nola::simd::avx512_fma(centv, centv, tempv);
    }

    sum = sum + nola::simd::avx512_reduce(tempv);
  }

  return sum / (n - 1);
}


// Standard Deviation

template <Integer I, Real R>
inline R
standard_deviation_avx512(I n, R const x[ ])
{
  // Compute the mean of the sequence
  constexpr I w = nola::simd::avx512_width<I, R>();
  I m = n % w;

  R sum{0.0};
  
  for (I i{0}; i < m; ++i)
    sum += x[i];

  if (n >= m) {
    auto tempv = nola::simd::avx512_set_zero<R>();

    for (I i{m}; i < n; i += w) {
      auto xv = nola::simd::avx512_load(&x[i]);
      tempv   = nola::simd::avx512_add(tempv, xv);
    }

    sum = sum + nola::simd::avx512_reduce(tempv);
  }

  R mean = sum / n;

  // Compute and return the variance of the sequence
  sum = 0.0;

  for (I i = 0; i < m; ++i) {
    R center = x[i] - mean;
    sum += center * center;
  }

  if (n >= m) {
    auto meanv = nola::simd::avx512_set_scalar(mean);
    auto tempv = nola::simd::avx512_set_zero<R>();

    for (int i{m}; i < n; i += w) {
      auto xv    = nola::simd::avx512_load(&x[i]);
      auto centv = nola::simd::avx512_sub(xv, meanv);
      tempv      = nola::simd::avx512_fma(centv, centv, tempv);
    }

    sum = sum + nola::simd::avx512_reduce(tempv);
  }

  R var = sum / (n - 1);

  // Compute and return the standard deviation of the sequence
  return std::sqrt(var);
}


// Covariance

template <Integer I, Real R>
inline R
covariance_avx512(I n, R const x[ ], R const y[ ])
{
  // Compute the mean of the two sequences
  constexpr I w = nola::simd::avx512_width<I, R>();
  I m = n % w;

  R sum1{0.0};
  R sum2{0.0};
  
  for (I i{0}; i < m; ++i) {
    sum1 += x[i];
    sum2 += y[i];
  }

  if (n >= m) {
    auto sum_xv = nola::simd::avx512_set_zero<R>();
    auto sum_yv = nola::simd::avx512_set_zero<R>();

    for (I i{m}; i < n; i += w) {
      auto xv = nola::simd::avx512_load(&x[i]);
      sum_xv  = nola::simd::avx512_add(sum_xv, xv);
      auto yv = nola::simd::avx512_load(&y[i]);
      sum_yv  = nola::simd::avx512_add(sum_yv, yv);
    }

    sum1 = sum1 + nola::simd::avx512_reduce(sum_xv);
    sum2 = sum2 + nola::simd::avx512_reduce(sum_yv);
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
    auto mean_xv = nola::simd::avx512_set_scalar(x_mean);
    auto mean_yv = nola::simd::avx512_set_scalar(y_mean);
    auto sumv    = nola::simd::avx512_set_zero<R>();

    for (int i{m}; i < n; i += w) {
      auto xv        = nola::simd::avx512_load(&x[i]);
      auto center_xv = nola::simd::avx512_sub(xv, mean_xv);
      auto yv        = nola::simd::avx512_load(&y[i]);
      auto center_yv = nola::simd::avx512_sub(yv, mean_yv);
      sumv           = nola::simd::avx512_fma(center_xv, center_yv, sumv);
    }

    sum1 = sum1 + nola::simd::avx512_reduce(sumv);
  }

  return sum1 / (n - 1);
}


// Correlation

template <Integer I, Real R>
inline R
correlation_avx512(I n, R const x[ ], R const y[ ])
{
  // Compute the mean of the first sequence
  R sum{0.0};

  for (I i{0}; i < n; ++i)
    sum += x[i];

  R x_mean = sum / n;

  // Compute the variance of the first sequence
  sum = 0.0;

  for (I i = 0; i < n; ++i) {
    R x_center = x[i] - x_mean;
    sum += x_center * x_center;
  }

  R x_var = sum / (n - 1);

  // Compute the mean of the second sequence
  sum = 0.0;

  for (I i = 0; i < n; ++i)
    sum += y[i];

  R y_mean = sum / n;

  // Compute the variance of the second sequence
  sum = 0.0;

  for (I i = 0; i < n; ++i) {
    R y_center = y[i] - y_mean;
    sum += y_center * y_center;
  }

  R y_var = sum / (n - 1);

  // Compute the standard deviation of the two sequences
  R x_std = std::sqrt(x_var);
  R y_std = std::sqrt(y_var);

  // Compute and return the correlation of the two sequences
  sum = 0.0;

  for (I i = 0; i < n; ++i) {
    R x_center = x[i] - x_mean;
    R y_center = y[i] - y_mean;
    sum += x_center * y_center;
  }

  R cov = sum / (n - 1);
  return cov / (x_std * y_std);
}


}


#endif