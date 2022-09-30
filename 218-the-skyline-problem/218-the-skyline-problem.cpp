class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> result;
        // store the first, third and second,third index in a vector of pair those represent starting and ending points of a building.
        vector<pair<int , int>> vec;
        
        //efficiently storing in a same vector.
        for( auto x : buildings){
            vec.push_back({x[0] , -x[2]});
            vec.push_back({x[1], x[2]});
        }
        
        sort(vec.begin() , vec.end());
        multiset<int, greater<int>> st;
        st.insert(0);
        int building_height = 0;
        
        for( auto x : vec){
            int x_value = x.first;
            int h_value = x.second;
            if(h_value < 0){ st.insert(-h_value);}
            else { st.erase(st.find(h_value));}
            int top = *st.begin();
            if(building_height != top){
                building_height = top;
                result.push_back({x_value , top});
            }
        }
        return result;
    }
};