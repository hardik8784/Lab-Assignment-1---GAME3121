#include "Bat.h"

Bat::Bat()
{
}

Bat::Bat(Ogre::Entity* ent, Ogre::SceneManager* scnMgr)
{
	BatNode = scnMgr->getRootSceneNode()->createChildSceneNode();
	BatNode->setPosition(0, -10, 0);
	BatNode->setScale(0.2f, 0.05f, 1.0f);
	BatNode->attachObject(ent);
	Reset();

	Position = BatNode->getPosition();
}

Bat::~Bat()
{
}

Ogre::Vector3 Bat::getPosition()
{
	return Position;
}

void Bat::SetPosition(Ogre::Vector3 p)
{
	Position = p;
}

Ogre::SceneNode* Bat::getShape()
{
	return BatNode;
}

Ogre::int32 Bat::getSpeed()
{
	return Speed;
}

void Bat::setSpeed(Ogre::int32 x)
{
	Speed = x;
}

void Bat::Update(const Ogre::FrameEvent& evt)
{
	if (Position.x > 102)
		Position.x = 102;
	if (Position.x < -102)
		Position.x = -102;
	BatNode->setPosition(Position);
}

void Bat::MoveLeft()
{
	if (BatNode->getPosition().x > -102)
		BatTranslate = Ogre::Vector3(-30, 0, 0);
}

void Bat::MoveRight()
{
	if (BatNode->getPosition().x < 102)
		BatTranslate = Ogre::Vector3(30, 0, 0);
}

void Bat::Reset()
{
	BatTranslate = Ogre::Vector3(0, 0, 0);
}
