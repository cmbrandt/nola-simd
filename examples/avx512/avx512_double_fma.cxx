// Copyright (c) 2020-2021 Christopher M. Brandt
// All rights reserved

#include <iostream>
#include <vector>
#include <nola/simd.hxx>
#include <nola/util.hxx>


int main()
{
  std::cout << "\nSIMD AVX512 Double Fused Multiply-Add Example." << std::endl;

  // Input data
  std::vector<double> a{ 5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5 };
  std::vector<double> b{ 2.2, 2.2, 2.2, 2.2, 2.2, 2.2, 2.2, 2.2 };
  std::vector<double> c{ 1.1, 1.1, 1.1, 1.1, 1.1, 1.1, 1.1, 1.1 };

  // Container to store solution
  std::vector<double> d(8);

  // Define SIMD objects using input data
  auto va = nola::simd::avx512_load( a.data() );
  auto vb = nola::simd::avx512_load( b.data() );
  auto vc = nola::simd::avx512_load( c.data() );

  // Compute SIMD operation d = (a * b) + c
  auto vd = nola::simd::avx512_fma(va, vb, vc);

  // Transfer data from SIMD object to container
  nola::simd::avx512_store( d.data(), vd );

  // Display result
  nola::util::print_vector("\nd", d.size(), d.data(), 3, 4);

  // d = [
  //  13.2 13.2 13.2 13.2 13.2 13.2 13.2 13.2
  // ]
}