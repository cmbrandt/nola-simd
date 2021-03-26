// Copyright (c) 2020-2021 Christopher M. Brandt
// All rights reserved

#include <iostream>
#include <vector>
#include <nola/simd.hxx>
 

int main()
{
  std::cout << "\nSIMD AVX2 Double Reduce Example." << std::endl;

  // Input data
  std::vector<double> a{ 1.1, 4.9, 2.3, 3.5 };

  // Define SIMD object using input data
  auto va = nola::simd::avx2_load( a.data() );

  // Compute sum of all elements in SIMD object
  double r = nola::simd::avx2_reduce(va);

  // Display result
  std::cout << "\nr = " << r << std::endl; // r = 11.8
}