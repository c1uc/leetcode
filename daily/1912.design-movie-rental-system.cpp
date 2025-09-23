#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


class MovieRentingSystem {
    map<int, set<pii>> unrented; // movie -> (price, shop)
    set<tuple<int, int, int>> rented; // (price, shop, movie)
    map<pii, int> price; // (movie, shop) -> price

    public:
        MovieRentingSystem(int n, vector<vector<int>>& entries) {
            unrented = map<int, set<pii>>();
            rented = set<tuple<int, int, int>>();
            price = map<pii, int>();
            for(auto& entry : entries) { // shop, movie, price
                unrented[entry[1]].insert({entry[2], entry[0]});
                price[{entry[1], entry[0]}] = entry[2];
            }
        }
        
        vector<int> search(int movie) {
            vector<int> res;
            for(auto& [price, shop] : unrented[movie]) {
                res.push_back(shop);
                if(res.size() == 5) break;
            }
            return res;
        }
        
        void rent(int shop, int movie) {
            auto p = price[{movie, shop}];
            unrented[movie].erase({p, shop});
            rented.insert({p, shop, movie});
        }
        
        void drop(int shop, int movie) {
            auto p = price[{movie, shop}];
            rented.erase({p, shop, movie});
            unrented[movie].insert({p, shop});
        }
        
        vector<vector<int>> report() {
            vector<vector<int>> res;
            for(auto& [p, shop, movie] : rented) {
                res.push_back({shop, movie});
                if(res.size() == 5) break;
            }
            return res;
        }
    };
    
    /**
     * Your MovieRentingSystem object will be instantiated and called as such:
     * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
     * vector<int> param_1 = obj->search(movie);
     * obj->rent(shop,movie);
     * obj->drop(shop,movie);
     * vector<vector<int>> param_4 = obj->report();
     */
