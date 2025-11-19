class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int curr = bits[0];
        bool valid = bits[0] ? false : true;
        int n = bits.size();
        for(int i = 1; i < n-1; i++){
            if(valid){
                if(bits[i]){
                    valid = false;
                    curr = 1;
                } else {
                    curr = 0;
                }
            } else {
                if(bits[i]){
                    valid = true;
                    curr = 1;
                } else {
                    valid = true;
                    curr = 0;
                }
            }
        }

        if(valid) return true; else return false;
    }
};