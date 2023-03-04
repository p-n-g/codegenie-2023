#include<bits/stdc++.h>
using namespace std;

string getEligibleStudents(int totalStudents,vector<string> students,vector<int>& marks,vector<string>& examResults,int totalMarks,float requiredPercentile){
    map<int, pair<string, string>> info;
    vector<string> ans;
    string output = "";

    for (int i = 0; i < totalStudents; i++)
    {
        info.insert(pair<int, pair<string, string>>(marks[i], pair<string, string>(students[i], examResults[i])));
    }
    int rank = 0;
    for (auto val : info)
    {
        float percentile = float(rank) / totalStudents * 100.0;
        // cout << val.second.first << " " << val.first << " " << percentile << " " << val.second.second << endl;
        if (percentile >= requiredPercentile && val.second.second == "Passed")
        {
            ans.push_back(val.second.first);
        }
        rank++;
    }

    reverse(ans.begin(), ans.end());
    for (auto elgStd : ans)
    {
        output += elgStd + ",";
    }
    if (output != "")
    {
        output.pop_back();
    }
    return output;
}

int main(){
    int totalStudents = 7;
    int totalMarks = 1000;
    float requiredPercentile = 50;
    vector<int> marks = {800, 300, 750, 760, 680, 790, 640};
    vector<string> students = { "Kartik", "Devang", "Pari", "Ketan", "Sheetal", "Darshana", "Mohan" };
    vector<string> examResults = {"Passed", "Failed", "Passed", "Failed", "Passed", "Passed", "Passed"};
    string eligibleStudents = getEligibleStudents(totalStudents, students,marks, examResults, totalMarks, requiredPercentile);
    cout<<eligibleStudents<<endl;
    return 0;
}
