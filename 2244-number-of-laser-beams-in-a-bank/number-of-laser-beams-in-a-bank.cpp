class Solution {
public:
    int numberOfBeams(vector<string>& bank) {

        vector<int> cam;
        for(auto row: bank) {
            int camCount = 0;
            for(int c: row) {
                if(c == '1') camCount++;
            }
            if(camCount) {
                cam.emplace_back(camCount);
            }
        }

        int nn = cam.size();
        if(nn==0 || nn==1) {
            return 0;
        }

        int res = 0;
        for(int i=1; i<nn; i++) {
            res += (cam[i-1]*cam[i]);
        }
        return res;
    }
};