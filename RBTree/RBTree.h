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
		while (parent)//parent不为空，也就是parent不是根节点
		{
			if (parent->_color == BLACK)
			{
				return make_pair(cur, true);
			}
			Node* grandparent =	parent->_parent;//如果parent是红，那么grandparent必存在，因为根节点为黑色节点
			if (parent == grandparent->_left)//parent位于grandparent左子树
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
					if (parent->_left == cur)//cur位于parent的左边，进行右单旋
					{
						RightRevole(grandparent);
						parent->_color = BLACK;
						grandparent->_color = RED;
					}
					else//cur位于parent的左边，先对parent进行左单旋，然后对granparent进行右单旋
					{
						LeftRevole(parent);//先左单旋
						RightRevole(grandparent);//对grandparent进行右单旋
						cur->_color = BLACK;
						grandparent->_color = RED;
					}
					break;
				}
			}
			else//parent位于grandparent右子树
			{
				Node* uncle = grandparent->_left;
				if (uncle&&uncle->_color == RED)
				{
					parent->_color = uncle->_color = BLACK;
					grandparent->_color = RED;
					cur = grandparent;
					parent = cur->_parent;
				}
				else//uncle是红色或者是黑色
				{
					if (parent->_right == cur)//cur位于parent的右边
					{
						LeftRevole(grandparent);
						grandparent->_color = RED;
						parent->_color = BLACK;
					}
					else//cur位于parent的左边
					{
						RightRevole(parent);//对parent进行有单旋
						LeftRevole(grandparent);//对grandparent进行左单旋
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
			parent->_left = subLR;//subL的右孩子连接到parent的左孩子节点上
			if (subLR)
			{
				subLR->_parent = parent;

			}
			
			if (pparent)//pparent不为空
			{
				if (pparent->_left == parent)//parent位于pparent左节点上
				{
					pparent->_left = subL;//subL连接到pparent的左孩孩子节点上
				}
				else if (pparent->_right == parent)//parent位于pparent右节点上
				{
					pparent->_right = subL;//subL连接到pparent的右孩孩子节点上
				}
				subL->_parent = pparent;//pparent连接到subL的parent的节点上
			}
			else//pparent为nullptr
			{
				_root = subL;//subL直接变为根节点
				subL->_parent = nullptr;//subL的parent指向空
			}
			subL->_right = parent;//subL的右节点连接parent
			parent->_parent = subL;//parent的parent连接subL
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
			if (pparent)//pparent不为空
			{
				if (pparent->_left == parent)//parent为pparent的左孩子的节点上
					pparent->_left = subR;//subR连接到pparent的左孩子节点上
				else if (pparent->_right == parent)//parent为pparent的右孩子的节点上
					pparent->_right = subR;//subR连接到pparent的右孩子节点上
				subR->_parent = pparent;//subR的parent连接pparent
			}
			else//pparent为空
			{
				_root = subR;//subR直接为根节点
				_root->_parent = nullptr;//_root的parent的指向空
			}
			subR->_left = parent;//subR的left连接parent
			parent->_parent = subR;//parent的parent连接subR
		}

		bool _checkRBTree(Node* root, int Blackcount, int count)
		{
			if (root == nullptr)
			{
				if (count != Blackcount)
				{
					cout << "路径上的黑色节点不相同" << endl;
					return false;
				}
				return true;
			}

			if (root->_color == RED && root->_parent->_color == RED)
			{
				cout << "出现连续红节点" << endl;
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