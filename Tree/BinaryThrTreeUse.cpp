#include<iostream>
#include"BinaryThrTree.h"

using namespace std;

int main(){
    BiThrTree T = getBiThrTree();
    BiThrTree Thrt;
    InOrderThreading(Thrt,T);
    InOrderTraverse_Thr(T);
    return 0;
}