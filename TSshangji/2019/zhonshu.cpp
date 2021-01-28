#include <stdio.h>
#include <vector>

using namespace std;

int n,m,num;


int main(){
    scanf("%d%d",&n,&m);
    vector<int> v;
    for(int i=0;i<n;i++){
        scanf("%d",&num);
        v.push_back(num);
    }
    for(int i=0;i<m;i++){
        vector<int> cnt(10,0);
        for(int j=0;j<n;j++){
            num=v[j]%10;
            v[j]=v[j]/10;
            cnt[num]++;
        }
        int max=0,loc=0;
        for(int j=0;j<10;j++){
            if(cnt[j]>max){
                max=cnt[j];
                loc=j;
            }
        }
        printf("%d ",loc);
    }
}