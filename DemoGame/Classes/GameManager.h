#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__


class GameManager
{
public:
	static GameManager *sharedGameManager();
	static void purgeSharedGameManager();

	bool init();

	enum SceneId
	{
		SCENE_PLAY,
	};

	void runSceneWithId(SceneId id);


protected:
	GameManager();
	~GameManager();

private:
	static GameManager *mSharedGameManager;

};


#endif

