#ifndef DENSITY_DISTRIBUTION_TPP
#define DENSITY_DISTRIBUTION_TPP

/**
 * @file DensityDistribution.tpp
 * @brief Implementation of the DensityDistribution class template that represents a generic density
 * distribution at a lattice node.
 */

;
#include "DensityDistribution.hpp"

/**
 * @brief Default constructor for DensityDistribution.
 *
 * Initializes the density distribution with zeros.
 *
 * @tparam Dimension The number of spatial dimensions.
 * @tparam Size The number of lattice vectors at each lattice node.
 * @tparam Scalar The floating-point type of scalar values.
 */
template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
DensityDistribution<Dimension, Size, Scalar>::DensityDistribution() : distribution_{0.0}
{
}

/**
 * @brief Constructor for DensityDistribution with an initializer list.
 *
 * Initializes the density distribution with the values in the initializer list.
 *
 * @param distribution Initial values for the density distribution.
 *
 * @tparam Dimension The number of spatial dimensions.
 * @tparam Size The number of lattice vectors at each lattice node.
 * @tparam Scalar The floating-point type of scalar values.
 */
template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
DensityDistribution<Dimension, Size, Scalar>::DensityDistribution(
    std::initializer_list<Scalar> distribution
)
{
    std::copy(distribution.begin(), distribution.end(), distribution_.begin());
}

/**
 * @brief Subscript operator for non-const DensityDistribution objects.
 *
 * @param index Index of the element to access.
 * @return Non-const reference to the element at the specified index.
 *
 * @tparam Dimension The number of spatial dimensions.
 * @tparam Size The number of lattice vectors at each lattice node.
 * @tparam Scalar The floating-point type of scalar values.
 */
template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
auto DensityDistribution<Dimension, Size, Scalar>::operator[](std::size_t index) -> Scalar&
{
    return distribution_.at(index);
}

/**
 * @brief Subscript operator for const DensityDistribution objects.
 *
 * @param index Index of the element to access.
 * @return Const reference to the element at the specified index.
 *
 * @tparam Dimension The number of spatial dimensions.
 * @tparam Size The number of lattice vectors at each lattice node.
 * @tparam Scalar The floating-point type of scalar values.
 */
template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
auto DensityDistribution<Dimension, Size, Scalar>::operator[](std::size_t index
) const -> const Scalar&
{
    return distribution_.at(index);
}

/**
 * @brief Returns a non-const iterator to the beginning of the density distribution container.
 *
 * @return Non-const iterator to the beginning of the density distribution container.
 *
 * @tparam Dimension The number of spatial dimensions.
 * @tparam Size The number of lattice vectors at each lattice node.
 * @tparam Scalar The floating-point type of scalar values.
 */
template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
auto DensityDistribution<Dimension, Size, Scalar>::begin() -> std::array<Scalar, Size>::iterator
{
    return distribution_.begin();
}

/**
 * @brief Returns a const iterator to the beginning of the density distribution container.
 *
 * @return Const iterator to the beginning of the density distribution container.
 *
 * @tparam Dimension The number of spatial dimensions.
 * @tparam Size The number of lattice vectors at each lattice node.
 * @tparam Scalar The floating-point type of scalar values.
 */
template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
auto DensityDistribution<Dimension, Size, Scalar>::begin() const
    -> std::array<Scalar, Size>::const_iterator
{
    return distribution_.begin();
}

/**
 * @brief Returns a non-const iterator to the end of the density distribution container.
 *
 * @return Non-const iterator to the end of the density distribution container.
 *
 * @tparam Dimension The number of spatial dimensions.
 * @tparam Size The number of lattice vectors at each lattice node.
 * @tparam Scalar The floating-point type of scalar values.
 */
template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
auto DensityDistribution<Dimension, Size, Scalar>::end() -> std::array<Scalar, Size>::iterator
{
    return distribution_.end();
}

/**
 * @brief Returns a const iterator to the end of the density distribution container.
 *
 * @return Const iterator to the end of the density distribution container.
 *
 * @tparam Dimension The number of spatial dimensions.
 * @tparam Size The number of lattice vectors at each lattice node.
 * @tparam Scalar The floating-point type of scalar values.
 */
template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
auto DensityDistribution<Dimension, Size, Scalar>::end() const
    -> std::array<Scalar, Size>::const_iterator
{
    return distribution_.end();
}

/**
 * @brief Returns a const iterator to the beginning of the density distribution container.
 *
 * @return Const iterator to the beginning of the density distribution container.
 *
 * @tparam Dimension The number of spatial dimensions.
 * @tparam Size The number of lattice vectors at each lattice node.
 * @tparam Scalar The floating-point type of scalar values.
 */
template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
auto DensityDistribution<Dimension, Size, Scalar>::cbegin() const
    -> std::array<Scalar, Size>::const_iterator
{
    return distribution_.cbegin();
}

/**
 * @brief Returns a const iterator to the end of the density distribution container.
 *
 * @return Const iterator to the end of the density distribution container.
 *
 * @tparam Dimension The number of spatial dimensions.
 * @tparam Size The number of lattice vectors at each lattice node.
 * @tparam Scalar The floating-point type of scalar values.
 */
template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
auto DensityDistribution<Dimension, Size, Scalar>::cend() const
    -> std::array<Scalar, Size>::const_iterator
{
    return distribution_.cend();
}

/**
 * @brief Returns the dimension of the density distribution.
 *
 * Returns the dimension of the density distribution, which is a compile-time constant.
 *
 * @return The dimension of the density distribution.
 *
 * @tparam Dimension The number of spatial dimensions.
 * @tparam Size The number of lattice vectors at each lattice node.
 * @tparam Scalar The floating-point type of scalar values.
 */
template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
constexpr auto DensityDistribution<Dimension, Size, Scalar>::dimension() const -> std::size_t
{
    return Dimension;
}

/**
 * @brief Returns the number of elements in the density distribution.
 *
 * Returns the number of elements in the density distribution, which is a compile-time constant.
 *
 * @return The number of elements in the density distribution.
 *
 * @tparam Dimension The number of spatial dimensions.
 * @tparam Size The number of lattice vectors at each lattice node.
 * @tparam Scalar The floating-point type of scalar values.
 */
template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
constexpr auto DensityDistribution<Dimension, Size, Scalar>::size() const -> std::size_t
{
    return Size;
}

#endif // DENSITY_DISTRIBUTION_TPP
