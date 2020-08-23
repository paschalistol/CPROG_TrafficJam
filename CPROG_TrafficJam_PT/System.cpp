#include "System.h"
#include <SDL.h>
#include <stdexcept>
namespace jam {
	System::System() {
		SDL_Init(SDL_INIT_EVERYTHING);
		win = SDL_CreateWindow("Traffic Jam by PT", 100,100,800,600, 0);
		ren = SDL_CreateRenderer(win, -1, 0);
		TTF_Init();
		font = TTF_OpenFont("c:/Windows/Fonts/Arial.ttf", 36);
		if (font == nullptr)
		{
			throw std::runtime_error("Font not found");
		}
	}

	SDL_Renderer* System::getRen() const{
		return ren;
	}
	TTF_Font* System::getFont() const {
		return font;
	}
	System::~System() {
		TTF_CloseFont(font);
		TTF_Quit();
		SDL_DestroyRenderer(ren);
		SDL_DestroyWindow(win);
		SDL_Quit();
	}


	System sys;

}