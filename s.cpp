#include<bits/stdc++.h>
using namespace std;
class rectangle{
    private:
        int length;
        int breadth;
    public:
        rectangle(int l, int b){
            length = l;
            breadth = b;
        }
        rectangle(int s){
            length = breadth = s;
        }
        int getl(){
            return length;
        }
        int getb(){
            return breadth;
        }
        void setl(int l){
            length = l;
        }
        void setb(int b){
            breadth = b;
        }
        int area(){
            return length*breadth;
        }
        int peri(){
            return 2*(length+breadth);
        }
};
