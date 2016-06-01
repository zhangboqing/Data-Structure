//
//  algo41(KMP算法）.h
//  数据结构
//
//  Created by 张波清 on 6/1/16.
//  Copyright © 2016 zhangboqing. All rights reserved.
//

#ifndef algo41_KMP____h
#define algo41_KMP____h

#include "c1.h"
#include "c4-1.h"
#include "bo4-1.h"
/**
 *  求模式串T的next函数值并存入数组next
 *
 */
void get_next(SString T,int next[])
{
    int i = 1,j = 0;
    next[1] = 0;      //T的第1个字符与主串“失配”时，主串的下一字符与T的第1个字符比较
    while(i < T[0])   //当T[0]>1时，next[2]=1
        if(j == 0||T[i] == T[j])   //初态或两字符相等
        {
            i++;
            j++;
            next[i] = j;   //主串和T在第i个字符不匹配时，前j-1个字符时匹配的，只需与第j个字符比较
        }
    else
        j = next[j];   //j减小到前面字符相等之处
}
/**
 *   求模式串T的next函数修正值并存入数组nextval
 *
 */
void get_nextval(SString T,int nextval[])
{
    int i = 1,j = 0;
    nextval[1]  = 0;
    while(i<T[0])
        if(j == 0 || T[i] == T[j])
        {
            i++;
            j++;
            if(T[i]!=T[j])
                nextval[i] = j;
            else
                nextval[i] = nextval[j];
        }
    else
        j = nextval[j];   //j减小到前面字符相等之处
}
/**
 *  利用模式串T的next数组求T在主串S中第pos个字符之后的位置的KMP算法
 *
 */
int Index_KMP(SString S,SString T,int pos,int next[])
{
    int i = pos,j = 1;
    while(i<=S[0] && j<=T[0])
        if(j == 0 || S[i] == T[j])
        {
            i++;
            j++;
        }
    else
        j = next[j];
    if(j>T[0])
        return i-T[0];
    else
        return 0;
    
}
#endif /* algo41_KMP____h */
