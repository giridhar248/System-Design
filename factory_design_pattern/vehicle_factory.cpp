#include "vehicle_factory.hpp"

#include<iostream>
Vehicle* VehicleFactory::getVehicle(string vehicleType) {
  Vehicle* vehicle;
  if(vehicleType=="car") {
    vehicle=new Car();
  }
  if(vehicleType=="bike") {
    vehicle=new Bike();
  }
  return vehicle;
}