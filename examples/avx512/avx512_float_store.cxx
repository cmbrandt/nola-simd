// Copyright (c) 2020-2021 Christopher M. Brandt
// All rights reserved

#include <iostream>
#include <vector>
#include <nola/simd.hxx>
#include <nola/util.hxx>


int main()
{
  std::cout << "\nSIMD AVX512 Float Store Example." << std::endl;

  // Input data
  std::vector<float> a{ 5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5,
                        5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5 }; 
  
  // Container to store solution
  std::vector<float> b(16);

  // Define SIMD object using input data
  auto va = nola::simd::avx512_load( a.data() );

  // Transfer data from SIMD object to container
  nola::simd::avx512_store( b.data(), va );

  // Display result
  nola::util::print_vector("\nb", b.size(), b.data(), 2, 3);
  
  // b = [
  //  5.5 5.5 5.5 5.5 5.5 5.5 5.5 5.5 5.5 5.5 5.5 5.5 5.5 5.5 5.5 5.5
  // ]
}