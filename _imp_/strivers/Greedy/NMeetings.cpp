#include<bits/stdc++.h>
using namespace std;


class Solution {
    public: 
    struct meet{
        int start, end;
    };
    int maxMeetings(int start[], int end[], int n)
    {
        meet arr[n];
        for(int i=0;i<n;i++){
            arr[i].start=start[i], arr[i].end=end[i];
        }

        sort(arr, arr+n, [](const meet &m1, const meet &m2){
            return m1.end < m2.end;
        });

        int ans = 0;
        int currEnd=0;
        for(int i=0;i<n;i++){
            if(arr[i].start > currEnd){
                ans+=1;
                currEnd=arr[i].end;
            }
        }
        return ans;
    }
};

int main() {
    int n;
    cin>>n;
    int st[n], en[n];
    for(int i=0;i<n;i++)
        cin>>st[i];
    for(int i=0;i<n;i++)
        cin>>en[i];
    Solution sb;
    cout<<sb.maxMeetings(st, en, n);
    return 0;
}