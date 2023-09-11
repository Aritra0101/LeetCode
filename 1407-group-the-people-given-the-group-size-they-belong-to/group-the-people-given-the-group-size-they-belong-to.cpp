class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();

        vector<vector<int>> hashMap(n+1);
        for(int i=0; i<n; i++) {
            hashMap[ groupSizes[i] ].emplace_back(i);
        }

        for(int i=0; i<=n; i++) {
            cout<<i<<" -> ";
            int nn = hashMap[i].size();
            for(int j=0; j<nn; j++)
                cout<<hashMap[i][j]<<" ";
            cout<<endl;
        }

        vector<vector<int>> res;
        vector<int> temp;
        for(int i=0; i<=n; i++) {
            int nn = hashMap[i].size();
            if(nn==0)
                continue;

            for(int j=0; j<nn; j+=i) {
                temp = vector<int>(hashMap[i].begin()+j, hashMap[i].begin()+j+i);
                res.emplace_back(temp);
            }
        }

        return res;
    }
};