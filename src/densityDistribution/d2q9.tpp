#ifndef DENSITY_DISTRIBUTION_D2Q9_TPP
#define DENSITY_DISTRIBUTION_D2Q9_TPP

/**
 * @file d2q9.tpp
 * @brief Implementation of the DensityDistribution class template with 2 dimensions and 9 lattice
 * vectors that represents a D2Q9 fluid density distribution at a lattice node.
 */

;
#include "d2q9.hpp"

/**
 * @brief Alias template for DensityDistribution with 2 dimensions and 9 lattice vectors.
 *
 * @tparam Scalar The floating-point type of lattice nodal values.
 */
template <std::floating_point Scalar>
using D2Q9 = DensityDistribution<2, 9, Scalar>;

/**
 * @brief Returns the lattice weights for the D2Q9 model.
 *
 * @param distribution A D2Q9 density distribution.
 * @return The D2Q9 lattice weights.
 *
 * @tparam Scalar The floating-point type of lattice nodal values.
 */
template <std::floating_point Scalar>
constexpr auto latticeWeights(const D2Q9<Scalar>& distribution) -> std::array<Scalar, 9>
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
 * @brief Computes the fluid density of a D2Q9 density distribution.
 *
 * @param distribution A D2Q9 density distribution.
 * @return The fluid density of the D2Q9 density distribution.
 *
 * @tparam Scalar The floating-point type of lattice nodal values.
 */
template <std::floating_point Scalar>
auto computeDensity(const D2Q9<Scalar>& distribution) -> Scalar
{
    const Scalar density{std::reduce(distribution.begin(), distribution.end())};
    return density;
}

/**
 * @brief Computes the momentum of a D2Q9 density distribution.
 *
 * @param distribution A D2Q9 density distribution.
 * @return The fluid momentum of the D2Q9 density distribution.
 *
 * @tparam Scalar The floating-point type of lattice nodal values.
 */
template <std::floating_point Scalar>
auto computeMomentum(const D2Q9<Scalar>& distribution) -> std::array<Scalar, 2>
{
    const Scalar momentumX = (distribution[1] + distribution[5] + distribution[8]) -
                             (distribution[3] + distribution[6] + distribution[7]);
    const Scalar momentumY = (distribution[2] + distribution[5] + distribution[6]) -
                             (distribution[4] + distribution[7] + distribution[8]);
    const std::array<Scalar, 2> momentum{momentumX, momentumY};

    return momentum;
}

#endif // DENSITY_DISTRIBUTION_D2Q9_TPP
