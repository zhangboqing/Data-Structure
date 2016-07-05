//
//  func7-1.h
//  数据结构
//
//  Created by 张波清 on 6/17/16.
//  Copyright © 2016 zhangboqing. All rights reserved.
//
//包括顶点信息类型的定义及对它的操作
#ifndef func7_1_
#define func7_1_

#define MAX_NAME 9  //定义顶点名称字符串的最大长度＋1
typedef struct      //最简单的顶点信息类型（只有顶点名称）
{
    char name[MAX_NAME];  //顶点名称
}VertexType;

void  Visit(VertexType ver) //与之配套的访问顶点的名称
{
    printf("%s",ver.name);
}

void Input(VertexType *ver)  //与之配套的输入顶点信息的函数
{
    scanf("%s",(*ver).name);
}

void InputFromFile(FILE *f,VertexType *ver)     //与之配套的从文件输入顶点信息的函数
{
    fscanf(f, "%s",(*ver).name);
}
#endif /* func7_1_h */
