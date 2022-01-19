#define _CRT_SECURE_NO_WARNINGS 1
#include"RBTree.h"
#include<stdlib.h>
#include<vector>
#include<time.h>

void test()
{
	time(0);
	//{4,1,6,8,3,7,23,45,36};
	//{ 12,432,5,65,32,43,253,654,43232,34};
	int arrs[] = { 12,432,5,65,32 ,43 ,253,654,43232 };
	RBTree<int, int> rbt;
	vector<int> v;
	for (int i = 0; i < 1000; i++)
	{
		int e = rand();
		//cout << e << endl;
		v.push_back(e);
	}
	for (auto arr : v)
	{
		rbt.insert(make_pair(arr,arr));
	}
	//rbt.Inorder();
	cout << rbt.checkRBTree() << endl;
	return;
}
int main()
{
	test();
	return 0;
}