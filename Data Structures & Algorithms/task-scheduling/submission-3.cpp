class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26, 0);
        for(auto it : tasks){
            freq[it-'A']++;
        }
        priority_queue<int>pq;
        for(auto f : freq){
            if(f>0){
                pq.push(f);
            }
        }
        int time = 0;
        while(!pq.empty()){
            vector<int>temp;
            for(int i=0; i<=n; i++){
                if(!pq.empty()){
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                    if(freq>0){
                        temp.push_back(freq);
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
