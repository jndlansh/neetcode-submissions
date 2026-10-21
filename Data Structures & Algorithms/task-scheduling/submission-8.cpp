class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26, 0);
        for(auto it : tasks) {
            freq[it-'A']++;
        }

        priority_queue<int>pq;
        for(auto f : freq) {
            if(f > 0) {
                pq.push(f);
            }
        }

        int intervals = 0;

        while(!pq.empty()) {
            vector<int>temp;
            for(int i=0; i<=n; i++) {
                if(!pq.empty()) {
                    int x = pq.top();
                    pq.pop();
                    x--;
                    if(x>0) {
                        temp.push_back(x);
                    }
                }
                intervals++;
                if(pq.empty() && temp.empty()) {
                    break;
                }
            }
            for(int i=0; i<temp.size(); i++) {
                pq.push(temp[i]);
            }
        }
        return intervals;
    }
};
