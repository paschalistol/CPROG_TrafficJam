#include "Session.h"
#include <SDL.h>
#include "System.h"
#include "Car.h"
#include <chrono>

#define TIME_PER_VEHICLE 1.9
using namespace std;
namespace jam
{
	Session::Session(int t) : tickInterval(1000 / t) {

	}
	void Session::addStone() {
		Stone* stone;
		stone = player->throwStone();
		if (stone == nullptr) {
			delete stone;
			return;
		}
		else
		stones.push_back(stone);
		
	}
	void Session::addCar() {
		Vehicle* car;
		car = Car::getInstance(-2, *lanes[rand() % lanes.size()]);
		vehicles.push_back(car);
	}
	void Session::addLane(Lane* l) {
		lanes.push_back(l);
	}
	void Session::add(Component* c)
	{
		comps.push_back(c);
	}
	void Session::definePlayer(Player* pl) {
		player = pl;
	}
	//void Session::remove(Component* c)
	//{
	//	removed.push_back(c);
	//}
	void Session::run()
	{
		SDL_SetRenderDrawColor(sys.getRen(), 255, 255, 255, 255);
		bool quit = false;
		std::chrono::steady_clock sc;
		auto start = sc.now();
		int sec = 0;
		while (!quit)
		{
			nextTick = SDL_GetTicks() + tickInterval;
			SDL_Event event;

			auto end = sc.now();
			auto time_span = static_cast<std::chrono::duration<double>>(end - start);

			if (time_span.count() > sec * TIME_PER_VEHICLE)
			{
				sec++;
				addCar();
			}


			while (SDL_PollEvent(&event)) {
				switch (event.type)
				{
				case SDL_QUIT: quit = true; break;
				case SDL_MOUSEBUTTONDOWN:
					for (Component* c : comps)
					{
						c->mouseDown(event);
					}
					break;
				case SDL_MOUSEBUTTONUP:
					for (Component* c : comps)
					{
						c->mouseUp(event);
					}
					break;
				case SDL_KEYDOWN:
					switch (event.key.keysym.sym)
					{
					case (SDLK_DOWN):
					case SDLK_s:

							if (playerInLane +1 < lanes.size())
							{

							player->moveY(playerMovementY);
							playerInLane++;
							}

						break;
					case (SDLK_UP):
					case SDLK_w:

							if (playerInLane != 0)
							{
							player->moveY(-playerMovementY);
							playerInLane--;
							
							}
						break;
					case SDLK_SPACE:
						addStone();
						break;
					}
					//for (Component* c : comps)
					//{
					//	c->keyDown(event);
					//}
				//	break;
				//case SDL_KEYUP:
				//	for (Component* c : comps)
				//	{
				//		c->keyUp(event);
				//	}
				//	break;
				} //switch
			}	//inner
			player->addReloadCount();
			//for (Component* c : added) {
			//	comps.push_back(c);
			//}
			//added.clear();
			//
			//for (vector<Component*>::iterator i = comps.begin(); i != comps.end(); )
			//{
			//	for (Component* c : removed) {
			//		if (*i == c)
			//		{
			//			i = comps.erase(i);
			//			delete c;
			//		}
			//		else i++;
			//	}
			//}


			SDL_RenderClear(sys.getRen());
			for (Lane* l : lanes)
			{
				l->draw();
			}
			for (Component* c : comps)
			{
				c->draw();
			}
			for ( Stone* s : stones)
			{
				s->stoneMovement();
				s->draw();
			}
			player->draw();
			for (Vehicle* v : vehicles)
			{
				v->moveVehicle();
				v->draw();
			}

			collisionDetection();

			SDL_RenderPresent(sys.getRen());
			delay = nextTick - SDL_GetTicks();
			if (delay > 0) { SDL_Delay(delay); }
		} //outter

	}
	void Session::collisionDetection() {
		for (int s = 0; s < stones.size() ; s++)
		{
			for (int v = 0; v < vehicles.size(); v++) {
				if (collision(stones[s]->getRect(), vehicles[v]->getRect())) {
					Stone* st = stones[s];
					stones.erase(stones.begin() + s);
					delete st;
					Vehicle* ve = vehicles[v];
					vehicles.erase(vehicles.begin() + v);
					delete ve;
					break;
				}
			}
		}
	}
	bool Session::collision(SDL_Rect stone, SDL_Rect vehicle){
		if (stone.y >= vehicle.y + vehicle.h)
		{
			return 0;
		}
		if (stone.x >= vehicle.x + vehicle.w) {
			return 0;
		}
		if (stone.y + stone.h <= vehicle.y) {
			return 0;
		}
		if (stone.x + stone.w <= vehicle.x) {
			return 0;
		}
		return 1;
	}
	Lane* Session::getLane(int no) {
		return lanes[no];
	}
	void Session::setStartLane(int no) {
		startLane = no;
		playerInLane = no;
	}
	void Session::setPlayerMovementY(int dif) {
		playerMovementY = dif;
	}
	Session::~Session()
	{
		for (Component* c : comps)
		{
			delete c;
		}
		for (Lane* c : lanes)
		{
			delete c;
		}
		for (Vehicle* c : vehicles)
		{
			delete c;
		}
		delete player;
	}
} //jam