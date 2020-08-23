#ifndef LABELED_H
#define LABELED_H
#include <string>
#include <SDL.h>
#include "Component.h"
namespace jam
{

	class Labeled : public Component
	{
	public:
		void setText(const std::string& txt);
		std::string getText() const;
		~Labeled();
	protected:
		Labeled(int x, int y, const std::string& txt);
		SDL_Texture* getTexture() const { return texture; }
	private:
		std::string text;
		SDL_Texture* texture = nullptr;
		void makeTexture();
	};


} //jam
#endif // !LABELED_H