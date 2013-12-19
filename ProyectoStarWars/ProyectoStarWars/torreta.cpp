#include "Ogre\Ogre.h"
#include "OIS\OIS.h"
#include "torreta.h"
		
Torreta::Torreta(float rx, float ry, float rz, float px, float py, float pz) {
	rotx = rx;
	roty = ry; 
	rotz = rz;
	posx = px;
	posy = py; //-20.0
	posz = pz;
}

Torreta::~Torreta() {
}

//Definicion de la base y cabeza de la torreta

void Torreta::initTorreta(Ogre::SceneManager* _sceneManager) {
		
		Ogre::SceneNode* torreta = _sceneManager->createSceneNode("NodeTorreta");
		torreta->translate(Ogre::Vector3(posx, posy, posz));
		_sceneManager->getRootSceneNode()->addChild(torreta);

		Ogre::SceneNode* nodoBaseTorreta = torreta->createChildSceneNode();
		Ogre::Entity* entBaseTorreta = _sceneManager->createEntity("BaseTorreta","usb_cubomod01torreta.mesh");
		entBaseTorreta->setMaterialName("lambert1");
		nodoBaseTorreta->attachObject(entBaseTorreta);

		Ogre::SceneNode* nodoCabezaTorreta = torreta->createChildSceneNode();
		nodoCabezaTorreta->translate(Ogre::Vector3(0.0, 5.4, -0.2));
		nodoCabezaTorreta->yaw(Ogre::Degree(30));
		Ogre::Entity* entCabezaTorreta = _sceneManager->createEntity("CabezaTorreta","usb_cubomod01torreta.mesh");
		nodoCabezaTorreta->attachObject(entCabezaTorreta);
		nodoCabezaTorreta->scale(0.7f,0.7f,0.7f);

		Ogre::SceneNode* nodoAroBajoTorreta = torreta->createChildSceneNode();
		nodoAroBajoTorreta->translate(Ogre::Vector3(0.0, -2.0, 0.0));
		Ogre::Entity* entAroBajoTorreta = _sceneManager->createEntity("AroBajoTorreta","usb_torus.mesh");
		nodoAroBajoTorreta->attachObject(entAroBajoTorreta);
		nodoAroBajoTorreta->scale(0.7f,0.7f,0.7f);

		Ogre::SceneNode* nodoAroAltoTorreta = torreta->createChildSceneNode();
		nodoAroAltoTorreta->translate(Ogre::Vector3(0.0, 4.0, 0.0));
		Ogre::Entity* entAroAltoTorreta = _sceneManager->createEntity("AroAltoTorreta","usb_torus.mesh");
		nodoAroAltoTorreta->attachObject(entAroAltoTorreta);
		nodoAroAltoTorreta->scale(0.5f,0.5f,0.5f);

		// Definicion de los 4 canones

		Ogre::SceneNode* nodoCanion1 = torreta->createChildSceneNode();
		nodoCanion1->roll(Ogre::Degree(-90));
		nodoCanion1->pitch(Ogre::Degree(90));		
		nodoCanion1->translate(Ogre::Vector3(-0.8, 5.4, 3.5));
		Ogre::Entity* entCanion1 = _sceneManager->createEntity("Canion1","usb_cilindro02.mesh");
		nodoCanion1->attachObject(entCanion1);
		nodoCanion1->scale(0.1f,0.4f,0.1f);

		Ogre::SceneNode* nodoCanion2 = torreta->createChildSceneNode();
		nodoCanion2->roll(Ogre::Degree(-90));
		nodoCanion2->pitch(Ogre::Degree(90));		
		nodoCanion2->translate(Ogre::Vector3(0.8, 5.4, 3.5));
		Ogre::Entity* entCanion2 = _sceneManager->createEntity("Canion2","usb_cilindro02.mesh");
		nodoCanion2->attachObject(entCanion2);
		nodoCanion2->scale(0.1f,0.4f,0.1f);

		Ogre::SceneNode* nodoCanion3 = torreta->createChildSceneNode();
		nodoCanion3->roll(Ogre::Degree(-90));
		nodoCanion3->pitch(Ogre::Degree(90));		
		nodoCanion3->translate(Ogre::Vector3(-0.8, 6.4, 3.5));
		Ogre::Entity* entCanion3 = _sceneManager->createEntity("Canion3","usb_cilindro02.mesh");
		nodoCanion3->attachObject(entCanion3);
		nodoCanion3->scale(0.1f,0.4f,0.1f);

		Ogre::SceneNode* nodoCanion4 = torreta->createChildSceneNode();
		nodoCanion4->roll(Ogre::Degree(-90));
		nodoCanion4->pitch(Ogre::Degree(90));		
		nodoCanion4->translate(Ogre::Vector3(0.8, 6.4, 3.5));
		Ogre::Entity* entCanion4 = _sceneManager->createEntity("Canion4","usb_cilindro02.mesh");
		nodoCanion4->attachObject(entCanion4);
		nodoCanion4->scale(0.1f,0.4f,0.1f);

		//Definicion de los toritos

		Ogre::SceneNode* nodoTorito1 = torreta->createChildSceneNode();
		nodoTorito1->roll(Ogre::Degree(-90));
		nodoTorito1->pitch(Ogre::Degree(90));		
		nodoTorito1->translate(Ogre::Vector3(0.8, 6.4, 5.0));
		Ogre::Entity* entTorito1 = _sceneManager->createEntity("Torito1","usb_torus.mesh");
		nodoTorito1->attachObject(entTorito1);
		nodoTorito1->scale(0.06f,0.06f,0.06f);

		Ogre::SceneNode* nodoTorito2 = torreta->createChildSceneNode();
		nodoTorito2->roll(Ogre::Degree(-90));
		nodoTorito2->pitch(Ogre::Degree(90));		
		nodoTorito2->translate(Ogre::Vector3(0.8, 6.4, 5.5));
		Ogre::Entity* entTorito2 = _sceneManager->createEntity("Torito2","usb_torus.mesh");
		nodoTorito2->attachObject(entTorito2);
		nodoTorito2->scale(0.06f,0.06f,0.06f);

		Ogre::SceneNode* nodoTorito3 = torreta->createChildSceneNode();
		nodoTorito3->roll(Ogre::Degree(-90));
		nodoTorito3->pitch(Ogre::Degree(90));		
		nodoTorito3->translate(Ogre::Vector3(-0.8, 6.4, 5.0));
		Ogre::Entity* entTorito3 = _sceneManager->createEntity("Torito3","usb_torus.mesh");
		nodoTorito3->attachObject(entTorito3);
		nodoTorito3->scale(0.06f,0.06f,0.06f);

		Ogre::SceneNode* nodoTorito4 = torreta->createChildSceneNode();
		nodoTorito4->roll(Ogre::Degree(-90));
		nodoTorito4->pitch(Ogre::Degree(90));		
		nodoTorito4->translate(Ogre::Vector3(-0.8, 6.4, 5.5));
		Ogre::Entity* entTorito4 = _sceneManager->createEntity("Torito4","usb_torus.mesh");
		nodoTorito4->attachObject(entTorito4);
		nodoTorito4->scale(0.06f,0.06f,0.06f);

		Ogre::SceneNode* nodoTorito5 = torreta->createChildSceneNode();
		nodoTorito5->roll(Ogre::Degree(-90));
		nodoTorito5->pitch(Ogre::Degree(90));		
		nodoTorito5->translate(Ogre::Vector3(0.8, 5.4, 5.0));
		Ogre::Entity* entTorito5 = _sceneManager->createEntity("Torito5","usb_torus.mesh");
		nodoTorito5->attachObject(entTorito5);
		nodoTorito5->scale(0.06f,0.06f,0.06f);

		Ogre::SceneNode* nodoTorito6 = torreta->createChildSceneNode();
		nodoTorito6->roll(Ogre::Degree(-90));
		nodoTorito6->pitch(Ogre::Degree(90));		
		nodoTorito6->translate(Ogre::Vector3(0.8, 5.4, 5.5));
		Ogre::Entity* entTorito6 = _sceneManager->createEntity("Torito6","usb_torus.mesh");
		nodoTorito6->attachObject(entTorito6);
		nodoTorito6->scale(0.06f,0.06f,0.06f);

		Ogre::SceneNode* nodoTorito7 = torreta->createChildSceneNode();
		nodoTorito7->roll(Ogre::Degree(-90));
		nodoTorito7->pitch(Ogre::Degree(90));		
		nodoTorito7->translate(Ogre::Vector3(-0.8, 5.4, 5.0));
		Ogre::Entity* entTorito7 = _sceneManager->createEntity("Torito7","usb_torus.mesh");
		nodoTorito7->attachObject(entTorito7);
		nodoTorito7->scale(0.06f,0.06f,0.06f);

		Ogre::SceneNode* nodoTorito8 = torreta->createChildSceneNode();
		nodoTorito8->roll(Ogre::Degree(-90));
		nodoTorito8->pitch(Ogre::Degree(90));		
		nodoTorito8->translate(Ogre::Vector3(-0.8, 5.4, 5.5));
		Ogre::Entity* entTorito8 = _sceneManager->createEntity("Torito8","usb_torus.mesh");
		nodoTorito8->attachObject(entTorito8);
		nodoTorito8->scale(0.06f,0.06f,0.06f);
}