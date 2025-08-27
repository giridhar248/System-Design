#include "vehicle_factory.hpp"
#include <iostream>

using namespace std;

int main() {
  string vehicleType;
  cout<<"Specify the vehicle to create it"<<endl;
  cin>>vehicleType;
  Vehicle* vehicle=VehicleFactory::getVehicle(vehicleType);
  vehicle->createVehicle();
  return 0;
}