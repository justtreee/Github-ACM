#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <map>
#include <vector>
using namespace std;
#define M 1000
#define INF (0x3f3f3f3f)
typedef long long ll;
const double PI = acos(-1.0);

map<string,int> cnt;
vector<string> words;
string cal(const string& s)
{
    string ans = s;
    for(int i=0; i<ans.size(); i++)
    {
        ans[i] = tolower(ans[i]);
    }
    sort(ans.begin(),ans.end());
    return ans;
}

int main()
{
    string str;
    while(cin>>str)
    {
        if(str == "#")
        {
            break;
        }
        words.push_back(str);
        string sortstr = cal(str);
        if(!cnt.count(sortstr))
        {
            cnt[sortstr] = 0;
        }
        cnt[sortstr]++;
    }
    vector<string> ans;
    for(int i=0; i<words.size(); i++)
    {
        if(cnt[cal(words[i])] == 1)
        {
            ans.push_back(words[i]);
        }
    }

    sort(ans.begin(),ans.end());
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<endl;
    }

return 0;
}
