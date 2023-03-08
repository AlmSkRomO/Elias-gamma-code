#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool theIdiotTest(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != '0' && s[i] != '1') return 1;
    }
    return 0;
}

vector<int> elias(string s) {
    vector<int> arr;

    int i = 1;
    for (; i < s.length();) {
        if (s[i] == '1') {
            arr.push_back(1);
            i++;
        }
        if (s[i] == '0') {
            int k = 2;
            i++;
            while (i < s.length() && s[i] != '1') {
                k *= 2;
                i++;
            }
            arr.push_back(0);
            while (i < s.length() && k) {
                arr[arr.size() - 1] += k * (s[i] == '1' ? 1 : 0);
                k /= 2;
                i++;
            }
        }
    }
    return arr;
}

vector<int> RLE(vector<int> sElias, bool fn) {
    cout << "test";
    vector<bool> arr;
    for (int i = 0; i < sElias.size(); i++) {
        for (int j = 0; j < sElias[i]; j++) {
            arr.push_back(fn);
        }
        fn = !fn;
    }

    vector<int> ans;
    if (arr.size() % 8 != 0) {
        ans.push_back(0);
        return ans;
    }

    else {
        for (int i = 0, count = 0; count != arr.size(); i++) {
            ans.push_back(0);
            for (int n = 128; n; n /= 2, count++) {
                ans[i] += arr[count] * n;
            }
        }
    }
    return ans;
}

int main() {
    string s;
    do {
       cout << "Elias gamma code: ";
       getline(cin, s);
    } while (theIdiotTest(s));

    vector<int> sElias = elias(s);
    cout << endl << "Elias to RLE: ";
    for (int i = 0; i < sElias.size(); i++) {
        cout << sElias[i] << ' ';
    }

    vector<int> sRLE = RLE(sElias, (s[0] == '1' ? 1 : 0));
    cout << endl << endl << "RLE to Text: ";
    if (sRLE.size() == 0 || sRLE[0] == 0) cout << "Incorrect value";
    else {
        for (int i = 0; i < sRLE.size(); i++) {
            cout << char(sRLE[i]);
        }
    }
    cout << endl;
}
