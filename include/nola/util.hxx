// Copyright (c) 2020-2021 Christopher M. Brandt
// All rights reserved

#ifndef NOLA_UTIL_HXX
#define NOLA_UTIL_HXX

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <string_view>
#include <nola/internal/concepts.hxx>


namespace nola
{
namespace util
{


//------------------------------------------------------------------------------
// Declarations


template <Real R>
inline void
print_vector(std::string_view s, std::int32_t size, R const a []);

template <Real R>
inline void
print_vector(std::string_view s, std::int32_t size, R const a[], std::int32_t precision, std::int32_t width);


template <Real R>
inline void
print_matrix(std::string_view s, std::int32_t rows, std::int32_t cols, R const a[]);

template <Real R>
inline void
print_matrix(std::string_view s, std::int32_t rows, std::int32_t cols, R const a[], std::int32_t precision, std::int32_t width);


//------------------------------------------------------------------------------
// Defintions


//
// Print Vector

// Display all elements of a one-dimensional container
template <Real R>
void print_vector(std::string_view s, std::int32_t size, R const a[], std::int32_t precision, std::int32_t width)
{
  std::cout << s << " = [" << std::endl;

  for (std::int32_t i{0}; i < size; ++i)
    std::cout << " " << std::setprecision(precision)
                     << std::setw(width) << a[i];

  std::cout << "\n]" << std::endl;
}

template <Real R>
void print_vector(std::string_view s, std::int32_t size, R const a[])
{
  return print_vector(s, size, a, 6, 8);
}


//
// Print Matrix

// Display all elements of a two-dimensional container
template <Real R>
void print_matrix(std::string_view s, std::int32_t rows, std::int32_t cols, R const a[], std::int32_t precision , std::int32_t width )
{
  std::cout << s << " = [" << std::endl;

  for (std::int32_t i = 0; i < rows; ++i) {
    for (std::int32_t j = 0; j < cols; ++j) {
      std::cout << " " << std::setprecision(precision)
                       << std::setw(width) << a[j*rows+i];
    }

    std::cout << std::endl;
  }

  std::cout << "]" << std::endl;
}

template <Real R>
void print_matrix(std::string_view s, std::int32_t rows, std::int32_t cols, R const a[] )
{
  return print_matrix(s, rows, cols, a, 6, 8);
}


} // namespace util
} // namespace nola


#endif