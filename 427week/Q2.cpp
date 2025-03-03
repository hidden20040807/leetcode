#include<bits\stdc++.h>
using namespace std;
class Solution {
public:
    int maxRectangleArea(vector<vector<int>>& points) {
        int n=points.size();
        int ans=-1;
        for(int i=0;i<n-1;i++)for(int j=i+1;j<n;j++){
            if(points[i][0]==points[j][0]||points[i][1]==points[j][1])
            continue;
            int x0=min(points[i][0],points[j][0]);
            int y0=min(points[i][1],points[j][1]);
            int x1=max(points[i][0],points[j][0]);
            int y1=max(points[i][1],points[j][1]);
            int cnt=0;
            for(int k=0;k<n;k++){
                int x=points[k][0];
                int y=points[k][1];
                if((x==points[i][0]&&y==points[j][1])||(x==points[j][0]&&y==points[i][1]))
                cnt++;
            }
            auto check=[&](){
                for(int k=0;k<n;k++){
                    int x=points[k][0];
                    int y=points[k][1];
                    if(!((x==points[i][0]&&y==points[i][1])||(x==points[j][0]&&y==points[j][1]))){
                    if(x<x0||x>x1||y<y0||y>y1)
                        continue;
                    else if((x==points[i][0]&&y==points[j][1])||(x==points[j][0]&&y==points[i][1]))
                    continue;
                    else
                    return false;
                    }
                   
                }
                return true;
            };
            if(cnt>=2&&check()){
                ans=max(ans,abs(x0-x1)*abs(y1-y0));
            }
               
        }
        return ans;
        
    }
};
int main(){
    return 0;
}