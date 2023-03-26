#include<stdio.h>
#include<malloc.h>
#include "string_.h"

int BF(S1 s1,S1 s2,int pos){
    char *maj = s1.ch;
    char *edg = s2.ch;
    int i = pos,j=0;
    while(i<s1.length&&j<s2.length){
        if(maj[i] == edg[j]){
            i++,j++;
        }else{
            i=i-j+1;j=0;
        }
    }
    if(j>=s2.length){
        return i - j;
    }else{
        return -1;
    }
}
void printf(S1 s1){
    for(int i =0;i<s1.length;i++){
        printf("%c",s1.ch[i]);
    }
    printf("\n");
}
void printf(int *arr,int length){
    for(int i =0;i<length;i++){
        printf("%d",arr[i]);
    }
    printf("\n");
}
int KMP(S2 &s1,S2 &s2,int next[]){
    char *maj = s1.ch;char *edg = s2.ch;
    int i =0,j=0;
    while (i<s1.length&&j<s2.length)
    {
        if (maj[i] == edg[j])
        {
            i++,j++;
        }else if(j>0){
            j = next[j-1];
        }else{
            i++;
        }
    }
    return j>=s2.length?i-j:-1;
}
void getNext(S2 &s,int next[]){
    printf("%s",s.ch);
    int i =1;int j=0;
    next[j] = 0;
    while (i < s.length)
    {
       if (s.ch[i] == s.ch[j])
       {
            next[i] = j+1;
            i++;j++;
       }else{
            j = j-1>=0?next[j-1]:j;
            next[i] = j +( s.ch[i]==s.ch[j]?1:0);
            i++;
       }
       
    }
    printf(next,s.length);
}
void push(S2 &s,char c){
    s.ch[s.length++] = c;
}
void charArr_copy(char *arr1,char *arr2,int length){
    //字符数组拷贝
    for(int i=0;i<length;i++) arr1[i] = arr2[i];
}