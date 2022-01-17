#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include"AVLtree.h"
int main()
{
	//, 26, 18, 14, 15 
	int arr[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15};
	AVLTree<int, int> at;
	for (auto num : arr)
	{
		at.insert(make_pair(num, num));
	}

	at.erase(18);
	at.erase(26);


	return 0;
}