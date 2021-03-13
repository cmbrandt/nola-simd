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

  fail += test_avx2_float_length();
  fail += test_avx2_float_set_zero_and_store();
  fail += test_avx2_float_set_scalar();
  fail += test_avx2_float_broadcast();
  fail += test_avx2_float_load();
  fail += test_avx2_float_add();
  fail += test_avx2_float_sub();
  fail += test_avx2_float_mul();
  fail += test_avx2_float_div();
  fail += test_avx2_float_fma();
  fail += test_avx2_float_reduce();

  if (fail == 0)
    std::cout << "\ntest_avx2_float()    passed with zero errors." << std::endl;
  else
    std::cout << "\ntest_avx2_float()    had " << fail << " errors." << std::endl;

  return fail;
}



int test_avx2_float_length()
{
  std::int32_t r = nola::simd::avx2_length<float>();
  std::int32_t soln{8};

  if (r != soln) {
    std::cout << "\nERROR! nola::simd::avx2_length()"
              << "\nr    = " << r
              << "\nsoln = " << soln << std::endl;
    return 1;
  }
  else
    return 0;
}



int test_avx2_float_set_zero_and_store()
{
  std::vector<float> a(8);
  std::vector<float> soln{ 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  auto av = nola::simd::avx2_set_zero<float>();

  nola::simd::avx2_store( a.data(), av );

  bool r = compare_sequences( a.begin(), a.end(), soln.begin() );

  if (r == true) {
    std::cout << "\nERROR! nola::simd::avx2_set_zero() / nola::simd::avx2_store()" << std::endl;
    print_sequence( "a",    a.begin(),    a.end()    );
    print_sequence( "soln", soln.begin(), soln.end() );
    return 1;
  }
  else
    return 0;
}



int test_avx2_float_set_scalar()
{
  std::vector<float> a(8);
  std::vector<float> soln{ 5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5 };

  auto av = nola::simd::avx2_set_scalar(5.5f);

  nola::simd::avx2_store( a.data(), av );

  bool r = compare_sequences( a.begin(), a.end(), soln.begin() );

  if (r == true) {
    std::cout << "\nERROR! nola::simd::avx2_set_scalar()" << std::endl;
    print_sequence( "a",    a.begin(),    a.end()    );
    print_sequence( "soln", soln.begin(), soln.end() );
    return 1;
  }
  else
    return 0;
}



int test_avx2_float_broadcast()
{
  std::vector<float> a(8);
  std::vector<float> soln{ 5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5 };
  float s{5.5};

  auto av = nola::simd::avx2_broadcast(&s);

  nola::simd::avx2_store( a.data(), av );

  bool r = compare_sequences( a.begin(), a.end(), soln.begin() );

  if (r == true) {
    std::cout << "\nERROR! nola::simd::avx2_broadcast()" << std::endl;
    print_sequence( "a",    a.begin(),    a.end()    );
    print_sequence( "soln", soln.begin(), soln.end() );
    return 1;
  }
  else
    return 0;
}



int test_avx2_float_load()
{
  std::vector<float> a{ 5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5 };
  std::vector<float> b(8);
  std::vector<float> soln{ 5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5 };

  auto av = nola::simd::avx2_load( a.data() );

  nola::simd::avx2_store( b.data(), av );

  bool r = compare_sequences( b.begin(), b.end(), soln.begin() );

  if (r == true) {
    std::cout << "\nERROR! nola::simd::avx2_load()" << std::endl;
    print_sequence( "b",    b.begin(),    b.end()    );
    print_sequence( "soln", soln.begin(), soln.end() );
    return 1;
  }
  else
    return 0;
}



int test_avx2_float_add()
{
  std::vector<float> a{ 5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5 }; 
  std::vector<float> b{ 2.2, 2.2, 2.2, 2.2, 2.2, 2.2, 2.2, 2.2 }; 
  std::vector<float> soln{ 7.7, 7.7, 7.7, 7.7, 7.7, 7.7, 7.7, 7.7 };

  std::vector<float> c(8);

  auto av = nola::simd::avx2_load( a.data() );
  auto bv = nola::simd::avx2_load( b.data() );

  auto cv = nola::simd::avx2_add(av, bv);

  nola::simd::avx2_store( c.data(), cv );

  bool r = compare_sequences( c.begin(), c.end(), soln.begin() );

  if (r == true) {
    std::cout << "\nERROR! nola::simd::avx2_add()" << std::endl;
    print_sequence( "c",    c.begin(),    c.end()    );
    print_sequence( "soln", soln.begin(), soln.end() );
    return 1;
  }
  else
    return 0;
}



int test_avx2_float_sub()
{
  std::vector<float> a{ 5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5 }; 
  std::vector<float> b{ 2.2, 2.2, 2.2, 2.2, 2.2, 2.2, 2.2, 2.2 }; 
  std::vector<float> soln{ 3.3, 3.3, 3.3, 3.3, 3.3, 3.3, 3.3, 3.3 };

  std::vector<float> c(8);

  auto av = nola::simd::avx2_load( a.data() );
  auto bv = nola::simd::avx2_load( b.data() );

  auto cv = nola::simd::avx2_sub(av, bv);

  nola::simd::avx2_store( c.data(), cv );

  bool r = compare_sequences( c.begin(), c.end(), soln.begin() );

  if (r == true) {
    std::cout << "\nERROR! nola::simd::avx2_sub()" << std::endl;
    print_sequence( "c",    c.begin(),    c.end()    );
    print_sequence( "soln", soln.begin(), soln.end() );
    return 1;
  }
  else
    return 0;
}



int test_avx2_float_mul()
{
  std::vector<float> a{ 5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5 }; 
  std::vector<float> b{ 2.2, 2.2, 2.2, 2.2, 2.2, 2.2, 2.2, 2.2 }; 
  std::vector<float> soln{ 12.1, 12.1, 12.1, 12.1, 12.1, 12.1, 12.1, 12.1 };

  std::vector<float> c(8);

  auto av = nola::simd::avx2_load( a.data() );
  auto bv = nola::simd::avx2_load( b.data() );

  auto cv = nola::simd::avx2_mul(av, bv);

  nola::simd::avx2_store( c.data(), cv );

  bool r = compare_sequences( c.begin(), c.end(), soln.begin() );

  if (r == true) {
    std::cout << "\nERROR! nola::simd::avx2_mul()" << std::endl;
    print_sequence( "c",    c.begin(),    c.end()    );
    print_sequence( "soln", soln.begin(), soln.end() );
    return 1;
  }
  else
    return 0;
}



int test_avx2_float_div()
{
  std::vector<float> a{ 5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5 }; 
  std::vector<float> b{ 2.2, 2.2, 2.2, 2.2, 2.2, 2.2, 2.2, 2.2 }; 
  std::vector<float> soln{ 2.5, 2.5, 2.5, 2.5, 2.5, 2.5, 2.5, 2.5 };

  std::vector<float> c(8);

  auto av = nola::simd::avx2_load( a.data() );
  auto bv = nola::simd::avx2_load( b.data() );

  auto cv = nola::simd::avx2_div(av, bv);

  nola::simd::avx2_store( c.data(), cv );

  bool r = compare_sequences( c.begin(), c.end(), soln.begin() );

  if (r == true) {
    std::cout << "\nERROR! nola::simd::avx2_div()" << std::endl;
    print_sequence( "c",    c.begin(),    c.end()    );
    print_sequence( "soln", soln.begin(), soln.end() );
    return 1;
  }
  else
    return 0;
}



int test_avx2_float_fma()
{
  std::vector<float> a{ 5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5, 5.5 };
  std::vector<float> b{ 2.2, 2.2, 2.2, 2.2, 2.2, 2.2, 2.2, 2.2 };
  std::vector<float> c{ 1.1, 1.1, 1.1, 1.1, 1.1, 1.1, 1.1, 1.1 };
  std::vector<float> soln{ 13.2, 13.2, 13.2, 13.2, 13.2, 13.2, 13.2, 13.2 };

  std::vector<float> d(8);

  auto av = nola::simd::avx2_load( a.data() );
  auto bv = nola::simd::avx2_load( b.data() );
  auto cv = nola::simd::avx2_load( c.data() );

  auto dv = nola::simd::avx2_fma(av, bv, cv);

  nola::simd::avx2_store( d.data(), dv );

  bool r = compare_sequences( d.begin(), d.end(), soln.begin() );

  if (r == true) {
    std::cout << "\nERROR! nola::simd::avx2_fma()" << std::endl;
    print_sequence( "d",    d.begin(),    d.end()    );
    print_sequence( "soln", soln.begin(), soln.end() );
    return 1;
  }
  else
    return 0;
}


// TODO: Complete this test after finishing the avx2_reduce<float> impl.
int test_avx2_float_reduce()
{


  return 0;
}