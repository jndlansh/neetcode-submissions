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
                int num = pq.top();
                pq.pop();

                num--;
                if(num > 0){
                    temp.push_back(num);
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
