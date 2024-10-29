#ifndef ARITHMETIC_HPP
#define ARITHMETIC_HPP

#include "D2Q9DensityDistribution.hpp"

template <std::floating_point Scalar>
auto operator+(
    const D2Q9DensityDistribution<Scalar>& lhs,
    const D2Q9DensityDistribution<Scalar>& rhs
) -> D2Q9DensityDistribution<Scalar>;

#include "arithmetic.tpp"

#endif // ARITHMETIC_HPP
