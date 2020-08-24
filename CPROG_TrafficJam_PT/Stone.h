#ifndef STONE_H
#define STONE_H

#include "Component.h"

namespace jam {


	class Stone : public Component
	{
	public:
		void move(int s) {};
		static Stone* getInstance(int x, int y, int w, int h, int s);
		void draw() const;
		void stoneMovement();
		~Stone();
	protected:
		Stone(int x, int y, int w, int h, int s);
	private:
		int stoneSpeed;
		SDL_Texture* stoneTexture;
	};
}
#endif
