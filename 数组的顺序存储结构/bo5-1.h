//
//  bo5-1.h
//  数据结构
//
//  Created by 张波清 on 6/1/16.
//  Copyright © 2016 zhangboqing. All rights reserved.
//
//基本操作5个
#ifndef bo5_1_h
#define bo5_1_h
/**
 *  若维数dim和各维长度合法，则构造相应的数组A，并返回OK
 *
 */
Status InitArray(Array *A,int dim,...)
{
    int elemtotal = 1,i;      //elemtotal是数据元素总数，初值为1
    va_list ap;               //定义变长参数表类型，在stdarg.h中
    if(dim<1 || dim>MAX_ARRAY_DIM)  //数组维数超出范围
        return ERROR;
    (*A).dim = dim;
    (*A).bounds = (int*)malloc(dim*sizeof(int)); //动态分配数组维界基址
    if(!(*A).bounds)
        exit(OVERFLOW);
    va_start(ap, dim);
    for (i = 0; i<dim; i++)
    {
        (*A).bounds[i] = va_arg(ap, int);   //逐一将变长参数赋给(*A).bounds[i]
        if((*A).bounds[i]<0)
            return UNDERFLOW;
        elemtotal *= (*A).bounds[i];        //数组元素总数＝各维长度之积
    }
    va_end(ap);             //结束提取变成参数
    (*A).base = (ElemType*)malloc(elemtotal*sizeof(ElemType));  //动态分配数组存储空间
    if(!(*A).base)
        exit(OVERFLOW);
    (*A).constants = (int *)malloc(dim*sizeof(int));        //动态分配数组偏移量基址
    if(!(*A).constants)
        exit(OVERFLOW);
    (*A).constants[dim-1] = 1;      //最后一维的偏移量为1
    for(i = dim-2;i>=0;--i)
        (*A).constants[i] = (*A).bounds[i+1]*(*A).constants[i+1]; //每一维的偏移量
    return OK;
}


#endif /* bo5_1_h */
