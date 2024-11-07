#ifndef ARITHMETIC_HPP
#define ARITHMETIC_HPP

#include "D2Q9DensityDistribution.hpp"

template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
auto operator+(
    const D2Q9DensityDistribution<Dimension, Size, Scalar>& lhs,
    const D2Q9DensityDistribution<Dimension, Size, Scalar>& rhs
) -> D2Q9DensityDistribution<Dimension, Size, Scalar>;

template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
auto operator-(
    const D2Q9DensityDistribution<Dimension, Size, Scalar>& lhs,
    const D2Q9DensityDistribution<Dimension, Size, Scalar>& rhs
) -> D2Q9DensityDistribution<Dimension, Size, Scalar>;

#include "arithmetic.tpp"

#endif // ARITHMETIC_HPP
