// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <iostream>
#include "cxx17_blas.hxx"
#include "cxx17_root.hxx"
#include "cxx17_stat.hxx"
#include "cxx17_simd.hxx"
#include "cxx17_exec.hxx"


int main()
{
  cxx17_blas();
  cxx17_root();
  cxx17_stat();
  //cxx17_exec();
  //cxx17_simd();

  std::cout << "\nend of test.cxx\n\n\n";
}