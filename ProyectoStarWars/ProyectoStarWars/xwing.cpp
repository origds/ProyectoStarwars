#include "Ogre/ogre.h"
#include "OIS/ois.h"
#include "xwing.h"

Xwing::Xwing() {

}
Xwing::Xwing(float x, float y, float z, Ogre::SceneManager* _sceneManager){
  xpos = x;
  ypos = y;
  zpos = z;
  rot = 0.0;
  rotLeftUp = 0.0;
  rotLeftDown = 0.0;
  rotRightUp = 0.0;
  rotRightDown = 0.0;

  //Initializing nodes
  main = _sceneManager->createSceneNode("NodeXwing");
  _sceneManager->getRootSceneNode()->addChild(main);
  //Rotating Nodes for Wings
  leftUpperNode = _sceneManager->createSceneNode("leftUpperNode");
  main->addChild(leftUpperNode);
  
  leftLowerNode = _sceneManager->createSceneNode("leftLoweroode");
  main->addChild(leftLowerNode);
  
  rightUpperNode = _sceneManager->createSceneNode("rightUpperNode");
  main->addChild(rightUpperNode);

  rightLowerNode = _sceneManager->createSceneNode("rightLowerNode");
  main->addChild(rightLowerNode);

  //Body
  initBackBody(_sceneManager);
  initFrontBody(_sceneManager);
  initCabin(_sceneManager);
  //Wings
  initLeftUpperWing(_sceneManager);
  initLeftLowerWing(_sceneManager);
  initRightUpperWing(_sceneManager);
  initRightLowerWing(_sceneManager);
  //Engines
  initLeftUpperFrontEngine(_sceneManager);
  initLeftLowerFrontEngine(_sceneManager);
  initRightUpperFrontEngine(_sceneManager);
  initRightLowerFrontEngine(_sceneManager);
  initLeftUpperBackEngine(_sceneManager);
  initLeftLowerBackEngine(_sceneManager);
  initRightUpperBackEngine(_sceneManager);
  initRightLowerBackEngine(_sceneManager);
  //Cannons Entities
  initLeftUpperCannon(_sceneManager);
  initLeftLowerCannon(_sceneManager);
  initRightUpperCannon(_sceneManager);
  initRightLowerCannon(_sceneManager);
  //Extra Entity()
  initR2d2(_sceneManager);

  leftUpperNode->translate(-2.8,0.1,0.0);
  leftLowerNode->translate(-2.8,-0.1,0.0);
  rightUpperNode->translate(2.8,0.1,0.0);
  rightLowerNode->translate(2.8,-0.1,0.0);

}

Xwing::~Xwing(){
}

void Xwing::initXwing(float x, float y, float z){
  xpos = x;
  ypos = y;
  zpos = y;
  rot = 0;
}

//Movement
void Xwing::moveForward(){
  if ((zpos - 1.0) >= -800.0) {
    zpos -= 1.0;
    main->translate(0.0,0.0,-1.0);
  } else {
    zpos = 0.0;
    main->translate(0.0,0.0,-800.0);
  }
}

void Xwing::moveRight(){
  if ((xpos + 1.0) <= 17.0) {
    xpos += 1.0;
    main->translate(1.0,0.0,0.0);
    if (rot > -30.0) {
      main->roll(Ogre::Degree(-30.0));
      rot -= 30.0;
    } 
  }
}

void Xwing::moveLeft(){
  if ((xpos - 1.0) >= -17.0) {
    xpos -= 1.0;
    main->translate(-1.0,0.0,0.0);
    if (rot < 30.0) {
      main->roll(Ogre::Degree(30.0));
      rot += 30.0;
    }
  }
}

void Xwing::moveUp(){
  if ((ypos += 1.0) <= 10.0) {
    ypos += 1.0;
    main->translate(0.0,1.0,0.0);
  }
}

void Xwing::moveDown(){
  if ((ypos -= 1.0) >= -5.0) {
    ypos -= 1.0;
    main->translate(0.0,-1.0,0.0);
  }
}

//Extra
void Xwing::openWings(){
  if (rotRightUp <= 40.0) {
    rotLeftUp   -= 5.0;
    rotLeftDown += 5.0;
    rotRightUp  += 5.0;
    rotLeftDown -= 5.0;
    leftUpperNode->roll(Ogre::Degree(-5.0));
    leftLowerNode->roll(Ogre::Degree(5.0));
    rightUpperNode->roll(Ogre::Degree(5.0));
    rightLowerNode->roll(Ogre::Degree(-5.0));
  }
}

void Xwing::closeWings(){
  if (rotRightUp >= 5.0) {
    rotLeftUp   += 5.0;
    rotLeftDown -= 5.0;
    rotRightUp  -= 5.0;
    rotLeftDown += 5.0;
    leftUpperNode->roll(Ogre::Degree(5.0));
    leftLowerNode->roll(Ogre::Degree(-5.0));
    rightUpperNode->roll(Ogre::Degree(-5.0));
    rightLowerNode->roll(Ogre::Degree(5.0));
  }
}

void Xwing::shootLaser(){

}

//Private
//Body

void Xwing::initBackBody(Ogre::SceneManager* _sceneManager){
  float vertex0[3], vertex1[3], vertex2[3], vertex3[3], vertex4[3], vertex5[3], vertex6[3], vertex7[3];
  float vertex8[3], vertex9[3], vertex10[3], vertex11[3], vertex12[3], vertex13[3], vertex14[3], vertex15[3];
  float normal0[3], normal1[3], normal2[3], normal3[3], normal4[3], normal5[3], normal6[3], normal7[3];
  float normal8[3], normal9[3], normal10[3], normal11[3], normal12[3], normal13[3], normal14[3], normal15[3];
  float size;

  backBodyNode = _sceneManager->createSceneNode();
  main->addChild(backBodyNode);
  backBody = _sceneManager->createManualObject("backBody");
  backBodyNode->attachObject(backBody);

  backBody->begin("BaseWhiteNoLighting", Ogre::RenderOperation::OT_TRIANGLE_LIST);

  //Position of the vertexes
  vertex0[0] = 0.0;   //0
  vertex0[1] = 0.0;
  vertex0[2] = 2.0;
  vertex1[0] = -1.5;  //1
  vertex1[1] = 2.3;
  vertex1[2] = 0.5;
  vertex2[0] = 1.5;   //2
  vertex2[1] = 2.3;
  vertex2[2] = 0.5;
  vertex3[0] = 3.0;   //3
  vertex3[1] = 0.0;
  vertex3[2] = 0.5;
  vertex4[0] = 2.5;   //4
  vertex4[1] = -3;
  vertex4[2] = 0.5;
  vertex5[0] = 0.0;   //5
  vertex5[1] = -3.5;
  vertex5[2] = 0.5;
  vertex6[0] = -2.5;  //6
  vertex6[1] = -3;
  vertex6[2] = 0.5;
  vertex7[0] = -3.0;  //7
  vertex7[1] = 0.0;
  vertex7[2] = 0.5;
  vertex8[0] = 0.0;   //8
  vertex8[1] = 0.0;
  vertex8[2] = -7.5;
  vertex9[0] = -1.5;  //9
  vertex9[1] = 2.3;
  vertex9[2] = -6.5;
  vertex10[0] = 1.5;  //10
  vertex10[1] = 2.3;
  vertex10[2] = -6.5;
  vertex11[0] = 3.0;  //11
  vertex11[1] = 0.0;
  vertex11[2] = -6.5;
  vertex12[0] = 2.5;  //12
  vertex12[1] = -3;
  vertex12[2] = -6.5;
  vertex13[0] = 0.0;  //13
  vertex13[1] = -3.5;
  vertex13[2] = -6.5;
  vertex14[0] = -2.5; //14
  vertex14[1] = -3;
  vertex14[2] = -6.5;
  vertex15[0] = -3.0; //15
  vertex15[1] = 0.0;
  vertex15[2] = -6.5;

  //Calculating the normal for each vertex
  //normal0
  normal0[0] = (vertex1[0] + vertex2[0] + vertex3[0] + vertex4[0] + vertex5[0] + vertex6[0] + vertex7[0] - 7 * vertex0[0]) / (-7);
  normal0[1] = (vertex1[1] + vertex2[1] + vertex3[1] + vertex4[1] + vertex5[1] + vertex6[1] + vertex7[1] - 7 * vertex0[1]) / (-7);
  normal0[2] = (vertex1[2] + vertex2[2] + vertex3[2] + vertex4[2] + vertex5[2] + vertex6[2] + vertex7[2] - 7 * vertex0[2]) / (-7);
  size = sqrt(normal0[0]*normal0[0] + normal0[1]*normal0[1] + normal0[2]*normal0[2]);
  normal0[0] = normal0[0] / size;
  normal0[1] = normal0[1] / size;
  normal0[2] = normal0[2] / size;

  //normal1
  normal1[0] = (vertex0[0] + vertex2[0] + vertex7[0] + vertex9[0] + vertex10[0] - 5 * vertex1[0]) / (-5);
  normal1[1] = (vertex0[1] + vertex2[1] + vertex7[1] + vertex9[1] + vertex10[1] - 5 * vertex1[1]) / (-5);
  normal1[2] = (vertex0[2] + vertex2[2] + vertex7[2] + vertex9[2] + vertex10[2] - 5 * vertex1[2]) / (-5);
  size = sqrt(normal1[0]*normal1[0] + normal1[1]*normal1[1] + normal1[2]*normal1[2]);
  normal1[0] = normal1[0] / size;
  normal1[1] = normal1[1] / size;
  normal1[2] = normal1[2] / size;

  //normal2
  normal2[0] = (vertex0[0] + vertex1[0] + vertex3[0] + vertex10[0] + vertex11[0] - 5 * vertex2[0]) / (-5);
  normal2[1] = (vertex0[1] + vertex1[1] + vertex3[1] + vertex10[1] + vertex11[1] - 5 * vertex2[1]) / (-5);
  normal2[2] = (vertex0[2] + vertex1[2] + vertex3[2] + vertex10[2] + vertex11[2] - 5 * vertex2[2]) / (-5);
  size = sqrt(normal2[0]*normal2[0] + normal2[1]*normal2[1] + normal2[2]*normal2[2]);
  normal2[0] = normal2[0] / size;
  normal2[1] = normal2[1] / size;
  normal2[2] = normal2[2] / size;

  //normal3
  normal3[0] = (vertex0[0] + vertex2[0] + vertex4[0] + vertex11[0] + vertex12[0] - 5 * vertex3[0]) / (-5);
  normal3[1] = (vertex0[1] + vertex2[1] + vertex4[1] + vertex11[1] + vertex12[1] - 5 * vertex3[1]) / (-5);
  normal3[2] = (vertex0[2] + vertex2[2] + vertex4[2] + vertex11[2] + vertex12[2] - 5 * vertex3[2]) / (-5);
  size = sqrt(normal3[0]*normal3[0] + normal3[1]*normal3[1] + normal3[2]*normal3[2]);
  normal3[0] = normal3[0] / size;
  normal3[1] = normal3[1] / size;
  normal3[2] = normal3[2] / size;

  //normal4
  normal4[0] = (vertex0[0] + vertex3[0] + vertex5[0] + vertex12[0] + vertex13[0] - 5 * vertex4[0]) / (-5);
  normal4[1] = (vertex0[1] + vertex3[1] + vertex5[1] + vertex12[1] + vertex13[1] - 5 * vertex4[1]) / (-5);
  normal4[2] = (vertex0[2] + vertex3[2] + vertex5[2] + vertex12[2] + vertex13[2] - 5 * vertex4[2]) / (-5);
  size = sqrt(normal4[0]*normal4[0] + normal4[1]*normal4[1] + normal4[2]*normal4[2]);
  normal4[0] = normal4[0] / size;
  normal4[1] = normal4[1] / size;
  normal4[2] = normal4[2] / size;

  //normal5
  normal5[0] = (vertex0[0] + vertex4[0] + vertex6[0] + vertex13[0] + vertex14[0] - 5 * vertex5[0]) / (-5);
  normal5[1] = (vertex0[1] + vertex4[1] + vertex6[1] + vertex13[1] + vertex14[1] - 5 * vertex5[1]) / (-5);
  normal5[2] = (vertex0[2] + vertex4[2] + vertex6[2] + vertex13[2] + vertex14[2] - 5 * vertex5[2]) / (-5);
  size = sqrt(normal5[0]*normal5[0] + normal5[1]*normal5[1] + normal5[2]*normal5[2]);
  normal5[0] = normal5[0] / size;
  normal5[1] = normal5[1] / size;
  normal5[2] = normal5[2] / size;

  //normal6
  normal6[0] = (vertex0[0] + vertex5[0] + vertex7[0] + vertex14[0] + vertex15[0] - 5 * vertex6[0]) / (-5);
  normal6[1] = (vertex0[1] + vertex5[1] + vertex7[1] + vertex14[1] + vertex15[1] - 5 * vertex6[1]) / (-5);
  normal6[2] = (vertex0[2] + vertex5[2] + vertex7[2] + vertex14[2] + vertex15[2] - 5 * vertex6[2]) / (-5);
  size = sqrt(normal6[0]*normal6[0] + normal6[1]*normal6[1] + normal6[2]*normal6[2]);
  normal6[0] = normal6[0] / size;
  normal6[1] = normal6[1] / size;
  normal6[2] = normal6[2] / size;

  //normal7
  normal7[0] = (vertex0[0] + vertex1[0] + vertex6[0] + vertex9[0] + vertex15[0] - 5 * vertex7[0]) / (-5);
  normal7[1] = (vertex0[1] + vertex1[1] + vertex6[1] + vertex9[1] + vertex15[1] - 5 * vertex7[1]) / (-5);
  normal7[2] = (vertex0[2] + vertex1[2] + vertex6[2] + vertex9[2] + vertex15[2] - 5 * vertex7[2]) / (-5);
  size = sqrt(normal7[0]*normal7[0] + normal7[1]*normal7[1] + normal7[2]*normal7[2]);
  normal7[0] = normal7[0] / size;
  normal7[1] = normal7[1] / size;
  normal7[2] = normal7[2] / size;

  //normal8
  normal8[0] = (vertex9[0] + vertex10[0] + vertex11[0] + vertex12[0] + vertex13[0] + vertex14[0] + vertex15[0] - 7 * vertex8[0]) / (-7);
  normal8[1] = (vertex9[1] + vertex10[1] + vertex11[1] + vertex12[1] + vertex13[1] + vertex14[1] + vertex15[1] - 7 * vertex8[1]) / (-7);
  normal8[2] = (vertex9[2] + vertex10[2] + vertex11[2] + vertex12[2] + vertex13[2] + vertex14[2] + vertex15[2] - 7 * vertex8[2]) / (-7);
  size = sqrt(normal8[0]*normal8[0] + normal8[1]*normal8[1] + normal8[2]*normal8[2]);
  normal8[0] = normal8[0] / size;
  normal8[1] = normal8[1] / size;
  normal8[2] = normal8[2] / size;

  //normal9
  normal9[0] = (vertex8[0] + vertex15[0] + vertex10[0] + vertex1[0] + vertex7[0] - 5 * vertex9[0]) / (-5);
  normal9[1] = (vertex8[1] + vertex15[1] + vertex10[1] + vertex1[1] + vertex7[1] - 5 * vertex9[1]) / (-5);
  normal9[2] = (vertex8[2] + vertex15[2] + vertex10[2] + vertex1[2] + vertex7[2] - 5 * vertex9[2]) / (-5);
  size = sqrt(normal9[0]*normal9[0] + normal9[1]*normal9[1] + normal9[2]*normal9[2]);
  normal9[0] = normal9[0] / size;
  normal9[1] = normal9[1] / size;
  normal9[2] = normal9[2] / size;

  //normal10
  normal10[0] = (vertex8[0] + vertex9[0] + vertex11[0] + vertex1[0] + vertex2[0] - 5 * vertex10[0]) / (-5);
  normal10[1] = (vertex8[1] + vertex9[1] + vertex11[1] + vertex1[1] + vertex2[1] - 5 * vertex10[1]) / (-5);
  normal10[2] = (vertex8[2] + vertex9[2] + vertex11[2] + vertex1[2] + vertex2[2] - 5 * vertex10[2]) / (-5);
  size = sqrt(normal10[0]*normal10[0] + normal10[1]*normal10[1] + normal10[2]*normal10[2]);
  normal10[0] = normal10[0] / size;
  normal10[1] = normal10[1] / size;
  normal10[2] = normal10[2] / size;

  //normal11
  normal11[0] = (vertex8[0] + vertex10[0] + vertex12[0] + vertex3[0] + vertex2[0] - 5 * vertex11[0]) / (-5);
  normal11[1] = (vertex8[1] + vertex10[1] + vertex12[1] + vertex3[1] + vertex2[1] - 5 * vertex11[1]) / (-5);
  normal11[2] = (vertex8[2] + vertex10[2] + vertex12[2] + vertex3[2] + vertex2[2] - 5 * vertex11[2]) / (-5);
  size = sqrt(normal11[0]*normal11[0] + normal11[1]*normal11[1] + normal11[2]*normal11[2]);
  normal11[0] = normal11[0] / size;
  normal11[1] = normal11[1] / size;
  normal11[2] = normal11[2] / size;

  //normal12
  normal12[0] = (vertex8[0] + vertex11[0] + vertex13[0] + vertex3[0] + vertex4[0] - 5 * vertex12[0]) / (-5);
  normal12[1] = (vertex8[1] + vertex11[1] + vertex13[1] + vertex3[1] + vertex4[1] - 5 * vertex12[1]) / (-5);
  normal12[2] = (vertex8[2] + vertex11[2] + vertex13[2] + vertex3[2] + vertex4[2] - 5 * vertex12[2]) / (-5);
  size = sqrt(normal12[0]*normal12[0] + normal12[1]*normal12[1] + normal12[2]*normal12[2]);
  normal12[0] = normal12[0] / size;
  normal12[1] = normal12[1] / size;
  normal12[2] = normal12[2] / size;

  //normal13
  normal13[0] = (vertex8[0] + vertex12[0] + vertex13[0] + vertex4[0] + vertex5[0] - 5 * vertex13[0]) / (-5);
  normal13[1] = (vertex8[1] + vertex12[1] + vertex13[1] + vertex4[1] + vertex5[1] - 5 * vertex13[1]) / (-5);
  normal13[2] = (vertex8[2] + vertex12[2] + vertex13[2] + vertex4[2] + vertex5[2] - 5 * vertex13[2]) / (-5);
  size = sqrt(normal13[0]*normal13[0] + normal13[1]*normal13[1] + normal13[2]*normal13[2]);
  normal13[0] = normal13[0] / size;
  normal13[1] = normal13[1] / size;
  normal13[2] = normal13[2] / size;

  //normal14
  normal14[0] = (vertex8[0] + vertex13[0] + vertex14[0] + vertex5[0] + vertex6[0] - 5 * vertex14[0]) / (-5);
  normal14[1] = (vertex8[1] + vertex13[1] + vertex14[1] + vertex5[1] + vertex6[1] - 5 * vertex14[1]) / (-5);
  normal14[2] = (vertex8[2] + vertex13[2] + vertex14[2] + vertex5[2] + vertex6[2] - 5 * vertex14[2]) / (-5);
  size = sqrt(normal14[0]*normal14[0] + normal14[1]*normal14[1] + normal14[2]*normal14[2]);
  normal14[0] = normal14[0] / size;
  normal14[1] = normal14[1] / size;
  normal14[2] = normal14[2] / size;

  //normal15
  normal15[0] = (vertex8[0] + vertex9[0] + vertex14[0] + vertex6[0] + vertex7[0] - 5 * vertex15[0]) / (-5);
  normal15[1] = (vertex8[1] + vertex9[1] + vertex14[1] + vertex6[1] + vertex7[1] - 5 * vertex15[1]) / (-5);
  normal15[2] = (vertex8[2] + vertex9[2] + vertex14[2] + vertex6[2] + vertex7[2] - 5 * vertex15[2]) / (-5);
  size = sqrt(normal15[0]*normal15[0] + normal15[1]*normal15[1] + normal15[2]*normal15[2]);
  normal15[0] = normal15[0] / size;
  normal15[1] = normal15[1] / size;
  normal15[2] = normal15[2] / size;

  //Vertexs of the left lower wing
  //Back vertexes
  backBody->position(vertex0[0], vertex0[1], vertex0[2]);  //0
  backBody->position(vertex1[0], vertex1[1], vertex1[2]);  //1
  backBody->position(vertex2[0], vertex2[1], vertex2[2]);  //2
  backBody->position(vertex3[0], vertex3[1], vertex3[2]);  //3
  backBody->position(vertex4[0], vertex4[1], vertex4[2]);  //4
  backBody->position(vertex5[0], vertex5[1], vertex5[2]);  //5
  backBody->position(vertex6[0], vertex6[1], vertex6[2]);  //6
  backBody->position(vertex7[0], vertex7[1], vertex7[2]);  //7
  //Front vertexes
  backBody->position(vertex8[0], vertex8[1], vertex8[2]);     //8
  backBody->position(vertex9[0], vertex9[1], vertex9[2]);     //9
  backBody->position(vertex10[0], vertex10[1], vertex10[2]);  //10
  backBody->position(vertex11[0], vertex11[1], vertex11[2]);  //11
  backBody->position(vertex12[0], vertex12[1], vertex12[2]);  //12
  backBody->position(vertex13[0], vertex13[1], vertex13[2]);  //13
  backBody->position(vertex14[0], vertex14[1], vertex14[2]);  //14
  backBody->position(vertex15[0], vertex15[1], vertex15[2]);  //15

  //Normal of the vertexes
  //Back normals
  backBody->normal(normal0[0], normal0[1], normal0[2]);
  backBody->normal(normal1[0], normal1[1], normal1[2]);
  backBody->normal(normal2[0], normal2[1], normal2[2]);
  backBody->normal(normal3[0], normal3[1], normal3[2]);
  backBody->normal(normal4[0], normal4[1], normal4[2]);
  backBody->normal(normal5[0], normal5[1], normal5[2]);
  backBody->normal(normal6[0], normal6[1], normal6[2]);
  backBody->normal(normal7[0], normal7[1], normal7[2]);
  //Front normals
  backBody->normal(normal8[0], normal8[1], normal8[2]);
  backBody->normal(normal9[0], normal9[1], normal9[2]);
  backBody->normal(normal10[0], normal10[1], normal10[2]);
  backBody->normal(normal11[0], normal11[1], normal11[2]);
  backBody->normal(normal12[0], normal12[1], normal12[2]);
  backBody->normal(normal13[0], normal13[1], normal13[2]);
  backBody->normal(normal14[0], normal14[1], normal14[2]);
  backBody->normal(normal15[0], normal15[1], normal15[2]);

  //Creating the triangles
  //BackFace
  backBody->index(0);
  backBody->index(2);
  backBody->index(1);
  backBody->index(0);
  backBody->index(3);
  backBody->index(2);
  backBody->index(0);
  backBody->index(4);
  backBody->index(3);
  backBody->index(0);
  backBody->index(5);
  backBody->index(4);
  backBody->index(0);
  backBody->index(6);
  backBody->index(5);
  backBody->index(0);
  backBody->index(7);
  backBody->index(6);
  backBody->index(0);
  backBody->index(1);
  backBody->index(7);
  //FrontFace
  backBody->index(8);
  backBody->index(9);
  backBody->index(10);
  backBody->index(8);
  backBody->index(10);
  backBody->index(11);
  backBody->index(8);
  backBody->index(11);
  backBody->index(12);
  backBody->index(8);
  backBody->index(12);
  backBody->index(13);
  backBody->index(8);
  backBody->index(13);
  backBody->index(14);
  backBody->index(8);
  backBody->index(14);
  backBody->index(15);
  backBody->index(8);
  backBody->index(15);
  backBody->index(9);
  //1
  backBody->index(1);
  backBody->index(10);
  backBody->index(9);
  backBody->index(1);
  backBody->index(2);
  backBody->index(10);
  //2
  backBody->index(2);
  backBody->index(11);
  backBody->index(10);
  backBody->index(2);
  backBody->index(3);
  backBody->index(11);
  //3
  backBody->index(3);
  backBody->index(12);
  backBody->index(11);
  backBody->index(3);
  backBody->index(4);
  backBody->index(12);
  //4
  backBody->index(4);
  backBody->index(13);
  backBody->index(12);
  backBody->index(4);
  backBody->index(5);
  backBody->index(13);
  //5
  backBody->index(7);
  backBody->index(9);
  backBody->index(15);
  backBody->index(7);
  backBody->index(1);
  backBody->index(9);
  //6
  backBody->index(6);
  backBody->index(15);
  backBody->index(14);
  backBody->index(6);
  backBody->index(7);
  backBody->index(15);
  //7 
  backBody->index(5);
  backBody->index(14);
  backBody->index(13);
  backBody->index(5);
  backBody->index(6);
  backBody->index(14);

  backBody->end();
}

void Xwing::initFrontBody(Ogre::SceneManager* _sceneManager){

  float vertex0[3], vertex1[3], vertex2[3], vertex3[3], vertex4[3], vertex5[3], vertex6[3], vertex7[3];
  float vertex8[3], vertex9[3], vertex10[3], vertex11[3], vertex12[3], vertex13[3], vertex14[3], vertex15[3];
  float normal0[3], normal1[3], normal2[3], normal3[3], normal4[3], normal5[3], normal6[3], normal7[3];
  float normal8[3], normal9[3], normal10[3], normal11[3], normal12[3], normal13[3], normal14[3], normal15[3];
  float size;

  frontBodyNode = _sceneManager->createSceneNode();
  main->addChild(frontBodyNode);
  frontBody = _sceneManager->createManualObject("frontBody");
  frontBody->begin("BaseWhiteNoLighting", Ogre::RenderOperation::OT_TRIANGLE_LIST);

  //Position of the vertexes
  vertex0[0] = 0.0;   //0
  vertex0[1] = 0.0;
  vertex0[2] = -6.5;
  vertex1[0] = -1.5;  //1
  vertex1[1] = 2.3;
  vertex1[2] = -6.5;
  vertex2[0] = 1.5;   //2
  vertex2[1] = 2.3;
  vertex2[2] = -6.5;
  vertex3[0] = 3.0;   //3
  vertex3[1] = 0.0;
  vertex3[2] = -6.5;
  vertex4[0] = 2.5;   //4
  vertex4[1] = -3;
  vertex4[2] = -6.5;
  vertex5[0] = 0.0;   //5
  vertex5[1] = -3.5;
  vertex5[2] = -6.5;
  vertex6[0] = -2.5;  //6
  vertex6[1] = -3;
  vertex6[2] = -6.5;
  vertex7[0] = -3.0;  //7
  vertex7[1] = 0.0;
  vertex7[2] = -6.5;
  vertex8[0] = 0.0;   //8
  vertex8[1] = 0.0;
  vertex8[2] = -26.5;
  vertex9[0] = -0.5;  //9
  vertex9[1] = 1.0;
  vertex9[2] = -25.5;
  vertex10[0] = 0.5;  //10
  vertex10[1] = 1.0;
  vertex10[2] = -25.5;
  vertex11[0] = 2.0;  //11
  vertex11[1] = 0.0;
  vertex11[2] = -25.5;
  vertex12[0] = 1.5;  //12
  vertex12[1] = -0.5;
  vertex12[2] = -25.5;
  vertex13[0] = 0.0;  //13
  vertex13[1] = -1.0;
  vertex13[2] = -25.5;
  vertex14[0] = -1.5; //14
  vertex14[1] = -0.5;
  vertex14[2] = -25.5;
  vertex15[0] = -2.0; //15
  vertex15[1] = 0.0;
  vertex15[2] = -25.5;

  //Calculating the normal for each vertex
  //normal0
  normal0[0] = (vertex1[0] + vertex2[0] + vertex3[0] + vertex4[0] + vertex5[0] + vertex6[0] + vertex7[0] - 7 * vertex0[0]) / (-7);
  normal0[1] = (vertex1[1] + vertex2[1] + vertex3[1] + vertex4[1] + vertex5[1] + vertex6[1] + vertex7[1] - 7 * vertex0[1]) / (-7);
  normal0[2] = (vertex1[2] + vertex2[2] + vertex3[2] + vertex4[2] + vertex5[2] + vertex6[2] + vertex7[2] - 7 * vertex0[2]) / (-7);
  size = sqrt(normal0[0]*normal0[0] + normal0[1]*normal0[1] + normal0[2]*normal0[2]);
  normal0[0] = normal0[0] / size;
  normal0[1] = normal0[1] / size;
  normal0[2] = normal0[2] / size;

  //normal1
  normal1[0] = (vertex0[0] + vertex2[0] + vertex7[0] + vertex9[0] + vertex10[0] - 5 * vertex1[0]) / (-5);
  normal1[1] = (vertex0[1] + vertex2[1] + vertex7[1] + vertex9[1] + vertex10[1] - 5 * vertex1[1]) / (-5);
  normal1[2] = (vertex0[2] + vertex2[2] + vertex7[2] + vertex9[2] + vertex10[2] - 5 * vertex1[2]) / (-5);
  size = sqrt(normal1[0]*normal1[0] + normal1[1]*normal1[1] + normal1[2]*normal1[2]);
  normal1[0] = normal1[0] / size;
  normal1[1] = normal1[1] / size;
  normal1[2] = normal1[2] / size;

  //normal2
  normal2[0] = (vertex0[0] + vertex1[0] + vertex3[0] + vertex10[0] + vertex11[0] - 5 * vertex2[0]) / (-5);
  normal2[1] = (vertex0[1] + vertex1[1] + vertex3[1] + vertex10[1] + vertex11[1] - 5 * vertex2[1]) / (-5);
  normal2[2] = (vertex0[2] + vertex1[2] + vertex3[2] + vertex10[2] + vertex11[2] - 5 * vertex2[2]) / (-5);
  size = sqrt(normal2[0]*normal2[0] + normal2[1]*normal2[1] + normal2[2]*normal2[2]);
  normal2[0] = normal2[0] / size;
  normal2[1] = normal2[1] / size;
  normal2[2] = normal2[2] / size;

  //normal3
  normal3[0] = (vertex0[0] + vertex2[0] + vertex4[0] + vertex11[0] + vertex12[0] - 5 * vertex3[0]) / (-5);
  normal3[1] = (vertex0[1] + vertex2[1] + vertex4[1] + vertex11[1] + vertex12[1] - 5 * vertex3[1]) / (-5);
  normal3[2] = (vertex0[2] + vertex2[2] + vertex4[2] + vertex11[2] + vertex12[2] - 5 * vertex3[2]) / (-5);
  size = sqrt(normal3[0]*normal3[0] + normal3[1]*normal3[1] + normal3[2]*normal3[2]);
  normal3[0] = normal3[0] / size;
  normal3[1] = normal3[1] / size;
  normal3[2] = normal3[2] / size;

  //normal4
  normal4[0] = (vertex0[0] + vertex3[0] + vertex5[0] + vertex12[0] + vertex13[0] - 5 * vertex4[0]) / (-5);
  normal4[1] = (vertex0[1] + vertex3[1] + vertex5[1] + vertex12[1] + vertex13[1] - 5 * vertex4[1]) / (-5);
  normal4[2] = (vertex0[2] + vertex3[2] + vertex5[2] + vertex12[2] + vertex13[2] - 5 * vertex4[2]) / (-5);
  size = sqrt(normal4[0]*normal4[0] + normal4[1]*normal4[1] + normal4[2]*normal4[2]);
  normal4[0] = normal4[0] / size;
  normal4[1] = normal4[1] / size;
  normal4[2] = normal4[2] / size;

  //normal5
  normal5[0] = (vertex0[0] + vertex4[0] + vertex6[0] + vertex13[0] + vertex14[0] - 5 * vertex5[0]) / (-5);
  normal5[1] = (vertex0[1] + vertex4[1] + vertex6[1] + vertex13[1] + vertex14[1] - 5 * vertex5[1]) / (-5);
  normal5[2] = (vertex0[2] + vertex4[2] + vertex6[2] + vertex13[2] + vertex14[2] - 5 * vertex5[2]) / (-5);
  size = sqrt(normal5[0]*normal5[0] + normal5[1]*normal5[1] + normal5[2]*normal5[2]);
  normal5[0] = normal5[0] / size;
  normal5[1] = normal5[1] / size;
  normal5[2] = normal5[2] / size;

  //normal6
  normal6[0] = (vertex0[0] + vertex5[0] + vertex7[0] + vertex14[0] + vertex15[0] - 5 * vertex6[0]) / (-5);
  normal6[1] = (vertex0[1] + vertex5[1] + vertex7[1] + vertex14[1] + vertex15[1] - 5 * vertex6[1]) / (-5);
  normal6[2] = (vertex0[2] + vertex5[2] + vertex7[2] + vertex14[2] + vertex15[2] - 5 * vertex6[2]) / (-5);
  size = sqrt(normal6[0]*normal6[0] + normal6[1]*normal6[1] + normal6[2]*normal6[2]);
  normal6[0] = normal6[0] / size;
  normal6[1] = normal6[1] / size;
  normal6[2] = normal6[2] / size;

  //normal7
  normal7[0] = (vertex0[0] + vertex1[0] + vertex6[0] + vertex9[0] + vertex15[0] - 5 * vertex7[0]) / (-5);
  normal7[1] = (vertex0[1] + vertex1[1] + vertex6[1] + vertex9[1] + vertex15[1] - 5 * vertex7[1]) / (-5);
  normal7[2] = (vertex0[2] + vertex1[2] + vertex6[2] + vertex9[2] + vertex15[2] - 5 * vertex7[2]) / (-5);
  size = sqrt(normal7[0]*normal7[0] + normal7[1]*normal7[1] + normal7[2]*normal7[2]);
  normal7[0] = normal7[0] / size;
  normal7[1] = normal7[1] / size;
  normal7[2] = normal7[2] / size;

  //normal8
  normal8[0] = (vertex9[0] + vertex10[0] + vertex11[0] + vertex12[0] + vertex13[0] + vertex14[0] + vertex15[0] - 7 * vertex8[0]) / (-7);
  normal8[1] = (vertex9[1] + vertex10[1] + vertex11[1] + vertex12[1] + vertex13[1] + vertex14[1] + vertex15[1] - 7 * vertex8[1]) / (-7);
  normal8[2] = (vertex9[2] + vertex10[2] + vertex11[2] + vertex12[2] + vertex13[2] + vertex14[2] + vertex15[2] - 7 * vertex8[2]) / (-7);
  size = sqrt(normal8[0]*normal8[0] + normal8[1]*normal8[1] + normal8[2]*normal8[2]);
  normal8[0] = normal8[0] / size;
  normal8[1] = normal8[1] / size;
  normal8[2] = normal8[2] / size;

  //normal9
  normal9[0] = (vertex8[0] + vertex15[0] + vertex10[0] + vertex1[0] + vertex7[0] - 5 * vertex9[0]) / (-5);
  normal9[1] = (vertex8[1] + vertex15[1] + vertex10[1] + vertex1[1] + vertex7[1] - 5 * vertex9[1]) / (-5);
  normal9[2] = (vertex8[2] + vertex15[2] + vertex10[2] + vertex1[2] + vertex7[2] - 5 * vertex9[2]) / (-5);
  size = sqrt(normal9[0]*normal9[0] + normal9[1]*normal9[1] + normal9[2]*normal9[2]);
  normal9[0] = normal9[0] / size;
  normal9[1] = normal9[1] / size;
  normal9[2] = normal9[2] / size;

  //normal10
  normal10[0] = (vertex8[0] + vertex9[0] + vertex11[0] + vertex1[0] + vertex2[0] - 5 * vertex10[0]) / (-5);
  normal10[1] = (vertex8[1] + vertex9[1] + vertex11[1] + vertex1[1] + vertex2[1] - 5 * vertex10[1]) / (-5);
  normal10[2] = (vertex8[2] + vertex9[2] + vertex11[2] + vertex1[2] + vertex2[2] - 5 * vertex10[2]) / (-5);
  size = sqrt(normal10[0]*normal10[0] + normal10[1]*normal10[1] + normal10[2]*normal10[2]);
  normal10[0] = normal10[0] / size;
  normal10[1] = normal10[1] / size;
  normal10[2] = normal10[2] / size;

  //normal11
  normal11[0] = (vertex8[0] + vertex10[0] + vertex12[0] + vertex3[0] + vertex2[0] - 5 * vertex11[0]) / (-5);
  normal11[1] = (vertex8[1] + vertex10[1] + vertex12[1] + vertex3[1] + vertex2[1] - 5 * vertex11[1]) / (-5);
  normal11[2] = (vertex8[2] + vertex10[2] + vertex12[2] + vertex3[2] + vertex2[2] - 5 * vertex11[2]) / (-5);
  size = sqrt(normal11[0]*normal11[0] + normal11[1]*normal11[1] + normal11[2]*normal11[2]);
  normal11[0] = normal11[0] / size;
  normal11[1] = normal11[1] / size;
  normal11[2] = normal11[2] / size;

  //normal12
  normal12[0] = (vertex8[0] + vertex11[0] + vertex13[0] + vertex3[0] + vertex4[0] - 5 * vertex12[0]) / (-5);
  normal12[1] = (vertex8[1] + vertex11[1] + vertex13[1] + vertex3[1] + vertex4[1] - 5 * vertex12[1]) / (-5);
  normal12[2] = (vertex8[2] + vertex11[2] + vertex13[2] + vertex3[2] + vertex4[2] - 5 * vertex12[2]) / (-5);
  size = sqrt(normal12[0]*normal12[0] + normal12[1]*normal12[1] + normal12[2]*normal12[2]);
  normal12[0] = normal12[0] / size;
  normal12[1] = normal12[1] / size;
  normal12[2] = normal12[2] / size;

  //normal13
  normal13[0] = (vertex8[0] + vertex12[0] + vertex13[0] + vertex4[0] + vertex5[0] - 5 * vertex13[0]) / (-5);
  normal13[1] = (vertex8[1] + vertex12[1] + vertex13[1] + vertex4[1] + vertex5[1] - 5 * vertex13[1]) / (-5);
  normal13[2] = (vertex8[2] + vertex12[2] + vertex13[2] + vertex4[2] + vertex5[2] - 5 * vertex13[2]) / (-5);
  size = sqrt(normal13[0]*normal13[0] + normal13[1]*normal13[1] + normal13[2]*normal13[2]);
  normal13[0] = normal13[0] / size;
  normal13[1] = normal13[1] / size;
  normal13[2] = normal13[2] / size;

  //normal14
  normal14[0] = (vertex8[0] + vertex13[0] + vertex14[0] + vertex5[0] + vertex6[0] - 5 * vertex14[0]) / (-5);
  normal14[1] = (vertex8[1] + vertex13[1] + vertex14[1] + vertex5[1] + vertex6[1] - 5 * vertex14[1]) / (-5);
  normal14[2] = (vertex8[2] + vertex13[2] + vertex14[2] + vertex5[2] + vertex6[2] - 5 * vertex14[2]) / (-5);
  size = sqrt(normal14[0]*normal14[0] + normal14[1]*normal14[1] + normal14[2]*normal14[2]);
  normal14[0] = normal14[0] / size;
  normal14[1] = normal14[1] / size;
  normal14[2] = normal14[2] / size;

  //normal15
  normal15[0] = (vertex8[0] + vertex9[0] + vertex14[0] + vertex6[0] + vertex7[0] - 5 * vertex15[0]) / (-5);
  normal15[1] = (vertex8[1] + vertex9[1] + vertex14[1] + vertex6[1] + vertex7[1] - 5 * vertex15[1]) / (-5);
  normal15[2] = (vertex8[2] + vertex9[2] + vertex14[2] + vertex6[2] + vertex7[2] - 5 * vertex15[2]) / (-5);
  size = sqrt(normal15[0]*normal15[0] + normal15[1]*normal15[1] + normal15[2]*normal15[2]);
  normal15[0] = normal15[0] / size;
  normal15[1] = normal15[1] / size;
  normal15[2] = normal15[2] / size;

  //Vertexs of the left lower wing
  //Back vertexes
  frontBody->position(vertex0[0], vertex0[1], vertex0[2]);  //0
  frontBody->position(vertex1[0], vertex1[1], vertex1[2]);  //1
  frontBody->position(vertex2[0], vertex2[1], vertex2[2]);  //2
  frontBody->position(vertex3[0], vertex3[1], vertex3[2]);  //3
  frontBody->position(vertex4[0], vertex4[1], vertex4[2]);  //4
  frontBody->position(vertex5[0], vertex5[1], vertex5[2]);  //5
  frontBody->position(vertex6[0], vertex6[1], vertex6[2]);  //6
  frontBody->position(vertex7[0], vertex7[1], vertex7[2]);  //7
  //Front vertexes
  frontBody->position(vertex8[0], vertex8[1], vertex8[2]);     //8
  frontBody->position(vertex9[0], vertex9[1], vertex9[2]);     //9
  frontBody->position(vertex10[0], vertex10[1], vertex10[2]);  //10
  frontBody->position(vertex11[0], vertex11[1], vertex11[2]);  //11
  frontBody->position(vertex12[0], vertex12[1], vertex12[2]);  //12
  frontBody->position(vertex13[0], vertex13[1], vertex13[2]);  //13
  frontBody->position(vertex14[0], vertex14[1], vertex14[2]);  //14
  frontBody->position(vertex15[0], vertex15[1], vertex15[2]);  //15

  //Normal of the vertexes
  //Back normals
  frontBody->normal(normal0[0], normal0[1], normal0[2]);
  frontBody->normal(normal1[0], normal1[1], normal1[2]);
  frontBody->normal(normal2[0], normal2[1], normal2[2]);
  frontBody->normal(normal3[0], normal3[1], normal3[2]);
  frontBody->normal(normal4[0], normal4[1], normal4[2]);
  frontBody->normal(normal5[0], normal5[1], normal5[2]);
  frontBody->normal(normal6[0], normal6[1], normal6[2]);
  frontBody->normal(normal7[0], normal7[1], normal7[2]);
  //Front normals
  frontBody->normal(normal8[0], normal8[1], normal8[2]);
  frontBody->normal(normal9[0], normal9[1], normal9[2]);
  frontBody->normal(normal10[0], normal10[1], normal10[2]);
  frontBody->normal(normal11[0], normal11[1], normal11[2]);
  frontBody->normal(normal12[0], normal12[1], normal12[2]);
  frontBody->normal(normal13[0], normal13[1], normal13[2]);
  frontBody->normal(normal14[0], normal14[1], normal14[2]);
  frontBody->normal(normal15[0], normal15[1], normal15[2]);

  //Creating the triangles
  //BackFace
  frontBody->index(0);
  frontBody->index(2);
  frontBody->index(1);
  frontBody->index(0);
  frontBody->index(3);
  frontBody->index(2);
  frontBody->index(0);
  frontBody->index(4);
  frontBody->index(3);
  frontBody->index(0);
  frontBody->index(5);
  frontBody->index(4);
  frontBody->index(0);
  frontBody->index(6);
  frontBody->index(5);
  frontBody->index(0);
  frontBody->index(7);
  frontBody->index(6);
  frontBody->index(0);
  frontBody->index(1);
  frontBody->index(7);
  //FrontFace
  frontBody->index(8);
  frontBody->index(9);
  frontBody->index(10);
  frontBody->index(8);
  frontBody->index(10);
  frontBody->index(11);
  frontBody->index(8);
  frontBody->index(11);
  frontBody->index(12);
  frontBody->index(8);
  frontBody->index(12);
  frontBody->index(13);
  frontBody->index(8);
  frontBody->index(13);
  frontBody->index(14);
  frontBody->index(8);
  frontBody->index(14);
  frontBody->index(15);
  frontBody->index(8);
  frontBody->index(15);
  frontBody->index(9);
  //1
  frontBody->index(1);
  frontBody->index(10);
  frontBody->index(9);
  frontBody->index(1);
  frontBody->index(2);
  frontBody->index(10);
  //2
  frontBody->index(2);
  frontBody->index(11);
  frontBody->index(10);
  frontBody->index(2);
  frontBody->index(3);
  frontBody->index(11);
  //3
  frontBody->index(3);
  frontBody->index(12);
  frontBody->index(11);
  frontBody->index(3);
  frontBody->index(4);
  frontBody->index(12);
  //4
  frontBody->index(4);
  frontBody->index(13);
  frontBody->index(12);
  frontBody->index(4);
  frontBody->index(5);
  frontBody->index(13);
  //5
  frontBody->index(7);
  frontBody->index(9);
  frontBody->index(15);
  frontBody->index(7);
  frontBody->index(1);
  frontBody->index(9);
  //6
  frontBody->index(6);
  frontBody->index(15);
  frontBody->index(14);
  frontBody->index(6);
  frontBody->index(7);
  frontBody->index(15);
  //7 
  frontBody->index(5);
  frontBody->index(14);
  frontBody->index(13);
  frontBody->index(5);
  frontBody->index(6);
  frontBody->index(14);
   
  frontBody->end();
  frontBodyNode->attachObject(frontBody);
}

//Cabin Manual Object
void Xwing::initCabin(Ogre::SceneManager* _sceneManager){
  /*cabinNode = _sceneManager->createSceneNode();
  main->addChild(cabinNode);
  cabin = _sceneManager->createManualObject("cabin");
  cabinNode->attachObject(cabin);*/
}

//Wings
void Xwing::initLeftUpperWing(Ogre::SceneManager* _sceneManager){
  float vertex0[3], vertex1[3], vertex2[3], vertex3[3], vertex4[3], vertex5[3], vertex6[3], vertex7[3];
  float normal0[3], normal1[3], normal2[3], normal3[3], normal4[3], normal5[3], normal6[3], normal7[3];
  float size;

  leftUpperWingNode = _sceneManager->createSceneNode();
  leftUpperNode->addChild(leftUpperWingNode);
  leftUpperWing = _sceneManager->createManualObject("leftUpperWing");
  leftUpperWing->begin("BaseWhiteNoLighting", Ogre::RenderOperation::OT_TRIANGLE_LIST);
  //Position of the vertexes
  vertex0[0] = 0.0;  //0
  vertex0[1] = 0.0;
  vertex0[2] = 0.0;
  vertex1[0] = 0.0;  //1
  vertex1[1] = 0.0;
  vertex1[2] = -6.0;
  vertex2[0] = 0.0;  //2
  vertex2[1] = 0.4;
  vertex2[2] = 0.0;
  vertex3[0] = 0.0;  //3
  vertex3[1] = 0.4;
  vertex3[2] = -6.0;
  vertex4[0] = -8.7;  //4
  vertex4[1] = 0.0;
  vertex4[2] = -2.0;
  vertex5[0] = -8.7;  //5
  vertex5[1] = 0.0;
  vertex5[2] = -6.0;
  vertex6[0] = -8.7;  //6
  vertex6[1] = 0.4;
  vertex6[2] = -2.0;
  vertex7[0] = -8.7;  //7
  vertex7[1] = 0.4;
  vertex7[2] = -6.0;

  //Calculating the normal for each vertex
  //normal0
  normal0[0] = (vertex1[0] + vertex2[0] + vertex3[0] - 3 * vertex0[0]) / (-3);
  normal0[1] = (vertex1[1] + vertex2[1] + vertex3[1] - 3 * vertex0[1]) / (-3);
  normal0[2] = (vertex1[2] + vertex2[2] + vertex3[2] - 3 * vertex0[2]) / (-3);
  size = sqrt(normal0[0]*normal0[0] + normal0[1]*normal0[1] + normal0[2]*normal0[2]);
  normal0[0] = normal0[0] / size;
  normal0[1] = normal0[1] / size;
  normal0[2] = normal0[2] / size;

  //normal1
  normal1[0] = (vertex0[0] + vertex2[0] + vertex3[0] + vertex4[0] + vertex5[0] - 5 * vertex1[0]) / (-5);
  normal1[1] = (vertex0[1] + vertex2[1] + vertex3[1] + vertex4[1] + vertex5[1] - 5 * vertex1[1]) / (-5);
  normal1[2] = (vertex0[2] + vertex2[2] + vertex3[2] + vertex4[2] + vertex5[2] - 5 * vertex1[2]) / (-5);
  size = sqrt(normal1[0]*normal1[0] + normal1[1]*normal1[1] + normal1[2]*normal1[2]);
  normal1[0] = normal1[0] / size;
  normal1[1] = normal1[1] / size;
  normal1[2] = normal1[2] / size;

  //normal2
  normal2[0] = (vertex0[0] + vertex1[0] + vertex3[0] + vertex4[0] + vertex6[0] - 5 * vertex2[0]) / (-5);
  normal2[1] = (vertex0[1] + vertex1[1] + vertex3[1] + vertex4[1] + vertex6[1] - 5 * vertex2[1]) / (-5);
  normal2[2] = (vertex0[2] + vertex1[2] + vertex3[2] + vertex4[2] + vertex6[2] - 5 * vertex2[2]) / (-5);
  size = sqrt(normal2[0]*normal2[0] + normal2[1]*normal2[1] + normal2[2]*normal2[2]);
  normal2[0] = normal2[0] / size;
  normal2[1] = normal2[1] / size;
  normal2[2] = normal2[2] / size;

  //normal3
  normal3[0] = (vertex1[0] + vertex2[0] + vertex5[0] + vertex6[0] + vertex7[0] - 5 * vertex3[0]) / (-5);
  normal3[1] = (vertex1[1] + vertex2[1] + vertex5[1] + vertex6[1] + vertex7[1] - 5 * vertex3[1]) / (-5);
  normal3[2] = (vertex1[2] + vertex2[2] + vertex5[2] + vertex6[2] + vertex7[2] - 5 * vertex3[2]) / (-5);
  size = sqrt(normal3[0]*normal3[0] + normal3[1]*normal3[1] + normal3[2]*normal3[2]);
  normal3[0] = normal3[0] / size;
  normal3[1] = normal3[1] / size;
  normal3[2] = normal3[2] / size;

  //normal4
  normal4[0] = (vertex0[0] + vertex1[0] + vertex2[0] + vertex5[0] + vertex6[0] - 5 * vertex4[0]) / (-5);
  normal4[1] = (vertex0[1] + vertex1[1] + vertex2[1] + vertex5[1] + vertex6[1] - 5 * vertex4[1]) / (-5);
  normal4[2] = (vertex0[2] + vertex1[2] + vertex2[2] + vertex5[2] + vertex6[2] - 5 * vertex4[2]) / (-5);
  size = sqrt(normal4[0]*normal4[0] + normal4[1]*normal4[1] + normal4[2]*normal4[2]);
  normal4[0] = normal4[0] / size;
  normal4[1] = normal4[1] / size;
  normal4[2] = normal4[2] / size;

  //normal5
  normal5[0] = (vertex1[0] + vertex3[0] + vertex4[0] + vertex6[0] + vertex7[0] - 5 * vertex5[0]) / (-5);
  normal5[1] = (vertex1[1] + vertex3[1] + vertex4[1] + vertex6[1] + vertex7[1] - 5 * vertex5[1]) / (-5);
  normal5[2] = (vertex1[2] + vertex3[2] + vertex4[2] + vertex6[2] + vertex7[2] - 5 * vertex5[2]) / (-5);
  size = sqrt(normal5[0]*normal5[0] + normal5[1]*normal5[1] + normal5[2]*normal5[2]);
  normal5[0] = normal5[0] / size;
  normal5[1] = normal5[1] / size;
  normal5[2] = normal5[2] / size;

  //normal6
  normal6[0] = (vertex2[0] + vertex3[0] + vertex4[0] + vertex5[0] + vertex7[0] - 5 * vertex6[0]) / (-5);
  normal6[1] = (vertex2[1] + vertex3[1] + vertex4[1] + vertex5[1] + vertex7[1] - 5 * vertex6[1]) / (-5);
  normal6[2] = (vertex2[2] + vertex3[2] + vertex4[2] + vertex5[2] + vertex7[2] - 5 * vertex6[2]) / (-5);
  size = sqrt(normal6[0]*normal6[0] + normal6[1]*normal6[1] + normal6[2]*normal6[2]);
  normal6[0] = normal6[0] / size;
  normal6[1] = normal6[1] / size;
  normal6[2] = normal6[2] / size;

  //normal7
  normal7[0] = (vertex3[0] + vertex5[0] + vertex6[0] - 3 * vertex7[0]) / (-3);
  normal7[1] = (vertex3[1] + vertex5[1] + vertex6[1] - 3 * vertex7[1]) / (-3);
  normal7[2] = (vertex3[2] + vertex5[2] + vertex6[2] - 3 * vertex7[2]) / (-3);
  size = sqrt(normal7[0]*normal7[0] + normal7[1]*normal7[1] + normal7[2]*normal7[2]);
  normal7[0] = normal7[0] / size;
  normal7[1] = normal7[1] / size;
  normal7[2] = normal7[2] / size;

  //Vertexs of the left upper wing
  //Right vertexes
  leftUpperWing->position(vertex0[0], vertex0[1], vertex0[2]);  //0
  leftUpperWing->position(vertex1[0], vertex1[1], vertex1[2]);  //1
  leftUpperWing->position(vertex2[0], vertex2[1], vertex2[2]);  //2
  leftUpperWing->position(vertex3[0], vertex3[1], vertex3[2]);  //3
  //Left vertexes
  leftUpperWing->position(vertex4[0], vertex4[1], vertex4[2]);  //4
  leftUpperWing->position(vertex5[0], vertex5[1], vertex5[2]);  //5
  leftUpperWing->position(vertex6[0], vertex6[1], vertex6[2]);  //6
  leftUpperWing->position(vertex7[0], vertex7[1], vertex7[2]);  //7

  //Normal of the vertexes
  //Right vertexes
  leftUpperWing->normal(normal0[0], normal0[1], normal0[2]);
  leftUpperWing->normal(normal1[0], normal1[1], normal1[2]);
  leftUpperWing->normal(normal2[0], normal2[1], normal2[2]);
  leftUpperWing->normal(normal3[0], normal3[1], normal3[2]);
  //Left vertexes
  leftUpperWing->normal(normal4[0], normal4[1], normal4[2]);
  leftUpperWing->normal(normal5[0], normal5[1], normal5[2]);
  leftUpperWing->normal(normal6[0], normal6[1], normal6[2]);
  leftUpperWing->normal(normal7[0], normal7[1], normal7[2]);

  //Creating the triangles
  //UpperFace
  leftUpperWing->index(6);
  leftUpperWing->index(2);
  leftUpperWing->index(3);
  leftUpperWing->index(6);
  leftUpperWing->index(3);
  leftUpperWing->index(7);
  //DownFace
  leftUpperWing->index(4);
  leftUpperWing->index(1);
  leftUpperWing->index(0);
  leftUpperWing->index(4);
  leftUpperWing->index(5);
  leftUpperWing->index(1);
  //LeftFace
  leftUpperWing->index(6);
  leftUpperWing->index(7);
  leftUpperWing->index(5);
  leftUpperWing->index(6);
  leftUpperWing->index(5);
  leftUpperWing->index(4);
  //RightFace
  leftUpperWing->index(3);
  leftUpperWing->index(2);
  leftUpperWing->index(1);
  leftUpperWing->index(0);
  leftUpperWing->index(1);
  leftUpperWing->index(2);
  //BackFace
  leftUpperWing->index(0);
  leftUpperWing->index(2);
  leftUpperWing->index(4);
  leftUpperWing->index(4);
  leftUpperWing->index(2);
  leftUpperWing->index(6);
  //FrontFace
  leftUpperWing->index(5);
  leftUpperWing->index(7);
  leftUpperWing->index(3);
  leftUpperWing->index(5);
  leftUpperWing->index(3);
  leftUpperWing->index(1);
   
  leftUpperWing->end();
  leftUpperWingNode->attachObject(leftUpperWing);
}

void Xwing::initLeftLowerWing(Ogre::SceneManager* _sceneManager){
  leftLowerWingNode = _sceneManager->createSceneNode();
  leftLowerNode->addChild(leftLowerWingNode);
  leftLowerWing = _sceneManager->createManualObject("leftLowerWing");

  float vertex0[3], vertex1[3], vertex2[3], vertex3[3], vertex4[3], vertex5[3], vertex6[3], vertex7[3];
  float normal0[3], normal1[3], normal2[3], normal3[3], normal4[3], normal5[3], normal6[3], normal7[3];
  float size;
  leftLowerWing->begin("BaseWhiteNoLighting", Ogre::RenderOperation::OT_TRIANGLE_LIST);

  //Position of the vertexes
  vertex0[0] = -2.8;  //0
  vertex0[1] = -0.5;
  vertex0[2] = 0.0;
  vertex1[0] = -2.8;  //1
  vertex1[1] = -0.5;
  vertex1[2] = -6.0;
  vertex2[0] = -2.8;  //2
  vertex2[1] = -0.1;
  vertex2[2] = 0.0;
  vertex3[0] = -2.8;  //3
  vertex3[1] = -0.1;
  vertex3[2] = -6.0;
  vertex4[0] = -11.5; //4
  vertex4[1] = -0.5;
  vertex4[2] = -2.0;
  vertex5[0] = -11.5; //5
  vertex5[1] = -0.5;
  vertex5[2] = -6.0;
  vertex6[0] = -11.5; //6
  vertex6[1] = -0.1;
  vertex6[2] = -2.0;
  vertex7[0] = -11.5; //7
  vertex7[1] = -0.1;
  vertex7[2] = -6.0;

  //Calculating the normal for each vertex
  //normal0
  normal0[0] = (vertex1[0] + vertex2[0] + vertex3[0] - 3 * vertex0[0]) / (-3);
  normal0[1] = (vertex1[1] + vertex2[1] + vertex3[1] - 3 * vertex0[1]) / (-3);
  normal0[2] = (vertex1[2] + vertex2[2] + vertex3[2] - 3 * vertex0[2]) / (-3);
  size = sqrt(normal0[0]*normal0[0] + normal0[1]*normal0[1] + normal0[2]*normal0[2]);
  normal0[0] = normal0[0] / size;
  normal0[1] = normal0[1] / size;
  normal0[2] = normal0[2] / size;

  //normal1
  normal1[0] = (vertex0[0] + vertex2[0] + vertex3[0] + vertex4[0] + vertex5[0] - 5 * vertex1[0]) / (-5);
  normal1[1] = (vertex0[1] + vertex2[1] + vertex3[1] + vertex4[1] + vertex5[1] - 5 * vertex1[1]) / (-5);
  normal1[2] = (vertex0[2] + vertex2[2] + vertex3[2] + vertex4[2] + vertex5[2] - 5 * vertex1[2]) / (-5);
  size = sqrt(normal1[0]*normal1[0] + normal1[1]*normal1[1] + normal1[2]*normal1[2]);
  normal1[0] = normal1[0] / size;
  normal1[1] = normal1[1] / size;
  normal1[2] = normal1[2] / size;

  //normal2
  normal2[0] = (vertex0[0] + vertex1[0] + vertex3[0] + vertex4[0] + vertex6[0] - 5 * vertex2[0]) / (-5);
  normal2[1] = (vertex0[1] + vertex1[1] + vertex3[1] + vertex4[1] + vertex6[1] - 5 * vertex2[1]) / (-5);
  normal2[2] = (vertex0[2] + vertex1[2] + vertex3[2] + vertex4[2] + vertex6[2] - 5 * vertex2[2]) / (-5);
  size = sqrt(normal2[0]*normal2[0] + normal2[1]*normal2[1] + normal2[2]*normal2[2]);
  normal2[0] = normal2[0] / size;
  normal2[1] = normal2[1] / size;
  normal2[2] = normal2[2] / size;

  //normal3
  normal3[0] = (vertex1[0] + vertex2[0] + vertex5[0] + vertex6[0] + vertex7[0] - 5 * vertex3[0]) / (-5);
  normal3[1] = (vertex1[1] + vertex2[1] + vertex5[1] + vertex6[1] + vertex7[1] - 5 * vertex3[1]) / (-5);
  normal3[2] = (vertex1[2] + vertex2[2] + vertex5[2] + vertex6[2] + vertex7[2] - 5 * vertex3[2]) / (-5);
  size = sqrt(normal3[0]*normal3[0] + normal3[1]*normal3[1] + normal3[2]*normal3[2]);
  normal3[0] = normal3[0] / size;
  normal3[1] = normal3[1] / size;
  normal3[2] = normal3[2] / size;

  //normal4
  normal4[0] = (vertex0[0] + vertex1[0] + vertex2[0] + vertex5[0] + vertex6[0] - 5 * vertex4[0]) / (-5);
  normal4[1] = (vertex0[1] + vertex1[1] + vertex2[1] + vertex5[1] + vertex6[1] - 5 * vertex4[1]) / (-5);
  normal4[2] = (vertex0[2] + vertex1[2] + vertex2[2] + vertex5[2] + vertex6[2] - 5 * vertex4[2]) / (-5);
  size = sqrt(normal4[0]*normal4[0] + normal4[1]*normal4[1] + normal4[2]*normal4[2]);
  normal4[0] = normal4[0] / size;
  normal4[1] = normal4[1] / size;
  normal4[2] = normal4[2] / size;

  //normal5
  normal5[0] = (vertex1[0] + vertex3[0] + vertex4[0] + vertex6[0] + vertex7[0] - 5 * vertex5[0]) / (-5);
  normal5[1] = (vertex1[1] + vertex3[1] + vertex4[1] + vertex6[1] + vertex7[1] - 5 * vertex5[1]) / (-5);
  normal5[2] = (vertex1[2] + vertex3[2] + vertex4[2] + vertex6[2] + vertex7[2] - 5 * vertex5[2]) / (-5);
  size = sqrt(normal5[0]*normal5[0] + normal5[1]*normal5[1] + normal5[2]*normal5[2]);
  normal5[0] = normal5[0] / size;
  normal5[1] = normal5[1] / size;
  normal5[2] = normal5[2] / size;

  //normal6
  normal6[0] = (vertex2[0] + vertex3[0] + vertex4[0] + vertex5[0] + vertex7[0] - 5 * vertex6[0]) / (-5);
  normal6[1] = (vertex2[1] + vertex3[1] + vertex4[1] + vertex5[1] + vertex7[1] - 5 * vertex6[1]) / (-5);
  normal6[2] = (vertex2[2] + vertex3[2] + vertex4[2] + vertex5[2] + vertex7[2] - 5 * vertex6[2]) / (-5);
  size = sqrt(normal6[0]*normal6[0] + normal6[1]*normal6[1] + normal6[2]*normal6[2]);
  normal6[0] = normal6[0] / size;
  normal6[1] = normal6[1] / size;
  normal6[2] = normal6[2] / size;

  //normal7
  normal7[0] = (vertex3[0] + vertex5[0] + vertex6[0] - 3 * vertex7[0]) / (-3);
  normal7[1] = (vertex3[1] + vertex5[1] + vertex6[1] - 3 * vertex7[1]) / (-3);
  normal7[2] = (vertex3[2] + vertex5[2] + vertex6[2] - 3 * vertex7[2]) / (-3);
  size = sqrt(normal7[0]*normal7[0] + normal7[1]*normal7[1] + normal7[2]*normal7[2]);
  normal7[0] = normal7[0] / size;
  normal7[1] = normal7[1] / size;
  normal7[2] = normal7[2] / size;

  //Vertexs of the left lower wing
  //Left vertexes
  leftLowerWing->position(vertex0[0], vertex0[1], vertex0[2]);  //0
  leftLowerWing->position(vertex1[0], vertex1[1], vertex1[2]);  //1
  leftLowerWing->position(vertex2[0], vertex2[1], vertex2[2]);  //2
  leftLowerWing->position(vertex3[0], vertex3[1], vertex3[2]);  //3
  //Right vertexes
  leftLowerWing->position(vertex4[0], vertex4[1], vertex4[2]);  //4
  leftLowerWing->position(vertex5[0], vertex5[1], vertex5[2]);  //5
  leftLowerWing->position(vertex6[0], vertex6[1], vertex6[2]);  //6
  leftLowerWing->position(vertex7[0], vertex7[1], vertex7[2]);  //7

  //Normal of the vertexes
  //Left vertexes
  leftLowerWing->normal(normal0[0], normal0[1], normal0[2]);
  leftLowerWing->normal(normal1[0], normal1[1], normal1[2]);
  leftLowerWing->normal(normal2[0], normal2[1], normal2[2]);
  leftLowerWing->normal(normal3[0], normal3[1], normal3[2]);
  //Right vertexes
  leftLowerWing->normal(normal4[0], normal4[1], normal4[2]);
  leftLowerWing->normal(normal5[0], normal5[1], normal5[2]);
  leftLowerWing->normal(normal6[0], normal6[1], normal6[2]);
  leftLowerWing->normal(normal7[0], normal7[1], normal7[2]);

  //Creating the triangles
  //UpperFace
  leftLowerWing->index(6);
  leftLowerWing->index(2);
  leftLowerWing->index(3);
  leftLowerWing->index(6);
  leftLowerWing->index(3);
  leftLowerWing->index(7);
  //LowerFace
  leftLowerWing->index(4);
  leftLowerWing->index(1);
  leftLowerWing->index(0);
  leftLowerWing->index(4);
  leftLowerWing->index(5);
  leftLowerWing->index(1);
  //LeftFace
  leftLowerWing->index(6);
  leftLowerWing->index(7);
  leftLowerWing->index(5);
  leftLowerWing->index(6);
  leftLowerWing->index(5);
  leftLowerWing->index(4);
  //RightFace
  leftLowerWing->index(3);
  leftLowerWing->index(2);
  leftLowerWing->index(1);
  leftLowerWing->index(0);
  leftLowerWing->index(1);
  leftLowerWing->index(2);
  //BackFace
  leftLowerWing->index(0);
  leftLowerWing->index(2);
  leftLowerWing->index(4);
  leftLowerWing->index(4);
  leftLowerWing->index(2);
  leftLowerWing->index(6);
  //FrontFace
  leftLowerWing->index(5);
  leftLowerWing->index(7);
  leftLowerWing->index(3);
  leftLowerWing->index(5);
  leftLowerWing->index(3);
  leftLowerWing->index(1);
   
  leftLowerWing->end();
  leftLowerWingNode->attachObject(leftLowerWing);
}

void Xwing::initRightUpperWing(Ogre::SceneManager* _sceneManager){
  float vertex0[3], vertex1[3], vertex2[3], vertex3[3], vertex4[3], vertex5[3], vertex6[3], vertex7[3];
  float normal0[3], normal1[3], normal2[3], normal3[3], normal4[3], normal5[3], normal6[3], normal7[3];
  float size;

  rightUpperWingNode = _sceneManager->createSceneNode();
  rightUpperNode->addChild(rightUpperWingNode);
  rightUpperWing = _sceneManager->createManualObject("rightUpperWing");
  rightUpperWing->begin("BaseWhiteNoLighting", Ogre::RenderOperation::OT_TRIANGLE_LIST);
  
  //Position of the vertexes
  vertex0[0] = 11.5;  //0
  vertex0[1] = 0.1;
  vertex0[2] = -2.0;
  vertex1[0] = 11.5;  //1
  vertex1[1] = 0.1;
  vertex1[2] = -6.0;
  vertex2[0] = 11.5;  //2
  vertex2[1] = 0.5;
  vertex2[2] = -2.0;
  vertex3[0] = 11.5;  //3
  vertex3[1] = 0.5;
  vertex3[2] = -6.0;
  vertex4[0] = 2.8;  //4
  vertex4[1] = 0.1;
  vertex4[2] = 0.0;
  vertex5[0] = 2.8;  //5
  vertex5[1] = 0.1;
  vertex5[2] = -6.0;
  vertex6[0] = 2.8;  //6
  vertex6[1] = 0.5;
  vertex6[2] = 0.0;
  vertex7[0] = 2.8;  //7
  vertex7[1] = 0.5;
  vertex7[2] = -6.0;

  //Calculating the normal for each vertex
  //normal0
  normal0[0] = (vertex1[0] + vertex2[0] + vertex3[0] - 3 * vertex0[0]) / (-3);
  normal0[1] = (vertex1[1] + vertex2[1] + vertex3[1] - 3 * vertex0[1]) / (-3);
  normal0[2] = (vertex1[2] + vertex2[2] + vertex3[2] - 3 * vertex0[2]) / (-3);
  size = sqrt(normal0[0]*normal0[0] + normal0[1]*normal0[1] + normal0[2]*normal0[2]);
  normal0[0] = normal0[0] / size;
  normal0[1] = normal0[1] / size;
  normal0[2] = normal0[2] / size;

  //normal1
  normal1[0] = (vertex0[0] + vertex2[0] + vertex3[0] + vertex4[0] + vertex5[0] - 5 * vertex1[0]) / (-5);
  normal1[1] = (vertex0[1] + vertex2[1] + vertex3[1] + vertex4[1] + vertex5[1] - 5 * vertex1[1]) / (-5);
  normal1[2] = (vertex0[2] + vertex2[2] + vertex3[2] + vertex4[2] + vertex5[2] - 5 * vertex1[2]) / (-5);
  size = sqrt(normal1[0]*normal1[0] + normal1[1]*normal1[1] + normal1[2]*normal1[2]);
  normal1[0] = normal1[0] / size;
  normal1[1] = normal1[1] / size;
  normal1[2] = normal1[2] / size;

  //normal2
  normal2[0] = (vertex0[0] + vertex1[0] + vertex3[0] + vertex4[0] + vertex6[0] - 5 * vertex2[0]) / (-5);
  normal2[1] = (vertex0[1] + vertex1[1] + vertex3[1] + vertex4[1] + vertex6[1] - 5 * vertex2[1]) / (-5);
  normal2[2] = (vertex0[2] + vertex1[2] + vertex3[2] + vertex4[2] + vertex6[2] - 5 * vertex2[2]) / (-5);
  size = sqrt(normal2[0]*normal2[0] + normal2[1]*normal2[1] + normal2[2]*normal2[2]);
  normal2[0] = normal2[0] / size;
  normal2[1] = normal2[1] / size;
  normal2[2] = normal2[2] / size;

  //normal3
  normal3[0] = (vertex1[0] + vertex2[0] + vertex5[0] + vertex6[0] + vertex7[0] - 5 * vertex3[0]) / (-5);
  normal3[1] = (vertex1[1] + vertex2[1] + vertex5[1] + vertex6[1] + vertex7[1] - 5 * vertex3[1]) / (-5);
  normal3[2] = (vertex1[2] + vertex2[2] + vertex5[2] + vertex6[2] + vertex7[2] - 5 * vertex3[2]) / (-5);
  size = sqrt(normal3[0]*normal3[0] + normal3[1]*normal3[1] + normal3[2]*normal3[2]);
  normal3[0] = normal3[0] / size;
  normal3[1] = normal3[1] / size;
  normal3[2] = normal3[2] / size;

  //normal4
  normal4[0] = (vertex0[0] + vertex1[0] + vertex2[0] + vertex5[0] + vertex6[0] - 5 * vertex4[0]) / (-5);
  normal4[1] = (vertex0[1] + vertex1[1] + vertex2[1] + vertex5[1] + vertex6[1] - 5 * vertex4[1]) / (-5);
  normal4[2] = (vertex0[2] + vertex1[2] + vertex2[2] + vertex5[2] + vertex6[2] - 5 * vertex4[2]) / (-5);
  size = sqrt(normal4[0]*normal4[0] + normal4[1]*normal4[1] + normal4[2]*normal4[2]);
  normal4[0] = normal4[0] / size;
  normal4[1] = normal4[1] / size;
  normal4[2] = normal4[2] / size;

  //normal5
  normal5[0] = (vertex1[0] + vertex3[0] + vertex4[0] + vertex6[0] + vertex7[0] - 5 * vertex5[0]) / (-5);
  normal5[1] = (vertex1[1] + vertex3[1] + vertex4[1] + vertex6[1] + vertex7[1] - 5 * vertex5[1]) / (-5);
  normal5[2] = (vertex1[2] + vertex3[2] + vertex4[2] + vertex6[2] + vertex7[2] - 5 * vertex5[2]) / (-5);
  size = sqrt(normal5[0]*normal5[0] + normal5[1]*normal5[1] + normal5[2]*normal5[2]);
  normal5[0] = normal5[0] / size;
  normal5[1] = normal5[1] / size;
  normal5[2] = normal5[2] / size;

  //normal6
  normal6[0] = (vertex2[0] + vertex3[0] + vertex4[0] + vertex5[0] + vertex7[0] - 5 * vertex6[0]) / (-5);
  normal6[1] = (vertex2[1] + vertex3[1] + vertex4[1] + vertex5[1] + vertex7[1] - 5 * vertex6[1]) / (-5);
  normal6[2] = (vertex2[2] + vertex3[2] + vertex4[2] + vertex5[2] + vertex7[2] - 5 * vertex6[2]) / (-5);
  size = sqrt(normal6[0]*normal6[0] + normal6[1]*normal6[1] + normal6[2]*normal6[2]);
  normal6[0] = normal6[0] / size;
  normal6[1] = normal6[1] / size;
  normal6[2] = normal6[2] / size;

  //normal7
  normal7[0] = (vertex3[0] + vertex5[0] + vertex6[0] - 3 * vertex7[0]) / (-3);
  normal7[1] = (vertex3[1] + vertex5[1] + vertex6[1] - 3 * vertex7[1]) / (-3);
  normal7[2] = (vertex3[2] + vertex5[2] + vertex6[2] - 3 * vertex7[2]) / (-3);
  size = sqrt(normal7[0]*normal7[0] + normal7[1]*normal7[1] + normal7[2]*normal7[2]);
  normal7[0] = normal7[0] / size;
  normal7[1] = normal7[1] / size;
  normal7[2] = normal7[2] / size;

  //Vertexs of the right upper wing
  //Left vertexes
  rightUpperWing->position(vertex0[0], vertex0[1], vertex0[2]);  //0
  rightUpperWing->position(vertex1[0], vertex1[1], vertex1[2]);  //1
  rightUpperWing->position(vertex2[0], vertex2[1], vertex2[2]);  //2
  rightUpperWing->position(vertex3[0], vertex3[1], vertex3[2]);  //3
  //Right vertexes
  rightUpperWing->position(vertex4[0], vertex4[1], vertex4[2]);  //4
  rightUpperWing->position(vertex5[0], vertex5[1], vertex5[2]);  //5
  rightUpperWing->position(vertex6[0], vertex6[1], vertex6[2]);  //6
  rightUpperWing->position(vertex7[0], vertex7[1], vertex7[2]);  //7

  //Normal of the vertexes
  //Left vertexes
  rightUpperWing->normal(normal0[0], normal0[1], normal0[2]);
  rightUpperWing->normal(normal1[0], normal1[1], normal1[2]);
  rightUpperWing->normal(normal2[0], normal2[1], normal2[2]);
  rightUpperWing->normal(normal3[0], normal3[1], normal3[2]);
  //Right vertexes
  rightUpperWing->normal(normal4[0], normal4[1], normal4[2]);
  rightUpperWing->normal(normal5[0], normal5[1], normal5[2]);
  rightUpperWing->normal(normal6[0], normal6[1], normal6[2]);
  rightUpperWing->normal(normal7[0], normal7[1], normal7[2]);

  //Creating the triangles
  //UpperFace
  rightUpperWing->index(6);
  rightUpperWing->index(2);
  rightUpperWing->index(3);
  rightUpperWing->index(6);
  rightUpperWing->index(3);
  rightUpperWing->index(7);
  //DownFace
  rightUpperWing->index(4);
  rightUpperWing->index(1);
  rightUpperWing->index(0);
  rightUpperWing->index(4);
  rightUpperWing->index(5);
  rightUpperWing->index(1);
  //LeftFace
  rightUpperWing->index(6);
  rightUpperWing->index(7);
  rightUpperWing->index(5);
  rightUpperWing->index(6);
  rightUpperWing->index(5);
  rightUpperWing->index(4);
  //RightFace
  rightUpperWing->index(3);
  rightUpperWing->index(2);
  rightUpperWing->index(1);
  rightUpperWing->index(0);
  rightUpperWing->index(1);
  rightUpperWing->index(2);
  //BackFace
  rightUpperWing->index(0);
  rightUpperWing->index(2);
  rightUpperWing->index(4);
  rightUpperWing->index(4);
  rightUpperWing->index(2);
  rightUpperWing->index(6);
  //FrontFace
  rightUpperWing->index(5);
  rightUpperWing->index(7);
  rightUpperWing->index(3);
  rightUpperWing->index(5);
  rightUpperWing->index(3);
  rightUpperWing->index(1);
   
  rightUpperWing->end();
  rightUpperWingNode->attachObject(rightUpperWing);
}

void Xwing::initRightLowerWing(Ogre::SceneManager* _sceneManager){
  float vertex0[3], vertex1[3], vertex2[3], vertex3[3], vertex4[3], vertex5[3], vertex6[3], vertex7[3];
  float normal0[3], normal1[3], normal2[3], normal3[3], normal4[3], normal5[3], normal6[3], normal7[3];
  float size;

  rightLowerWingNode = _sceneManager->createSceneNode();
  rightLowerNode->addChild(rightLowerWingNode);
  rightLowerWing = _sceneManager->createManualObject("rightLowerWing");
  rightLowerWing->begin("BaseWhiteNoLighting", Ogre::RenderOperation::OT_TRIANGLE_LIST);
  
  //Position of the vertexes
  vertex0[0] = 11.5;  //0
  vertex0[1] = -0.1;
  vertex0[2] = -2.0;
  vertex1[0] = 11.5;  //1
  vertex1[1] = -0.1;
  vertex1[2] = -6.0;
  vertex2[0] = 11.5;  //2
  vertex2[1] = -0.1;
  vertex2[2] = -2.0;
  vertex3[0] = 11.5;  //3
  vertex3[1] = -0.1;
  vertex3[2] = -6.0;
  vertex4[0] = 2.8;  //4
  vertex4[1] = -0.5;
  vertex4[2] = 0.0;
  vertex5[0] = 2.8;  //5
  vertex5[1] = -0.5;
  vertex5[2] = -6.0;
  vertex6[0] = 2.8;  //6
  vertex6[1] = -0.1;
  vertex6[2] = 0.0;
  vertex7[0] = 2.8;  //7
  vertex7[1] = -0.1;
  vertex7[2] = -6.0;

  //Calculating the normal for each vertex
  //normal0
  normal0[0] = (vertex1[0] + vertex2[0] + vertex3[0] - 3 * vertex0[0]) / (-3);
  normal0[1] = (vertex1[1] + vertex2[1] + vertex3[1] - 3 * vertex0[1]) / (-3);
  normal0[2] = (vertex1[2] + vertex2[2] + vertex3[2] - 3 * vertex0[2]) / (-3);
  size = sqrt(normal0[0]*normal0[0] + normal0[1]*normal0[1] + normal0[2]*normal0[2]);
  normal0[0] = normal0[0] / size;
  normal0[1] = normal0[1] / size;
  normal0[2] = normal0[2] / size;

  //normal1
  normal1[0] = (vertex0[0] + vertex2[0] + vertex3[0] + vertex4[0] + vertex5[0] - 5 * vertex1[0]) / (-5);
  normal1[1] = (vertex0[1] + vertex2[1] + vertex3[1] + vertex4[1] + vertex5[1] - 5 * vertex1[1]) / (-5);
  normal1[2] = (vertex0[2] + vertex2[2] + vertex3[2] + vertex4[2] + vertex5[2] - 5 * vertex1[2]) / (-5);
  size = sqrt(normal1[0]*normal1[0] + normal1[1]*normal1[1] + normal1[2]*normal1[2]);
  normal1[0] = normal1[0] / size;
  normal1[1] = normal1[1] / size;
  normal1[2] = normal1[2] / size;

  //normal2
  normal2[0] = (vertex0[0] + vertex1[0] + vertex3[0] + vertex4[0] + vertex6[0] - 5 * vertex2[0]) / (-5);
  normal2[1] = (vertex0[1] + vertex1[1] + vertex3[1] + vertex4[1] + vertex6[1] - 5 * vertex2[1]) / (-5);
  normal2[2] = (vertex0[2] + vertex1[2] + vertex3[2] + vertex4[2] + vertex6[2] - 5 * vertex2[2]) / (-5);
  size = sqrt(normal2[0]*normal2[0] + normal2[1]*normal2[1] + normal2[2]*normal2[2]);
  normal2[0] = normal2[0] / size;
  normal2[1] = normal2[1] / size;
  normal2[2] = normal2[2] / size;

  //normal3
  normal3[0] = (vertex1[0] + vertex2[0] + vertex5[0] + vertex6[0] + vertex7[0] - 5 * vertex3[0]) / (-5);
  normal3[1] = (vertex1[1] + vertex2[1] + vertex5[1] + vertex6[1] + vertex7[1] - 5 * vertex3[1]) / (-5);
  normal3[2] = (vertex1[2] + vertex2[2] + vertex5[2] + vertex6[2] + vertex7[2] - 5 * vertex3[2]) / (-5);
  size = sqrt(normal3[0]*normal3[0] + normal3[1]*normal3[1] + normal3[2]*normal3[2]);
  normal3[0] = normal3[0] / size;
  normal3[1] = normal3[1] / size;
  normal3[2] = normal3[2] / size;

  //normal4
  normal4[0] = (vertex0[0] + vertex1[0] + vertex2[0] + vertex5[0] + vertex6[0] - 5 * vertex4[0]) / (-5);
  normal4[1] = (vertex0[1] + vertex1[1] + vertex2[1] + vertex5[1] + vertex6[1] - 5 * vertex4[1]) / (-5);
  normal4[2] = (vertex0[2] + vertex1[2] + vertex2[2] + vertex5[2] + vertex6[2] - 5 * vertex4[2]) / (-5);
  size = sqrt(normal4[0]*normal4[0] + normal4[1]*normal4[1] + normal4[2]*normal4[2]);
  normal4[0] = normal4[0] / size;
  normal4[1] = normal4[1] / size;
  normal4[2] = normal4[2] / size;

  //normal5
  normal5[0] = (vertex1[0] + vertex3[0] + vertex4[0] + vertex6[0] + vertex7[0] - 5 * vertex5[0]) / (-5);
  normal5[1] = (vertex1[1] + vertex3[1] + vertex4[1] + vertex6[1] + vertex7[1] - 5 * vertex5[1]) / (-5);
  normal5[2] = (vertex1[2] + vertex3[2] + vertex4[2] + vertex6[2] + vertex7[2] - 5 * vertex5[2]) / (-5);
  size = sqrt(normal5[0]*normal5[0] + normal5[1]*normal5[1] + normal5[2]*normal5[2]);
  normal5[0] = normal5[0] / size;
  normal5[1] = normal5[1] / size;
  normal5[2] = normal5[2] / size;

  //normal6
  normal6[0] = (vertex2[0] + vertex3[0] + vertex4[0] + vertex5[0] + vertex7[0] - 5 * vertex6[0]) / (-5);
  normal6[1] = (vertex2[1] + vertex3[1] + vertex4[1] + vertex5[1] + vertex7[1] - 5 * vertex6[1]) / (-5);
  normal6[2] = (vertex2[2] + vertex3[2] + vertex4[2] + vertex5[2] + vertex7[2] - 5 * vertex6[2]) / (-5);
  size = sqrt(normal6[0]*normal6[0] + normal6[1]*normal6[1] + normal6[2]*normal6[2]);
  normal6[0] = normal6[0] / size;
  normal6[1] = normal6[1] / size;
  normal6[2] = normal6[2] / size;

  //normal7
  normal7[0] = (vertex3[0] + vertex5[0] + vertex6[0] - 3 * vertex7[0]) / (-3);
  normal7[1] = (vertex3[1] + vertex5[1] + vertex6[1] - 3 * vertex7[1]) / (-3);
  normal7[2] = (vertex3[2] + vertex5[2] + vertex6[2] - 3 * vertex7[2]) / (-3);
  size = sqrt(normal7[0]*normal7[0] + normal7[1]*normal7[1] + normal7[2]*normal7[2]);
  normal7[0] = normal7[0] / size;
  normal7[1] = normal7[1] / size;
  normal7[2] = normal7[2] / size;

  //Vertexs of the right down wing
  //Left vertexes
  rightLowerWing->position(10.5, -0.5, -2.0);  //0
  rightLowerWing->position(10.5, -0.5, -6.0);  //1
  rightLowerWing->position(10.5, -0.1, -2.0);  //2
  rightLowerWing->position(10.5, -0.1, -6.0);  //3
  //Right vertexes
  rightLowerWing->position(4.0, -0.5, 0.0);    //4
  rightLowerWing->position(4.0, -0.5, -6.0);   //5
  rightLowerWing->position(4.0, -0.1, 0.0);    //6
  rightLowerWing->position(4.0, -0.1, -6.0);   //7

  //Vertexs of the left lower wing
  //Left vertexes
  rightLowerWing->position(vertex0[0], vertex0[1], vertex0[2]);  //0
  rightLowerWing->position(vertex1[0], vertex1[1], vertex1[2]);  //1
  rightLowerWing->position(vertex2[0], vertex2[1], vertex2[2]);  //2
  rightLowerWing->position(vertex3[0], vertex3[1], vertex3[2]);  //3
  //Right vertexes
  rightLowerWing->position(vertex4[0], vertex4[1], vertex4[2]);  //4
  rightLowerWing->position(vertex5[0], vertex5[1], vertex5[2]);  //5
  rightLowerWing->position(vertex6[0], vertex6[1], vertex6[2]);  //6
  rightLowerWing->position(vertex7[0], vertex7[1], vertex7[2]);  //7

  //Normal of the vertexes
  //Left vertexes
  rightLowerWing->normal(normal0[0], normal0[1], normal0[2]);
  rightLowerWing->normal(normal1[0], normal1[1], normal1[2]);
  rightLowerWing->normal(normal2[0], normal2[1], normal2[2]);
  rightLowerWing->normal(normal3[0], normal3[1], normal3[2]);
  //Right vertexes
  rightLowerWing->normal(normal4[0], normal4[1], normal4[2]);
  rightLowerWing->normal(normal5[0], normal5[1], normal5[2]);
  rightLowerWing->normal(normal6[0], normal6[1], normal6[2]);
  rightLowerWing->normal(normal7[0], normal7[1], normal7[2]);

  //Creating the triangles
  //UpperFace
  rightLowerWing->index(6);
  rightLowerWing->index(2);
  rightLowerWing->index(3);
  rightLowerWing->index(6);
  rightLowerWing->index(3);
  rightLowerWing->index(7);
  //DownFace
  rightLowerWing->index(4);
  rightLowerWing->index(1);
  rightLowerWing->index(0);
  rightLowerWing->index(4);
  rightLowerWing->index(5);
  rightLowerWing->index(1);
  //LeftFace
  rightLowerWing->index(6);
  rightLowerWing->index(7);
  rightLowerWing->index(5);
  rightLowerWing->index(6);
  rightLowerWing->index(5);
  rightLowerWing->index(4);
  //RightFace
  rightLowerWing->index(3);
  rightLowerWing->index(2);
  rightLowerWing->index(1);
  rightLowerWing->index(0);
  rightLowerWing->index(1);
  rightLowerWing->index(2);
  //BackFace
  rightLowerWing->index(0);
  rightLowerWing->index(2);
  rightLowerWing->index(4);
  rightLowerWing->index(4);
  rightLowerWing->index(2);
  rightLowerWing->index(6);
  //FrontFace
  rightLowerWing->index(5);
  rightLowerWing->index(7);
  rightLowerWing->index(3);
  rightLowerWing->index(5);
  rightLowerWing->index(3);
  rightLowerWing->index(1);
   
  rightLowerWing->end();
  rightLowerWingNode->attachObject(rightLowerWing);
}

//Engines
void Xwing::initLeftUpperFrontEngine(Ogre::SceneManager* _sceneManager){
  leftUpperFrontEngineNode = _sceneManager->createSceneNode();
  leftUpperNode->addChild(leftUpperFrontEngineNode);
  leftUpperFrontEngine = _sceneManager->createEntity("leftUpperFrontEngine","usb_cilindro.mesh");
  leftUpperFrontEngineNode->translate(-1.0f,0.8f,0.0f);
  leftUpperFrontEngineNode->scale(0.3f,0.3f,0.3f);
  leftUpperFrontEngineNode->pitch(Ogre::Degree(90));
  leftUpperFrontEngineNode->attachObject(leftUpperFrontEngine);
}

void Xwing::initLeftLowerFrontEngine(Ogre::SceneManager* _sceneManager){
  leftLowerFrontEngineNode = _sceneManager->createSceneNode();
  leftLowerNode->addChild(leftLowerFrontEngineNode);
  leftLowerFrontEngine = _sceneManager->createEntity("leftLowerFrontEngine","usb_cilindro.mesh");
  leftLowerFrontEngineNode->translate(-1.0f,-0.8f,0.0f);
  leftLowerFrontEngineNode->scale(0.3f,0.3f,0.3f);
  leftLowerFrontEngineNode->pitch(Ogre::Degree(90));
  leftLowerFrontEngineNode->attachObject(leftLowerFrontEngine);

}

void Xwing::initRightUpperFrontEngine(Ogre::SceneManager* _sceneManager){
  rightUpperFrontEngineNode = _sceneManager->createSceneNode();
  rightUpperNode->addChild(rightUpperFrontEngineNode);
  rightUpperFrontEngine = _sceneManager->createEntity("rightUpperFrontEngine","usb_cilindro.mesh");
  rightUpperFrontEngineNode->translate(1.0f,0.8f,0.0f);
  rightUpperFrontEngineNode->scale(0.3f,0.3f,0.3f);
  rightUpperFrontEngineNode->pitch(Ogre::Degree(90));
  rightUpperFrontEngineNode->attachObject(rightUpperFrontEngine);

}

void Xwing::initRightLowerFrontEngine(Ogre::SceneManager* _sceneManager){
  rightLowerFrontEngineNode = _sceneManager->createSceneNode();
  rightLowerNode->addChild(rightLowerFrontEngineNode);
  rightLowerFrontEngine = _sceneManager->createEntity("rightLowerFrontEngine","usb_cilindro.mesh");
  rightLowerFrontEngineNode->translate(1.0f,-0.8f,0.0f);
  rightLowerFrontEngineNode->scale(0.3f,0.3f,0.3f);
  rightLowerFrontEngineNode->pitch(Ogre::Degree(90));
  rightLowerFrontEngineNode->attachObject(rightLowerFrontEngine);
}

void Xwing::initLeftUpperBackEngine(Ogre::SceneManager* _sceneManager){
  leftUpperBackEngineNode = _sceneManager->createSceneNode();
  leftUpperNode->addChild(leftUpperBackEngineNode);
  leftUpperBackEngine = _sceneManager->createEntity("leftUpperBackEngine","usb_cilindro.mesh");
  leftUpperBackEngineNode->translate(-1.0f,0.8f,1.5f);
  leftUpperBackEngineNode->scale(0.2f,0.2f,0.2f);
  leftUpperBackEngineNode->pitch(Ogre::Degree(90));
  leftUpperBackEngineNode->attachObject(leftUpperBackEngine);
}

void Xwing::initLeftLowerBackEngine(Ogre::SceneManager* _sceneManager){
  leftLowerBackEngineNode = _sceneManager->createSceneNode();
  leftLowerNode->addChild(leftLowerBackEngineNode);
  leftLowerBackEngine = _sceneManager->createEntity("leftLowerBackEngine","usb_cilindro.mesh");
  leftLowerBackEngineNode->translate(-1.0f,-0.8f,1.5f);
  leftLowerBackEngineNode->scale(0.2f,0.2f,0.2f);
  leftLowerBackEngineNode->pitch(Ogre::Degree(90));
  leftLowerBackEngineNode->attachObject(leftLowerBackEngine);
}

void Xwing::initRightUpperBackEngine(Ogre::SceneManager* _sceneManager){
  rightUpperBackEngineNode = _sceneManager->createSceneNode();
  rightUpperNode->addChild(rightUpperBackEngineNode);
  rightUpperBackEngine = _sceneManager->createEntity("rightUpperBackEngine","usb_cilindro.mesh");
  rightUpperBackEngineNode->translate(1.0f,0.8f,1.5f);
  rightUpperBackEngineNode->scale(0.2f,0.2f,0.2f);
  rightUpperBackEngineNode->pitch(Ogre::Degree(90));
  rightUpperBackEngineNode->attachObject(rightUpperBackEngine);
}

void Xwing::initRightLowerBackEngine(Ogre::SceneManager* _sceneManager){
  rightLowerBackEngineNode = _sceneManager->createSceneNode();
  rightLowerNode->addChild(rightLowerBackEngineNode);
  rightLowerBackEngine = _sceneManager->createEntity("rightLowerBackEngine","usb_cilindro.mesh");
  rightLowerBackEngineNode->translate(1.0f,-0.8f,1.5f);
  rightLowerBackEngineNode->scale(0.2f,0.2f,0.2f);
  rightLowerBackEngineNode->pitch(Ogre::Degree(90));
  rightLowerBackEngineNode->attachObject(rightLowerBackEngine);
}

//Cannons Entities
void Xwing::initLeftUpperCannon(Ogre::SceneManager* _sceneManager){
  leftUpperCannonNode = _sceneManager->createSceneNode();
  leftUpperNode->addChild(leftUpperCannonNode);
  leftUpperCannon = _sceneManager->createEntity("leftUpperCannon","usb_cilindro.mesh");
  leftUpperCannonNode->translate(-8.7f,0.45f,-1.2f);
  leftUpperCannonNode->scale(0.2f,1.2f,0.2f);
  leftUpperCannonNode->pitch(Ogre::Degree(90));
  leftUpperCannonNode->attachObject(leftUpperCannon);
}

void Xwing::initLeftLowerCannon(Ogre::SceneManager* _sceneManager){
  leftLowerCannonNode = _sceneManager->createSceneNode();
  leftLowerNode->addChild(leftLowerCannonNode);
  leftLowerCannon = _sceneManager->createEntity("leftLowerCannon","usb_cilindro.mesh");
  leftLowerCannonNode->translate(-8.7f,-0.45f,-1.2f);
  leftLowerCannonNode->scale(0.2f,1.2f,0.2f);
  leftLowerCannonNode->pitch(Ogre::Degree(90));
  leftLowerCannonNode->attachObject(leftLowerCannon);
}

void Xwing::initRightUpperCannon(Ogre::SceneManager* _sceneManager){
  rightUpperCannonNode = _sceneManager->createSceneNode();
  rightLowerNode->addChild(rightUpperCannonNode);
  rightUpperCannon = _sceneManager->createEntity("rightUpperCannon","usb_cilindro.mesh");
  rightUpperCannonNode->translate(8.7f,0.45f,-1.2f);
  rightUpperCannonNode->scale(0.2f,1.2f,0.2f);
  rightUpperCannonNode->pitch(Ogre::Degree(90));
  rightUpperCannonNode->attachObject(rightUpperCannon);
}

void Xwing::initRightLowerCannon(Ogre::SceneManager* _sceneManager){
  rightLowerCannonNode = _sceneManager->createSceneNode();
  rightLowerNode->addChild(rightLowerCannonNode);
  rightLowerCannon = _sceneManager->createEntity("rightLowerCannon","usb_cilindro.mesh");
  rightLowerCannonNode->translate(8.7f,-0.45f,-1.2f);
  rightLowerCannonNode->scale(0.2f,1.2f,0.2f);
  rightLowerCannonNode->pitch(Ogre::Degree(90));
  rightLowerCannonNode->attachObject(rightLowerCannon);
}

//Extra Entity()
void Xwing::initR2d2(Ogre::SceneManager* _sceneManager){
  r2d2Node = _sceneManager->createSceneNode();
  main->addChild(r2d2Node);
  r2d2 = _sceneManager->createEntity("r2d2","usb_dodecaedro.mesh");
  r2d2Node->scale(0.15f,0.15f,0.15f);
  r2d2Node->translate(0.0,2.5,-3.0);
  r2d2Node->attachObject(r2d2);
}