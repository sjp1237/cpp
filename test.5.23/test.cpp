#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdio.h>

//using namespace std;

//namespaced定义一个域  解决c语言命名冲突的问题
//定义变量时不能使用关键字

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



//c++库为了防止命名冲突，就把库里面的东西都定义在一个std的命名空间里


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
//	//自动遍历，依次把arr中的值赋值给e，直到结束
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
//	TestFunc(); // 没有传参时，使用参数的默认值
//	TestFunc(10); // 传参时，使用指定的实参
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
//	//不是把r变成b的别名，而是把b的值赋值给r
//	r = b;
//	
//	return 0;
//}


//int main()
//{
//	const int a = 0;
//	int& ra = a;//ra引用a，属于权限放大，不行
//
//	int b = 10;
//	const int& rb = b;//rb引用是属于权限缩小，所以可以
//
//	int c = 10;
//	double d = 1.11;
//	d = c;//发生隐式类型转化过程，中间创建一个double类型的临时变量
//	double& rc = c;//rc引用c时，也会发生隐式类型转换
//	const double& rc = c;//临时变量具有常性，就是只读不能写 ，所以加一个const即可
//	
//	return 0;
//}

//传引用返回，返回的是c的拷贝


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
//	// 以值作为函数参数
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//	// 以引用作为函数参数
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//	// 分别计算两个函数运行结束后的时间
//	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
//	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
//}
//
//#include <time.h>
//struct A { int a[10000]; };
//A a;
//// 值返回
//A TestFunc1()
//{
//	return a;
//}
//// 引用返回
//A& TestFunc2() 
//{
//	return a;
//}
//void TestReturnByRefOrValue()
//{
//	// 以值作为函数的返回值类型
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc1();
//	size_t end1 = clock();
//	// 以引用作为函数的返回值类型
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc2();
//	size_t end2 = clock();
//	// 计算两个函数运算完成之后的时间
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
//	//在语法上ra是a的别名，ra和a共用一块空间
//	int& ra = a;
//	ra = 20;
//
//	//在语法上，pa是指针变量，开了4个字节的空间大小，存储a的地址
//	int* pa = &a;
//	*pa = 20;
//
//	return 0;
//}


//c语言为了避免小函数建立栈帧消耗，-》提供了宏函数，预处理展开。

//a.宏函数不支持调试
//b.宏函数语法复杂，容易出错
//c.没有类型安全的检查


//#define add(x,y) ((x)+(y))
//	
//int main()
//{
//	int c = add(1, 2);
//	cout << c;
//	return 0;
//}



//c++推荐频繁调用的小函数，定义成inline，会在调用的地方展开，没有栈帧的开销
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
//	auto b = a;//类型声明auto，可以根据a的类型推导出b的类型
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
//	auto c = 3, d = 4.0; // 该行代码会编译失败，因为c和d的初始化表达式类型不同
//	
//	auto e;//无法通过编译，auto在定义变量时必须初始化该变量
//	return 0;
//}


// 此处代码编译失败，auto不能作为形参类型，因为编译器无法对a的实际类型进行推导
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
//	//自动遍历，依次把arr中的值赋值给e，直到结束
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




