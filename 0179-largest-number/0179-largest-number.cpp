
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;

        for (int x : nums) {
            arr.push_back(to_string(x));
        }

        sort(arr.begin(), arr.end(),
             [](const string& a, const string& b) {
                 return a + b > b + a;
             });

        if (arr[0] == "0") return "0";

        string ans;
        for (const string& s : arr) {
            ans += s;
        }

        return ans;
    }
};
