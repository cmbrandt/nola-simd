// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#ifndef NOLA_STAT_HXX
#define NOLA_STAT_HXX

#include <nola/internal/stat_impl.hxx>

// If <nola/exec.hxx> has already been included,
// pull in the avx2 and avx512 simd backends.
#if defined (NOLA_EXEC_HXX)
  #include <nola/internal/stat_avx2_impl.hxx>
  #include <nola/internal/stat_avx512_impl.hxx>
#endif


#endif