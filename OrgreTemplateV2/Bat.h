#pragma once
#include "Ogre.h"

class Bat
{
private:
	Ogre::int32 Speed;
	Ogre::Vector3 Position;
	Ogre::SceneNode* BatNode;

public:
	Bat();
	Bat(Ogre::Entity* BatEntity, Ogre::SceneManager* SceneManager);
	~Bat();
	Ogre::Vector3 BatTranslate;
	Ogre::Vector3 getPosition();
	void SetPosition(Ogre::Vector3);
	Ogre::SceneNode* getShape();
	Ogre::int32 getSpeed();
	void setSpeed(Ogre::int32 X);
	void Update(const Ogre::FrameEvent& Event);
	void MoveLeft();
	void MoveRight();
	void Reset();
};

