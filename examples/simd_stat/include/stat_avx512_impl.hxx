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


}


#endif