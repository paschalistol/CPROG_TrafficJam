#include "Session.h"
#include <SDL.h>
#include "System.h"
#include "Car.h"
#include <chrono>
using namespace std;
namespace jam
{
	Session::Session(int t) : tickInterval(1000 / t) {

	}
	void Session::addCar() {
		Vehicle* car;
		car = Car::getInstance(-2, *lanes[1]);
		vehicles.push_back(car);
	}
	void Session::addLane(Lane* l) {
		lanes.push_back(l);
	}
	void Session::add(Component* c)
	{
		comps.push_back(c);
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
		while (!quit)
		{
			nextTick = SDL_GetTicks() + tickInterval;
			SDL_Event event;
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
						for (Component* c : comps)
						{
							if (playerInLane +1 < lanes.size())
							{

							c->moveY(100);
							playerInLane++;
							}
						}
						break;
					case (SDLK_UP):
					case SDLK_w:
						for (Component* c : comps)
						{
							if (playerInLane != 0)
							{
							c->moveY(-100);
							playerInLane--;
							}
						}
						break;
					}
					for (Component* c : comps)
					{
						c->keyDown(event);
					}
					break;
				case SDL_KEYUP:
					for (Component* c : comps)
					{
						c->keyUp(event);
					}
					break;
				} //switch
			}	//inner

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
			for (Component* c : comps)
			{
				c->draw();
			}
			for (Lane* l : lanes)
			{
				l->draw();
			}
			for (Vehicle* v : vehicles)
			{
				v->moveVehicle();
				v->draw();
			}
			SDL_RenderPresent(sys.getRen());
			delay = nextTick - SDL_GetTicks();
			if (delay > 0) { SDL_Delay(delay); }
		} //outter

	}
	Lane* Session::getLane(int no) {
		return lanes[no];
	}
	void Session::setStartLane(int no) {
		startLane = no;
		playerInLane = no;
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
	}
} //jam