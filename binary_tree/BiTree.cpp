#include "BiTree.h"
#include <stdio.h>
#include <stdlib.h>

#define FORM "%c"
#define OUTPUT_FORM "%c"

int Visit(TElemType e)
{
	if(e=='\0')
		return -1;

	printf(OUTPUT_FORM, e);
}

void CreateBiTree(BiTree pBT)
{
 	TElemType ch;
	scanf(FORM, &ch);
	if(ch=='\0')
		pBT = NULL;
	else
	{
		pBT = (BiTree)malloc(sizeof(BiTNode));
		if(!pBT)
			exit(-1);
		pBT->data = ch;
		CreateBiTree(pBT->lchild);
		CreateBiTree(pBT->rchild);
	}
}

void DestroyTree(BiTree pBT)
{
	if(pBT)
	{
		if(pBT->lchild)
			DestroyTree(pBT->lchild);

		if(pBT->rchild)
			DestroyTree(pBT->rchild);

		free(pBT);
		pBT = NULL;

	}
}

int BiTreeEmpty(BiTree pBT)
{
	if(pBT)
		return 0;
	else
		return -1;
}

int BiTreeDepth(BiTree pBT)
{
	int ileft_depth, iright_depth;
	if(!pBT)
		return 0;
	if(pBT->lchild)
		ileft_depth = BiTreeDepth(pBT->lchild);
	else if(pBT->rchild)
		iright_depth = BiTreeDepth(pBT->rchild);
	else
		iright_depth = 0;
	return ileft_depth >iright_depth?ileft_depth + 1:iright_depth + 1;
}

int PreOrderTravers(BiTree pBT )
{
	if(pBT)
	{
		if(Visit(pBT->data))
			if(PreOrderTravers(pBT->lchild))
				if(PreOrderTravers(pBT->rchild))
					return 0;
	}
	else
		return  -1;
}

int MidOrderTravers(BiTree pBT)
{
	
	if(pBT)
	{
		if((pBT->lchild))
				MidOrderTravers(pBT->lchild);
		else
			Visit(pBT->data);

		if((pBT->rchild))
				MidOrderTravers(pBT->rchild);
		else
			Visit(pBT->data);
	}
	else
		return  -1;
}

int PostOrderTravers(BiTree pBT)
{
	 if(pBT)
	 {
		 if((pBT->lchild))
			 PostOrderTravers(pBT->lchild);
		 if((pBT->rchild))
			 PostOrderTravers(pBT->rchild);
		
		 Visit(pBT->data);
	 }
}
