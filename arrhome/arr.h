#include<iostream>
using namespace std;
typedef struct List{
    int * arr;
    int length;
}*SqList;
void deleteItems(SqList &sq,int item);
void showList(SqList sq);