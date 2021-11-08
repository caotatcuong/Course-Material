#pragma once
#include <SFML/Audio.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class sound
{
private:
	SoundBuffer soundBuffer;
	Sound SOUND;
public:
	string amvachamthanhdo = "Sound\\vachamthanhdo.ogg";//Âm thanh va chạm thanh đỡ
	string amvachamcanhban = "Sound\\vachamcanhban.ogg";//Âm thanh va chạm canh bàn
	string win1 = "Sound\\win1.ogg";//Âm thanh chiến thắng
	string win = "Sound\\win.ogg";//Âm thanh chiến thắng
	string lose1 = "Sound\\lose1.ogg";//Âm thanh thua cuộc
	string lose = "Sound\\lose.ogg";//Âm thanh thua cuộc
	string backgroundsound = "Sound\\background.ogg";//Âm thanh nền
	string choose = "Sound\\choose.ogg";//Âm thanh chọn menu
	string luckey = "Sound\\luckey.ogg";//Âm thanh ăn được vật phẩm may mắn
	string unLuckey = "Sound\\unLuckey.ogg";//Âm thanh ăn được vật phẩm không may mắn

	void soundPlay(string);//Phát âm thanh
};


