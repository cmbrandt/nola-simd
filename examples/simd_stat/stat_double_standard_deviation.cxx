// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <cstdint>
#include <iostream>
#include <vector>
#include "include/stat_simd.hxx"


int main()
{
  std::cout << "\nStandard Deviation (Double) Example." << std::endl;

  // Sequence of values
  std::vector<double> x{ 0.2, 0.4, 0.6, 0.8, 1.0 };

  // Length of sequence
  std::int32_t n = x.size();

  // Compute arithmetic mean
  double m1 = nola::standard_deviation_serial( n, x.data() );
  //double m2 = nola::standard_deviation_avx2(   n, x.data() );
  //double m3 = nola::standard_deviation_avx512( n, x.data() );

  // Display result
  std::cout << "\nstandard deviation (serial) = " << m1 // m1 = 0.3162
            //<< "\nstandard deviation (avx2)   = " << m2 // m2 = 0.3162
            //<< "\nstandard deviation (avx512) = " << m3 // m3 = 0.3162
            << std::endl;
}