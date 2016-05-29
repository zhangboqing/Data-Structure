//
//  bo4-1.h
//  数据结构
//
//  Created by 张波清 on 5/27/16.
//  Copyright © 2016 zhangboqing. All rights reserved.
//
//基本操作12个
//SString是数组，故不需要引用类型
#ifndef bo4_1_h
#define bo4_1_h

#define DestroyString ClearString
#define InitString ClearString
/**
 *  生成一个其值等于chars的串T
 *
 */
Status StrAssign(SString T,char* chars)
{
    int i;
    if(strlen(chars)>MAX_STR_LEN)
        return ERROR;
    else
    {
        T[0] = strlen(chars);
        for(i = 1;i<=T[0];i++)
            T[i] = *(chars+i-1);
        return OK;
    }
}
/**
 *  由串S复制得串T
 *
 */
void StrCopy(SString T,SString S)
{
    int i;
    for(i = 0;i<=S[0];i++)
        T[i] = S[i];
}
//若S为空串，则返回TRUE；否则返回FALSE
Status StrEmpty(SString S)
{
    if(S[0] == 0)
        return TRUE;
    else
        return FALSE;
}
/**
 *  若S>T，返回值>0；若S＝T，返回值＝0；若S<T,返回值<0
 *
 */
int StrCompare(SString S,SString T)
{
    int i;
    for(i = 1;i<=S[0]&&i<=T[0];i++)
        if(S[i] != T[i])
            return  S[i]-T[i];
    return S[0]-T[0];
}
/**
 *  返回串S的元素个数
 *
 */
int StrLength(SString S)
{
    return S[0];
}
/**
 *  将S清为空串
 *
 */
void ClearString(SString S)
{
    S[0] = 0;
}
/**
 *  用T返回S1和S2连接而成的新串。若未截断，返回TRUE，否则返回FALSE
 *
 */
Status Concat(SString T,SString S1,SString S2)
{
    int i;
    if (S1[0]+S2[0]<=MAX_STR_LEN) //未截断
    {
        for(i = 1;i<=S1[0];i++)
            T[i] = S1[i];
        for (i = 1; i<=S2[0]; i++)
            T[S1[0]+i] = S2[i];
        T[0] = S1[0]+S2[0];
        return TRUE;
    }
    else
    {
        for (i = 1; i<=S1[0]; i++)
            T[i] = S1[i];
        for (i = 1;i<=MAX_STR_LEN-S1[0] ; i++)
            T[S1[0]+i] = S2[i];
        T[0] = MAX_STR_LEN;
        return FALSE;
    }
}
/**
 *  用Sub返回串S的自第pos个字符起长度为len的子串
 *
 */
Status SubString(SString Sub,SString S,int pos,int len)
{
    int i;
    if(pos<1||pos>S[0]||len<0||len>S[0]-pos+1)  //pos和len的值超出范围
        return ERROR;
    for(i =1;i<=len;i++)
        Sub[i] = S[pos+i-1];
    Sub[0] = len;
    return OK;
}
/**
 *  返回子串T在主串S中第S中第pos个字符之后的位置。若不存在，则函数值为0
 *
 */
int Index1(SString S,SString T,int pos)
{
    int i,j;        //指示主串S和子串T的当前比较字符
    if (1<=pos && pos<=S[0])        //pos的范围合适
    {
        i = pos;        //从主串S的第pos个字符开始和子串T的第一个字符比较
        j = 1;
        while(i<=S[0] && j<=T[0])
            if(S[i] == T[j])        //当前两字符相等
            {
                i++;                //继续比较后继字符
                j++;
            }
            else
            {
                i = i-j+2;      //两指针后退重新开始匹配
                j = 1;
            }
        if(j>T[0])              //主串S中存在子串T
            return i-T[0];
        else
            return 0;
    }
    else
        return 0;
}
/**
 *  在串S的第pos个字符之前插入串T。完全插入返回TRUE，部分插入返回FALSE
 *
 */
Status StrInsert(SString S,int pos,SString T)
{
    int i;
    if(pos<1 || pos>S[0]+1)
        return ERROR;
    if(S[0]+T[0] <= MAX_STR_LEN) //完全插入
    {
        for(i = S[0];i>=pos;i--)
            S[i+T[0]] = S[i];
        for(i = pos;i<pos+T[0];i++)
            S[i] = T[i-pos+1];
        S[0] += T[0];
        return TRUE;
    }
    else    //部分插入
    {
        for(i = MAX_STR_LEN;i>=pos+T[0];i--)    //移动串S中位于pos之后且移后仍在串内的字符
            S[i] = S[i-T[0]];
        for (i = pos; i<pos+T[0]&&i<=MAX_STR_LEN; i++)  //在串S中插入串T（也可能是部分插入
            S[i] = T[i-pos+1];
        S[0] = MAX_STR_LEN;
        return FALSE;
    }
}
#endif /* bo4_1_h */
