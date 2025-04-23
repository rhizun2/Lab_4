#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    string s = "";
    stack<pair<int, string>> history;

    for (int i = 0; i < n; ++i) {
        int op;
        cin >> op;

        if (op == 1) {  
            string str;
            cin >> str;
            history.push({op, str});
            s += str;
        } else if (op == 2) {  
            int k;
            cin >> k;
            string deleted = s.substr(s.length() - k, k);
            history.push({op, deleted});
            s = s.substr(0, s.length() - k);
        } else if (op == 3) {  
            int k;
            cin >> k;
            cout << s[k - 1] << endl;
        } else if (op == 4) {  
            if (!history.empty()) {
                pair<int, string> last_op = history.top();
                history.pop();
                if (last_op.first == 1) {  
                    s = s.substr(0, s.length() - last_op.second.length());
                } else if (last_op.first == 2) {  
                    s += last_op.second;
                }
            }
        }
    }

    return 0;
}

