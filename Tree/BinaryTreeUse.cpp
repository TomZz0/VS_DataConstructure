#include<iostream>
#include"BinaryTree.h"
using namespace std;
int main(){
    BiTree T = getBiTree();
    InOrderTraverse(T);
    cout<<Depth(T)<<'\n';
    cout<<getNumOfNode(T);
    return 0;
}