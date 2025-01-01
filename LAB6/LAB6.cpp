#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <limits>
#include <algorithm>

using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> adjMatrix;
    vector<vector<int>> adjList;
    vector<vector<pair<int, int>>> adjListWeighted;
    bool dfsCycleDirectedUtil(int v, vector<bool>& visited, vector<bool>& inRecStack) {
        visited[v] = true;
        inRecStack[v] = true;
        for (int neigh : adjList[v]) {
            if (!visited[neigh] && dfsCycleDirectedUtil(neigh, visited, inRecStack)) return true;
            else if (inRecStack[neigh]) return true;
        }
        inRecStack[v] = false;
        return false;
    }
    bool dfsCycleUndirectedUtil(int v, int parent, vector<bool>& visited) {
        visited[v] = true;
        for (int neigh : adjList[v]) {
            if (!visited[neigh]) {
                if (dfsCycleUndirectedUtil(neigh, v, visited)) return true;
            }
            else if (neigh != parent) {
                return true;
            }
        }
        return false;
    }
    void bridgesDfs(int v, int p, vector<int>& disc, vector<int>& low, vector<bool>& visited, int& time, vector<pair<int, int>>& ans) {
        visited[v] = true;
        disc[v] = low[v] = ++time;
        for (int neigh : adjList[v]) {
            if (!visited[neigh]) {
                bridgesDfs(neigh, v, disc, low, visited, time, ans);
                low[v] = min(low[v], low[neigh]);
                if (low[neigh] > disc[v]) ans.push_back({ v, neigh });
            }
            else if (neigh != p) {
                low[v] = min(low[v], disc[neigh]);
            }
        }
    }
    vector<vector<int>> buildReverseGraph() {
        vector<vector<int>> rev(vertices);
        for (int u = 0; u < vertices; u++) {
            for (int w : adjList[u]) {
                rev[w].push_back(u);
            }
        }
        return rev;
    }
public:
    Graph() : vertices(0) {}
    int getVertexCount() const {
        return vertices;
    }
    void addVertex() {
        vertices++;
        for (auto& row : adjMatrix) row.push_back(0);
        adjMatrix.push_back(vector<int>(vertices, 0));
        adjList.push_back({});
        adjListWeighted.push_back({});
    }
    void addEdgeUndirected(int src, int dest) {
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1;
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }
    void addEdgeDirected(int src, int dest) {
        adjMatrix[src][dest] = 1;
        adjList[src].push_back(dest);
    }
    void addEdgeWeighted(int src, int dest, int weight) {
        adjListWeighted[src].push_back({ dest, weight });
    }
    void printAdjMatrix() {
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) cout << adjMatrix[i][j] << " ";
            cout << "\n";
        }
        cout << "\n";
    }
    void printAdjList() {
        for (int i = 0; i < vertices; i++) {
            cout << i << ": ";
            for (int n : adjList[i]) cout << n << " ";
            cout << "\n";
        }
        cout << "\n";
    }
    void printAdjListWeighted() {
        for (int i = 0; i < vertices; i++) {
            cout << i << ": ";
            for (auto& p : adjListWeighted[i]) cout << "(" << p.first << "," << p.second << ") ";
            cout << "\n";
        }
        cout << "\n";
    }
    vector<int> dfsRecursiveUtil(int v, vector<bool>& visited, vector<int>& res) {
        visited[v] = true;
        res.push_back(v);
        for (int neigh : adjList[v]) {
            if (!visited[neigh]) dfsRecursiveUtil(neigh, visited, res);
        }
        return res;
    }
    vector<int> dfsRecursive(int start) {
        vector<bool> visited(vertices, false);
        vector<int> res;
        dfsRecursiveUtil(start, visited, res);
        return res;
    }
    vector<int> dfsIterative(int start) {
        vector<bool> visited(vertices, false);
        vector<int> res;
        stack<int> st;
        st.push(start);
        while (!st.empty()) {
            int cur = st.top();
            st.pop();
            if (!visited[cur]) {
                visited[cur] = true;
                res.push_back(cur);
                for (auto it = adjList[cur].rbegin(); it != adjList[cur].rend(); it++) {
                    if (!visited[*it]) st.push(*it);
                }
            }
        }
        return res;
    }
    vector<int> bfs(int start) {
        vector<bool> visited(vertices, false);
        vector<int> order;
        queue<int> q;
        visited[start] = true;
        q.push(start);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            order.push_back(cur);
            for (int neigh : adjList[cur]) {
                if (!visited[neigh]) {
                    visited[neigh] = true;
                    q.push(neigh);
                }
            }
        }
        return order;
    }
    bool isCyclicDirected() {
        vector<bool> visited(vertices, false);
        vector<bool> inRecStack(vertices, false);
        for (int i = 0; i < vertices; i++) {
            if (!visited[i]) {
                if (dfsCycleDirectedUtil(i, visited, inRecStack)) return true;
            }
        }
        return false;
    }
    bool isCyclicUndirected() {
        vector<bool> visited(vertices, false);
        for (int i = 0; i < vertices; i++) {
            if (!visited[i]) {
                if (dfsCycleUndirectedUtil(i, -1, visited)) return true;
            }
        }
        return false;
    }
    vector<int> dijkstra(int start) {
        vector<int> dist(vertices, numeric_limits<int>::max());
        dist[start] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0, start));
        while (!pq.empty()) {
            pair<int, int> topElem = pq.top();
            int cdist = topElem.first;
            int u = topElem.second;
            pq.pop();
            if (cdist > dist[u]) continue;
            for (size_t i = 0; i < adjListWeighted[u].size(); i++) {
                int v = adjListWeighted[u][i].first;
                int w = adjListWeighted[u][i].second;
                int ndist = dist[u] + w;
                if (ndist < dist[v]) {
                    dist[v] = ndist;
                    pq.push(make_pair(ndist, v));
                }
            }
        }
        return dist;
    }
    vector<vector<int>> findConnectedComponents() {
        vector<bool> visited(vertices, false);
        vector<vector<int>> components;
        for (int i = 0; i < vertices; i++) {
            if (!visited[i]) {
                vector<int> comp;
                queue<int> q;
                q.push(i);
                visited[i] = true;
                while (!q.empty()) {
                    int cur = q.front();
                    q.pop();
                    comp.push_back(cur);
                    for (int neigh : adjList[cur]) {
                        if (!visited[neigh]) {
                            visited[neigh] = true;
                            q.push(neigh);
                        }
                    }
                }
                components.push_back(comp);
            }
        }
        return components;
    }
    vector<pair<int, int>> findBridges() {
        vector<bool> visited(vertices, false);
        vector<int> disc(vertices, -1), low(vertices, -1);
        vector<pair<int, int>> ans;
        int time = 0;
        for (int i = 0; i < vertices; i++) {
            if (!visited[i]) bridgesDfs(i, -1, disc, low, visited, time, ans);
        }
        return ans;
    }
    vector<vector<int>> detectCommunitiesLouvain() {
        vector<vector<int>> placeholder;
        placeholder.push_back({ 0 });
        return placeholder;
    }
    vector<double> pageRank(int maxIter, double d) {
        vector<vector<int>> rev = buildReverseGraph();
        vector<double> rank(vertices, 1.0 / vertices);
        vector<int> outdeg(vertices, 0);
        for (int u = 0; u < vertices; u++) outdeg[u] = (int)adjList[u].size();
        for (int iter = 0; iter < maxIter; iter++) {
            vector<double> newRank(vertices, (1.0 - d) / vertices);
            for (int v = 0; v < vertices; v++) {
                for (int u : rev[v]) {
                    if (outdeg[u] > 0) newRank[v] += d * (rank[u] / outdeg[u]);
                }
            }
            rank = newRank;
        }
        return rank;
    }
    vector<int> aStar(int start, int goal, const vector<int>& heuristic) {
        vector<int> gCost(vertices, numeric_limits<int>::max());
        vector<int> parent(vertices, -1);
        vector<bool> visited(vertices, false);
        gCost[start] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({ heuristic[start], start });

        while (!pq.empty()) {
            auto topElem = pq.top();
            int currentF = topElem.first;
            int u = topElem.second;
            pq.pop();

            if (u == goal) break;
            if (visited[u]) continue;
            visited[u] = true;

            for (auto& edge : adjListWeighted[u]) {
                int v = edge.first;
                int w = edge.second;
                int tentativeG = gCost[u] + w;
                if (tentativeG < gCost[v]) {
                    gCost[v] = tentativeG;
                    parent[v] = u;
                    int f = gCost[v] + heuristic[v];
                    pq.push({ f, v });
                }
            }
        }

        vector<int> path;
        if (parent[goal] != -1 || start == goal) {
            for (int cur = goal; cur != -1; cur = parent[cur]) {
                path.push_back(cur);
            }
            reverse(path.begin(), path.end());
        }
        return path;
    }

    vector<int> degreeCentrality() {
        vector<int> degree(vertices, 0);
        for (int i = 0; i < vertices; i++) {
            degree[i] = (int)adjList[i].size();
        }
        return degree;
    }

};

int main() {
    int exerciseNumber;
    cin >> exerciseNumber;

    switch (exerciseNumber) {
    case 1: {
        Graph g;
        for (int i = 0; i < 5; i++) g.addVertex();
        g.addEdgeUndirected(0, 1);
        g.addEdgeUndirected(0, 2);
        g.addEdgeUndirected(1, 3);
        g.addEdgeUndirected(2, 3);
        g.addEdgeUndirected(3, 4);
        g.printAdjMatrix();
        g.printAdjList();
        break;
    }
    case 2: {
        Graph g;
        for (int i = 0; i < 6; i++) g.addVertex();
        g.addEdgeUndirected(0, 1);
        g.addEdgeUndirected(0, 2);
        g.addEdgeUndirected(1, 3);
        g.addEdgeUndirected(2, 4);
        g.addEdgeUndirected(3, 5);
        g.addEdgeUndirected(4, 5);
        g.printAdjList();
        vector<int> dfsRec = g.dfsRecursive(0);
        for (int v : dfsRec) cout << v << " ";
        cout << "\n";
        vector<int> dfsIter = g.dfsIterative(0);
        for (int v : dfsIter) cout << v << " ";
        cout << "\n";
        break;
    }
    case 3: {
        Graph g;
        for (int i = 0; i < 5; i++) g.addVertex();
        g.addEdgeUndirected(0, 1);
        g.addEdgeUndirected(0, 2);
        g.addEdgeUndirected(1, 3);
        g.addEdgeUndirected(2, 3);
        g.addEdgeUndirected(3, 4);
        g.printAdjList();
        vector<int> bfsOrder = g.bfs(0);
        for (int v : bfsOrder) cout << v << " ";
        cout << "\n";
        break;
    }
    case 4: {
        Graph g;
        for (int i = 0; i < 4; i++) g.addVertex();
        g.addEdgeDirected(0, 1);
        g.addEdgeDirected(1, 2);
        g.addEdgeDirected(2, 0);
        g.addEdgeUndirected(2, 3);
        cout << g.isCyclicDirected() << "\n";
        cout << g.isCyclicUndirected() << "\n";
        break;
    }
    case 5: {
        Graph g;
        for (int i = 0; i < 5; i++) g.addVertex();
        g.addEdgeWeighted(0, 1, 2);
        g.addEdgeWeighted(0, 2, 4);
        g.addEdgeWeighted(1, 2, 1);
        g.addEdgeWeighted(1, 3, 7);
        g.addEdgeWeighted(2, 4, 3);
        g.printAdjListWeighted();
        vector<int> dist = g.dijkstra(0);
        for (int d : dist) cout << d << " ";
        cout << "\n";
        break;
    }
    case 6: {
        Graph g;
        for (int i = 0; i < 6; i++) g.addVertex();
        g.addEdgeUndirected(0, 1);
        g.addEdgeUndirected(2, 3);
        g.addEdgeUndirected(2, 4);
        g.addEdgeUndirected(5, 5);
        vector<vector<int>> comps = g.findConnectedComponents();
        for (auto& comp : comps) {
            for (int v : comp) cout << v << " ";
            cout << "\n";
        }
        break;
    }
    case 7: {
        Graph g;
        for (int i = 0; i < 5; i++) g.addVertex();
        g.addEdgeUndirected(0, 1);
        g.addEdgeUndirected(1, 2);
        g.addEdgeUndirected(2, 3);
        g.addEdgeUndirected(2, 4);
        vector<pair<int, int>> bridges = g.findBridges();
        for (auto& b : bridges) cout << b.first << "-" << b.second << "\n";
        break;
    }
    case 8: {
        Graph g;
        for (int i = 0; i < 4; i++) g.addVertex();
        g.addEdgeUndirected(0, 1);
        g.addEdgeUndirected(2, 3);
        vector<vector<int>> c = g.detectCommunitiesLouvain();
        for (auto& comp : c) {
            for (int v : comp) cout << v << " ";
            cout << "\n";
        }
        break;
    }
    case 9: {
        Graph g;
        for (int i = 0; i < 4; i++) g.addVertex();
        g.addEdgeDirected(0, 1);
        g.addEdgeDirected(0, 2);
        g.addEdgeDirected(1, 2);
        g.addEdgeDirected(2, 0);
        g.addEdgeDirected(2, 3);
        vector<double> pr = g.pageRank(10, 0.85);
        for (double r : pr) cout << r << " ";
        cout << "\n";
        break;
    }
    case 10: {
        Graph g;
        for (int i = 0; i < 5; i++) g.addVertex();
        g.addEdgeWeighted(0, 1, 2);
        g.addEdgeWeighted(0, 2, 4);
        g.addEdgeWeighted(1, 2, 1);
        g.addEdgeWeighted(1, 3, 7);
        g.addEdgeWeighted(2, 4, 3);
        g.printAdjListWeighted();

        vector<int> dist = g.dijkstra(0);
        for (int i = 0; i < (int)dist.size(); i++) {
            cout << "Distance from 0 to " << i << " = " << dist[i] << "\n";
        }
        break;
    }
    case 11: {
        Graph g;
        for (int i = 0; i < 5; i++) g.addVertex();
        g.addEdgeWeighted(0, 1, 2);
        g.addEdgeWeighted(0, 2, 4);
        g.addEdgeWeighted(1, 2, 1);
        g.addEdgeWeighted(1, 3, 7);
        g.addEdgeWeighted(2, 4, 3);

        vector<int> heuristic = { 7, 6, 2, 1, 0 };
        vector<int> route = g.aStar(0, 4, heuristic);

        cout << "Route from 0 to 4 (A*): ";
        for (int r : route) cout << r << " ";
        cout << "\n";
        break;
    }
    case 12: {
        Graph g;
        for (int i = 0; i < 6; i++) g.addVertex();
        g.addEdgeUndirected(0, 1);
        g.addEdgeUndirected(0, 2);
        g.addEdgeUndirected(2, 3);
        g.addEdgeUndirected(2, 4);
        g.addEdgeUndirected(4, 5);

        vector<int> deg = g.degreeCentrality();
        cout << "Degree Centrality:\n";
        for (int i = 0; i < (int)deg.size(); i++) {
            cout << "User " << i << ": " << deg[i] << "\n";
        }

        vector<vector<int>> communities = g.detectCommunitiesLouvain();
        cout << "Detected communities (placeholder):\n";
        for (auto& c : communities) {
            for (int u : c) cout << u << " ";
            cout << "\n";
        }
        break;
    }
    case 13: {
        Graph g;
        for (int i = 0; i < 6; i++) g.addVertex();
        g.addEdgeWeighted(0, 1, 2);
        g.addEdgeWeighted(1, 2, 5);
        g.addEdgeWeighted(2, 3, 2);
        g.addEdgeWeighted(2, 4, 10);
        g.addEdgeWeighted(3, 5, 3);
        vector<int> dist = g.dijkstra(0);
        for (int i = 0; i < (int)dist.size(); i++) {
            cout << "Distance from 0 to " << i << " = " << dist[i] << "\n";
        }
        break;
    }
    case 14: {
        Graph g;
        for (int i = 0; i < 5; i++) g.addVertex();
        g.addEdgeUndirected(0, 1);
        g.addEdgeUndirected(0, 2);
        g.addEdgeUndirected(1, 2);
        g.addEdgeUndirected(1, 3);
        g.addEdgeUndirected(2, 4);
        vector<vector<int>> comps = g.findConnectedComponents();
        for (auto& c : comps) {
            for (int v : c) cout << v << " ";
            cout << "\n";
        }
        break;
    }

    case 15: {
        Graph g;
        for (int i = 0; i < 6; i++) g.addVertex();
        g.addEdgeUndirected(0, 1);
        g.addEdgeUndirected(1, 2);
        g.addEdgeUndirected(2, 3);
        g.addEdgeUndirected(2, 4);
        g.addEdgeUndirected(4, 5);
        vector<pair<int, int>> bridges = g.findBridges();
        for (auto& b : bridges) cout << b.first << "-" << b.second << "\n";
        break;
    }
    case 16: {
        Graph g;
        for (int i = 0; i < 9; i++) g.addVertex();
        g.addEdgeWeighted(0, 1, 1);
        g.addEdgeWeighted(0, 3, 1);
        g.addEdgeWeighted(1, 2, 1);
        g.addEdgeWeighted(1, 4, 1);
        g.addEdgeWeighted(2, 5, 1);
        g.addEdgeWeighted(3, 4, 1);
        g.addEdgeWeighted(3, 6, 1);
        g.addEdgeWeighted(4, 5, 1);
        g.addEdgeWeighted(4, 7, 1);
        g.addEdgeWeighted(5, 8, 1);
        g.addEdgeWeighted(6, 7, 1);
        g.addEdgeWeighted(7, 8, 1);
        vector<int> heuristic(9, 0);
        vector<int> path = g.aStar(0, 8, heuristic);
        for (int p : path) cout << p << " ";
        cout << "\n";
        break;
    }
    default:
        break;
    }
    return 0;
}
