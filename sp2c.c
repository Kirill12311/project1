#include "stdio.h"
int main() {
	short mas[10] = {10, -2, 3, 3, 2, -7, 4, -6, 0, 0 };
	short summ = 0;
	for (int i = 0; i < 10; i++) {
		if(mas[i] < 0)
		{
		  summ += -1 * mas[i];
		}
		else
		{
		summ += mas[i];
		}
	}
	printf("%d\n", summ);
	return 0;
}
