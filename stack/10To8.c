#include<stdio.h>
#include"SeqStack.h"
void decToeig(int n);
int main() {
	printf("head");
	decToeig(238);	
	return 0;
}
void decToeig(int n) {
	PSeqStack p = createEmptyStack_seq(100);
	while (n != 0) {
		push_seq(p, n % 8);
		n /= 8;
	}
	while (!isEmptyStack_seq(p)) {
		printf("%d", top_seq(p));
		pop_seq(p);
	}
}