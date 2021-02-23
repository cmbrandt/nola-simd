// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <iostream>
#include <nola/cxx17/simd.hxx>


int main()
{
  std::cout << "\nSIMD AVX2 Double Length Example." << std::endl;

  // Compute length of SIMD object
  constexpr std::int32_t l = nola::simd::avx2_length<double>();

  // Display result
  std::cout << "\nlength = " << l << std::endl; // l = 4
}