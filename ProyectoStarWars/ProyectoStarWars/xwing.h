#include "Ogre/ogre.h"
#include "OIS/ois.h"

class Xwing
{
  float xpos, ypos, zpos;
  float rot, rotLeftUp, rotLeftDown, rotRightUp, rotRightDown;
  //Body Nodes
  Ogre::SceneNode* main;
  Ogre::SceneNode* backBodyNode; 
  Ogre::SceneNode* frontBodyNode;
  Ogre::SceneNode* cabinNode;
  //Rotating Nodes for Wings
  Ogre::SceneNode* leftUpperNode;
  Ogre::SceneNode* leftLowerNode;
  Ogre::SceneNode* rightUpperNode;
  Ogre::SceneNode* rightLowerNode;
  //Wings Nodes
  Ogre::SceneNode* leftUpperWingNode;
  Ogre::SceneNode* leftLowerWingNode;
  Ogre::SceneNode* rightUpperWingNode;
  Ogre::SceneNode* rightLowerWingNode;
  //Engines Nodes
  Ogre::SceneNode* leftUpperFrontEngineNode;
  Ogre::SceneNode* leftLowerFrontEngineNode;
  Ogre::SceneNode* rightUpperFrontEngineNode;
  Ogre::SceneNode* rightLowerFrontEngineNode;
  Ogre::SceneNode* leftUpperBackEngineNode;
  Ogre::SceneNode* leftLowerBackEngineNode;
  Ogre::SceneNode* rightUpperBackEngineNode;
  Ogre::SceneNode* rightLowerBackEngineNode;
  //Cannons Nodes
  Ogre::SceneNode* leftUpperCannonNode;
  Ogre::SceneNode* leftLowerCannonNode;
  Ogre::SceneNode* rightUpperCannonNode;
  Ogre::SceneNode* rightLowerCannonNode;
  //Extra Node
  Ogre::SceneNode* r2d2Node;
  
  //Body Manual Objects
  Ogre::ManualObject* backBody;
  Ogre::ManualObject* frontBody;
  Ogre::ManualObject* cabin;
  //Wings Manual Objects
  Ogre::ManualObject* leftUpperWing;
  Ogre::ManualObject* leftLowerWing;
  Ogre::ManualObject* rightUpperWing;
  Ogre::ManualObject* rightLowerWing;
  //Engines Entities
  Ogre::Entity* leftUpperFrontEngine;
  Ogre::Entity* leftLowerFrontEngine;
  Ogre::Entity* rightUpperFrontEngine;
  Ogre::Entity* rightLowerFrontEngine;
  Ogre::Entity* leftUpperBackEngine;
  Ogre::Entity* leftLowerBackEngine;
  Ogre::Entity* rightUpperBackEngine;
  Ogre::Entity* rightLowerBackEngine;
  //Cannons Entities
  Ogre::Entity* leftUpperCannon;
  Ogre::Entity* leftLowerCannon;
  Ogre::Entity* rightUpperCannon;
  Ogre::Entity* rightLowerCannon;
  //Extra Entity
  Ogre::Entity* r2d2;

public:
  Xwing();
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
};