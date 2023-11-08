/*
  We used Dijkstar algo to solve this problem.
  In every time we pick node 'u' the node which is not visited yet and minimum dist.
  Then we update the nodes that are connected with node 'u' dist if it needed (if we found min dist[v] > dist[u] + w).

  Problem link: https://leetcode.com/problems/network-delay-time/description/

  Time Complexity: O(m log m) where m is times.length().
*/

class Solution {

public:
int N = 1e2;
int INF = 1e9;

struct Node {
    int at, cost;
    Node(int _at, int _cost) {
        at = _at;
        cost = _cost;
    }
};

struct CompareNode {
    bool operator()(const Node& a, const Node& b) const {
        // Priority queue returns the smallest value.
        // So we need to write the comparator in a way
        // so that the smallest value becomes the greatest value.
        return a.cost > b.cost;
    }
};

struct Edge {
    int v, w;
    Edge(int _v, int _w) {
        v = _v;
        w = _w;
    }
};

vector < Edge >* adj = new vector<Edge>[N];
priority_queue < Node, vector<Node>, CompareNode > pq;
vector < int > dist;

void dijkstra(int u) {
    dist.resize(N, INF);
    dist[u] = 0;
    pq.push(Node(u, 0));

    while (!pq.empty()) {
        Node tp = pq.top(); pq.pop();

        // Here we tracking that tp.at is visited or not.
        // If once tp.at is visited we will not travers 
        // the nodes that are connected to tp.at.
        if (tp.cost != dist[tp.at])
            continue;
        
        for (Edge e : adj[tp.at]) {
            if (dist[e.v] > tp.cost + e.w) {
                dist[e.v] = tp.cost + e.w;
                pq.push(Node(e.v, dist[e.v]));
            }
        }
    }
}

int minimum_time(int n) {
    int mn = 0;
    for (int i = 1; i <= n; i++) {
        mn = max(mn, dist[i]);
    }

    return mn;
}

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    for (int i = 0; i < (int)times.size(); i++) {
        adj[times[i][0]].push_back(Edge(times[i][1], times[i][2]));
    }
    dijkstra(k);
    int ans = minimum_time(n);
    if (ans == INF)
        ans = -1;
    return ans;
}
};

