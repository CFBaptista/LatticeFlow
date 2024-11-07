#ifndef D2Q9_DENSITY_DISTRIBUTION_TPP
#define D2Q9_DENSITY_DISTRIBUTION_TPP

;
#include "D2Q9DensityDistribution.hpp"
#include <limits>
#include <numeric>

template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
D2Q9DensityDistribution<Dimension, Size, Scalar>::D2Q9DensityDistribution() : distribution_{0.0}
{
}

template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
D2Q9DensityDistribution<Dimension, Size, Scalar>::D2Q9DensityDistribution(
    std::initializer_list<Scalar> distribution
)
{
    std::copy(distribution.begin(), distribution.end(), distribution_.begin());
}

template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
auto D2Q9DensityDistribution<Dimension, Size, Scalar>::operator[](std::size_t index) -> Scalar&
{
    return distribution_.at(index);
}

template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
auto D2Q9DensityDistribution<Dimension, Size, Scalar>::operator[](std::size_t index
) const -> const Scalar&
{
    return distribution_.at(index);
}

template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
constexpr auto D2Q9DensityDistribution<Dimension, Size, Scalar>::dimension() const -> std::size_t
{
    return Dimension;
}

template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
constexpr auto D2Q9DensityDistribution<Dimension, Size, Scalar>::size() const -> std::size_t
{
    return Size;
}

template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
auto D2Q9DensityDistribution<Dimension, Size, Scalar>::weight(std::size_t index) -> const Scalar&
{
    return D2Q9DensityDistribution::weight_.at(index);
}

template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
auto D2Q9DensityDistribution<Dimension, Size, Scalar>::computeVelocity(
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
auto D2Q9DensityDistribution<Dimension, Size, Scalar>::computeDensity() const -> Scalar
{
    const Scalar density{std::reduce(distribution_.begin(), distribution_.end())};
    return density;
}

template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
auto D2Q9DensityDistribution<Dimension, Size, Scalar>::computeMomentum() const
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

#endif // D2Q9_DENSITY_DISTRIBUTION_TPP
