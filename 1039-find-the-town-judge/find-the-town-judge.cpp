class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1) { return true; }

        int *tt = (int*) calloc(n+1, sizeof(int));
        int *ttt = (int*) calloc(n+1, sizeof(int));

        for(int i=0; i<trust.size(); i++) {
            // tt[trust[i][1]]++;
            // ttt[trust[i][0]]++;

            tt[trust[i][1]] = tt[trust[i][1]] + 1;
            ttt[trust[i][0]] = ttt[trust[i][0]] + 1;
        }

        for(int i=0; i<n+1; i++) {
            if(tt[i] == n-1 && ttt[i] == 0) {
                return i;
            }
        } 

        return -1;  
    }
};