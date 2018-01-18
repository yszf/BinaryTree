#include "binarytree.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

void MakeTree(BTNode **ptr)
{
	*ptr = NULL;
}

//购买结点
BTNode * BuyNode()
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (NULL == node)
	{
		exit(1);
	}
	memset(node, 0, sizeof(BTNode));
	node->leftChild = NULL;
	node->rightChild = NULL;
	node->tag = 0;
	return node;
}

void FreeNode(BTNode *ptr)
{
	free(ptr);
}

//中序查找元素
BTNode * FindIs(BTNode *ptr, Elem_Type x)
{
	if (ptr == NULL || ptr->data == x)
	{
		return ptr;
	}
	BTNode *p = FindIs(ptr->leftChild, x);
	if (p == NULL)
	{
		p = FindIs(ptr->rightChild, x);
	}
	return p;
}

BTNode * CreateTree1()
{
	BTNode *s = NULL;
	Elem_Type data;
	scanf_s("%c", &data, 1);
	if (END != data)
	{
		s = BuyNode();
		s->data = data;
		s->leftChild = CreateTree1();
		s->rightChild = CreateTree1();
	}
	return s;
}

BTNode * CreateTree2(Elem_Type *&str)
{
	BTNode *s = NULL;
	if (str != NULL && *str != END)
	{
		s = BuyNode();
		s->data = *str;
		s->leftChild = CreateTree2(++str);
		s->rightChild = CreateTree2(++str);
	}
	return s;
}

BTNode * CreateTree3(Elem_Type ** const pstr)
{
	BTNode *s = NULL;
	if (pstr != NULL && *pstr != NULL && **pstr != END)
	{
		s = BuyNode();
		s->data = **pstr;
		s->leftChild = CreateTree3(&++*pstr);
		s->rightChild = CreateTree3(&++*pstr);
	}
	return s;
}

void CreateTree4(BTNode *&ptr)
{
	Elem_Type x;
	scanf_s("%c", &x, 1);
	if (x == END)
	{
		ptr = NULL;
	}
	else
	{
		ptr = BuyNode();
		ptr->data = x;
		CreateTree4(ptr->leftChild);
		CreateTree4(ptr->rightChild);
	}
}

void CreateTree5(BTNode ** const pptr)
{
	Elem_Type x;
	scanf_s("%c", &x, 1);
	if (x == END)
	{
		*pptr = NULL;
	}
	else
	{
		*pptr = BuyNode();
		(*pptr)->data = x;
		CreateTree5(&(*pptr)->leftChild);
		CreateTree5(&(*pptr)->rightChild);
	}
}

int isIndex(const Elem_Type *is, Elem_Type x, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (is[i] == x)
		{
			return i;
		}
	}
	return -1;
}

BTNode * CreatePI(const Elem_Type *ps, const Elem_Type *is, int n)
{
	BTNode *s = NULL;
	if (n > 0)
	{
		s = BuyNode();
		s->data = ps[0];
		int pos = isIndex(is, ps[0], n);
		if (pos == -1)
		{
			exit(0);
		}

		s->leftChild = CreatePI(ps + 1, is, pos);
		s->rightChild = CreatePI(ps + pos + 1, is + pos + 1, n - pos - 1);
	}
	return s;
}

//根据前序和中序序列创建二叉树
BTNode * CreateTreePI(const Elem_Type *ps, const Elem_Type *is, int n)
{
	if (ps == NULL || is == NULL || n < 1)
	{
		exit(0);
	}
	return CreatePI(ps, is, n);
}

BTNode * CreateIL(const Elem_Type *is, const Elem_Type *ls, int n)
{
	BTNode *s = NULL;
	if (n > 0)
	{
		s = BuyNode();
		s->data = ls[n - 1];
		int pos = isIndex(is, ls[n - 1], n);
		if (pos == -1)
		{
			exit(0);
		}
		s->leftChild = CreateIL(is, ls, pos);
		s->rightChild = CreateIL(is + pos + 1, ls + pos, n - pos - 1);
	}
	return s;
}

//根据中序和后序序列创建二叉树
BTNode * CreateTreeIL(const Elem_Type *is, const Elem_Type *ls, int n)
{
	if (is == NULL || ls == NULL || n < 1)
	{
		exit(0);
	}
	return CreateIL(is, ls, n);
}

//前序遍历
void PreOrder(BTNode *ptr)
{
	if (ptr != NULL)
	{
		printf("%c", ptr->data);
		PreOrder(ptr->leftChild);
		PreOrder(ptr->rightChild);
	}
}

//递归中序遍历
void InOrder(BTNode *ptr)
{
	if (ptr != NULL)
	{
		InOrder(ptr->leftChild);
		printf("%c", ptr->data);
		InOrder(ptr->rightChild);
	}
}

//递归后续遍历
void PastOrder(BTNode *ptr)
{
	if (ptr != NULL)
	{
		PastOrder(ptr->leftChild);
		PastOrder(ptr->rightChild);
		printf("%c", ptr->data);
	}
}

//非递归前序遍历
void NicePreOrder(BTNode *ptr)
{
	if (ptr == NULL)
	{
		return;
	}
	stack<BTNode *>sta;
	BTNode *p = ptr;
	sta.push(p);
	printf("%c", sta.top()->data);
	p = p->leftChild;
	while (p != NULL)
	{
		printf("%c", p->data);
		sta.push(p);
		p = p->leftChild;
	}

	while (!sta.empty())
	{
		p = sta.top();
		sta.pop();
		if (p->rightChild != NULL)
		{
			p = p->rightChild;
			while (p != NULL)
			{
				printf("%c", p->data);
				sta.push(p);
				p = p->leftChild;
			}
		}
	}
}

//非递归中序遍历
void NiceInOrder(BTNode *ptr)
{
	if (ptr == NULL)
	{
		return;
	}
	stack<BTNode *> sta;
	BTNode *p = ptr;
	sta.push(p);

	while (p->leftChild != NULL)
	{
		sta.push(p->leftChild);
		p = p->leftChild;
	}

	while (!sta.empty())
	{
		p = sta.top();
		printf("%c", p->data);
		sta.pop();

		if (p->rightChild != NULL)
		{
			p = p->rightChild;
			sta.push(p);
			while (p->leftChild != NULL)
			{
				sta.push(p->leftChild);
				p = p->leftChild;
			}
		}
	}
}

//非递归后续遍历
void NicePastOrder(BTNode *ptr)
{
	if (ptr == NULL)
	{
		return;
	}
	stack<BTNode *> sta;
	BTNode *p = ptr;
	BTNode *visited = NULL;

	while (p != NULL || !sta.empty())
	{
		while (p != NULL)
		{
			sta.push(p);
			p = p->leftChild;
		}

		p = sta.top();

		if (p->rightChild == NULL || p->rightChild == visited)
		{
			printf("%c", p->data);
			visited = p;
			sta.pop();
			p = NULL;
		}
		else
		{
			p = p->rightChild;
		}
	}
}

void StkNiceInOrder(BTNode *ptr)
{
	if (ptr == NULL)
	{
		return;
	}

	stack<BTNode *> sta;
	BTNode *p = ptr;
	sta.push(p);

	while (!sta.empty())
	{
		p = sta.top();
		if (p->tag == 0)
		{
			p->tag = 1;
		}
		else if (p->tag == 1)
		{
			p->tag++;
			if (p->leftChild != NULL)
			{
				p = p->leftChild;
				sta.push(p);
			}
			else//左孩子为空，打印当前结点
			{
				printf("%c", p->data);
				//如果左右孩子为空，则直接从栈中删除当前结点，并将tag置为0
				if (p->rightChild == NULL)
				{
					p->tag = 0;
					sta.pop();
				}
			}
		}
		else if (p->tag == 2)//tag为2表示右孩子结点还未访问
		{
			//从栈中删除清空当前结点
			p->tag = 0;
			sta.pop();

			if (p->leftChild != NULL)//当前结点未被打印
			{
				printf("%c", p->data);
			}

			if (p->rightChild != NULL)
			{
				p = p->rightChild;
				sta.push(p);
			}
		}
	}
}

void StkNiceInOrder2(BTNode *ptr)
{
	if (ptr == NULL)
	{
		return;
	}

	stack<StkNode> sta;
	sta.push(StkNode(ptr));
	StkNode node;

	while (!sta.empty())
	{
		node = sta.top();
		sta.pop();

		if (++node.poptim == 2)
		{
			printf("%c", node.pnode->data);
			sta.push(node);
			if (node.pnode->rightChild)
			{
				sta.push(StkNode(node.pnode->rightChild));
			}
		}
		else if (node.poptim == 1)
		{
			sta.push(node);
			if (node.pnode->leftChild)
			{
				sta.push(node.pnode->leftChild);
			}
		}
	}

}
//使用stack和在标记变量实现非递归遍历
void StkNicePastOrder(BTNode *ptr)
{
	if (ptr == NULL)
	{
		return;
	}
	stack<BTNode *> sta;
	BTNode *p = ptr;
	sta.push(p);

	while (!sta.empty())
	{
		p = sta.top();
		//	printf("%c%d", p->data, p->tag);
		if (p->tag == 0)
		{
			p->tag = 1;
		}
		else if (p->tag == 1)
		{
			p->tag++;
			if (p->leftChild != NULL)
			{
				p = p->leftChild;
				sta.push(p);
			}
		}
		else if (p->tag == 2)
		{
			p->tag++;
			if (p->rightChild != NULL)
			{
				p = p->rightChild;
				sta.push(p);
			}
		}
		else if (p->tag == 3)
		{
			printf("%c", p->data);
			p->tag = 0;
			sta.pop();
		}
	}
}

void StkNicePastOrder2(BTNode *ptr)
{
	if (ptr == NULL)
	{
		return;
	}

	stack<StkNode> sta;
	sta.push(StkNode(ptr));
	StkNode node;

	while (!sta.empty())
	{
		node = sta.top();
		sta.pop();

		if (node.poptim == 0)
		{
			node.poptim++;
			sta.push(node);
		}
		else if (node.poptim == 1)
		{
			node.poptim++;
			sta.push(node);
			if (node.pnode->leftChild != NULL)
			{
				sta.push(StkNode(node.pnode->leftChild));
			}
		}
		else if (node.poptim == 2)
		{
			node.poptim++;
			sta.push(node);
			if (node.pnode->rightChild != NULL)
			{
				sta.push(StkNode(node.pnode->rightChild));
			}
		}
		else if (node.poptim == 3)
		{
			printf("%c", node.pnode->data);
		}
	}
}

BTNode * Parent(BTNode *ptr, BTNode *child)
{
	if (ptr == NULL || ptr->leftChild == child ||
		ptr->rightChild == child)
	{
		return ptr;
	}
	else
	{
		BTNode *p = Parent(ptr->leftChild, child);
		if (p == NULL)
		{
			p = Parent(ptr->rightChild, child);
		}
		return p;
	}
}

//寻找双亲结点
BTNode * FindParent(BTNode *ptr, BTNode *child)
{
	if (ptr == NULL || child == NULL || child == ptr)
	{
		return NULL;
	}
	else
	{
		return Parent(ptr, child);
	}
}

//寻找两个结点的最近双亲
BTNode * FindNearParent(BTNode *ptr, BTNode *child1, BTNode *child2)
{
	if (ptr == NULL || child1 == NULL || child2 == NULL)
	{
		return NULL;
	}
	if (ptr == child1 || ptr == child2)
	{
		return ptr;
	}
	//左子树中查找两个结点并返回查找结果
	BTNode *pLeft = FindNearParent(ptr->leftChild, child1, child2);
	//右子树中查找两个结点并返回查找的结果
	BTNode *pRight = FindNearParent(ptr->rightChild, child1, child2);

	//如果左子树中没找到，则断定两个结点都在右子树中，
	//可以返回右子树中的查询结果，否则需要结合左右子树的查询
	//结果并作出判断
	if (pLeft == NULL)
	{
		return pRight;
	}

	//如果右子树没找到，则断定两个结点都在左子树中，可以
	//返回左子树的查询结果，否则需要结合左右子树的查询结果来共同判定
	if (pRight == NULL)
	{
		return pLeft;
	}

	//如果左右子树中都找到两个结点之一，则ptr就是最低公共祖先结点，返回即可
	return ptr;
}

//非递归层序遍历
void NiceLevelOrder(BTNode *ptr)
{
	if (ptr == NULL)
	{
		return;
	}
	queue<BTNode*> que;
	BTNode *p = ptr;
	que.push(p);

	while (!que.empty())
	{
		p = que.front();
		printf("%c", p->data);
		que.pop();
		if (p->leftChild != NULL)
		{
			que.push(p->leftChild);
		}

		if (p->rightChild != NULL)
		{
			que.push(p->rightChild);
		}
	}
}

//层序遍历，使用容器
void LevelOrder(BTNode *ptr)
{
	if (ptr == NULL)
	{
		return;
	}
	vector<BTNode*> vec;
	BTNode *p = ptr;
	vec.push_back(p);

	//存放当前结点在vector中的下标
	int cur = 0;
	while (cur < vec.size())
	{
		printf("%c", vec[cur]->data);
		if (vec[cur]->leftChild != NULL)
		{
			vec.push_back(vec[cur]->leftChild);
		}

		if (vec[cur]->rightChild != NULL)
		{
			vec.push_back(vec[cur]->rightChild);
		}
		++cur;
	}
}

void LevelOrder2(BTNode *ptr)
{
	if (ptr == NULL)
	{
		return;
	}
	int depth = BTDepth(ptr);
	for (int i = 1; i <= depth; i++)
	{
		Print_K_Level(ptr, i);
	}
}
//得到树的的高度
int BTDepth(BTNode *ptr)
{
	if (ptr == NULL)
	{
		return 0;
	}
	int left, right;
	if (ptr->leftChild != NULL)
	{
		left = BTDepth(ptr->leftChild);
	}
	else
	{
		left = 0;
	}

	if (ptr->rightChild != NULL)
	{
		right = BTDepth(ptr->rightChild);
	}
	else
	{
		right = 0;
	}
	return left > right ? left + 1 : right + 1;
}

//得到树中结点的个数
int Size(BTNode *ptr)
{
	if (ptr == NULL)
	{
		return 0;
	}
	int left = Size(ptr->leftChild);
	int right = Size(ptr->rightChild);
	return left + right + 1;
}

int Size2(BTNode *ptr)
{
	static int count = 0;
	if (ptr != NULL)
	{
		count++;
		Size2(ptr->leftChild);
		Size2(ptr->rightChild);
	}
	return count;
}

//判断是否是满二叉树
bool Is_Full_BinaryTree(BTNode *ptr)
{
	if (ptr == NULL)
	{
		return false;
	}

	int depth = BTDepth(ptr);
	int size = Size(ptr);
	printf("%d\n", (int)pow(2, depth) - 1);
	return (int)pow(2, depth) - 1 == size;
}

//判断是否是完全二叉树
bool Is_Comp_BinaryTree(BTNode *ptr)
{
	if (ptr == NULL)
	{
		return false;
	}
	queue<BTNode*> que;
	BTNode *p = ptr;
	que.push(p);

	//判断队列中当前结点的上一个结点是否是双分支结点，
	//若是则为false,若不是则为true
	bool flag = false;
	while (!que.empty())
	{
		p = que.front();
		que.pop();
		if (flag)
		{
			if (p->leftChild != NULL || p->rightChild != NULL)
			{
				return false;
			}
		}
		else
		{
			if (p->leftChild != NULL && p->rightChild != NULL)
			{
				que.push(p->leftChild);
				que.push(p->rightChild);
			}
			else if (p->rightChild != NULL)
			{
				return false;
			}
			else if (p->leftChild != NULL)
			{
				que.push(p->leftChild);
				flag = true;
			}
			else
			{
				flag = true;
			}
		}
	}
	return true;
}

//判断是否是平衡二叉树
bool Is_Balance_BinaryTree(BTNode *ptr)
{
	if (ptr == NULL)
	{
		return true;
	}

	int diff = BTDepth(ptr->leftChild) - BTDepth(ptr->rightChild);
	if (diff < -1 || diff > 1)
	{
		return false;
	}

	return Is_Balance_BinaryTree(ptr->leftChild) && Is_Balance_BinaryTree(ptr->rightChild);
}

bool IsBalance(BTNode *ptr, int *pDepth)
{
	if (ptr == NULL)
	{
		*pDepth = 0;
		return true;
	}
	int left, right;
	if (IsBalance(ptr->leftChild, &left) && IsBalance(ptr->rightChild, &right))
	{
		int diff = left - right;
		if (diff >= -1 && diff <= 1)
		{
			*pDepth = 1 + (left > right ? left : right);
			return true;
		}
	}
	return false;
}

bool Is_Balance_BinaryTree2(BTNode *ptr)
{
	if (ptr == NULL)
	{
		return true;
	}
	int depth = 0;
	return IsBalance(ptr, &depth);
}

bool Equal(BTNode *pa, BTNode *pb)
{
	if (pa == NULL && pb == NULL)
	{
		return true;
	}

	if ((pa == NULL && pb != NULL) || (pa != NULL && pb == NULL))
	{
		return false;
	}

	if (pa->data != pb->data)
	{
		return false;
	}

	return Equal(pa->leftChild, pb->leftChild) && Equal(pa->rightChild, pb->rightChild);
}

void Destroy(BTNode **ptr)
{
	if (ptr == NULL || *ptr == NULL)
	{
		return;
	}

	if ((*ptr)->leftChild != NULL)
	{
		Destroy(&(*ptr)->leftChild);
	}

	if ((*ptr)->rightChild != NULL)
	{
		Destroy(&(*ptr)->rightChild);
	}

	FreeNode(*ptr);
	*ptr = NULL;
}

void Print_k(BTNode *ptr, int k)
{
	if (ptr == NULL)
	{
		return;
	}

	if (k == 1)
	{
		printf("%c", ptr->data);
	}
	else
	{
		Print_k(ptr->leftChild, k - 1);
		Print_k(ptr->rightChild, k - 1);
	}
}

void Print_K_Level(BTNode *ptr, int k)
{
	if (ptr == NULL)
	{
		return;
	}
	int depth = BTDepth(ptr);
	if (k < 1 || k > depth)
	{
		return;
	}
	Print_k(ptr, k);
}

bool Is_BSTree(BTNode *ptr)
{
	if (ptr == NULL)
	{
		return NULL;
	}
	stack<BTNode*> sta;
	BTNode *p = ptr;
	sta.push(p);
	int max = 0;

	while (!sta.empty())
	{
		while (p->leftChild != NULL)
		{
			sta.push(p->leftChild);
			p = p->leftChild;
		}
		p = sta.top();
		sta.pop();
		if (p->data >= max)
		{
			max = p->data;
			//	printf("%c", p->data);
		}
		else
		{
			return false;
		}

		if (p->rightChild != NULL)
		{
			p = p->rightChild;
			sta.push(p);
			while (p->leftChild != NULL)
			{
				sta.push(p->leftChild);
				p = p->leftChild;
			}
		}
	}
	return true;
}

int SizeLeaf(BTNode *ptr)
{
	if (ptr == NULL)
	{
		return 0;
	}

	if (ptr->leftChild == NULL && ptr->rightChild == NULL)
	{
		return 1;
	}

	return SizeLeaf(ptr->leftChild) + SizeLeaf(ptr->rightChild);
}

int SizeBinaryBranch(BTNode *ptr)
{
	if (ptr == NULL)
	{
		return 0;
	}

	if (ptr->leftChild != NULL && ptr->rightChild != NULL)
	{
		return 2 + SizeBinaryBranch(ptr->leftChild) + SizeBinaryBranch(ptr->rightChild);
	}

	if (ptr->leftChild != NULL)
	{
		return 1 + SizeBinaryBranch(ptr->leftChild);
	}

	if (ptr->rightChild != NULL)
	{
		return 1 + SizeBinaryBranch(ptr->rightChild);
	}

	return 0;
}

int SizeOneBranch(BTNode *ptr)
{
	if (ptr == NULL)
	{
		return 0;
	}

	if (ptr->leftChild != NULL && ptr->rightChild != NULL)
	{
		return SizeOneBranch(ptr->leftChild) + SizeOneBranch(ptr->rightChild);
	}

	if (ptr->leftChild != NULL)
	{
		return 1 + SizeOneBranch(ptr->leftChild);
	}

	if (ptr->rightChild != NULL)
	{
		return 1 + SizeOneBranch(ptr->rightChild);
	}

	return 0;
}

int SizeOneLBranch(BTNode *ptr)
{
	if (ptr == NULL)
	{
		return 0;
	}
	if (ptr->leftChild != NULL && ptr->rightChild != NULL)
	{
		return SizeOneLBranch(ptr->leftChild) + SizeOneLBranch(ptr->rightChild);
	}
	if (ptr->leftChild != NULL)
	{
		return 1 + SizeOneLBranch(ptr->leftChild);
	}
	if (ptr->rightChild != NULL)
	{
		return SizeOneLBranch(ptr->rightChild);
	}
	return 0;
}


int SizeOneRBranch(BTNode *ptr)
{
	if (ptr == NULL)
	{
		return 0;
	}
	if (ptr->leftChild != NULL && ptr->rightChild != NULL)
	{
		return SizeOneRBranch(ptr->leftChild) + SizeOneRBranch(ptr->rightChild);
	}
	if (ptr->leftChild != NULL)
	{
		return SizeOneRBranch(ptr->leftChild);
	}
	if (ptr->rightChild != NULL)
	{
		return 1 + SizeOneRBranch(ptr->rightChild);
	}
	return 0;
}