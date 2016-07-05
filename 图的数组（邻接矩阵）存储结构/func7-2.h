//
//  func7-2.h
//  数据结构
//
//  Created by 张波清 on 7/4/16.
//  Copyright © 2016 zhangboqing. All rights reserved.
//
//包括弧的相关信息类型的定义及对它的操作
#ifndef func7_2_h
#define func7_2_h

#define MAX_INFO 20 //弧的相关信息字符串的最大长度＋1
typedef char infoType; //弧的相关信息类型

void InputArc(infoType* *arc) //与之配套的输入弧的相关信息的函数
{
    char s[MAX_INFO];  //临时存储空间
    int m;
    printf("请输入该弧的相关信息（<%d个字符）：",MAX_INFO);
    gets(s);
    m = strlen(s);
    if (m) {
        *arc = (char*)malloc((m+1)*sizeof(char));
        strcpy(*arc, s);
    }
}

void InputArcFromFile(FILE* f,infoType* *arc)  //由文件输入弧的相关信息的函数
{
    char s[MAX_INFO];
    fgets(s, MAX_INFO, f);
    *arc = (char*)malloc((strlen(s)+1)*sizeof(char));
    strcpy(*arc, s);
}

void OutputArc(infoType* arc)  //与之配套的输出弧的相关信息的函数
{
    printf("%s\n",arc);
}
#endif /* func7_2_h */
