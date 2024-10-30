#ifndef ARITHMETIC_TPP
#define ARITHMETIC_TPP

;
#include "D2Q9DensityDistribution.hpp"

template <std::floating_point Scalar>
auto operator+(
    const D2Q9DensityDistribution<Scalar>& lhs,
    const D2Q9DensityDistribution<Scalar>& rhs
) -> D2Q9DensityDistribution<Scalar>
{
    D2Q9DensityDistribution<Scalar> result;

    for (std::size_t i = 0; i < D2Q9DensityDistribution<Scalar>::size(); ++i)
    {
        result[i] = lhs[i] + rhs[i];
    }

    return result;
}

#endif // ARITHMETIC_TPP
