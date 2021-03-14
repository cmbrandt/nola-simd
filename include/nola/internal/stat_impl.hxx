// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#ifndef NOLA_STAT_IMPL_HXX
#define NOLA_STAT_IMPL_HXX


namespace nola
{


//----------------------------------------------------------------------------//
// Declarations


template <Real R>
inline R
arithmetic_mean(std::int32_t n, R const x[ ]);

template <Real R>
inline R
variance(std::int32_t n, R const x[ ]);

template <Real R>
inline R
standard_deviation(std::int32_t n, R const x[ ]);

template <Real R>
inline R
covariance(std::int32_t n, R const x[ ], R const y[ ]);

template <Real R>
inline R
correlation(std::int32_t n, R const x[ ], R const y[ ]);


//----------------------------------------------------------------------------//
// Definitions


// Arithmetic Mean

template <Real R>
inline R
arithmetic_mean(std::int32_t n, const R x[ ])
{
  R sum{0.0};
  
  for (std::int32_t i{0}; i < n; ++i)
    sum += x[i];

  return sum / n;
}





} // namespace nola


#endif