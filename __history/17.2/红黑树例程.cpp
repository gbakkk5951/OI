#include <stdio.h>
#include <stdlib.h>

#define RED 0
#define BACK 1

typedef int Elemtype;

//����һ��������Ľ��
typedef struct Red_Back_Tree
{
    Elemtype e;
    int color;
    struct Red_Back_Tree * child[2];
}* RBT;

//    �����ڵ�任����
void conversion(RBT *T,int direction);

//    ɾ��һ���ڵ�����ú���
int DeleteRBT(RBT *T,Elemtype e);                                //    ɾ����(�ӿ�)����
int find_replace_point(RBT gogal,RBT *l);                        //    Ѱ�������
int keep_balance_for_delete(RBT *T,int direction);                //    ɾ����ƽ�����
int do_with_start_point(RBT gogal,RBT *T,int direction);                    //    �����һ����ʼ��

//    ����һ���ڵ�����ú���
int InsertRBT(RBT *T,Elemtype e);                                //    ����ӿں���
int _InsertRBT(RBT *T,Elemtype e);                                //    ����������
int keep_balance_for_insert(RBT *T,int firdirection,Elemtype e);//    �����ƽ�����
RBT create_one_node(Elemtype e);                                //    �½�һ���ڵ�



void conversion(RBT *T,int direction)
{
    RBT f=(*T),s=f->child[direction],ss=s->child[!direction];

    f->child[direction]=ss;
    s->child[!direction]=f;
    *T=s;
}

//������������������ɾ����������������������������������

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
//        conversion(&p,!direction);//�ֲܿ���һ��д����żȻ�з��֣����ﴫ�ĵ�ַ�Ǽٵ�!����T!!
//                                    ������ô��ôɵ��!!������Ǽ�ʱ���֣�������ʱ�������޿ֲ�
//                                    ����һ���޴�����ص�BUG!!!��������޴���鷳!!!
        conversion(T,!direction);
        return keep_balance_for_delete(&((*T)->child[direction]),direction);
    }
    else if(BACK==p->color && BACK==b->color && 
        (NULL==b->child[0] || BACK==b->child[0]->color) && 
        (NULL==b->child[1] || BACK==b->child[1]->color))    //����о���������һ��ΪNULLȴÿ��Ҫ
    {                                                        //�ж��Ƿ�ΪNULL����������
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
//    ��һ�ε���
//    ����ԭ������ɾ��0��δ��Ԥ�ϵĲ���Ӧ��������ܣ�ȴ���ݲ���
//    ����ĵط���RED==b->child[!direction] ! ����->color ����������ϱߴ��˼��Σ�����������������˹���
//    ��εı�����������������Ҳ�������������׷�������һһ���ղŷ���!!!
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
        conversion(&(p->child[!direction]),direction);//�����pд�Ĳ��㲻��!��pҲ(*T)���У�һ��!
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
//    �ڶ��ε���---��ʵûF5,F10,F11�����ݽ���²⣬�����￴�������ǵ�!
//    ����ԭ��ɾ��0���ˣ�ɾ��1�ִ���---2�����ˣ�1����
//    ����ĵط�����������ҵ�����㣬ȴû�С������������ڰ������ɾ��...
//                ��������ԣ�gogal���ɾ����ָ�������û��...�ҵ�ʱ���˰�!!�޸�����!
//    else    //�����Ϊ��ʼ��
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
        if(NULL!=(*T)->child[1])    //������ɾ���㲻����ʼ�㣬���������
        {
            if(find_replace_point((*T),&((*T)->child[1])))    return 1;
            return keep_balance_for_delete(T,1);
            //...
        }
        else    //������ɾ���������ʼ��
        {
            return do_with_start_point((*T),T,0);
        }
    }
}
//�������������������������������������������������


//����������������������������������������������������

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
    int secdirection=( (e>p->e) ? 1 : 0 );    //    �鴦�ڶ�������
    
    if(NULL!=u && RED==u->color)    /*****����ڵ�Ϊ��ɫ*****/    
    {
        p->color=BACK;
        u->color=BACK;
        (*T)->color=RED;
        return 1;    //����...
    }
    else                            /*****����ڵ�Ϊ��ɫ*****/    
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
    if(NULL==(*T))                    /*****�ٲ��뵽���ڵ�*****/        //����ֻ�ǰ����������
    {
        *T=create_one_node(e);
        (*T)->color=RED;
        info=1;
    }
    else if(e>((*T)->e))
    {
        info=_InsertRBT(&(*T)->child[1],e);
        if(info<1)    return info;
        else if(info==1)            /*****�ڸ��ڵ�Ϊ��******/
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

int InsertRBT(RBT *T,Elemtype e)    //����ڵ㺯������ֵ�� -1->�ĵ��Ѵ���  0->�ɹ�����
{
    int info=0;        //    info:  -1->�Ѵ��� 0->���� 1->���ݵ����ڵ� 2->���ݵ���ڵ�
    
//2011��11��30��9:13:47 ������������������������if���Բ�Ҫ���ɣ�Ҳ���ǰ���Ҳ�ŵ�_InsertRBT
//�ڴ�����InsertRBT���и��жϼ���!���ĳ��±ߵ�д��!
//    if(NULL==(*T))                    /*****�ٲ��뵽���ڵ�*****/
//    {
//        *T=create_one_node(e);
//        (*T)->color=BACK;
//    }
//    else            
//    {
//        info=_InsertRBT(T,e);    //    ��������˼��������info�ķ���ֵֻ����Ϊ��-1  0  1
//        if(info>0)    (*T)->color=BACK,info=0;    //    �鿴���ڵ��Ƿ�Ϊ��
//    }

    info=_InsertRBT(T,e);
    if(info==1)    (*T)->color=BACK,info=0;    
    //    Ϊ�˷�ֹ������Ϊ�죬����ʵ�Ǵ�������������ĺ���֢
//    �ֱ��ǣ�������������������ڵ���  ���������㼴Ϊ���ڵ㣬Ϊ��
//    ����û��ֱ�ӰѸ�����ڣ���Ҫ��Ϊ����_InsertRBT����һ�µ�д������ʵ����!
    return info;
}
//�������������������������������������������������


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

    printf("\n�������\n");
    for(i=0;i<nodenum;i++)
    {
        InsertRBT(&T,i);
        printf("����%d\n",i);
        print(T);
        printf("\n");
    }

//    print(T);
    printf("\nɾ������:\n");

    for(i=0;i<nodenum;i++)
    {
        DeleteRBT(&T,i);
        printf("ɾ��%d\n",i);
        print(T);
        printf("\n");
    }

    return 0;
}
