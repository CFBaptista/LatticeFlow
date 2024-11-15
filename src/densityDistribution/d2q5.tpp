#ifndef DENSITY_DISTRIBUTION_D2Q5_TPP
#define DENSITY_DISTRIBUTION_D2Q5_TPP

/**
 * @file d2q5.tpp
 * @brief Implementation of non-member functions that operate on DensityDistribution<2, 5, *>
 * objects.
 */

;
#include "d2q5.hpp"

#include <numeric>

/**
 * @brief Returns the lattice weights for the D2Q5 lattice model.
 *
 * @param distribution A D2Q5 density distribution.
 * @return The D2Q5 lattice weights.
 *
 * @tparam Scalar The floating-point type of scalar values.
 */
template <std::floating_point Scalar>
constexpr auto latticeWeights(const D2Q5<Scalar>& distribution) -> std::array<Scalar, D2Q5_SIZE>
{
    static_cast<void>(distribution);

    constexpr Scalar weightCenter{1.0 / 3.0};
    constexpr Scalar weightRight{1.0 / 6.0};
    constexpr Scalar weightTop{1.0 / 6.0};
    constexpr Scalar weightLeft{1.0 / 6.0};
    constexpr Scalar weightBottom{1.0 / 6.0};

    constexpr std::array<Scalar, D2Q5_SIZE> weights{
        weightCenter, weightRight, weightTop, weightLeft, weightBottom
    };

    return weights;
}

/**
 * @brief Computes the mass density of a D2Q5 density distribution.
 *
 * @param distribution A D2Q5 density distribution.
 * @return The mass density of the D2Q5 density distribution.
 *
 * @tparam Scalar The floating-point type of scalar values.
 */
template <std::floating_point Scalar>
auto computeDensity(const D2Q5<Scalar>& distribution) -> Scalar
{
    const Scalar density{std::reduce(distribution.begin(), distribution.end())};
    return density;
}

/**
 * @brief Computes the momentum density of a D2Q5 density distribution.
 *
 * @param distribution A D2Q5 density distribution.
 * @return The momentum density of the D2Q5 density distribution.
 *
 * @tparam Scalar The floating-point type of scalar values.
 */
template <std::floating_point Scalar>
auto computeMomentum(const D2Q5<Scalar>& distribution) -> std::array<Scalar, D2Q5_DIMENSION>
{
    const Scalar momentumX = distribution[1] - distribution[3];
    const Scalar momentumY = distribution[2] - distribution[4];
    const std::array<Scalar, D2Q5_DIMENSION> momentum{momentumX, momentumY};

    return momentum;
}

#endif // DENSITY_DISTRIBUTION_D2Q5_TPP
