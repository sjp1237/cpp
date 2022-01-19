#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

enum color
{
	BLACK,
    RED
};
template<class K,class V>
struct RBTreenode
{
	RBTreenode(pair<K, V> kv)
		:_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_kv(kv)
		,_color(RED)
	{

	}
	RBTreenode* _left;
	RBTreenode* _right;
	RBTreenode* _parent;
	pair<K, V> _kv;
	color _color = RED;
};

template<class K, class V>
class RBTree
{
public:
	RBTree()
		:_root(nullptr)
	{

	}
	typedef RBTreenode<K,V> Node;
	pair<Node*, bool> insert(pair<K, V> kv)
	{
		if (_root == nullptr)
		{
			Node* newnode = new Node(kv);
			_root = newnode;
			_root->_color = BLACK;
			return make_pair(_root, true);
		}

		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first == kv.first)
			{
				return make_pair(cur, false);
			}
		}

		Node* newnode = new Node(kv);

		if (parent->_kv.first > kv.first)
		{
			parent->_left = newnode;
		}
		else if (parent->_kv.first < kv.first)
		{
			parent->_right = newnode;
		}
		newnode->_parent = parent;
		cur = newnode;
		while (parent)//parent��Ϊ�գ�Ҳ����parent���Ǹ��ڵ�
		{
			if (parent->_color == BLACK)
			{
				return make_pair(cur, true);
			}
			Node* grandparent =	parent->_parent;//���parent�Ǻ죬��ôgrandparent�ش��ڣ���Ϊ���ڵ�Ϊ��ɫ�ڵ�
			if (parent == grandparent->_left)//parentλ��grandparent������
			{
				Node* uncle = grandparent->_right;
				if (uncle&&uncle->_color == RED)
				{
					uncle->_color = BLACK;
					parent->_color = BLACK;
					grandparent->_color = RED;
					cur = grandparent;
					parent = cur->_parent;
				}
				else
				{
					if (parent->_left == cur)//curλ��parent����ߣ������ҵ���
					{
						RightRevole(grandparent);
						parent->_color = BLACK;
						grandparent->_color = RED;
					}
					else//curλ��parent����ߣ��ȶ�parent����������Ȼ���granparent�����ҵ���
					{
						LeftRevole(parent);//������
						RightRevole(grandparent);//��grandparent�����ҵ���
						cur->_color = BLACK;
						grandparent->_color = RED;
					}
					break;
				}
			}
			else//parentλ��grandparent������
			{
				Node* uncle = grandparent->_left;
				if (uncle&&uncle->_color == RED)
				{
					parent->_color = uncle->_color = BLACK;
					grandparent->_color = RED;
					cur = grandparent;
					parent = cur->_parent;
				}
				else//uncle�Ǻ�ɫ�����Ǻ�ɫ
				{
					if (parent->_right == cur)//curλ��parent���ұ�
					{
						LeftRevole(grandparent);
						grandparent->_color = RED;
						parent->_color = BLACK;
					}
					else//curλ��parent�����
					{
						RightRevole(parent);//��parent�����е���
						LeftRevole(grandparent);//��grandparent��������
						grandparent->_color = RED;
						cur->_color = BLACK;
					}
					break;
				}
				
			}
		}
		_root->_color = BLACK;
		return make_pair(newnode, true);
	}

		
		void RightRevole(Node*& parent)
		{
			Node* pparent = parent->_parent;
			Node* subL = parent->_left;
			Node* subLR = subL->_right;
			parent->_left = subLR;//subL���Һ������ӵ�parent�����ӽڵ���
			if (subLR)
			{
				subLR->_parent = parent;

			}
			
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
				subL->_parent = pparent;//pparent���ӵ�subL��parent�Ľڵ���
			}
			else//pparentΪnullptr
			{
				_root = subL;//subLֱ�ӱ�Ϊ���ڵ�
				subL->_parent = nullptr;//subL��parentָ���
			}
			subL->_right = parent;//subL���ҽڵ�����parent
			parent->_parent = subL;//parent��parent����subL
		}

		void LeftRevole(Node*& parent)
		{
			Node* pparent = parent->_parent;
			Node* subR = parent->_right;
			Node* subRL = subR->_left;
			parent->_right = subRL;
			if (subRL)
			{
				subRL->_parent = parent;
			}
			if (pparent)//pparent��Ϊ��
			{
				if (pparent->_left == parent)//parentΪpparent�����ӵĽڵ���
					pparent->_left = subR;//subR���ӵ�pparent�����ӽڵ���
				else if (pparent->_right == parent)//parentΪpparent���Һ��ӵĽڵ���
					pparent->_right = subR;//subR���ӵ�pparent���Һ��ӽڵ���
				subR->_parent = pparent;//subR��parent����pparent
			}
			else//pparentΪ��
			{
				_root = subR;//subRֱ��Ϊ���ڵ�
				_root->_parent = nullptr;//_root��parent��ָ���
			}
			subR->_left = parent;//subR��left����parent
			parent->_parent = subR;//parent��parent����subR
		}

		bool _checkRBTree(Node* root, int Blackcount, int count)
		{
			if (root == nullptr)
			{
				if (count != Blackcount)
				{
					cout << "·���ϵĺ�ɫ�ڵ㲻��ͬ" << endl;
					return false;
				}
				return true;
			}

			if (root->_color == RED && root->_parent->_color == RED)
			{
				cout << "����������ڵ�" << endl;
				return false;
			}

			if (root->_color == BLACK)
			{
				count++;
			}

			return _checkRBTree(root->_left,Blackcount,count) && _checkRBTree(root->_right, Blackcount, count);
		}

		bool checkRBTree()
		{
			if (_root == nullptr)
			{
				return true;
			}

			if (_root->_color == RED)
			{
				cout << "_root is RED" << endl;
				return false;
			}

			int Blackcount = 0;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_color == BLACK)
				{
					Blackcount++;
				}
				cur = cur->_left;
			}
			int count = 0;
			return _checkRBTree(_root, Blackcount, count);
		}

		void _Inorder(Node* root)
		{
			if (root == nullptr)
				return;
			_Inorder(root->_left);
			cout << root->_kv.first << endl;
			_Inorder(root->_right);
		}

		void Inorder()
		{
			_Inorder(_root);
		}

private:
	Node* _root;
};