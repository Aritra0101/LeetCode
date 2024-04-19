class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        if(source == destination) {
            return true;
        }

        vector<vector<int>> adjList(n);
        for(auto it: edges) {
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }

        vector<bool> isVisited(n, false);
        stack<int> st;

        st.push(source);

        while(!st.empty()) {
            int top = st.top();
            st.pop();
            isVisited[top] = true;

            for(int n: adjList[top]) {
                if(n == destination) {
                    return true;
                }

                if(!isVisited[n]) {
                    st.push(n);
                }
            } 
        }

        return false;
    }
};