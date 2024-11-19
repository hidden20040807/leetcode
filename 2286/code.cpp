#include<bits\stdc++.h>
using namespace std;
class BookMyShow {
    public:
    
    vector<int>min;
    vector<long long >sum;
    int m;
    int n;
    void modify(int k,int x,int y,int i,int value){
        if(x==y){
            if(x==i){
                min[k]=value;
                sum[k]=value;
            }
            return;
        }
        int mid=(x+y)>>1;
        if(i<=mid)
            modify(2*k,x,mid,i,value);
        else
            modify(2*k+1,mid+1,y,i,value);
        min[k]=std::min(min[2*k],min[2*k+1]);
        sum[k]=sum[2*k]+sum[2*k+1];
    }
    int getfirst(int k,int x,int y,int value){
        if(x==y){
            if(min[k]<=value)
            return x;
            return n;
        }
        int mid=(x+y)>>1;
        if(min[2*k]<=value)
        return getfirst(2*k,x,mid,value);
        else
        return getfirst(2*k+1,mid+1,y,value);
    }
    long long getsum(int k,int x,int y,int i,int j){
        if(x==i&&y==j){
            return sum[k];
        }
        int mid=(x+y)>>1;
        if(j<=mid){
            return getsum(2*k,x,mid,i,j);
        }
        else if(i>mid){
            return getsum(2*k+1,mid+1,y,i,j);
        }
        else
        return getsum(2*k,x,mid,i,mid)+getsum(2*k+1,mid+1,y,mid+1,j);
    }


     BookMyShow(int n, int m): n(n), m(m), min(4 * n), sum(4 * n) {
    }
    
    vector<int> gather(int k, int maxRow) {
           int row=getfirst(1,0,n-1,m-k);
           if(row>maxRow)
           return {};
           int sum=getsum(1,0,n-1,row,row);
           modify(1,0,n-1,row,k+sum);
           return {row,sum};
    }
    
    bool scatter(int k, int maxRow) {
             long long  sum=getsum(1,0,n-1,0,maxRow);
            if((long long)(maxRow+1)*m-sum<k)
            return false;
            int i=getfirst(1,0,n-1,m-1);
            while(true){
                int s=getsum(1,0,n-1,i,i);
                if(m-s>=k){
                    modify(1,0,n-1,i,s+k);
                    break;
                }
                k-=m-s;
                modify(1,0,n-1,i,m);
                i++;
            }
            return true;
    }
};
int main(){
    BookMyShow b(2,5);
    b.gather(4,0);
    b.gather(2,0);
    b.scatter(5,1);
    b.scatter(5,1);
    return 0;
}