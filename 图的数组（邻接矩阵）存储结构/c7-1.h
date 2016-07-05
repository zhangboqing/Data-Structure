//
//  c7-1.h
//  数据结构
//
//  Created by 张波清 on 6/17/16.
//  Copyright © 2016 zhangboqing. All rights reserved.
//

#ifndef c7_1_h
#define c7_1_h

#define INFINITY1 INT_MAX   //用整数最大值代替无穷大
typedef int VRType;         //定义顶点关系类型为整型，与INFINITY1的类型一致
#define MAX_VERTEX_NUM  26  //最大顶点个数
typedef enum {DG,DN,UDG,UDN} GraphKind;  //｛有向图，有向网，无向图，无向网｝

typedef struct          //弧信息结构
{
    VRType adj;    //顶点关系类型。对无权图，用1（是）或0（否）表示相邻否；对带权图，则为权值
    infoType *info; //该弧相关信息的指针（可无）
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//二维数组

typedef struct  {     //图的结构
    VertexType vexs[MAX_VERTEX_NUM]; //顶点向量
    AdjMatrix arcs;             //邻接矩阵（二维数组）
    int vexnum,arcnum;          //图的当前顶点树和弧树
    GraphKind kind;         //图的种类标志
}MGraph;

#endif /* c7_1_h */
