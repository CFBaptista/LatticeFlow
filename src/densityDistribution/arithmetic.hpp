#ifndef ARITHMETIC_HPP
#define ARITHMETIC_HPP

/**
 * @file arithmetic.hpp
 * @brief Declaration of non-member arithmetic functions that operate on DensityDistribution
 * objects.
 */

#include "DensityDistribution.hpp"

template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
auto operator+(
    const DensityDistribution<Dimension, Size, Scalar>& lhs,
    const DensityDistribution<Dimension, Size, Scalar>& rhs
) -> DensityDistribution<Dimension, Size, Scalar>;

template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
auto operator-(
    const DensityDistribution<Dimension, Size, Scalar>& lhs,
    const DensityDistribution<Dimension, Size, Scalar>& rhs
) -> DensityDistribution<Dimension, Size, Scalar>;

#include "arithmetic.tpp"

#endif // ARITHMETIC_HPP
