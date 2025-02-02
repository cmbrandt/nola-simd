// Copyright (c) 2020-2021 Christopher M. Brandt
// All rights reserved

#include <iostream>
#include <nola/simd.hxx>


int main()
{
  std::cout << "\nSIMD AVX2 Float Width Example." << std::endl;

  // Compute width of SIMD object
  constexpr std::int32_t w = nola::simd::avx2_width<std::int32_t, float>();

  // Display result
  std::cout << "\nw = " << w << std::endl; // w = 8
}