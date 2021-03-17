// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <cstdint>
#include <iostream>
#include <vector>
#include "include/stat_simd.hxx"


int main()
{
  std::cout << "\nVariance (Float) Example." << std::endl;

  // Sequence of values
  std::vector<double> x{ 0.2, 0.4, 0.6, 0.8, 1.0 };

  // Length of sequence
  std::int32_t n = x.size();

  // Compute arithmetic mean
  double m1 = nola::variance_serial( n, x.data() );
  //double m2 = nola::variance_avx2(   n, x.data() );
  //double m3 = nola::variance_avx512( n, x.data() );

  // Display result
  std::cout << "\nvariance (serial) = " << m1 // m1 = 0.6000
            //<< "\nvariance (avx2)   = " << m2 // m2 = 0.6000
            //<< "\nvariance (avx512) = " << m3 // m3 = 0.6000
            << std::endl;
}