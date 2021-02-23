// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <iostream>
#include <vector>
#include <nola/cxx17/simd.hxx>
#include <nola/cxx17/util.hxx>


int main()
{
  std::cout << "\nSIMD AVX512 Double Set Scalar Example." << std::endl;

  // Container to store solution
  std::vector<double> a(8);

  // Define SIMD object using scalar value
  auto av = nola::simd::avx512_set_scalar(5.5);

  // Transfer data from SIMD object to container
  nola::simd::avx512_store( a.data(), av );

  // Display result
  nola::util::print_vector("\na", a.size(), a.data(), 2, 3);

  // a = [
  //  5.5 5.5 5.5 5.5 5.5 5.5 5.5 5.5
  // ]
}