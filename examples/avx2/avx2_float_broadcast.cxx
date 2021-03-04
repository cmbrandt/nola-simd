// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <iostream>
#include <vector>
#include <nola/simd.hxx>
#include <nola/util.hxx>


int main()
{
  std::cout << "\nSIMD AVX2 Float Broadcast Example." << std::endl;

  // Container to store solution
  std::vector<float> a(8);

  // Scalar value
  float s = 5.5;

  // Broadcast scalar value to each element of SIMD object
  auto av = nola::simd::avx2_broadcast(&s);

  // Transfer data from SIMD object to container
  nola::simd::avx2_store( a.data(), av );

  // Display result
  nola::util::print_vector("\na", a.size(), a.data(), 2, 3);

  // a = [
  //  5.5 5.5 5.5 5.5 5.5 5.5 5.5 5.5
  // ]
}