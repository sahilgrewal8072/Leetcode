class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int n = s.length();
        int left = 0;
        int right = 0;
        int count = 0;
        string curr = "";
        while(right < k){
            curr += s[right++];
        }
        
        int x = stoi(curr);
        if(num%x == 0){
            count++;
        }
        // cout<<curr<<endl;
        for(right; right < n; right++){
            // cout<<left<<" "<<right<<endl;
            curr += s[right];
            
            curr.erase(0, 1);
            // cout<<curr<<endl;
            left++;
            x = stoi(curr);
            if(x != 0 && num%x == 0)count++;
        }
        
        return count;
    }
};