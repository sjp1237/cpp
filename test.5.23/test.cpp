#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdio.h>

//using namespace std;

//namespaced����һ����  ���c����������ͻ������
//�������ʱ����ʹ�ùؼ���

//void  swap(int& left, int& right)
//{
//	int tmp = left;
//	left = right;
//	right = tmp;
//}
//
//namespace A
//{
//	int i = 0;
//	int add(int a, int b)
//	{
//		return a + b;
//	}
//}

//namespace B
//{
//	int i = 1;
//	int add(int a, int b)
//	{
//		return a - b;
//	}
//}
//
//int main()
//{
//	printf("%d\n", i);
//
//	return 0;
//}


//namespace N2
//{
//	int a;
//	int b;
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//
//	namespace N3
//	{
//		int a=2;
//		int d;
//		int Sub(int left, int right)
//		{
//			return left - right;
//		}
//	}
//}



//c++��Ϊ�˷�ֹ������ͻ���Ͱѿ�����Ķ�����������һ��std�������ռ���


using namespace std;



//int main()
//{
//	int i = 1;
//	printf("%d\n", i);
//	cout << "abcdef"<<endl;
//	cout << 'a'<<'b'<<1<<endl;
//	cout << i;
//	return 0;
//}

//void TestFun1(int a = 1)
//{
//	cout << a << endl;
//
//}

//int main()
//{
//	int a = 10;
//	TestFun1(a);
//	TestFun1();
//}

//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6 };
//	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//	{
//		cout << arr[i]<<" ";
//	}
//	cout << endl;
//	//�Զ����������ΰ�arr�е�ֵ��ֵ��e��ֱ������
//	for (auto& e : arr)
//	{
//		e *= 2;
//	}
//	for (auto e : arr)
//	{
//		cout << e<<" " ;
//	}
//	cout << endl;
//
//	return 0;
//}


//void TestFunc(int a = 0) 
//{
//	cout << a << endl;
//}
//int main()
//{
//	TestFunc(); // û�д���ʱ��ʹ�ò�����Ĭ��ֵ
//	TestFunc(10); // ����ʱ��ʹ��ָ����ʵ��
//}



//
//int main()
//{
//	double a= add(1.0, 2.0);
//	int b= add(1, 2);
//	int c=add(1, 2, 3);
//	return 0;
//}

//
//void TestFunc(int a = 10, int b = 20, int c = 30) 
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl<<endl;
//	
//}


//int main()
//{
//	TestFunc();
//	TestFunc(1);
//	TestFunc(1, 2);
//	TestFunc(1, 2,3);
//	return 0;
//}


//int add(int x, int y)
//{
//	return x + y;
//}
//
//int add(int x, int y, int z=10)
//{
//	return x + y + z;
//}




//int main()
//{
//	int a = 10;
//	int b = 10;
//	int& ra = a;
//	int& ra = b;
//	return 0;
//}

//int& Count()
//{
//	static int n = 0;
//		n++;
//	return n;
//}

//int main()
//{
//	const int a = 10;
//	int b = 20;
//	int& r = a;
//	//���ǰ�r���b�ı��������ǰ�b��ֵ��ֵ��r
//	r = b;
//	
//	return 0;
//}


//int main()
//{
//	const int a = 0;
//	int& ra = a;//ra����a������Ȩ�޷Ŵ󣬲���
//
//	int b = 10;
//	const int& rb = b;//rb����������Ȩ����С�����Կ���
//
//	int c = 10;
//	double d = 1.11;
//	d = c;//������ʽ����ת�����̣��м䴴��һ��double���͵���ʱ����
//	double& rc = c;//rc����cʱ��Ҳ�ᷢ����ʽ����ת��
//	const double& rc = c;//��ʱ�������г��ԣ�����ֻ������д �����Լ�һ��const����
//	
//	return 0;
//}

//�����÷��أ����ص���c�Ŀ���


//int& add(int a, int b)
//{
//	static int c = a + b;
//	return c;
//}
//
//int main()
//{
//	int& ret = add(1, 2);
//	cout << ret;
//	return 0;
//}

//#include <time.h>
//struct A { int a[10000]; };
//void TestFunc1(A a) 
//{
//}
//void TestFunc2(A& a)
//{
//}
//
//void TestRefAndValue()
//{
//	A a;
//	// ��ֵ��Ϊ��������
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//	// ��������Ϊ��������
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//	// �ֱ���������������н������ʱ��
//	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
//	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
//}
//
//#include <time.h>
//struct A { int a[10000]; };
//A a;
//// ֵ����
//A TestFunc1()
//{
//	return a;
//}
//// ���÷���
//A& TestFunc2() 
//{
//	return a;
//}
//void TestReturnByRefOrValue()
//{
//	// ��ֵ��Ϊ�����ķ���ֵ����
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc1();
//	size_t end1 = clock();
//	// ��������Ϊ�����ķ���ֵ����
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc2();
//	size_t end2 = clock();
//	// �������������������֮���ʱ��
//	cout << "TestFunc1 time:" << end1 - begin1 << endl;
//	cout << "TestFunc2 time:" << end2 - begin2 << endl;
//}

//int main()
//{
//	TestReturnByRefOrValue();
//	return 0;
//}


//int main()
//{
//	int a = 10;
//
//	//���﷨��ra��a�ı�����ra��a����һ��ռ�
//	int& ra = a;
//	ra = 20;
//
//	//���﷨�ϣ�pa��ָ�����������4���ֽڵĿռ��С���洢a�ĵ�ַ
//	int* pa = &a;
//	*pa = 20;
//
//	return 0;
//}


//c����Ϊ�˱���С��������ջ֡���ģ�-���ṩ�˺꺯����Ԥ����չ����

//a.�꺯����֧�ֵ���
//b.�꺯���﷨���ӣ����׳���
//c.û�����Ͱ�ȫ�ļ��


//#define add(x,y) ((x)+(y))
//	
//int main()
//{
//	int c = add(1, 2);
//	cout << c;
//	return 0;
//}



//c++�Ƽ�Ƶ�����õ�С�����������inline�����ڵ��õĵط�չ����û��ջ֡�Ŀ���
//void Swap(int& x, int& y)
//{
//	int tmp = x;
//	x = y;
//	y = tmp;
//}



inline int Add(int x, int y)
{
	return x + y;
}


//int main()
//{
//	int a = 10;
//	auto px = &a;
//	auto* pa = &a;
//	auto b = a;//��������auto�����Ը���a�������Ƶ���b������
//	int& c = a;
//	auto y = c;
//	cout << typeid(b).name() << endl;
//	cout << typeid(y).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(pa).name() << endl;
//	cout << typeid(px).name() << endl;
//
//
//
//	return 0;
//}


//int main()
//{
//	
//	auto a = 1, b = 2;
//	auto c = 3, d = 4.0; // ���д�������ʧ�ܣ���Ϊc��d�ĳ�ʼ�����ʽ���Ͳ�ͬ
//	
//	auto e;//�޷�ͨ�����룬auto�ڶ������ʱ�����ʼ���ñ���
//	return 0;
//}


// �˴��������ʧ�ܣ�auto������Ϊ�β����ͣ���Ϊ�������޷���a��ʵ�����ͽ����Ƶ�
//void TestAuto(auto a)
//{
//
//}

//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	
//	for (auto& e : arr)
//	{
//		e *= 2;
//	}
//	//�Զ����������ΰ�arr�е�ֵ��ֵ��e��ֱ������
//	for (auto e : arr)
//	{
//		cout << e << ' ';
//	}
//	return 0;
//}

//
//void test(int* i)
//{
//	cout << "f(int*)" << endl;
//}
//
//void test(int i)
//{
//	cout << "f(int)" << endl;
//}
//
//int main()
//{
//	test(NULL);
//	return 0;
//}


int main()
{
	int i = 0;
	char s[] = "abcdef";
	cin >> i>>s;
	cout << i<<endl<<s;
	return 0;
}




