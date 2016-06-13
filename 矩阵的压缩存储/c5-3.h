//
//  c5-3.h
//  数据结构
//
//  Created by 张波清 on 6/10/16.
//  Copyright © 2016 zhangboqing. All rights reserved.
//
//稀疏矩阵的三元组行逻辑链接的顺序表存储结构
#ifndef c5_3_h
#define c5_3_h

#define MAX_SIZE1 100  //非零元个数的最大值
#define MAX_RC 20     //最大行数

typedef struct     //同c5-2.h
{
    int i,j;      //行下标，列下标
    ElemType e;    //非零元素值
}Triple1;

typedef struct
{
    Triple1 data[MAX_SIZE1+1];   //非零元三元组表，data[0]未用
    int rpos[MAX_RC+1]; //各行第一个非零元素的位置表，比c5-2.h增加的项
    int mu,nu,tu;       //矩阵的行数，列数，非零元个数
}TLSMatrix;
#endif /* c5_3_h */
