#include "stdio.h"
#include "algorithm"
#include "vector"

int main(){
    int n;
    std::vector<std::pair<int,int>> coordinates;
    int x,y;
    int sum[5]={0};
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d",&x,&y);
        coordinates.push_back(std::make_pair(x,y));
    }
    for (int i = 0; i < coordinates.size(); ++i) {
        x = coordinates[i].first;
        y = coordinates[i].second;
        if (std::find(coordinates.begin(),coordinates.end(), std::make_pair(x-1,y))!=coordinates.end()
        &&std::find(coordinates.begin(),coordinates.end(), std::make_pair(x+1,y))!=coordinates.end()
        &&std::find(coordinates.begin(),coordinates.end(), std::make_pair(x,y+1))!=coordinates.end()
        &&std::find(coordinates.begin(),coordinates.end(), std::make_pair(x,y-1))!=coordinates.end()){
            int score = 0;
            if (std::find(coordinates.begin(),coordinates.end(), std::make_pair(x-1,y-1))!=coordinates.end()){
                score++;
            }
            if (std::find(coordinates.begin(),coordinates.end(), std::make_pair(x+1,y+1))!=coordinates.end()){
                score++;
            }
            if (std::find(coordinates.begin(),coordinates.end(), std::make_pair(x-1,y+1))!=coordinates.end()){
                score++;
            }
            if (std::find(coordinates.begin(),coordinates.end(), std::make_pair(x+1,y-1))!=coordinates.end()){
                score++;
            }
            sum[score]++;
        }
    }
    for (int i = 0; i < 5; ++i) {
        printf("%d\n",sum[i]);
    }
    return 0;
}