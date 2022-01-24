#define _CRT_SECURE_NO_WARNINGS 1
#include"Sort.h"


//插入排序
void InsterSort(int* a, int n)
{
	//有序序列从0-1，要插入的数据从n-1
	for (int i = 0; i < n - 1; i++)
	{
		int end=i;
		int tmp =a[end+1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}	
		}
		a[end + 1] = tmp;
	}
}


void Sort(int* a, int left, int right)
{
	int keyi = a[left];
	int prev = a[left];
	int cur = a[left+1];
	while (cur <= right )
	{
		if (a[cur] < a[keyi])
		{
			prev++;
			int tmp = a[cur];
			a[cur] = a[prev];
			a[prev] = tmp;
		}
			cur++;
	}
}

//快速排序
int GetMidIndex(int* a, int left, int right)
{
	int mid = left + (right - left) / 2;
	if (a[mid] > a[left] && a[mid] < a[right] ||
		a[mid] > a[right] && a[mid] < a[left])
		return right;
	else if (a[left] > a[mid] && a[left]<a[right] || a[left]>a[right] && a[left] < a[mid])
		return left;
	else
		return mid;

}
void swap(int* s1, int* s2)
{
	int tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}


int  PartSort(int* a,int begin,int end)
{
	int keyi = GetMidIndex(a,begin,end);
	int left = begin;
	int right = end;
	while (left < right)
	{
		while (left<right&&a[right] >= a[keyi])
		{
			--right;
		}
		while (left<right&&a[left] <= a[keyi])
		{
			++left;
		}
		swap(&a[left], &a[right]);
	}
	swap(&a[left], &a[keyi]);
	return left;
}

void QuickSort(int*a,int begin,int end)
{
	if (begin >= end)
		return;
	int keyi = PartSort(a, begin, end);
	QuickSort(a, begin, keyi - 1);
	QuickSort(a, keyi + 1, end);
}


//冒泡排序
void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		int i = 0;
		for (int j = 0; j < n-i-1; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(&a[j], &a[j + 1]);
				i = 1;
			}
		}
		if (i == 0)
			break;
	}
}


//归并排序
void _Merge(int* a,int* tmp, int begin1, int end1, int begin2, int end2)
{
	int i = begin1;
	//先定义j，不然j在下面for循环定义就不是起始的begin1
	int j = begin1;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
			tmp[i++] = a[begin1++];
		else
			tmp[i++] = a[begin2++];
	}
	while (begin1 <= end1)
		tmp[i++] = a[begin1++];
	while (begin2 <= end2)
		tmp[i++] = a[begin2++];
	for (; j <= end2; j++)
	{
		a[j] = tmp[j];
	}
}
//递归版
void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);
	_Merge(a, tmp, left, mid, mid + 1, right);
	
}

//非递归版
void MergeSort1(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		printf("malloc fail!\n");
		exit(-1);
	}
	int gap = 1;
	//如果gap大于n/2,小于n，则为最后一次归并
	while (gap <n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i, end1 = i + gap - 1, begin2 = i + gap, end2 = i + (2 * gap) - 1;
			//在最后一个小组归并时，第二个小区间步存在，或者第一个小区间不够gap个，则不需要再归并
			if (begin2 > n)
				break;
			//在最后一个小组归并时，第一个小区间存在，第二个小区间不够gap个
			if (end2 >= n-1)
				end2 = n-1 ;
			_Merge(a, tmp, begin1, end1, begin2, end2);
		}
		gap *= 2;
	}


}


void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		printf("malloc fail!\n");
		exit(-1);
	}
	_MergeSort(a, 0, n-1 , tmp);
}


void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//希尔排序
void ShellSort(int* a, int n)
{
	//gap>1为预排序
	//gap=1时为插入排序
	    int gap=n;
		while (gap > 1)//不能等于1
		{
			//如果n=6，则你除以3为2，2再去除以3为0，相当于没有排序，所以gap得+1
			gap = gap / 3 +1;
			for (int i = 0; i < n - gap; i++)
			{
				int end = i;
				int tmp = a[end + gap];
				//插入排序
				//假设有一段有序数组，然后把一个数插入进去
				while (end >= 0)
				{
					if (a[end] > tmp)
					{
						swap(&a[end], &a[end + gap]);
						end -= gap;
					}
					else
						break;
				}
				a[end + gap] = tmp;
			}
		}
}


x

void AdjustDown(int* a, int parent,int n)
{
	int child = 2 * parent + 1;
	while (child <= n-1)
	{
		if (child + 1<=n-1 && a[child] < a[child + 1])
			child = child + 1;
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = 2 * parent + 1;
		}
		
		else
		{
			break;
		}
	}
}


void Stacksort(int* a, int n)
{
	for (int i = (n- 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, i, n);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		end--;
		AdjustDown(a, 0, end+1);
	}
}










