#ifndef D2Q9_DISTRIBUTION_TPP
#define D2Q9_DISTRIBUTION_TPP

D2Q9Distribution::D2Q9Distribution() :
    distribution_{0.0}
{
}

double& D2Q9Distribution::operator[](int index)
{
    return distribution_[index];
}

constexpr std::size_t D2Q9Distribution::dimension() const
{
    return D2Q9Distribution::dimension_;
}

constexpr std::size_t D2Q9Distribution::size() const
{
    return D2Q9Distribution::size_;
}

double D2Q9Distribution::density() const
{
    double density{std::reduce(distribution_.begin(), distribution_.end())};
    return density;
}

std::array <double, 2> D2Q9Distribution::momentum() const
{
    std::array<double, 2> momentum;
    
    momentum[0] = (distribution_[1] + distribution_[5] + distribution_[8]) - (distribution_[3] + distribution_[6] + distribution_[7]);
    momentum[1] = (distribution_[2] + distribution_[5] + distribution_[6]) - (distribution_[4] + distribution_[7] + distribution_[8]);

    return momentum;
}

std::array <double, 2> D2Q9Distribution::velocity(const double& density, const std::array<double, 2>& momentum) const
{
    std::array<double, 2> velocity;
    
    velocity[0] = momentum[0] / (density + std::numeric_limits<double>::epsilon());
    velocity[1] = momentum[1] / (density + std::numeric_limits<double>::epsilon());

    return velocity;
}

#endif // D2Q9_DISTRIBUTION_TPP
