//
//  c2-1.h
//  数据结构
//
//  Created by 张波清 on 5/21/16.
//  Copyright © 2016 zhangboqing. All rights reserved.
//
//线性表的动态分配顺序存储结构
#ifndef c2_1_h
#define c2_1_h
#define LIST_INIT_SIZE 10  //线性表存储空间的初始分配量
#define LIST_INCREMENT 2   //线性表存储空间的分配增量

typedef  struct
{
    ElemType *elem;    //存储空间基址
    int length;        //当前长度
    int listsize;       //当前分配的存储容量
}SqList;

#endif /* c2_1_h */
