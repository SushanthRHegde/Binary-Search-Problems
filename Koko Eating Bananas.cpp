class Solution {
public:
    bool canEatAll(vector<int>& piles, int givenHour, int h){
        int actualhour = 0;
        for(int &x: piles){
            actualhour += x /givenHour;
            if(x%givenHour != 0){
                actualhour++;
            }
        }
        return actualhour <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(),piles.end());

        while( l < r){
            int mid = l + ( r - l) /2;
            //per hour koko can eat mid no of banana
            if(canEatAll(piles,mid,h)){
                //if its true --> no need to go more ( we need min )
                r = mid;
            }
            //otherwise we should increase low
            else l = mid +1 ;
        }
        return l;
    }
};
