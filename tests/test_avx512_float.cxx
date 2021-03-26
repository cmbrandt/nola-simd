// Copyright (c) 2020-2021 Christopher M. Brandt
// All rights reserved

#include <iostream>
#include <vector>
#include <nola/simd.hxx>
#include <test_helpers.hxx>
#include <test_avx512_float.hxx>


int test_avx512_float()
{
  std::cout << "\ntest_avx512_float()" << std::endl;

  int fail{0};

  fail += test_avx512_float_width();
  fail += test_avx512_float_set_zero_and_store();
  fail += test_avx512_float_set_scalar();
  fail += test_avx512_float_broadcast();
  fail += test_avx512_float_load();
  fail += test_avx512_float_add();
  fail += test_avx512_float_sub();
  fail += test_avx512_float_mul();
  fail += test_avx512_float_div();
  fail += test_avx512_float_fma();
  fail += test_avx512_float_reduce();

  if (fail == 0)
    std::cout << "test_avx512_float()  passed with zero errors." << std::endl;
  else
    std::cout << "\ntest_avx512_float()  had " << fail << " errors." << std::endl;

  return fail;
}


int test_avx512_float_width()
{
  constexpr std::int32_t r = nola::simd::avx512_width<std::int32_t, float>();
  std::int32_t soln{16};

  if (r != soln) {
    std::cout << "\nERROR! test_avx512_float_width()"
              << "\nr    = " << r
              << "\nsoln = " << soln << std::endl;
    return 1;
  }
  else
    return 0;
}


int test_avx512_float_set_zero_and_store()
{
  std::vector<float> a(16);
  std::vector<float> soln(16, 0.0);

  auto av = nola::simd::avx512_set_zero<float>();

  nola::simd::avx512_store( a.data(), av );

  bool r = compare_sequences( a.begin(), a.end(), soln.begin() );

  if (r == true) {
    std::cout << "\nERROR! test_avx512_float_set_zero_and_store()" << std::endl;
    print_sequence( "a",    a.begin(),    a.end()    );
    print_sequence( "soln", soln.begin(), soln.end() );
    return 1;
  }
  else
    return 0;
}


int test_avx512_float_set_scalar()
{
  std::vector<float> a(16);
  std::vector<float> soln(16, 5.5);

  auto av = nola::simd::avx512_set_scalar(5.5f);

  nola::simd::avx512_store( a.data(), av );

  bool r = compare_sequences( a.begin(), a.end(), soln.begin() );

  if (r == true) {
    std::cout << "\nERROR! test_avx512_float_set_scalar()" << std::endl;
    print_sequence( "a",    a.begin(),    a.end()    );
    print_sequence( "soln", soln.begin(), soln.end() );
    return 1;
  }
  else
    return 0;
}


int test_avx512_float_broadcast()
{
  std::vector<float> a(16);
  std::vector<float> soln(16, 5.5);
  float s{5.5};

  auto av = nola::simd::avx512_broadcast(&s);

  nola::simd::avx512_store( a.data(), av );

  bool r = compare_sequences( a.begin(), a.end(), soln.begin() );

  if (r == true) {
    std::cout << "\nERROR! test_avx512_float_broadcast()" << std::endl;
    print_sequence( "a",    a.begin(),    a.end()    );
    print_sequence( "soln", soln.begin(), soln.end() );
    return 1;
  }
  else
    return 0;
}


int test_avx512_float_load()
{
  std::vector<float> a(16, 5.5);
  std::vector<float> b(16);
  std::vector<float> soln(16, 5.5);

  auto av = nola::simd::avx512_load( a.data() );

  nola::simd::avx512_store( b.data(), av );

  bool r = compare_sequences( b.begin(), b.end(), soln.begin() );

  if (r == true) {
    std::cout << "\nERROR! test_avx512_float_load()" << std::endl;
    print_sequence( "b",    b.begin(),    b.end()    );
    print_sequence( "soln", soln.begin(), soln.end() );
    return 1;
  }
  else
    return 0;
}


int test_avx512_float_add()
{
  std::vector<float> a(16, 5.5);
  std::vector<float> b(16, 2.2);
  std::vector<float> c(16);
  std::vector<float> soln(16, 7.7);

  auto av = nola::simd::avx512_load( a.data() );
  auto bv = nola::simd::avx512_load( b.data() );

  auto cv = nola::simd::avx512_add(av, bv);

  nola::simd::avx512_store( c.data(), cv );

  bool r = compare_sequences( c.begin(), c.end(), soln.begin() );

  if (r == true) {
    std::cout << "\nERROR! test_avx512_float_add()" << std::endl;
    print_sequence( "c",    c.begin(),    c.end()    );
    print_sequence( "soln", soln.begin(), soln.end() );
    return 1;
  }
  else
    return 0;
}


int test_avx512_float_sub()
{
  std::vector<float> a(16, 5.5);
  std::vector<float> b(16, 2.2);
  std::vector<float> c(16);
  std::vector<float> soln(16, 3.3);

  auto av = nola::simd::avx512_load( a.data() );
  auto bv = nola::simd::avx512_load( b.data() );

  auto cv = nola::simd::avx512_sub(av, bv);

  nola::simd::avx512_store( c.data(), cv );

  bool r = compare_sequences( c.begin(), c.end(), soln.begin() );

  if (r == true) {
    std::cout << "\nERROR! test_avx512_float_sub()" << std::endl;
    print_sequence( "c",    c.begin(),    c.end()    );
    print_sequence( "soln", soln.begin(), soln.end() );
    return 1;
  }
  else
    return 0;
}


int test_avx512_float_mul()
{
  std::vector<float> a(16, 5.5);
  std::vector<float> b(16, 2.2);
  std::vector<float> c(16);
  std::vector<float> soln(16, 12.1);

  auto av = nola::simd::avx512_load( a.data() );
  auto bv = nola::simd::avx512_load( b.data() );

  auto cv = nola::simd::avx512_mul(av, bv);

  nola::simd::avx512_store( c.data(), cv );

  bool r = compare_sequences( c.begin(), c.end(), soln.begin() );

  if (r == true) {
    std::cout << "\nERROR! test_avx512_float_mul()" << std::endl;
    print_sequence( "c",    c.begin(),    c.end()    );
    print_sequence( "soln", soln.begin(), soln.end() );
    return 1;
  }
  else
    return 0;
}


int test_avx512_float_div()
{
  std::vector<float> a(16, 5.5);
  std::vector<float> b(16, 2.2);
  std::vector<float> c(16);
  std::vector<float> soln(16, 2.5);

  auto av = nola::simd::avx512_load( a.data() );
  auto bv = nola::simd::avx512_load( b.data() );

  auto cv = nola::simd::avx512_div(av, bv);

  nola::simd::avx512_store( c.data(), cv );

  bool r = compare_sequences( c.begin(), c.end(), soln.begin() );

  if (r == true) {
    std::cout << "\nERROR! test_avx512_float_div()" << std::endl;
    print_sequence( "c",    c.begin(),    c.end()    );
    print_sequence( "soln", soln.begin(), soln.end() );
    return 1;
  }
  else
    return 0;
}


int test_avx512_float_fma()
{
  std::vector<float> a(16, 5.5);
  std::vector<float> b(16, 2.2);
  std::vector<float> c(16, 1.1);
  std::vector<float> d(16);
  std::vector<float> soln(16, 13.2);

  auto av = nola::simd::avx512_load( a.data() );
  auto bv = nola::simd::avx512_load( b.data() );
  auto cv = nola::simd::avx512_load( c.data() );

  auto dv = nola::simd::avx512_fma(av, bv, cv);

  nola::simd::avx512_store( d.data(), dv );

  bool r = compare_sequences( d.begin(), d.end(), soln.begin() );

  if (r == true) {
    std::cout << "\nERROR! test_avx512_float_fma()" << std::endl;
    print_sequence( "d",    d.begin(),    d.end()    );
    print_sequence( "soln", soln.begin(), soln.end() );
    return 1;
  }
  else
    return 0;
}


int test_avx512_float_reduce()
{
  std::vector<float> a{ 1.1, 4.9, 2.3, 3.5, 5.7, 2.8, 0.6, 8.0,
                        6.2, 2.5, 4.3, 0.7, 4.8, 3.0, 1.8, 2.1 };
  float soln{54.3};

  auto av = nola::simd::avx512_load( a.data() );

  float r = nola::simd::avx512_reduce(av);

  if (r != soln) {
    std::cout << "\nERROR! test_avx512_float_reduce()"
              << "\nr    = " << r
              << "\nsoln = " << soln << std::endl;
    return 1;
  }
  else
    return 0;
}