#ifndef DENSITY_DISTRIBUTION_TPP
#define DENSITY_DISTRIBUTION_TPP

/**
 * @file DensityDistribution.tpp
 * @brief Implementation of the DensityDistribution class template that represents the discrete
 * fluid density distribution at a lattice node.
 */

;
#include "DensityDistribution.hpp"

/**
 * @brief Default constructor for DensityDistribution.
 *
 * Initializes the density distribution array with zeros.
 */
template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
DensityDistribution<Dimension, Size, Scalar>::DensityDistribution() : distribution_{0.0}
{
}

/**
 * @brief Constructor for DensityDistribution with an initializer list.
 *
 * @param distribution Initial values for the density distribution array.
 */
template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
DensityDistribution<Dimension, Size, Scalar>::DensityDistribution(
    std::initializer_list<Scalar> distribution
)
{
    std::copy(distribution.begin(), distribution.end(), distribution_.begin());
}

/**
 * @brief Overloaded subscript operator for non-const DensityDistribution objects.
 *
 * @param index Index of the element to access.
 * @return Reference to the element at the specified index.
 */
template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
auto DensityDistribution<Dimension, Size, Scalar>::operator[](std::size_t index) -> Scalar&
{
    return distribution_.at(index);
}

/**
 * @brief Overloaded subscript operator for const DensityDistribution objects.
 *
 * @param index Index of the element to access.
 * @return Const reference to the element at the specified index.
 */
template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
auto DensityDistribution<Dimension, Size, Scalar>::operator[](std::size_t index
) const -> const Scalar&
{
    return distribution_.at(index);
}

/**
 * @brief Returns an iterator to the beginning of the density distribution array.
 *
 * @return Iterator to the beginning of the density distribution array.
 */
template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
auto DensityDistribution<Dimension, Size, Scalar>::begin() -> std::array<Scalar, Size>::iterator
{
    return distribution_.begin();
}

/**
 * @brief Returns a const iterator to the beginning of the density distribution array.
 *
 * @return Const iterator to the beginning of the density distribution array.
 */
template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
auto DensityDistribution<Dimension, Size, Scalar>::begin() const
    -> std::array<Scalar, Size>::const_iterator
{
    return distribution_.begin();
}

/**
 * @brief Returns an iterator to the end of the density distribution array.
 *
 * @return Iterator to the end of the density distribution array.
 */
template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
auto DensityDistribution<Dimension, Size, Scalar>::end() -> std::array<Scalar, Size>::iterator
{
    return distribution_.end();
}

/**
 * @brief Returns a const iterator to the end of the density distribution array.
 *
 * @return Const iterator to the end of the density distribution array.
 */
template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
auto DensityDistribution<Dimension, Size, Scalar>::end() const
    -> std::array<Scalar, Size>::const_iterator
{
    return distribution_.end();
}

/**
 * @brief Returns a const iterator to the beginning of the density distribution array.
 *
 * @return Const iterator to the beginning of the density distribution array.
 */
template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
auto DensityDistribution<Dimension, Size, Scalar>::cbegin() const
    -> std::array<Scalar, Size>::const_iterator
{
    return distribution_.cbegin();
}

/**
 * @brief Returns a const iterator to the end of the density distribution array.
 *
 * @return Const iterator to the end of the density distribution array.
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
 * @return The dimension of the density distribution.
 */
template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
constexpr auto DensityDistribution<Dimension, Size, Scalar>::dimension() const -> std::size_t
{
    return Dimension;
}

/**
 * @brief Returns the number of elements in the density distribution array.
 *
 * @return The number of elements in the density distribution array.
 */
template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
constexpr auto DensityDistribution<Dimension, Size, Scalar>::size() const -> std::size_t
{
    return Size;
}

#endif // DENSITY_DISTRIBUTION_TPP
