//
//  bo6-2.h
//  数据结构
//
//  Created by 张波清 on 6/13/16.
//  Copyright © 2016 zhangboqing. All rights reserved.
//
//18个基本操作
#ifndef bo6_2_h
#define bo6_2_h
/**
 *  若T为空儿叉树，则返回TRUE；否则返回FALSE
 *
 */
Status BiTreeEmpty(BiTree T)
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
int BiTreeDepth(BiTree T)
{
    int i,j;
    if(!T)
        return 0;  //空树深度为0
    i = BiTreeDepth(T->lchild); //i为左子树的深度
    j = BiTreeDepth(T->rchild); //j为右子树的深度
    return i>j?i+1:j+1;   //T的深度为其左右子树的深度中的大着＋1
}
/**
 *  返回T的根
 *
 */
TElemType Root(BiTree T)
{
    if(BiTreeEmpty(T))
        return Nil;  //返回“空”
    else
        return T->data;  //返回根结点的值
}
/**
 *  返回p所指结点的值
 *
 */
TElemType Value(BiTree p)
{
    return p->data;
}
/**
 *  给p所指结点赋值为value
 *
 */
void Assign(BiTree p,TElemType value)
{
    p->data = value;
}
/**
 *  返回二叉树T中指向元素值为s的结点的指针。新增
 */
typedef BiTree QElemType;    //定义队列元素为二叉树的指针类型
#include "c3-2.h"           //链队列
#include "bo3-2.h"          //链队列的基本操作
BiTree Point(BiTree T,TElemType s)
{
    LinkQueue q;
    QElemType a;
    if(T)        //非空树
    {
        InitQueue(&q);   //初始化队列
        EnQueue(&q, a);  //根指针入队
        while (!QueueEmpty(q))  //队不空
        {
            DeQueue(&q, &a);    //出队，队列元素赋给a
            if (a->data == s)   //a所指结点的值为s
            {
                DestroyQueue(&q); //销毁队列q
                return a;
            }
            if(a->lchild)    //有左孩子
                EnQueue(&q, a->lchild); //入队左孩子
            if(a->rchild)
                EnQueue(&q, a->rchild);
        }
        DestroyQueue(&q);   //销毁队列q
    }
    return NULL;  //二叉树T中没有元素值为s的结点
}
/**
 *  返回e的左孩子的值，若e无左孩子，则返回“空”
 *
 */
TElemType LeftChild(BiTree T,TElemType e)
{
    BiTree a;
    if(T)   //非空树
    {
        a = Point(T, e);  //a指向结点e的指针
        if(a&&a->lchild)   //T中存在结点e且e存在左孩子
            return a->lchild->data;  //返回值
    }
    return Nil;  //其它情况返回“空”
}
/**
 *  返回e的右孩子的值，若e无右孩子，则返回“空”
 *
 */
TElemType RightChild(BiTree T,TElemType e)
{
    BiTree a;
    if(T)   //非空树
    {
        a = Point(T, e);  //a指向结点e的指针
        if(a&&a->rchild)   //T中存在结点e且e存在右孩子
            return a->rchild->data;  //返回值
    }
    return Nil;  //其它情况返回“空”
}
/**
 *  根据LR为0或1，删除T中p所指结点的左或右子树
 *
 */
Status DeleteChild(BiTree p,int LR)
{
    if(p)
    {
        if(LR == 0)  //删除左子树
            ClearBitree(&p->lchild);
        else if(LR == 1)  //删除右子树
            ClearBitree(&p->rchild);
        return OK;
    }
    return ERROR;
}
/**
 *  后序递归遍历T，对每个结点调用函数Visit一次且仅一次
 *
 */
void PostOrderTraverse(BiTree T,void(*Visit)(TElemType))
{
    if(T) //T不空
    {
        PostOrderTraverse(T->lchild, Visit); //先后序遍历左子树
        PostOrderTraverse(T->rchild, Visit); //再后序遍历右子树
        Visit(T->data); //最后访问根结点
    }
}
/**
 *  层序递归遍历T（利用队列），对每个结点调用函数Visit一次且仅一次
 *
 */
void LevelOrderTraverse(BiTree T,void(*Visit)(TElemType))
{
    LinkQueue q;
    QElemType a;
    if(T)
    {
        InitQueue(&q);  //初始化队列q
        EnQueue(&q, T); //根指针入队
        while (!QueueEmpty(q)) //队列不空
        {
            DeQueue(&q, &a); //出队元素（指针），赋给a
            Visit(a->data);
            if(a->lchild!=NULL)
                EnQueue(&q, a->lchild);
            if(a->rchild!=NULL)
                EnQueue(&q, a->rchild);
        }
        printf("\n");
        DestroyQueue(&q); //销毁队列q
    }
}
/**
 *  按先序次序输入二叉树中结点的值，构造二叉链表表示的二叉树T
 *
 */
void CreateBiTree(BiTree *T)
{
    TElemType ch;
    scanf(form,&ch); //输入结点的值
    if(ch == Nil) //结点值为空
        *T = NULL;
    else    //结点的值不为空
    {
        *T = (BiTree)malloc(sizeof(BiTNode)); //生成根结点
        if(!(*T))
            exit(OVERFLOW);
        (*T)->data = ch;      //将值赋给T所指结点
        CreateBiTree(&(*T)->lchild); //递归构造左子树
        CreateBiTree(&(*T)->rchild);
    }
}
/**
 *  若e是T的非根结点，则返回它的双亲，否则返回“空”
 *
 */
TElemType Parent(BiTree T,TElemType e)
{
    LinkQueue q;
    QElemType a;
    if(T)
    {
        InitQueue(&q);
        EnQueue(&q, T);
        while (!QueueEmpty(q))
        {
            DeQueue(&q,&a);
            if((a->lchild&&a->lchild->data==e)||(a->rchild&&a->rchild->data==e)) //找到e（是其左或右孩子）
                return a->data;  //返回e的双亲的值
            else //未找到e，则入队其左右孩子指针
            {
                if(a->lchild)
                    EnQueue(&q, a->lchild);
                if(a->rchild)
                    EnQueue(&q, a->rchild);
            }
        }
    }
    return Nil;
}
/**
 *  返回e的左兄弟，若e是T的左孩子或无左兄弟，则返回“空”
 *
 */
TElemType LeftSibling(BiTree T,TElemType e)
{
    TElemType a;
    BiTree p;
    if(T)
    {
        a = Parent(T, e); //a为e的双亲
        if(a!=Nil)      //找到e的双亲
        {
            p = Point(T, a); //p为指向结点a的指针
            if (p->lchild&&p->rchild&&p->rchild->data==e) //p存在左右孩子且右孩子是e
            {
                return p->lchild->data; //返回p的左孩子（e的左兄弟）
            }
        }
    }
    return Nil; //其余情况返回“空”
}
/**
 *  返回e的右兄弟，若e是T的右孩子或无右兄弟，则返回“空”
 *
 */
TElemType RightSibling(BiTree T,TElemType e)
{
    TElemType a;
    BiTree p;
    if(T)
    {
        a = Parent(T, e); //a为e的双亲
        if(a!=Nil)      //找到e的双亲
        {
            p = Point(T, a); //p为指向结点a的指针
            if (p->lchild&&p->rchild&&p->lchild->data==e) //p存在左右孩子且左孩子是e
            {
                return p->rchild->data; //返回p的右孩子（e的右兄弟）
            }
        }
    }
    return Nil; //其余情况返回“空”
}
/**
 *  根据LR为0或1，插入c为T中p所指结点的左或右子树。p所指结点的原有左或右子树则成为c的右子树
 *
 */
Status InsertChild(BiTree p,int LR,BiTree c)
{
    if(p)
    {
        if(LR == 0) //把二叉树c插为p所指结点的左子树
        {
            c->rchild = p->lchild;
            p->lchild = c;
        }
        else
        {
            c->rchild = p->rchild;
            p->rchild = c;
        }
        return OK;
    }
    return ERROR;
}
/**
 *  中序遍历二叉树T的非递归算法（利用栈），对每个数据元素调用函数Visit
 */
typedef BiTree SElemType; //定义栈元素为二叉树的指针类型
#include "c3-1.h"       //顺序栈
#include "bo3-1(顺序栈）.h"     //顺序栈的基本操作
void InOrderTraverse1(BiTree T,void(*Visit)(TElemType))
{
    SqStack S;
    InitStack(&S);
    while (T||!StackEmpty(S)) //当二叉树T不空或者栈不空
    {
        if(T)   //二叉树T不空
        {//根指针进栈，遍历左子树
            Push(&S, T);  //入栈根指针
            T = T->lchild;  //T指向其左孩子
        }
        else    //根指针退栈，访问根结点，遍历右子树
        {
            Pop(&S, &T);
            Visit(T->data);
            T = T->rchild;
        }
    }
    printf("\n");
    DestroyStack(&S);  //销毁栈S
}
/**
 *  中序遍历二叉树T的非递归算法（利用栈），对每个数据元素调用函数Visit
 */
void InOrderTraverse2(BiTree T,void(*Visit)(TElemType))
{
    SqStack S;
    BiTree p;
    InitStack(&S);
    Push(&S, T);   //根指针进栈（无论空否）
    while (!StackEmpty(S)) //栈不空
    {
        while(GetTop(S, &p)&&p)  //栈顶元素不为空指针
            Push(&S, p->lchild);        //向左走到尽头，入栈左孩子指针
        Pop(&S, &p);                //空指针退栈，退掉最后入栈的空指针
        if(!StackEmpty(S))      //访问结点，向右一步
        {
            Pop(&S, &p);        //弹出栈顶元素（非空指针）
            Visit(p->data);      //访问刚弹出的结点（目前栈顶元素的左孩子）
            Push(&S, p->rchild); //入栈其右孩子指针
        }
    }
    printf("\n");
    DestroyStack(&S);  //销毁栈S
}
#endif /* bo6_2_h */
