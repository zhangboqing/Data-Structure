//
//  c3-1.h
//  数据结构
//
//  Created by 张波清 on 5/24/16.
//  Copyright © 2016 zhangboqing. All rights reserved.
//
//栈数据结构定义
#ifndef c3_1_h
#define c3_1_h

#define STACK_INIT_SIZE 10  //存储空间初始分配量
#define STACK_INCREMENT 2   //存储空间分配增量

typedef struct
{
    SElemType *base;        //栈底指针  在栈构造之前和销毁之后，base的值为NULL
    SElemType *top;         //栈顶指针
    int stacksize;          //当前已分配的存储空间，以元素个数为单位
}SqStack;

#endif /* c3_1_h */
