// Copyright (c) 2020-2021 Christopher M. Brandt
// All rights reserved

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
#include "stat_simd.hxx"


int main()
{
  std::cout << "\nCorrelation (Float) Example." << std::endl;

  // Length of sequences
  int n{100};

  // Pseudo-random number generator
  Random_values<int, float> rand(0);

  // Sequences of pseudo-random values 
  std::vector<float> x(n);
  std::vector<float> y(n);

  std::generate_n( x.begin(), n, rand );
  std::generate_n( y.begin(), n, rand );

  // Compute arithmetic mean
  float m1 = nola::correlation_serial( n, x.data(), y.data() );
  float m2 = nola::correlation_avx2(   n, x.data(), y.data() );
  float m3 = nola::correlation_avx512( n, x.data(), y.data() );

  // Display result
  std::cout << "\ncorrelation (serial) = " << m1
            << "\ncorrelation (avx2)   = " << m2
            << "\ncorrelation (avx512) = " << m3
            << std::endl;
}