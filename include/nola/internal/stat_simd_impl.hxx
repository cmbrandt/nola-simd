// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#ifndef NOLA_STAT_SIMD_HXX
#define NOLA_STAT_SIMD_HXX

#include <nola/internal/stat_avx2_impl.hxx>
#include <nola/internal/stat_avx512_impl.hxx>


namespace nola
{


//----------------------------------------------------------------------------//
// Declarations


template <ExecutionPolicy E, Real R>
inline R
arithmetic_mean(E&& exec, std::int32_t n, R const x[ ]);

template <ExecutionPolicy E, Real R>
inline R
variance(E&& exec, std::int32_t n, R const x[ ]);

template <ExecutionPolicy E, Real R>
inline R
standard_deviation(E&& exec, std::int32_t n, R const x[ ]);

template <ExecutionPolicy E, Real R>
inline R
covariance(E&& exec, std::int32_t n, R const x[ ], R const y[ ]);

template <ExecutionPolicy E, Real R>
inline R
correlation(E&& exec, std::int32_t n, R const x[ ], R const y[ ]);


//----------------------------------------------------------------------------//
// Definitions


// Arithmetic Mean

template <ExecutionPolicy E, Real R>
inline Real
arithmetic_mean(std::int32_t n, const Real x[ ])
{
  constexpr bool avx2 = std::same_as_v<E, nola::exec::simd_avx2>;

  if constexpr (avx2)
    return detail::arithmetic_mean_avx2(n, x);
  else
    return detail::arithmetic_mean_avx512(n, x);
}





} // namespace nola


#endif