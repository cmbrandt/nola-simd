// Copyright (c) 2020-2021 Christopher M. Brandt
// All rights reserved

#include <iostream>
#include <nola/simd.hxx>


int main()
{
  std::cout << "\nSIMD AVX512 Double Width Example." << std::endl;

  // Compute width of SIMD object
  constexpr std::int32_t w = nola::simd::avx512_width<std::int32_t, double>();

  // Display result
  std::cout << "\nw = " << w << std::endl; // w = 8
}