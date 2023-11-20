class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int Tm=-1, Tp=-1, Tg=-1;
        int ans = 0;

        for(int i=0; i<garbage.size(); i++) {
            for(int j=0; j<garbage[i].size(); j++) {
                if(garbage[i][j]=='M')
                    Tm= i;

                if(garbage[i][j]=='P')
                    Tp= i;

                if(garbage[i][j]=='G')
                    Tg= i;
            }
            ans += garbage[i].size();
        }

        for(int i=1; i<travel.size(); i++) {
            travel[i] += travel[i-1];
        }

        if(Tm-1>=0) ans+=travel[Tm-1];
        if(Tp-1>=0) ans+=travel[Tp-1];
        if(Tg-1>=0) ans+=travel[Tg-1];

        cout<<"\nM -> "<<Tm;
        cout<<"\nP -> "<<Tp;
        cout<<"\nG -> "<<Tg;


        return ans;
    }
};