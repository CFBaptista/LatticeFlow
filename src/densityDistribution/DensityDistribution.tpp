#ifndef DENSITY_DISTRIBUTION_TPP
#define DENSITY_DISTRIBUTION_TPP

;
#include "DensityDistribution.hpp"
#include <limits>
#include <numeric>

template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
DensityDistribution<Dimension, Size, Scalar>::DensityDistribution() : distribution_{0.0}
{
}

template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
DensityDistribution<Dimension, Size, Scalar>::DensityDistribution(
    std::initializer_list<Scalar> distribution
)
{
    std::copy(distribution.begin(), distribution.end(), distribution_.begin());
}

template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
auto DensityDistribution<Dimension, Size, Scalar>::operator[](std::size_t index) -> Scalar&
{
    return distribution_.at(index);
}

template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
auto DensityDistribution<Dimension, Size, Scalar>::operator[](std::size_t index
) const -> const Scalar&
{
    return distribution_.at(index);
}

template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
constexpr auto DensityDistribution<Dimension, Size, Scalar>::dimension() const -> std::size_t
{
    return Dimension;
}

template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
constexpr auto DensityDistribution<Dimension, Size, Scalar>::size() const -> std::size_t
{
    return Size;
}

template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
auto DensityDistribution<Dimension, Size, Scalar>::weight(std::size_t index) -> const Scalar&
{
    return DensityDistribution::weight_.at(index);
}

template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
auto DensityDistribution<Dimension, Size, Scalar>::computeVelocity(
    const Scalar& density,
    const std::array<Scalar, Dimension>& momentum
) -> std::array<Scalar, Dimension>
{
    const Scalar densityEpsilon = density + std::numeric_limits<Scalar>::epsilon();
    const std::array<Scalar, Dimension> velocity{
        momentum[0] / densityEpsilon, momentum[1] / densityEpsilon
    };

    return velocity;
}

template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
auto DensityDistribution<Dimension, Size, Scalar>::computeDensity() const -> Scalar
{
    const Scalar density{std::reduce(distribution_.begin(), distribution_.end())};
    return density;
}

template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
auto DensityDistribution<Dimension, Size, Scalar>::computeMomentum() const
    -> std::array<Scalar, Dimension>
{
    const Scalar momentumX =
        (distribution_[right_] + distribution_[topRight_] + distribution_[bottomRight_]) -
        (distribution_[left_] + distribution_[topLeft_] + distribution_[bottomLeft_]);
    const Scalar momentumY =
        (distribution_[top_] + distribution_[topRight_] + distribution_[topLeft_]) -
        (distribution_[bottom_] + distribution_[bottomLeft_] + distribution_[bottomRight_]);
    const std::array<Scalar, Dimension> momentum{momentumX, momentumY};

    return momentum;
}

template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
constexpr auto
DensityDistribution<Dimension, Size, Scalar>::setWeights_() -> std::array<Scalar, Size>
{
    constexpr Scalar weightCenter{4.0 / 9.0};
    constexpr Scalar weightRight{1.0 / 9.0};
    constexpr Scalar weightTop{1.0 / 9.0};
    constexpr Scalar weightLeft{1.0 / 9.0};
    constexpr Scalar weightBottom{1.0 / 9.0};
    constexpr Scalar weightTopRight{1.0 / 36.0};
    constexpr Scalar weightTopLeft{1.0 / 36.0};
    constexpr Scalar weightBottomLeft{1.0 / 36.0};
    constexpr Scalar weightBottomRight{1.0 / 36.0};

    return {weightCenter,   weightRight,   weightTop,        weightLeft,       weightBottom,
            weightTopRight, weightTopLeft, weightBottomLeft, weightBottomRight};
}

#endif // DENSITY_DISTRIBUTION_TPP
