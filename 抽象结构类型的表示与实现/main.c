//
//  main.c
//  抽象结构类型的表示与实现
//
//  Created by 张波清 on 5/20/16.
//  Copyright © 2016 zhangboqing. All rights reserved.
//

#include "c1.h"
typedef int ElemType;
#include "c1-1.h"
#include "bo1-1.h"
#include "func1-1.h"

int main()
{
    

    Triplet T;
    ElemType m;
    Status i;
    i = InitTriplet(&T, 5, 7, 9);
    printf("调用初始化函数后，i = %d。T的3个值为",i);
    PrintT(T);
    i = Get(T, 2, &m);
    if (i == OK) {
        printf("T的第2个值为");
        PrintE(m);
    }
    i = Put(T, 2, 6);
    if (i == OK) {
        printf("将T的第2个值改为6后，T的3个值为");
        PrintT(T);
    }
    i = IsAscending(T);
    printf("调用测试升序的函数后，i = %d\n",i);
    i = IsDescending(T);
    printf("调用测试降序的函数后，i = %d\n",i);
    if ((i = Max(T,&m) == OK)) {
        printf("T中最大值为");
        PrintE(m);
    }
    if ((i = Min(T,&m) == OK)) {
        printf("T中最小值为");
        PrintE(m);
    }
    DestroyTriplet(&T);
    printf("销毁T后，T = %p\n",T);
    return 0;
}
