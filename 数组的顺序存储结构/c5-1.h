//
//  c5-1.h
//  数据结构
//
//  Created by 张波清 on 6/1/16.
//  Copyright © 2016 zhangboqing. All rights reserved.
//

#ifndef c5_1_h
#define c5_1_h

#define MAX_ARRAY_DIM 8   //假设数组维数的最大值为8

typedef struct
{
    ElemType *base;         //数据元素基址，由InitArray分配
    int dim;                //数组维数
    int *bounds;            //数组维界基址，由InitArray分配
    int *constants;         //数组影像函数常量基址，由InitArray分配
}Array;

#endif /* c5_1_h */
