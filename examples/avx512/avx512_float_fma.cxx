// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <iostream>
#include <vector>
#include <nola/cxx17/simd.hxx>
#include <nola/cxx17/util.hxx>


int main()
{
  std::cout << "\nSIMD AVX512 Float Fused Multiply-Add Example." << std::endl;

  // Input data
  std::vector<float> a{ 5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5,
                        5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5 };
  std::vector<float> b{ 2.2, 2.2, 2.2, 2.2, 2.2, 2.2, 2.2, 2.2,
                        2.2, 2.2, 2.2, 2.2, 2.2, 2.2, 2.2, 2.2 };
  std::vector<float> c{ 1.1, 1.1, 1.1, 1.1, 1.1, 1.1, 1.1, 1.1,
                        1.1, 1.1, 1.1, 1.1, 1.1, 1.1, 1.1, 1.1 };

  // Container to store solution
  std::vector<float> d(16);

  // Define SIMD objects using input data
  auto av = nola::simd::avx512_load( a.data() );
  auto bv = nola::simd::avx512_load( b.data() );
  auto cv = nola::simd::avx512_load( c.data() );

  // Compute SIMD operation d = (a * b) + c
  auto dv = nola::simd::avx512_fma(av, bv, cv);

  // Transfer data from SIMD object to container
  nola::simd::avx512_store( d.data(), dv );

  // Display result
  nola::util::print_vector("\nd", d.size(), d.data(), 3, 4);

  // d = [
  //  13.2 13.2 13.2 13.2 13.2 13.2 13.2 13.2 13.2 13.2 13.2 13.2 13.2 13.2 13.2 13.2
  // ]
}