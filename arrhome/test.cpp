#include<iostream>
using namespace std;
#include "arr.h"
int main(){

    SqList sq = new struct List;
    cout<<"please input the length of arr:";
    int n;cin>>n;
    sq->arr = new int[n];
    sq->length = 0;
    cout<<"put in every number please:";
    for (int i = 0; i < n; i++)
    {
        cin>>sq->arr[i];
        sq->length++;
    }
    showList(sq);
    cout<<"\nput in the number you want to delete:"; int item;cin>>item;
    deleteItems(sq,item);
    showList(sq);
    return 0;
}