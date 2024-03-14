#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int num = -1;
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == num)
            continue;
        num = arr[i];
        answer.push_back(num);
    }
    return answer;
}