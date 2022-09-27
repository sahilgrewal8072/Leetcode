class Solution {
    private:
        void SET(int i, char c, vector<int> &arr, int &count, char &prev, string &s){
            if(s[i] == c){
                count = 1;
                prev = c;
            }else if(s[i] != '.'){
                prev = s[i];
            }
            if(prev == c && s[i] == '.'){
                arr[i] = count++;
            }

        }
    
public:
    string pushDominoes(string s) {
        int n = s.length();
        vector<int> left(n, -1);
        vector<int> right(n, -1);
        
        int count = 0;
        char prev = '1';
        for(int i = 0; i<n; i++){
            SET(i, 'R', right, count, prev, s);
        }
        
        count = 0;
        prev = '1';
        for(int i = n-1; i>=0; i--){
            SET(i, 'L', left, count, prev, s);
        }
        
        
        for(int i=0; i<n; i++){
            if(right[i] == -1 && left[i] == -1){
                continue;
            }else if(left[i] == right[i]){
                s[i] = '.';
            }else if(right[i] == -1 && left[i] > 0){
                s[i] = 'L';
            }else if(left[i] == -1 && right[i] > 0){
                s[i] = 'R';
            }else if(left[i] < right[i]){
                s[i] = 'L';
            }else{
                s[i] ='R';
            }
            
        }
        return s;
    }
};