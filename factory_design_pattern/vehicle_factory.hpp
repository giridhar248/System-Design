#pragma once
#include "car.hpp"
#include "bike.hpp"
#include <iostream>
using namespace std;

class VehicleFactory {
  public:
    static Vehicle* getVehicle(string vehicleType);
};