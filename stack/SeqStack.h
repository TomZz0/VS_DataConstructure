#ifndef SEQSTACK_H
#define SEQSTACK_H
#include<stdio.h>
#include<malloc.h>
//.c文件 实现.h文件中声明的函数
struct SeqStack {
	int MAXNUM;  //最大存储数量
	int t;		//当前栈顶位置
	int* s;
};   //PSeqStack指一个栈的地址
typedef struct SeqStack* PSeqStack;
PSeqStack createEmptyStack_seq(int m);
int isEmptyStack_seq(PSeqStack p);
void push_seq(PSeqStack p, int x);
void pop_seq(PSeqStack p);
int top_seq(PSeqStack p);
#endif