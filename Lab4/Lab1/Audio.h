#pragma once
#include <irrkLang\irrKlang.h>

using namespace irrklang;
class Audio
{
public:
	Audio();
	~Audio();

	ISoundEngine* GetEngine();


private:
	ISoundEngine* soundEngine;
};

