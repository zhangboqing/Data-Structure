//
//  c3-3.h
//  数据结构
//
//  Created by 张波清 on 5/27/16.
//  Copyright © 2016 zhangboqing. All rights reserved.
//
//队列的顺序存储结构（循环队列）
#ifndef c3_3_h
#define c3_3_h

#define MAX_QSIZE 5  //最大队列长度＋1（能存放4个元素）

typedef struct
{
    QElemType *base;  //初始化的动态分配存储空间
    int front;        //头指针，若队列不空，指向队列头元素
    int rear;         //尾指针，若队列不空，指向队列尾元素的下一个位置
}SqQueue;

#endif /* c3_3_h */
