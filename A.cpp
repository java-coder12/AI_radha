#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

struct Node
{
    int x, y; // row and column
    int g, h;

    int f() const
    {
        return g + h;
    }
};

struct Compare
{
    bool operator()(Node a, Node b)
    {
        return a.f() > b.f();
    }
};

int maze[10][10];
bool visited[10][10]; 

pair<int,int> parent[10][10];

int rowDir[4] = {-1, 1, 0, 0};
int colDir[4] = {0, 0, -1, 1};

int rows, cols;
int goalX, goalY;

// Heuristic Function
int heuristic(int x, int y)
{
    return abs(x - goalX) + abs(y - goalY);
}

void Astar(int startX, int startY)
{
    priority_queue<Node, vector<Node>, Compare> pq;
    pq.push({startX, startY, 0, heuristic(startX, startY)});
    while(!pq.empty())
    {
        Node current = pq.top();
        pq.pop();

        int x = current.x;
        int y = current.y;

        if(visited[x][y])
            continue;

        visited[x][y] = true;

        // Goal reached
        if(x == goalX && y == goalY)
        {
            cout << "\nGoal Reached!\n";
            break;
        }

        for(int i = 0; i < 4; i++)
        {
            int newX = x + rowDir[i];
            int newY = y + colDir[i];

            if(newX >= 0 && newX < rows &&
               newY >= 0 && newY < cols &&
               maze[newX][newY] == 0 &&
               !visited[newX][newY])
            {
                int newG = current.g + 1;
                int newH = heuristic(newX, newY);

                pq.push({newX, newY, newG, newH});

                parent[newX][newY] = {x, y};
            }
        }
    }

    // Mark path
    int x = goalX;
    int y = goalY;

    while(!(x == startX && y == startY))
    {
        maze[x][y] = 2;

        pair<int,int> p = parent[x][y];
        x = p.first;
        y = p.second;
    }

    maze[startX][startY] = 2;

    // Display final maze
    cout << "\nTraced Path:\n";

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(maze[i][j] == 1)
                cout << "# ";
            else if(maze[i][j] == 2)
                cout << "* ";
            else
                cout << ". ";
        }
        cout << endl;
    }
}

int main()
{
    cout << "Enter rows and columns: ";
    cin >> rows >> cols;

    cout << "Enter maze (0 = path, 1 = blocked):\n";

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cin >> maze[i][j];
        }
    }

    int startX, startY;

    cout << "Enter start position: ";
    cin >> startX >> startY;

    cout << "Enter goal position: ";
    cin >> goalX >> goalY;

    Astar(startX, startY);

    return 0;
}