#pragma once

typedef char Elem_Type;
#define END '#'

typedef struct BTNode
{
	struct BTNode *leftChild;
	struct BTNode *rightChild;
	int tag;
	Elem_Type data;
}BTNode, *BinaryTree;

struct StkNode
{
	BTNode *pnode;
	int poptim;
public:
	StkNode(BTNode *p = nullptr) :pnode(p), poptim(0) {}
};

void MakeTree(BTNode **ptr);
BTNode * BuyNode();
void FreeNode(BTNode *ptr);
BTNode * FindIs(BTNode *ptr,Elem_Type x);
//通过前序遍历+END构建二叉树
BTNode * CreateTree1();
//指针的引用
BTNode * CreateTree2(Elem_Type *&str);
//** const
BTNode * CreateTree3(Elem_Type ** const str);
void CreateTree4(BTNode *&ptr);
void CreateTree5(BTNode ** const pptr);
BTNode * CreateTreePI(const Elem_Type *ps, const Elem_Type *is, int n);
BTNode * CreateTreeIL(const Elem_Type *is, const Elem_Type *ls, int n);
void PreOrder(BTNode *ptr);
void InOrder(BTNode *ptr);
void PastOrder(BTNode *ptr);

void NicePreOrder(BTNode *ptr);
void NiceInOrder(BTNode *ptr);
void NicePastOrder(BTNode *ptr);

void StkNiceInOrder(BTNode *ptr);
void StkNiceInOrder2(BTNode *ptr);

void StkNicePastOrder(BTNode *ptr);
void StkNicePastOrder2(BTNode *ptr);

BTNode * FindParent(BTNode *ptr,BTNode *child);
BTNode * FindNearParent(BTNode *ptr,BTNode *child1,BTNode *child2);
void NiceLevelOrder(BTNode *ptr);
void LevelOrder(BTNode *ptr);
void LevelOrder2(BTNode *ptr);

bool Is_Full_BinaryTree(BTNode *ptr);
bool Is_Comp_BinaryTree(BTNode *ptr);
bool Is_Balance_BinaryTree(BTNode *ptr);
bool Is_Balance_BinaryTree2(BTNode *ptr);
bool Is_BSTree(BTNode *ptr);
bool Equal(BTNode *pa, BTNode *pb);

//2-3树 ---------RB_Tree

int BTDepth(BTNode *ptr);
int Size(BTNode *ptr);
int Size2(BTNode *ptr);
void Destroy(BTNode **ptr);
void Print_K_Level(BTNode *ptr, int k);
int SizeLeaf(BTNode *ptr);
int SizeBinaryBranch(BTNode *ptr);
int SizeOneBranch(BTNode *ptr);
int SizeOneLBranch(BTNode *ptr);
int SizeOneRBranch(BTNode *ptr);
