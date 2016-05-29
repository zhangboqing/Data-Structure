//
//  func2-1.h
//  数据结构
//
//  Created by 张波清 on 5/21/16.
//  Copyright © 2016 zhangboqing. All rights reserved.
//
//常用函数
#ifndef func2_1_h
#define func2_1_h
Status equal(ElemType c1,ElemType c2)
{
    if (c1 == c2)
        return TRUE;
    else
        return FALSE;
}

int comp(ElemType a,ElemType b)
{
    if (a == b)
        return 0;
    else
        return (a-b)/abs(a-b);
    
}

void print(ElemType c)
{
    printf("%d",c);
}

void print1(ElemType *c)
{
    printf("%d",*c);
}

void print2(ElemType c)
{
    printf("%c",c);
}
#endif /* func2_1_h */
