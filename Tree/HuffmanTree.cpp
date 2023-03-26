#include"HuffmanTree.h"
void Select(HuffmanTree &HT,int length,int &index1,int &index2){
    int index = 1;
    int min = INT32_MAX;
    for (int  i = 1; i <= length; i++)
    {
        if (HT[i].parent!=0) continue;
        if(HT[i].weight < min) {
            min = HT[i].weight;
            index  =i;
        } 
    }
    index1 = index; index = 1;min = INT32_MAX;
    for (int  i = 1; i <= length; i++)
    {
        if (HT[i].parent!=0||i==index1) continue;
        if(HT[i].weight < min) {
            min = HT[i].weight;
            index  =i;
        } 
    }
    index2 = index;
}
void CreateHuffmanTree(HuffmanTree &HT,int n){
    //构造哈夫曼树
    if (n<=1) return;
    int m = n*2-1;
    HT = new HTNode[m+1];  //0号位置不使用
    //左右孩子以及双亲 下标初始化为0
    for (int i = 0; i < m+1; i++) HT[i].parent = HT[i].left = HT[i].right = 0;
    for(int i=1;i<=n;i++) cin>>HT[i].weight; //输入前n个单元中叶子节点的权值
    showHuffmanTree(HT,n);//打印存储结构
    //=====初始化工作结束
    for (int i = n+1; i <= m; i++)
    {
        //通过n-1次选择，合并，删除创建哈夫曼树
        int s1,s2 = 0;
        //选择两个双亲域为零且最小的节点 将下标赋予s1 s2
        Select(HT,i-1,s1,s2);
       
       //得到新节点i 删除s1 s2即将其双亲域改为i
       HT[s1].parent = HT[s2].parent = i;
       HT[i].left = s1; HT[i].right = s2; //设置i的左右孩子
       HT[i].weight = HT[s1].weight + HT[s2].weight; //设置权重
    }
}
HuffmanTree getHuffmanTree(int n){
    HuffmanTree HT;
    CreateHuffmanTree(HT,n);
    return HT;
}
void showHTNode(HTNode ht){
    cout<<ht.weight<<" "<<ht.parent<<" "<<ht.left<<" "<<ht.right<<"\n";
}
void showHuffmanTree(HuffmanTree HT,int n){
    for (int i = 1; i <= n*2-1; i++)
    {
        cout<<i<<" ";
        showHTNode(HT[i]);
    }
    
}
int* CreatHuffmanCode(HuffmanTree HT,HuffmanCode &HC,int n){
    //因为不确定编码长度 所以先开辟一个数组 计算出长度后再为HC申请
    //返回index数组 写有每行哈夫曼编码含有的编码个数
    int *index = new int[n];
    HC = new char*[n+1];        
    char *cd = new char[n];
    cd[n-1] = '\0';
    for(int i=1;i<=n;i++){//为每个节点求哈夫曼编码
        HTNode cur = HT[i];   //获得本次节点
        int start = n-1;int c = i;//用start表示cd数组的下标 c表示每次循环过程的节点
        while (cur.parent!=0)//当cur不是根节点时
        {
            start--;//start-1
            if (HT[cur.parent].left==c) cd[start] = '0';
            else cd[start] = '1';
            c = cur.parent;
            cur = HT[cur.parent];
        }
        HC[i] = new char[n-start]; //从n到cd最后一个 即'\0'
        index[i-1] = n-start-1;    //共有n-start-1个 
        strcpy(HC[i],&cd[start]);
    }
    delete cd;
    return index;
}
void showHTCode(HuffmanCode &HC){
    for (int i = 1; i < sizeof(HC)/sizeof(HC[i]); i++)
    {
        for(int j=0;j<sizeof(HC[i])/sizeof(char);j++){
            cout<<HC[i][j]<<" ";
        }
        cout<<"\n";
    }
    
}