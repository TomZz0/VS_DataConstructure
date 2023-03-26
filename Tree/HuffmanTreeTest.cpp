#include<iostream>
using namespace std;
#include "HuffmanTree.h"
int main(){
    //输入节点个数和每个节点权值 得到哈夫曼编码
    int n;
    cout<<"please input the num of node:";
    cin>>n;
    cout<<"\nput in every weight:";
    HuffmanTree HT = getHuffmanTree(n);
    showHuffmanTree(HT,n);
    HuffmanCode hfc;
    int * arr = CreatHuffmanCode(HT,hfc,n);
    cout<<"\n";
    for(int i=0;i<n;i++) cout<<arr[i];
    cout<<"\n";
    for(int i=1;i<= n;i++){
        for(int j=0;j<arr[i-1];j++){
            cout<<hfc[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}