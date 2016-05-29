//
//  bo2-1.h
//  数据结构
//
//  Created by 张波清 on 5/21/16.
//  Copyright © 2016 zhangboqing. All rights reserved.
//
//顺序存储的线性表的12个基本操作
#ifndef bo2_1_h
#define bo2_1_h
/**
 *  构造一个空的线性表L
 *
 */
void InitList(SqList *L)
{
    (*L).elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if (!(*L).elem) {
        exit(OVERFLOW);
    }
    (*L).length = 0;
    (*L).listsize = LIST_INIT_SIZE;
}
/**
 *  销魂顺序线性表L
 *
 */
void DestroyList(SqList *L)
{
    free((*L).elem);
    (*L).elem = NULL;
    (*L).length = 0;
    (*L).listsize = 0;
}
/**
 *  将L重置为空表
 *
 */
void ClearList(SqList *L)
{
    (*L).length = 0;
}
/**
 *  判断顺序表L是否为空
 *
 */
Status ListEmpty(SqList L)
{
    if (L.length == 0)
        return TRUE;
    else
        return FALSE;
}
/**
 *  返回L中数据元素的个数
 *
 */
int ListLength(SqList L)
{
    return L.length;
}
/**
 *  用e返回L中的第i个数据元素的值
 *
 */
Status GetElem(SqList L,int i,ElemType *e)
{
    if (i<1||i>L.length) {
        return ERROR;
    }
    *e = *(L.elem+i-1);
    return OK;
}
/**
 *  返回L中第一个与e满足关系compare()的数据元素的位序
 *
 */
int LocateElem(SqList L,ElemType e,Status(*compare)(ElemType,ElemType))
{
    int i = 1;
    ElemType *p = L.elem;
    while (i<L.length&&!compare(*p++,e))
        i++;
    if (i<=L.length)
        return i;
    else
        return 0;
}
/**
 *  若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱
 *
 */
Status PriorElem(SqList L,ElemType cur_e,ElemType *pre_e)
{
    int i = 2;
    ElemType *p = L.elem+1;
    while (i<L.length&&*p!=cur_e) {
        p++;
        i++;
    }
    if (i>L.length)
        return ERROR;
    else
    {
        *pre_e = * --p;
        return OK;
    }
}
/**
 *  若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继
 *
 */
Status NextElem(SqList L,ElemType cur_e,ElemType *next_e)
{
    int i = 1;
    ElemType *p = L.elem;
    while (i<L.length && *p!=cur_e) {
        p++;
        i++;
    }
    if (i == L.length)
        return ERROR;
    else
    {
        *next_e = * ++p;
        return OK;
    }
}
/**
 *  在L中的第i个位置之前插入新的数据元素e，L的长度加1
 *
 */
Status ListInsert(SqList *L,int i,ElemType e)
{
    ElemType *newbase,*q,*p;
    if (i<1 && i>(*L).length+1)
        return ERROR;
    if ((*L).length == (*L).listsize) {
        newbase = (ElemType *)realloc((*L).elem,((*L).listsize+LIST_INIT_SIZE)*sizeof(ElemType));
        if (!newbase)
            exit(OVERFLOW);
        (*L).elem = newbase;
        (*L).listsize += LIST_INIT_SIZE;
    }
    q = (*L).elem+i-1;
    for (p = (*L).elem+(*L).length-1; p>=q; --p)
        *(p+1) = *p;
    *q = e;
    (*L).length++;
    return OK;
}
/**
 *  删除L的第i个数据元素，并用e返回其值，L的长度减1
 *
 */
Status ListDelete(SqList *L,int i,ElemType *e)
{
    ElemType *p,*q;
    if (i<1 && i>(*L).length+1)
        return ERROR;
    p = (*L).elem+i-1;
    *e = *p;
    q = (*L).elem+(*L).length-1;
    for (p++; p<=q; p++)
        *(p-1) = *p;
    (*L).length--;
    return OK;
}
/**
 *  依次对L的每个数据元素调用函数visit(),来改变元素的值
 *
 */
void ListTraverse(SqList L,void(*visit)(ElemType *))
{
    ElemType *p = L.elem;
    int i;
    for (i = 1; i<=L.length; i++)
        visit(p++);
    printf("\n");
}
#endif /* bo2_1_h */
