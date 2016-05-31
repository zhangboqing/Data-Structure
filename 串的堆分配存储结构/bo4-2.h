//
//  bo4-2.h
//  数据结构
//
//  Created by 张波清 on 5/30/16.
//  Copyright © 2016 zhangboqing. All rights reserved.
//
//12个基本操作
#ifndef bo4_2_h
#define bo4_2_h

#define DestroyString ClearString  //DestroyString()与ClearString()作用相同
/**
 *  初始化（产生空串）字符串S
 *
 */
void InitString(HString *S)
{
    (*S).length = 0;
    (*S).ch = NULL;
}
/**
 *  将S清为空串
 *
 *  @param S <#S description#>
 */
void ClearString(HString *S)
{
    free((*S).ch);
    InitString(S);
}
/**
 *  生成一个其值等于串常量chars的串T
 *
 */
void StrAssign(HString *T,char* chars)
{
    int i,j;
    if((*T).ch)   //T指向某个存储单元
        free((*T).ch);
    i = (int)strlen(chars);
    if(!i)
        InitString(T);
    else
    {
        (*T).ch = (char *)malloc(i*sizeof(char));
        if(!(*T).ch)
            exit(OVERFLOW);
        for(j = 0;j<i;j++)
            (*T).ch[j] = chars[j];
        (*T).length = i;
    }
    
}
/**
 *  由串S复制得串T
 *
 */
void StrCopy(HString *T,HString S)
{
    int i;
    if((*T).ch)
        free((*T).ch);
    (*T).ch = (char*)malloc(S.length*sizeof(char));
    if (!(*T).ch)
        exit(OVERFLOW);
    for(i = 0;i<S.length;i++)
        (*T).ch[i] = S.ch[i];
    (*T).length = S.length;
}
//若S为空串，则返回TRUE；否则返回FALSE
Status StrEmpty(HString S)
{
    if(S.length == 0 && S.ch == NULL )//空串标志
        return TRUE;
    else
        return FALSE;
}
/**
 *  若S>T，返回值>0；若S＝T，返回值＝0；若S<T,返回值<0
 *
 */
int StrCompare(HString S,HString T)
{
    int i;
    for (i = 0; i<S.length && i<T.length; i++)
        if(S.ch[i] != T.ch[i])
            return S.ch[i]-T.ch[i];
    return S.length-T.length;
}
/**
 *  返回串S的元素个数
 *
 */
int StrLength(HString S)
{
    return S.length;
}
/**
 *  用T返回S1和S2连接而成的新串。若未截断，返回TRUE，否则返回FALSE
 *
 */
void Concat(HString *T,HString S1,HString S2)
{
    int i;
    if((*T).ch)
        free((*T).ch);
    (*T).length = S1.length+S2.length;
    (*T).ch = (char*)malloc((*T).length*sizeof(char));
    if(!(*T).ch)
        exit(OVERFLOW);
    for(i = 0;i<S1.length;i++)
        (*T).ch[i] = S1.ch[i];
    for (i = 0; i<S2.length; i++)
        (*T).ch[S1.length+i] = S2.ch[i];
    
}
/**
 *  用Sub返回串S的自第pos个字符起长度为len的子串
 *
 */
Status SubString(HString *Sub,HString S,int pos,int len)
{
    int i;
    if(pos<1||pos>S.length||len<0||len>S.length-pos+1)
        return ERROR;
    if((*Sub).ch)   //串Sub不为空
        free((*Sub).ch);
    if(!len)     //空子串
        InitString(Sub);
    else
    {
        (*Sub).ch = (char*)malloc(len*sizeof(char));
        if(!(*Sub).ch)
            exit(OVERFLOW);
        for(i = 0;i<=len-1;i++)
            (*Sub).ch[i] = S.ch[pos-1+i];
        (*Sub).length = len;
    }
    return OK;
}
/**
 *  在串S的第pos个字符之前插入串T。完全插入返回TRUE，部分插入返回FALSE
 *
 */
Status StrInsert(HString *S,int pos,HString T)
{
    int i;
    if(pos<1||pos>(*S).length+1)
        return ERROR;
    if(T.length)
    {
        (*S).ch = (char*)realloc((*S).ch,((*S).length+T.length)*sizeof(char));
        if(!(*S).ch)
            exit(OVERFLOW);
        for(i = (*S).length-1;i>=pos-1;--i)
            (*S).ch[i+T.length] = (*S).ch[i];
        for(i = 0;i<T.length;i++)
            (*S).ch[pos-1+i] = T.ch[i];
        (*S).length += T.length;
    }
    return OK;
    
}
/**
 *  从串S中删除第pos个字符起长度为len的子串
 *
 */
Status StrDelete(HString *S,int pos,int len)
{
    int i;
    if((*S).length<pos+len-1)
        return ERROR;
    for(i = pos-1;i<=(*S).length-len;i++)   //将待删除子串之后的字符逐一前移
        (*S).ch[i] = (*S).ch[i+len];
    (*S).length -= len;
    (*S).ch = (char*)realloc((*S).ch,(*S).length*sizeof(char));
    return OK;
}
/**
 *  输出字符串S
 *
 */
void StrPrint(HString S)
{
    int i;
    for(i = 0;i<S.length;i++)
        printf("%c",S.ch[i]);
    printf("\n");
}
#endif /* bo4_2_h */
