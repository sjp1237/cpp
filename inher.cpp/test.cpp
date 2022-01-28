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
//	string _name ; // 姓名
//	string _sex;//性别
//	int _age; // 年龄
//};
//
//class Student :public Person
//{
//
//protected:
//	int _stuid;//学号
//};
//
//class Teacher :public Person
//{
//
//protected:
//	int _jobid;//工号
//};
//
//void test1()
//{
//	Student s;
//	s._name = "张三";
//	s._age = 15;
//	Teacher t;
//	t._name = "李四";
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
//	string _name; // 姓名
//private:
//	int _age; // 年龄
//};
//
//class Student : public Person
//{
//	void test()
//	{
//		cout << _name << endl;//正确，_name是父类的protected的成员
//		cout << _age << endl;//错误，_age是父类的private的成员,不能被子类访问
//	}
//
//
//protected:
//	int _stunum; // 学号
//};

//class Person
//{
//public:
//	string _name; // 姓名
//	string _sex; // 性别
//	int _age; // 年龄
//};
//
//class Student : public Person
//{
//public:
//	int _No; // 学号
//};
//
//void test2()
//{
//	Student s;
//	s._name = "张三";
//	s._sex = "男";
//	s._age = 20;
//	s._No = 202100200;
//	//正确，将s的_name,_sex,_age成员变量赋值给p
//	Person p = s;
//	Person* pi = &s;//正确
//	Person& ps = s;//正确
//	//Student s1 = p;//错误，父类的对象不能赋值给子类的对象
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
//	Person(const char* name="张三",int age=20)
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
//	const char* _name; // 姓名
//	int _age;
//};
//
//class Student : public Person
//{
//public:
//	Student(const char* name="张三",int age=100,int num=100)
//		//调用父类的构造函数初始化的部分
//		//在初始化自己的成员
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
//		:Person(s)//s传递给Person是一个切片行为
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
//			//operator=(s) 错误的，如果不指定类域，则会一直调用自己的operator=，会发生栈溢出的错误
//			_num = s._num;
//		}
//		return *this;
//	}
//
//	~Student()//编译器会认为子类和父类的析构函数是同名函数，所以，父类的析构函数就被隐藏
//			//因为多态的原因，任何析构函数都会被处理为destructor()
//	{
//		Person::~Person();
//		cout << "~student" << endl;
//	}
//
//
//protected:
//	int _num = 999; // 学号
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
//	string _name; // 姓名
//};
//
//class Student : virtual public Person
//{
//protected:
//	int _num; //学号
//};
//
//class Teacher :virtual public Person
//{	
//protected:
//	int _id; // 职工编号
//};
//
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//
//int main()
//{
//	//会存在二义性，无法明确要访问哪一个
//	Assistant a;
//	a._name = "张三";
//
//	//需要显示指定访问父类的成员可以解决二义性的问题。
//	//但还是存在数据冗余
//	a.Teacher::_name = "张三";
//	a.Student::_name = "张三";
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

//class A final{/* */ };//A不能作为基类
//class B{/* */ };
//class C final:B{/* */ };//C不能作为基类
//
//class Tire {
//protected:
//	string _brand = "Michelin"; // 品牌
//	size_t _size = 17; // 尺寸
//
//};
//
//class Car {
//protected:
//	string _colour = "白色"; // 颜色
//	string _num = "陕ABIT00"; // 车牌号
//	Tire _t; // 轮胎
//};