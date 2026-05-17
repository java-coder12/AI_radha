#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

map<string, vector<string>> city;
map<string, bool> visitedDFS;
map<string, bool> visitedBFS;

queue<string> q;

// Recursive DFS
void DFS(string current)
{
    visitedDFS[current] = true;
    cout << current << " ";
    for(string next : city[current])
    {
        if(!visitedDFS[next])
        {
            DFS(next);
        }
    }
}

// Recursive BFS
void BFS()
{
    if(q.empty())
        return;

    string current = q.front();
    q.pop();

    cout << current << " ";

    for(string next : city[current])
    {
        if(!visitedBFS[next])
        {
            visitedBFS[next] = true;
            q.push(next);
        }
    }

    BFS(); // Recursive Call
}

int main()
{
    int roads;

    cout << "Enter number of roads: ";
    cin >> roads;

    cout << "Enter connected cities:\n";

    for(int i = 0; i < roads; i++)
    {
        string u, v;
        cin >> u >> v;

        city[u].push_back(v);
        city[v].push_back(u);
    }

    string start;

    cout << "Enter starting city: ";
    cin >> start;

    cout << "\nDFS Traversal: ";
    DFS(start);

    cout << "\nBFS Traversal: ";

    visitedBFS[start] = true;
    q.push(start);

    BFS();

    return 0;
}
