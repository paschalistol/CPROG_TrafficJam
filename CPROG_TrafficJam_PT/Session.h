#ifndef SESSION_H
#define SESSION_H
#include <vector>
#include "Component.h"
#include "Vehicle.h"
#include "Lane.h"


namespace jam {

	class Session
	{
	public:
		Session(int);
		void add(Component*);
		void addLane(Lane*);
		//void remove(Component*){}
		void run();
		void addCar();
		~Session();
	private:
		std::vector<Vehicle*> vehicles;
		std::vector<Component*> comps;
		std::vector<Component*> added, removed;
		std::vector<Lane*> lanes;
		Uint32 nextTick;
		int delay;
		const int tickInterval;
		int playerInLane = 1;
	};
} //jam

#endif