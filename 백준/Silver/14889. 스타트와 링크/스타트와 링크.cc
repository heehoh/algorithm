#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool team[20] = {};
int S[20][20] = {};
int N;
int min_value = 100000000;

void teamset(int idx, int cnt)
{
    vector<int> t1;
    vector<int> t2;
    int t1_score = 0;
    int t2_score = 0;
    if(cnt == (N/2))
    {
        for(int i = 0; i < N; i++)
        {
            if(team[i] == true) // 선택된 사람들은 t1팀에
                t1.push_back(i);
            else // 그 외의 사람들은 t2팀으로
                t2.push_back(i);
        }
        for(int i = 0; i < (N/2); i++)
            for(int j = 0; j < (N/2); j++)
            {
                t1_score += S[t1[i]][t1[j]];
                t2_score += S[t2[i]][t2[j]];
            } // 각 팀의 능력치의 합 계산
        if(abs(t1_score - t2_score) < min_value)
            min_value = abs(t1_score - t2_score);
        return;
    }

    for(int i = idx; i < N; i++)
    {
        if(team[i])
            continue;
        else
        {
            team[i] = true;
            teamset(i, cnt+1);
            team[i] = false;
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> S[i][j];
        }
    }
    teamset(0, 0);
    cout << min_value;
}