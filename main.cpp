#include<cstdio>
#include<stack>
#include<vector>
#include"graph.h"

using namespace std;

/*
由林品儒和陳哲雋聯合編寫
made by 40147014S & 40147005S
*/

int main()
{
    int T=0;//case Number
    scanf(" %d",&T);

    for(int t=0;t<T;t+=1)
    {
        char  finalNodeChar;
        scanf(" %c",&finalNodeChar);
        getchar();
        int nodeNum=finalNodeChar-'A'+1;
        Graph graph(nodeNum);
        bool nodeUsed[26]={0};

        //draw grapg
        char first,second;//1stNode&2ndNode
        while(scanf("%c",&first)!=EOF&&first!='\n')
        {
            scanf("%c",&second);
            graph.AddEdge(first-'A',second-'A');

            getchar();
        }

        int subGraphNum=0;

        for(int i=0;i<nodeNum;i+=1)
        {
            if(nodeUsed[i])continue;
            else//DFS
            {
                subGraphNum+=1;
                stack<int> nodeStack;
                nodeStack.push(i);

                while(!nodeStack.empty())
                {
                    int nodeNow=nodeStack.top();
                    nodeStack.pop();
                    if(nodeUsed[nodeNow])continue;
                    nodeUsed[nodeNow]=true;
                    vector<int> nextNode=graph.Span(nodeNow);
                    for(vector<int>::iterator it=nextNode.begin();it!=nextNode.end();it+=1)
                    {
                        nodeStack.push(*it);
                    }
                }
            }
        }

        if(t!=0)printf("\n\n");
        printf("%d",subGraphNum);
    }
}
