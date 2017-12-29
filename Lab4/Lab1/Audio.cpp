#include "Audio.h"
#include <iostream>


Audio::Audio()
{
}


Audio::~Audio()
{
	delete soundEngine;
}

ISoundEngine * Audio::GetEngine()
{
	
	if (soundEngine == nullptr)
	{
		std::cout << "No Sound Engine" << std::endl;
		return nullptr;
	}
	if (soundEngine != nullptr)
	{
		return soundEngine;
	}
}
