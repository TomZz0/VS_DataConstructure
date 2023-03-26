#include<iostream>
#include<string.h>
using namespace std;
typedef char **HuffmanCode;
typedef struct {
    int weight;  //节点的权值
    int parent,left,right; //双亲,左右孩子的下标
}HTNode,*HuffmanTree;
//哈夫曼树查找两个最小值 length为下标最大值
void Select(HuffmanTree &HT,int length,int &index1,int &index2); //选出两个最小的
HuffmanTree getHuffmanTree(int n);//利用CreateHuffmanTree得到一颗哈夫曼树
void CreateHuffmanTree(HuffmanTree &HT,int n);
void showHTNode(HTNode ht);//打印输出节点
void showHuffmanTree(HuffmanTree HT,int n);//打印整个哈夫曼树的存储结构
int* CreatHuffmanCode(HuffmanTree HT,HuffmanCode &HC,int n);//获取哈夫曼编码
void showHTCode(HuffmanCode &HC);