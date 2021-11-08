#include "NODE.h"

int main()
{
	int n;
	NODE* Root = NULL;
	do
	{
		cout << "0. Thoat.\n";
		cout << "1. Nhap gia tri cho cac node.\n";
		cout << "2. Duyet cay.\n";
		cout << "3. Tim phan tu.\n";
		cout << "4. Xoa node.\n";
		cout << "Nhap lua chon: ";
		cin >> n;
		switch (n)
		{
			case 1:
			{ 
				int m;
				cout << "Nhap so luong phan tu: ";
				cin >> m;
				int* a = new int[m];
				for (int i = 0; i < m; i++)
				{
					cout << "Nhap gia tri phan tu thu " << i + 1 << " : ";
					cin >> a[i];
					insertNode(Root, a[i]);
				}	
				break;
			}
			case 2:
			{
				LNR(Root);
				break;
			}
			case 3:
			{
				int value = 0;
				cout << "Nhap gia tri can tim: ";
				cin >> value;
				Search(Root, value);
				break;
			}
			case 4:
			{
				int value = 0;
				cout << "Nhap gia tri can xoa: ";
				cin >> value;
				Remove(Root, value);
				Remove(Root, value);
				Remove(Root, value);
				break;
			}
		default:
			break;
		}
	} while (n >= 0 && n <= 4);
	system("pause");
	return 0;
}


