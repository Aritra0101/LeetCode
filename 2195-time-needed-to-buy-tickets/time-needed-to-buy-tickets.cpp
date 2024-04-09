class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {

        int i=-1, count=0, n=tickets.size();
        while(tickets[k] != 0) {
            i = (i+1) %n;
            if(tickets[i] != 0) {
                count++;
                tickets[i] -= 1;
            }
        }

        return count;
        
    }
};