// Copyright (c) 2020-2021 Christopher M. Brandt
// All rights reserved

#include <iostream>
#include <vector>
#include <nola/simd.hxx>
#include <nola/util.hxx>


int main()
{
  std::cout << "\nSIMD AVX2 Double Load Example." << std::endl;

  // Input data
  std::vector<double> a{ 5.5, 5.5, 5.5, 5.5 };
  
  // Container to store solution
  std::vector<double> b(4);

  // Define SIMD object using input data
  auto va = nola::simd::avx2_load( a.data() );

  // Transfer data from SIMD object to container
  nola::simd::avx2_store( b.data(), va );

  // Display result
  nola::util::print_vector("\nb", b.size(), b.data(), 2, 3);
  
  // b = [
  //  5.5 5.5 5.5 5.5
  // ]
}