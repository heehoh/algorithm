#include <string>
#include <vector>
#include <iostream>

using namespace std;

string caltime2(int m, int s) {
    char arr[5];
    
    arr[0] = m / 10 + '0';
    arr[1] = m % 10 + '0';
    arr[2] = ':';
    arr[3] = s / 10 + '0';
    arr[4] = s % 10 + '0';
    
    string str(arr);
    return str;
}

int caltime(const string &time) {
    int m;
    int s;
    m = (int)(time[0] - '0') * 10 + (int)(time[1] - '0');
    s = (int)(time[3] - '0') * 10 + (int)(time[4] - '0');
    // cout << m << ':' << s << '\n';
    return m * 60 + s;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    int len = caltime(video_len);
    int p = caltime(pos);
    int s = caltime(op_start);
    int e = caltime(op_end);
    for (auto com : commands) {
        if (p >= s && p <= e)
            p = e;
        if (com == "prev")
        {
            p -= 10;
            if (p < 0)
                p = 0;
        }
        else if (com == "next")
        {
            p += 10;
            if (p > len)
                p = len;
        }
    }
    if (p >= s && p <= e)
        p = e;
    int mm = p / 60;
    int ss = p % 60;
    
    return caltime2(mm, ss);
}