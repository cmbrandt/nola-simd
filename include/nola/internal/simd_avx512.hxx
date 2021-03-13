// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#ifndef NOLA_AVX512_HXX
#define NOLA_AVX512_HXX

#include <cstdint>
#include <immintrin.h>


namespace nola
{
namespace simd
{


//----------------------------------------------------------------------------//
// Type aliases


using v512f = __m512;
using v512d = __m512d;


//----------------------------------------------------------------------------//
// Declarations


//
// Generic

template <class Real>
inline std::int32_t avx512_length();

template <class Real>
inline auto avx512_set_scalar(Real a);

template <class Real>
inline auto avx512_set_zero();


//
// Single precision

inline v512f avx512_broadcast(float const* addr);
inline v512f avx512_load(float const* addr);
inline void  avx512_store(float* addr, v512f a);
inline v512f avx512_add(v512f a, v512f b);
inline v512f avx512_sub(v512f a, v512f b);
inline v512f avx512_mul(v512f a, v512f b);
inline v512f avx512_div(v512f a, v512f b);
inline v512f avx512_fma(v512f a, v512f b, v512f c);
inline float avx512_reduce(v512f a);


//
// Double precision

inline v512d  avx512_broadcast(double const* addr);
inline v512d  avx512_load(double const* addr);
inline void   avx512_store(double* addr, v512d a);
inline v512d  avx512_add(v512d a, v512d b);
inline v512d  avx512_sub(v512d a, v512d b);
inline v512d  avx512_mul(v512d a, v512d b);
inline v512d  avx512_div(v512d a, v512d b);
inline v512d  avx512_fma(v512d a, v512d b, v512d c);
inline double avx512_reduce(v512d a);


//----------------------------------------------------------------------------//
// Helper classes

namespace detail
{

//
// avx2_length

template <class Real> // <Real R>
struct simd_mm512_length {
  // static std::int32_t
  // mm512_length();
};

template <>
struct simd_mm512_length<float> {
  static std::int32_t
  mm512_length() { return std::int32_t{16}; }
};

template <>
struct simd_mm512_length<double> {
  static std::int32_t
  mm512_length() { return std::int32_t{8}; }
};



//
// avx2_set_zero

template <class Real> // <Real R>
struct simd_mm512_setzero {
  // static auto
  // mm512_setzero();
};

template <>
struct simd_mm512_setzero<float> {
  static auto
  mm512_setzero() { return _mm512_setzero_ps(); }
};

template <>
struct simd_mm512_setzero<double> {
  static auto
  mm512_setzero() { return _mm512_setzero_pd(); }
};

} //namespace detail



//----------------------------------------------------------------------------//
// Definitions


//
// Generic

template <class Real> // <Real R>
inline std::int32_t
avx512_length() { return detail::simd_mm512_length<Real>::mm512_length(); }

template <class Real> // <Real R>
inline auto
avx512_set_zero() { return detail::simd_mm512_setzero<Real>::mm512_setzero(); }


//
// Single precision

inline v512f
avx512_broadcast(float const* addr)
{
  __m128 a = _mm_broadcast_ss(addr); 
  return _mm512_broadcastss_ps(a);
}

inline v512f
avx512_load(float const* addr) { return _mm512_loadu_ps(addr); }

inline void
avx512_store(float* addr, v512f a) { _mm512_storeu_ps(addr, a); }

inline v512f
avx512_add(v512f a, v512f b) { return _mm512_add_ps(a, b); }

inline v512f 
avx512_sub(v512f a, v512f b) { return _mm512_sub_ps(a, b); }

inline v512f
avx512_mul(v512f a, v512f b) { return _mm512_mul_ps(a, b); }

inline v512f
avx512_div(v512f a, v512f b) { return _mm512_div_ps(a, b); }

inline v512f
avx512_fma(v512f a, v512f b, v512f c) { return _mm512_fmadd_ps(a, b, c); }

inline float
avx512_reduce(v512f a) { return _mm512_reduce_add_ps(a); }


//
// Double precision

inline v512d
avx512_set_zero() { return _mm512_setzero_pd(); }

inline v512d
avx512_broadcast(double const* addr)
{
  __m128d a = _mm_load1_pd(addr); 
  return _mm512_broadcastsd_pd(a);
}

inline v512d
avx512_load(double const* addr) { return _mm512_loadu_pd(addr); }

inline void
avx512_store(double* addr, v512d a) { _mm512_storeu_pd(addr, a); }

inline v512d
avx512_add(v512d a, v512d b) { return _mm512_add_pd(a, b); }

inline v512d 
avx512_sub(v512d a, v512d b) { return _mm512_sub_pd(a, b); }

inline v512d
avx512_mul(v512d a, v512d b) { return _mm512_mul_pd(a, b); }

inline v512d
avx512_div(v512d a, v512d b) { return _mm512_div_pd(a, b); }

inline v512d
avx512_fma(v512d a, v512d b, v512d c) { return _mm512_fmadd_pd(a, b, c); }

inline double
avx512_reduce(v512d a) { return _mm512_reduce_add_pd(a); }


} // namespace simd
} // namespace nola


#endif