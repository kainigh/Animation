#pragma once
#include "Actor.h"
#include <iostream>

class CubeActor : public Actor
{
public:
	CubeActor();

	class BoxComponent* getBox() { return box; }
	std::string lable;

private:
	class BoxComponent* box;

	
};

