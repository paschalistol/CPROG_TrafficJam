#include "Button.h"
#include <SDL_image.h>
#include "System.h"
using namespace std;
namespace jam {

	Button* Button::getInstance(int x, int y, const string& txt) {
		return  new Button(x, y, txt);
	}
	Button::Button(int x, int y, const string& txt) :Labeled(x,y,txt) {
		//!!!!!!!!make an if null

		upIcon = IMG_LoadTexture(sys.getRen(), "c:/images/up.png");
		downIcon = IMG_LoadTexture(sys.getRen(), "c:/images/down.png");
	}
	void Button::mouseDown(const SDL_Event& event) {
		SDL_Point point = { event.button.x, event.button.y };
		if (SDL_PointInRect(&point, &getRect()))
		{
			isDown = true;
		}
	}
	void Button::mouseUp(const SDL_Event& event) {
		SDL_Point point = { event.button.x, event.button.y };
		if (isDown && SDL_PointInRect(&point, &getRect()))
		{
			perform(getText());
		}
		isDown = false;
	}
	void Button::draw() const {
		if (isDown)
		{
			SDL_RenderCopy(sys.getRen(), downIcon, NULL, &getRect());
		}
		else
		{
			SDL_RenderCopy(sys.getRen(), upIcon, NULL, &getRect());
		}
		SDL_RenderCopy(sys.getRen(), getTexture(), NULL, &getRect());
	}
	Button::~Button() {
		SDL_DestroyTexture(upIcon);
		SDL_DestroyTexture(downIcon);
	}
}