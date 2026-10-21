
class Solution {
public:
    vector<int> previousGreater(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] <= nums[i])
                st.pop();

            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> nextGreater(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] < nums[i])
                st.pop();

            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> previousSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i])
                st.pop();

            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> nextSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] > nums[i])
                st.pop();

            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }

    long long sumSubarrayMaximums(vector<int>& nums) {
        int n = nums.size();
        vector<int> left = previousGreater(nums);
        vector<int> right = nextGreater(nums);

        long long sum = 0;

        for (int i = 0; i < n; i++) {
            long long l = i - left[i];
            long long r = right[i] - i;

            sum += 1LL * nums[i] * l * r;
        }

        return sum;
    }

    long long sumSubarrayMinimums(vector<int>& nums) {
        int n = nums.size();
        vector<int> left = previousSmaller(nums);
        vector<int> right = nextSmaller(nums);

        long long sum = 0;

        for (int i = 0; i < n; i++) {
            long long l = i - left[i];
            long long r = right[i] - i;

            sum += 1LL * nums[i] * l * r;
        }

        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaximums(nums)
             - sumSubarrayMinimums(nums);
    }
};
