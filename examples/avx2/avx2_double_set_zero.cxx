// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <iostream>
#include <vector>
#include <nola/cxx17/simd.hxx>
#include <nola/cxx17/util.hxx>


int main()
{
  std::cout << "\nSIMD AVX2 Double Set Zero Example." << std::endl;

  // Container to store solution
  std::vector<double> a(4);

  // Define SIMD object of zeros
  auto av = nola::simd::avx2_set_zero<double>();

  // Transfer data from SIMD object to container
  nola::simd::avx2_store( a.data(), av );

  // Display result
  nola::util::print_vector("\nvector 'a'", a.size(), a.data(), 1, 1);

  // a = [
  //  0 0 0 0
  // ]
}