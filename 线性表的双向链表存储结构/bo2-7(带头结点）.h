//
//  bo2-7(带头结点）.h
//  数据结构
//
//  Created by 张波清 on 5/23/16.
//  Copyright © 2016 zhangboqing. All rights reserved.
//

#ifndef bo2_7_______h
#define bo2_7_______h
/**
 *  构造一个空的双向循环链表L
 */
void InitList(DuLinkList *L)
{
    *L = (DuLinkList)malloc(sizeof(DuLNode));
    if(L)
        (*L)->next = (*L)->prior = *L;
    else
        exit(OVERFLOW);
}
/**
 *  将L重置为空表
 *
 */
void ClearList(DuLinkList L)
{
    DuLinkList p = L->next;
    while (p != L) {
        p = p->next;
        free(p->prior);
    }
    L->next = L->prior = L;
}
/**
 *  销毁线性表L
 *
 */

void DestroyList(DuLinkList *L)
{
    ClearList(*L);
    free(*L);
    L = NULL;
}

/**
 *  判断表L是否为空，若L为空，返回TRUE，否则返回FALSE
 *
 */
Status ListEmpty(DuLinkList L)
{
    if(L->next == L && L->prior == L)
        return TRUE;
    else
        return FALSE;
}
/**
 *  返回L中数据元素的个数
 *
 */
int ListLength(DuLinkList L)
{
    int i = 0;
    DuLinkList p = L->next;
    while (p != L) {
        i++;
        p = p->next;
    }
    return i;
}
/**
 *  当第i个元素存在时，其值赋给e并返回OK，否则返回ERROR
 *
 */
Status GetElem(DuLinkList L,int i,ElemType *e)
{
    int j = 1;
    DuLinkList p = L->next;
    while (p!=L && j<i) {
        j++;
        p = p->next;
    }
    if(p==L || j>i)
        return ERROR;
    *e = p->data;
    return OK;
}
/**
 *  返回L中第一个与e满足关系compare（）的数据元素的位序
 *
 */
int LocateElem(DuLinkList L,ElemType e,Status(*compare)(ElemType,ElemType))
{
    int i = 0;
    DuLinkList p = L->next;
    while (p!=L)
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
Status PriorElem(DuLinkList L,ElemType cur_e,ElemType *pre_e)
{
    DuLinkList p = L->next->next;
    while (p!=L)
    {
        if (p->data == cur_e)
        {
            *pre_e = p->prior->data;
            return OK;
        }
        p = p->next;
    }
    return ERROR;
}
/**
 *若cur_e时L的数据元素，且不是最后一个，则用next_e返回它的后继
 *
 */
Status NextElem(DuLinkList L,ElemType cur_e,ElemType *next_e)
{
    DuLinkList p = L->next->next;
    while (p != L)
    {
        if (p->prior->data == cur_e)
        {
            *next_e= p->data;
            return OK;
        }
        p = p->next;
    }
    return ERROR;
}
/**
 *  在双向链表L中返回第i个元素的地址，i为0返回头结点的地址，若第i个元素不存在，返回NULL
 *
 */
DuLinkList GetElemP(DuLinkList L,int i)
{
    int j;
    DuLinkList p = L;
    if(i<0 || i>ListLength(L))
        return NULL;
    for(j = 1;j<=i;j++)
        p = p->next;
    return p;
}
/**
 *  在链表L中第i个位置之前插入元素e
 *
 */
Status ListInsert(DuLinkList L,int i,ElemType e)
{
    DuLinkList p,s;
   if(i<1 || i>ListLength(L)+1)
       return ERROR;
    p = GetElemP(L, i-1);
    if(!p)
        return ERROR;
    s = (DuLinkList)malloc(sizeof(DuLNode));
    if(!s)
        return ERROR;
    s->data = e;
    s->prior = p;
    s->next = p->next;
    p->next->prior = s;
    p->next = s;
    return OK;
}
/**
 *  删除第i个元素，并由e返回其值
 *
 */
Status ListDelete(DuLinkList L,int i,ElemType *e)
{
    DuLinkList p;
    if(i<1)
        return ERROR;
    p = GetElemP(L, i);
    if(!p)
        return ERROR;
    *e = p->data;
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p);
    return OK;
}
/**
 *  依次对L的每个数据元素调用函数visit（）
 *
 */
void ListTraverse(DuLinkList L,void(*visit)(ElemType))
{
    DuLinkList p = L->next;
    while (p!=L)
    {
        visit(p->data);
        p = p->next;
    }
    printf("\n");
}
/**
 *  逆序对L的每个数据元素调用函数visit（）
 *
 */
void ListTraverseBack(DuLinkList L,void(*visit)(ElemType))
{
    DuLinkList p = L->prior;
    while (p!=L)
    {
        visit(p->data);
        p = p->prior;
    }
    printf("\n");
}

#endif /* bo2_7_______h */
