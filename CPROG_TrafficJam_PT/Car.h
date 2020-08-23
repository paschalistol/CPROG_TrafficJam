#ifndef CAR_H
#define CAR_H
#include "Vehicle.h"
#include <SDL.h>
#include "Lane.h"
namespace jam {

	class Car : public Vehicle
	{
	public:
		static Vehicle* getInstance(double, Lane&);
		//Vehicle* spawnVehicle(double);
		void draw() const;
		void deleteVehicle();
		~Car();
	protected:
		Car(double, Lane&);
	private:
		SDL_Texture* texture;
	};
}
#endif
