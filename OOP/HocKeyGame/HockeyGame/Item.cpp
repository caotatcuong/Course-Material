#include "Item.h"


Item::Item()
{
}

void Item::setItem(int n)
{
	switch (n) {
	case 1:// Vật phẩm nhân đôi điểm khi ăn gạch.
		InIt(random(30, 510), random(30, 500), "AssetGame\\x2.png");
		TYPE = 1;
		break;
	case 2:// Vật phẩm nhân 4 điểm khi ăn gạch.
		InIt(random(30, 510), random(30, 500), "AssetGame\\x4.png");
		TYPE = 2;
		break;
	case 3:// Cộng 1 lượt chơi.
		InIt(random(30, 510), random(30, 500), "AssetGame\\+1turn.png");
		TYPE = 3;
		break;
	case 4:// Cộng điểm trong khoảng 100 đến 300.
		InIt(random(30, 510), random(30, 500), "AssetGame\\+100.png");
		TYPE = 4;
		break;
	case 5:// Trừ điểm trong khoảng 100 đến 300.
		InIt(random(30, 510), random(30, 500), "AssetGame\\-200.png");
		TYPE = 5;
		break;
	case 6:// Làm cho thanh đỡ bị đơ.
		InIt(random(30, 510), random(30, 500), "AssetGame\\paralyze.png");
		TYPE = 6;
		break;
	case 7:// Làm trái banh di chuyển nhanh gấp đôi.
		InIt(random(30, 510), random(30, 500), "AssetGame\\rocket.png");
		TYPE = 7;
		break;
	case 8:// Làm thanh đỡ di chuyển ngược lại với phím bấm.
		InIt(random(30, 510), random(30, 500), "AssetGame\\poison.png");
		TYPE = 8;
		break;
	}
}

int Item::getType()
{
	return TYPE;
}

void Item::setType(int n)
{
	this->TYPE = n;
}

bool Item::InIt(int x, int y, string file)
{
	if (ITEM.InIt(x, y, file) == false)//load file
	{
		return false;
	}
}

void Item::setOrigin(int x, int y)
{
	ITEM.setOrigin(x, y);
}

int Item::random(int min, int max)
{
	srand((time(0) * time(0)));
	return min + rand() % (max + 1 - min);
}

void Item::setPosition(Item item)
{
	item.ITEM.setPosition(random(30, 510), random(30, 500));//Khởi tạo vị trí ngẫu nhiên
}

Vector2f Item::getPosition()
{
	return ITEM.getPosition();
}

void Item::draw(RenderWindow& window)
{
	ITEM.draw(window);
}

void Item::moveDown(float tocdo)// Vật phẩm di chuyển xuống.
{
	this->ITEM.Move(0, tocdo);
}

void Item::setItem()
{
	int test = random(1, 8);
	switch (test) {
	case 1:// Vật phẩm nhân đôi điểm khi ăn gạch.
		InIt(random(30, 510), random(30, 500), "AssetGame\\x2.png");
		TYPE = 1;
		break;
	case 2:// Vật phẩm nhân 4 điểm khi ăn gạch.
		InIt(random(30, 510), random(30, 500), "AssetGame\\x4.png");
		TYPE = 2;
		break;
	case 3:// Cộng 1 lượt chơi.
		InIt(random(30, 510), random(30, 500), "AssetGame\\+1turn.png");
		TYPE = 3;
		break;
	case 4:// Cộng điểm trong khoảng 100 đến 300.
		InIt(random(30, 510), random(30, 500), "AssetGame\\+100.png");
		TYPE = 4;
		break;
	case 5:// Trừ điểm trong khoảng 100 đến 300.
		InIt(random(30, 510), random(30, 500), "AssetGame\\-200.png");
		TYPE = 5;
		break;
	case 6:// Làm cho thanh đỡ bị đơ.
		InIt(random(30, 510), random(30, 500), "AssetGame\\paralyze.png");
		TYPE = 6;
		break;
	case 7:// Làm trái banh di chuyển nhanh gấp đôi.
		InIt(random(30, 510), random(30, 500), "AssetGame\\rocket.png");
		TYPE = 7;
		break;
	case 8:// Làm thanh đỡ di chuyển ngược lại với phím bấm.
		InIt(random(30, 510), random(30, 500), "AssetGame\\poison.png");
		TYPE = 8;
		break;
	}
}

void Item::setItemEffectLoop(int& score, int n, Ball& ball1, list<Block> lBlock, Vector2f d, double& u, double& v, font& f3, int& dx)
{
	list<Block>::iterator it;
	switch (n) {
	case 1:
		for (it = lBlock.begin(); it != lBlock.end(); it++) {
			if (d.y > it->top() - 10 && d.y < it->bottom() + 10 && d.x > it->left() - 10 && d.x < it->rigth() + 10) {//Điều kiện bóng va chạm vào gạch
				score += 10; // Nhân đôi điểm khi ăn gạch.
				f3.InIt(235, 820, "brushsbi.ttf", to_string(score));
				break;
			}
		}
		break;
	case 2:
		for (it = lBlock.begin(); it != lBlock.end(); it++) {
			if (d.y > it->top() - 10 && d.y < it->bottom() + 10 && d.x > it->left() - 10 && d.x < it->rigth() + 10) {//Điều kiện bóng va chạm vào gạch
				score += 30;// Nhân 4 điểm khi ăn gạch.
				f3.InIt(235, 820, "brushsbi.ttf", to_string(score));
				break;
			}
		}
		break;
	case 6:// Thanh đỡ đứng yên dù có ấn phím.
		if (Keyboard::isKeyPressed(Keyboard::A)) {
			dx += 2;
		}
		if (Keyboard::isKeyPressed(Keyboard::D)) {
			dx -= 2;
		}
		break;
	case 7:
		ball1.Move(u, v);// Banh di chuyển nhanh.
		break;
	case 8:// Thanh đỡ di chuyển ngược lại so với phím bấm nhập vào.
		if (Keyboard::isKeyPressed(Keyboard::A)) {
			if (dx <= bienPhai) {
				dx += 4;
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::D)) {
			if (dx >= bienTrai) {
				dx -= 4;
			}
		}
		break;
	}
}

void Item::setItemEffectNoLoop(int& score, int n, int& turn, font& f3, font& f4)
{
	switch (n) {
	case 3:
		turn += 1;// Cộng cho người chơi 1 lượt chơi.
		f4.InIt(110, 820, "brushsbi.ttf", to_string(turn));
		break;
	case 4:
		score += random(100, 300);// Cộng ngẫu nhiên 100 đến 300 điểm.
		f3.InIt(235, 820, "brushsbi.ttf", to_string(score));
		break;
	case 5:
		score -= random(100, 300);// Trừ nhẫu nhiên 100 đến 300 điểm.
		f3.InIt(235, 820, "brushsbi.ttf", to_string(score));
		break;
	}
}
