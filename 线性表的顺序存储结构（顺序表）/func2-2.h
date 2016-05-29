//
//  func2-2.h
//  数据结构
//
//  Created by 张波清 on 5/21/16.
//  Copyright © 2016 zhangboqing. All rights reserved.
//

#ifndef func2_2_h
#define func2_2_h
/**
 *  已知顺序表La和Lb的元素递增排列，将La和Lb归并得到新的Lc也递增排列
 *
 */
void MergeList_Sq(SqList La,SqList Lb,SqList *Lc)
{
    ElemType *pa,*pa_last,*pb,*pb_last,*pc;
    pa = La.elem;
    pb = Lb.elem;
    (*Lc).listsize = (*Lc).length = La.length+Lb.length;
    pc = (*Lc).elem = (ElemType *)malloc((*Lc).listsize*sizeof(ElemType));
    if (!((*Lc).elem))
        exit(OVERFLOW);
    pa_last = La.elem+La.length-1;
    pb_last = Lb.elem+Lb.length-1;
    while (pa<=pa_last && pb<pb_last)
    {
        if(*pa<=*pb)
            *pc++ = *pa++;
        else
            *pc++ = *pb++;
    }
    while(pa<=pa_last)
        *pc++ = *pa++;
    while(pb<=pb_last)
        *pc++ = *pb++;
}

#endif /* func2_2_h */
