
#include"SeqStack.h"

PSeqStack createEmptyStack_seq(int m) {
	//使用malloc分配空间 这时s为一个数组
	PSeqStack stack = (PSeqStack)malloc(sizeof(struct SeqStack));
	if (stack != NULL) {
		stack->s = (int*)malloc(sizeof(int) * m);
		if (stack->s) {
			stack->MAXNUM = m;
			stack->t = -1;
			return stack;
		}
		else {
			free(stack);
		}
	}
	printf("分配失败");
	return NULL;

}
int isEmptyStack_seq(PSeqStack p) {
	return p->t == -1 ? 1 : 0;
}
void push_seq(PSeqStack p, int x) {
	//如果栈已满 输出OverFlow 返回
	if (p->t >= p->MAXNUM - 1) {
		printf("OverFlow!");
		return;
	}
	//令栈顶指针右移 赋值
	(p->t)++;
	p->s[p->t] = x;
}
void pop_seq(PSeqStack p) {
	//删除栈顶元素
	if (p->t == -1) {
		printf("UnderFlow!");
		return;
	}
	(p->t)--;
}
int top_seq(PSeqStack p) {
	if (p->t == -1) {
		printf("Empty Stack!");
		return EOF;
	}
	return p->s[p->t];
}