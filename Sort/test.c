#pragma once
#include"Sort.h"

int main()
{
	int a[] = { 4,7,3,8,2,1,9,10,6,5 };
	int sz = sizeof(a) / sizeof(a[0]);
	InsterSort(a,sz);
	for (int i = 0; i <sz; i++)
	{
		printf("%d ", a[i]);
	}

	return 0;
}
