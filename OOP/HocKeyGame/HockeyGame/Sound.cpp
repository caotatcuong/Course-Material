#include "Sound.h"

void sound::soundPlay(string a)
{
	soundBuffer.loadFromFile(a);//load file
	SOUND.setBuffer(soundBuffer);//set loại ăm thanh
	SOUND.play();//Phát âm thanh
}
