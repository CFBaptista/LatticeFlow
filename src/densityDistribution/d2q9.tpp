#ifndef DENSITY_DISTRIBUTION_D2Q9_TPP
#define DENSITY_DISTRIBUTION_D2Q9_TPP

/**
 * @file d2q9.tpp
 * @brief Implementation of non-member functions that operate on DensityDistribution<2, 9, *>
 * objects.
 */

;
#include "d2q9.hpp"

#include <numeric>

/**
 * @brief Returns the lattice weights for the D2Q9 lattice model.
 *
 * Returns the lattice weights for the D2Q9 lattice model as defined in \cite Kruger2017.
 *
 * @param distribution A D2Q9 density distribution.
 * @return The D2Q9 lattice weights.
 *
 * @tparam Scalar The floating-point type of scalar values.
 */
template <std::floating_point Scalar>
constexpr auto latticeWeights(const D2Q9<Scalar>& distribution) -> std::array<Scalar, D2Q9_SIZE>
{
    static_cast<void>(distribution);

    constexpr Scalar weightCenter{4.0 / 9.0};
    constexpr Scalar weightRight{1.0 / 9.0};
    constexpr Scalar weightTop{1.0 / 9.0};
    constexpr Scalar weightLeft{1.0 / 9.0};
    constexpr Scalar weightBottom{1.0 / 9.0};
    constexpr Scalar weightTopRight{1.0 / 36.0};
    constexpr Scalar weightTopLeft{1.0 / 36.0};
    constexpr Scalar weightBottomLeft{1.0 / 36.0};
    constexpr Scalar weightBottomRight{1.0 / 36.0};

    constexpr std::array<Scalar, 9> weights{weightCenter,  weightRight,      weightTop,
                                            weightLeft,    weightBottom,     weightTopRight,
                                            weightTopLeft, weightBottomLeft, weightBottomRight};

    return weights;
}

/**
 * @brief Computes the mass density of a D2Q9 density distribution.
 *
 * @param distribution A D2Q9 density distribution.
 * @return The mass density of the D2Q9 density distribution.
 *
 * @tparam Scalar The floating-point type of scalar values.
 */
template <std::floating_point Scalar>
auto computeDensity(const D2Q9<Scalar>& distribution) -> Scalar
{
    const Scalar density{std::reduce(distribution.begin(), distribution.end())};
    return density;
}

/**
 * @brief Computes the momentum density of a D2Q9 density distribution.
 *
 * @param distribution A D2Q9 density distribution.
 * @return The momentum density of the D2Q9 density distribution.
 *
 * @tparam Scalar The floating-point type of scalar values.
 */
template <std::floating_point Scalar>
auto computeMomentum(const D2Q9<Scalar>& distribution) -> std::array<Scalar, D2Q9_DIMENSION>
{
    const Scalar momentumX = (distribution[1] + distribution[5] + distribution[8]) -
                             (distribution[3] + distribution[6] + distribution[7]);
    const Scalar momentumY = (distribution[2] + distribution[5] + distribution[6]) -
                             (distribution[4] + distribution[7] + distribution[8]);
    const std::array<Scalar, D2Q9_DIMENSION> momentum{momentumX, momentumY};

    return momentum;
}

#endif // DENSITY_DISTRIBUTION_D2Q9_TPP
