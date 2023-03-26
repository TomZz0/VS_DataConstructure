#include <iostream>
#include "string_.h"
using namespace std;
int main(){
    S2 s;
    s.length=0;
    s.ch = (char*)malloc(sizeof(char)*100);
    S2 ss;ss.length=0;ss.ch = (char*)malloc(sizeof(char)*100);
      char s1[] = {"abcaby"};
      char s2[] = {"abxabcabcaby"};
     
      charArr_copy(s.ch,s1,7);
      s.length = 7;//注意设置长度
      charArr_copy(ss.ch,s2,13);
      ss.length = 13;
    int *arr = new int[s.length];
    getNext(s,arr);
    printf("%d",KMP(ss,s,arr));

    system("pause");
    return 0;
}
