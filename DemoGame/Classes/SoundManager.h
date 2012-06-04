#ifndef __SOUND_MANAGER_H__
#define __SOUND_MANAGER_H__


class SoundManager
{
public:
	static SoundManager *sharedSoundManager();
	static void purgeSharedSoundManager();

	void PlayMusic();
	void StopMusic();

protected:
	SoundManager();
	~SoundManager();

	bool init();

private:
	static SoundManager *mSharedSoundManager;

};


#endif

