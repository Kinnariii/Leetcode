class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string>mpp;
        for(auto i : wordList){
            mpp.insert(i);
        }
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty()){
            int size = q.size();
            while(size--){
                string a = q.front().first;
                int e = q.front().second;
                q.pop();
                if(a == endWord) return e;
                int n = a.length();
                for(int i=0;i<n;i++){
                    char origin = a[i];
                    for(char k = 'a';k<='z';k++){
                        a[i] = k;
                        if(mpp.find(a) != mpp.end()){
                            q.push({a,e+1});
                            mpp.erase(a);
                        }
                    }
                    a[i] = origin;
                }
            }
        }
        return 0;
    }
};