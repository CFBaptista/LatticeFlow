#ifndef DENSITY_DISTRIBUTION_HPP
#define DENSITY_DISTRIBUTION_HPP

/**
 * @file DensityDistribution.hpp
 * @brief Declaration of the DensityDistribution class template that represents a generic density
 * distribution at a lattice node.
 */

#include <array>

/**
 * @class DensityDistribution
 * @brief A class template representing a generic density distribution at a lattice node.
 *
 * This class template provides functionalities to manage and access a density distribution
 * represented as an one-dimensional array of scalar values.
 *
 * @tparam Dimension The number of spatial dimensions.
 * @tparam Size The number of lattice vectors at each lattice node.
 * @tparam Scalar The floating-point type of scalar values.
 */
template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
class DensityDistribution
{
public:
    DensityDistribution();
    DensityDistribution(std::initializer_list<Scalar> distribution);

    auto operator[](std::size_t index) -> Scalar&;
    auto operator[](std::size_t index) const -> const Scalar&;
    auto begin() -> std::array<Scalar, Size>::iterator;
    auto begin() const -> std::array<Scalar, Size>::const_iterator;
    auto end() -> std::array<Scalar, Size>::iterator;
    auto end() const -> std::array<Scalar, Size>::const_iterator;
    auto cbegin() const -> std::array<Scalar, Size>::const_iterator;
    auto cend() const -> std::array<Scalar, Size>::const_iterator;

    constexpr auto dimension() const -> std::size_t;
    constexpr auto size() const -> std::size_t;

private:
    std::array<Scalar, Size> distribution_;
};

#include "DensityDistribution.tpp"

#endif // DENSITY_DISTRIBUTION_HPP
