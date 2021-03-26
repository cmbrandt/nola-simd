// Copyright (c) 2020-2021 Christopher M. Brandt
// All rights reserved

#include <iostream>
#include <vector>
#include <nola/simd.hxx>
#include <nola/util.hxx>


int main()
{
  std::cout << "\nSIMD AVX512 Float Set Zero Example." << std::endl;

  // Container to store solution
  std::vector<float> a(16);

  // Define SIMD object of zeros
  auto va = nola::simd::avx512_set_zero<float>();

  // Transfer data from SIMD object to container
  nola::simd::avx512_store( a.data(), va );

  // Display result
  nola::util::print_vector("\na", a.size(), a.data(), 1, 1);

  // a = [
  //  0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
  // ]
}
