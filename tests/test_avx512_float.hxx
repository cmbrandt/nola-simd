// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#ifndef NOLA_SIMD_TEST_AVX512_FLOAT_HXX
#define NOLA_SIMD_TEST_AVX512_FLOAT_HXX


int test_avx512_float_length(int);
int test_avx512_float_set_scalar(int);
int test_avx512_float_set_zero(int);
int test_avx512_float_broadcast(int);
int test_avx512_float_load(int);
int test_avx512_float_store(int);
int test_avx512_float_add(int);
int test_avx512_float_sub(int);
int test_avx512_float_mul(int);
int test_avx512_float_div(int);
int test_avx512_float_fma(int);
int test_avx512_float_reduce(int);

int test_avx512_float();


#endif