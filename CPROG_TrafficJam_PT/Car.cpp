#include "Car.h"
#include <SDL_image.h>
#include "System.h"
#include <iostream>
namespace jam {
	Car::Car(double speed, Lane& lane) : Vehicle(speed, lane){
		texture = IMG_LoadTexture(sys.getRen(), "../Resources/car.png");
	}
	//Vehicle* Car::spawnVehicle(double speed) {
	//	return new Car(speed);
	//}
	void Car::draw()const {
		SDL_RenderCopy(sys.getRen(), texture, NULL, &getRect());
	}
	Car::~Car() {
		SDL_DestroyTexture(texture);
		std::cout << "deleted car";
	}
	Vehicle* Car::getInstance(double speed, Lane& lane) {
		return (new Car(speed, lane));
	}
	void Car::deleteVehicle() {
		delete this;
	}
}