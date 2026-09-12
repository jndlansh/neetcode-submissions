class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26, 0);
        for(auto it : tasks){
            freq[it-'A']++;
        }

        priority_queue<int>pq;
        for(auto it : freq){
            if(it > 0){
                pq.push(it);
            }
        }
        int time = 0;
        while(!pq.empty()){
            vector<int>temp;
            for(int i=0; i<=n; i++){
                if(!pq.empty()){
                    int f = pq.top();
                    pq.pop();
                    f--;
                    if(f>0){
                        temp.push_back(f);
                    }
                }
                time++;
                if(pq.empty() && temp.empty()){
                    break;
                }
            }
            for(auto it : temp){
                pq.push(it);
            }
        }
        return time;
    }
};
