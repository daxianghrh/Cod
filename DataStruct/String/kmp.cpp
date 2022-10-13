#include <iostream>
#include <string>
#include <vector>
using namespace std;

void getNext (int next[], string &t) {
    //四步
    //1、初始化
    //i表示后缀末尾 
    //j表示前缀末尾、同时表示最长相等前后缀的长度
    int j = 0;
    next[0] = 0;
    for (int i = 1; i < t.size(); ++i) {
        //2、前后缀不相同
        while(j > 0 && t[i] != t[j]) {
            j = next[j - 1];
        }
        //3、前后缀相同
        if(t[i] == t[j]){
            ++j;
        }
        //4、更新next[]  
        next[i] = j;
    }
}

bool kmp(string &s, string &t) {
    int i = 0, j = 0;
    int next[t.size()];
    getNext(next, t);
    while (i < s.size() && j < t.size()) {
        // j回溯到0时 i+1;
        if (j == 0 || s[i] == t[j]) {
            ++i;
            ++j;
        }else{
            j = next[j - 1];
        }
    }
    if ( i > s.size()) {
        return false;
    }
    return true;
}

int main()
{
    string s = "aabaabaaf";//主串
    string t = "aabaaf"; //模式串
    cout << kmp(s, t) << endl;
}