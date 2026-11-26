class Solution {
public:
    bool canAliceWin(int n) {
        bool turn=true;
        int remove=10;
        while(n>0){
            //alice turn
            if(turn==true){
                if(remove>n){
                    return false;
                }
                
            }else{
                if(remove>n){
                    return true;
                }
            }
            n-=remove;
            remove--;
            turn=!turn;
        }
        return !turn;
    }
};