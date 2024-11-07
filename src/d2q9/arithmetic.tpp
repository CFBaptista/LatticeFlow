#ifndef ARITHMETIC_TPP
#define ARITHMETIC_TPP

;
#include "arithmetic.hpp"

template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
auto operator+(
    const D2Q9DensityDistribution<Dimension, Size, Scalar>& lhs,
    const D2Q9DensityDistribution<Dimension, Size, Scalar>& rhs
) -> D2Q9DensityDistribution<Dimension, Size, Scalar>
{
    D2Q9DensityDistribution<Dimension, Size, Scalar> result;

    for (std::size_t i = 0; i < result.size(); ++i)
    {
        result[i] = lhs[i] + rhs[i];
    }

    return result;
}

template <std::size_t Dimension, std::size_t Size, std::floating_point Scalar>
auto operator-(
    const D2Q9DensityDistribution<Dimension, Size, Scalar>& lhs,
    const D2Q9DensityDistribution<Dimension, Size, Scalar>& rhs
) -> D2Q9DensityDistribution<Dimension, Size, Scalar>
{
    D2Q9DensityDistribution<Dimension, Size, Scalar> result;

    for (std::size_t i = 0; i < result.size(); ++i)
    {
        result[i] = lhs[i] - rhs[i];
    }

    return result;
}

#endif // ARITHMETIC_TPP
