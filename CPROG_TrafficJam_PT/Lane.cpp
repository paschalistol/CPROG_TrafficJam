#include "Lane.h"
#include <SDL.h>
#include "System.h"
namespace jam {
	Lane::Lane(int x, int y, int w, int h, int r, int g, int b, int a) : Component(x,y,w,h), x(x), y(y) {
		lane = SDL_CreateRGBSurface(0,w,h, 32,0,0,0,0);
		SDL_FillRect(lane, NULL, SDL_MapRGBA(lane->format, r, g, b,a));
		laneTexture = SDL_CreateTextureFromSurface(sys.getRen(), lane);
		setWH(lane->w, lane->h);
		SDL_FreeSurface(lane);
	}

	bool Lane::getLaneEmpty() {
		return laneEmpty;
	}
	Lane* Lane::getInstance(int x, int y, int w, int h, int r, int g, int b, int a) {
		return new Lane(x,y,w, h,r,g,b,a);
	}
	void Lane::draw() const{
		SDL_RenderCopy(sys.getRen(), laneTexture, NULL, &getRect());
	}
	Lane::~Lane() {
		SDL_DestroyTexture(laneTexture);

	}
	void Lane::setLaneEmpty(bool b) {
		laneEmpty = b;
	}
}