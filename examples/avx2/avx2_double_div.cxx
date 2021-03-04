// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <iostream>
#include <vector>
#include <nola/simd.hxx>
#include <nola/util.hxx>


int main()
{
  std::cout << "\nSIMD AVX2 Double Division Example." << std::endl;

  // Input data
  std::vector<double> a{ 5.5, 5.5, 5.5, 5.5 }; 
  std::vector<double> b{ 2.2, 2.2, 2.2, 2.2 }; 

  // Container to store solution
  std::vector<double> c(4);

  // Define SIMD objects using input data
  auto av = nola::simd::avx2_load( a.data() );
  auto bv = nola::simd::avx2_load( b.data() );

  // Compute SIMD operation c = a / b
  auto cv = nola::simd::avx2_div(av, bv);

  // Transfer data from SIMD object to container
  nola::simd::avx2_store( c.data(), cv );

  // Display result
  nola::util::print_vector("\nvector 'c'", c.size(), c.data(), 2, 3);

  // c = [
  //  2.5 2.5 2.5 2.5
  // ]
}