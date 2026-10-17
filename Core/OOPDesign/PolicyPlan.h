#pragma once

#include <string>

using std::string;

// Base class for insurance plans.
class PolicyPlan
{
protected:
    string planName;
    double basePremium;
    double coverageRate;

public:
    PolicyPlan()
    {
        planName = "";
        basePremium = 0.0;
        coverageRate = 0.0;
    }

    string getPlanName() const
    {
        return planName;
    }

    double getBasePremium() const
    {
        return basePremium;
    }

    double getCoverageRate() const
    {
        return coverageRate;
    }
};

class LifePolicy : public PolicyPlan
{
public:
    LifePolicy()
    {
        planName = "Life Insurance";
        basePremium = 2500.0;
        coverageRate = 0.0015;
    }
};

class HealthPolicy : public PolicyPlan
{
public:
    HealthPolicy()
    {
        planName = "Health Insurance";
        basePremium = 1800.0;
        coverageRate = 0.0012;
    }
};

class VehiclePolicy : public PolicyPlan
{
public:
    VehiclePolicy()
    {
        planName = "Vehicle Insurance";
        basePremium = 2200.0;
        coverageRate = 0.0018;
    }
};
