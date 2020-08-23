#ifndef LABEL_H
#define LABEL_H
#include <string>
#include "Labeled.h"
namespace jam {

	class Label : public Labeled
	{
	public:
		static Label* getInstance(int x, int y, const std::string& txt);
		void draw() const;
		~Label();
	protected:
		Label(int x, int y, const std::string& txt);
	};

}
#endif
