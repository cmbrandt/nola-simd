// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <iostream>
#include <vector>
#include <nola/simd.hxx>


int main()
{
  std::cout << "\nSIMD AVX2 Float Reduce Example." << std::endl;

  // Input data
  std::vector<float> a{ 5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5 };

  // Define SIMD object using input data
  auto av = nola::simd::avx2_load( a.data() );

  // Compute sum of all elements in SIMD object
  float r = nola::simd::avx2_reduce(av);

  // Display result
  std::cout << "\nr = " << r << std::endl;
}