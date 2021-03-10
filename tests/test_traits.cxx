// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <iostream>
#include <nola/internal/traits.hxx>


template <class R>
std::enable_if_t<nola::is_real_v<R>, R>
foo(R x, R y)
{ return x * y + 5; }


template <class I>
std::enable_if_t<nola::is_integer_v<I>, I>
bar(I x, I y)
{ return x + y * 5; }


int main()
{

  auto r1 = foo(1.,  2. );
  auto r2 = foo(1.1, 2.1);

  auto r3 = bar(1, 2);

  //auto r4 = foo(1,  2 ); // ERROR!
  //auto r5 = bar(1., 2.); // ERROR!

  std::cout << "\nr1 = " << r1 // = 7
            << "\nr2 = " << r2 // = 7.31
            << "\nr3 = " << r3 // = 11
            << std::endl;
}