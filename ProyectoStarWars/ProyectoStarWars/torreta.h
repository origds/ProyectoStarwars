class Torreta {

	float rotx;
	float roty;
	float rotz;
	float posx;
	float posy;
	float posz;

public:
	Torreta(float rx, float ry, float rz, float px, float py, float pz);
	~Torreta();

	void initTorreta1(Ogre::SceneManager* _sceneManager);
	void initTorreta2(Ogre::SceneManager* _sceneManager);
	void initTorreta3(Ogre::SceneManager* _sceneManager);
	void initTorreta4(Ogre::SceneManager* _sceneManager);

};