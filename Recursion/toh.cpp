#include<iostream>
using namespace std;
void TOH(int n,char src, char temp , char dest){
    if(n==1){
        cout<<"Move disk - "<<n<<"  from "<<src<<" to  "<<dest<<endl;
        return;

    }
    TOH(n-1,src,dest,temp);
        cout<<"Move disk - "<<n<<"  from "<<src<<" to  "<<dest<<endl;
        TOH(n-1,temp,src,dest);

}
int main(){
    int n;
    cout<<"enter the number of disk: "<<endl;
    cin>>n;
    TOH(n,'A','B','C');
    return 0;
}
