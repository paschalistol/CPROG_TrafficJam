#ifndef PLAYER_H
#define PLAYER_H
#include "Session.h"
#include "Component.h"
#include <SDL.h>
namespace jam {

	class Player : public Component
	{
	public:
		~Player();
		static Player* getInstance(int x, int y, int w, int h, Session& ses);
		void draw() const;
		void moveY(int);
	protected:
		Player(int x, int y, int w, int h,  Session& ses);
	private:
		SDL_Texture* playerAvatar;
	};

}
#endif // !PLAYER_H
