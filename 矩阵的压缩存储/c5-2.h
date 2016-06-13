//
//  c5-2.h
//  数据结构
//
//  Created by 张波清 on 6/8/16.
//  Copyright © 2016 zhangboqing. All rights reserved.
//
//稀疏矩阵的三元组顺序表存储结构
#ifndef c5_2_h
#define c5_2_h

#define MAX_SIZE 12500  //假设非零元个数的最大值为12500

typedef struct
{
    int i,j;     //该非零元的行下标和列下标
    ElemType e;
    
}Triple;

typedef struct
{
    Triple data[MAX_SIZE+1]; // 非零元三元组表，data［0］未用
    int mu,nu,tu;           //矩阵的行数、列数和非零元个数
}TSMatrix;

#endif /* c5_2_h */
