// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#ifndef NOLA_STAT_AVX2_IMPL_HXX
#define NOLA_STAT_AVX2_IMPL_HXX

//#include <nola/exec.hxx>
#include <nola/internal/concepts.hxx>


namespace nola
{


//----------------------------------------------------------------------------//
// Declarations


template <class Real>
inline Real
arithmetic_mean_avx2(std::int32_t n, Real const x[ ]);

template <Real R>
inline R
variance_avx2(std::int32_t n, R const x[ ]);

template <Real R>
inline R
standard_deviation_avx2(std::int32_t n, R const x[ ]);

template <Real R>
inline R
covariance_avx2(std::int32_t n, R const x[ ], R const y[ ]);

template <Real R>
inline R
correlation_avx2(std::int32_t n, R const x[ ], R const y[ ]);


//----------------------------------------------------------------------------//
// Definitions


// Arithmetic Mean


   



}



#endif