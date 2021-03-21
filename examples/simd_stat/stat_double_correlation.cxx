// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <cstdint>
#include <iostream>
#include <vector>
#include "include/stat_simd.hxx"


int main()
{
  std::cout << "\nCorrelation (Double) Example." << std::endl;

  // Two sequences of values
  std::vector<double> x{ 3.2, 1.4, 2.6, 0.8, 2.0, 3.2, 1.4, 2.6, 0.8, 2.0,
                         3.2, 1.4, 2.6, 0.8, 2.0, 3.2, 1.4, 2.6, 0.8, 2.0 };
  std::vector<double> y{ 2.1, 2.5, 2.3, 2.9, 2.7, 2.1, 2.5, 2.3, 2.9, 2.7,
                         2.1, 2.5, 2.3, 2.9, 2.7, 2.1, 2.5, 2.3, 2.9, 2.7};

  // Length of sequence
  std::int32_t n = x.size();

  // Compute arithmetic mean
  double m1 = nola::correlation_serial( n, x.data(), y.data() );
  double m2 = nola::correlation_avx2(   n, x.data(), y.data() );
  double m3 = nola::correlation_avx512( n, x.data(), y.data() );

  // Display result
  std::cout << "\ncorrelation (serial) = " << m1 // m1 = -0.9000
            << "\ncorrelation (avx2)   = " << m2 // m2 = -0.9000
            << "\ncorrelation (avx512) = " << m3 // m3 = -0.9000
            << std::endl;
}