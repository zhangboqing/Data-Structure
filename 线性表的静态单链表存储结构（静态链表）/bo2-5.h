//
//  bo2-5.h
//  数据结构
//
//  Created by 张波清 on 5/22/16.
//  Copyright © 2016 zhangboqing. All rights reserved.
//
//静态链表的13个基本操作
#ifndef bo2_5_h
#define bo2_5_h

#define DestroyList ClearList //DestroyList和ClearList的操作是一样的
/**
 *  若备用链表非空，则返回分配的结点下标，否则返回0
 *
 */
int Malloc(SLinkList space)
{
    int i = space[0].cur;
    if(i)
        space[0].cur = space[i].cur;
    return i;
}
/**
 *  将下标为K的空闲结点回收到备用链表中（成为备用链表的第一个结点）
 *
 */
void Free(SLinkList space,int k)
{
    space[k].cur = space[0].cur;
    space[0].cur = k;
}
/**
 *  构造一个空的链表L，表头为L的最后一个单元L［MAX_SIZE－1］，其余单元链成一个备用链表，表头为L的第一个单元L[0],"0"表示空指针
 *
 */
void InitList(SLinkList L)
{
    int i;
    L[MAX_SIZE].cur = 0;
    for(i = 0;i<MAX_SIZE-2;i++)
        L[i].cur = i+1;
    L[MAX_SIZE-2].cur = 0;
}
/**
 *  将L重置为空表
 *
 */
void ClearList(SLinkList L)
{
    int j = 0,i = L[0].cur;
    while (i) {
        j = i;
        i = L[i].cur;
    }
    L[j].cur = L[MAX_SIZE-1].cur;
    L[MAX_SIZE-1].cur = 0;
}
/**
 *  判断L是否为空表，是返回TRUE，否则返回FALSE
 *
 */
Status ListEmpty(SLinkList L)
{
    if(L[MAX_SIZE-1].cur == 0)
        return TRUE;
    else
        return FALSE;
}
/**
 *  返回L中数据元素个数
 *
 */
int ListLength(SLinkList L)
{
    int j = 0,i = L[MAX_SIZE-1].cur;
    while (i) {
        i = L[i].cur;
        j++;
    }
    return j;
}
/**
 *  用e返回L中第i个元素的值
 *
 */
Status GetElem(SLinkList L,int i,ElemType *e)
{
    int m,k = MAX_SIZE-1;
    if(i<1 || i>ListLength(L))
        return ERROR;
    for(m = 1;m<=i;m++)
        k = L[k].cur;
    *e = L[k].data;
    return OK;
}
/**
 *  在静态链表L中查找第一个值为e的元素，若找到返回位序，否则返回0
 *
 */
int LocateElem(SLinkList L,ElemType e)
{
    int i = L[MAX_SIZE-1].cur;
    while(i && L[i].data!=e)
        i = L[i].cur;
    return i;
}
/**
 *  若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱
 *
 */
Status PriorElem(SLinkList L,ElemType cur_e,ElemType *pre_e)
{
    int j,i = L[MAX_SIZE-1].cur;
    do
    {
        j = i;
        i = L[i].cur;
    }while(i && cur_e!=L[i].data);
    if (i) {
       *pre_e = L[j].data;
        return OK;
    }
    return ERROR;
}
/**
 *  若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继
 *
 */
Status NextElem(SLinkList L,ElemType cur_e,ElemType *next_e)
{
    int j,i = LocateElem(L, cur_e);
    if (i)
    {
        j = L[i].cur;
        if (j)
        {
            *next_e = L[j].data;
            return OK;
        }
    }
    return ERROR;
}
/**
 *  在L中第i个元素之前插入新的数据元素e
 *
 */
Status ListInsert(SLinkList L,int i,ElemType e)
{
    int m,j,k = MAX_SIZE-1;
    if(i<1 || i>ListLength(L)+1)
        return ERROR;
    j = Malloc(L);
    if (j) {
        L[j].data = e;
        for(m = 1;m<i;m++)
            k = L[k].cur;
        L[j].cur = L[k].cur;
        L[k].cur = j;
        return OK;
    }
    return ERROR;
}
/**
 *  删除L中第i个数据元素e，并返回其值
 *
 */
Status ListDelete(SLinkList L,int i,ElemType *e)
{
    int j,k = MAX_SIZE-1;
    if(i<1 || i>ListLength(L))
        return ERROR;
    for(j = 1;j<i;j++)
        k = L[k].cur;
    j = L[k].cur;
    L[k].cur = L[j].cur;
    *e = L[j].data;
    Free(L, j);
    return OK;
}
/**
 *  依次对L的每个元素调用函数visit（）
 *
 */
void ListTraverse(SLinkList L,void(*visit)(ElemType))
{
    int i = L[MAX_SIZE-1].cur;
    while (i) {
        visit(L[i].data);
        i = L[i].cur;
    }
    printf("\n");
}
#endif /* bo2_5_h */
