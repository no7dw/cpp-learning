#ifndef __BI_TREE_H
#define __BI_TREE_H

#define TElemType char

typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

int Visit(TElemType e);
void CreateBiTree(BiTree pBT);
void Destroy(BiTree pBT);
int BiTreeEmpty(BiTree pBT);
int BiTreeDepth(BiTree pBT);
int PreOrderTravers(BiTree pBT);
int MidOrderTravers(BiTree pBT);
int PostOrderTravers(BiTree pBT);

#endif

