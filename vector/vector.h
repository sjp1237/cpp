#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string.h>
#include<assert.h>
using namespace std;

namespace sjp
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator; //vector的迭代器就是原生指针
		typedef const T* const_iterator;

		//类模板的成员函数还可以再是函数模板。
		//template<class InputIterator>
		vector(iterator first, iterator end)
			:_first(nullptr), _end(nullptr), _end_of_storage(nullptr)
		{
			while (first != end)
			{
				push_back(*first);
				first++;
			}
		}

		vector(size_t n, T val=T())//
		{
			reserve(n);
			for (int i = 0; i < n; i++)
			{
				push_back(val);
			}
		}
		vector()
		 :_first(nullptr),_end(nullptr),_end_of_storage(nullptr)
		{

		}

		//v2(v1)
		vector(const vector<T>& v)
			:_first(nullptr),_end(nullptr),_end_of_storage(nullptr)
		{
			reserve(v.capacity());
			for ( auto e: v)
			{
				push_back(e);
			}
		}

		//v2=v1
		vector<T>& operator=(const vector<T>& v)
		{
			vector<T> tmp(v);
			swap(_first, tmp._first);//不能用 赋值 过去，tmp出函数作业域或被析构掉。
			swap(_end, tmp._end);
			swap(_end_of_storage, tmp._end_of_storage);
			return *this;
		}

		~vector()
		{
			if (_first != _end)
			{
				delete[] _first;
				_first = _end = _end_of_storage = nullptr;
			}

		}

		iterator begin()//返回vector迭代区间的头
		{
			return _first;
		}
		iterator end()//返回vector的迭代区间的尾
		{
			return _end;
		}

		const_iterator begin()const
		{
			return _first;
		}
		const_iterator end()const
		{
			return _end;
		}

		size_t size()const//返回vector的数据个数
		{
			return _end - _first;
		}

		size_t capacity()const//返回vector的容量
		{
			return _end_of_storage - _first;
		}

		void push_back(const T& x)//尾插，直接在最后一个位置插入数据即可
		{
			insert(_end, x);
			//if (_end == _end_of_storage)
			//{
			//	int newcapacity = capacity() == 0 ? 5 : capacity() * 2;
			//	reserve(newcapacity);
			//}
			//*_end = x;
			//++_end;
		}

		
		void pop_back()
		{
			--_end;
		}

		void reserve(size_t n)
		{
			size_t sz = size();//先保存原本的size
			if (capacity() < n)
			{
				T* tmp = new T[n];//重新开一块空间
				if (_first)//如果_first不为空指针
				{
					memcpy(tmp, _first, sz*sizeof(T));//将原空间的值拷贝给新空间
					for (int i = 0; i < size(); i++)
					{
						tmp[i] = _first[i];
					}
					delete[] _first;//释放旧空间
				}
				//在让迭代器指向新空间
				_first = tmp;
				_end = _first + sz;
				_end_of_storage = _first + n;
			}
		}

		void resize(size_t n,T val=T())
		{
			if (n > size())
			{
				if (n > capacity())//如果预留数据个数大于容量则需要增容
				{
					reserve(n);
				}
				size_t sz = n - size();//将数据补齐到n个
				for (int i = 0; i < sz; i++)
				{
					push_back(val);
				}
			}
		}
			


		void insert(iterator& pos,const T& x)
		{
			assert(pos >= _first && pos <= _end);
			if (_end == _end_of_storage)//判断容量是否满了
			{
				size_t lenth = pos - _first;//如果换新空间，需要保留pos在vector的位置
				int newcapacity = capacity() == 0 ? 5 : capacity() * 2;
				reserve(newcapacity);//预留新空间
				pos =_first+lenth;//更新pos
			}
			//将x插入到pos位置的前面
			iterator cur = end();
			while (cur != pos)
			{
				*(cur) = *(cur-1);
				cur--;
			}
			*pos = x;	
			_end += 1;//数据个数再加一
			pos += 1;
		}

		iterator erase(iterator pos)
		{
			assert(pos < _end);	
			iterator cur = pos;//将pos位置后的所有数据向前挪一步
			while (cur != _end - 1)
			{
				*cur = *(cur + 1);	
				cur++;
			}
			_end--;//数据个数再减一
			return pos;
		}

		bool empty()const//判断vector是否为空
		{
			return _first == _end;
		}

		const T& operator[](size_t i)const
		{
			return *(_first + i);
		}

		T& operator[](size_t i)
		{
			return *(_first + i);
		}

		void clear()//清空vector
		{
			_end = _first;
		}

		T& back()//返回vector最后一个元素
		{
			return *(back - 1);
		}

		const T& back()const
		{
			return *(back - 1);
		}

		T& front()//返回vector第一个元素
		{
			return *(front);
		}

		const T& front()const
		{
			return *(front);
		}


	private:	
		iterator _first;//表示目前使用空间的头
		iterator _end;//表示目前使用空间的尾
		iterator _end_of_storage;//表示目前可用空间的尾
	};

}