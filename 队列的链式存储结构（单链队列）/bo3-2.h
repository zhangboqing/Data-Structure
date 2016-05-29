//
//  bo3-2.h
//  数据结构
//
//  Created by 张波清 on 5/25/16.
//  Copyright © 2016 zhangboqing. All rights reserved.
//
//基本操作9个
#ifndef bo3_2_h
#define bo3_2_h
/**
 *  构造一个空队列Q
 *
 */
void InitQueue(LinkQueue *Q)
{
    (*Q).front = (*Q).rear = (QueuePtr)malloc(sizeof(QNode)); //生成头结点
    if(!(*Q).front)
        exit(OVERFLOW);
    (*Q).front->next = NULL;
}
/**
 *  销毁队列Q
 *
 */
void DestroyQueue(LinkQueue *Q)
{
    while ((*Q).front)
    {
        (*Q).rear = (*Q).front->next;
        free((*Q).front);
        (*Q).front = (*Q).rear;
    }
}
/**
 *  将队列Q清为空队列
 *
 */
void ClearQueue(LinkQueue *Q)
{
    DestroyQueue(Q);
    InitQueue(Q);
}
/**
 *  若队列Q为空队列，则返回TRUE，否则返回FALSE
 *
 */
Status QueueEmpty(LinkQueue Q)
{
    if(Q.front->next == NULL)
        return TRUE;
    else
        return FALSE;
}
/**
 *  返回队列Q的元素个数即队列的长度
 *
 */
int QueueLength(LinkQueue Q)
{
    int i = 0;
    QueuePtr p = Q.front;  //指向头结点
    while (Q.rear != p)
    {
        i++;
        p = p->next;
    }
    return i;
}
/**
 *  若队列Q不空，则用e返回Q的队头元素，并返回OK，否则返回ERROR
 *
 */
Status GetHead(LinkQueue Q,QElemType *e)
{
    QueuePtr p;
    if(Q.front == Q.rear)
        return ERROR;
    p = Q.front->next;
    *e = p->data;
    return OK;
}
/**
 *  插入元素e为队列Q的新的队尾元素
 *
 */
void  EnQueue(LinkQueue *Q,QElemType e)
{
    QueuePtr p;
    p = (QueuePtr)malloc(sizeof(QNode));
    if(!p)
        exit(OVERFLOW);
    p->data = e;
    p->next = NULL;
    (*Q).rear->next = p;
    (*Q).rear = p;
}
/**
 *  若队列Q不空，则删除Q的队头元素，用e返回其值，并返回OK
 *
 */
Status DeQueue(LinkQueue *Q,QElemType *e)
{
    QueuePtr p;
    if((*Q).front == (*Q).rear)
        return ERROR;
    p = (*Q).front->next;
    *e = p->data;
    (*Q).front->next = p->next;
    if((*Q).rear == p)
        (*Q).rear = (*Q).front;
    free(p);
    return OK;
}
/**
 *  从队头到队尾依次对队列Q中每个元素调用函数visit()
 *
 */
void  QueueTraverse(LinkQueue Q,void(*visit)(QElemType))
{
    QueuePtr p = Q.front->next;
    while (p)
    {
        visit(p->data);
        p = p->next;
    }
    printf("\n");
}


#endif /* bo3_2_h */
