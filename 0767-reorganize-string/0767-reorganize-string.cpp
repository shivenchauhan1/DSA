class Solution{
public:
    string reorganizeString(string s) {
        int freq[26] = {0};

        for(char x : s) {
            freq[x - 'a']++;
        }

        priority_queue<pair<int, char>> pq;

        for(int i = 0; i < 26; i++) {
            if(freq[i] > 0) {
                pq.push({freq[i], (char)(i + 'a')});
            }
        }

        string ans = "";

        while(!pq.empty()) {
            auto e1 = pq.top();
            pq.pop();

            if(pq.empty()) {
                if(e1.first > 1)
                    return "";

                ans += e1.second;
                break;
            }

            auto e2 = pq.top();
            pq.pop();

            ans += e1.second;
            ans += e2.second;

            e1.first--;
            e2.first--;

            if(e1.first > 0)
                pq.push(e1);

            if(e2.first > 0)
                pq.push(e2);
        }

        return ans;
    }
};