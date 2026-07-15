class Solution {
private:
    vector<int> par, sz;
    int find(int i) {
        if (par[i] == i) return i;
        return par[i] = find(par[i]);
    }
    bool unite(int i, int j) {
        int ri = find(i);
        int rj = find(j);
        if (ri == rj) return false;
        if (sz[ri] < sz[rj]) swap(ri, rj);
        par[rj] = ri;
        sz[ri] += sz[rj];
        return true;
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        par.resize(n);
        sz.resize(n, 1);
        iota(par.begin(), par.end(), 0);
        int ans = n;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    if (unite(i, j)) ans--;
                }
            }
        }
        return ans;
    }
};