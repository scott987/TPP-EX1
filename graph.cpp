#include<stdlib.h>
#include<vector>
#include"graph.h"
Graph::Graph(int e) {
    m_max=e;
    m_arr=(bool*)calloc(m_max*m_max,sizeof(bool));
}
//distructor
Graph::~Graph() {
    free(m_arr);
    m_arr=0;
}
//get length
int Graph::Length()const {
    return m_max;
}
//add edge with edge check
bool Graph::AddEdge(int a,int b) {
    if(a>=m_max) {
        return false;
    }
    if(b>=m_max) {
        return false;
    }
    m_arr[p_LinearConvert(a,b)]=true;
    m_arr[p_LinearConvert(b,a)]=true;
    return true;
}
//detect connection with edge check
bool Graph::IsConnected(int a,int b)const {
    if(a>=m_max) {
        return false;
    }
    if(b>=m_max) {
        return false;
    }
    return m_arr[p_LinearConvert(a,b)];
}
std::vector<int> Graph::Span(int a)const{
    std::vector<int> list;
    for(int i=0;i<m_max;i++){
      if(IsConnected(a,i))
        list.push_back(i);
    }
    return list;
}
