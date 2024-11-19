#include<bits\stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
int main(){
    int num;
    scanf("%d",&num);
    while(num--){
        int m,n;
        scanf("%d%d",&n,&m);
        int arr[n][m];
        rep(i,0,n){
            rep(j,0,m){
                scanf("%d",&arr[i][j]);
            }
        }
        if(m==1&&n==1){
            printf("-1\n");
        }
        else{
         rep(i,0,n){
            rep(j,0,m){
               arr[i][j]++;
               if(arr[i][j]>m*n)
               arr[i][j]=1;
               printf("%d ",arr[i][j]);
            }
            printf("\n");
        }
        }
    }
    return 0;
}