class Solution {
public:
       unordered_map<int, int> parent;

    // Function to find the ultimate parent of node x
    int find(int x) {
        // If x is not present, make it its own parent
        if (parent.find(x) == parent.end())
            parent[x] = x;

        // Path compression to optimize future finds
        if (x != parent[x])
            parent[x] = find(parent[x]);

        return parent[x];
    }

    // Function to connect two nodes
    void unite(int x, int y) {
        // Set parent of x's root to y's root
        parent[find(x)] = find(y);
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        for(auto ed: stones){
            int u=ed[0];
            int v=ed[1];
            unite(u,v+10001);
        }

        unordered_set<int> components;

        // Count unique connected components
        for (auto& stone : stones) {
            components.insert(find(stone[0]));
        }

        // Max stones removed = total stones - number of components
        return stones.size() - components.size();
    }
};