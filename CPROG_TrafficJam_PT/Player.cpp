#include "Player.h"
#include "System.h"
#include <SDL_image.h>
namespace jam {
	Player* Player::getInstance(int x, int y, int w, int h, Session& ses) {
		return new Player(x, y, w, h, ses);
	}
	Player::Player(int x, int y, int w, int h,  Session& ses) : Component(x, y, w, h) {
		playerAvatar = IMG_LoadTexture(sys.getRen(), "../Resources/person.jpg");
	}
	void Player::draw() const
	{
		SDL_RenderCopy(sys.getRen(), playerAvatar, NULL, &getRect());
	}
	void Player::moveY(int y) {
		changeY(y);
	}
	Player::~Player() {
		SDL_DestroyTexture(playerAvatar);
	}
}