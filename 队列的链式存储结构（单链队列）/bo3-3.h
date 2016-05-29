//
//  bo3-3.h
//  数据结构
//
//  Created by 张波清 on 5/26/16.
//  Copyright © 2016 zhangboqing. All rights reserved.
//
//用单链表的基本操作实现链队列
#ifndef bo3_3_h
#define bo3_3_h

typedef QElemType ElemType;
#define LinkList QueuePtr
#define LNode QNode
#include "bo2-2(带头结点的).h" 
/**
 *  构造一个空队列Q
 *
 */
void InitQueue2(LinkQueue *Q)
{
    InitList(&(*Q).front);
    (*Q).rear = (*Q).front;
}
/**
 *  销毁队列Q
 *
 */
void DestroyQueue2(LinkQueue *Q)
{
    DestroyList(&(*Q).front);
    (*Q).rear = (*Q).front;
}
/**
 *  将队列Q清为空队列
 *
 */
void ClearQueue2(LinkQueue *Q)
{
    ClearList((*Q).front);
    (*Q).rear = (*Q).front;
}
/**
 *  若队列Q为空队列，则返回TRUE，否则返回FALSE
 *
 */
Status QueueEmpty2(LinkQueue Q)
{
    return ListEmpty(Q.front);
}
/**
 *  返回队列Q的元素个数即队列的长度
 *
 */
int QueueLength2(LinkQueue Q)
{
    return ListLength(Q.front);
}
/**
 *  若队列Q不空，则用e返回Q的队头元素，并返回OK，否则返回ERROR
 *
 */
Status GetHead2(LinkQueue Q,QElemType *e)
{
    return GetElem(Q.front, 1, e);
}
/**
 *  插入元素e为队列Q的新的队尾元素
 *
 */
void  EnQueue2(LinkQueue *Q,QElemType e)
{
    ListInsert((*Q).front, ListLength((*Q).front)+1, e);
}
/**
 *  若队列Q不空，则删除Q的队头元素，用e返回其值，并返回OK
 *
 */
Status DeQueue2(LinkQueue *Q,QElemType *e)
{
    if((*Q).front->next == (*Q).rear)
        (*Q).rear = (*Q).front;
    return ListDelete((*Q).front, 1, e);
}
/**
 *  从队头到队尾依次对队列Q中每个元素调用函数visit()
 *
 */
void  QueueTraverse2(LinkQueue Q,void(*visit)(QElemType))
{
    ListTraverse(Q.front, visit);
}

#endif /* bo3_3_h */
