// Copyright (c) 2020-2021 Christopher M. Brandt
// All rights reserved

#include <iostream>
#include <vector>
#include <nola/simd.hxx>
#include <nola/util.hxx>


int main()
{
  std::cout << "\nSIMD AVX2 Float Set Scalar Example." << std::endl;

  // Container to store solution
  std::vector<float> a(8);

  // Define SIMD object using scalar value
  auto va = nola::simd::avx2_set_scalar(5.5f);

  // Transfer data from SIMD object to container
  nola::simd::avx2_store( a.data(), va );

  // Display result
  nola::util::print_vector("\na", a.size(), a.data(), 2, 3);

  // a = [
  //  5.5 5.5 5.5 5.5 5.5 5.5 5.5 5.5
  // ]
}