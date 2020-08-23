#include "Vehicle.h"
namespace jam {
	void Vehicle::moveVehicle() {
		changeX(-speed);
	}
	Vehicle::Vehicle(double s, Lane& lane) : Component(0,lane.getY(),100,100), speed(s){

	}
	void Vehicle::draw() const {

	}
}