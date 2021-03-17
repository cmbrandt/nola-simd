// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <cstdint>
#include <iostream>
#include <vector>
#include "include/stat_simd.hxx"


int main()
{
  std::cout << "\nCovariance (Float) Example." << std::endl;

  // Two sequences of values
  std::vector<float> x{ 3.2, 1.4, 2.6, 0.8, 2.0 };
  std::vector<float> y{ 2.1, 2.5, 2.3, 2.9, 2.7 };

  // Length of sequence
  std::int32_t n = x.size();

  // Compute arithmetic mean
  float m1 = nola::covariance_serial( n, x.data(), y.data() );
  //float m2 = nola::covariance_avx2(   n, x.data(), y.data() );
  //float m3 = nola::covariance_avx512( n, x.data(), y.data() );

  // Display result
  std::cout << "\ncovariance (serial) = " << m1 // m1 = -0.2700
            //<< "\ncovariance (avx2)   = " << m2 // m2 = -0.2700
            //<< "\ncovariance (avx512) = " << m3 // m3 = -0.2700
            << std::endl;
}