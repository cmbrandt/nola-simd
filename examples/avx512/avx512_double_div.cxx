// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <iostream>
#include <vector>
#include <nola/simd.hxx>
#include <nola/util.hxx>


int main()
{
  std::cout << "\nSIMD AVX512 Double Division Example." << std::endl;

  // Input data
  std::vector<double> a{ 5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5 };
  std::vector<double> b{ 2.2, 2.2, 2.2, 2.2, 2.2, 2.2, 2.2, 2.2 };

  // Container to store solution
  std::vector<double> c(8);

  // Define SIMD objects using input data
  auto va = nola::simd::avx512_load( a.data() );
  auto vb = nola::simd::avx512_load( b.data() );

  // Compute SIMD operation c = a / b
  auto vc = nola::simd::avx512_div(va, vb);

  // Transfer data from SIMD object to container
  nola::simd::avx512_store( c.data(), vc );

  // Display result
  nola::util::print_vector("\nc", c.size(), c.data(), 2, 3);

  // c = [
  //  2.5 2.5 2.5 2.5 2.5 2.5 2.5 2.5
  // ]
}