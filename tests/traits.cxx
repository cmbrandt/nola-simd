// Copyright (c) 2019-2021 Christopher M. Brandt
// All rights reserved

#include <iostream>
#include <nola/internal/traits.hxx>


template <class Real>
Real foo(Real x, Real y)
{ return x * y + 5; }


template <class Integer>
Integer bar(Integer x, Integer y)
{ return x + y * 5; }


int main()
{

  auto r1 = foo(1.,  2. );
  auto r2 = foo(1.1, 2.1);

  auto r3 = bar(1, 2);

  //auto r4 = foo(2,   1  );
  //auto r5 = bar(1., 2.);

  std::cout << "\nr1 = " << r1 // = 7
            << "\nr2 = " << r2 // = 7.31
            << "\nr3 = " << r3 // = 11
            << std::endl;
}