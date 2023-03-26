#include "BinaryTree.h"

void InOrderTraverse(BiTree T){
    //中序遍历二叉树
    if (T)
    {
        InOrderTraverse(T->left);
        cout<<T->ch;
        InOrderTraverse(T->right);
    }
    
}
void frontOrderTraverse(BiTree T){
    //前序遍历二叉树
    if (T)
    {
        cout<<T->ch;
        InOrderTraverse(T->left);
        InOrderTraverse(T->right);
    }
}
void backOrderTraverse(BiTree T){
    //后序遍历二叉树
    if (T)
    {
        InOrderTraverse(T->left);
        InOrderTraverse(T->right);
        cout<<T->ch;
    }
}
BiTree getBiTree(){
    BiTree T;
    createBiTree_Front(T);
    return T;
}
void createBiTree_Front(BiTree &T){
    //递归并按照前序顺序创建树
    char ch;
    cin>>ch;
    if (ch=='#') T=NULL;
    else 
    {
        T = new BiTNode;
        T->ch = ch;
        createBiTree_Front(T->left);
        createBiTree_Front(T->right);   
    }
}
void createBiTree_In(BiTree &T){
    //递归并按照中序顺序创建树
    char ch;
    cin>>ch;
    if (ch=='#') T=NULL;
    else 
    {
        createBiTree_In(T->left);
        T = new BiTNode;
        T->ch = ch;
        createBiTree_In(T->right);   
    }
}
void createBiTree_Back(BiTree &T){
    //递归并按照后序顺序创建树
    char ch;
    cin>>ch;
    if (ch=='#') T=NULL;
    else 
    {
        createBiTree_Back(T->left);
        createBiTree_Back(T->right);   
         T = new BiTNode;
        T->ch = ch;
    }
}
BiTree getEqualTree(BiTree T){
    //复制一棵同T一样的树并返回
    BiTree newT;
    Copy(T,newT);
    return newT;
}
void Copy(BiTree T,BiTree& newT){
    //复制树 递归复制每个节点
    if (T)
    {
        newT = new BiTNode;
        newT->ch = T->ch;
        Copy(T->left,newT->left);
        Copy(T->right,newT->right);
    }else{
        newT = NULL;
        return;
    }
    
}
int Max(int x,int y){
    if (x>y) return x;
    return y;
    
}
int Depth(BiTree T){
    //计算二叉树的深度
    if (T==NULL) return 0;
    return 1 + Max(Depth(T->left),Depth(T->right));
}
int getNumOfNode(BiTree T){
    return T?1+getNumOfNode(T->left)+getNumOfNode(T->right):0;
}