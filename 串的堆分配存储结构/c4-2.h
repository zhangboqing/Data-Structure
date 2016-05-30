//
//  c4-2.h
//  数据结构
//
//  Created by 张波清 on 5/30/16.
//  Copyright © 2016 zhangboqing. All rights reserved.
//
//串的堆分配存储结构
#ifndef c4_2_h
#define c4_2_h

typedef struct
{
    char * ch;    //若失非空串，则按串长分配存储区，否则ch为NULL
    int length;   //串长度
}HString;

#endif /* c4_2_h */
