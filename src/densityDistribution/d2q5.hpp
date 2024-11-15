#ifndef DENSITY_DISTRIBUTION_D2Q5_HPP
#define DENSITY_DISTRIBUTION_D2Q5_HPP

/**
 * @file d2q5.hpp
 * @brief Declaration of non-member functions that operate on DensityDistribution<2, 5, *>
 * objects.
 */

#include "DensityDistribution.hpp"

/**
 * @brief The number of spatial dimensions in the D2Q5 lattice model.
 */
constexpr std::size_t D2Q5_DIMENSION{2};

/**
 * @brief The number of lattice vectors in the D2Q5 lattice model.
 */
constexpr std::size_t D2Q5_SIZE{5};

/**
 * @brief Alias template for DensityDistribution with 2 dimensions and 5 lattice vectors.
 *
 * @tparam Scalar The floating-point type of scalar values.
 */
template <std::floating_point Scalar>
using D2Q5 = DensityDistribution<D2Q5_DIMENSION, D2Q5_SIZE, Scalar>;

template <std::floating_point Scalar>
constexpr auto latticeWeights(const D2Q5<Scalar>& distribution) -> std::array<Scalar, D2Q5_SIZE>;

template <std::floating_point Scalar>
auto computeDensity(const D2Q5<Scalar>& distribution) -> Scalar;

template <std::floating_point Scalar>
auto computeMomentum(const D2Q5<Scalar>& distribution) -> std::array<Scalar, D2Q5_DIMENSION>;

#include "d2q5.tpp"

#endif // DENSITY_DISTRIBUTION_D2Q5_HPP
