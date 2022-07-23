class Solution {
    private:
    int solve(int &n){
        int sum = 0;
        while(n){
            int digit = n%10;
            sum += (digit*digit);
            n /= 10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        // Applying floyd's cycle detection algo
        int slow = n;
        int fast = n;
        do{
            slow = solve(slow);
            fast = solve(fast);
            fast = solve(fast);
        }while(slow != fast);
        if(slow == 1)return true;
        return false;
    }
};