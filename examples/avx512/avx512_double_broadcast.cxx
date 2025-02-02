// Copyright (c) 2020-2021 Christopher M. Brandt
// All rights reserved

#include <iostream>
#include <vector>
#include <nola/simd.hxx>
#include <nola/util.hxx>


int main()
{
  std::cout << "\nSIMD AVX512 Double Broadcast Example." << std::endl;

  // Container to store solution
  std::vector<double> a(8);

  // Scalar value
  double s = 5.5;

  // Broadcast scalar value to each element of SIMD object
  auto va = nola::simd::avx512_broadcast(&s);

  // Transfer data from SIMD object to container
  nola::simd::avx512_store( a.data(), va );

  // Display result
  nola::util::print_vector("\na", a.size(), a.data(), 2, 3);

  // a = [
  //  5.5 5.5 5.5 5.5 5.5 5.5 5.5 5.5
  // ]
}