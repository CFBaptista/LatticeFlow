#ifndef DENSITY_DISTRIBUTION_TPP
#define DENSITY_DISTRIBUTION_TPP

;
#include "DensityDistribution.hpp"

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
auto DensityDistribution<Dimension, Size, Scalar>::begin() -> std::array<Scalar, Size>::iterator
{
    return distribution_.begin();
}

template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
auto DensityDistribution<Dimension, Size, Scalar>::begin() const
    -> std::array<Scalar, Size>::const_iterator
{
    return distribution_.begin();
}

template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
auto DensityDistribution<Dimension, Size, Scalar>::end() -> std::array<Scalar, Size>::iterator
{
    return distribution_.end();
}

template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
auto DensityDistribution<Dimension, Size, Scalar>::end() const
    -> std::array<Scalar, Size>::const_iterator
{
    return distribution_.end();
}

template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
auto DensityDistribution<Dimension, Size, Scalar>::cbegin() const
    -> std::array<Scalar, Size>::const_iterator
{
    return distribution_.cbegin();
}

template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
auto DensityDistribution<Dimension, Size, Scalar>::cend() const
    -> std::array<Scalar, Size>::const_iterator
{
    return distribution_.cend();
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
constexpr auto
DensityDistribution<Dimension, Size, Scalar>::setWeights_() -> std::array<Scalar, Size>
{
    return defineWeights<Dimension, Size, Scalar>();
}

template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
constexpr auto defineWeights() -> std::array<Scalar, Size>
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

    constexpr std::array<Scalar, Size> weights{weightCenter,  weightRight,      weightTop,
                                               weightLeft,    weightBottom,     weightTopRight,
                                               weightTopLeft, weightBottomLeft, weightBottomRight};

    return weights;
}

template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
auto computeDensity(const DensityDistribution<Dimension, Size, Scalar>& distribution) -> Scalar
{
    const Scalar density{std::reduce(distribution.begin(), distribution.end())};
    return density;
}

template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
auto computeMomentum(const DensityDistribution<Dimension, Size, Scalar>& distribution
) -> std::array<Scalar, Dimension>
{
    const Scalar momentumX = (distribution[1] + distribution[5] + distribution[8]) -
                             (distribution[3] + distribution[6] + distribution[7]);
    const Scalar momentumY = (distribution[2] + distribution[5] + distribution[6]) -
                             (distribution[4] + distribution[7] + distribution[8]);
    const std::array<Scalar, Dimension> momentum{momentumX, momentumY};

    return momentum;
}

#endif // DENSITY_DISTRIBUTION_TPP
