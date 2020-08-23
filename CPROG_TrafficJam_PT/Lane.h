#ifndef LANE_H
#define LANE_H
#include <SDL.h>
#include "Component.h"
namespace jam {

	class Lane :public Component
	{
	public:
		static Lane* getInstance(int x, int y, int w, int h, int r, int g, int b, int a);
		~Lane();
		bool getLaneEmpty();
		void draw() const;
		void setLaneEmpty(bool);
		int getY() { return y; }
	protected:
		Lane(int x, int y, int w, int h, int r, int g, int b, int a);
	private:
		int x, y;
		bool laneEmpty = true;
		SDL_Surface* lane;
		SDL_Texture* laneTexture;
	};
}
#endif
