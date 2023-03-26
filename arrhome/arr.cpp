#include"arr.h"
void showList(SqList sq){
    for (int i = 0; i < sq->length; i++)
    {
        cout<<sq->arr[i]<<" ";
    }
    cout<<"\n";
}
void deleteItems(SqList &sq,int item){
    int index,i; index = i = 0;
    while (index<sq->length)
    {
        while(sq->arr[index] == item){
                index++;
                sq->length--;
        } 
        sq->arr[i++] = sq->arr[index++];
    }
}