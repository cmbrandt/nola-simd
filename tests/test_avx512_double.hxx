// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#ifndef NOLA_SIMD_TEST_AVX512_DOUBLE_HXX
#define NOLA_SIMD_TEST_AVX512_DOUBLE_HXX


int test_avx512_double();

int test_avx512_double_width();
int test_avx512_double_set_zero_and_store();
int test_avx512_double_set_scalar();
int test_avx512_double_broadcast();
int test_avx512_double_load();
int test_avx512_double_store();
int test_avx512_double_add();
int test_avx512_double_sub();
int test_avx512_double_mul();
int test_avx512_double_div();
int test_avx512_double_fma();
int test_avx512_double_reduce();


#endif