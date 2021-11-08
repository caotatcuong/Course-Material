#include "Header.h"

int main()
{
	fstream f;
	f.open("Result.txt", ios::out);
	float time_use;
	clock_t start, end;
	int x[5] = { 1000,5000,10000,30000,100000 };
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 7; k++)
			{
				int* a = new int[x[j]];
				Generate(a, x[j], i);
				start = clock();
				Sort(a, x[j], k);
				end = clock();
				delete[x[i]] a;
				f << (float)(end - start) / CLOCKS_PER_SEC << "\t";
			}
			f << "\n";
		}
	}	
	f.close();
}

