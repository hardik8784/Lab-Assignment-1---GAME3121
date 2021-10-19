#pragma once
/** @file Lab Assignment 1 - 101249099.cpp
 *  @brief LAB Assignment 
 *
 * 
 *
 *  @author Hooman Salamat
 *  @Editor Hardik Shah
 *  @bug No known bugs.
 */

#include "Ogre.h"
#include "Ball.h"
#include "Bat.h"

#include "OgreApplicationContext.h"
#include "OgreInput.h"
#include "OgreRTShaderSystem.h"
#include "OgreTrays.h"
#include <iostream>

using namespace Ogre;
using namespace OgreBites;
Ogre::Vector3 translate(0, 0, 0);

Ogre::int32 MoveDirectionY;
Ogre::int32 MoveDirectionX;

class ExampleFrameListener : public Ogre::FrameListener
{
private:
    Ogre::SceneNode* BatNode;
    Ogre::SceneNode* BallNode;
public:

    ExampleFrameListener(Ogre::SceneNode* node, Ogre::SceneNode* bnode)
    {
        BatNode = node;
        BallNode = bnode;
    }

    bool frameStarted(const Ogre::FrameEvent& evt)
    {
        return true;
    }
};

class Game
    : public ApplicationContext
    , public InputListener
{
private:
    SceneNode* BatNode;
    Ogre::SceneNode* BallNode;
    SceneManager* SceneManager;
    OgreBites::TrayManager* TrayManager;
    Root* root;
    Ogre::int32 isCollide;

    Ogre::int32 Score = 0;
    Ogre::int32 Lives = 3;
    bool gameover = false;
    int NumberofFrame = 0;
    float Time = 0;
    float FrameRate = 0;
    float rt = 0.03;
public:
    Game();
    virtual ~Game() {}

    void setup();
    bool keyPressed(const KeyboardEvent& evt);
    bool mouseMoved(const MouseMotionEvent& evt) override;
    bool frameRenderingQueued(const FrameEvent& evt);
    void createScene();
    void createCamera();
    void createFrameListener();
    OgreBites::TrayListener TrayListener;
    OgreBites::Label* mInfoLabel;
    OgreBites::Label* mScoreLabel;
    OgreBites::Label* mScore;
    OgreBites::Label* mLivesLabel;
    OgreBites::Label* mLives;
    OgreBites::Label* mFPS;
    OgreBites::Label* mTPU;
    OgreBites::Button* QuitButton = nullptr;
    OgreBites::Label* mGameOverLabel;
    OgreBites::Label* mHelp;
    Ogre::DisplayString sc;
    Ogre::DisplayString l;
    Ball* mBall;
    Bat* mBat;
};


Game::Game()
    : ApplicationContext("Lab Assignment 1 - 101249099")
{
    Score = 0;
    Lives = 3;
    isCollide = 0;              //no collision
    mBall = nullptr;
}


void Game::setup()
{
    // do not forget to call the base first
    ApplicationContext::setup();
    addInputListener(this);

    // get a pointer to the already created root
    //Root* 
    root = getRoot();

    //SceneManager* 
    SceneManager = root->createSceneManager();

    // register our scene with the RTSS
    RTShader::ShaderGenerator* shadergen = RTShader::ShaderGenerator::getSingletonPtr();
    shadergen->addSceneManager(SceneManager);
    createScene();
    createCamera();
    createFrameListener();





}

void Game::createScene()
{
    // -- tutorial section start --
    //! [turnlights]
    SceneManager->setAmbientLight(ColourValue(0.5, 0.5, 0.5));
    //! [turnlights]

    //! [newlight]
    Light* light = SceneManager->createLight("MainLight");
    SceneNode* lightNode = SceneManager->getRootSceneNode()->createChildSceneNode();
    lightNode->attachObject(light);
    //! [newlight]

    //! [lightpos]
    lightNode->setPosition(20, 80, 50);
    //! [lightpos]

    //std::cout << "h:" << getRenderWindow()->getHeight() << ";w:" << getRenderWindow()->getWidth() << std::endl;
    //OgreBites::TrayManager* 
    TrayManager = new OgreBites::TrayManager("InterfaceName", getRenderWindow());

    //you must add this in order to add a tray
    SceneManager->addRenderQueueListener(mOverlaySystem);
    //Once you have your tray manager, make sure you relay input events to it.
    addInputListener(TrayManager);

    // TrayManager->showLogo(TL_TOPRIGHT);

    sc = std::to_string(Score);
    l = std::to_string(Lives);
    mInfoLabel = TrayManager->createLabel(TL_TOP, "TInfo", "Lab Assignment 1 - 101249099", 300);
    //mHelp = TrayManager->createLabel(TL_BOTTOM, "Thelp", "press 'm' for switching mouse/key arrow or A D", 500);
    mScoreLabel = TrayManager->createLabel(TL_TOPLEFT, "Score", "Score:", 150);
    mScore = TrayManager->createLabel(TL_TOPLEFT, "score", sc, 150);
    mLivesLabel = TrayManager->createLabel(TL_TOPLEFT, "Lives", "Lives:", 150);
    mLives = TrayManager->createLabel(TL_TOPLEFT, "lives", l, 150);
    mFPS = TrayManager->createLabel(TL_BOTTOMLEFT, "FPS", "FPS: 60", 150);
    mTPU = TrayManager->createLabel(TL_BOTTOMRIGHT, "TPU", "Time/Update: 0m/s", 200);
    Ogre::Entity* ballEntity = SceneManager->createEntity(SceneManager::PrefabType::PT_SPHERE);
    mBall = new Ball(ballEntity, SceneManager);
    BallNode = mBall->getShape();

    Ogre::Entity* paddleEntity = SceneManager->createEntity(SceneManager::PrefabType::PT_PLANE);  
    mBat = new Bat(paddleEntity, SceneManager);
    BatNode = mBat->getShape();
}

void Game::createCamera()
{
    //! [camera]
    SceneNode* camNode = SceneManager->getRootSceneNode()->createChildSceneNode();

    // create the camera
    Camera* cam = SceneManager->createCamera("myCam");
    cam->setNearClipDistance(5); // specific to this sample
    cam->setAutoAspectRatio(true);
    camNode->attachObject(cam);
    camNode->setPosition(0, 0, 140);

    // and tell it to render into the main window
    getRenderWindow()->addViewport(cam);
    //! [camera]


    //! [cameramove]
    camNode->setPosition(0, 47, 222);
    //! [cameramove]

}

void Game::createFrameListener()
{
    Ogre::FrameListener* FrameListener = new ExampleFrameListener(BatNode, BallNode);

    mRoot->addFrameListener(FrameListener);
}

bool Game::keyPressed(const KeyboardEvent& evt)
{
    switch (evt.keysym.sym)
    {
    case SDLK_ESCAPE:
        getRoot()->queueEndRendering();
        break;
    case 'm':
        //mBat->isMouseActive = !mBat->isMouseActive;
        break;
    case 'a':
    case SDLK_LEFT:
        //mBat->moveLeft();
        break;
    case 'd':
    case SDLK_RIGHT:
        //mBat->moveRight();
        break;
    default:
        break;
    }
    return true;
}

bool Game::mouseMoved(const MouseMotionEvent& evt)
{
    // Pause game when the game is over
    if (gameover)
        return true;

    float mtw = (evt.x - (float)getRenderWindow()->getWidth() / 2.0f) * 0.5f;

    mBat->SetPosition(Vector3(mtw, -10.f, 0.f));

    return true;
}
bool Game::frameRenderingQueued(const FrameEvent& Event)
{
    mBall->update(Event);
    mBat->Update(Event);
    if (Time < rt)
    {
        Time += Event.timeSinceLastFrame;
        NumberofFrame++;
    }
    else
    {
        FrameRate = (float)NumberofFrame / Time;
        NumberofFrame = 0;
        Time = 0;
        char str[20];
        sprintf_s(str, "FPS: %.1f", FrameRate);
        mFPS->setCaption(str);
    }
    char str1[80];
    sprintf_s(str1, "Time/Update: %.3f m/s", Event.timeSinceLastFrame);
    mTPU->setCaption(str1);
    if (gameover)
    {

        if (QuitButton->getState() == OgreBites::ButtonState::BS_DOWN)
        {
            getRoot()->queueEndRendering();
        }
        return true;
    }
    else
    {
        if (BallNode->getPosition().y < -50)
        {
            if (Lives > 0)
            {
                Lives--;
                l = std::to_string(Lives);
                mLives->setCaption(l);
                int v1 = (int)rand() % 200 - 200;
                BallNode->setPosition(Ogre::Vector3(v1, 100, 0));
                std::cout << "lives:" << Lives << std::endl;
                mBall->reset();
            }
            else
            {
                mGameOverLabel = TrayManager->createLabel(TL_CENTER, "gameO", "GAME OVER", 150);
                QuitButton = TrayManager->createButton(TL_CENTER, "qbtn", "Quit Game", 150);
                gameover = true;
            }

        }
        //collision for Ball and Bat
        AxisAlignedBox BallBox = BallNode->_getWorldAABB();
        AxisAlignedBox BatBox = BatNode->_getWorldAABB();
        if (BallBox.intersects(BatBox))
        {
            if (isCollide == 0)
            {
                std::cout << "collide";
                isCollide = 1;
                MoveDirectionY = -1;
                mBall->setVelocityonY(-1);
                Score = Score + 10;
                sc = std::to_string(Score);
                mScore->setCaption(sc);
                std::cout << "Score:" << Score << std::endl;
                const auto attackVector = BallNode->getPosition() - BatNode->getPosition();
                const auto normal = Ogre::Vector3(0, -1, 0);

                const auto dot = attackVector.dotProduct(normal);
                const auto angle = acos(dot / attackVector.length()) * Ogre::Math::fRad2Deg;

                if ((attackVector.x > 0 && attackVector.y > 0) || (attackVector.x < 0 && attackVector.y > 0))
                    // bottom right or bottom left
                {
                    if (angle <= 135)
                    {                      
                        MoveDirectionX = 1;
                        MoveDirectionY = -1;
                        mBall->setVelocityonY(-1);
                        mBall->setVelocityonX(1);
                        std::cout << "bottom right" << std::endl;
                    }
                    else
                    {                       
                        MoveDirectionY = -1;
                        MoveDirectionX = -1;
                        mBall->setVelocityonY(-1);
                        mBall->setVelocityonX(-1);
                        std::cout << "bottom left" << std::endl;
                    }
                }
            }

        }
        else
            isCollide = 0;

    }
    return true;
}


int main(int argc, char** argv)
{
    try
    {
        Game app;
        app.initApp();

        app.getRoot()->startRendering();
        app.closeApp();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error occurred during execution: " << e.what() << '\n';
        return 1;
    }

    return 0;
}