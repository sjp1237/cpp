#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
//给定两个排序后的数组 A 和 B，其中 A 的末端有足够的缓冲空间容纳 B。 编写一个方法，将 B 合并入 A 并排序。
//初始化 A 和 B 的元素数量分别为 m 和 n。

class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        //定义3个指针，一个指向数组A有效数据的结尾，一个指向数组B有效数据的结尾
        //一个指向A数组的结尾
        int end1 = m - 1, end2 = n - 1, end3 = A.size() - 1;
        while (end1 >= 0 && end2 >= 0)
        {
            //将较大的值插入到A的结尾
            if (A[end1] > B[end2])
            {
                A[end3] = A[end1];
                end1--;
            }
            else
            {
                A[end3] = B[end2];
                end2--;
            }
            end3--;
        }
        //将B剩下的值插入到A中
        while (end2 >= 0)
        {
            A[end3] = B[end2];
            end2--;
            end3--;
        }
    }
};

void test()
{
    vector<int> A;
    A.resize(6);
    vector<int> B;
}
int main()
{
    test();
    return 0;
}
