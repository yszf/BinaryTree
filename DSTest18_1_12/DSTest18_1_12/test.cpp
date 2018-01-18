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

	printf("�ݹ������������\n");
	PreOrder(t);
	printf("\n");

	InOrder(t);
	printf("\n");

	PastOrder(t);
	printf("\n");

	printf("�ǵݹ������������\n");
	NicePreOrder(t);
	printf("\n");

	NiceInOrder(t);
	printf("\n");

	NicePastOrder(t);
	printf("\n");

	printf("�ǵݹ���������\n");
	NiceLevelOrder(t);
	printf("\n");

	printf("ʹ��vector�������в��������\n");
	LevelOrder(t);
	printf("\n");

	//��ȡ�����������
	int depth = BTDepth(t);
	printf("depth = %d\n", depth);

	//�ж��Ƿ�����������
	printf("%d\n", Is_Full_BinaryTree(t));

	//�ж��Ƿ�����ȫ������
	printf("%d\n", Is_Comp_BinaryTree(t));

	StkNiceInOrder2(t);
	printf("\n");

	//�ǵݹ��������
	StkNicePastOrder2(t);
	printf("\n");

	//	Destroy(&t);

//	StkNicePastOrder(t);
//	printf("\n");

	Print_K_Level(t, 2);
	printf("\n");

	LevelOrder2(t);
	printf("\n");

	//�ж��Ƿ��Ƕ���������
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

	//�ж��Ƿ���ƽ�������
	printf("%d\n",Is_Balance_BinaryTree(t));
	printf("%d\n", Is_Balance_BinaryTree2(t));
	
	//�е�
	printf("%d\n", Equal(t,t));

	//��ӡҶ�ӽ�����Ŀ
	printf("%d\n",SizeLeaf(t));

	//��ӡ��֧����Ŀ
	printf("%d\n", SizeBinaryBranch(t));
	
	//��ӡ����֧����Ŀ
	printf("%d\n", SizeOneBranch(t));

	//��ӡ�󵥷�֧����Ŀ
	printf("%d\n", SizeOneLBranch(t));

	//��ӡ�ҵ���֧����Ŀ
	printf("%d\n", SizeOneRBranch(t));

	return 0;
}

