#ifndef SESSION_H
#define SESSION_H
#include <vector>
#include "Component.h"
#include "Vehicle.h"
#include "Lane.h"
#include "Stone.h"
#include "Player.h"

namespace jam {

	class Session
	{
	public:
		Session(int);
		void add(Component*);
		void addLane(Lane*);
		//void remove(Component*){}
		void run();
		~Session();
		void setStartLane(int);
		Lane* getLane(int);
		void setPlayerMovementY(int);
		void definePlayer(Player*);
	private:
		void addCar();
		void addStone();
		std::vector<Vehicle*> vehicles;
		std::vector<Component*> comps;
		std::vector<Component*> added, removed;
		std::vector<Lane*> lanes;
		std::vector<Stone*> stones;
		Uint32 nextTick;
		int delay;
		const int tickInterval;
		int playerInLane = 1;
		int startLane ;
		int playerMovementY;
		Player* player;
		void collisionDetection();
		bool collision(SDL_Rect, SDL_Rect);
	};
} //jam

#endif
