#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m;
  int x, y;
  double f;
  while (scanf("%d %d", &n, &m) == 2)
  {
    if (n == 0 && m == 0)
    {
      break;
    }

    // build up the adjacency list
    // adj[x] is the list of intersections adjacent to node x,
    // ordered by shrink factor first
    vector<vector<pair<double, int> > > adj(n);
    for (int i = 0; i < m; i++)
    {
      cin >> x >> y >> f;
      adj[x].push_back(make_pair(f, y));
      adj[y].push_back(make_pair(f, x));
    }

    // always start from 0, always end at n-1
    int start = 0;

    // initially set the distance to something low
    double dist[n];
    fill(dist, dist+n, 0);

    // except for the starting node,
    // which will be the max/starting factor of 1
    dist[start] = 1;

    // and we also keep track of what we've visited so far
    bool visited[n];
    fill(visited, visited+n, false);

    // keep track of what nodes we need to visit
    // this is sorted in descending orderby the double value,
    // which is the distance to the node
    priority_queue<pair<double, int> > to_visit;
    to_visit.push(make_pair(dist[start], start));

    pair<double, int> current;

    // we have some nodes to look at
    while (!to_visit.empty())
    {
      // take it out of the priority queue and work with it
      current = to_visit.top();
      to_visit.pop();

      // for all the nodes adjacent to the current one...
      for (pair<double, int> node : adj[current.second])
      {
        // if it hasn't been visited...
        if (!visited[node.second])
        {
          // then update the distance to it if moving from
          // current to that node gets us a greater distance
          if (dist[current.second] * node.first > dist[node.second])
          {
            dist[node.second] = dist[current.second] * node.first;
          }
          // now put in on the queue to visit, using the *updated* distance
          to_visit.push(make_pair(dist[node.second], node.second));
        }
      }

      // be sure to mark as visited so we don't process it again
      // and get stuck in an infinite loop
      visited[current.second] = true;

      // exit earlier if we've managed to reach the destination
      if (current.second == n-1)
      {
        break;
      }
    }

    // answer is the distance to node n-1
    printf("%0.4f\n", dist[n-1]);
  }
}
