#include <bits/stdc++.h>
using namespace std;


class FoodRatings {
    public:
        unordered_map<string, int> rating;
        unordered_map<string, string> cuisine;
        using pis = pair<int, string>;
        unordered_map<string, priority_queue<pis, vector<pis>, greater<pis>>> pq;

        FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
            for(int i = 0; i < foods.size(); i++) {
                rating[foods[i]] = ratings[i];
                cuisine[foods[i]] = cuisines[i];
                if(pq.find(cuisines[i]) == pq.end()) {
                    pq[cuisines[i]] = priority_queue<pis, vector<pis>, greater<pis>>();
                }
                pq[cuisines[i]].push({-ratings[i], foods[i]});
            }
        }
        
        void changeRating(string food, int newRating) {
            rating[food] = newRating;
            pq[cuisine[food]].push({-newRating, food});
        }
        
        string highestRated(string cuisine) {
            while(!pq[cuisine].empty()) {
                auto [r, food] = pq[cuisine].top();
                if(rating[food] == -r) {
                    return food;
                }
                pq[cuisine].pop();
            }
            return "";
        }
    };
    
    /**
     * Your FoodRatings object will be instantiated and called as such:
     * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
     * obj->changeRating(food,newRating);
     * string param_2 = obj->highestRated(cuisine);
     */
