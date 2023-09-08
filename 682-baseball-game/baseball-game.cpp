class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> scores;
        for(auto it: operations) {
            if(it == "+") {
                int n1 = scores.top();
                scores.pop();
                int n2 = scores.top();
                scores.pop();
                scores.push(n2);
                scores.push(n1);
                scores.push(n1+n2);
            } else if(it == "D") {
                scores.push(2 * scores.top());
            } else if(it == "C") {
                scores.pop();
            } else {
                scores.push( stoi(it) );
            }
        }

        int ans = 0;
        while(!scores.empty()) {
            ans += scores.top();
            scores.pop();
        }
        return ans;
    }
};