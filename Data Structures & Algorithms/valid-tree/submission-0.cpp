class DSU {
private:
    vector<int> parent, sz;
public:
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        sz.resize(n, 1);
    }

    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    bool unite(int i, int j) {
        int ri = find(i);
        int rj = find(j);
        if (ri == rj) return false;
        if (sz[ri] < sz[rj]) swap(ri, rj);
        parent[rj] = ri;
        sz[ri] += sz[rj];
        return true;
    }
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() > n - 1) return false;
        DSU dsu(n);
        int ans = n;
        for (auto e : edges) {
            if (!dsu.unite(e[0], e[1])) {
                return false;
            } else {
                ans--;
            }
        }
        return ans == 1;
    }
};
