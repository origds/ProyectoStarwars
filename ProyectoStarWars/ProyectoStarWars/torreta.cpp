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

void Torreta::initTorreta1(Ogre::SceneManager* _sceneManager) {
		
		Ogre::SceneNode* torreta1 = _sceneManager->createSceneNode("NodeTorreta1");
		torreta1->translate(Ogre::Vector3(posx, posy, posz));
		_sceneManager->getRootSceneNode()->addChild(torreta1);

		Ogre::SceneNode* nodoBaseTorreta1 = torreta1->createChildSceneNode();
		Ogre::Entity* entBaseTorreta1 = _sceneManager->createEntity("BaseTorreta1","usb_cubomod01torreta.mesh");
		entBaseTorreta1->setMaterialName("lambert1");
		nodoBaseTorreta1->attachObject(entBaseTorreta1);

		Ogre::SceneNode* nodoCabezaTorreta1 = torreta1->createChildSceneNode();
		nodoCabezaTorreta1->translate(Ogre::Vector3(0.0, 5.4, -0.2));
		nodoCabezaTorreta1->yaw(Ogre::Degree(30));
		Ogre::Entity* entCabezaTorreta1 = _sceneManager->createEntity("CabezaTorreta1","usb_cubomod01torreta.mesh");
		nodoCabezaTorreta1->attachObject(entCabezaTorreta1);
		nodoCabezaTorreta1->scale(0.7f,0.7f,0.7f);

		Ogre::SceneNode* nodoAroBajoTorreta1 = torreta1->createChildSceneNode();
		nodoAroBajoTorreta1->translate(Ogre::Vector3(0.0, -2.0, 0.0));
		Ogre::Entity* entAroBajoTorreta1 = _sceneManager->createEntity("AroBajoTorreta1","usb_torus.mesh");
		nodoAroBajoTorreta1->attachObject(entAroBajoTorreta1);
		nodoAroBajoTorreta1->scale(0.7f,0.7f,0.7f);

		Ogre::SceneNode* nodoAroAltoTorreta1 = torreta1->createChildSceneNode();
		nodoAroAltoTorreta1->translate(Ogre::Vector3(0.0, 4.0, 0.0));
		Ogre::Entity* entAroAltoTorreta1 = _sceneManager->createEntity("AroAltoTorreta1","usb_torus.mesh");
		nodoAroAltoTorreta1->attachObject(entAroAltoTorreta1);
		nodoAroAltoTorreta1->scale(0.5f,0.5f,0.5f);

		// Definicion de los 4 canones

		Ogre::SceneNode* nodoCanion11 = torreta1->createChildSceneNode();
		nodoCanion11->roll(Ogre::Degree(-90));
		nodoCanion11->pitch(Ogre::Degree(90));		
		nodoCanion11->translate(Ogre::Vector3(-0.8, 5.4, 3.5));
		Ogre::Entity* entCanion11 = _sceneManager->createEntity("Canion11","usb_cilindro02.mesh");
		nodoCanion11->attachObject(entCanion11);
		nodoCanion11->scale(0.1f,0.4f,0.1f);

		Ogre::SceneNode* nodoCanion21 = torreta1->createChildSceneNode();
		nodoCanion21->roll(Ogre::Degree(-90));
		nodoCanion21->pitch(Ogre::Degree(90));		
		nodoCanion21->translate(Ogre::Vector3(0.8, 5.4, 3.5));
		Ogre::Entity* entCanion21 = _sceneManager->createEntity("Canion21","usb_cilindro02.mesh");
		nodoCanion21->attachObject(entCanion21);
		nodoCanion21->scale(0.1f,0.4f,0.1f);

		Ogre::SceneNode* nodoCanion31 = torreta1->createChildSceneNode();
		nodoCanion31->roll(Ogre::Degree(-90));
		nodoCanion31->pitch(Ogre::Degree(90));		
		nodoCanion31->translate(Ogre::Vector3(-0.8, 6.4, 3.5));
		Ogre::Entity* entCanion31 = _sceneManager->createEntity("Canion31","usb_cilindro02.mesh");
		nodoCanion31->attachObject(entCanion31);
		nodoCanion31->scale(0.1f,0.4f,0.1f);

		Ogre::SceneNode* nodoCanion41 = torreta1->createChildSceneNode();
		nodoCanion41->roll(Ogre::Degree(-90));
		nodoCanion41->pitch(Ogre::Degree(90));		
		nodoCanion41->translate(Ogre::Vector3(0.8, 6.4, 3.5));
		Ogre::Entity* entCanion41 = _sceneManager->createEntity("Canion41","usb_cilindro02.mesh");
		nodoCanion41->attachObject(entCanion41);
		nodoCanion41->scale(0.1f,0.4f,0.1f);

		//Definicion de los toritos

		Ogre::SceneNode* nodoTorito11 = torreta1->createChildSceneNode();
		nodoTorito11->roll(Ogre::Degree(-90));
		nodoTorito11->pitch(Ogre::Degree(90));		
		nodoTorito11->translate(Ogre::Vector3(0.8, 6.4, 5.0));
		Ogre::Entity* entTorito11 = _sceneManager->createEntity("Torito11","usb_torus.mesh");
		nodoTorito11->attachObject(entTorito11);
		nodoTorito11->scale(0.06f,0.06f,0.06f);

		Ogre::SceneNode* nodoTorito21 = torreta1->createChildSceneNode();
		nodoTorito21->roll(Ogre::Degree(-90));
		nodoTorito21->pitch(Ogre::Degree(90));		
		nodoTorito21->translate(Ogre::Vector3(0.8, 6.4, 5.5));
		Ogre::Entity* entTorito21 = _sceneManager->createEntity("Torito21","usb_torus.mesh");
		nodoTorito21->attachObject(entTorito21);
		nodoTorito21->scale(0.06f,0.06f,0.06f);

		Ogre::SceneNode* nodoTorito31 = torreta1->createChildSceneNode();
		nodoTorito31->roll(Ogre::Degree(-90));
		nodoTorito31->pitch(Ogre::Degree(90));		
		nodoTorito31->translate(Ogre::Vector3(-0.8, 6.4, 5.0));
		Ogre::Entity* entTorito31 = _sceneManager->createEntity("Torito31","usb_torus.mesh");
		nodoTorito31->attachObject(entTorito31);
		nodoTorito31->scale(0.06f,0.06f,0.06f);

		Ogre::SceneNode* nodoTorito41 = torreta1->createChildSceneNode();
		nodoTorito41->roll(Ogre::Degree(-90));
		nodoTorito41->pitch(Ogre::Degree(90));		
		nodoTorito41->translate(Ogre::Vector3(-0.8, 6.4, 5.5));
		Ogre::Entity* entTorito41 = _sceneManager->createEntity("Torito41","usb_torus.mesh");
		nodoTorito41->attachObject(entTorito41);
		nodoTorito41->scale(0.06f,0.06f,0.06f);

		Ogre::SceneNode* nodoTorito51 = torreta1->createChildSceneNode();
		nodoTorito51->roll(Ogre::Degree(-90));
		nodoTorito51->pitch(Ogre::Degree(90));		
		nodoTorito51->translate(Ogre::Vector3(0.8, 5.4, 5.0));
		Ogre::Entity* entTorito51 = _sceneManager->createEntity("Torito51","usb_torus.mesh");
		nodoTorito51->attachObject(entTorito51);
		nodoTorito51->scale(0.06f,0.06f,0.06f);

		Ogre::SceneNode* nodoTorito61 = torreta1->createChildSceneNode();
		nodoTorito61->roll(Ogre::Degree(-90));
		nodoTorito61->pitch(Ogre::Degree(90));		
		nodoTorito61->translate(Ogre::Vector3(0.8, 5.4, 5.5));
		Ogre::Entity* entTorito61 = _sceneManager->createEntity("Torito61","usb_torus.mesh");
		nodoTorito61->attachObject(entTorito61);
		nodoTorito61->scale(0.06f,0.06f,0.06f);

		Ogre::SceneNode* nodoTorito71 = torreta1->createChildSceneNode();
		nodoTorito71->roll(Ogre::Degree(-90));
		nodoTorito71->pitch(Ogre::Degree(90));		
		nodoTorito71->translate(Ogre::Vector3(-0.8, 5.4, 5.0));
		Ogre::Entity* entTorito71 = _sceneManager->createEntity("Torito71","usb_torus.mesh");
		nodoTorito71->attachObject(entTorito71);
		nodoTorito71->scale(0.06f,0.06f,0.06f);

		Ogre::SceneNode* nodoTorito81 = torreta1->createChildSceneNode();
		nodoTorito81->roll(Ogre::Degree(-90));
		nodoTorito81->pitch(Ogre::Degree(90));		
		nodoTorito81->translate(Ogre::Vector3(-0.8, 5.4, 5.5));
		Ogre::Entity* entTorito81 = _sceneManager->createEntity("Torito81","usb_torus.mesh");
		nodoTorito81->attachObject(entTorito81);
		nodoTorito81->scale(0.06f,0.06f,0.06f);

		Ogre::SceneNode* nodoLaser11 = nodoCanion11->createChildSceneNode();	
		Ogre::Entity* entLaser11 = _sceneManager->createEntity("Laser11","usb_laser.mesh");
		nodoLaser11->translate(Ogre::Vector3(5.0, 5.4, 6.5));
		nodoLaser11->attachObject(entLaser11);
		nodoLaser11->scale(0.06f,0.06f,0.06f);
}

void Torreta::initTorreta3(Ogre::SceneManager* _sceneManager) {
		
		Ogre::SceneNode* torreta3 = _sceneManager->createSceneNode("NodeTorreta3");
		torreta3->translate(Ogre::Vector3(posx, posy, posz));
		_sceneManager->getRootSceneNode()->addChild(torreta3);

		Ogre::SceneNode* nodoBaseTorreta3 = torreta3->createChildSceneNode();
		Ogre::Entity* entBaseTorreta3 = _sceneManager->createEntity("BaseTorreta3","usb_cubomod01torreta.mesh");
		entBaseTorreta3->setMaterialName("lambert1");
		nodoBaseTorreta3->attachObject(entBaseTorreta3);

		Ogre::SceneNode* nodoCabezaTorreta3 = torreta3->createChildSceneNode();
		nodoCabezaTorreta3->translate(Ogre::Vector3(0.0, 5.4, -0.2));
		nodoCabezaTorreta3->yaw(Ogre::Degree(30));
		Ogre::Entity* entCabezaTorreta3 = _sceneManager->createEntity("CabezaTorreta3","usb_cubomod01torreta.mesh");
		nodoCabezaTorreta3->attachObject(entCabezaTorreta3);
		nodoCabezaTorreta3->scale(0.7f,0.7f,0.7f);

		Ogre::SceneNode* nodoAroBajoTorreta3 = torreta3->createChildSceneNode();
		nodoAroBajoTorreta3->translate(Ogre::Vector3(0.0, -2.0, 0.0));
		Ogre::Entity* entAroBajoTorreta3 = _sceneManager->createEntity("AroBajoTorreta3","usb_torus.mesh");
		nodoAroBajoTorreta3->attachObject(entAroBajoTorreta3);
		nodoAroBajoTorreta3->scale(0.7f,0.7f,0.7f);

		Ogre::SceneNode* nodoAroAltoTorreta3 = torreta3->createChildSceneNode();
		nodoAroAltoTorreta3->translate(Ogre::Vector3(0.0, 4.0, 0.0));
		Ogre::Entity* entAroAltoTorreta3 = _sceneManager->createEntity("AroAltoTorreta3","usb_torus.mesh");
		nodoAroAltoTorreta3->attachObject(entAroAltoTorreta3);
		nodoAroAltoTorreta3->scale(0.5f,0.5f,0.5f);

		// Definicion de los 4 canones

		Ogre::SceneNode* nodoCanion13 = torreta3->createChildSceneNode();
		nodoCanion13->roll(Ogre::Degree(-90));
		nodoCanion13->pitch(Ogre::Degree(90));		
		nodoCanion13->translate(Ogre::Vector3(-0.8, 5.4, 3.5));
		Ogre::Entity* entCanion13 = _sceneManager->createEntity("Canion13","usb_cilindro02.mesh");
		nodoCanion13->attachObject(entCanion13);
		nodoCanion13->scale(0.1f,0.4f,0.1f);

		Ogre::SceneNode* nodoCanion23 = torreta3->createChildSceneNode();
		nodoCanion23->roll(Ogre::Degree(-90));
		nodoCanion23->pitch(Ogre::Degree(90));		
		nodoCanion23->translate(Ogre::Vector3(0.8, 5.4, 3.5));
		Ogre::Entity* entCanion23 = _sceneManager->createEntity("Canion23","usb_cilindro02.mesh");
		nodoCanion23->attachObject(entCanion23);
		nodoCanion23->scale(0.1f,0.4f,0.1f);

		Ogre::SceneNode* nodoCanion33 = torreta3->createChildSceneNode();
		nodoCanion33->roll(Ogre::Degree(-90));
		nodoCanion33->pitch(Ogre::Degree(90));		
		nodoCanion33->translate(Ogre::Vector3(-0.8, 6.4, 3.5));
		Ogre::Entity* entCanion33 = _sceneManager->createEntity("Canion33","usb_cilindro02.mesh");
		nodoCanion33->attachObject(entCanion33);
		nodoCanion33->scale(0.1f,0.4f,0.1f);

		Ogre::SceneNode* nodoCanion43 = torreta3->createChildSceneNode();
		nodoCanion43->roll(Ogre::Degree(-90));
		nodoCanion43->pitch(Ogre::Degree(90));		
		nodoCanion43->translate(Ogre::Vector3(0.8, 6.4, 3.5));
		Ogre::Entity* entCanion43 = _sceneManager->createEntity("Canion43","usb_cilindro02.mesh");
		nodoCanion43->attachObject(entCanion43);
		nodoCanion43->scale(0.1f,0.4f,0.1f);

		//Definicion de los toritos

		Ogre::SceneNode* nodoTorito13 = torreta3->createChildSceneNode();
		nodoTorito13->roll(Ogre::Degree(-90));
		nodoTorito13->pitch(Ogre::Degree(90));		
		nodoTorito13->translate(Ogre::Vector3(0.8, 6.4, 5.0));
		Ogre::Entity* entTorito13 = _sceneManager->createEntity("Torito13","usb_torus.mesh");
		nodoTorito13->attachObject(entTorito13);
		nodoTorito13->scale(0.06f,0.06f,0.06f);

		Ogre::SceneNode* nodoTorito23 = torreta3->createChildSceneNode();
		nodoTorito23->roll(Ogre::Degree(-90));
		nodoTorito23->pitch(Ogre::Degree(90));		
		nodoTorito23->translate(Ogre::Vector3(0.8, 6.4, 5.5));
		Ogre::Entity* entTorito23 = _sceneManager->createEntity("Torito23","usb_torus.mesh");
		nodoTorito23->attachObject(entTorito23);
		nodoTorito23->scale(0.06f,0.06f,0.06f);

		Ogre::SceneNode* nodoTorito33 = torreta3->createChildSceneNode();
		nodoTorito33->roll(Ogre::Degree(-90));
		nodoTorito33->pitch(Ogre::Degree(90));		
		nodoTorito33->translate(Ogre::Vector3(-0.8, 6.4, 5.0));
		Ogre::Entity* entTorito33 = _sceneManager->createEntity("Torito33","usb_torus.mesh");
		nodoTorito33->attachObject(entTorito33);
		nodoTorito33->scale(0.06f,0.06f,0.06f);

		Ogre::SceneNode* nodoTorito43 = torreta3->createChildSceneNode();
		nodoTorito43->roll(Ogre::Degree(-90));
		nodoTorito43->pitch(Ogre::Degree(90));		
		nodoTorito43->translate(Ogre::Vector3(-0.8, 6.4, 5.5));
		Ogre::Entity* entTorito43 = _sceneManager->createEntity("Torito43","usb_torus.mesh");
		nodoTorito43->attachObject(entTorito43);
		nodoTorito43->scale(0.06f,0.06f,0.06f);

		Ogre::SceneNode* nodoTorito53 = torreta3->createChildSceneNode();
		nodoTorito53->roll(Ogre::Degree(-90));
		nodoTorito53->pitch(Ogre::Degree(90));		
		nodoTorito53->translate(Ogre::Vector3(0.8, 5.4, 5.0));
		Ogre::Entity* entTorito53 = _sceneManager->createEntity("Torito53","usb_torus.mesh");
		nodoTorito53->attachObject(entTorito53);
		nodoTorito53->scale(0.06f,0.06f,0.06f);

		Ogre::SceneNode* nodoTorito63 = torreta3->createChildSceneNode();
		nodoTorito63->roll(Ogre::Degree(-90));
		nodoTorito63->pitch(Ogre::Degree(90));		
		nodoTorito63->translate(Ogre::Vector3(0.8, 5.4, 5.5));
		Ogre::Entity* entTorito63 = _sceneManager->createEntity("Torito63","usb_torus.mesh");
		nodoTorito63->attachObject(entTorito63);
		nodoTorito63->scale(0.06f,0.06f,0.06f);

		Ogre::SceneNode* nodoTorito73 = torreta3->createChildSceneNode();
		nodoTorito73->roll(Ogre::Degree(-90));
		nodoTorito73->pitch(Ogre::Degree(90));		
		nodoTorito73->translate(Ogre::Vector3(-0.8, 5.4, 5.0));
		Ogre::Entity* entTorito73 = _sceneManager->createEntity("Torito73","usb_torus.mesh");
		nodoTorito73->attachObject(entTorito73);
		nodoTorito73->scale(0.06f,0.06f,0.06f);

		Ogre::SceneNode* nodoTorito83 = torreta3->createChildSceneNode();
		nodoTorito83->roll(Ogre::Degree(-90));
		nodoTorito83->pitch(Ogre::Degree(90));		
		nodoTorito83->translate(Ogre::Vector3(-0.8, 5.4, 5.5));
		Ogre::Entity* entTorito83 = _sceneManager->createEntity("Torito83","usb_torus.mesh");
		nodoTorito83->attachObject(entTorito83);
		nodoTorito83->scale(0.06f,0.06f,0.06f);
}

void Torreta::initTorreta2(Ogre::SceneManager* _sceneManager) {
		
		Ogre::SceneNode* torreta2 = _sceneManager->createSceneNode("NodeTorreta2");
		torreta2->translate(Ogre::Vector3(posx, posy, posz));
		_sceneManager->getRootSceneNode()->addChild(torreta2);

		Ogre::SceneNode* nodoBaseTorreta2 = torreta2->createChildSceneNode();
		Ogre::Entity* entBaseTorreta2 = _sceneManager->createEntity("BaseTorreta2","usb_cubomod01torreta.mesh");
		entBaseTorreta2->setMaterialName("lambert1");
		nodoBaseTorreta2->attachObject(entBaseTorreta2);

		Ogre::SceneNode* nodoCabezaTorreta2 = torreta2->createChildSceneNode();
		nodoCabezaTorreta2->translate(Ogre::Vector3(0.0, 5.4, -0.2));
		nodoCabezaTorreta2->yaw(Ogre::Degree(30));
		Ogre::Entity* entCabezaTorreta2 = _sceneManager->createEntity("CabezaTorreta2","usb_cubomod01torreta.mesh");
		nodoCabezaTorreta2->attachObject(entCabezaTorreta2);
		nodoCabezaTorreta2->scale(0.7f,0.7f,0.7f);

		Ogre::SceneNode* nodoAroBajoTorreta2 = torreta2->createChildSceneNode();
		nodoAroBajoTorreta2->translate(Ogre::Vector3(0.0, -2.0, 0.0));
		Ogre::Entity* entAroBajoTorreta2 = _sceneManager->createEntity("AroBajoTorreta2","usb_torus.mesh");
		nodoAroBajoTorreta2->attachObject(entAroBajoTorreta2);
		nodoAroBajoTorreta2->scale(0.7f,0.7f,0.7f);

		Ogre::SceneNode* nodoAroAltoTorreta2 = torreta2->createChildSceneNode();
		nodoAroAltoTorreta2->translate(Ogre::Vector3(0.0, 4.0, 0.0));
		Ogre::Entity* entAroAltoTorreta2 = _sceneManager->createEntity("AroAltoTorreta2","usb_torus.mesh");
		nodoAroAltoTorreta2->attachObject(entAroAltoTorreta2);
		nodoAroAltoTorreta2->scale(0.5f,0.5f,0.5f);

		// Definicion de los 4 canones

		Ogre::SceneNode* nodoCanion12 = torreta2->createChildSceneNode();
		nodoCanion12->roll(Ogre::Degree(-90));
		nodoCanion12->pitch(Ogre::Degree(90));		
		nodoCanion12->translate(Ogre::Vector3(-0.8, 5.4, 3.5));
		Ogre::Entity* entCanion12 = _sceneManager->createEntity("Canion12","usb_cilindro02.mesh");
		nodoCanion12->attachObject(entCanion12);
		nodoCanion12->scale(0.1f,0.4f,0.1f);

		Ogre::SceneNode* nodoCanion22 = torreta2->createChildSceneNode();
		nodoCanion22->roll(Ogre::Degree(-90));
		nodoCanion22->pitch(Ogre::Degree(90));		
		nodoCanion22->translate(Ogre::Vector3(0.8, 5.4, 3.5));
		Ogre::Entity* entCanion22 = _sceneManager->createEntity("Canion22","usb_cilindro02.mesh");
		nodoCanion22->attachObject(entCanion22);
		nodoCanion22->scale(0.1f,0.4f,0.1f);

		Ogre::SceneNode* nodoCanion32= torreta2->createChildSceneNode();
		nodoCanion32->roll(Ogre::Degree(-90));
		nodoCanion32->pitch(Ogre::Degree(90));		
		nodoCanion32->translate(Ogre::Vector3(-0.8, 6.4, 3.5));
		Ogre::Entity* entCanion32 = _sceneManager->createEntity("Canion32","usb_cilindro02.mesh");
		nodoCanion32->attachObject(entCanion32);
		nodoCanion32->scale(0.1f,0.4f,0.1f);

		Ogre::SceneNode* nodoCanion42 = torreta2->createChildSceneNode();
		nodoCanion42->roll(Ogre::Degree(-90));
		nodoCanion42->pitch(Ogre::Degree(90));		
		nodoCanion42->translate(Ogre::Vector3(0.8, 6.4, 3.5));
		Ogre::Entity* entCanion42 = _sceneManager->createEntity("Canion42","usb_cilindro02.mesh");
		nodoCanion42->attachObject(entCanion42);
		nodoCanion42->scale(0.1f,0.4f,0.1f);

		//Definicion de los toritos

		Ogre::SceneNode* nodoTorito12 = torreta2->createChildSceneNode();
		nodoTorito12->roll(Ogre::Degree(-90));
		nodoTorito12->pitch(Ogre::Degree(90));		
		nodoTorito12->translate(Ogre::Vector3(0.8, 6.4, 5.0));
		Ogre::Entity* entTorito12 = _sceneManager->createEntity("Torito12","usb_torus.mesh");
		nodoTorito12->attachObject(entTorito12);
		nodoTorito12->scale(0.06f,0.06f,0.06f);

		Ogre::SceneNode* nodoTorito22 = torreta2->createChildSceneNode();
		nodoTorito22->roll(Ogre::Degree(-90));
		nodoTorito22->pitch(Ogre::Degree(90));		
		nodoTorito22->translate(Ogre::Vector3(0.8, 6.4, 5.5));
		Ogre::Entity* entTorito22 = _sceneManager->createEntity("Torito22","usb_torus.mesh");
		nodoTorito22->attachObject(entTorito22);
		nodoTorito22->scale(0.06f,0.06f,0.06f);

		Ogre::SceneNode* nodoTorito32 = torreta2->createChildSceneNode();
		nodoTorito32->roll(Ogre::Degree(-90));
		nodoTorito32->pitch(Ogre::Degree(90));		
		nodoTorito32->translate(Ogre::Vector3(-0.8, 6.4, 5.0));
		Ogre::Entity* entTorito32 = _sceneManager->createEntity("Torito32","usb_torus.mesh");
		nodoTorito32->attachObject(entTorito32);
		nodoTorito32->scale(0.06f,0.06f,0.06f);

		Ogre::SceneNode* nodoTorito42 = torreta2->createChildSceneNode();
		nodoTorito42->roll(Ogre::Degree(-90));
		nodoTorito42->pitch(Ogre::Degree(90));		
		nodoTorito42->translate(Ogre::Vector3(-0.8, 6.4, 5.5));
		Ogre::Entity* entTorito42 = _sceneManager->createEntity("Torito42","usb_torus.mesh");
		nodoTorito42->attachObject(entTorito42);
		nodoTorito42->scale(0.06f,0.06f,0.06f);

		Ogre::SceneNode* nodoTorito52 = torreta2->createChildSceneNode();
		nodoTorito52->roll(Ogre::Degree(-90));
		nodoTorito52->pitch(Ogre::Degree(90));		
		nodoTorito52->translate(Ogre::Vector3(0.8, 5.4, 5.0));
		Ogre::Entity* entTorito52 = _sceneManager->createEntity("Torito52","usb_torus.mesh");
		nodoTorito52->attachObject(entTorito52);
		nodoTorito52->scale(0.06f,0.06f,0.06f);

		Ogre::SceneNode* nodoTorito62 = torreta2->createChildSceneNode();
		nodoTorito62->roll(Ogre::Degree(-90));
		nodoTorito62->pitch(Ogre::Degree(90));		
		nodoTorito62->translate(Ogre::Vector3(0.8, 5.4, 5.5));
		Ogre::Entity* entTorito62 = _sceneManager->createEntity("Torito62","usb_torus.mesh");
		nodoTorito62->attachObject(entTorito62);
		nodoTorito62->scale(0.06f,0.06f,0.06f);

		Ogre::SceneNode* nodoTorito72 = torreta2->createChildSceneNode();
		nodoTorito72->roll(Ogre::Degree(-90));
		nodoTorito72->pitch(Ogre::Degree(90));		
		nodoTorito72->translate(Ogre::Vector3(-0.8, 5.4, 5.0));
		Ogre::Entity* entTorito72 = _sceneManager->createEntity("Torito72","usb_torus.mesh");
		nodoTorito72->attachObject(entTorito72);
		nodoTorito72->scale(0.06f,0.06f,0.06f);

		Ogre::SceneNode* nodoTorito82 = torreta2->createChildSceneNode();
		nodoTorito82->roll(Ogre::Degree(-90));
		nodoTorito82->pitch(Ogre::Degree(90));		
		nodoTorito82->translate(Ogre::Vector3(-0.8, 5.4, 5.5));
		Ogre::Entity* entTorito82 = _sceneManager->createEntity("Torito82","usb_torus.mesh");
		nodoTorito82->attachObject(entTorito82);
		nodoTorito82->scale(0.06f,0.06f,0.06f);
}

void Torreta::initTorreta4(Ogre::SceneManager* _sceneManager) {
		
		Ogre::SceneNode* torreta4 = _sceneManager->createSceneNode("NodeTorreta4");
		torreta4->translate(Ogre::Vector3(posx, posy, posz));
		_sceneManager->getRootSceneNode()->addChild(torreta4);

		Ogre::SceneNode* nodoBaseTorreta4 = torreta4->createChildSceneNode();
		Ogre::Entity* entBaseTorreta4 = _sceneManager->createEntity("BaseTorreta4","usb_cubomod01torreta.mesh");
		entBaseTorreta4->setMaterialName("lambert1");
		nodoBaseTorreta4->attachObject(entBaseTorreta4);

		Ogre::SceneNode* nodoCabezaTorreta4 = torreta4->createChildSceneNode();
		nodoCabezaTorreta4->translate(Ogre::Vector3(0.0, 5.4, -0.2));
		nodoCabezaTorreta4->yaw(Ogre::Degree(30));
		Ogre::Entity* entCabezaTorreta4 = _sceneManager->createEntity("CabezaTorreta4","usb_cubomod01torreta.mesh");
		nodoCabezaTorreta4->attachObject(entCabezaTorreta4);
		nodoCabezaTorreta4->scale(0.7f,0.7f,0.7f);

		Ogre::SceneNode* nodoAroBajoTorreta4 = torreta4->createChildSceneNode();
		nodoAroBajoTorreta4->translate(Ogre::Vector3(0.0, -2.0, 0.0));
		Ogre::Entity* entAroBajoTorreta4 = _sceneManager->createEntity("AroBajoTorreta4","usb_torus.mesh");
		nodoAroBajoTorreta4->attachObject(entAroBajoTorreta4);
		nodoAroBajoTorreta4->scale(0.7f,0.7f,0.7f);

		Ogre::SceneNode* nodoAroAltoTorreta4 = torreta4->createChildSceneNode();
		nodoAroAltoTorreta4->translate(Ogre::Vector3(0.0, 4.0, 0.0));
		Ogre::Entity* entAroAltoTorreta4 = _sceneManager->createEntity("AroAltoTorreta4","usb_torus.mesh");
		nodoAroAltoTorreta4->attachObject(entAroAltoTorreta4);
		nodoAroAltoTorreta4->scale(0.5f,0.5f,0.5f);

		// Definicion de los 4 canones

		Ogre::SceneNode* nodoCanion14 = torreta4->createChildSceneNode();
		nodoCanion14->roll(Ogre::Degree(-90));
		nodoCanion14->pitch(Ogre::Degree(90));		
		nodoCanion14->translate(Ogre::Vector3(-0.8, 5.4, 3.5));
		Ogre::Entity* entCanion14 = _sceneManager->createEntity("Canion14","usb_cilindro02.mesh");
		nodoCanion14->attachObject(entCanion14);
		nodoCanion14->scale(0.1f,0.4f,0.1f);

		Ogre::SceneNode* nodoCanion24 = torreta4->createChildSceneNode();
		nodoCanion24->roll(Ogre::Degree(-90));
		nodoCanion24->pitch(Ogre::Degree(90));		
		nodoCanion24->translate(Ogre::Vector3(0.8, 5.4, 3.5));
		Ogre::Entity* entCanion24 = _sceneManager->createEntity("Canion24","usb_cilindro02.mesh");
		nodoCanion24->attachObject(entCanion24);
		nodoCanion24->scale(0.1f,0.4f,0.1f);

		Ogre::SceneNode* nodoCanion34= torreta4->createChildSceneNode();
		nodoCanion34->roll(Ogre::Degree(-90));
		nodoCanion34->pitch(Ogre::Degree(90));		
		nodoCanion34->translate(Ogre::Vector3(-0.8, 6.4, 3.5));
		Ogre::Entity* entCanion34 = _sceneManager->createEntity("Canion34","usb_cilindro02.mesh");
		nodoCanion34->attachObject(entCanion34);
		nodoCanion34->scale(0.1f,0.4f,0.1f);

		Ogre::SceneNode* nodoCanion44 = torreta4->createChildSceneNode();
		nodoCanion44->roll(Ogre::Degree(-90));
		nodoCanion44->pitch(Ogre::Degree(90));		
		nodoCanion44->translate(Ogre::Vector3(0.8, 6.4, 3.5));
		Ogre::Entity* entCanion44 = _sceneManager->createEntity("Canion44","usb_cilindro02.mesh");
		nodoCanion44->attachObject(entCanion44);
		nodoCanion44->scale(0.1f,0.4f,0.1f);

		//Definicion de los toritos

		Ogre::SceneNode* nodoTorito14 = torreta4->createChildSceneNode();
		nodoTorito14->roll(Ogre::Degree(-90));
		nodoTorito14->pitch(Ogre::Degree(90));		
		nodoTorito14->translate(Ogre::Vector3(0.8, 6.4, 5.0));
		Ogre::Entity* entTorito14 = _sceneManager->createEntity("Torito14","usb_torus.mesh");
		nodoTorito14->attachObject(entTorito14);
		nodoTorito14->scale(0.06f,0.06f,0.06f);

		Ogre::SceneNode* nodoTorito24 = torreta4->createChildSceneNode();
		nodoTorito24->roll(Ogre::Degree(-90));
		nodoTorito24->pitch(Ogre::Degree(90));		
		nodoTorito24->translate(Ogre::Vector3(0.8, 6.4, 5.5));
		Ogre::Entity* entTorito24 = _sceneManager->createEntity("Torito24","usb_torus.mesh");
		nodoTorito24->attachObject(entTorito24);
		nodoTorito24->scale(0.06f,0.06f,0.06f);

		Ogre::SceneNode* nodoTorito34 = torreta4->createChildSceneNode();
		nodoTorito34->roll(Ogre::Degree(-90));
		nodoTorito34->pitch(Ogre::Degree(90));		
		nodoTorito34->translate(Ogre::Vector3(-0.8, 6.4, 5.0));
		Ogre::Entity* entTorito34 = _sceneManager->createEntity("Torito34","usb_torus.mesh");
		nodoTorito34->attachObject(entTorito34);
		nodoTorito34->scale(0.06f,0.06f,0.06f);

		Ogre::SceneNode* nodoTorito44 = torreta4->createChildSceneNode();
		nodoTorito44->roll(Ogre::Degree(-90));
		nodoTorito44->pitch(Ogre::Degree(90));		
		nodoTorito44->translate(Ogre::Vector3(-0.8, 6.4, 5.5));
		Ogre::Entity* entTorito44 = _sceneManager->createEntity("Torito44","usb_torus.mesh");
		nodoTorito44->attachObject(entTorito44);
		nodoTorito44->scale(0.06f,0.06f,0.06f);

		Ogre::SceneNode* nodoTorito54 = torreta4->createChildSceneNode();
		nodoTorito54->roll(Ogre::Degree(-90));
		nodoTorito54->pitch(Ogre::Degree(90));		
		nodoTorito54->translate(Ogre::Vector3(0.8, 5.4, 5.0));
		Ogre::Entity* entTorito54 = _sceneManager->createEntity("Torito54","usb_torus.mesh");
		nodoTorito54->attachObject(entTorito54);
		nodoTorito54->scale(0.06f,0.06f,0.06f);

		Ogre::SceneNode* nodoTorito64 = torreta4->createChildSceneNode();
		nodoTorito64->roll(Ogre::Degree(-90));
		nodoTorito64->pitch(Ogre::Degree(90));		
		nodoTorito64->translate(Ogre::Vector3(0.8, 5.4, 5.5));
		Ogre::Entity* entTorito64 = _sceneManager->createEntity("Torito64","usb_torus.mesh");
		nodoTorito64->attachObject(entTorito64);
		nodoTorito64->scale(0.06f,0.06f,0.06f);

		Ogre::SceneNode* nodoTorito74 = torreta4->createChildSceneNode();
		nodoTorito74->roll(Ogre::Degree(-90));
		nodoTorito74->pitch(Ogre::Degree(90));		
		nodoTorito74->translate(Ogre::Vector3(-0.8, 5.4, 5.0));
		Ogre::Entity* entTorito74 = _sceneManager->createEntity("Torito74","usb_torus.mesh");
		nodoTorito74->attachObject(entTorito74);
		nodoTorito74->scale(0.06f,0.06f,0.06f);

		Ogre::SceneNode* nodoTorito84 = torreta4->createChildSceneNode();
		nodoTorito84->roll(Ogre::Degree(-90));
		nodoTorito84->pitch(Ogre::Degree(90));		
		nodoTorito84->translate(Ogre::Vector3(-0.8, 5.4, 5.5));
		Ogre::Entity* entTorito84 = _sceneManager->createEntity("Torito84","usb_torus.mesh");
		nodoTorito84->attachObject(entTorito84);
		nodoTorito84->scale(0.06f,0.06f,0.06f);
}