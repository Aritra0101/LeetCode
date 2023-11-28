class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count[2] = {0};
        stack<int> st;

        for(int n: students) {
            count[n]++;
        }
        for (auto it = sandwiches.rbegin(); it != sandwiches.rend(); it++) {
            st.push(*it);
        }

        // while(!st.empty()) {
        //     cout<<st.top()<<endl;
        //     st.pop();
        // }

        while(!st.empty() && count[st.top()] != 0) {
            int top = st.top();
            st.pop();
            count[top]--;
        }

        // return 11;
        return count[0]+count[1];
    }
};