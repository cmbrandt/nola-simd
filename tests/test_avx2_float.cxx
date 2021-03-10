// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <iostream>
#include <vector>
#include <nola/simd.hxx>
#include <test_helpers.hxx>
#include <test_avx2_float.hxx>


int test_avx2_float()
{
  int fail{0};

  //fail = test_avx2_float_length(fail);
  //fail = test_avx2_float_set_scalar_and_store(fail);
  //fail = test_avx2_float_set_zero(fail);

  fail = test_avx2_float_broadcast(fail);
  fail = test_avx2_float_load(fail);
  fail = test_avx2_float_add(fail);
  fail = test_avx2_float_sub(fail);
  fail = test_avx2_float_mul(fail);
  fail = test_avx2_float_div(fail);
  fail = test_avx2_float_fma(fail);
  fail = test_avx2_float_reduce(fail);

  if (fail == 0)
    std::cout << "\ntest_avx2_float()  passed with zero errors." << std::endl;
  else
    std::cout << "\ntest_avx2_float()  had " << fail << " errors." << std::endl;

  return fail;
}


/*
int test_avx2_float_length(int fail)
{

  return fail;
}



int test_avx2_float_set_scalar_and_store(int fail)
{

  return fail;
}



int test_avx2_float_set_zero(int fail)
{

  return fail;
}
*/


int test_avx2_float_broadcast(int fail)
{
  std::vector<float> a(8);
  std::vector<float> soln(8, 5);
  float s{5.5};

  auto av = nola::simd::avx2_broadcast(&s);

  nola::simd::avx2_store( a.data(), av );

  bool r = compare_sequences( a.begin(), a.end(), soln.begin() );

  if (r != false) {
    ++fail;
    std::cout << "\nERROR! nola::simd::avx2_broadcast()" << std::endl;
    print_sequence( "a",    a.begin(),    a.end()    );
    print_sequence( "soln", soln.begin(), soln.end() );
  }

  return fail;
}



int test_avx2_float_load(int fail)
{

  return fail;
}



int test_avx2_float_add(int fail)
{

  return fail;
}



int test_avx2_float_sub(int fail)
{

  return fail;
}



int test_avx2_float_mul(int fail)
{

  return fail;
}



int test_avx2_float_div(int fail)
{

  return fail;
}



int test_avx2_float_fma(int fail)
{

  return fail;
}



int test_avx2_float_reduce(int fail)
{

  return fail;
}