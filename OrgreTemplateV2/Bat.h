#pragma once
#include "Ogre.h"

/// <summary>
/// Class for the behaviour of the Bat
/// </summary>
class Bat
{
private:
	Ogre::int32 Speed;

	/*Points for the Bat*/
	Ogre::Vector3 Position;
	Ogre::SceneNode* BatNode;

public:
	Bat();

	/// <summary>
	/// Constructor of Bat Class
	/// </summary>
	/// <param name="BatEntity"></param> A reference to the Entity we want to use
	/// <param name="SceneManager"></param> A reference to the Scene Manager
	Bat(Ogre::Entity* BatEntity, Ogre::SceneManager* SceneManager);


	/// Destructor
	/// 
	/// @param no parameters
	~Bat();
	Ogre::Vector3 BatTranslate;

	/// Can get the position of the Bat
	/// 
	/// @param no parameters
	/// @returns Returns the position as an Ogre::Vector3
	Ogre::Vector3 getPosition();
	void SetPosition(Ogre::Vector3);
	Ogre::SceneNode* getShape();
	Ogre::int32 getSpeed();

	/// Set the Speed 
	void setSpeed(Ogre::int32 x);

	///Update everyframe Function
	void Update(const Ogre::FrameEvent& evt);

	///Move towards left Function for the Bat
	void MoveLeft();

	///Move towards right Function for the Bat
	void MoveRight();

	///Reset the Bat position and attributes 
	void Reset();
};
