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
auto D2Q9DensityDistribution<Scalar>::operator[](int index) -> Scalar&
{
    return distribution_.at(index);
}

template <std::floating_point Scalar>
auto D2Q9DensityDistribution<Scalar>::operator[](int index) const -> const Scalar&
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
auto D2Q9DensityDistribution<Scalar>::weight(int index) -> const Scalar&
{
    return D2Q9DensityDistribution::weight_.at(index);
}

template <std::floating_point Scalar>
auto D2Q9DensityDistribution<Scalar>::computeVelocity(
    const Scalar& density,
    const std::array<Scalar, 2>& momentum
) -> std::array<Scalar, 2>
{
    const Scalar densityEpsilon = density + std::numeric_limits<Scalar>::epsilon();
    std::array<Scalar, 2> velocity{momentum[0] / densityEpsilon, momentum[1] / densityEpsilon};

    return velocity;
}

template <std::floating_point Scalar>
auto D2Q9DensityDistribution<Scalar>::computeDensity() const -> Scalar
{
    Scalar density{std::reduce(distribution_.begin(), distribution_.end())};
    return density;
}

template <std::floating_point Scalar>
auto D2Q9DensityDistribution<Scalar>::computeMomentum() const -> std::array<Scalar, 2>
{
    const Scalar momentumX = (distribution_[D2Q9DensityDistribution::right] +
                              distribution_[D2Q9DensityDistribution::topRight] +
                              distribution_[D2Q9DensityDistribution::bottomRight]) -
                             (distribution_[D2Q9DensityDistribution::left] +
                              distribution_[D2Q9DensityDistribution::topLeft] +
                              distribution_[D2Q9DensityDistribution::bottomLeft]);
    const Scalar momentumY = (distribution_[D2Q9DensityDistribution::top] +
                              distribution_[D2Q9DensityDistribution::topRight] +
                              distribution_[D2Q9DensityDistribution::topLeft]) -
                             (distribution_[D2Q9DensityDistribution::bottom] +
                              distribution_[D2Q9DensityDistribution::bottomLeft] +
                              distribution_[D2Q9DensityDistribution::bottomRight]);
    std::array<Scalar, 2> momentum{momentumX, momentumY};

    return momentum;
}

#endif // D2Q9_DENSITY_DISTRIBUTION_TPP
