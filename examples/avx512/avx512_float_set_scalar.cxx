// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <iostream>
#include <vector>
#include <nola/simd.hxx>
#include <nola/util.hxx>


int main()
{
  std::cout << "\nSIMD AVX512 Float Set Scalar Example." << std::endl;

  // Container to store solution
  std::vector<float> a(16);

  // Define SIMD object using scalar value
  auto va = nola::simd::avx512_set_scalar(5.5f);

  // Transfer data from SIMD object to container
  nola::simd::avx512_store( a.data(), va );

  // Display result
  nola::util::print_vector("\na", a.size(), a.data(), 2, 3);

  // a = [
  //  5.5 5.5 5.5 5.5 5.5 5.5 5.5 5.5 5.5 5.5 5.5 5.5 5.5 5.5 5.5 5.5
  // ]
}