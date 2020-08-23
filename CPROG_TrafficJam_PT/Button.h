#ifndef BUTTON_H
#define BUTTON_H
#include "Labeled.h"
namespace jam {


	class Button : public Labeled
	{
	public:
		static Button* getInstance(int x, int y, const std::string& txt);
		void draw() const;
		void mouseDown(const SDL_Event& event);
		void mouseUp(const SDL_Event& event);
		virtual void perform(const std::string&) {}
		~Button();
	protected:
		Button(int x, int y, const std::string& txt);
	private:
		SDL_Texture* upIcon, *downIcon;
		bool isDown = false;
	};

}

#endif // !BUTTON_H