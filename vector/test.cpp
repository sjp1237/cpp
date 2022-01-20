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
//	string s1("hello");//ֱ�ӿ�������
//	string s2 = "hello";//�ȹ��죬�ڿ������죬���Ż�
//
//	vector<string> v3;
//	
//	v3.push_back(string("sjp"));
//	//�Ƽ���
//	v3.push_back("hello");//��������
//	v3.push_back("sjp");
//	vector_print(v3);
//
//	//�������ıȽ϶�����==���ߣ�=
//
//	//find��ʵ�����㷨�У��κ�����������ʹ������ֻ��Ҫ�����������������Ϳ����ڵ����������
//	//����ֵҲ��һ��������
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
//	//������ʧЧ
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
////���Բ�ʵ��string��vector<char>
////string��/0 ,vectorû��
////�ӿڹ����в��
//
//void test(vector<int> v)
//{
//	vector<int>::iterator it = v.begin();
//	cout << "�������������:";
//	while (it != v.end())//void test(vector<int> v)
//	{
//		vector<int>::iterator it = v.begin();
//		cout << "�������������:";
//		while (it != v.end())//�������������
//		{
//			cout << *it << ' ';	
//			it++;
//		}
//		cout << endl;
//
//		vector<int>::reverse_iterator rt = v.rbegin();
//		cout << "�������������:";
//		while (rt != v.rend())//�������������
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
//	cout << "�������������:";
//	while (rt != v.rend())//�������������
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
	//std::vector<int> v1;//�޲εĹ��캯��
	//std::vector<int> v2(10, 2);//���첢��ʼ��10��2
	//std::vector<int> v3(v2.begin(), v2.end());//����v2�ĵ�������ʼ��v3
	//vector<int> v4(v2);//����

	//v1.push_back(1);//β��
	//v1.push_back(2);//β��
	//v1.push_back(3);//β��
	//v1.push_back(4);//β��
	//v1.push_back(5);//β��

	////����3��λ�ã��������صĵ������洢��pos
	//vector<int>::iterator pos = find(v1.begin(), v1.end(), 3);
	//v1.insert(pos, 30);//��posλ��֮ǰ����30
	//reverse(v1.begin(), v1.end());//����vector
	////����3��λ�ã��������صĵ������洢��it
	//vector<int>::iterator it = find(v1.begin(), v1.end(), 4);
	//v1.erase(it);//ɾ��itλ�õ�����

	std::vector<int> v;
	cout << v.capacity() << endl;//���0
	cout << v.size() << endl;//���0
	v.reserve(10);//Ԥ��10��capacity�Ŀռ��С
	cout << v.capacity() << endl;//���10
	cout << v.size() << endl;//���0
	v.resize(20,10);//Ԥ��20������
	cout << v.capacity() << endl;// ���20
	cout << v.size() << endl;//���20
	std::vector<int> v1;
	std::vector<string> v2;
	std::vector<char> v3;


}

void test3()
{
	sjp::vector<int> v1;
	v1.push_back(1);//β��
	v1.push_back(2);//β��
	v1.push_back(3);//β��
	v1.push_back(4);//β��
	v1.push_back(5);//β��
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