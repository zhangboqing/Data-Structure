//
//  bo7-1.h
//  数据结构
//
//  Created by 张波清 on 7/4/16.
//  Copyright © 2016 zhangboqing. All rights reserved.
//
//图的邻接矩阵存储的基本操作（17个）
#ifndef bo7_1_h
#define bo7_1_h
/**
 *  若G中存在顶点u，则返回该顶点在图中位置（序号）；否则返回－1
 *
 */
int LocateVex(MGraph G,VertexType u)
{
    int i;
    for (i = 0; i<G.vexnum; i++)   //对所有顶点依次查找
        if (strcmp(u.name,G.vexs[i].name)==0)  //顶点与给定的u的顶点名称相同
            return i;
    return -1;
}
/**
 *  采用数组（邻接矩阵）表示法，构造有向图G
 *
 */
void CreateDG(MGraph *G)
{
    int i,j,k,IncInfo;   //IncInfo为0则弧不含相关信息
    VertexType v1,v2;   //顶点类型
    printf("请输入有向图G的顶点数，弧数，弧是否含相关信息（是：1否：0）：");
    scanf("%d,%d,%d",&(*G).vexnum,&(*G).arcnum,&IncInfo);
    printf("请输入%d个顶点的值（名称<%d个字符）：\n",(*G).vexnum,MAX_NAME);
    for (i = 0; i<(*G).vexnum; i++)  //构造顶点向量
        Input(&(*G).vexs[i]);      //根据顶点信息的类型，输入顶点信息，在func7-1.h中
    for (i = 0; i<(*G).vexnum;i++ )    //初始化二维邻接矩阵（弧信息）
        for (j = 0; j<(*G).vexnum;j++) {
            (*G).arcs[i][j].adj = 0;    //图，不相邻
            (*G).arcs[i][j].info = NULL;  //无相关信息
        }
    printf("请输入%d条弧的弧尾 弧头：\n",(*G).arcnum);
    for (k = 0; k<(*G).arcnum; k++) {
        scanf("%s%s%*c",v1.name,v2.name);    //％＊c吃掉回车符（起跳过一个字符的作用）
        i = LocateVex(*G, v1);    //弧尾的序号
        j = LocateVex(*G, v2);      //弧头的序号
        (*G).arcs[i][j].adj = 1;    //有向图
        if (IncInfo) {          //有相关信息
            InputArc(&(*G).arcs[i][j].info);  //动态生成存储空间，输入弧的相关信息，在func7-2.h中
        }
    }
    (*G).kind = DG;
}

/**
 *  采用数组（邻接矩阵）表示法，构造有向网G
 *
 */
void CreateDN(MGraph *G)
{
    int i,j,k,IncInfo;   //IncInfo为0则弧不含相关信息
    VRType w;
    VertexType v1,v2;   //顶点类型
    printf("请输入有向网G的顶点数，弧数，弧是否含相关信息（是：1否：0）：");
    scanf("%d,%d,%d",&(*G).vexnum,&(*G).arcnum,&IncInfo);
    printf("请输入%d个顶点的值（名称<%d个字符）：\n",(*G).vexnum,MAX_NAME);
    for (i = 0; i<(*G).vexnum; i++)  //构造顶点向量
        Input(&(*G).vexs[i]);      //根据顶点信息的类型，输入顶点信息，在func7-1.h中
    for (i = 0; i<(*G).vexnum;i++ )    //初始化二维邻接矩阵（弧信息）
        for (j = 0; j<(*G).vexnum;j++) {
            (*G).arcs[i][j].adj = INFINITY1;    //网，不相邻
            (*G).arcs[i][j].info = NULL;  //无相关信息
        }
    printf("请输入%d条弧的弧尾 弧头 权值：\n",(*G).arcnum);
    for (k = 0; k<(*G).arcnum; k++) {
        scanf("%s%s%d%*c",v1.name,v2.name,&w);    //％＊c吃掉回车符（起跳过一个字符的作用）
        i = LocateVex(*G, v1);    //弧尾的序号
        j = LocateVex(*G, v2);      //弧头的序号
        (*G).arcs[i][j].adj = w;    //有向图
        if (IncInfo) {          //有相关信息
            InputArc(&(*G).arcs[i][j].info);  //动态生成存储空间，输入弧的相关信息，在func7-2.h中
        }
    }
    (*G).kind = DN;
}
/**
 *  采用数组（邻接矩阵）表示法，构造无向图G
 *
 */
void CreateUDG(MGraph *G)
{
    int i,j,k,IncInfo;   //IncInfo为0则弧不含相关信息
    VertexType v1,v2;   //顶点类型
    printf("请输入无向图G的顶点数，边数，边是否含相关信息（是：1否：0）：");
    scanf("%d,%d,%d",&(*G).vexnum,&(*G).arcnum,&IncInfo);
    printf("请输入%d个顶点的值（名称<%d个字符）：\n",(*G).vexnum,MAX_NAME);
    for (i = 0; i<(*G).vexnum; i++)  //构造顶点向量
        Input(&(*G).vexs[i]);      //根据顶点信息的类型，输入顶点信息，在func7-1.h中
    for (i = 0; i<(*G).vexnum;i++ )    //初始化二维邻接矩阵（弧信息）
        for (j = 0; j<(*G).vexnum;j++) {
            (*G).arcs[i][j].adj = 0;    //图，不相邻
            (*G).arcs[i][j].info = NULL;  //无相关信息
        }
    printf("请输入%d条边的顶点1 顶点2：\n",(*G).arcnum);
    for (k = 0; k<(*G).arcnum; k++) {
        scanf("%s%s%*c",v1.name,v2.name);    //％＊c吃掉回车符（起跳过一个字符的作用）
        i = LocateVex(*G, v1);    //顶点1的序号
        j = LocateVex(*G, v2);      //顶点2的序号
        (*G).arcs[i][j].adj = 1;    //图
        if (IncInfo) {          //有相关信息
            InputArc(&(*G).arcs[i][j].info);  //动态生成存储空间，输入弧的相关信息，在func7-2.h中
        }
        (*G).arcs[j][i] = (*G).arcs[i][j]; //无向，两个单元的信息相同
    }
    (*G).kind = UDG;
}

/**
 *  采用数组（邻接矩阵）表示法，构造无向网G
 *
 */
void CreateUDN(MGraph *G)
{
    int i,j,k,IncInfo;   //IncInfo为0则弧不含相关信息
    VRType w; //顶点关系类型
    VertexType v1,v2;   //顶点类型
    printf("请输入无向图G的顶点数，边数，边是否含相关信息（是：1否：0）：");
    scanf("%d,%d,%d",&(*G).vexnum,&(*G).arcnum,&IncInfo);
    printf("请输入%d个顶点的值（名称<%d个字符）：\n",(*G).vexnum,MAX_NAME);
    for (i = 0; i<(*G).vexnum; i++)  //构造顶点向量
        Input(&(*G).vexs[i]);      //根据顶点信息的类型，输入顶点信息，在func7-1.h中
    for (i = 0; i<(*G).vexnum;i++ )    //初始化二维邻接矩阵（弧信息）
        for (j = 0; j<(*G).vexnum;j++) {
            (*G).arcs[i][j].adj = INFINITY1;    //图，不相邻
            (*G).arcs[i][j].info = NULL;  //无相关信息
        }
    printf("请输入%d条边的顶点1 顶点2 权值：\n",(*G).arcnum);
    for (k = 0; k<(*G).arcnum; k++) {
        scanf("%s%s%d%*c",v1.name,v2.name,&w);    //％＊c吃掉回车符（起跳过一个字符的作用）
        i = LocateVex(*G, v1);    //顶点1的序号
        j = LocateVex(*G, v2);      //顶点2的序号
        (*G).arcs[i][j].adj = w;    //图
        if (IncInfo) {          //有相关信息
            InputArc(&(*G).arcs[i][j].info);  //动态生成存储空间，输入弧的相关信息，在func7-2.h中
        }
        (*G).arcs[j][i] = (*G).arcs[i][j]; //无向，两个单元的信息相同
    }
    (*G).kind = UDN;
}
/**
 *  采用数组（邻接矩阵）表示法，构造图G。
 *
 */
void CreateGraph(MGraph *G)
{
    printf("请输入图G的类型（有向图：0有向网：1无向图：2无向网：3）：");
    scanf("%d",&(*G).kind);
    switch ((*G).kind) {   //根据图G的类型，调用不同的构造图的函数
        case DG:
            CreateDG(G);  //构造有向图
            break;
        case DN:
            CreateDN(G);  //构造有向网
            break;
        case UDG:
            CreateUDG(G); //构造无向图
            break;
        case UDN:
            CreateUDN(G); //构造无向网
    }
}
/**
 *  返回v的值
 *
 */
VertexType GetVex(MGraph G,int v)
{
    if (v>G.vexnum||v<0)  //图G中不存在序号为v的顶点
        exit(OVERFLOW);
    return G.vexs[v];  //返回该顶点的信息
}
/**
 *  对v赋新值value
 *
 */
Status PuyVex(MGraph *G,VertexType v,VertexType value)
{
    int k = LocateVex(*G, v);  //k为顶点v在图G中的序号
    if (k<0)        //不存在顶点v
        return ERROR;
    (*G).vexs[k] = value;  //将新值赋给顶点v（其序号为k）
    return OK;
        
}
/**
 *  返回v的第一个邻接顶点的序号。若顶点在G中没有邻接顶点，则返回－1
 *
 */
int FirstAdjVex(MGraph G,int v)
{
    int i;
    VRType j = 0;   //顶点关系类型，图
    if(G.kind%2)  //网
        j = INFINITY1;
    for(i = 0;i<G.vexnum;i++)   //从第一个顶点开始查找
        if(G.arcs[v][i].adj!=j)  //是第一个邻接顶点
            return i;  //返回该邻接顶点的序号
    return -1;   //没有邻接顶点
}
/**
 *  返回v的（相对于w的）下一个邻接顶点的序号。若w是v的最后一个邻接顶点，则返回－1
 *
 */
int NextAdjVex(MGraph G,int v,int w)
{
    int i;
    VRType j = 0;   //顶点关系类型，图
    if(G.kind%2)  //网
        j = INFINITY1;
    for(i = w+1;i<G.vexnum;i++)   //从第w+1个顶点开始查找
        if(G.arcs[v][i].adj!=j)  //是从w＋1开始的第一个邻接顶点
            return i;  //返回该邻接顶点的序号
    return -1;   //没有下一个邻接顶点
}
/**
 *  在图G中增添新顶点v（不增添与顶点相关的弧，留待InsertArc()去做）
 *
 */
void InsertVex(MGraph *G,VertexType v)
{
    int i;
    VRType j = 0;   //顶点关系类型，图
    if((*G).kind%2)  //网
        j = INFINITY1;
    (*G).vexs[(*G).vexnum] = v; //将值v赋给新顶点
    for (i = 0; i<=(*G).vexnum; i++) {  //对于新增行、新增列
        (*G).arcs[(*G).vexnum][i].adj = (*G).arcs[i][(*G).vexnum].adj=j; //初始化新增行、新增列邻接矩阵的值（无弧）
        (*G).arcs[(*G).vexnum][i].info = (*G).arcs[i][(*G).vexnum].info=NULL; //初始化相关信息指针
    }
    (*G).vexnum++;  //图G的顶点数加1
}
/**
 *  在G中增添弧<v,w>,若G是无向的，则还增添对称弧<w,v>
 *
 */
Status InsertArc(MGraph *G,VertexType v,VertexType w)
{
    int  i,v1,w1;
    v1 = LocateVex(*G, v); //弧尾顶点v的序号
    w1 = LocateVex(*G, w); //弧头顶点w的序号
    if(v1<0||w1<0)      //不存在顶点v或w
        return ERROR;
    (*G).arcnum++;  //弧数加1
    if((*G).kind%2) //网
    {
        printf("请输入此弧的权值：");
        scanf("%d",&(*G).arcs[v1][w1].adj);
    }
    else  //图
        (*G).arcs[v1][w1].adj = 1;
    printf("是否有该弧的相关信息（0:无1:有):");
    scanf("%d%*c",&i);
    if(i)
        InputArc(&(*G).arcs[v1][w1].info);//动态生成存储空间，输入弧的相关信息，在func7-2.h中
    if((*G).kind>1) //无向
        (*G).arcs[w1][v1] = (*G).arcs[v1][w1]; //有同样的邻接值，指向同一个相关信息
    return OK;
}
/**
 *  在G中删除弧<v,w>,若G是无向的，则还删除对称弧<w,v>
 *
 */
Status DeleteArc(MGraph *G,VertexType v,VertexType w)
{
    int  v1,w1;
    VRType j = 0;
    if((*G).kind%2) //网
        j = INFINITY1;
    v1 = LocateVex(*G, v); //弧尾顶点v的序号
    w1 = LocateVex(*G, w); //弧头顶点w的序号
    if(v1<0||w1<0)      //不存在顶点v或w
        return ERROR;
    if((*G).arcs[v1][w1].adj!=j)  //有弧<v,w>
    {
        (*G).arcs[v1][w1].adj = j; //删除弧<v,w>
        if((*G).arcs[v1][w1].info)  //有相关信息
        {
            free((*G).arcs[v1][w1].info); //释放相关信息
            (*G).arcs[v1][w1].info = NULL; //置相关信息指针为空
        }
        if((*G).kind>=2)  //无向，删除对称弧<w,v>
            (*G).arcs[w1][v1] =  (*G).arcs[v1][w1]; //删除弧，置相关信息指针为空
        (*G).arcnum--;  //弧数－1
    }
    return OK;
}
/**
 *删除G中顶点v及其相关的弧
 *
 */
Status DeleteVex(MGraph *G,VertexType v)
{
    int i,j,k;
    k = LocateVex(*G, v);  //k为待删除顶点v的序号
    if(k<0)
        return ERROR;
    for(i = 0;i<(*G).vexnum;i++)
        DeleteArc(G, v, (*G).vexs[i]);   //删除由顶点v发出的所有弧
    if((*G).kind<2)  //有向
        for(i = 0;i<(*G).vexnum;i++)
            DeleteArc(G, (*G).vexs[i],v);  //删除发向顶点v的所有弧
    for(j = k+1;j<(*G).vexnum;j++)
        (*G).vexs[j-1] = (*G).vexs[j];   //序号k后面的顶点向量依次前移
    for(i = 0;i<(*G).vexnum;i++)
        for(j = k+1;j<(*G).vexnum;j++)
            (*G).arcs[i][j-1] = (*G).arcs[i][j];  //移动待删除顶点之后的矩阵元素
    for(i = 0;i<(*G).vexnum;i++)
        for(j = k+1;j<(*G).vexnum;j++)
            (*G).arcs[j-1][i] = (*G).arcs[j][i];  //移动待删除顶点之下的矩阵元素
    (*G).vexnum--;   //更新图的顶点数
    return OK;
}
/**
 *  销毁图G
 *
 */
void DestroyGraph(MGraph *G)
{
    int i;
    for(i = (*G).vexnum-1;i>=0;i--)  //由大到小逐一删除顶点及其相关的弧
        DeleteVex(G, (*G).vexs[i]);
}
/**
 *  输出邻接矩阵存储结构的图G
 *
 */
void Display(MGraph G)
{
    int i,j;
    char s[10] = "无向图",s1[4] = "边";
    switch (G.kind) {
        case DG:
            strcpy(s, "有向图");
            strcpy(s1, "弧");
            break;
        case DN:
            strcpy(s, "有向网");
            strcpy(s1, "弧");
            break;
        case UDG:
            strcpy(s, "无向图");
        case UDN: ;
    }
    printf("%d个顶点%d条%s的%s。顶点依次是：",G.vexnum,G.arcnum,s1,s);
    for(i = 0;i<G.vexnum;i++)
        Visit(GetVex(G, i));    //根据顶点信息的类型，访问第i个顶点，在func7－1.h中
    printf("\nG.arcs.adj:\n");
    for(i = 0;i<G.vexnum;i++)  //输出二维数组G.arcs.adj
    {
        for(j = 0;j<G.vexnum;j++)
            if(G.arcs[i][j].adj==INFINITY1)
                printf("∞");
        else
            printf("%4d",G.arcs[i][j].adj);
        printf("\n");
    }
    printf("G.arcs.info:\n");   //输出G.arcs.info
    if(G.kind<2) //有向
        printf("弧尾 弧头 该%s的信息:\n",s1);
    else //无向
        printf("顶点1 顶点2该%s的信息:\n",s1);
    for(i = 0;i<G.vexnum;i++)
        if(G.kind<2) //有向
        {
            for(j = 0;j<G.vexnum;j++)
                if(G.arcs[i][j].info)
                {
                    printf("%5s%5s",G.vexs[i].name,G.vexs[j].name);
                    OutputArc(G.arcs[i][j].info);   //输出弧的相关信息，在func7-2.h中
                }
        }
        else    //无向，输出上三角
            for(j = i+1;j<G.vexnum;j++)
                if(G.arcs[i][j].info)
                {
                    printf("%5s%5s",G.vexs[i].name,G.vexs[j].name);
                    OutputArc(G.arcs[i][j].info);  //输出弧的相关信息，在func7-2.h中
                }
}
/**
 *  采用数组（邻接矩阵）表示法，由文件构造图或网G。IncInfo＝0或1，表示弧无或有相关信息
 *
 */
void CreateFromFile(MGraph *G,char* filename,int IncInfo)
{
    int i,j,k;
    VRType w = 0;   //顶点关系类型，图
    VertexType v1,v2;  //顶点类型
    FILE* f;    //文件指针类型
    f = fopen(filename, "r");  //打开数据文件，并以f表示
    fscanf(f, "%d",&(*G).kind); //由文件输入G的类型
    if((*G).kind%2)   //网
        w = INFINITY1;
    fscanf(f, "%d",&(*G).vexnum);  //由文件输入G的顶点数
    for(i = 0;i<(*G).vexnum;i++)
        InputFromFile(f, &(*G).vexs[i]); //由文件输入顶点信息，在func7-1.h中
    fscanf(f, "%d",&(*G).arcnum);  //由文件输入G的弧数
    for(i = 0;i<(*G).vexnum;i++)   //初始化二维邻接矩阵
        for(j = 0;j<(*G).vexnum;j++)
        {
            (*G).arcs[i][j].adj = w;  //不相邻
            (*G).arcs[i][j].info = NULL; //没有相关信息
        }
    if(!((*G).kind%2))  //图
        w = 1;
    for(k = 0;k<(*G).arcnum;k++)  //对于所有弧
    {
        fscanf(f, "%s%s",v1.name,v2.name);  //输入弧尾、弧头的名称
        if((*G).kind%2)   //网
            fscanf(f, "%d",&w);   //再输入权值
        i = LocateVex(*G, v1);  //弧尾的序号
        j = LocateVex(*G, v2);  //弧头的序号
        (*G).arcs[i][j].adj = w;  //权值
        if(IncInfo)   //有相关信息
            InputArcFromFile(f,&(*G).arcs[i][j].info);  //由文件动态生成存储空间，输入弧的相关信息，在func7-2.h中
        if((*G).kind>1)   //无向
            (*G).arcs[j][i] = (*G).arcs[i][j];  //无向，两个单元的信息相同
    }
    fclose(f);  //关闭数据文件
}
#endif /* bo7_1_h */

