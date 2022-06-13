class Robot {
     int w = 0;
    int h = 0;
    int x = 0;
    int y = 0;
    string dir;
public:
   
    Robot(int width, int height) {
        x = 0;
        y = 0;
        w = width;
        h = height;
        dir = "East";
    }
    
    void step(int num) {
        num %= (2*h + 2*w - 4);
        if(num == 0) num = (2*h + 2*w - 4);
        for(int i=0; i<num; i++){
        
                if(dir == "East"){
                    if(x == w-1){
                        dir = "North";
                        y++;
                    }else{
                        x++;
                    }
                }else if(dir == "North"){
                    if(y == h-1){
                        dir = "West";
                        x--;
                    }else{
                        y++;
                    }
                }else if(dir == "West"){
                    if(x == 0){
                        dir = "South";
                        y--;
                    }else{
                        x--;
                    }
                }else if(dir == "South"){
                    if(y == 0){
                        dir = "East";
                        x++;
                    }else{
                        y--;
                    }
                }
        }
    }
    
    vector<int> getPos() {
        return {x,y};
    }
    
    string getDir() {
        return dir;
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */