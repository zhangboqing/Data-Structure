//
//  c3-2.h
//  数据结构
//
//  Created by 张波清 on 5/25/16.
//  Copyright © 2016 zhangboqing. All rights reserved.
//
//先进先出，队列的存储结构,只允许队尾插入元素，队头删除元素
#ifndef c3_2_h
#define c3_2_h

typedef struct QNode
{
    QElemType data;
    struct QNode *next;
}QNode,*QueuePtr;

typedef  struct
{
    QueuePtr front;   //队头指针
    QueuePtr rear;    //队尾指针
}LinkQueue;
#endif /* c3_2_h */
