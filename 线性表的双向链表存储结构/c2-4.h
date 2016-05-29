//
//  c2-4.h
//  数据结构
//
//  Created by 张波清 on 5/23/16.
//  Copyright © 2016 zhangboqing. All rights reserved.
//
//线性表的双向链表存储结构
#ifndef c2_4_h
#define c2_4_h

typedef struct DuLNode
{
    ElemType data;
    struct DuLNode *prior,*next;
}DuLNode,*DuLinkList;

#endif /* c2_4_h */
