#include "BasicExamples.h"
#include "RenderObject.h"
#include "PhysicsObject.h"

using namespace NCL;

BasicExamples::BasicExamples(GameTechRenderer* render) {
	cubeMesh    = render->LoadMesh("cube.msh");
	sphereMesh  = render->LoadMesh("sphere.msh");
	charMesh    = render->LoadMesh("Keeper.msh");
	goatMesh    = render->LoadMesh("goat.msh");
	capsuleMesh = render->LoadMesh("capsule.msh");

	basicTexture = render->LoadTexture("checkerboard.png");
	basicShader = render->LoadShader("scene.vert", "scene.frag");
}

BasicExamples::~BasicExamples() {
	cubeMesh = nullptr;
	sphereMesh = nullptr;
	charMesh = nullptr;
	goatMesh = nullptr;
	capsuleMesh = nullptr;
	basicTexture = nullptr;
	basicShader = nullptr;
}

GameObject* BasicExamples::CreateCube(const Vector3& position, const Vector3& dimensions, float inverseMass) {
	GameObject* cube = new GameObject("cube");

	AABBVolume* volume = new AABBVolume(dimensions);
	cube->SetBoundingVolume((CollisionVolume*)volume);

	cube->GetTransform().SetPosition(position).SetScale(dimensions * 2);
	cube->SetRenderObject(new RenderObject(&cube->GetTransform(), cubeMesh, basicTexture, basicShader));
	cube->SetPhysicsObject(new PhysicsObject(&cube->GetTransform(), cube->GetBoundingVolume()));

	cube->GetPhysicsObject()->SetInverseMass(inverseMass);
	cube->GetPhysicsObject()->InitCubeInertia();

	return cube;
}

GameObject* BasicExamples::CreateSphere(const Vector3& position, float radius, float inverseMass) {
	GameObject* sphere = new GameObject("sphere");

	Vector3 sphereSize = Vector3(radius, radius, radius);
	SphereVolume* volume = new SphereVolume(radius);
	sphere->SetBoundingVolume((CollisionVolume*)volume);

	sphere->GetTransform().SetScale(sphereSize).SetPosition(position);

	sphere->SetRenderObject(new RenderObject(&sphere->GetTransform(), sphereMesh, basicTexture, basicShader));
	sphere->SetPhysicsObject(new PhysicsObject(&sphere->GetTransform(), sphere->GetBoundingVolume()));

	sphere->GetPhysicsObject()->SetInverseMass(inverseMass);
	sphere->GetPhysicsObject()->InitSphereInertia();

	return sphere;
}

GameObject* BasicExamples::CreateChar(const Vector3& position, const Vector3& dimensions, float inverseMass) {
	GameObject* character = new GameObject("character");

	AABBVolume* volume = new AABBVolume(dimensions);
	character->SetBoundingVolume((CollisionVolume*)volume);

	character->GetTransform().SetScale(dimensions * 2).SetPosition(position);
	character->SetRenderObject(new RenderObject(&character->GetTransform(), charMesh, basicTexture, basicShader));
	character->SetPhysicsObject(new PhysicsObject(&character->GetTransform(), character->GetBoundingVolume()));

	character->GetPhysicsObject()->SetInverseMass(inverseMass);
	character->GetPhysicsObject()->InitCubeInertia();

	return character;
}

GameObject* BasicExamples::CreateGoat(const Vector3& position, const Vector3& dimensions, float inverseMass) {
	GameObject* goat = new GameObject("goat");

	AABBVolume* volume = new AABBVolume(dimensions);
	goat->SetBoundingVolume((CollisionVolume*)volume);

	goat->GetTransform().SetScale(dimensions * 2).SetPosition(position);
	goat->SetRenderObject(new RenderObject(&goat->GetTransform(), goatMesh, basicTexture, basicShader));
	goat->SetPhysicsObject(new PhysicsObject(&goat->GetTransform(), goat->GetBoundingVolume()));

	goat->GetPhysicsObject()->SetInverseMass(inverseMass);
	goat->GetPhysicsObject()->InitCubeInertia();

	return goat;
}

GameObject* BasicExamples::CreateCapsule(const Vector3& position, float halfHeight, float radius, float inverseMass) {
	GameObject* capsule = new GameObject("capsule");

	CapsuleVolume* volume = new CapsuleVolume(halfHeight, radius);
	capsule->SetBoundingVolume((CollisionVolume*)volume);

	capsule->GetTransform().SetPosition(position).SetScale(Vector3(radius, halfHeight, radius));
	capsule->SetRenderObject(new RenderObject(&capsule->GetTransform(), capsuleMesh, basicTexture, basicShader));
	capsule->SetPhysicsObject(new PhysicsObject(&capsule->GetTransform(), capsule->GetBoundingVolume()));

	capsule->GetPhysicsObject()->SetInverseMass(inverseMass);
	capsule->GetPhysicsObject()->InitSphereInertia();

	return capsule;
}