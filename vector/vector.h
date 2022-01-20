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
		typedef T* iterator; //vector�ĵ���������ԭ��ָ��
		typedef const T* const_iterator;

		//��ģ��ĳ�Ա�������������Ǻ���ģ�塣
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
			swap(_first, tmp._first);//������ ��ֵ ��ȥ��tmp��������ҵ�����������
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

		iterator begin()//����vector���������ͷ
		{
			return _first;
		}
		iterator end()//����vector�ĵ��������β
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

		size_t size()const//����vector�����ݸ���
		{
			return _end - _first;
		}

		size_t capacity()const//����vector������
		{
			return _end_of_storage - _first;
		}

		void push_back(const T& x)//β�壬ֱ�������һ��λ�ò������ݼ���
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
			size_t sz = size();//�ȱ���ԭ����size
			if (capacity() < n)
			{
				T* tmp = new T[n];//���¿�һ��ռ�
				if (_first)//���_first��Ϊ��ָ��
				{
					memcpy(tmp, _first, sz*sizeof(T));//��ԭ�ռ��ֵ�������¿ռ�
					for (int i = 0; i < size(); i++)
					{
						tmp[i] = _first[i];
					}
					delete[] _first;//�ͷžɿռ�
				}
				//���õ�����ָ���¿ռ�
				_first = tmp;
				_end = _first + sz;
				_end_of_storage = _first + n;
			}
		}

		void resize(size_t n,T val=T())
		{
			if (n > size())
			{
				if (n > capacity())//���Ԥ�����ݸ���������������Ҫ����
				{
					reserve(n);
				}
				size_t sz = n - size();//�����ݲ��뵽n��
				for (int i = 0; i < sz; i++)
				{
					push_back(val);
				}
			}
		}
			


		void insert(iterator& pos,const T& x)
		{
			assert(pos >= _first && pos <= _end);
			if (_end == _end_of_storage)//�ж������Ƿ�����
			{
				size_t lenth = pos - _first;//������¿ռ䣬��Ҫ����pos��vector��λ��
				int newcapacity = capacity() == 0 ? 5 : capacity() * 2;
				reserve(newcapacity);//Ԥ���¿ռ�
				pos =_first+lenth;//����pos
			}
			//��x���뵽posλ�õ�ǰ��
			iterator cur = end();
			while (cur != pos)
			{
				*(cur) = *(cur-1);
				cur--;
			}
			*pos = x;	
			_end += 1;//���ݸ����ټ�һ
			pos += 1;
		}

		iterator erase(iterator pos)
		{
			assert(pos < _end);	
			iterator cur = pos;//��posλ�ú������������ǰŲһ��
			while (cur != _end - 1)
			{
				*cur = *(cur + 1);	
				cur++;
			}
			_end--;//���ݸ����ټ�һ
			return pos;
		}

		bool empty()const//�ж�vector�Ƿ�Ϊ��
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

		void clear()//���vector
		{
			_end = _first;
		}

		T& back()//����vector���һ��Ԫ��
		{
			return *(back - 1);
		}

		const T& back()const
		{
			return *(back - 1);
		}

		T& front()//����vector��һ��Ԫ��
		{
			return *(front);
		}

		const T& front()const
		{
			return *(front);
		}


	private:	
		iterator _first;//��ʾĿǰʹ�ÿռ��ͷ
		iterator _end;//��ʾĿǰʹ�ÿռ��β
		iterator _end_of_storage;//��ʾĿǰ���ÿռ��β
	};

}