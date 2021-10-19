#pragma once
#include "Ogre.h"


/// <summary>
/// Class for the behaviour of the Ball
/// </summary>
class Ball
{
private:
	///Velocity on Y-axis
	Ogre::int32 VelocityonY;

	///Velocity on X-axis
	Ogre::int32 VelocityonX;

	///Points for the Ball
	Ogre::Vector3 Position;
	Ogre::SceneNode* BallNode;

public:
	Ball();

	/// <summary>
	/// Constructor of the Ball Class
	/// </summary>
	/// <param name="BallEntity"></param> A reference to the Entity we want to use
	/// <param name="SceneManager"></param> A reference to the Scene Manager
	Ball(Ogre::Entity* BallEntity, Ogre::SceneManager* SceneManager);

	/// Destructor
	/// 
	/// @param no parameters
	~Ball();
	Ogre::Vector3 BallTranslate;

	/// Can get the position of the Ball
	/// 
	/// @param no parameters
	/// @returns Returns the position as an Ogre::Vector3
	Ogre::Vector3 getPosition();
	void setPosition(Ogre::Vector3);

	/// Can get the Shape of the Ball
	/// 
	/// @param no parameters
	Ogre::SceneNode* getShape();

	/// Can get the Velocity on x-axis of the Ball
	/// 
	/// @param no parameters
	Ogre::int32 getVelocityonX();
	void setVelocityonX(Ogre::int32 x);
	void setVelocityonY(Ogre::int32 y);
	Ogre::int32 getVelocityonY();

	///Update everyframe Function
	void update(const Ogre::FrameEvent& evt);

	///Reset the Ball position and attributes 
	void reset();
};
