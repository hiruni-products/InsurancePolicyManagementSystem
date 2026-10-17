#pragma once

#include <string>

using std::string;

// TG/2024/2194 - OOP DESIGN: PolicyPlan inheritance structure.
// TG/2024/2283 - PROGRAMMER 2: plan values are used in premium calculation.
// PolicyPlan is a BASE CLASS for different insurance plans.
class PolicyPlan
{
protected:
    // protected allows derived plan classes to set these values.
    string planName;
    double basePremium;
    double coverageRate;

public:
    // Default constructor.
    PolicyPlan()
    {
        planName = "";
        basePremium = 0.0;
        coverageRate = 0.0;
    }

    // Getter for plan name.
    string getPlanName() const
    {
        return planName;
    }

    // Getter for base premium.
    double getBasePremium() const
    {
        return basePremium;
    }

    // Getter for coverage rate.
    double getCoverageRate() const
    {
        return coverageRate;
    }
};

// LifePolicy is derived from PolicyPlan.
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

// HealthPolicy is derived from PolicyPlan.
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

// VehiclePolicy is derived from PolicyPlan.
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
