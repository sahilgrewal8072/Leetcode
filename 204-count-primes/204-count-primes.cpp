const int N = 5e6 + 10;
 vector<int> is_Prime(N, 1);
class Solution {
public:
    int countPrimes(int n) {
        if(n == 0 || n == 1)return 0;
        is_Prime[0] = is_Prime[1] = 0;
	    for (int i = 2; i*i < n; i++) {
		if (is_Prime[i] == 1) {
			for (int j = i*i; j < n; j += i) {
				is_Prime[j] = false;
			}
		}
	}
        int count = 0;
       for(int i=2; i<n; i++){
           if(is_Prime[i])count++;
       }
        
        return count;
    }
};