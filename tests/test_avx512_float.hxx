// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#ifndef NOLA_SIMD_TEST_AVX512_FLOAT_HXX
#define NOLA_SIMD_TEST_AVX512_FLOAT_HXX


int test_avx512_float();

int test_avx512_float_width();
int test_avx512_float_set_zero_and_store();
int test_avx512_float_set_scalar();
int test_avx512_float_broadcast();
int test_avx512_float_load();
int test_avx512_float_add();
int test_avx512_float_sub();
int test_avx512_float_mul();
int test_avx512_float_div();
int test_avx512_float_fma();
int test_avx512_float_reduce();


#endif