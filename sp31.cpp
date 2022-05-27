#include <iostream>
#include <ctime>
using namespace std;
int main()
{
	srand (time(0));
	int array[5][5];
	int array2[5][5];
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			array[i][j] = rand() % 10;
			cout  << array[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			array2[0][j] = array[j][0];
			array2[1][j] = array[j][1];
			array2[2][j] = array[j][2];
			array2[3][j] = array[j][3];
			array2[4][j] = array[j][4];
		}
	}
	cout << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << array2[i][j] << " ";
		}
		cout << endl;
	}
}
