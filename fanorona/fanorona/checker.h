#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class checker {
private:
	bool color, selected, inGame;
	float x, y;
	RenderWindow *window;
	CircleShape shape;

public:
	checker(float x, float y, bool color);
	float *getX();
	float *getY();
	CircleShape *getShape();
	bool *getSelected();
	bool getColor();
	void updatePosition();
	bool *getInGame();
};