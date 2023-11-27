
class Dijkstra {

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

// Dynamically allocating an array of vectors 
// where 'adj' is holdin the address of the first index of the array.
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
};
