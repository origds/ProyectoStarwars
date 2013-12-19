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

	void initTorreta(Ogre::SceneManager* _sceneManager);
};