#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*
    stores index represent storeid
    0 -> store1
    1 -> store2
    2 -> store3
    .
    .
    .
    n = storeN
    NOTE : a city cannot have more than 20 darkstore.
    Note : item count in high demand when stock<10;
*/


struct Darkstore{
    unordered_map<string,int>inventory;
};

class city{
    private:
        int Totalstore;
       vector<Darkstore> stores;
       vector<vector<int>>distance;
       
    public:
        city(int n){
            Totalstore = n;
            stores.resize(n);
            distance.resize(0);
            for(int i=0; i<n; i++){
                vector<int>helper(n, 0);
                distance.push_back(helper);
            }
        }
        
        void addInventory(int strid , string product, int quantity) {
            if(strid >= Totalstore && strid < 0) cout<<"Invalide storeID"<<endl;
            stores[strid].inventory[product] = quantity; 
        }

        void addRoad(int from , int to, int wayLength){
            distance[from][to] = wayLength;
            distance[to][from] = wayLength;
        }

        int checkAndRebalance(int strid, int product){
            
            return 0;
        }
};

int main() {
    city c1(4);
    //add items
    c1.addInventory(0,"milk", 20);
    c1.addInventory(0,"bread", 20);
    c1.addInventory(0,"butter", 20);
    c1.addInventory(0,"cake", 20);
    c1.addInventory(1,"milk", 20);
    c1.addInventory(1,"bread", 20);
    c1.addInventory(2,"milk", 5);
    c1.addInventory(2,"cake", 9);
    c1.addInventory(2,"butter", 10);
    c1.addInventory(3,"cake", 3);

    //connect stores
    c1.addRoad(0, 1 , 8);
    c1.addRoad(0, 2, 5);
    c1.addRoad(0, 3, 10);
    c1.addRoad(1,2, 3);
    c1.addRoad(2, 3, 2);

}