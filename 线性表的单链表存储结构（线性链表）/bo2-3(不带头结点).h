//
//  bo2-3(不带头结点）.h
//  数据结构
//
//  Created by 张波清 on 5/22/16.
//  Copyright © 2016 zhangboqing. All rights reserved.
//
//不带头结点的基本操作
#ifndef bo2_3________h
#define bo2_3________h
/**
 *  构造一个空的线性表L
 */
void InitList2(LinkList *L)
{
    L = NULL;
}
/**
 *  将L重置为空表
 *
 */
void ClearList2(LinkList L)
{
    LinkList p;
    while(L)
    {
        p = L;
        L = L->next;
        free(p);
    }
}
/**
 *  判断表L是否为空，若L为空，返回TRUE，否则返回FALSE
 *
 */
Status ListEmpty2(LinkList L)
{
    if(L)
        return FALSE;
    else
        return TRUE;
}
/**
 *  返回L中数据元素的个数
 *
 */
int ListLength2(LinkList L)
{
    int i = 0;
    LinkList p = L;
    while (p) {
        i++;
        p = p->next;
    }
    return i;
}
/**
 *  当第i个元素存在时，其值赋给e并返回OK，否则返回ERROR
 *
 */
Status GetElem2(LinkList L,int i,ElemType *e)
{
    int j = 1;
    LinkList p = L;
    if(i<1)
        return ERROR;
    while (p && j<i)
    {
        j++;
        p = p->next;
    }
    if (j==i && p) {
        *e = p->data;
        return OK;
    }
    return ERROR;
}
/**
 *  返回L中第一个与e满足关系compare（）的数据元素的位序
 *
 */
int LocateElem2(LinkList L,ElemType e,Status(*compare)(ElemType,ElemType))
{
    int i = 0;
    LinkList p = L;
    while (p)
    {
        i++;
        if(compare(p->data,e))
            return i;
        p = p->next;
    }
    return 0;
}
/**
 *  若cur_e时L的数据元素，且不是第一个，则用pre_e返回它的前驱
 *
 */
Status PriorElem2(LinkList L,ElemType cur_e,ElemType *pre_e)
{
    LinkList q,p = L;
    while (p->next)
    {
        q = p->next;
        if (q->data == cur_e)
        {
            *pre_e = p->data;
            return OK;
        }
        p = q;
    }
    return ERROR;
}
/**
 *若cur_e时L的数据元素，且不是最后一个，则用next_e返回它的后继
 *
 */
Status NextElem2(LinkList L,ElemType cur_e,ElemType *next_e)
{
    LinkList p = L;
    while (p->next)
    {
        if (p->data == cur_e)
        {
            *next_e= p->next->data;
            return OK;
        }
        p = p->next;
    }
    return ERROR;
}
/**
 *  在链表L中第i个位置之前插入元素e
 *
 */
Status ListInsert2(LinkList L,int i,ElemType e)
{
    int j = 1;
    LinkList s,p = L;
    if(i<1)
        return ERROR;
    s = (LinkList)malloc(sizeof(LNode));
    s->data = e;
    if (i == 1)
    {
        s->next = L;
        L = s;
    }
    else
    {
        while (p && j<i-1)
        {
            j++;
            p = p->next;
        }
        if (!p)
            return ERROR;
        s->next = p->next;
        p->next = s;
    }
    return OK;
}
/**
 *  删除第i个元素，并由e返回其值
 *
 */
Status ListDelete2(LinkList L,int i,ElemType *e)
{
    int j = 1;
    LinkList q,p = L;
    if(!L)
        return ERROR;
    else if(i == 1)
    {
        L = p->next;
        *e = p->data;
        free(p);
    }
    else
    {
        while (p->next && j<i-1)
        {
            j++;
            p = p->next;
        }
        if(!p->next || j>i-1)
            return ERROR;
        q = p->next;
        p->next = q->next;
        *e = q->data;
        free(q);
    }
    return OK;

}
/**
 *  依次对L的每个数据元素调用函数visit（）
 *
 */
void ListTraverse2(LinkList L,void(*visit)(ElemType))
{
    LinkList p = L;
    while (p)
    {
        visit(p->data);
        p = p->next;
    }
    printf("\n");
}

#endif /* bo2_3________h */
