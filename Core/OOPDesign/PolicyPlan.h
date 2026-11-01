#pragma once

#include <string>

using std::string;

// Base class for insurance plans.
class PolicyPlan
{
protected:
    // Common values shared by all policy plans
    string planName;
    double basePremium;
    double coverageRate;

public:
    // Default constructor - starts with empty plan values
    PolicyPlan()
    {
        planName = "";
        basePremium = 0.0;
        coverageRate = 0.0;
    }

    // Returns the plan name
    string getPlanName() const
    {
        return planName;
    }

    // Returns the base premium
    double getBasePremium() const
    {
        return basePremium;
    }

    // Returns the coverage rate
    double getCoverageRate() const
    {
        return coverageRate;
    }
};

// Life Insurance plan inherits from PolicyPlan
class LifePolicy : public PolicyPlan
{
public:
    // Sets the values used for Life Insurance
    LifePolicy()
    {
        planName = "Life Insurance";
        basePremium = 2500.0;
        coverageRate = 0.0015;
    }
};

// Health Insurance plan inherits from PolicyPlan
class HealthPolicy : public PolicyPlan
{
public:
    // Sets the values used for Health Insurance
    HealthPolicy()
    {
        planName = "Health Insurance";
        basePremium = 1800.0;
        coverageRate = 0.0012;
    }
};

// Vehicle Insurance plan inherits from PolicyPlan
class VehiclePolicy : public PolicyPlan
{
public:
    // Sets the values used for Vehicle Insurance
    VehiclePolicy()
    {
        planName = "Vehicle Insurance";
        basePremium = 2200.0;
        coverageRate = 0.0018;
    }
};
