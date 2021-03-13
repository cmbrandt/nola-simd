// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#ifndef NOLA_CONCEPTS_HXX
#define NOLA_CONCEPTS_HXX

#include <nola/internal/traits.hxx>


namespace nola
{

// concept Integer
template <class T>
concept Integer = nola::is_integer_v<T>;


// concept Real
template <class T>
concept Real = nola::is_real_v<T>;

} // namespace nola


#endif