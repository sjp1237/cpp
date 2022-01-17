#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

template<class K,class V>
struct AVLTreeNode
{
	AVLTreeNode* _left;//���ӽڵ�
	AVLTreeNode* _right;//�Һ��ӽڵ�
	AVLTreeNode* parent;//���׽ڵ�
	int _bf;//ƽ������
	pair<K, V> _kv;//�洢����
	AVLTreeNode(pair<K,V> kv)//�ڵ�Ĺ��캯��
		:_left(nullptr)
		,_right(nullptr)
		,parent(nullptr)
		,_kv(kv)
		,_bf(0)
	{

	}
};


template<class K,class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> node;//�ڵ�
public:
	AVLTree()
		:_root(nullptr)
	{

	}

	~AVLTree()
	{

	}

	bool insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)//����ǿ�����ֱ�Ӳ���
		{
			_root = new node(kv);
			return true;
		}

		node* cur = _root;
		node* parent = nullptr;
		while (cur)//Ѱ�����Ӧ�Ŀ�λ��
		{
			if (cur->_kv.first > kv.first)//���ֵС�ڸýڵ��ֵ����ȥ����������Ѱ��
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_kv.first < kv.first)//���ֵ���ڸýڵ��ֵ����ȥ����������Ѱ��
			{
				parent = cur;
				cur = cur->_right;
			}
		}

		node* newnode = new node(kv);//�����µĽڵ�
		newnode->parent = parent;//���µĽڵ���parent��������
		if (parent->_kv.first > kv.first)//�ж��½ڵ���������parent�����ӻ����Һ���
		{
			parent->_left = newnode;
			parent->_bf--;//���뵽parent�����ӣ�parent��ƽ������-1
		}
		else if (parent->_kv.first < kv.first)
		{
			parent->_right = newnode;
			parent->_bf++; //���뵽parent���Һ��ӣ�parent��ƽ������ +1 1
		}

		//���ϸı�ƽ������
		
		while (parent)//parentΪnullptr����ͣ����
		{
			node* pparent = parent->parent;//���Ӵ�
			if (parent->_bf == 0)//ƽ�����ӵ���0
			{
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				
				if (pparent==nullptr)//parent�Ǹ��ڵ�
				{
					break;
				}
				else if (pparent->_left == parent)//parent��pparent����ڵ�
				{
					pparent->_bf--;
				}
				else if (pparent->_right == parent)//parent��pparent���ҽڵ�
				{
					pparent->_bf++;
				}
				parent = pparent;//parent�����ƶ�
			}
			else if (parent->_bf == 2 || parent->_bf == -2)//parent
			{
				if (parent->_bf == 2)
				{
					if (parent->_right->_bf == 1)
					{
						//����
						LeftRevole(parent);			
					}
					else if (parent->_right->_bf == -1)
					{
						//������������
						RLrevole(parent);
					}
				}
				else if (parent->_bf == -2)
				{
					if (parent->_left->_bf == -1)
					{
						//�ҵ���
						RightRevole(parent);
					}
						else if (parent->_left->_bf == 1)
					{
						//���������ҵ���
						LRrevole(parent);
					}
				}
				break;//��ת֮����ƽ������ֱ������ѭ��
			
			}
		}
	}

	void RLrevole(node* parent)
	{
		node* subR = parent->_right;
		node* subRL = subR->_left;
		RightRevole(subR);//��subR�Ľ����ҵ���
		LeftRevole(parent);//��parent��������
		if (subRL->_bf == -1)//subRL��ƽ������Ϊ-1
		{
			subR->_bf = 1;
			subRL->_bf = 0;
			parent->_bf = 0;
		}
		else if (subRL->_bf == 1)//subRL��ƽ������Ϊ1
		{
			parent->_bf = -1;
			subRL->_bf = 0;
			subR->_bf = 0;
		}
		else if (subRL->_bf == 0)//subRL��ƽ������Ϊ0
		{
			subRL->_bf = 0;
			subR->_bf = 0;
			parent->_bf = 0;
		}
	}

	void LRrevole(node* parent)
	{
		node* subL = parent->_left;
		node* subLR = parent->_left->_right;
		LeftRevole(subL);//��subL��������
		RightRevole(parent);//��parent�����ҵ���
		if (subLR->_bf == -1)//subLR��ƽ������Ϊ-1
		{
			parent->_bf = 1;
			subLR->_bf = 0;
			subL->_bf = 0;
		}
		else if (subLR->_bf == 1)//subLR��ƽ������Ϊ1
		{
			subL->_bf = -1;
			subLR->_bf = 0;
			parent->_bf = 0;
		}
		else if (subLR->_bf == 0)//subLR��ƽ������
		{
			subL->_bf = 0;
			subLR->_bf = 0;
			parent->_bf = 0;
		}
	}

	void RightRevole(node* parent)
	{
		node* pparent = parent->parent;
		node* subL = parent->_left;
		parent->_left = subL->_right;//subL���Һ������ӵ�parent�����ӽڵ���

		if (pparent)//pparent��Ϊ��
		{
			if (pparent->_left == parent)//parentλ��pparent��ڵ���
			{
				pparent->_left = subL;//subL���ӵ�pparent���󺢺��ӽڵ���
			}
			else if (pparent->_right == parent)//parentλ��pparent�ҽڵ���
			{
				pparent->_right = subL;//subL���ӵ�pparent���Һ����ӽڵ���
			}
			subL->parent = pparent;//pparent���ӵ�subL��parent�Ľڵ���
		}
		else//pparentΪnullptr
		{
			_root = subL;//subLֱ�ӱ�Ϊ���ڵ�
			subL->parent = nullptr;//subL��parentָ���
		}
		subL->_right = parent;//subL���ҽڵ�����parent
		parent->parent = subL;//parent��parent����subL
		subL->_bf = parent->_bf = 0;//subL��parent��ƽ�����ӱ�Ϊ0
	}

	void LeftRevole(node*& parent)
	{
		node* pparent = parent->parent;
		node* subR = parent->_right;
		parent->_right = subR->_left;
		if (pparent)//pparent��Ϊ��
		{
			if (pparent->_left == parent)//parentΪpparent�����ӵĽڵ���
				pparent->_left = subR;//subR���ӵ�pparent�����ӽڵ���
			else if (pparent->_right == parent)//parentΪpparent���Һ��ӵĽڵ���
				pparent->_right = subR;//subR���ӵ�pparent���Һ��ӽڵ���
			subR->parent = pparent;//subR��parent����pparent
		}
		else//pparentΪ��
		{
			_root = subR;//subRֱ��Ϊ���ڵ�
			_root->parent = nullptr;//_root��parent��ָ���
		}
		subR->_left = parent;//subR��left����parent
		parent->parent = subR;//parent��parent����subR
		subR->_bf = parent->_bf = 0;//subR��parent��ƽ�����ӱ�ΪΪ0
	}

	node* find(const K& key)
	{
		node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first > key)
			{
				cur = cur->_left;
			}
			else if (cur->_kv.first < key)
			{
				cur = cur->_right;
			}
			else
			{
				return cur;//�ҵ���
			}
		}
		return nullptr;//�Ҳ���
	}

	bool erase(const K& key)
	{
		node* cur = find(key);//����cur
		if (cur == nullptr)//�Ҳ���
		{
			return false;
		}

		//�ҵ���
		node* parent = cur->parent;
		if (cur->_left == nullptr && cur->_right == nullptr)//���Ҫɾ���Ľڵ�����Һ���Ϊ��
		{
			if (parent->_left == cur)//curΪparent����ߣ�ƽ������+1
			{
				parent->_bf++;
			}
			else//curΪparent���ұߣ�ƽ������-1
			{
				parent->_bf--;
			}
			delete cur;//ֱ��ɾ��
			cur = nullptr;
			//ƽ������
		}
		else if (cur->_left && cur->_right)//Ҫɾ���Ľڵ��е����Һ��Ӷ�����
		{
			node* rightmin = cur->_right;//����������С�ڵ�
			while (rightmin->_left)//��������������Сֵ
			{
				rightmin == rightmin->_left;
			}
			cur->_kv = rightmin->_kv;//������������Сֵ��Ҫɾ���Ľڵ㣬Ȼ��ɾ��rightmin
			parent = rightmin->parent;//rightmin�ĸ���
			if (rightmin->_right)//rightmin����������
			{
				node* right = rightmin->_right;
				parent->_right = right;//��rightmin����������parent
				right->parent = parent;//�������ĸ�������parent
			}
			else
			{
				parent->_right = nullptr;//�����������ڣ�����nullptr
			}
			delete rightmin;//ֱ��ɾ��rightmin
			rightmin = nullptr;
			parent->_bf--;//right�ĸ��׵�ƽ������-1
		}
		else if (cur->_left)//cur����������Ϊ�գ�������������
		{
			if (cur == _root)//curΪ���ڵ�
			{
				_root = cur->_left;
				_root->parent = nullptr;
			}
			else//cur���Ǹ��ڵ�
			{
				node* subL = cur->_left;//cur��������
				if (parent->_left == cur)//cur��parent��������
				{
					parent->_left = subL;//parent������������subL
					parent->_bf++;//parent��ƽ������+1
				}
				else
				{
					parent->_right = subL;//parent������������subL
					parent->_bf--;//parent��ƽ������-1
				}
				subL->parent = parent;//subL��parent����cur��parent
			}
			delete cur;
			cur == nullptr;
		}

		else if (cur->_right)//cur����������Ϊ�գ�������������
		{
			if (cur == _root)
			{
				_root = cur->_right;
				_root->parent = nullptr;
			}
			else
			{
				node* subR = cur->_right;//cur��������
				if (parent->_left == cur)//cur��parent��������
				{
					parent->_left = subR;//parent������������subR
					parent->_bf++;
				}
				else
				{
					parent->_right = subR;//parent������������subR
					parent->_bf--;
				}
				subR->parent = parent;
			}
			delete cur;
			cur == nullptr;
		}

		//����ƽ������
		while (parent)//parentΪnullptr����ͣ����
		{
			node* pparent = parent->parent;
			if (parent->_bf == 0)//ƽ�����ӵ���0
			{
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{

				if (pparent == nullptr)//parent�Ǹ��ڵ�
				{
					break;
				}
				else if (pparent->_left == parent)//parent��pparent����ڵ�
				{
					pparent->_bf--;
				}
				else if (pparent->_right == parent)//parent��pparent���ҽڵ�
				{
					pparent->_bf++;
				}
				parent = pparent;//parent�����ƶ�
			}
			else if (parent->_bf == 2 || parent->_bf == -2)//parent
			{
				if (parent->_bf == 2)
				{
					if (parent->_right->_bf == -1)//parent���Һ��ӽڵ��ƽ������Ϊ-1
					{
						//������������
						RLrevole(parent);
					}
					else //parent���Һ��ӽڵ��ƽ������Ϊ1����0
					{
						//����
						node* subR = parent->_right;
						LeftRevole(parent);
						if (subR->_bf == 0)//parent���Һ��ӽڵ��ƽ������Ϊ0
						{
							//�ı�ƽ������
							subR->_bf = -1;
							parent->_bf = 1;
						}

					}
				}
				else if (parent->_bf == -2)
				{
					if (parent->_left->_bf == 1)
					{
						//���������ҵ���
						LRrevole(parent);
						
					}
					else //parent���Һ��ӽڵ��ƽ������Ϊ-1����0
					{
						//�ҵ���
						node* subL = parent->_left;
						RightRevole(parent);
						if (subL->_bf == 0)//parent���Һ��ӽڵ��ƽ������Ϊ0
						{
							parent->_bf = -1;
							subL->_bf = 1;
						}
					}
				}
				break;//��ת֮����ƽ������ֱ������ѭ��
			}
		}
	}

private:
	node* _root;
};