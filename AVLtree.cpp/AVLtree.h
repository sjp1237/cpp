#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

template<class K,class V>
struct AVLTreeNode
{
	AVLTreeNode* _left;//左孩子节点
	AVLTreeNode* _right;//右孩子节点
	AVLTreeNode* parent;//父亲节点
	int _bf;//平衡因子
	pair<K, V> _kv;//存储数据
	AVLTreeNode(pair<K,V> kv)//节点的构造函数
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
	typedef AVLTreeNode<K, V> node;//节点
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
		if (_root == nullptr)//如果是空树，直接插入
		{
			_root = new node(kv);
			return true;
		}

		node* cur = _root;
		node* parent = nullptr;
		while (cur)//寻找相对应的空位置
		{
			if (cur->_kv.first > kv.first)//如果值小于该节点的值，则去它的左子树寻找
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_kv.first < kv.first)//如果值大于该节点的值，则去它的右子树寻找
			{
				parent = cur;
				cur = cur->_right;
			}
		}

		node* newnode = new node(kv);//创建新的节点
		newnode->parent = parent;//将新的节点与parent进行连接
		if (parent->_kv.first > kv.first)//判断新节点是连接在parent的左孩子还是右孩子
		{
			parent->_left = newnode;
			parent->_bf--;//插入到parent的左孩子，parent的平衡因子-1
		}
		else if (parent->_kv.first < kv.first)
		{
			parent->_right = newnode;
			parent->_bf++; //插入到parent的右孩子，parent的平衡因子 +1 1
		}

		//向上改变平衡因子
		
		while (parent)//parent为nullptr，则停下来
		{
			node* pparent = parent->parent;//连接错
			if (parent->_bf == 0)//平衡因子等于0
			{
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				
				if (pparent==nullptr)//parent是根节点
				{
					break;
				}
				else if (pparent->_left == parent)//parent是pparent的左节点
				{
					pparent->_bf--;
				}
				else if (pparent->_right == parent)//parent是pparent的右节点
				{
					pparent->_bf++;
				}
				parent = pparent;//parent向上移动
			}
			else if (parent->_bf == 2 || parent->_bf == -2)//parent
			{
				if (parent->_bf == 2)
				{
					if (parent->_right->_bf == 1)
					{
						//左单旋
						LeftRevole(parent);			
					}
					else if (parent->_right->_bf == -1)
					{
						//先右旋在左单旋
						RLrevole(parent);
					}
				}
				else if (parent->_bf == -2)
				{
					if (parent->_left->_bf == -1)
					{
						//右单旋
						RightRevole(parent);
					}
						else if (parent->_left->_bf == 1)
					{
						//先左单旋在右单旋
						LRrevole(parent);
					}
				}
				break;//旋转之后都是平衡树，直接跳出循环
			
			}
		}
	}

	void RLrevole(node* parent)
	{
		node* subR = parent->_right;
		node* subRL = subR->_left;
		RightRevole(subR);//对subR的进行右单旋
		LeftRevole(parent);//对parent进行左单旋
		if (subRL->_bf == -1)//subRL的平衡因子为-1
		{
			subR->_bf = 1;
			subRL->_bf = 0;
			parent->_bf = 0;
		}
		else if (subRL->_bf == 1)//subRL的平衡因子为1
		{
			parent->_bf = -1;
			subRL->_bf = 0;
			subR->_bf = 0;
		}
		else if (subRL->_bf == 0)//subRL的平衡因子为0
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
		LeftRevole(subL);//对subL进行左单旋
		RightRevole(parent);//对parent进行右单旋
		if (subLR->_bf == -1)//subLR的平衡因子为-1
		{
			parent->_bf = 1;
			subLR->_bf = 0;
			subL->_bf = 0;
		}
		else if (subLR->_bf == 1)//subLR的平衡因子为1
		{
			subL->_bf = -1;
			subLR->_bf = 0;
			parent->_bf = 0;
		}
		else if (subLR->_bf == 0)//subLR的平衡因子
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
		parent->_left = subL->_right;//subL的右孩子连接到parent的左孩子节点上

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
			subL->parent = pparent;//pparent连接到subL的parent的节点上
		}
		else//pparent为nullptr
		{
			_root = subL;//subL直接变为根节点
			subL->parent = nullptr;//subL的parent指向空
		}
		subL->_right = parent;//subL的右节点连接parent
		parent->parent = subL;//parent的parent连接subL
		subL->_bf = parent->_bf = 0;//subL和parent的平衡因子变为0
	}

	void LeftRevole(node*& parent)
	{
		node* pparent = parent->parent;
		node* subR = parent->_right;
		parent->_right = subR->_left;
		if (pparent)//pparent不为空
		{
			if (pparent->_left == parent)//parent为pparent的左孩子的节点上
				pparent->_left = subR;//subR连接到pparent的左孩子节点上
			else if (pparent->_right == parent)//parent为pparent的右孩子的节点上
				pparent->_right = subR;//subR连接到pparent的右孩子节点上
			subR->parent = pparent;//subR的parent连接pparent
		}
		else//pparent为空
		{
			_root = subR;//subR直接为根节点
			_root->parent = nullptr;//_root的parent的指向空
		}
		subR->_left = parent;//subR的left连接parent
		parent->parent = subR;//parent的parent连接subR
		subR->_bf = parent->_bf = 0;//subR和parent的平衡因子变为为0
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
				return cur;//找到了
			}
		}
		return nullptr;//找不到
	}

	bool erase(const K& key)
	{
		node* cur = find(key);//查找cur
		if (cur == nullptr)//找不到
		{
			return false;
		}

		//找到了
		node* parent = cur->parent;
		if (cur->_left == nullptr && cur->_right == nullptr)//如果要删除的节点的左右孩子为空
		{
			if (parent->_left == cur)//cur为parent的左边，平衡因子+1
			{
				parent->_bf++;
			}
			else//cur为parent的右边，平衡因子-1
			{
				parent->_bf--;
			}
			delete cur;//直接删除
			cur = nullptr;
			//平衡因子
		}
		else if (cur->_left && cur->_right)//要删除的节点中的左右孩子都存在
		{
			node* rightmin = cur->_right;//右子树的最小节点
			while (rightmin->_left)//查找右子树的最小值
			{
				rightmin == rightmin->_left;
			}
			cur->_kv = rightmin->_kv;//将右子树的最小值给要删除的节点，然后删除rightmin
			parent = rightmin->parent;//rightmin的父亲
			if (rightmin->_right)//rightmin存在右子树
			{
				node* right = rightmin->_right;
				parent->_right = right;//将rightmin的右子树给parent
				right->parent = parent;//右子树的父亲连接parent
			}
			else
			{
				parent->_right = nullptr;//右子树不存在，连接nullptr
			}
			delete rightmin;//直接删除rightmin
			rightmin = nullptr;
			parent->_bf--;//right的父亲的平衡因子-1
		}
		else if (cur->_left)//cur的左子树不为空，右子树不存在
		{
			if (cur == _root)//cur为根节点
			{
				_root = cur->_left;
				_root->parent = nullptr;
			}
			else//cur不是根节点
			{
				node* subL = cur->_left;//cur的左子树
				if (parent->_left == cur)//cur是parent的左子树
				{
					parent->_left = subL;//parent的左子树连接subL
					parent->_bf++;//parent的平衡因子+1
				}
				else
				{
					parent->_right = subL;//parent的右子树连接subL
					parent->_bf--;//parent的平衡因子-1
				}
				subL->parent = parent;//subL的parent连接cur的parent
			}
			delete cur;
			cur == nullptr;
		}

		else if (cur->_right)//cur的右子树不为空，左子树不存在
		{
			if (cur == _root)
			{
				_root = cur->_right;
				_root->parent = nullptr;
			}
			else
			{
				node* subR = cur->_right;//cur的右子树
				if (parent->_left == cur)//cur是parent的左子树
				{
					parent->_left = subR;//parent的左子树连接subR
					parent->_bf++;
				}
				else
				{
					parent->_right = subR;//parent的右子树连接subR
					parent->_bf--;
				}
				subR->parent = parent;
			}
			delete cur;
			cur == nullptr;
		}

		//更新平衡因子
		while (parent)//parent为nullptr，则停下来
		{
			node* pparent = parent->parent;
			if (parent->_bf == 0)//平衡因子等于0
			{
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{

				if (pparent == nullptr)//parent是根节点
				{
					break;
				}
				else if (pparent->_left == parent)//parent是pparent的左节点
				{
					pparent->_bf--;
				}
				else if (pparent->_right == parent)//parent是pparent的右节点
				{
					pparent->_bf++;
				}
				parent = pparent;//parent向上移动
			}
			else if (parent->_bf == 2 || parent->_bf == -2)//parent
			{
				if (parent->_bf == 2)
				{
					if (parent->_right->_bf == -1)//parent的右孩子节点的平衡因子为-1
					{
						//先右旋在左单旋
						RLrevole(parent);
					}
					else //parent的右孩子节点的平衡因子为1或者0
					{
						//左单旋
						node* subR = parent->_right;
						LeftRevole(parent);
						if (subR->_bf == 0)//parent的右孩子节点的平衡因子为0
						{
							//改变平衡因子
							subR->_bf = -1;
							parent->_bf = 1;
						}

					}
				}
				else if (parent->_bf == -2)
				{
					if (parent->_left->_bf == 1)
					{
						//先左单旋在右单旋
						LRrevole(parent);
						
					}
					else //parent的右孩子节点的平衡因子为-1或者0
					{
						//右单旋
						node* subL = parent->_left;
						RightRevole(parent);
						if (subL->_bf == 0)//parent的右孩子节点的平衡因子为0
						{
							parent->_bf = -1;
							subL->_bf = 1;
						}
					}
				}
				break;//旋转之后都是平衡树，直接跳出循环
			}
		}
	}

private:
	node* _root;
};