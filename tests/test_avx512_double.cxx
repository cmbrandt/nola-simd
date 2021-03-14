// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <iostream>
#include <vector>
#include <nola/simd.hxx>
#include <test_helpers.hxx>
#include <test_avx512_double.hxx>


int test_avx512_double()
{
  std::cout << "\ntest_avx512_double()" << std::endl;

  int fail{0};

  fail += test_avx512_double_width();
  fail += test_avx512_double_set_zero_and_store();
  fail += test_avx512_double_set_scalar();
  fail += test_avx512_double_broadcast();
  fail += test_avx512_double_load();
  fail += test_avx512_double_add();
  fail += test_avx512_double_sub();
  fail += test_avx512_double_mul();
  fail += test_avx512_double_div();
  fail += test_avx512_double_fma();
  fail += test_avx512_double_reduce();

  if (fail == 0)
    std::cout << "test_avx512_double() passed with zero errors." << std::endl;
  else
    std::cout << "\ntest_avx512_double() had " << fail << " errors." << std::endl;

  return fail;
}


int test_avx512_double_width()
{
  std::int32_t r = nola::simd::avx512_width<double>();
  std::int32_t soln{8};

  if (r != soln) {
    std::cout << "\nERROR! test_avx512_double_width()"
              << "\nr    = " << r
              << "\nsoln = " << soln << std::endl;
    return 1;
  }
  else
    return 0;
}


int test_avx512_double_set_zero_and_store()
{
  std::vector<double> a(8);
  std::vector<double> soln(8, 0.0);

  auto av = nola::simd::avx512_set_zero<double>();

  nola::simd::avx512_store( a.data(), av );

  bool r = compare_sequences( a.begin(), a.end(), soln.begin() );

  if (r == true) {
    std::cout << "\nERROR! test_avx512_double_set_zero_and_store()" << std::endl;
    print_sequence( "a",    a.begin(),    a.end()    );
    print_sequence( "soln", soln.begin(), soln.end() );
    return 1;
  }
  else
    return 0;
}


int test_avx512_double_set_scalar()
{
  std::vector<double> a(8);
  std::vector<double> soln(8, 5.5);

  auto av = nola::simd::avx512_set_scalar(5.5);

  nola::simd::avx512_store( a.data(), av );

  bool r = compare_sequences( a.begin(), a.end(), soln.begin() );

  if (r == true) {
    std::cout << "\nERROR! test_avx512_double_set_scalar()" << std::endl;
    print_sequence( "a",    a.begin(),    a.end()    );
    print_sequence( "soln", soln.begin(), soln.end() );
    return 1;
  }
  else
    return 0;
}


int test_avx512_double_broadcast()
{
  std::vector<double> a(8);
  std::vector<double> soln(8, 5.5);
  double s{5.5};

  auto av = nola::simd::avx512_broadcast(&s);

  nola::simd::avx512_store( a.data(), av );

  bool r = compare_sequences( a.begin(), a.end(), soln.begin() );

  if (r == true) {
    std::cout << "\nERROR! test_avx512_double_broadcast()" << std::endl;
    print_sequence( "a",    a.begin(),    a.end()    );
    print_sequence( "soln", soln.begin(), soln.end() );
    return 1;
  }
  else
    return 0;
}


int test_avx512_double_load()
{
  std::vector<double> a(8, 5.5);
  std::vector<double> b(8);
  std::vector<double> soln(8, 5.5);

  auto av = nola::simd::avx512_load( a.data() );

  nola::simd::avx512_store( b.data(), av );

  bool r = compare_sequences( b.begin(), b.end(), soln.begin() );

  if (r == true) {
    std::cout << "\nERROR! test_avx512_double_load()" << std::endl;
    print_sequence( "b",    b.begin(),    b.end()    );
    print_sequence( "soln", soln.begin(), soln.end() );
    return 1;
  }
  else
    return 0;
}


int test_avx512_double_add()
{
  std::vector<double> a(8, 5.5);
  std::vector<double> b(8, 2.2);
  std::vector<double> c(8);
  std::vector<double> soln(8, 7.7);

  auto av = nola::simd::avx512_load( a.data() );
  auto bv = nola::simd::avx512_load( b.data() );

  auto cv = nola::simd::avx512_add(av, bv);

  nola::simd::avx512_store( c.data(), cv );

  bool r = compare_sequences( c.begin(), c.end(), soln.begin() );

  if (r == true) {
    std::cout << "\nERROR! test_avx512_double_add()" << std::endl;
    print_sequence( "c",    c.begin(),    c.end()    );
    print_sequence( "soln", soln.begin(), soln.end() );
    return 1;
  }
  else
    return 0;
}


int test_avx512_double_sub()
{
  std::vector<double> a(8, 5.5);
  std::vector<double> b(8, 2.2);
  std::vector<double> c(8);
  std::vector<double> soln(8, 3.3);

  auto av = nola::simd::avx512_load( a.data() );
  auto bv = nola::simd::avx512_load( b.data() );

  auto cv = nola::simd::avx512_sub(av, bv);

  nola::simd::avx512_store( c.data(), cv );

  bool r = compare_sequences( c.begin(), c.end(), soln.begin() );

  if (r == true) {
    std::cout << "\nERROR! test_avx512_double_sub()" << std::endl;
    print_sequence( "c",    c.begin(),    c.end()    );
    print_sequence( "soln", soln.begin(), soln.end() );
    return 1;
  }
  else
    return 0;
}


int test_avx512_double_mul()
{
  std::vector<double> a(8, 5.5);
  std::vector<double> b(8, 2.2);
  std::vector<double> c(8);
  std::vector<double> soln(8, 12.1);

  auto av = nola::simd::avx512_load( a.data() );
  auto bv = nola::simd::avx512_load( b.data() );

  auto cv = nola::simd::avx512_mul(av, bv);

  nola::simd::avx512_store( c.data(), cv );

  bool r = compare_sequences( c.begin(), c.end(), soln.begin() );

  if (r == true) {
    std::cout << "\nERROR! test_avx512_double_mul()" << std::endl;
    print_sequence( "c",    c.begin(),    c.end()    );
    print_sequence( "soln", soln.begin(), soln.end() );
    return 1;
  }
  else
    return 0;
}


int test_avx512_double_div()
{
  std::vector<double> a(8, 5.5);
  std::vector<double> b(8, 2.2);
  std::vector<double> c(8);
  std::vector<double> soln(8, 2.5);

  auto av = nola::simd::avx512_load( a.data() );
  auto bv = nola::simd::avx512_load( b.data() );

  auto cv = nola::simd::avx512_div(av, bv);

  nola::simd::avx512_store( c.data(), cv );

  bool r = compare_sequences( c.begin(), c.end(), soln.begin() );

  if (r == true) {
    std::cout << "\nERROR! test_avx512_double_div()" << std::endl;
    print_sequence( "c",    c.begin(),    c.end()    );
    print_sequence( "soln", soln.begin(), soln.end() );
    return 1;
  }
  else
    return 0;
}


int test_avx512_double_fma()
{
  std::vector<double> a(8, 5.5);
  std::vector<double> b(8, 2.2);
  std::vector<double> c(8, 1.1);
  std::vector<double> d(8);
  std::vector<double> soln(8, 13.2);

  auto av = nola::simd::avx512_load( a.data() );
  auto bv = nola::simd::avx512_load( b.data() );
  auto cv = nola::simd::avx512_load( c.data() );

  auto dv = nola::simd::avx512_fma(av, bv, cv);

  nola::simd::avx512_store( d.data(), dv );

  bool r = compare_sequences( d.begin(), d.end(), soln.begin() );

  if (r == true) {
    std::cout << "\nERROR! test_avx512_double_fma()" << std::endl;
    print_sequence( "d",    d.begin(),    d.end()    );
    print_sequence( "soln", soln.begin(), soln.end() );
    return 1;
  }
  else
    return 0;
}


int test_avx512_double_reduce()
{
  std::vector<double> a{ 1.1, 4.9, 2.3, 3.5, 5.7, 2.8, 0.6, 8.0 };
  double soln{28.9};

  auto av = nola::simd::avx512_load( a.data() );

  double r = nola::simd::avx512_reduce(av);

  if (r != soln) {
    std::cout << "\nERROR! test_avx512_double_reduce()"
              << "\nr    = " << r
              << "\nsoln = " << soln << std::endl;
    return 1;
  }
  else
    return 0;
}