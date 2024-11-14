#ifndef ARITHMETIC_TPP
#define ARITHMETIC_TPP

/**
 * @file arithmetic.tpp
 * @brief Implementation of non-member arithmetic functions that operate on DensityDistribution
 * objects.
 */

;
#include "arithmetic.hpp"

/**
 * @brief Adds two density distributions element-wise.
 *
 * @param lhs The left-hand side density distribution.
 * @param rhs The right-hand side density distribution.
 * @return A new density distribution containing the element-wise sum of lhs and rhs.
 *
 * @tparam Dimension The number of spatial dimensions.
 * @tparam Size The number of lattice vectors at each lattice node.
 * @tparam Scalar The floating-point type of scalar values.
 */
template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
auto operator+(
    const DensityDistribution<Dimension, Size, Scalar>& lhs,
    const DensityDistribution<Dimension, Size, Scalar>& rhs
) -> DensityDistribution<Dimension, Size, Scalar>
{
    DensityDistribution<Dimension, Size, Scalar> result;

    for (std::size_t i = 0; i < result.size(); ++i)
    {
        result[i] = lhs[i] + rhs[i];
    }

    return result;
}

/**
 * @brief Subtracts two density distributions element-wise.
 *
 * @param lhs The left-hand side density distribution.
 * @param rhs The right-hand side density distribution.
 * @return A new density distribution containing the element-wise difference between lhs and rhs.
 *
 * @tparam Dimension The number of spatial dimensions.
 * @tparam Size The number of lattice vectors at each lattice node.
 * @tparam Scalar The floating-point type of scalar values.
 */
template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
auto operator-(
    const DensityDistribution<Dimension, Size, Scalar>& lhs,
    const DensityDistribution<Dimension, Size, Scalar>& rhs
) -> DensityDistribution<Dimension, Size, Scalar>
{
    DensityDistribution<Dimension, Size, Scalar> result;

    for (std::size_t i = 0; i < result.size(); ++i)
    {
        result[i] = lhs[i] - rhs[i];
    }

    return result;
}

#endif // ARITHMETIC_TPP
