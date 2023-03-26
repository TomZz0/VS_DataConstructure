#include<iostream>
using namespace std;

typedef struct BiThrNode{
    //线索二叉树的定义
    char ch;
    //若节点的左右子树存在就指向 否则左指针指向前驱节点 右指针指向后继节点
    //这里的前驱后继指的是中序遍历的前驱后继
    struct BiThrNode *left,*right;
    int LTag,RTag;
}BiThrNode,*BiThrTree;

void InThreading(BiThrTree p);//以p为根的树的线索化
void InOrderThreading(BiThrTree &Thrt,BiThrTree T);//将带头节点的树线索化
void InOrderTraverse_Thr(BiThrTree T);
BiThrTree getBiThrTree(); 
void createBiThrTree_Front(BiThrTree &T); 
