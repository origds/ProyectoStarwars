/*#include "Ogre/ogre.h"
#include "OIS/ois.h"

class Xwing
{
  float xpos, ypos, zpos;
  float rot, rotLeftUp, rotLeftDown, rotRightUp, rotRightDown;
  //Body Nodes
  Ogre::SceneNode* main, backBodyNode, frontBodyNode, cabinNode;
  //Rotating Nodes for Wings
  Ogre::SceneNode* leftUpperNode, leftLowerNode, rightUpperNode, rightLowerNode;
  //Wings Nodes
  Ogre::SceneNode* leftUpperWingNode, leftLowerWingNode;
  Ogre::SceneNode* rightUpperWingNode, rightLowerWingNode;
  //Engines Nodes
  Ogre::SceneNode* leftUpperFrontEngineNode, leftLowerFrontEngineNode, rightUpperFrontEngineNode, rightLowerFrontEngineNode;
  Ogre::SceneNode* leftUpperBackEngineNode, leftLowerBackEngineNode, rightUpperBackEngineNode, rightLowerBackEngineNode;
  //Cannons Nodes
  Ogre::SceneNode* leftUpperCannonNode, leftLowerCannonNode, rightUpperCannonNode, leftLowerCannonNode;
  //Extra Node
  Ogre::SceneNode* r2d2Node;
  
  //Body Manual Objects
  Ogre::ManualObject* backBody, frontBody, cabin;
  //Wings Manual Objects
  Ogre::ManualObject* leftUpperWing, leftLowerWing, rightUpperWing, rightLowerWing;
  //Engines Entities
  Ogre::Entity* leftUpperFrontEngine, leftLowerFrontEngine, rightUpperFrontEngine, rightLowerFrontEngine;
  Ogre::Entity* leftUpperBackEngine, leftLowerBackEngine, rightUpperBackEngine, rightLowerBackEngine;
  //Cannons Entities
  Ogre::Entity* leftUpperCannon, leftLowerCannon, rightUpperCannon, leftLowerCannon;
  //Extra Entity
  Ogre::Entity* r2d2;

public:
  Xwing(float x, float y, float z, Ogre::SceneManager* _sceneManager);
  ~Xwing();

  void initXwing(float x, float y, float z);  
  //Movement
  void moveForward();
  void moveLeft();
  void moveRight();
  void moveUp();
  void moveDown();

  //Extra
  void openWings();
  void closeWings();
  void shootLaser();


private:
  //Body
  void initBackBody(Ogre::SceneManager* _sceneManager);
  void initFrontBody(Ogre::SceneManager* _sceneManager);
  void initCabin(Ogre::SceneManager* _sceneManager);
  //Wings
  void initLeftUpperWing(Ogre::SceneManager* _sceneManager);
  void initLeftLowerWing(Ogre::SceneManager* _sceneManager);
  void initRightUpperWing(Ogre::SceneManager* _sceneManager);
  void initRightLowerWing(Ogre::SceneManager* _sceneManager);
  //Engines
  void initLeftUpperFrontEngine(Ogre::SceneManager* _sceneManager);
  void initLeftLowerFrontEngine(Ogre::SceneManager* _sceneManager);
  void initRightUpperFrontEngine(Ogre::SceneManager* _sceneManager);
  void initRightLowerFrontEngine(Ogre::SceneManager* _sceneManager);
  void initLeftUpperBackEngine(Ogre::SceneManager* _sceneManager);
  void initLeftLowerBackEngine(Ogre::SceneManager* _sceneManager);
  void initRightUpperBackEngine(Ogre::SceneManager* _sceneManager);
  void initRightLowerBackEngine(Ogre::SceneManager* _sceneManager);
  //Cannons Entities
  void initLeftUpperCannon(Ogre::SceneManager* _sceneManager);
  void initLeftLowerCannon(Ogre::SceneManager* _sceneManager);
  void initRightUpperCannon(Ogre::SceneManager* _sceneManager);
  void initRightLowerCannon(Ogre::SceneManager* _sceneManager);
  //Extra Entity()
  void initR2d2(Ogre::SceneManager* _sceneManager);
};*/