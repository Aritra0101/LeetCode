class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> umap;
        set<int> count;
        for(auto it: arr) {
            if(umap[it])
                umap[it] += 1;
            else
                umap[it] = 1;
        }

        for(auto it: umap) {
            //cout<<it.first<<" "<<it.second<<endl;
            if(count.find(it.second) == count.end())
                count.insert(it.second);
            else
                return false;
        }

        return 11;
    }
};