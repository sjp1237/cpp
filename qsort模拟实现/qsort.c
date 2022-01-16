#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>


void Print(int* arr[], int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}
//int cmp_int(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}

void Swap(char* p1, char* p2,size_t width)
{
	for (int i = 0; i < width; i++)
	{
		char tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
		p1++;
		p2++;
	}
}

void Bubble_sort(void* base, size_t num, size_t width, int cmp(const void* elem1, const void* elem2))
{
	for (int i = 0; i < num-1; i++)
	{
		for (int j = 0; j < num - i-1; j++)
		{
			if (cmp((char*)base + j * width, (char*)base + j * width+ width)>0 )
			{
				Swap((char*)base + j * width, (char*)base + j * width + width,width);
			}
		}
	}	
}

struct person
{
	int age;
	char ch;
};

int cmp_int(const void* e1, const void* e2)
{
	return ((struct person*)e1)->age - ((struct person*)e2)->age;
}

int cmp_char(const void* e1, const void* e2)
{
	return ((struct person*)e1)->ch - ((struct person*)e2)->ch;
}
int main()
{
	int arr[10] = { 0,4,6,3,7,2,8,5,9,1 };
	//void qsort( void *base, 
	//             size_t num,	
	//			   size_t width,
	//			   int (__cdecl *compare )(const void *elem1, const void *elem2 ) );
	//Bubble_sort(str, sz, sizeof(str[0]), cmp_int);
	struct person str[3] = { {20,'b'},{30,'c'},{25,'a'} };
	int sz = sizeof(str) / sizeof(str[0]);
	qsort(str, sz, sizeof(str[0]), cmp_char);
	
	Print(str, sz);
	return 0;
}


void test()
{
	int i = 0;
	char c = 'a';
	void* pi = &i;
	void* pc = &c;
	int* pd = pi;
}