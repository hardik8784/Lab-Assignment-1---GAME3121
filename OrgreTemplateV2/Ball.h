#pragma once

#include "Ogre.h"


class Ball
{
private:
	Ogre::int32 VelocityonY;
	Ogre::int32 VelocityonX;
	Ogre::Vector3 Position;
	Ogre::SceneNode* BallNode;

public:

	Ball();
	Ball(Ogre::Entity* BallEntity, Ogre::SceneManager* SceneManager);
	~Ball();
	Ogre::Vector3 BallTranslate;
	Ogre::Vector3 getPosition();
	void SetPosition(Ogre::Vector3);
	Ogre::SceneNode* getShape();
	Ogre::int32 getVelocityonX();
	void setVelocityonX(Ogre::int32 VelocityonX);
	void setVelocityonY(Ogre::int32 VelocityonY);
	Ogre::int32 getVelocityonY();
	void update(const Ogre::FrameEvent& Event);
	void reset();

};

