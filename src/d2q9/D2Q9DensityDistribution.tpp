#ifndef D2Q9_DENSITY_DISTRIBUTION_TPP
#define D2Q9_DENSITY_DISTRIBUTION_TPP

;
#include "D2Q9DensityDistribution.hpp"
#include <limits>
#include <numeric>

template <std::floating_point Scalar>
D2Q9DensityDistribution<Scalar>::D2Q9DensityDistribution() : distribution_{0.0}
{
}

template <std::floating_point Scalar>
D2Q9DensityDistribution<Scalar>::D2Q9DensityDistribution(std::initializer_list<Scalar> distribution)
{
    std::copy(distribution.begin(), distribution.end(), distribution_.begin());
}

template <std::floating_point Scalar>
auto D2Q9DensityDistribution<Scalar>::operator[](std::size_t index) -> Scalar&
{
    return distribution_.at(index);
}

template <std::floating_point Scalar>
auto D2Q9DensityDistribution<Scalar>::operator[](std::size_t index) const -> const Scalar&
{
    return distribution_.at(index);
}

template <std::floating_point Scalar>
constexpr auto D2Q9DensityDistribution<Scalar>::dimension() -> std::size_t
{
    return D2Q9DensityDistribution::dimension_;
}

template <std::floating_point Scalar>
constexpr auto D2Q9DensityDistribution<Scalar>::size() -> std::size_t
{
    return D2Q9DensityDistribution::size_;
}

template <std::floating_point Scalar>
auto D2Q9DensityDistribution<Scalar>::weight(std::size_t index) -> const Scalar&
{
    return D2Q9DensityDistribution::weight_.at(index);
}

template <std::floating_point Scalar>
auto D2Q9DensityDistribution<Scalar>::computeVelocity(
    const Scalar& density,
    const std::array<Scalar, dimension()>& momentum
) -> std::array<Scalar, dimension()>
{
    const Scalar densityEpsilon = density + std::numeric_limits<Scalar>::epsilon();
    const std::array<Scalar, dimension()> velocity{
        momentum[0] / densityEpsilon, momentum[1] / densityEpsilon
    };

    return velocity;
}

template <std::floating_point Scalar>
auto D2Q9DensityDistribution<Scalar>::computeDensity() const -> Scalar
{
    const Scalar density{std::reduce(distribution_.begin(), distribution_.end())};
    return density;
}

template <std::floating_point Scalar>
auto D2Q9DensityDistribution<Scalar>::computeMomentum() const -> std::array<Scalar, dimension()>
{
    const Scalar momentumX =
        (distribution_[right_] + distribution_[topRight_] + distribution_[bottomRight_]) -
        (distribution_[left_] + distribution_[topLeft_] + distribution_[bottomLeft_]);
    const Scalar momentumY =
        (distribution_[top_] + distribution_[topRight_] + distribution_[topLeft_]) -
        (distribution_[bottom_] + distribution_[bottomLeft_] + distribution_[bottomRight_]);
    const std::array<Scalar, dimension_> momentum{momentumX, momentumY};

    return momentum;
}

#endif // D2Q9_DENSITY_DISTRIBUTION_TPP
