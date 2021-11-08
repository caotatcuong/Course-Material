#include "Ball.h"


bool Ball::InIt(int x, int y, string file)
{
	if (sprite.InIt(x,y,file)==false)//Load file
	{
		sprite.setOrigin(10, 10);//Set vị tri bóng
		return false;
	}
}

void Ball::Move(double u, double v)
{
	sprite.Move(u, v);//Ham di chuyển bóng
}

void Ball::ResetMove(double& u, double& v)
{
	srand((int)time(0));//Random hướng bóng
	u = pow(-1,rand());
	v = pow(-1, rand());
}

void Ball::draw(RenderWindow& window)
{
	sprite.draw(window);//Vẽ bóng
}

void Ball::setPosition(double x, double y)
{
	sprite.setPosition(x, y);//Set vị tri bóng
}

Vector2f Ball::getPosition()
{
	return sprite.getPosition();//Lay vị trí bóng
}

void Ball::HandlingCollisions(Vector2f d, Vector2f d2, double& u, double& v)
{
	if (d.x < 1 || d.x > 570)
	{
		u = -u;//Đổi hướng bóng
		vacham.soundPlay(vacham.amvachamcanhban);//Âm thanh va chạm cạnh bàn

	}
	if (d.y >= 7 && d.y <= 11)
	{
		v = -v;//Đổi hướng bóng
		vacham.soundPlay(vacham.amvachamcanhban);//Âm thanh va chạm cạnh bàn
	}

	if (d.y >= 752 && d.y <= 757 && d.x >= d2.x -70 && d.x <= d2.x + 90) {//Tang toc do trai banh khi va cham vao thanh do cua nguoi choi.
		if (u < 0) {
			u -= tocdo;//Tăng tốc bóng
		}
		else {
			u += tocdo;//Tăng tốc bóng
		}
		if (v < 0) {
			v -= tocdo;//Tăng tốc bóng
		}
		else {
			v += tocdo;//Tăng tốc bóng
		}
		v = -v;//Đổi hướng bóng
		vacham.soundPlay(vacham.amvachamthanhdo);//Âm thanh va chạm thanh đỡ
	}
}



