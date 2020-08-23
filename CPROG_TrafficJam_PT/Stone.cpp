#include "Stone.h"
#include <SDL_image.h>
#include "System.h"

namespace jam {
	Stone* Stone::getInstance(int x, int y, int w, int h, int s) {
		return new Stone(x, y, w, h, s);
	}
	Stone::Stone(int x, int y, int w, int h, int s) : Component(x - (w / 2), y, w, h), stoneSpeed(s)
	{
		stoneTexture = IMG_LoadTexture(sys.getRen(), "../Resources/stone.jpg");
	}

	void Stone::draw() const {
		SDL_RenderCopy(sys.getRen(), stoneTexture, NULL, &getRect());
	}


	void Stone::destroyBullet()
	{
		/*if(outOfGame())*/
		SDL_DestroyTexture(stoneTexture);
	}

	void Stone::stoneMovement()
	{
		changeX(-stoneSpeed);
	}

	Stone::~Stone()
	{
		SDL_DestroyTexture(stoneTexture);
	}
}