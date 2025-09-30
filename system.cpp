#include<bits/stdc++.h>

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
        
        bool checkStore(int strid){
            if(strid >= Totalstore || strid < 0) return false;
            return true;
        }
        
        void addInventory(int strid , string product, int quantity) {
            if(!checkStore(strid)) cout<<"Invalide storeID"<<endl;
            stores[strid].inventory[product] = quantity; 
        }

        void addRoad(int from , int to, int wayLength){
            distance[from][to] = wayLength;
            distance[to][from] = wayLength;
        }

        int checkAndRebalance(int strid, string product, int minquantity){
           if(!checkStore(strid)) cout<<"Invalide storeID"<<endl;
            int ans = -1;                           // -1 mean no store found
            int minu = INT_MAX;
            for(int i=0; i<Totalstore; i++) {
                if(i == strid) continue;
                if(stores[i].inventory[product] >= minquantity && distance[strid][i] > 0){
                    if(distance[strid][i] < minu){
                        minu = distance[strid][i];
                        ans = i;
                    }
                }
            }
            return ans;
        }
};

int main() {
    cout<<"📌 Note: Number of store should be less than 20 in a city"<<endl;
    cout<<"Enter Number of stores: ";
    int n;
    cin>>n;
    if(n > 20 || n <= 0)
        cout<<"\n⚠️ Enter valid Number"<<endl;
    city goa(n); 
    
    cout<<"\t\t\t-----------😀 Stores Created-------------"<<endl;
    cout<<"\n\t\t\t\t StoreID"<<"\t\tStore Name"<<endl;
    for(int i=0; i<n; i++){
        cout<<"\n\t\t\t\t\t\t"<<i<<"\t\tStore"<<i<<endl;
    }
    
    while(true) {
        cout<<"👉 Press 1 to add Inventory"<<endl;
        cout<<"👉 Press 2 to Connect Stores"<<endl;
        cout<<"👉 Press 3 to Find Near by Store"<<endl;
        cout<<"👉 Press 0  to Exit"<<endl;
        int choice;
        cin>>choice;
        if(choice > 3 || choice < 0){
            cout<<"⚠️ Invalid choice"<<endl;
            continue;
        }
        if(choice == 0) break;
        if(choice == 1) {
            cout<<"Enter store ID: ";
            int storeid;
            cin>>storeid;
            cout<<"\nEnter Number of Products: ";
            int productcount;
            cin>>productcount;
            while(productcount <= 0) {
                cout<<"\nNumber should be positive"<<endl;
                cout<<"Enter Number of Products: ";
                cin>>productcount;
            }
            
            for(int i=0; i<productcount; i++) {
                cout<<"\nEnter Product Name: ";
                string product;
                cin>>product;
                cout<<"\nEnter Quantity: ";
                int quantity;
                cin>>quantity;
                goa.addInventory(storeid, product, quantity);
            }
        }
        
        if(choice == 2) {
            cout<<"\nEnter first storeID: ";
            int storeid1;
            cin>>storeid1;
            cout<<"\nEnter second storeID: ";
            int storeid2;
            cin>>storeid2;
            cout<<"\nEnter Distance between them ";
            int dist;
            cin>>dist;
            goa.addRoad(storeid1, storeid2 , dist);
        }
        
        if(choice == 3){
             cout<<"\nEnter Your store ID: ";
            int strid;
            cin>>strid;
            cout<<"\nEnter Product Name: ";
            string product;
            cin>>product;
            cout<<"\nEnter Required Quantity: ";
            int quantity;
            cin>>quantity;
            int temp = goa.checkAndRebalance(strid, product, quantity);
            cout<<endl<<temp;
        }
        
    }
    
    /* sample data for test 
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
    
    */

    return 0;
}