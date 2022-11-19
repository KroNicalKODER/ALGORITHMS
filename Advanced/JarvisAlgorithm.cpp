#include<bits/stdc++.h>
#define ip pair<int,int>
using namespace std;

int orientation(ip& p,ip& q,ip& r){
    int val = (q.second - p.second) * (r.first-q.first) - (q.first-p.first) * (r.second-q.second);
    if(val==0) return 0;
    if(val>0) return 1;
    else return 2;
}

vector<ip> convexHullJarvis(vector<ip>& Points){
    int n = Points.size();
    vector<ip> hull;
    int l=0;
    vector<bool> vis(n,false);
    vector<bool> inHull(n,false);
    for(int i=1;i<n;i++) if(Points[l].first > Points[i].first) l = i; //LEFTMOST POINT
    int p=l,q;
    vis[p] = true;
    inHull[p] = true;
    do{
        if(inHull[p]==false) hull.push_back(Points[p]);
        vis[p]=true;
        inHull[p] = true;
        q = (p+1)%n;
        for(int i = 0;i<n;i++){
            int ori = orientation(Points[p],Points[i],Points[q]);
            if(ori==2) q = i;
        }
        for(int i=0;i<n;i++){
            if(i!=p&&i!=q&&orientation(Points[p],Points[i],Points[q])==0){
                if(inHull[i]==false){
                    hull.push_back(Points[i]);
                    inHull[i] = true;
                }
            }
        }
        p = q;
    }while(p!=l&&vis[p]==false);
    for(auto itr : hull){
        cout<<itr.first<<" "<<itr.second<<endl;
    }
    return hull;
}

int main()
{
    vector<ip> pairr = {{3,0},{4,0},{5,0},{6,1},{7,2},{7,3},{7,4},{6,5},{5,5},{4,5},{3,5},{2,5},{1,4},{1,3},{1,2},{2,1},{4,2},{0,3}};
    vector<ip> ans = convexHullJarvis(pairr);
    for(auto itr : ans){
        cout<<itr.first<<" "<<itr.second<<endl;
    }
    return 0;
}
