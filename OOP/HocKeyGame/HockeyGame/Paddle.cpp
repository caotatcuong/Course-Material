#include "Paddle.h"

bool Paddle::InIt(int x, int y, string file)
{
	if (paddle.InIt(x, y, file) == false)//load file
	{
		return false;
	}
}

void Paddle::setOrigin(int x, int y)
{
	paddle.setOrigin(x, y);//set vị trí thanh đỡ
}

Vector2f Paddle::getPosition()
{
	return paddle.getPosition();//lấy vị trí thanh đỡ
}

void Paddle::draw(RenderWindow& window)
{
	paddle.draw(window);//vẽ thanh dỡ lên màn hình
}

void Paddle::MovePlayer(int& dx)
{
	if (Keyboard::isKeyPressed(Keyboard::A)) {//Nhấn phím A thì thanh đỡ di chuyển sang trái
		if (dx >= bienTrai) {
			dx -= 2;//tốc độ di chuyển của thanh đỡ
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::D)) {//Nhấn phím D thì thanh đỡ di chuyển sang phải
		if (dx <= bienPhai) {
			dx += 2;//tốc độ di chuyển của thanh đỡ
		}
	}
}

void Paddle::MoveAI(int& dx, Vector2f muctieu, double v, Vector2f item)
{
	if ((muctieu.y > 400) && (v > 0))//điều kiện thanh đỡ di chuyển đỡ bóng thanh sẽ ưu tiên đỡ bóng hơn là ăn item
	{
		if (dx > muctieu.x)//Điều kiện để chạy theo mục tiêu
		{
			if (dx >= bienTrai)
			{
				dx -= 2;//tốc độ di chuyển của thanh đỡ
			}
		}
		if (dx < muctieu.x)//Điều kiện để chạy theo mục tiêu
		{
			if (dx <= bienPhai) 
			{
				dx += 2;//tốc độ di chuyển của thanh đỡ
			}
		}
	}	
	else
	{
		if (dx > item.x)
		{
			if (dx >= bienTrai)//Điều kiện để chạy theo mục tiêu
			{
				dx -= 2;//tốc độ di chuyển của thanh đỡ
			}
		}
		if (dx < item.x)//Điều kiện để chạy theo mục tiêu
		{
			if (dx <= bienPhai)
			{
				dx += 2;//tốc độ di chuyển của thanh đỡ
			}
		}
	}
}
