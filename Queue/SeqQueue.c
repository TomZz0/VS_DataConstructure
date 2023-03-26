#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
//定义队列数据结构
typedef struct SeqQueue {
	int MAXNUM;  // 最大存储数量
	int f, r;	//f指向头元素所在位置 r指向尾元素的下一个元素
	int* q;
}*PSeqQueue;


PSeqQueue createEmptyQueue_seq(int m) {
	PSeqQueue p = (PSeqQueue)malloc(sizeof(struct SeqQueue));
	if (p) {
		p->q = (int*)malloc(sizeof(int)*m);
		if (p->q) {
			p->MAXNUM = m;
			p->f = p->r = 0;
			return p;
		}
		else free(p);
	}
	printf("空间分配失败");
	return NULL;
}
int isEmptyQueue_seq(PSeqQueue p) {
	return p->f == p->r;
}
int QueueLength(PSeqQueue p) {
	//由于是循环队列 r-f有可能是负数 所以将其加上最大容量 再对最大容量取余即可
	return (p->r - p->f + p->MAXNUM) % p->MAXNUM;
}
void enQueue_seq(PSeqQueue p, int x) {
	//如果已满
	//巧用取模 进队过程中如果有出队操作 队列前边就会空下空间不能复用
	//这时让r=r+1再对MAXNUM取模 r就会回到队列前边的位置就能复用空间 
	//如果回到前边的位置 发现其等于f 说明队列真正被装满了
	// 当全部装满的时候 按此法r就会等于0 若此时f也为0 就会和空队列情况混淆
	//为了避免与空队列(即f = r)相混淆  空出一个位置 当有MAXNUM-1个元素时认为已满
	if ((p->r + 1) % p->MAXNUM == p->f) {
		printf("Full Queue"); 
	}
	else {
		p->q[p->r] = x;
		p->r = (p->r + 1) % p->MAXNUM;
	}
	
}
void deQueue_seq(PSeqQueue p) {
	//如果是空队列 
	if (p->f == p->r) {
		printf("Empty Queue");
	}
	else {
		//同样使用取模操作
		p->f = (p->f + 1) % p->MAXNUM;
	}
}
int frontQueue_seq(PSeqQueue p) {
	if (p->f == p->r) {
		printf("Empty Queue");
		return EOF;
	}
	return p->q[p->f];
}