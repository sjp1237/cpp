#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

using namespace std;


//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//	string _name ; // ����
//	string _sex;//�Ա�
//	int _age; // ����
//};
//
//class Student :public Person
//{
//
//protected:
//	int _stuid;//ѧ��
//};
//
//class Teacher :public Person
//{
//
//protected:
//	int _jobid;//����
//};
//
//void test1()
//{
//	Student s;
//	s._name = "����";
//	s._age = 15;
//	Teacher t;
//	t._name = "����";
//	t._age = 45;
//	s.Print();
//	t.Print();
//}


//class Person
//{
//public:
//	void Print()
//	{
//		cout << _name << endl;
//	}
//protected:
//	string _name; // ����
//private:
//	int _age; // ����
//};
//
//class Student : public Person
//{
//	void test()
//	{
//		cout << _name << endl;//��ȷ��_name�Ǹ����protected�ĳ�Ա
//		cout << _age << endl;//����_age�Ǹ����private�ĳ�Ա,���ܱ��������
//	}
//
//
//protected:
//	int _stunum; // ѧ��
//};

//class Person
//{
//public:
//	string _name; // ����
//	string _sex; // �Ա�
//	int _age; // ����
//};
//
//class Student : public Person
//{
//public:
//	int _No; // ѧ��
//};
//
//void test2()
//{
//	Student s;
//	s._name = "����";
//	s._sex = "��";
//	s._age = 20;
//	s._No = 202100200;
//	//��ȷ����s��_name,_sex,_age��Ա������ֵ��p
//	Person p = s;
//	Person* pi = &s;//��ȷ
//	Person& ps = s;//��ȷ
//	//Student s1 = p;//���󣬸���Ķ����ܸ�ֵ������Ķ���
//
//}
//int main()
//{
//	test2();
//	return 0;
//}

//class Person
//{
//public:
//	void Print()
//	{
//		cout << "I am a Person" << endl;
//	}
//};
//
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << "I am a Student" << endl;
//	}
//};

//class Person
//{
//public:
//	Person(const char* name="����",int age=20)
//		:_name(name)
//		,_age(age)
//	{
//
//	}
//	Person(const Person& p)
//		: _name(p._name)
//		,_age(p._age)
//	{
//		
//	}
//
//	Person& operator=(const Person& p)
//	{
//		if (this != &p)
//		{
//			_name = p._name;
//			_age = p._age;
//		}
//		return *this;
//	}
//
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//
//
//protected:
//	const char* _name; // ����
//	int _age;
//};
//
//class Student : public Person
//{
//public:
//	Student(const char* name="����",int age=100,int num=100)
//		//���ø���Ĺ��캯����ʼ���Ĳ���
//		//�ڳ�ʼ���Լ��ĳ�Ա
//		:Person(name,age)
//		,_num(num)
//	{
//
//	}
//
//
//	//Student(const char* name, int age, int num)
//	//	:_name(name)
//	//	,_age(age)
//	//	,_num(num)
//	//{
//
//	//}
//
//	Student(const Student& s)
//		:Person(s)//s���ݸ�Person��һ����Ƭ��Ϊ
//		,_num(s._num)
//	{
//
//	}
//
//	Student& operator=(const Student& s)
//	{
//		if (this != &s)
//		{
//			Person::operator=(s);
//			//operator=(s) ����ģ������ָ���������һֱ�����Լ���operator=���ᷢ��ջ����Ĵ���
//			_num = s._num;
//		}
//		return *this;
//	}
//
//	~Student()//����������Ϊ����͸��������������ͬ�����������ԣ���������������ͱ�����
//			//��Ϊ��̬��ԭ���κ������������ᱻ����Ϊdestructor()
//	{
//		Person::~Person();
//		cout << "~student" << endl;
//	}
//
//
//protected:
//	int _num = 999; // ѧ��
//};

//class A
//{
//private:
//	A()
//	{
//
//	}
//};
//
//class B :public A
//{
//
//};

//int main()
//{
//	Student s1;
//	return 0;
//}

//class Person
//{
//public:
//	string _name; // ����
//};
//
//class Student : virtual public Person
//{
//protected:
//	int _num; //ѧ��
//};
//
//class Teacher :virtual public Person
//{	
//protected:
//	int _id; // ְ�����
//};
//
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // ���޿γ�
//};
//
//int main()
//{
//	//����ڶ����ԣ��޷���ȷҪ������һ��
//	Assistant a;
//	a._name = "����";
//
//	//��Ҫ��ʾָ�����ʸ���ĳ�Ա���Խ�������Ե����⡣
//	//�����Ǵ�����������
//	a.Teacher::_name = "����";
//	a.Student::_name = "����";
//}


//class Base
//{
//public:
//	Base()
//	{
//		_count++;
//	}
//
//	static int _count;
//};
//
//int Base::_count = 0;
//
//class Derived1:public Base
//{
//
//};
//
//class Derived2 :public Base
//{
//};
//
//int main()
//{
//	Derived1 d1;
//	Derived2 d2;
//	cout << Base::_count << endl;
//}


class A {
public:
	int _a;
};


class B : virtual public A {
public:
	int _b;
};

class C : virtual public A {
public:
	int _c;
};

class D : public B, public C
{
public:
	int _d;
};

int main()
{
	D d;
	d.B::_a = 1;
	d.C::_a = 2;
	d._b = 3;	
	d._c = 4;
	d._d = 5;
	return 0;
}

//class A final{/* */ };//A������Ϊ����
//class B{/* */ };
//class C final:B{/* */ };//C������Ϊ����
//
//class Tire {
//protected:
//	string _brand = "Michelin"; // Ʒ��
//	size_t _size = 17; // �ߴ�
//
//};
//
//class Car {
//protected:
//	string _colour = "��ɫ"; // ��ɫ
//	string _num = "��ABIT00"; // ���ƺ�
//	Tire _t; // ��̥
//};