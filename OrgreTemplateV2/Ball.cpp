#include "Ball.h"

Ball::Ball()
{
}

Ball::Ball(Ogre::Entity* Entity, Ogre::SceneManager* SceneManager)
{
	BallNode = SceneManager->getRootSceneNode()->createChildSceneNode();
	int v1 = rand() % 100;
	BallNode->setPosition(v1, 100, 0);
	BallNode->setScale(0.1f, 0.1f, 0.1f);

	BallNode->attachObject(Entity);
	reset();
	
	Position = BallNode->getPosition();
	
}

Ball::~Ball()
{
}

void Ball::reset() {
	VelocityonY = 1;

	VelocityonX = 0;
	int v1 = rand() % 100;
	BallTranslate = Ogre::Vector3(v1, 100, 0);
}

Ogre::Vector3 Ball::getPosition()
{
	return Position;
}

void Ball::setPosition(Ogre::Vector3 Position)
{
	Position = Position;
}

Ogre::SceneNode* Ball::getShape()
{
	return BallNode;
}

Ogre::int32 Ball::getVelocityonX()
{
	return VelocityonX;
}

void Ball::setVelocityonX(Ogre::int32 x)
{
	VelocityonX = x;
}

Ogre::int32 Ball::getVelocityonY()
{
	return VelocityonY;
}

void Ball::setVelocityonY(Ogre::int32 y)
{
	VelocityonY = y;
}

void Ball::update(const Ogre::FrameEvent& Event)
{
	BallTranslate = Ogre::Vector3(-50 * VelocityonX, -50 * VelocityonY, 0);

    if (BallNode->getPosition().y > 135)
    {
        VelocityonY = 1;
    }
    
    if (BallNode->getPosition().x > 112)
    {
        VelocityonX = 1;
    }
    if (BallNode->getPosition().x < -112)
    {
        VelocityonX = -1;
    }
	BallNode->translate(BallTranslate * Event.timeSinceLastFrame);
}
