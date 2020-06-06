#include <iostream>
#include <queue>
#include <string>
#include <stack>
#include <cstdlib>
#include <map>

using namespace std;

struct Graph
{
    char G_tp;
    char S_tp;
};

string Matrix[1000][1000];
map <string,int> nodes;
map <string, map < string, int> > Matrix2;
string mask[1000];

int main()
{
    for(int i=0;i<=200;i++)
    {
        for(int j=0;j<=200;j++)
        {
            Matrix[i][j]="0";
        }
    }
    queue<string> Queue;
    stack<string> Stack;
    Graph graph;
    string tmp,tmp2,start;
    int  st, fin, N = 1,b=0;
    cin >> graph.G_tp >> start >> graph.S_tp;
    if (graph.G_tp == 'd')
    {
        while (!cin.eof())
        {
            cin>>tmp;
            cin>>tmp2;
            Matrix2[tmp][tmp2]=1;
        }
    }
    else
    {

        while (!cin.eof())
        {
            cin>>tmp;
            cin>>tmp2;
            Matrix2[tmp][tmp2]=1;
            Matrix2[tmp2][tmp]=1;
        }
    }



    if (graph.S_tp == 'b')
    {
        string node;
        Queue.push(start);
        while (!Queue.empty())
        {
            node = Queue.front();
            Queue.pop();
            nodes[node] = 2;
            for (map<string,int>::iterator it=Matrix2[node].begin();it!=Matrix2[node].end();++it)
            {
                if (Matrix2[node][it->first] == 1 && nodes[it->first] == 0)
                {
                    Queue.push(it->first);
                    nodes[it->first] = 1;
                }
            }

            cout << node << endl;
        }

    }

    else
    {
        string node;
        Stack.push(start);
        while (!Stack.empty())
        {
            node = Stack.top();

            Stack.pop();
            if (nodes[node] == 2) continue;
            nodes[node] = 2;
            for (map<string,int>::reverse_iterator it=Matrix2[node].rbegin();it!=Matrix2[node].rend();++it)
            {
                if (Matrix2[node][it->first] == 1 && nodes[it->first] != 2)
                {

                    Stack.push(it->first);
                    nodes[it->first] = 1;
                }

            }
            cout << node << endl;
        }
    }
    cin.get();

}
