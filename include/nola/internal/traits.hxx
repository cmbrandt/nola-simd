// Copyright (c) 2020-2021 Christopher M. Brandt
// All rights reserved

#ifndef NOLA_TRAITS_HXX
#define NOLA_TRAITS_HXX

#include <type_traits>


namespace nola
{

// Declarations
template <class T> struct is_integer;
template <class T> struct is_real;

template <class T>
  constexpr bool is_integer_v = nola::is_integer<T>::value;
template <class T>
  constexpr bool is_real_v    = nola::is_real<T>::value;


// nola::is_integer
namespace detail
{
  template <class T> struct is_integer_impl                     : public std::false_type { };
  template <>        struct is_integer_impl<short>              : public std::true_type  { };
  template <>        struct is_integer_impl<unsigned short>     : public std::true_type  { };
  template <>        struct is_integer_impl<int>                : public std::true_type  { };
  template <>        struct is_integer_impl<unsigned int>       : public std::true_type  { };
  template <>        struct is_integer_impl<long>               : public std::true_type  { };
  template <>        struct is_integer_impl<unsigned long>      : public std::true_type  { };
  template <>        struct is_integer_impl<long long>          : public std::true_type  { };
  template <>        struct is_integer_impl<unsigned long long> : public std::true_type  { };
}

template <class T>
struct is_integer
  : public detail::is_integer_impl<std::remove_cvref_t<T>> { };


// nola::is_real
namespace detail
{
  template <class T> struct is_real_impl         : public std::false_type { };
  template <>        struct is_real_impl<float>  : public std::true_type  { };
  template <>        struct is_real_impl<double> : public std::true_type  { };
}

template <class T>
struct is_real
  : public detail::is_real_impl<std::remove_cvref_t<T>> { };

} // namespace nola


#endif