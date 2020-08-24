#include "Player.h"
#include "System.h"
#include <SDL_image.h>
#include <SDL_rect.h>
#include <iostream>
#include "Session.h"
namespace jam {
	Player* Player::getInstance(int x, int y, int w, int h, int r) {
		return new Player(x, y, w, h,r);
	}
	Player::Player(int x, int y, int w, int h, int r) : Component(x, y, w, h) ,reloadTime(r){
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
		if (reloadCount >= reloadTime) {
			Stone* stone;

			stone = Stone::getInstance(getRect().x, getRect().y, 20, 20, 1);
			reloadCount = 0;
			return stone;
		}
		else return nullptr;
	}
	void Player::addReloadCount()
	{
		reloadCount++;
	}
}