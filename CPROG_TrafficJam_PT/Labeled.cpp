#include "Labeled.h"
#include "SDL_ttf.h"
#include "System.h"
using namespace std;

namespace jam
{
	Labeled::Labeled(int x, int y, const string& txt) : Component(x, y, 0, 0), text(txt)
	{
		makeTexture();
	}

	string Labeled::getText() const {
		return text;
	}

	void Labeled::makeTexture() {
		if (texture != nullptr)
		{
			SDL_DestroyTexture(texture);
		}
		SDL_Surface* surf = TTF_RenderText_Solid(sys.getFont(), text.c_str(), { 0,0,0 });
		texture = SDL_CreateTextureFromSurface(sys.getRen(), surf);
		setWH(surf->w, surf->h);
		SDL_FreeSurface(surf);
	}

	void Labeled::setText(const string& txt) {
		text = txt;
		makeTexture();
	}

	Labeled::~Labeled()
	{
		SDL_DestroyTexture(texture);
	}
}