class Solution {
    public String frequencySort(String s) {
        int n = s.length();
        int[] freq = new int[256];
        
        for(int i = 0; i<n; i++){
            freq[(int)s.charAt(i)]++;
        }
        
        
        int x = 0;
        String ans = "";
        while(x < n){
            int mx = 0;
            int index = -1;
            for(int i = 0; i<256; i++){
                if(freq[i] > mx){
                    mx = freq[i];
                    index = i;
                }
            }
            
            if(mx == 0){
                break;
            }
            
            while(freq[index] > 0){
                freq[index]--;
                ans += (char)index;
            }
        }
        return ans;
    }
}