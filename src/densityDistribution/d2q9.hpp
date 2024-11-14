#ifndef DENSITY_DISTRIBUTION_D2Q9_HPP
#define DENSITY_DISTRIBUTION_D2Q9_HPP

#include "DensityDistribution.hpp"

constexpr std::size_t D2Q9_DIMENSION{2};
constexpr std::size_t D2Q9_SIZE{9};

/**
 * @brief Alias template for DensityDistribution with 2 dimensions and 9 lattice vectors.
 *
 * @tparam Scalar The floating-point type of lattice nodal values.
 */
template <std::floating_point Scalar>
using D2Q9 = DensityDistribution<D2Q9_DIMENSION, D2Q9_SIZE, Scalar>;

template <std::floating_point Scalar>
constexpr auto latticeWeights(const D2Q9<Scalar>& distribution) -> std::array<Scalar, D2Q9_SIZE>;

template <std::floating_point Scalar>
auto computeDensity(const D2Q9<Scalar>& distribution) -> Scalar;

template <std::floating_point Scalar>
auto computeMomentum(const D2Q9<Scalar>& distribution) -> std::array<Scalar, D2Q9_DIMENSION>;

#include "d2q9.tpp"

#endif // DENSITY_DISTRIBUTION_D2Q9_HPP
