//
//  bo5-2.h
//  数据结构
//
//  Created by 张波清 on 6/8/16.
//  Copyright © 2016 zhangboqing. All rights reserved.
//
//三元组稀疏矩阵的基本操作
#ifndef bo5_2_h
#define bo5_2_h
/**
 *  创建稀疏矩阵M
 *
 */
Status CreateSMatrix(TSMatrix *M)
{
    int i;
    Triple T;
    Status k;
    printf("请输入矩阵的行数，列数，非零元素个数：");
    scanf("%d,%d,%d",&(*M).mu,&(*M).nu,&(*M).tu);
    if((*M).tu>MAX_SIZE)     //非零元个数太多
        return ERROR;
    (*M).data[0].i = 0;     //为以下比较顺序作准备
    for (i = 1; i<=(*M).tu; i++)   //依次输入M.tu个非零元素
    {
        do
        {
            printf("请按行序顺序输入第%d个非零元素所在的行（1～%d），列（1～%d），元素值：",i,(*M).mu,(*M).nu);
            scanf("%d,%d,%d",&T.i,&T.i,&T.e);
            k = 0;
            if(T.i<1||T.i>(*M).mu||T.j<1||T.j>(*M).nu)   //行或列超出范围
                k = 1;
            if(T.i<(*M).data[i-1].i||(T.i==(*M).data[i-1].i&&T.j<=(*M).data[i-1].j))
                k = 1;   //行或列的顺序有错
        }while(k);    //输入值的范围不正确则重新输入
        (*M).data[i] = T;  //将输入正确的值赋给三元组结构体M的相应单元
    }
    return OK;
}

#endif /* bo5_2_h */
