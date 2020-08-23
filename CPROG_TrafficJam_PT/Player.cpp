#include "Player.h"
#include "System.h"
#include <SDL_image.h>
#include <SDL_rect.h>

namespace jam {
	Player* Player::getInstance(int x, int y, int w, int h) {
		return new Player(x, y, w, h);
	}
	Player::Player(int x, int y, int w, int h) : Component(x, y, w, h) {
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
	Stone* Player::throwStone() {
		
		return Stone::getInstance(300,150,20,20,1);
	}
}