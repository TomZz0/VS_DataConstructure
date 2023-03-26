#include"BinaryThrTree.h"
BiThrNode* pre ;
BiThrTree getBiThrTree(){
    BiThrTree T;
    createBiThrTree_Front(T);
    return T;
}
void createBiThrTree_Front(BiThrTree &T){
    //递归并按照前序顺序创建树
    char ch;
    cin>>ch;
    if (ch=='#') T=NULL;
    else 
    {
        T = new BiThrNode;
        T->ch = ch;
        createBiThrTree_Front(T->left);
        createBiThrTree_Front(T->right);   
    }
}
void InThreading(BiThrTree p){
    //线索化是一个回溯的过程 一直找到最左然后回溯 实际上p是pre的双亲
    //pre是最左节点的前驱 如果不设节点就是null pre要设置成全局变量 否则递归后其值不有效
    //如果设置节点且最右节点的后继也指向pre 则链表联通
    //到最左开始左右子树的线索化 左右子树都完成线索化后 回溯 即pre指向p p为现在节点的双亲节点
    //如果已经到了树的右子树 则pre为p的双亲 p一步步向下
    if (p)
    {      
       InThreading(p->left);//线索化左子树 
       if (!p->left) //左子树为空
       {
        p->LTag = 1;    
        p->left = pre;
       }else p->LTag = 0;
    
       if (!pre->right) //每一个线索化完左孩子的节点在回溯到其双亲时会在次线索化右节点
       {
        pre->RTag=1;
        pre->right=p;     //这里会给节点赋值right,如果没有右孩子 就赋值后继节点
       }else pre->RTag = 0;
       pre = p;

       //右子树线索化在上面都进行完毕后 由于语句pre=p 这是一步一步向右推下来的 p最右 pre是p的双亲
       //最后pre为p
       InThreading(p->right);
    }
    
}
void InOrderThreading(BiThrTree &Thrt,BiThrTree T){
    Thrt = new BiThrNode;  //建立头节点
    Thrt->LTag=0;           //若树非空 头节点的左孩子就是树根
    Thrt->RTag = 1;         //头结点的右孩子为树的最右节点 
    Thrt->right=Thrt;       //将其置为本身 以后做修改
    if (!T)Thrt->left = Thrt;//若树为空则其左指针也指向自身
    else{
        Thrt->left = T;     //头节点左子树指向树根
        pre = Thrt ;        //pre指向头节点
        InThreading(T);//树的线索化
        //右上面的InThreading方法可知 线索化完毕后pre指向最右节点
        pre->right = Thrt; //最右节点的右子树为空 后继为Thrt
        pre->RTag = 1;      //类型为1
        Thrt->right = pre;  //头节点的右子树为pre
    }
    
}
void InOrderTraverse_Thr(BiThrTree T){
    //遍历线索化树 无需递归
    //T是头节点
    BiThrNode* p = T->left;
    while (p!=T)
    {
        //中序遍历找到最左输出
        while (p->LTag==0)
        {
            p = p->left;
        }
        cout<<p->ch;
        //若右节点是后继 走即可
        while (p->RTag==1&&p->right!=T)
        {
            p = p->right;
            cout<<p->ch;
        }
        //此时p有右孩子 转向p的右子树继续遍历 不是输出右节点而是进行右子树的中序遍历
        p = p->right;
        
    }
    
}