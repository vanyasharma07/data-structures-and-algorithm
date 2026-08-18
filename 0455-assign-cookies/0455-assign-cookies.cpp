class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int greed = 0;
        int size = 0;

        while (greed < g.size() && size < s.size()) {
                if (s[size] >= g[greed]) {
                greed++;
            }
            size++;
        }

        return greed;
    }
};