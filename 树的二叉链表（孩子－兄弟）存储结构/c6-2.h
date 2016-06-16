//
//  c6-2.h
//  数据结构
//
//  Created by 张波清 on 6/16/16.
//  Copyright © 2016 zhangboqing. All rights reserved.
//

#ifndef c6_2_h
#define c6_2_h

typedef struct CSNode   //结点类型
{
    TElemType data;   //结点的值
    struct CSNode *firstchild,*nextsibling;  //两个链域分别指向该结点的第一个孩子结点和下一个兄弟结点
}CSNode,*CSTree;

#endif /* c6_2_h */
