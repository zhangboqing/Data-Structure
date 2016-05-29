//
//  bo2-6.h
//  数据结构
//
//  Created by 张波清 on 5/23/16.
//  Copyright © 2016 zhangboqing. All rights reserved.
//
/*
    单链的循环链表结点的存储结构和单链表结点的存储结构一样
    所不同的是：最后一个结点的next域指向头结点，而不是空
    单循环链表往往设立尾指针而不是头指针
*/
#ifndef bo2_6_h
#define bo2_6_h
/**
 *  构造一个空的线性表L
 */
void InitList(LinkList *L)
{
    *L = (LinkList)malloc(sizeof(LNode));
    if(!(*L))
        exit(OVERFLOW);
    (*L)->next = *L;
}
/**
 *  将L重置为空表
 *
 */
void ClearList(LinkList *L)
{
    LinkList p,q;
    *L = (*L)->next;
    p = (*L)->next;
    while (p!=*L) {
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = *L;
}
/**
 *  销毁线性表L
 *
 */
void DestroyList(LinkList *L)
{
    ClearList(L);
    free(*L);
    L = NULL;
}

/**
 *  判断表L是否为空，若L为空，返回TRUE，否则返回FALSE
 *
 */
Status ListEmpty(LinkList L)
{
    if(L->next == L)
        return TRUE;
    else
        return FALSE;
}
/**
 *  返回L中数据元素的个数
 *
 */
int ListLength(LinkList L)
{
    int i = 0;
    LinkList p = L->next;
    while (p!=L) {
        i++;
        p = p->next;
    }
    return i;
}
/**
 *  当第i个元素存在时，其值赋给e并返回OK，否则返回ERROR
 *
 */
Status GetElem(LinkList L,int i,ElemType *e)
{
    int j = 1;
    LinkList p = L->next->next;
    if(i<=0 || i>ListLength(L))
        return ERROR;
    while (j<i) {
        j++;
        p = p->next;
    }
    *e = p->data;
    return OK;
}
/**
 *  返回L中第一个与e满足关系compare（）的数据元素的位序
 *
 */
int LocateElem(LinkList L,ElemType e,Status(*compare)(ElemType,ElemType))
{
    int i = 0;
    LinkList p = L->next->next;
    while (p!=L->next)
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
Status PriorElem(LinkList L,ElemType cur_e,ElemType *pre_e)
{
    LinkList q,p = L->next->next;
    q = p->next;
    while (q != L->next)
    {
        if (q->data == cur_e)
        {
            *pre_e = p->data;
            return OK;
        }
        p = q;
        q = q->next;
    }
    return ERROR;
}
/**
 *若cur_e时L的数据元素，且不是最后一个，则用next_e返回它的后继
 *
 */
Status NextElem(LinkList L,ElemType cur_e,ElemType *next_e)
{
    LinkList p = L->next->next;
    while (p != L)
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
Status ListInsert(LinkList *L,int i,ElemType e)
{
    LinkList p = (*L)->next,s;
    int j = 0;
    if(i<=0 || i>ListLength(*L)+1)
        return ERROR;
    while (j<i-1)  //寻找第i－1个结点
    {
        j++;
        p = p->next;
    }
    s = (LinkList)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    if (p == *L)
        *L = s;
    return OK;
}
/**
 *  删除第i个元素，并由e返回其值
 *
 */
Status ListDelete(LinkList *L,int i,ElemType *e)
{
    LinkList q,p = (*L)->next;
    int j = 0;
    if(i<=0 || i>ListLength(*L))
        return ERROR;
    while (j<i-1)
    {
        j++;
        p = p->next;
    }
    q = p->next;
    p->next = q->next;
    *e = q->data;
    if(*L == q)
        *L = p;
    free(q);
    return OK;
}
/**
 *  依次对L的每个数据元素调用函数visit（）
 *
 */
void ListTraverse(LinkList L,void(*visit)(ElemType))
{
    LinkList p = L->next->next;
    while (p != L->next)
    {
        visit(p->data);
        p = p->next;
    }
    printf("\n");
}


#endif /* bo2_6_h */
