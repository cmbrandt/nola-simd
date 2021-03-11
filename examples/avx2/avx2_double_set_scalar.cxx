// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <iostream>
#include <vector>
#include <nola/simd.hxx>
#include <nola/util.hxx>


int main()
{
  std::cout << "\nSIMD AVX2 Double Set Scalar Example." << std::endl;

  // Container to store solution
  std::vector<double> a(4);

  // Define SIMD object using scalar value
  auto av = nola::simd::avx2_set_scalar(5.5);

  // Transfer data from SIMD object to container
  nola::simd::avx2_store( a.data(), av );

  // Display result
  nola::util::print_vector("\na", a.size(), a.data(), 2, 3);

  // a = [
  //  5.5 5.5 5.5 5.5
  // ]
}