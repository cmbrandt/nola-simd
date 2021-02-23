// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <iostream>
#include <vector>
#include <nola/cxx17/simd.hxx>


int main()
{
  std::cout << "\nSIMD AVX512 Double Reduce Example." << std::endl;

  // Input data
  std::vector<double> a{ 5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5 };

  // Define SIMD object using input data
  auto av = nola::simd::avx512_load( a.data() );

  // Compute sum of all elements in SIMD object
  double r = nola::simd::avx512_reduce(av);

  // Display result
  std::cout << "\nr = " << r << std::endl; // r = 44
}