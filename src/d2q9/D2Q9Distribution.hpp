#ifndef D2Q9_DISTRIBUTION_HPP
#define D2Q9_DISTRIBUTION_HPP

#include <array>

template <typename Scalar>
class D2Q9Distribution
{
public:
    D2Q9Distribution();

    auto operator[](int index) -> Scalar&;

    static constexpr auto dimension() -> std::size_t;
    static constexpr auto size() -> std::size_t;

    static constexpr std::size_t center{0};
    static constexpr std::size_t right{1};
    static constexpr std::size_t top{2};
    static constexpr std::size_t left{3};
    static constexpr std::size_t bottom{4};
    static constexpr std::size_t topRight{5};
    static constexpr std::size_t topLeft{6};
    static constexpr std::size_t bottomLeft{7};
    static constexpr std::size_t bottomRight{8};

    auto computeDensity() const -> Scalar;
    auto computeMomentum() const -> std::array<Scalar, 2>;
    static auto computeVelocity(const Scalar& density, const std::array<Scalar, 2>& momentum)
        -> std::array<Scalar, 2>;

private:
    static constexpr std::size_t dimension_{2};
    static constexpr std::size_t size_{9};

    std::array<Scalar, D2Q9Distribution<Scalar>::size_> distribution_;
};

#include "D2Q9Distribution.tpp"

#endif // D2Q9_DISTRIBUTION_HPP
