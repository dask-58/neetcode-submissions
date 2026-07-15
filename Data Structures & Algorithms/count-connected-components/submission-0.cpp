class DSU {
private:
    vector<int> par, sz;
public:
    DSU(int n) {
        par.resize(n);
        sz.resize(n, 1);
        iota(par.begin(), par.end(), 0);
    }

    int find(int i) {
        if (par[i] == i) return par[i];
        return par[i] = find(par[i]);
    }

    bool unite(int i, int j) {
        int ri = find(i);
        int rj = find(j);
        if (ri == rj) return false;
        if (sz[ri] < sz[rj]) {
            swap(ri, rj);
        }
        par[rj] = ri;
        sz[ri] += sz[rj];
        return true;
    }
};
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        int ans = n;
        for (auto e : edges) {
            if (dsu.unite(e[0], e[1])) ans--;
        }
        return ans;
    }
};
