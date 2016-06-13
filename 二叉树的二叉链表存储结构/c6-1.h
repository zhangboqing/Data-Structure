//
//  c6-1.h
//  数据结构
//
//  Created by 张波清 on 6/13/16.
//  Copyright © 2016 zhangboqing. All rights reserved.
//

#ifndef c6_1_h
#define c6_1_h

typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

#endif /* c6_1_h */
