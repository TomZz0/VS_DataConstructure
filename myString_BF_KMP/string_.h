#include<stdio.h>
#define MAXLEN  255
#define SINGMAX 80
typedef struct myString1
{
    char ch[MAXLEN+1];
    int length;
}S1;
typedef struct myString2
{
    char *ch;
    int length;
}S2;
typedef struct myString3{
    char ch[SINGMAX];
    struct myString3 *next;
}S3;
typedef struct {
    S3* head,*tail;
    int length ;
}LinkedString;
int BF(S1 s1,S1 s2,int pos);
void push(S2 &s,char c);
void printf(S1 s1);
void printf(int *arr,int length);
int KMP(S2 &s1,S2 &s2,int next[]);
void getNext(S2 &s,int next[]);
void charArr_copy(char *arr1,char*arr2,int length);