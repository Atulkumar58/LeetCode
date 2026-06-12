class Solution {
public:
    vector<vector<int>> adj;
    vector<vector<int>> up; // up[i][j] stores the (2^j)-th ancestor of node i
    vector<int> depth;
    int LOG;

    // Safe iterative BFS to prevent stack overflow on deep trees
    void build_tree(int root, int n) {
        queue<int> q;
        q.push(root);
        depth[root] = 0;
        up[root][0] = root; // Root's parent points to itself

        vector<bool> visited(n + 1, false);
        visited[root] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int neighbor : adj[curr]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    depth[neighbor] = depth[curr] + 1;
                    up[neighbor][0] = curr; // 2^0 ancestor is the direct parent
                    q.push(neighbor);
                }
            }
        }
    }

    // O(log N) LCA finding via Binary Lifting
    int get_lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        // 1. Lift 'u' up to the same depth as 'v'
        for (int j = LOG - 1; j >= 0; j--) {
            if (depth[u] - (1 << j) >= depth[v]) {
                u = up[u][j];
            }
        }

        if (u == v) return u;

        // 2. Lift both nodes simultaneously right below their common ancestor
        for (int j = LOG - 1; j >= 0; j--) {
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }

        // Return their direct parent
        return up[u][0];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1; // Number of nodes is edges + 1 in a tree
        adj.assign(n + 1, vector<int>());
        
        for (auto& i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        // Determine maximum jump size required (log2(N))
        LOG = 0;
        while ((1 << LOG) <= n) LOG++;

        up.assign(n + 1, vector<int>(LOG));
        depth.assign(n + 1, 0);

        // Preprocess tree layers securely
        build_tree(1, n);

        // Compute the rest of the binary lifting table
        for (int j = 1; j < LOG; j++) {
            for (int i = 1; i <= n; i++) {
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }

        // Precompute powers of 2
        vector<int> power(n + 1);
        const int mod = 1e9 + 7;
        int p = 1;
        for (int i = 0; i <= n; i++) {
            power[i] = p;
            p = (p << 1) % mod;
        }

        vector<int> ans;
        for (int i = 0; i < queries.size(); i++) {
            int x = queries[i][0], y = queries[i][1];
            
            if (x == y) {
                ans.push_back(0);
                continue;
            }

            int z = get_lca(x, y);
            int edge_count = depth[x] + depth[y] - depth[z] * 2;

            ans.push_back(power[edge_count - 1]);
        }

        return ans;
    }
};