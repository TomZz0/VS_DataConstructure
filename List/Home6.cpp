#include<iostream>
#include"LinkedList.h"
using namespace std;
int main(){
    LinkedList list = InitList();
    cout<<"please input the length of the LinkedList:";
    int length; cin>>length;
    cout<<"please input every value of the node:";
    for (int i = 0; i < length; i++)
    {
        int x; cin>>x;
        insert_back(list,x);
    }
    showList(list);
    cout<<"the bigget one is"<<getMax(list)->data;
    reverse2(list);
    showList(list);
    return 0;
}