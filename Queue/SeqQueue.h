#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"SeqQueue.c"
//方法区
int QueueLength(PSeqQueue p);			//求队列长度
PSeqQueue createEmptyQueue_seq(int m);//创建空队列操作
int isEmptyQueue_seq(PSeqQueue p);//判断队列是否为空
void enQueue_seq(PSeqQueue p, int x);//进队操作 在队尾插入一个元素
void deQueue_seq(PSeqQueue p);//出队操作
int frontQueue_seq(PSeqQueue p);//取队列头元素