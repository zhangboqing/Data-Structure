//
//  bo6-1.h
//  数据结构
//
//  Created by 张波清 on 6/13/16.
//  Copyright © 2016 zhangboqing. All rights reserved.
//
//4个基本操作
#ifndef bo6_1_h
#define bo6_1_h

#define ClearBitree DestroyBiTree //清空二叉树和销毁二叉树的操作一样
/**
 *  构造空二叉树T
 *
 */
void InitBiTree(BiTree *T)
{
    *T = NULL;
}
/**
 *  销毁二叉树T
 *
 */
void DestroyBiTree(BiTree *T)
{
    if(*T)
    {
        DestroyBiTree(&(*T)->lchild);  //递归销毁左子树
        DestroyBiTree(&(*T)->rchild);   //递归销毁右子树
        free(*T);   //释放根结点
        *T = NULL;  //空指针赋wei 0
    }
}
/**
 *  先序递归遍历T，对每个结点调用函数Visit一次且仅一次
 *
 */
void PreOrderTraverse(BiTree T,void(*Visit)(TElemType))
{
    if(T)  //T不空
    {
        Visit(T->data);  //先访问根结点
        PreOrderTraverse(T->lchild, Visit);    //再先序遍历左子树
        PreOrderTraverse(T->rchild, Visit);     //最后先序遍历右子树
    }
}
/**
 *  中序递归遍历T，对每个结点调用函数Visit一次且仅一次
 *
 */
void InOrderTraverse(BiTree T,void(*Visit)(TElemType))
{
    if (T)
    {
        InOrderTraverse(T->lchild, Visit);  //先中序遍历左子树
        Visit(T->data);         //再访问根结点
        InOrderTraverse(T->rchild, Visit); //最后中序遍历右子树
    }
}

#endif /* bo6_1_h */
