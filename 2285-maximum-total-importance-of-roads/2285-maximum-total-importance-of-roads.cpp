class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        
        vector<int> outdegree(n, 0);
        int count = 1;
        long long sum = 0;
        for(auto &it : roads){
            outdegree[it[0]]++;
            outdegree[it[1]]++;
        }
        
        sort(outdegree.begin(), outdegree.end());
        for(auto it : outdegree){
            sum += 1ll*(it)*(count++);
        }
        return sum;
    }
};