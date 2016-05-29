//
//  bo3-4.h
//  数据结构
//
//  Created by 张波清 on 5/27/16.
//  Copyright © 2016 zhangboqing. All rights reserved.
//
//循环队列基本操作9个
#ifndef bo3_4_h
#define bo3_4_h

/**
 *  构造一个空队列Q
 *
 */
void InitQueue(SqQueue *Q)
{
    (*Q).base = (QElemType*)malloc(MAX_QSIZE*sizeof(QElemType));
    if(!(*Q).base)
        exit(OVERFLOW);
    (*Q).front = (*Q).rear = 0;
}
/**
 *  销毁队列Q,Q不再存在
 *
 */
void DestroyQueue(SqQueue *Q)
{
   if((*Q).base)
       free((*Q).base);
    (*Q).base = NULL;
    (*Q).front = (*Q).rear = 0;
}
/**
 *  将队列Q清为空队列
 *
 */
void ClearQueue(SqQueue *Q)
{
    (*Q).front = (*Q).rear;
}
/**
 *  若队列Q为空队列，则返回TRUE，否则返回FALSE
 *
 */
Status QueueEmpty(SqQueue Q)
{
    if(Q.front == Q.rear)
        return TRUE;
    else
        return FALSE;
}
/**
 *  返回队列Q的元素个数即队列的长度
 *
 */
int QueueLength(SqQueue Q)
{
    return (Q.rear-Q.front+MAX_QSIZE)%MAX_QSIZE;
}
/**
 *  若队列Q不空，则用e返回Q的队头元素，并返回OK，否则返回ERROR
 *
 */
Status GetHead(SqQueue Q,QElemType *e)
{
    if(Q.front == Q.rear)
        return ERROR;
    *e = Q.base[Q.front];
    return OK;
}
/**
 *  插入元素e为队列Q的新的队尾元素
 *
 */
Status  EnQueue(SqQueue *Q,QElemType e)
{
    if(((*Q).front+1)%MAX_QSIZE == (*Q).front) //队列满
        return ERROR;
    (*Q).base[(*Q).rear] = e;
    (*Q).rear = ((*Q).rear+1)%MAX_QSIZE;  //队尾指针＋1后对MAX_QSIZE取余
    return OK;
}
/**
 *  若队列Q不空，则删除Q的队头元素，用e返回其值，并返回OK
 *
 */
Status DeQueue(SqQueue *Q,QElemType *e)
{
    if((*Q).front == (*Q).rear)
        return ERROR;
    *e = (*Q).base[(*Q).front];
    (*Q).front = ((*Q).front+1)%MAX_QSIZE;  //移动队头指针
    return OK;
}
/**
 *  从队头到队尾依次对队列Q中每个元素调用函数visit()
 *
 */
void  QueueTraverse(SqQueue Q,void(*visit)(QElemType))
{
    int i = Q.front;
    while (i != Q.rear)
    {
        visit(Q.base[i]);
        i = (i+1)%MAX_QSIZE; //i指向下一个元素
    }
    printf("\n");
}



#endif /* bo3_4_h */
