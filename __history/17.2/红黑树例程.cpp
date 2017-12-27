#include <stdio.h>
#include <stdlib.h>

#define RED 0
#define BACK 1

typedef int Elemtype;

//定义一个红黑树的结点
typedef struct Red_Back_Tree
{
    Elemtype e;
    int color;
    struct Red_Back_Tree * child[2];
}* RBT;

//    两个节点变换函数
void conversion(RBT *T,int direction);

//    删除一个节点的所用函数
int DeleteRBT(RBT *T,Elemtype e);                                //    删除主(接口)函数
int find_replace_point(RBT gogal,RBT *l);                        //    寻找替代点
int keep_balance_for_delete(RBT *T,int direction);                //    删除的平衡操作
int do_with_start_point(RBT gogal,RBT *T,int direction);                    //    处理第一个起始点

//    插入一个节点的所用函数
int InsertRBT(RBT *T,Elemtype e);                                //    插入接口函数
int _InsertRBT(RBT *T,Elemtype e);                                //    插入主函数
int keep_balance_for_insert(RBT *T,int firdirection,Elemtype e);//    插入的平衡操作
RBT create_one_node(Elemtype e);                                //    新建一个节点



void conversion(RBT *T,int direction)
{
    RBT f=(*T),s=f->child[direction],ss=s->child[!direction];

    f->child[direction]=ss;
    s->child[!direction]=f;
    *T=s;
}

//★★★★★★★★★★★★★★★★★删除操作★★★★★★★★★★★★★★★★★★★★★★★★★★★

int do_with_start_point(RBT gogal,RBT *T,int direction)
{
    gogal->e=(*T)->e;
    if(BACK==((*T)->color))
    {
        if(NULL!=(*T)->child[direction])
        {
            (*T)->e=(*T)->child[direction]->e;
            free((*T)->child[direction]);
            (*T)->child[direction]=NULL;
            return 1;
        }
        else
        {
            free((*T));
            *T=NULL;
            return 0;
        }
    }
    else
    {
        free((*T));
        (*T)=NULL;
        return 1;
    }
}

int keep_balance_for_delete(RBT *T,int direction)
{
    RBT p=(*T),b=p->child[!direction];
    
    if(RED==b->color)
    {
        p->color=RED;
        b->color=BACK;
//        conversion(&p,!direction);//很恐怖的一个写法，偶然中发现：这里传的地址是假的!不是T!!
//                                    考我怎么这么傻逼!!如果不是及时发现，到调试时将是无限恐怖
//                                    将是一个巨大的隐藏的BUG!!!将会带来巨大的麻烦!!!
        conversion(T,!direction);
        return keep_balance_for_delete(&((*T)->child[direction]),direction);
    }
    else if(BACK==p->color && BACK==b->color && 
        (NULL==b->child[0] || BACK==b->child[0]->color) && 
        (NULL==b->child[1] || BACK==b->child[1]->color))    //这里感觉不美，就一次为NULL却每次要
    {                                                        //判断是否为NULL，不美……
        b->color=RED;
        return    0; 
    }
    else if(RED==p->color && 
        (NULL==b->child[0] || BACK==b->child[0]->color) &&
        (NULL==b->child[1] || BACK==b->child[1]->color))
    {
        p->color=BACK;
        b->color=RED;
        return 1;
    }
//    第一次调试
//    调试原因：由于删除0点未按预料的操作应该是情况④，却按⑤操作
//    错误的地方：RED==b->child[!direction] ! 丢了->color 这个错误我上边错了几次，不过编译器报错改了过来
//    这次的编译器不报错，看代码也看不错来，最后追究到这里，一一对照才发现!!!
//    else if(BACK==b->color && (NULL!=b->child[!direction] && RED==b->child[!direction]))
    else if(BACK==b->color && (NULL!=b->child[!direction] && RED==b->child[!direction]->color))
    {
        b->color=p->color;
        p->color=BACK;
        b->child[!direction]->color=BACK;
        conversion(T,!direction);
        return 1;
    }
    else
    {
        b->child[direction]->color=p->color;
        p->color=BACK;
        conversion(&(p->child[!direction]),direction);//这里的p写的才算不错!即p也(*T)都行，一样!
        conversion(T,!direction);
        return 1;
    }

}

int find_replace_point(RBT gogal,RBT *l)
{
    if(NULL!=(*l)->child[0])
    {
        if(find_replace_point(gogal,&(*l)->child[0]))    return 1;
        return keep_balance_for_delete(l,0);
        //...
    }
//    第二次调试---其实没F5,F10,F11，根据结果猜测，到这里看看还真是的!
//    调试原因：删除0好了，删除1又错了---2不见了，1还在
//    错误的地方：就在这里，找到替代点，却没有“替代”，这等于把替代点删了...
//                这里很明显，gogal这个删除点指针根本就没用...我当时忘了吧!!修改如下!
//    else    //替代点为起始点
//    {
//        return do_with_start_point(l,1);
//    }
    else
    {
        return do_with_start_point(gogal,l,1);
    }
}

int DeleteRBT(RBT *T,Elemtype e)
{
    if(!(*T))    return -1;
    else if(e>(*T)->e)
    {
        if(DeleteRBT(&((*T)->child[1]),e))    return 1;
        return keep_balance_for_delete(T,1);
        //...
    }
    else if(e<(*T)->e)
    {
        if(DeleteRBT(&((*T)->child[0]),e))    return 1;
        return keep_balance_for_delete(T,0);
        //...
    }
    else
    {
        if(NULL!=(*T)->child[1])    //真正的删除点不是起始点，需找替代点
        {
            if(find_replace_point((*T),&((*T)->child[1])))    return 1;
            return keep_balance_for_delete(T,1);
            //...
        }
        else    //真正的删除点就是起始点
        {
            return do_with_start_point((*T),T,0);
        }
    }
}
//★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★


//★★★★★★★★★★★★★★★★★★★插入操作★★★★★★★★★★★★★★★★★★★★★★★★★

RBT create_one_node(Elemtype e)
{
    RBT p=(RBT)malloc(sizeof(struct Red_Back_Tree));
    p->e=e;    p->color=RED;
    p->child[0]=p->child[1]=NULL;
    return p;
}

int keep_balance_for_insert(RBT *T,int firdirection,Elemtype e)
{
    RBT p=(*T)->child[firdirection],u=(*T)->child[!firdirection];
    int secdirection=( (e>p->e) ? 1 : 0 );    //    查处第二个方向
    
    if(NULL!=u && RED==u->color)    /*****③叔节点为红色*****/    
    {
        p->color=BACK;
        u->color=BACK;
        (*T)->color=RED;
        return 1;    //继续...
    }
    else                            /*****④叔节点为黑色*****/    
    {
        if(firdirection!=secdirection)    conversion(&((*T)->child[firdirection]),secdirection);
        (*T)->color=RED;    (*T)->child[firdirection]->color=BACK;
        conversion(T,firdirection);
        return 0;
    }
}

int _InsertRBT(RBT *T,Elemtype e)
{
    int info=0;
    if(NULL==(*T))                    /*****①插入到根节点*****/        //这里只是包含这种情况
    {
        *T=create_one_node(e);
        (*T)->color=RED;
        info=1;
    }
    else if(e>((*T)->e))
    {
        info=_InsertRBT(&(*T)->child[1],e);
        if(info<1)    return info;
        else if(info==1)            /*****②父节点为黑******/
        {
            if(BACK==((*T)->color))    info--;
            else    info++;
        }
        else
        {
            info=keep_balance_for_insert(T,1,e);
        }
        
    }
    else if(e<((*T)->e))
    {
        info=_InsertRBT(&((*T)->child[0]),e);
        if(info<1)    return info;
        else if(info==1)    
        {
            if(BACK==((*T)->color))    info--;
            else    info++;
        }
        else
        {
            info=keep_balance_for_insert(T,0,e);
        }
        
    }
    else    return info=-1;
    
    return info;
}

int InsertRBT(RBT *T,Elemtype e)    //插入节点函数返回值： -1->改点已存在  0->成功插入
{
    int info=0;        //    info:  -1->已存在 0->结束 1->回溯到父节点 2->回溯到祖节点
    
//2011年11月30日9:13:47 昨天晚上最后又想来这里这个if可以不要即可，也就是把它也放到_InsertRBT
//内处理，在InsertRBT中有个判断即可!即改成下边的写法!
//    if(NULL==(*T))                    /*****①插入到根节点*****/
//    {
//        *T=create_one_node(e);
//        (*T)->color=BACK;
//    }
//    else            
//    {
//        info=_InsertRBT(T,e);    //    经过再三思考，这里info的返回值只可能为：-1  0  1
//        if(info>0)    (*T)->color=BACK,info=0;    //    查看根节点是否为红
//    }

    info=_InsertRBT(T,e);
    if(info==1)    (*T)->color=BACK,info=0;    
    //    为了防止根结点变为红，它其实是处理了两种情况的后遗症
//    分别是：③情况回溯上来，根节点变红  ①情况插入点即为根节点，为红
//    这里没有直接把根结点变黑，主要是为了与_InsertRBT保持一致的写法，其实都行!
    return info;
}
//★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★


//******************JUST FOR TEST********************//
RBT queue[1000];
void print(RBT cur)
{
    int front=0,rear=0;
    int count=1,temp=0;

    if(NULL==cur)    
    {
        printf("NULL\n");
        return ;
    }

    queue[rear]=cur;
    while(front<=rear)
    {
        cur=queue[front++];    count--;
        if(NULL!=cur->child[0])    queue[++rear]=cur->child[0],temp++;
        if(NULL!=cur->child[1])    queue[++rear]=cur->child[1],temp++;

        printf("%d color->",cur->e);
        if(BACK==cur->color)    printf("BACK |");
        else    printf("RED  |");
        
        if(0==count)
        {
            count=temp;
            temp=0;
            printf("\n");
        }
    }
}
//*****************************************************//

//*****************DEAR MAIN***************************//
int main()
{
    RBT T=NULL;
    int i,nodenum=10;
    
    print(T);
    printf("\n");

    printf("\n插入操作\n");
    for(i=0;i<nodenum;i++)
    {
        InsertRBT(&T,i);
        printf("插入%d\n",i);
        print(T);
        printf("\n");
    }

//    print(T);
    printf("\n删除操作:\n");

    for(i=0;i<nodenum;i++)
    {
        DeleteRBT(&T,i);
        printf("删除%d\n",i);
        print(T);
        printf("\n");
    }

    return 0;
}
