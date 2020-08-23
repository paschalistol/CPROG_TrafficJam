#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "System.h"
#include "Session.h"
#include "Component.h"
#include "Label.h"
#include "Button.h"
#include <string>
#include <iostream>
#include "Lane.h"
#include "Player.h"

#include "Car.h"
#include <vector>
#define LANE_WIDTH 500
#define LANE_HEIGHT 100
#define LANE_X 0
#define LANE_Y_START 60
#define LANE_Y_DIF 5
#define FPS 60

using namespace std;
using namespace jam;

Label* lbl;
class MyButton : public Button {
public:
	MyButton(Session s) :Button(50, 100, "OK"), ses(s) {}
	void perform(const string& txt) {
		if (added)
		{
			//ses.remove(lbl);
			added = false;
		}
		else {

			ses.add(lbl);
			added = true;
		}
	}
private:
	bool added = true;
	Session& ses;
};

int main(int argc, char** argv) {
	//SDL_Init(SDL_INIT_EVERYTHING);
	Session ses(FPS);
	//lbl = Label::getInstance(100, 100, "PT_");
	//Button* b = new MyButton(ses);

	//ses.add(b);
	int startLane = 0;
	int playerHeight = LANE_HEIGHT / 2;
	ses.setPlayerMovementY(LANE_HEIGHT + LANE_Y_DIF);
	ses.setStartLane(startLane);
	Lane* lane1 = Lane::getInstance(LANE_X, LANE_Y_START , LANE_WIDTH, LANE_HEIGHT, 255,0,100,255);
	Lane* lane2 = Lane::getInstance(LANE_X, LANE_Y_START + LANE_Y_DIF + LANE_HEIGHT, LANE_WIDTH, LANE_HEIGHT, 100,200,0,255);
	Lane* lane3 = Lane::getInstance(LANE_X, LANE_Y_START + (2 * LANE_Y_DIF) + (2 * LANE_HEIGHT), LANE_WIDTH, LANE_HEIGHT, 0,255,100,255);
	ses.addLane(lane1);
	ses.addLane(lane2);
	ses.addLane(lane3);
	Session& sref = ses;
	Lane* lref = ses.getLane(startLane);
	Player* player = Player::getInstance(LANE_WIDTH, lref->getY() + LANE_HEIGHT - playerHeight,100 ,playerHeight);
	//ses.definePlayer(player);
	ses.add(player);
	ses.run();
	return 0;
}