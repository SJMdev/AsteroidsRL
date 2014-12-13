#pragma once
#include "moveable.h"

class Bullet : public Moveable
{
public:
	Bullet(int x, int y, double dx, double dy, int rotation) : Moveable(x, y, dx, dy, true), movesCounter(0), radius(2)
	{
		double rotx = cos(deg2rad(rotation)) * 4;
		double roty = sin(deg2rad(rotation)) * 4;
		this->path.setDx(rotx);
		this->path.setDy(roty);
		//std::cout << "Bullet was just created that has a wrap of: " << path.getWrap() << std::endl;
	};
	~Bullet()					{};

	void draw();

	void moveBullet();
	bool readyToDie() { return this->movesCounter > Point::xMax - 10; }
	int getRadius() { return radius; }
	int getMovesCounter() { return this->movesCounter; }
private:
	int movesCounter;
	int radius;
};

