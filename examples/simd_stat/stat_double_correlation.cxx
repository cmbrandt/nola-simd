// Copyright (c) 2020-2021 Christopher M. Brandt
// All rights reserved

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
#include "stat_simd.hxx"


int main()
{
  std::cout << "\nCorrelation (Double) Example." << std::endl;

  // Length of sequences
  int n{100};

  // Pseudo-random number generator
  Random_values<int, double> rand(0);
  
  // Sequences of pseudo-random values 
  std::vector<double> x(n);
  std::vector<double> y(n);

  std::generate_n( x.begin(), n, rand );
  std::generate_n( y.begin(), n, rand );

  // Compute correlation
  double m1 = nola::correlation_serial( n, x.data(), y.data() );
  double m2 = nola::correlation_avx2(   n, x.data(), y.data() );
  double m3 = nola::correlation_avx512( n, x.data(), y.data() );

  // Display result
  std::cout << "\ncorrelation (serial) = " << m1
            << "\ncorrelation (avx2)   = " << m2
            << "\ncorrelation (avx512) = " << m3
            << std::endl;
}