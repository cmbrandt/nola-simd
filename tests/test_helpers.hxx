// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#ifndef NOLA_TEST_HELPERS_HXX
#define NOLA_TEST_HELPERS_HXX

#include <string_view>
#include <type_traits>


//
// Helper functions used throughout

template <class I1, class I2>
bool compare_sequences(I1 first1, I1 last1, I2 first2)
{
  using T = std::common_type_t<typename I1::value_type, typename I2::value_type>;

  bool flag{false};

  for (; first1 != last1; ++first1, ++first2) {
    T diff = (*first1) - (*first2);

    if ( std::abs(diff) > T{0} )
      flag = true;
  }

  return flag;
}



template <typename I>
void print_sequence(std::string_view str, I first, I last)
{
  std::cout << str << ":" << std::endl;

  for (; first != last; ++first)
    std::cout << " " << *first;

  std::cout << std::endl;
}


#endif