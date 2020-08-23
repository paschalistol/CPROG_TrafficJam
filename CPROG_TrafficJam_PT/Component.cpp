#include "Component.h"
#include <SDL.h>
#include "System.h"
namespace jam {
	Component::Component(int x, int y, int w, int h) :rect{x,y,w,h}
	{
	}

	void Component::setWH(int w, int h) {
		rect.w = w;
		rect.h = h;
	}
	void Component::changeY(int i) {
		rect.y += i;
	}
	void Component::changeX(int i) {
		rect.x += i;
	}
	//void Component::draw() const
	//{
	//	SDL_SetRenderDrawColor(sys.getRen(), 255, 0, 0, 0);
	//	SDL_RenderFillRect(sys.getRen(), &rect);
	//}
}