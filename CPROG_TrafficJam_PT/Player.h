#ifndef PLAYER_H
#define PLAYER_H
#include "Component.h"
#include "Stone.h"
#include <SDL.h>
namespace jam {

	class Player : public Component
	{
	public:
		~Player();
		static Player* getInstance(int x, int y, int w, int h);
		void draw() const;
		void moveY(int);
		Stone* throwStone();
	protected:
		Player(int x, int y, int w, int h);
	private:
		SDL_Texture* playerAvatar;
	};

}
#endif // !PLAYER_H
