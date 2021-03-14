// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#ifndef NOLA_STAT_HXX
#define NOLA_STAT_HXX

#include <nola/internal/stat_impl.hxx>

// If <nola/exec.hxx> has already been included,
// pull in the avx2 and avx512 SIMD backends.
#if defined (NOLA_EXEC_HXX)
  #include <nola/internal/stat_simd_impl.hxx>
#endif


#endif