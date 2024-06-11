#include "CubeActor.h"
#include "MeshComponent.h"
#include "Assets.h"
#include "Game.h"
#include "BoxComponent.h"

CubeActor::CubeActor()
{
	MeshComponent* mc = new MeshComponent(this);
	Mesh* mesh = &Assets::getMesh("Mesh_Cube");
	
	mc->setMesh(*mesh);
	box = new BoxComponent(this);
	box->setObjectBox(mesh->getBox());

	getGame().addCube(this);
}
