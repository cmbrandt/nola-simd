// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <iostream>
#include <vector>
#include <nola/cxx17/simd.hxx>
#include <nola/cxx17/util.hxx>


int main()
{
  std::cout << "\nSIMD AVX2 Float Multiplication Example." << std::endl;

  // Input data
  std::vector<float> a{ 5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5 }; 
  std::vector<float> b{ 2.2, 2.2, 2.2, 2.2, 2.2, 2.2, 2.2, 2.2 }; 

  // Container to store solution
  std::vector<float> c(8);

  // Define SIMD objects using input data
  auto av = nola::simd::avx2_load( a.data() );
  auto bv = nola::simd::avx2_load( b.data() );

  // Compute SIMD operation c = a * b
  auto cv = nola::simd::avx2_mul(av, bv);

  // Transfer data from SIMD object to container
  nola::simd::avx2_store( c.data(), cv );

  // Display result
  nola::util::print_vector("\nc", c.size(), c.data(), 2, 2);

  // c = [
  //  12 12 12 12 12 12 12 12
  // ]
}