// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#ifndef NOLA_SIMD_TEST_AVX512_DOUBLE_HXX
#define NOLA_SIMD_TEST_AVX512_DOUBLE_HXX


int test_avx512_double();

int test_avx512_double_length(int);
int test_avx512_double_set_scalar(int);
int test_avx512_double_set_zero(int);
int test_avx512_double_broadcast(int);
int test_avx512_double_load(int);
int test_avx512_double_store(int);
int test_avx512_double_add(int);
int test_avx512_double_sub(int);
int test_avx512_double_mul(int);
int test_avx512_double_div(int);
int test_avx512_double_fma(int);
int test_avx512_double_reduce(int);


#endif