// Copyright (c) 2020-2021 Christopher M. Brandt
// All rights reserved

#include <iostream>
#include <nola/internal/concepts.hxx>


template <nola::Real R>
R foo(R x, R y)
{ return x * y + 5; }


template <nola::Integer I>
I bar(I x, I y)
{ return x + y * 5; }


int main()
{

  nola::Real auto r1 = foo(1.,  2. );
  nola::Real auto r2 = foo(1.1, 2.1);

  nola::Integer auto r3 = bar(1, 2);

  //nola::Real    auto r4 = foo(1,  2 ); // ERROR!
  //nola::Integer auto r5 = bar(1., 2.); // ERROR!

  std::cout << "\nr1 = " << r1 // = 7
            << "\nr2 = " << r2 // = 7.31
            << "\nr3 = " << r3 // = 11
            << std::endl;
}