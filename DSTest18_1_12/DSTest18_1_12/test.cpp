#include "binarytree.h"
#include <stdio.h>
#include <string.h>

int main()
{
	//char *ps = "ABDEGHCF";
	//char *is = "DBGEHAFC";
	//char *ls = "DGHEBFCA";

	//char *ps = "ABDECFG";
	//char *is = "DBEAFCG";
	//char *ls = "DEBFGCA";

	char *ps = "ABDEC";
	char *is = "DBEAC";
	char *ls = "DEBCA";

	//char *ps = "ABCDEFGH";
	//char *is = "CBEDFAGH";
	//char *ls = "CEFDBHGA";

	int n = strlen(ps);

	BinaryTree t;

	//	t = CreateTreePI(ps,is,n);
	//	t = CreateTreeIL(is,ls,n);

		//ABC##DE##F##G#H##
	//	t = CreateTree1();
	char *str = "ABC##DE##F##G#H##";
//	char *str = "DBA##C##FE##G##";
	t = CreateTree2(str);
	//	t = CreateTree3(&str);

	//	CreateTree4(t);
	//	CreateTree5(&t);

	printf("递归遍历二叉树：\n");
	PreOrder(t);
	printf("\n");

	InOrder(t);
	printf("\n");

	PastOrder(t);
	printf("\n");

	printf("非递归遍历二叉树：\n");
	NicePreOrder(t);
	printf("\n");

	NiceInOrder(t);
	printf("\n");

	NicePastOrder(t);
	printf("\n");

	printf("非递归层序遍历：\n");
	NiceLevelOrder(t);
	printf("\n");

	printf("使用vector容器进行层序遍历：\n");
	LevelOrder(t);
	printf("\n");

	//获取二叉树的深度
	int depth = BTDepth(t);
	printf("depth = %d\n", depth);

	//判断是否是满二叉树
	printf("%d\n", Is_Full_BinaryTree(t));

	//判断是否是完全二叉树
	printf("%d\n", Is_Comp_BinaryTree(t));

	StkNiceInOrder2(t);
	printf("\n");

	//非递归后续遍历
	StkNicePastOrder2(t);
	printf("\n");

	//	Destroy(&t);

//	StkNicePastOrder(t);
//	printf("\n");

	Print_K_Level(t, 2);
	printf("\n");

	LevelOrder2(t);
	printf("\n");

	//判断是否是二叉排序树
	printf("%d\n", Is_BSTree(t));

	printf("%d\n", Size(t));
	printf("%d\n", Size2(t));

	BTNode *res1 = FindIs(t, 'B');
	printf("%c\n", res1->data);
	BTNode *res2 = FindIs(t, 'E');
	printf("%c\n", res2->data);

	BTNode *parent = FindParent(t, res2);
	printf("%c\n", parent->data);

	BTNode *nearParent = FindNearParent(t, res1, res2);
	printf("%c\n",nearParent->data);

	//判断是否是平衡二叉树
	printf("%d\n",Is_Balance_BinaryTree(t));
	printf("%d\n", Is_Balance_BinaryTree2(t));
	
	//判等
	printf("%d\n", Equal(t,t));

	//打印叶子结点的数目
	printf("%d\n",SizeLeaf(t));

	//打印分支的数目
	printf("%d\n", SizeBinaryBranch(t));
	
	//打印单分支的数目
	printf("%d\n", SizeOneBranch(t));

	//打印左单分支的数目
	printf("%d\n", SizeOneLBranch(t));

	//打印右单分支的数目
	printf("%d\n", SizeOneRBranch(t));

	return 0;
}

