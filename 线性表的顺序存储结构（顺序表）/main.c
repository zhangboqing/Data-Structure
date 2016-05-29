//
//  main.c
//  线性表的顺序存储结构（顺序表）
//
//  Created by 张波清 on 5/21/16.
//  Copyright © 2016 zhangboqing. All rights reserved.
//

#include "c1.h"
typedef int  ElemType;
#include "c2-1.h"
#include "bo2-1.h"
#include "func2-1.h"
#include "func2-2.h"
Status sq(ElemType c1,ElemType c2)
{
    if (c1 == c2*c2)
        return TRUE;
    else
        return FALSE;
}

void db1(ElemType *c)
{
    *c *= 2;
}

int main()
{
    SqList L;
    ElemType e,e0;
    Status i;
    int j,k;
    InitList(&L);
    printf("初始化L后,L.length=%d,L.listsize=%d,L.elem=%p\n",L.length,L.listsize,L.elem);
    for (j =1; j<=5; j++)
        i = ListInsert(&L, 1, j);
    printf("在L的表头依次插入1～5后，*L.elem=\n");
    for (j = 1; j<=5; j++) {
        printf("%d",*(L.elem+j-1));
    }
    printf("\n调用ListTraverse()函数，依次输出表L中的元素");
    ListTraverse(L, print1);
    SqList L1,L2,L3;
    InitList(&L1);
    InitList(&L2);
    for (int i = 4; i>=0; i--) {
        ListInsert(&L1, 1, i);
    }
    for (int i = 9; i>=5; i--) {
        ListInsert(&L2, 1, i);
    }
    MergeList_Sq(L1, L2, &L3);
    for (int i = 0; i<10; i++) {
        printf("%d ",*(L3.elem+i));
    }
    return 0;
}
