// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <cstdint>
#include <iostream>
#include <vector>
#include "stat_simd.hxx"


int main()
{
  std::cout << "\nArithmetic Mean (Float) Example." << std::endl;

  // Sequence of values
  std::vector<float> x{ 0.2, 0.4, 0.6, 0.8, 1.0, 1.2, 1.4, 1.6, 1.8, 2.0,
                        0.2, 0.4, 0.6, 0.8, 1.0, 1.2, 1.4, 1.6, 1.8, 2.0 };

  // Length of sequence
  std::int32_t n = x.size();

  // Compute arithmetic mean
  float m1 = nola::arithmetic_mean_serial( n, x.data() );
  float m2 = nola::arithmetic_mean_avx2(   n, x.data() );
  float m3 = nola::arithmetic_mean_avx512( n, x.data() );

  // Display result
  std::cout << "\narithmetic mean (serial) = " << m1 // m1 = 0.6000
            << "\narithmetic mean (avx2)   = " << m2 // m2 = 0.6000
            << "\narithmetic mean (avx512) = " << m3 // m3 = 0.6000
            << std::endl;
}