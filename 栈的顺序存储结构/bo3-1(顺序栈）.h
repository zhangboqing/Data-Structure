//
//  bo3-1(顺序栈）.h
//  数据结构
//
//  Created by 张波清 on 5/24/16.
//  Copyright © 2016 zhangboqing. All rights reserved.
//
//基本操作9个
#ifndef bo3_1______h
#define bo3_1______h
/**
 *  构造一个空栈S
 *
 */
void InitStack(SqStack *S)
{
    (*S).base = (SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
    if(!(*S).base)
        exit(OVERFLOW);
    (*S).top = (*S).base;
    (*S).stacksize = STACK_INIT_SIZE;
}
/**
 *  销毁栈S
 *
 */
void DestroyStack(SqStack *S)
{
    free((*S).base);
    (*S).top = (*S).base = NULL;
    (*S).stacksize = 0;
}
/**
 *  把栈S置为空栈
 *
 */
void ClearStack(SqStack *S)
{
    (*S).top = (*S).base;
}
/**
 *  若栈S为空栈，则返回TRUE，否则返回FALSE
 *
 */
Status StackEmpty(SqStack S)
{
    if(S.top == S.base)
        return TRUE;
    else
        return FALSE;
}
/**
 *  返回栈S的元素个数即栈的长度
 *
 */
int StackLength(SqStack S)
{
    return (int)(S.top-S.base);
}
/**
 *  若栈S不空，则用e返回S的栈顶元素，并返回OK，否则返回ERROR
 *
 */
Status GetTop(SqStack S,SElemType *e)
{
    if (S.top>S.base) {
        *e = *(S.top-1);
        return OK;
    }
    else
        return ERROR;
}
/**
 *  插入元素e为栈S新的栈顶元素
 *
 */
void  Push(SqStack *S,SElemType e)
{
    if ((*S).top-(*S).base==(*S).stacksize)   //栈满条件
    {
        (*S).base = (SElemType*)realloc((*S).base,((*S).stacksize+STACK_INCREMENT)*sizeof(SElemType));
        if(!(*S).base)
            exit(OVERFLOW);
        (*S).top = (*S).base+(*S).stacksize;
        (*S).stacksize += STACK_INCREMENT;
    }
    *((*S).top)++ = e;
}
/**
 *  若栈S不空，则删除S的栈顶元素，用e返回其值，并返回OK
 *
 */
Status Pop(SqStack *S,SElemType *e)
{
    if((*S).top == (*S).base)
        return  ERROR;
    *e = * --(*S).top;
    return OK;
}
/**
 *  从栈底到栈顶依次对栈S中每个元素调用函数visit()
 *
 */
void StackTraverse(SqStack S,void(*visit)(SElemType))
{
    SElemType *p = S.base;
    while(p < S.top)
        visit(*p++);
    printf("\n");
}
#endif /* bo3_1______h */
