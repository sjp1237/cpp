#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
#define STR "hehe"
//#define print printf("hehe\n")

//#define print(data,format) printf("the value of "  #data   " is "   format  "\n" ,data)
//void test2()
//{
//	int a = 10;
//	float f = 1.00;
//	print(f, "%f");
//	print(a,"%d");
//	//printf("the value a is %d ", a);
//	
//	//	//printf("%s\n ", __FILE__);
////	printf("%d\n", __LINE__);
////	printf("%s\n ", __DATE__);
////	printf("%s\n ", __TIME__);
////	printf("%s\n", STR);
//	
//
//}
void test1()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPrint(&s);
	SeqListPushFront(&s, 0);
	SeqListPushFront(&s, -1);
	SeqListPrint(&s);
	SeqListInsert(&s, 2, 3);
	SeqListPrint(&s);
	SeqListInsert(&s, 3, 4);
	SeqListPrint(&s);
	SeqListErase(&s, 3);
	SeqListPrint(&s);

	SeqListDestory(&s);


}
//写一个函数返回参数二进制中 1 的个数。
//比如： 15    0000 1111    4 个 1
//int cont_one_bit(int n)
//{
//	int count = 0;
//	int i = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if (((n >> i) & 1) == 1)
//		{
//			count++;
//
//		}
//	}
//	return count;	
//}


//void test3()
//{
//	int i = 0;
//	scanf("%d", &i);
//	int ret=cont_one_bit(i);
//	printf("%d\n", ret);
//
//}
//打印整数二进制的奇数位和偶数位
//作业内容
//获取一个整数二进制序列中所有的偶数位和奇数位，分别打印出二进制序列
//void printbit(int n)
//{
//	int i = 0;
//	printf("奇数位：");
//	for (i = 31; i >= 1; i -= 2)
//	{
//		if (((n >> i) & 1) == 1)
//		{
//			printf("1 ");
//		}
//		else
//		{
//			printf("0 ");
//		}
//	}
//	printf("\n");
//	printf("偶数位：");
//	for (i = 30; i >= 0; i -= 2)
//	{
//		if (((n >> i) & 1) == 1)
//		{
//			printf("1 ");
//		}
//		else
//		{
//			printf("0 ");
//		}
//	}
//	printf("\n");
//
//}
//void test4()
//{
//	int i = 0;
//	scanf("%d", &i);
//	printbit(i);
//}
 
//void test5()
//{
//	int i = 0;
//	int j = 0;
//	scanf("%d%d", &i, &j);
//	int ret = i | j;
//	int n = 0;
//	int count = 0;
//	for (n = 0; n < 32; n++)
//	{
//		if (((ret >> n) & 1) == 1)
//		{
//			count++;
//		}
//	}
//	printf("%d\n", count);
//}

//写一个宏，可以将一个整数的二进制位的奇数位和偶数位交换。
//#define SwapBit(n) ((n&(0X55555555))<<1)|((n&0xaaaaaaaa)>>1)
////void test6()
////{
////	int n = 10;
////	int i = SwapBit(n);
////	printf("%d\n", i);
////}
//一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。
//编写一个函数找出这两个只出现一次的数字。
//void Check_int(int* arr, int sz)
//{
//	//先找到这两个数的异或
//	int i = 0;
//	int ret = 0;
//	for (i = 0; i < sz; i++)
//	{
//		ret ^= arr[i];
//	}
//	//找出这两个数中一个1
//	int j = 0;
//	for (j = 0; j < 32; j++)
//	{
//		if ((ret >> j) & 1)
//		{
//			break;
//		}
//	}
//	int x = 0;
//	int y = 0;
//	int k = 0;
//	for (k = 0; k < sz; k++)
//	{
//		if (arr[k] >> j & 1)
//		{
//			x ^= arr[k];
//		}
//		else
//		{
//			y ^= arr[k];
//		}
//	}
//	printf("%d %d", x, y);
//}
//void test7()
//{
//	int arr[10] = { 2,2,4,4,5,8 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	Check_int(arr, sz);
//
//}

int main()
{
	test1();
	return 0;
}


