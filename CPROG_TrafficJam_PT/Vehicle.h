#ifndef VEHICLE_H
#define VEHICLE_H
#include "Component.h"
#include "Lane.h"
namespace jam {

	class Vehicle : public Component
	{
	public:
		virtual ~Vehicle() {};
		virtual void moveVehicle();
		//virtual Vehicle* spawnVehicle(double) = 0;
		//virtual void deleteVehicle() = 0;
		void draw() const;
	protected:
		double speed;
		Vehicle(double, Lane&);
	};

}
#endif // !VEHICLE_H
