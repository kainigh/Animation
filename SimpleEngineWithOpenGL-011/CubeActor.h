#pragma once
#include "Actor.h"
class CubeActor : public Actor
{
public:
	CubeActor();

	class BoxComponent* getBox() { return box; }

private:
	class BoxComponent* box;
};

