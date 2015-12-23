#include <bits/stdc++.h>
using namespace std;

// keeps track of the coordinates of each node
vector<pair<int,int> > nodes;

// calculates the manhattan distance between two points
int distance(pair<int,int> ptA, pair<int,int> ptB)
{
    return abs(ptA.first - ptB.first) + abs(ptA.second - ptB.second);
}

// initializes a graph, only creating edges if the distance between
// two nodes is not greater than 1000, that is, we can make it on a 
// single box of beer
// then performs a BFS to see if we can get to the end from the start
bool solve()
{
    int num_nodes = nodes.size();
    map<int, vector<int> > adj;
    for (int i = 0; i < num_nodes; i++)
    {
        adj[i] = vector<int>();
    }

    // initializing graph with valid edges only
    for (int i = 0; i < num_nodes; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (distance(nodes[i], nodes[j]) <= 20*50)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    // doing the BFS
    int src = 0, dst = num_nodes-1;
    set<int> visited = set<int>();
    deque<int> to_visit = deque<int>();
    to_visit.push_back(src);

    while (!to_visit.empty())
    {
        int current = to_visit.front();
        to_visit.pop_front();
        visited.insert(current);

        if (current == dst)
        {
            // we're able to reach the end!
            return true;
        }

        for (int i : adj[current])
        {
            if (visited.count(i) == 0)
            {
                to_visit.push_back(i);
            }
        }
    }

    // went through all edges without getting to the party
    return false;
}

int main()
{
    int T, N;
    int x, y;
    cin >> T;
    while (T--)
    {
        cin >> N;
        // there are N stops along the way, plus the start and the end point
        nodes.resize(N+2);
        for (int i = 0; i < N + 2; i++)
        {
            cin >> x >> y;
            nodes[i] = make_pair(x, y);
        }

        bool okay = solve();
        if (okay)
        {
            cout << "happy" << endl;
        }
        else
        {
            cout << "sad" << endl;
        }
    }
}
