#include<iostream>
using namespace std;
#include"CharStack.h"

int Matching();

int main(){
    if(Matching()){
        printf("yes");
    }else{
        printf("no");
    }
    system("pause");
    return 0;
}
int Matching(){
    CSeqStack p = createEmptyStackChar_seq(20);
    int flag = 1;
    char ch;
    cout<<"put in char:";
    cout<<"\n";
    cin>>ch;
    while(ch!='#'&&flag){ //#表示输出结束
        switch (ch)
        {
        case '[':;
        case '(':
            push_seq(p,ch);
            printf("this is %c",ch);
            break;
        case ')':
        if(!isEmptyStack_seq(p)&&top_seq(p)=='('){
            printf("pop\n");
            pop_seq(p);
        }else{
            flag = 0;
        }
        break;
        case ']':
        if(!isEmptyStack_seq(p)&&top_seq(p)=='['){
            printf("pop\n");
            pop_seq(p);
        }else{
            flag = 0;
        }
        break;
        }
        cout<<"put in a char:";
        cout<<"\n";
        cin>>ch;
    }
    if(isEmptyStack_seq(p)&&flag) return 1;
    return 0;
}