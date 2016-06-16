//
//  bo6-3.h
//  数据结构
//
//  Created by 张波清 on 6/16/16.
//  Copyright © 2016 zhangboqing. All rights reserved.
//
//16个基本操作
#ifndef bo6_3_h
#define bo6_3_h

#define ClearTree DestroyTree
/**
 *  构造空树T
 *
 */
void Inittree(CSTree *T)
{
    *T = NULL;
}
/**
 *  销毁树T
 *
 */
void DestroyTree(CSTree *T)
{
    if(*T)  //非空树
    {
        DestroyTree(&(*T)->firstchild);  //递归销毁T的长子为根结点的子树
        DestroyTree(&(*T)->nextsibling); //递归销毁T的下一个兄弟为根结点的子树
        free(*T);
        *T = NULL;
    }
}
/**
 *  构造树
 */
typedef CSTree QElemType; //定义队列元素类型为孩子－兄弟二叉链表的指针类型
#include "c3-2.h"           //定义LinkQueue类型（链队列）
#include "bo3-2.h"          //LinkQueue类型的基本操作
void CreateTree(CSTree *T)
{
    char c[20];             //临时存放孩子结点（设步超过20个）的值
    CSTree p,p1;
    LinkQueue q;
    int i,m;
    InitQueue(&q);
    printf("请输入根结点（字符型，＃为空：");
    scanf("%c",&c[0]);                      //输入根结点的值
    if(c[0]!= Nil)          //非空树
    {
        *T = (CSTree)malloc(sizeof(CSNode));   //建立根结点
        (*T)->data = c[0];
        (*T)->nextsibling = NULL;     //根结点没有下一个兄弟
        EnQueue(&q, *T);        //入队根结点的指针
        while(!QueueEmpty(q))
        {
            DeQueue(&q, &p);        //出队一个结点的指针
            printf("请按长幼顺序输入结点%c的所有孩子：",p->data);
            gets(c);        //将结点的所有孩子作为字符串输入
            m = strlen(c);
            if(m>0)         //有孩子
            {
                p1 = p->firstchild = (CSTree)malloc(sizeof(CSNode));  //建立长子结点
                p1->data = c[0];
                EnQueue(&q, p1);
                for (i = 1; i<m; i++)       //对于除长子以外的其它孩子
                {
                    p1->nextsibling = (CSTree)malloc(sizeof(CSNode));
                    p1 = p1->nextsibling;
                    p1->data = c[i];
                    EnQueue(&q, p1);
                }
                p1->nextsibling= NULL;  //最后一个结点没有下一个兄弟
    
            }
            else
                p->firstchild = NULL; //长子指针为空
        }
    }
    else   //无孩子
        T = NULL;
    
}
/**
 *  判断T是否为空树
 */
Status TreeEmpty(CSTree T)
{
    if(T)
        return FALSE;
    else
        return TRUE;
}
/**
 *  返回T的深度
 *
 */
int TreeDepth(CSTree T)
{
    CSTree p;
    int depth,max = 0;
    if(!T)    //树空
        return 0;
    for(p = T->firstchild;p;p = p->nextsibling)  //对于树T根结点的所有孩子结点（由p指向）
    {//求子树深度的最大值
        depth = TreeDepth(p);  //递归求孩子结点的深度depth
        if(depth>max)   //最大孩子结点的深度存max
            max = depth;
    }
    return max+1;           //树的深度 ＝ 子树深度最大值＋1
}
/**
 *  返回p所指结点的值
 *
 */
TElemType Value(CSTree p)
{
    return p->data;
}
/**
 *  返回T的根
 *
 */
TElemType Root(CSTree T)
{
    if(T)
        return Value(T);
    else
        return Nil;
}
/**
 *  返回二叉链表（孩子－兄弟）树T中指向元素值为s的结点的指针。新增
 *
 */
CSTree Point(CSTree T,TElemType s)
{
    LinkQueue q;
    QElemType a;
    if(T)
    {
        InitQueue(&q);
        EnQueue(&q, T);    //根结点入队
        while(!QueueEmpty(q))
        {
            DeQueue(&q, &a);
            if(a->data == s)   //找到元素值为s的结点
                return a;
            if(a->firstchild)   //有长子
                EnQueue(&q, a->firstchild);
            if(a->nextsibling)      //有下一个兄弟
                EnQueue(&q, a->nextsibling);
        }
    }
    return ERROR;
}
/**
 *  树T存在，cur_e是树T中结点的值，将cur_e为value
 */
Status Assign(CSTree *T,TElemType cur_e,TElemType value)
{
    CSTree p;
    if(*T)
    {
        p = Point(*T, cur_e);
        if(p)
        {
            p->data = value;
            return OK;
        }
    }
    return ERROR;
}
/**
 *  若cur_e是T的非根结点，则返回它的双亲；否则函数值为“空”
 *
 */
TElemType Parent(CSTree T,TElemType cur_e)
{
    CSTree p,t;
    LinkQueue q;
    InitQueue(&q);
    if(T)
    {
        if(Value(T) == cur_e)   //根结点值为cur_e
            return Nil;
        EnQueue(&q, T);
        while(!QueueEmpty(q))
        {
            DeQueue(&q, &p);
            if(p->firstchild)    //p有长子
            {
                if(p->firstchild->data == cur_e)  //长子为cur_e
                    return Value(p);  //返回双亲值
                t = p;          //双亲指针赋给t
                p = p->firstchild;
                EnQueue(&q, p);
                while (p->nextsibling)   //有下一个兄弟
                {
                    p = p->nextsibling;
                    if(Value(p) == cur_e)
                        return Value(t);
                    EnQueue(&q,p);
                }
            }
        }
    }
    return Nil;
}
/**
 *  若cur_e是T的非叶子结点，则返回它的最左孩子；否则返回“空”
 *
 */
TElemType LeftChild(CSTree T,TElemType cur_e)
{
    CSTree f;
    f = Point(T, cur_e);  //f指向结点cur_e
    if(f && f->firstchild)   //找到结点cur_e且结点cur_e有长子
        return f->firstchild->data;
    else
        return Nil;
}
/**
 *  若cur_e有右兄弟，则返回它的右兄弟；否则返回“空”
 *
 */
TElemType RightSibling(CSTree T,TElemType cur_e)
{
    CSTree f;
    f = Point(T, cur_e);  //f指向结点cur_e
    if(f && f->nextsibling)   //找到结点cur_e且结点cur_e有右兄弟
        return f->nextsibling->data;
    else
        return Nil;
}
/**
 *  插入c为T中p结点的第i棵子树
 *
 */
Status InsertChild(CSTree *T,CSTree p,int i,CSTree c)
{
    int j;
    CSTree q;
    if(*T)
    {
        if(i == 1)   //插入c为p的长子
        {
            c->nextsibling = p->firstchild;
            p->firstchild = c;
        }
        else    //c不是p的长子
        {
            q = p->firstchild;
            j = 2;
            while(q && j<i)   //找c的插入点，并由q指向
            {
                q = q->nextsibling;
                j++;
            }
            if(j == i)  //找到插入位置
            {
                c->nextsibling = q->nextsibling;
                q->nextsibling = c;
            }
            else
                return ERROR;
        }
        return OK;
    }
    else
        return ERROR;
}
/**
 *  删除T中p所指结点的第i棵子树
 *
 */
Status DeleteChild(CSTree *T,CSTree p,int i)
{
    CSTree b,q;
    int j;
    if(*T)
    {
        if(i == 1)   //删除长子
        {//把长子结点子树从p中分离出来
            b = p->firstchild;
            p->firstchild = b->nextsibling;
            b->nextsibling = NULL;
            DestroyTree(&b);
        }
        else   //删除非长子
        {
            q = b->firstchild;
            j = 2;
            while (q&&j<i)  //找第i棵子树
            {
                q = q->nextsibling;
                j++;
            }
            if(j==i)   //找到第i棵子树
            {
                b = q->nextsibling;
                q->nextsibling = b->nextsibling;
                b->nextsibling = NULL;
                DestroyTree(&b);
            }
            else
                return ERROR;
        }
        return OK;
    }
    else
        return ERROR;
}
/**
 *  后根遍历孩子－兄弟二叉链表结构的树T
 */
void PostOrderTraverse(CSTree T,void(*Visit)(TElemType))
{
    CSTree p;
    if(T)
    {
        if(T->firstchild)   //有长子
        {
            PostOrderTraverse(T->firstchild, Visit);  //后根遍历长子子树
            p = T->firstchild->nextsibling;
            while(p)
            {
                PostOrderTraverse(p, Visit);  //后根遍历下一个兄弟子树
                p = p->nextsibling;
            }
        }
        Visit(Value(T));  //最后访问根结点
    }
}
/**
 *  层序遍历孩子－兄弟二叉链表结构的树T
 *
 */
void LeverOrderTraverse(CSTree T,void(*Visit)(TElemType))
{
    CSTree p;
    LinkQueue q;
    InitQueue(&q);
    if(T)
    {
        Visit(Value(T));  //先访问根结点
        EnQueue(&q, T);
        while(!QueueEmpty(q))
        {
            DeQueue(&q, &p);
            if(p->firstchild)  //有长子
            {
                p = p->firstchild;
                Visit(Value(p));
                EnQueue(&q, p);
                while(p->nextsibling)  //有下一个兄弟
                {
                    p = p->nextsibling;
                    Visit(Value(p));
                    EnQueue(&q,p);
                }
            }
        }
    }
    printf("\n");
}
#endif /* bo6_3_h */
