class Graph {
protected:
    int numVertex; //图中的顶点个数
    int numEdge;   //边的个数
    bool *visited; //visted 指针标志位
    int *InDegree; //入度的数组

public:
    Graph(int numVert);
    ~Graph();
    virtual int FirstAdj(int oneVertex) = 0;                //返回与顶点oneVertex相关联的第一个邻接点
    virtual int NextAdj(int oneVertex, int preVertex) = 0;  //返回与顶点oneVertex相关联的preVertex之后的下一个邻接点
    int VerticesNum() { return numVertex; };                //返回图的顶点个数
    int EdgesNum() { return numEdge; };                     //返回边的个数
    virtual int weight(int from, int to) = 0;               //返回权重
    virtual void setEdge(int from, int to, int weight) = 0; //设置边
    virtual void delEdge(int from, int to) = 0;             //删除边
};