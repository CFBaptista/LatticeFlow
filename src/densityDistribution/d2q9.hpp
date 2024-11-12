#ifndef DENSITY_DISTRIBUTION_D2Q9_HPP
#define DENSITY_DISTRIBUTION_D2Q9_HPP

#include "DensityDistribution.hpp"

template <std::floating_point Scalar>
constexpr auto latticeWeights(const DensityDistribution<2, 9, Scalar>& distribution
) -> std::array<Scalar, 9>;

template <std::floating_point Scalar>
auto computeDensity(const DensityDistribution<2, 9, Scalar>& distribution) -> Scalar;

template <std::floating_point Scalar>
auto computeMomentum(const DensityDistribution<2, 9, Scalar>& distribution
) -> std::array<Scalar, 2>;

#include "d2q9.tpp"

#endif // DENSITY_DISTRIBUTION_D2Q9_HPP
