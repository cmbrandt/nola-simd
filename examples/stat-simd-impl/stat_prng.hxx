// Copyright (c) 2020-2021 Christopher M. Brandt
// All rights reserved

#ifndef NOLA_PRNG_HXX
#define NOLA_PRNG_HXX

#include <random>
#include <nola/internal/concepts.hxx>


template <nola::Integer I, nola::Real R>
class Random_values {

  using Generator    = std::mt19937;
  using Distribution = std::normal_distribution<R>;

public:
  Random_values() = default;
  Random_values(I seed) : g(seed) { }

  R operator()() { return dist(g); }

private:
  Generator    g{std::random_device{}()};
  Distribution dist{0.5, 2.0};
};


#endif
