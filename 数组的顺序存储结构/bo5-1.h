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
/**
 *  销毁数组A
 *
 */
void DestroyArray(Array *A)
{
    if((*A).base)
        free((*A).base);
    if((*A).bounds)
        free((*A).bounds);
    if((*A).constants)
        free((*A).constants);
    (*A).base = (*A).bounds = (*A).constants = NULL;
    (*A).dim = 0;
}
/**
 *  若ap指示的各下标值合法，则求出该元素在A中的相对地址off
 *
 */
Status Locate(Array A,va_list ap,int *off)
{
    int i,ind;
    off = 0;
    for (i = 0; i<A.dim; i++)
    {
        ind  = va_arg(ap, int);     //逐一读取各维的下标值
        if(ind<0 || ind>=A.bounds[i])
            return OVERFLOW;
        off += A.constants[i]*ind; //相对地址 ＝ 各维的下标值＊本维的偏移量之和
    }
    return OK;
}
/**
 *  "..." 依次为各维的下标值，若各下标合法，则e被赋值为A的相应的元素值
 *
 */
Status Value(ElemType *e,Array A,...)
{
    va_list ap;
    int off;
    va_start(ap, A); //变成参数从"..."从形参A之后开始
    if(Locate(A, ap, &off))
       return ERROR;
       *e = *(A.base+off);
       return OK;
}
/**
 *  “...”依次为各维的下标值，若各下标合法，则将e的值赋给A的指定的元素
 *
 */
Status Assign(Array A,ElemType e,...)
{
    va_list ap;
    int off;
    va_start(ap, e);
    if(Locate(A, ap, &off) == OVERFLOW)
        return ERROR;
    *(A.base+off) = e;
    return OK;
    
}
#endif /* bo5_1_h */
