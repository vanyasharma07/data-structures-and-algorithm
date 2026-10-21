
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        // monotonic increasing stack
        stack<int> st;

        for (int i = 0; i < ast.size(); i++) {
            if (st.empty() || ast[i] > 0 || st.top() < 0) {
                st.push(ast[i]);
            }
            else {
                bool alive = true;

                while (!st.empty() && st.top() > 0 && ast[i] < 0) {
                    if (abs(ast[i]) < abs(st.top())) {
                        alive = false;
                        break;
                    }
                    else if (abs(ast[i]) == abs(st.top())) {
                        st.pop();
                        alive = false;
                        break;
                    }
                    else {
                        st.pop();
                    }
                }

                if (alive) {
                    st.push(ast[i]);
                }
            }
        }

        vector<int> ans(st.size());

        for (int i = (int)st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};
