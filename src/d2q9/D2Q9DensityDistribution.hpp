#ifndef D2Q9_DENSITY_DISTRIBUTION_HPP
#define D2Q9_DENSITY_DISTRIBUTION_HPP

#include <array>
#include <concepts>

template <std::floating_point Scalar>
class D2Q9DensityDistribution
{
public:
    D2Q9DensityDistribution();
    D2Q9DensityDistribution(std::initializer_list<Scalar> distribution);

    auto operator[](std::size_t index) -> Scalar&;
    auto operator[](std::size_t index) const -> const Scalar&;

    static constexpr auto dimension() -> std::size_t;
    static constexpr auto size() -> std::size_t;
    static auto weight(std::size_t index) -> const Scalar&;

    static auto
    computeVelocity(const Scalar& density, const std::array<Scalar, dimension()>& momentum)
        -> std::array<Scalar, dimension()>;

    auto computeDensity() const -> Scalar;
    auto computeMomentum() const -> std::array<Scalar, dimension()>;

private:
    static constexpr std::size_t dimension_{2};
    static constexpr std::size_t size_{9};

    static constexpr std::size_t center_{0};
    static constexpr std::size_t right_{1};
    static constexpr std::size_t top_{2};
    static constexpr std::size_t left_{3};
    static constexpr std::size_t bottom_{4};
    static constexpr std::size_t topRight_{5};
    static constexpr std::size_t topLeft_{6};
    static constexpr std::size_t bottomLeft_{7};
    static constexpr std::size_t bottomRight_{8};

    static constexpr std::array<Scalar, size()> weight_{4.0 / 9.0,  1.0 / 9.0,  1.0 / 9.0,
                                                        1.0 / 9.0,  1.0 / 9.0,  1.0 / 36.0,
                                                        1.0 / 36.0, 1.0 / 36.0, 1.0 / 36.0};

    std::array<Scalar, size()> distribution_;
};

#include "D2Q9DensityDistribution.tpp"

#endif // D2Q9_DENSITY_DISTRIBUTION_HPP
