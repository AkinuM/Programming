#include "checker.h"

checker::checker(float x, float y, bool color) {
	this->x = x;
	this->y = y;
	this->color = color;
	this->selected = 0;
	this->inGame = 1;
	shape.setRadius(36);
	shape.setOutlineThickness(3);
	shape.setPosition(x, y);
	if (color == 1) {
		shape.setFillColor(Color(255, 255, 255));
		shape.setOutlineColor(Color(0, 0, 0));
	}
	else {
		shape.setFillColor(Color(0, 0, 0));
		shape.setOutlineColor(Color(255, 255, 255));
	}
}

float *checker::getX() {
	return &x;
}

float *checker::getY() {
	return &y;
}

CircleShape *checker::getShape() {
	return &shape;
}

bool *checker::getSelected() {
	return &selected;
}

bool checker::getColor() {
	return color;
}

void checker::updatePosition() {
	shape.setPosition(x, y);
}

bool *checker::getInGame() {
	return &inGame;
}