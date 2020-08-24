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
		static Player* getInstance(int x, int y, int w, int h, int r);
		void draw() const;
		void moveY(int);
		Stone* throwStone();
		void addReloadCount();
	protected:
		Player(int x, int y, int w, int h, int r);
	private:
		SDL_Texture* playerAvatar;
		int reloadTime;
		 int reloadCount;
	};

}
#endif // !PLAYER_H
