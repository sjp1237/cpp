#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include"vector.h"
using std::cout;
using std::endl;
using namespace std;

template<class T>
void vector_print(std::vector<T> v)
{
	typename std::vector<T>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << ' ';
		it++;
	}
	cout << endl;

}

template<class T>
void vector_print(sjp::vector<T> v)
{
	typename sjp::vector<T>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << ' ';
		it++;
	}
	cout << endl;

}

//void test_vector1()
//{
//	std::vector<int> v1(10, 0);
//	std::vector<int>v2(v1.begin(), v1.end());
//	std::vector<int>::iterator it = v2.begin();
//
//	vector_print(v2);
//
//
//	string s1("hello");//直接拷贝构造
//	string s2 = "hello";//先构造，在拷贝构造，再优化
//
//	vector<string> v3;
//	
//	v3.push_back(string("sjp"));
//	//推荐的
//	v3.push_back("hello");//匿名对象
//	v3.push_back("sjp");
//	vector_print(v3);
//
//	//迭代器的比较都是用==或者！=
//
//	//find是实现再算法中，任何容器都可以使用它，只需要传迭代器给它，它就可以在迭代区间查找
//	//返回值也是一个迭代器
//
//
//
//}

//void test_vector()
//{
//	vector<int> v1;
//	v1.push_back(2);
//	v1.push_back(3);
//	v1.push_back(4);
//	v1.push_back(5);
//	v1.push_back(6);
//	vector<int>::iterator pos=find(v1.begin(), v1.end(),3);
//	if (pos != v1.end())
//	{
//		v1.erase(pos);
//	}
//	//迭代器失效
//
//	vector<int>::iterator it = v1.begin();
//	while (it != v1.end())
//	{
//		if (*it % 2 == 0)
//		{
//			v1.erase(it);
//		}
//		it++;
//	}
//
//
//}
//
////可以不实现string和vector<char>
////string有/0 ,vector没有
////接口功能有差别
//
//void test(vector<int> v)
//{
//	vector<int>::iterator it = v.begin();
//	cout << "正向迭代器遍历:";
//	while (it != v.end())//void test(vector<int> v)
//	{
//		vector<int>::iterator it = v.begin();
//		cout << "正向迭代器遍历:";
//		while (it != v.end())//正向迭代器遍历
//		{
//			cout << *it << ' ';	
//			it++;
//		}
//		cout << endl;
//
//		vector<int>::reverse_iterator rt = v.rbegin();
//		cout << "反向迭代器遍历:";
//		while (rt != v.rend())//反向迭代器遍历
//		{
//			cout << *rt << ' ';
//			rt++;
//		}
//		cout << endl;
//	}
//	{
//		cout << *it << ' ';
//		it++;
//	}
//	cout << endl;
//
//	vector<int>::reverse_iterator rt = v.rbegin();
//	cout << "反向迭代器遍历:";
//	while (rt != v.rend())//反向迭代器遍历
//	{
//		cout << *rt << ' ';
//		rt++;
//	}	
//	cout << endl;
//}


void test_myvector1()
 {
	sjp::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	sjp::vector<int>:: iterator pos=find(v.begin(), v.end(), 3);
	v.insert(pos, 30);
	sjp::vector<int>::iterator pis = find(v.begin(), v.end(), 3);
	v.erase(pis);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	v.pop_back();
	v.pop_back();
	v.pop_back();
	v.pop_back();
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
}

void test2()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(10);
	v.push_back(4);
    vector<int>::iterator pos = find(v.begin(), v.end(), 2);
	v.insert(pos,10);
	v.insert(pos, 20);
}

void test3(vector<int> v)
{
	vector<int>::iterator it = v.begin();
	while (it!=v.end())
	{
		if (*it % 2 == 0)
		{
			v.erase(it);
	
		}
		it++;
	}
	for (int i = 0; i < v.size(); i++)
	{

	}
}

void test_myvector2()
{
	sjp::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	sjp::vector<int> v2;
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	v1 = v2;
	//vector_print(v1);
	//vector_print(v2);
}

void test_myvector3()
{
	sjp::vector<int>v1(2,10);
	vector_print(v1);
	sjp::vector<int>v2(v1.begin(), v1.end());
	vector_print(v2);


		
}

void test1()
{
	//std::vector<int> v1;//无参的构造函数
	//std::vector<int> v2(10, 2);//构造并初始化10个2
	//std::vector<int> v3(v2.begin(), v2.end());//利用v2的迭代器初始化v3
	//vector<int> v4(v2);//拷贝

	//v1.push_back(1);//尾插
	//v1.push_back(2);//尾插
	//v1.push_back(3);//尾插
	//v1.push_back(4);//尾插
	//v1.push_back(5);//尾插

	////查找3的位置，并将返回的迭代器存储在pos
	//vector<int>::iterator pos = find(v1.begin(), v1.end(), 3);
	//v1.insert(pos, 30);//在pos位置之前插入30
	//reverse(v1.begin(), v1.end());//逆置vector
	////查找3的位置，并将返回的迭代器存储在it
	//vector<int>::iterator it = find(v1.begin(), v1.end(), 4);
	//v1.erase(it);//删除it位置的数据

	std::vector<int> v;
	cout << v.capacity() << endl;//输出0
	cout << v.size() << endl;//输出0
	v.reserve(10);//预留10个capacity的空间大小
	cout << v.capacity() << endl;//输出10
	cout << v.size() << endl;//输出0
	v.resize(20,10);//预留20个数据
	cout << v.capacity() << endl;// 输出20
	cout << v.size() << endl;//输出20
	std::vector<int> v1;
	std::vector<string> v2;
	std::vector<char> v3;


}

void test3()
{
	sjp::vector<int> v1;
	v1.push_back(1);//尾插
	v1.push_back(2);//尾插
	v1.push_back(3);//尾插
	v1.push_back(4);//尾插
	v1.push_back(5);//尾插
	sjp::vector<int>::iterator pos = find(v1.begin(), v1.end(), 3);
	v1.insert(pos, 10);

}

int main()
{

	/*vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);*/
	//test(v);
	test1();


	return 0;
}