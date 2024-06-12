#pragma once
#include <vector>
#include "Actor.h"
#include "SpriteComponent.h"
#include "Window.h"
#include "Vector2.h"
#include "RendererOGL.h"
#include "Camera.h"
#include "InputSystem.h"
#include "PhysicsSystem.h"
#include "PlaneActor.h"
#include "CubeActor.h"
#include "HUD.h"

using std::vector;

enum class GameState
{
	Gameplay, Pause, Quit
};

class Game
{
public:
	static Game& instance()
	{
		static Game inst;
		return inst;
	}

	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	Game(Game&&) = delete;
	Game& operator=(Game&&) = delete;

//private:
//	Game() : isRunning(true), isUpdatingActors(false), fps(nullptr), crosshair(nullptr), follow(nullptr), orbit(nullptr), path(nullptr) {}

private:
	Game() : state(GameState::Gameplay), isUpdatingActors(false), fps(nullptr), crosshair(nullptr) {}

public:
	bool initialize();
	void load();
	void loop();
	void unload();
	void close();

	GameState getState() const { return state; }
	void setState(GameState stateP);
	InputSystem& getInputSystem() { return inputSystem; }

	void addActor(Actor* actor);
	void removeActor(Actor* actor);
	RendererOGL& getRenderer() { return renderer; }
	PhysicsSystem& getPhysicsSystem() { return physicsSystem; }

	const vector<class UIScreen*>& getUIStack() { return UIStack; }
	void pushUI(class UIScreen* screen);
	HUD* getHUD() { return hud; }

	// Game-specific
	void addPlane(class PlaneActor* plane);
	void removePlane(class PlaneActor* plane);
	vector<PlaneActor*>& getPlanes() { return planes; }
	class FPSActor* getPlayer() { return fps; }
	//class FollowActor* getPlayer() { return player; }

	void addCube(class CubeActor* cube);
	vector<CubeActor*>& getCubes() { return cubes; }


private:
	void processInput();
	void update(float dt);
	void render();
	void changeCamera(int mode);

	bool isRunning;
	GameState state;
	Window window;
	RendererOGL renderer;
	InputSystem inputSystem;
	PhysicsSystem physicsSystem;
	vector<class UIScreen*> UIStack;
	HUD* hud;

	bool isUpdatingActors;
	vector<Actor*> actors;
	vector<Actor*> pendingActors;
	Camera* camera;

	class CubeActor* platform;
	class CubeActor* elevator;
	float elevatorPos = 650.0f;
	float elevatorSpeed = 4.0f;
	float platformPos = -200.0f;
	float platformSpeed = 3.0f;

	class FPSActor* fps;
	class SpriteComponent* crosshair;
	class FollowActor* follow;
	class OrbitActor* orbit;
	class SplineActor* path;

	vector<PlaneActor*> planes;
	vector<CubeActor*> cubes;

};

