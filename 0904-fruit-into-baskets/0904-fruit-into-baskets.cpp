
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> freq;
        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < fruits.size(); right++) {
            freq[fruits[right]]++;

            while (freq.size() > 2) {
                int outgoing = fruits[left];
                freq[outgoing]--;

                if (freq[outgoing] == 0) {
                    freq.erase(outgoing);
                }

                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
