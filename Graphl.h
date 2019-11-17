#include "Graph.h"
#include "LList.h"

struct listUnit {
    int vertex; //边的终点
    int weight; //边的权
};

class Graphl : public Graph {
    LList<listUnit> *vexList;

public:
    Graphl(int numVert) : Graph(numVert) {
        vexList = new LList<listUnit>[numVertex];
    }
    ~Graphl() { delete[] vexList; };
    int weight(int from, int to) {
        Link<listUnit> *temp = vexList[from].Head();
        while (temp->next != NULL && temp->next->element.vertex != to) {
            temp = temp->next;
        }
        return temp->next->element.weight;
    }
    int FirstAdj(int oneVertex) {
        Link<listUnit> *temp = vexList[oneVertex].Head();
        if (temp->next != NULL) {
            return temp->next->element.vertex;
        }
        return -1;
    }
    int NextAdj(int oneVertex, int preVertex) {
        Link<listUnit> *temp = vexList[oneVertex].Head();
        while (temp->next != NULL && temp->next->element.vertex <= preVertex) {
            temp = temp->next;
        }
        if (temp->next != NULL) {
            return temp->next->element.vertex;
        }
        return -1;
    }
    void setEdge(int from, int to, int weight) {
        Link<listUnit> *temp = vexList[from].Head();
        while (temp->next != NULL && temp->next->element.vertex < to) {
            temp = temp->next;
        }
        if (temp->next == NULL) {
            temp->next = new Link<listUnit>;
            temp->next->element.vertex = to;
            temp->next->element.weight = weight;
            numEdge++;
            InDegree[to]++;
            return;
        }
        if (temp->next->element.vertex == to) {
            temp->next->element.weight = weight;
            return;
        }
        if (temp->next->element.vertex > to) {
            Link<listUnit> *other = temp->next;
            temp->next = new Link<listUnit>;
            temp->next->element.vertex = to;
            temp->next->element.weight = weight;
            temp->next->next = other;
            numEdge++;
            InDegree[to]++;
            return;
        }
    }
    void delEdge(int from, int to) {
        Link<listUnit> *temp = vexList[from].Head();
        while (temp->next != NULL && temp->next->element.vertex < to) {
            temp = temp->next;
        }
        if (temp->next == NULL) {
            return;
        }
        if (temp->next->element.vertex == to) {
            Link<listUnit> *other = temp->next->next;
            delete temp->next;
            temp->next = other;
            numEdge--;
            InDegree[to]--;
            return;
        }
    }
};
