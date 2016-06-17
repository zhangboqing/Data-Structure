//
//  c6-3.h
//  数据结构
//
//  Created by 张波清 on 6/17/16.
//  Copyright © 2016 zhangboqing. All rights reserved.
//
//赫夫曼树和赫夫曼编码的存储结构（最优二叉树）
#ifndef c6_3_h
#define c6_3_h

typedef struct
{
    unsigned int weight;  //结点的权值
    unsigned int parent,lchild,rchild;
}HTNode,*HuffmanTree;  //动态分配数组存储赫夫曼树

typedef char  *  *HuffmanCode;  //动态分配数组存储赫夫曼编码表


#endif /* c6_3_h */
