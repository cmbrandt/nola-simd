// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <iostream>
#include <avx2.hxx>
#include <avx512.hxx>


int main()
{
  avx2();
  avx512();

  std::cout << "\nend of test.cxx\n\n\n";
}