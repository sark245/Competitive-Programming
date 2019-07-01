//
// Created by sark2 on 27-06-2019.
//

#include "bits/stdc++.h"

using namespace std;
#define IOS cin.sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define rep(i, n)    for(int i = 1; i <= (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define cases int t;cin>>t;while(t--)
typedef long double ld;

template <class k, class v>
class MyHashMap{

private:
    int n;
    int N;

   struct Hashnode{
       k key;
       v val;
       Hashnode(){}
       Hashnode(k key, v val) : key(key), val(val){}
   };

    list<Hashnode> *buckets;

   int getBucketIndex(k key){

       int hc = hash<k>()(key);
       hc = abs(hc);
       return hc%N;

   }

    typename list<Hashnode>::iterator getDataIndex(int bi, k key){

       for(auto it = buckets[bi].begin(); it != buckets[bi].end(); ++it){
           if(it->key == key){
               return it;
           }
       }
        return buckets[bi].end();
   }

public:
   // typedef blRawIterator< MyHashMap > iterator;

    MyHashMap(){
       this->n = 0;
       this->N = 4;
       buckets = new list<Hashnode> [N];
   }

   v&operator [] (const k& key){
       int bi = getBucketIndex(key);
       auto itr = getDataIndex(bi,key);

       if(itr == buckets[bi].end()){

           Hashnode nn(key,v());
           buckets[bi].push_back(nn);
           n++;

           double lambda  = n*1.0 / N;
           if(lambda > 2.0){
               rehash();
               bi = getBucketIndex(key);
               itr = getDataIndex(bi,key);

           }

               return buckets[bi].back().val;
       }
       else{
           return itr->val;
       }
   }

   void rehash(){

       int oldN = N;
       list<Hashnode> *store = buckets;
       N = 2*N;
       buckets = new list<Hashnode> [N];
       n = 0;

       for(int bi = 0; bi < oldN; bi++){
           for(auto  di = store[bi].begin(); di != store[bi].end(); di++){
               (*this)[di->key] = di->val;
           }
       }
       delete[] store;

    }
   int size(){
       return  n;
   }

   void display(){
       cout<<"*******************************************"<<endl;
       for(int bi = 0; bi < N; bi++){
           cout<<bi<<" : ";
           for(auto i : buckets[bi]){
               cout<<"[ "<<i.key<<" "<<i.val<<" ] ";
           }
           cout<<endl;

       }
       cout<<"*********************************************"<<endl;
   }
   void erase(k key){
       int bi = getBucketIndex(key);
       auto itr = getDataIndex(bi,key);

       if(itr != buckets[bi].end()){
           buckets[bi].erase(itr);
       }

   }

   int count(k key){
       int bi = getBucketIndex(key);
       auto itr = getDataIndex(bi,key);
       if(itr == buckets[bi].end()){
           return 0;
       }
       else{
           return 1;
       }
   }

};

/*
template <typename blDataType>
class blRawIterator : public iterator forward_access_iterator_tag,
                                                        blDataType,
                                                        ptrdiff_t,
                                                        blDataType*,
                                                        blDataType&>
{
public :
    blRawIterator(blDataType* ptr = nullptr){m_ptr = ptr;}


protected:
    blDataType* m_ptr;
};


*/
struct Point{
    int x;
    int y;

    //Point(){}
    Point(int x, int y) : x(x), y(y){}
    bool operator==(const Point& p) const{
        return (this->x == p.x && this->y == p.y);
    }


};

 ostream& operator<<(ostream& out, const Point& p){
    out<<"{"<<p.x<<", "<<p.y<<"}";
    return out;
}

namespace std {
     template template<>
    struct hash<Point> {

    public:

        size_t operator()(const Point &p) const {
            return hash<int>()(p.x) ^ hash<int>()(p.y);
        }


    };
}






int main() {
    IOS

   /* MyHashMap<string,int> map;

    map["india"] = 100;
    map["pak"] = 80;

    cout<<map.count("india")<<" "<<map.count("pak")<<endl;
    cout<<map["india"];
    map["india"] = 200;
    cout<<map["india"];

    map["aus"] = 60;
    map["utopia"] = 150;
    map["usa"] = 20;
    map["afghanistan"] = 75;
    map["nepal"] = 50;
    map["uk"] = 30;
    map["bhutan"] = 300;
    map["iran"] = 50;
    map["dubai"] = 1000;*/


   MyHashMap<Point,int>map;
  /*  map[Point(1,2)] = 1;
    map[Point(1,3)] = 2;
    map[Point(1,4)] = 3;
    map[Point(1,5)] = 4;
    map[Point(1,6)] = 5;
    cout<<Point(1,1);
    map[Point(1,1)] = 0;
    map[Point(1,7)] = 6;
    map[Point(1,8)] = 7;
    map[Point(1,9)] = 9;

    map.display();*/






}
