// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <iostream>
#include <nola/simd.hxx>


int main()
{
  std::cout << "\nSIMD AVX512 Width Width Example." << std::endl;

  // Compute length of SIMD object
  /*constexpr*/ std::int32_t w = nola::simd::avx512_width<float>();

  // Display result
  std::cout << "\nwidth = " << w << std::endl; // w = 16
}