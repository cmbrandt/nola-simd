#ifndef NOLA_SIMD_HXX
#define NOLA_SIMD_HXX

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