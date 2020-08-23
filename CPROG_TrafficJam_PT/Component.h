#ifndef COMPONENT_H
#define COMPONENT_H
#include <SDL.h>
namespace jam {

	class Component
	{
	public:

		virtual void mouseDown(const SDL_Event& event) {}
		virtual void mouseUp(const SDL_Event& event) {}
		virtual void keyDown(const SDL_Event& event) {}
		virtual void keyUp(const SDL_Event& event) {}
		virtual ~Component() {}
		SDL_Rect getRect() const { return rect; }
		virtual void draw() const = 0;
		Component(const Component&) = delete;
		const Component& operator=(const Component&) = delete;
		void changeY(int i);
		void changeX(int i);
		virtual void moveY(int) {};
	protected:
		Component(int x, int y, int w, int h);
		void setWH(int w, int h);
	private:
		SDL_Rect rect;
	};
} //arkanoid
#endif
