#include<vector>
#ifndef DEF_GRAPH
#define DEF_GRAPH
class Graph{
private:
  bool *m_arr;
  int m_max;
  int p_LinearConvert(int a,int b)const{return a*m_max+b;}
public:
  Graph(int e);
  ~Graph();;
  int Length()const;
  bool AddEdge(int a,int b);
  bool IsConnected(int a,int b)const;
  std::vector<int> Span(int a)const;
};
#endif
