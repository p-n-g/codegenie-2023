#include<bits/stdc++.h>
using namespace std;

float calculatePercentile(int totalStudent,vector<int>& marks,int yourScore){
   int count = 0;
    for(auto mark: marks){
        if(mark < yourScore){
            count++;
        }
    }
    float ans = float(count)/totalStudent*100;
    ans = int(ans*100 + 0.5);
    return ans/100;
}

int main(){
    int totalStudents = 7;
    vector<int> marks = {800, 300, 950, 760, 680, 490, 640};
    int yourScore = 760;
    float percentileScore = calculatePercentile(totalStudents,marks,yourScore);
    cout<<percentileScore<<endl; 
    return 0;
}
