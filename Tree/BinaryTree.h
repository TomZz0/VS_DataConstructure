#include<stdio.h>
#include<iostream>
using namespace std;

typedef struct BiTNode{
    char ch;
    struct BiTNode *left,*right;
}BiTNode,*BiTree;
void frontOrderTraverse(BiTree T); //前序遍历
void InOrderTraverse(BiTree T);    //中序遍历
void backOrderTraverse(BiTree T);  //后序遍历
BiTree getBiTree();                //输入字符得到一颗二叉树
void createBiTree_Front(BiTree &T);//前序创建二叉树
void createBiTree_In(BiTree &T);   //中序创建二叉树
void createBiTree_Back(BiTree &T); //后序创建二叉树
BiTree getEqualTree(BiTree T);     //得到一颗与传入的树相同的二叉树
void Copy(BiTree T,BiTree& newT);  //二叉树的复制方法
int Depth(BiTree T);              //计算二叉树的深度并返回
int Max(int x,int y);             //返回较大值
int getNumOfNode(BiTree T);       //获取节点个数