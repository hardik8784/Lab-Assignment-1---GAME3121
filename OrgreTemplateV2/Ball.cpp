#include "Ball.h"

Ball::Ball()
{
}

Ball::Ball(Ogre::Entity* BallEntity, Ogre::SceneManager* SceneManager)
{
    BallNode = SceneManager->getRootSceneNode()->createChildSceneNode();
    BallNode->setPosition(0, -40, 0);
    BallNode->setScale(0.2f,0.2f, 0.2f);

}

Ball::~Ball()
{
}

Ogre::Vector3 Ball::getPosition()
{
    return Position;
}

void Ball::SetPosition(Ogre::Vector3 pos)
{
    Position = pos;
}

Ogre::SceneNode* Ball::getShape()
{
    return BallNode;
}

Ogre::int32 Ball::getVelocityonX()
{
    return VelocityonX;
}

void Ball::setVelocityonX(Ogre::int32 VelocityonX)
{
    VelocityonX = VelocityonX;
}

void Ball::setVelocityonY(Ogre::int32 VelocityonY)
{
    VelocityonY = VelocityonY;
}

Ogre::int32 Ball::getVelocityonY()
{
    return VelocityonY;
}

void Ball::update(const Ogre::FrameEvent& Event)
{
    /*BallTranslate = Ogre::Vector3(-10 * VelocityonX, -10 * VelocityonY, 0);
    if (BallNode->getPosition().y > 135)
    {
        VelocityonY = 1;
    }
    if (BallNode->getPosition().y > 112)
    {
        VelocityonX = 1;
    }
    if (BallNode->getPosition().x < -112)
    {
        VelocityonX = -1;
    }

    BallNode->translate(BallTranslate * Event.timeSinceLastFrame);*/
}

void Ball::reset()
{
    VelocityonY = 1;
    VelocityonX = 0;
    BallTranslate = Ogre::Vector3(0, 0, 0);
}
