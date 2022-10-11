#include <iostream>
#include <vector>
using namespace std;

void translate(bool*&b2, int n, int i, int j) {
    if (j == 1) return;
    translate(b2, n, ++i, j/=2);
    b2[i-1] = n/j%2;
}
void translate(vector<bool>&ans, int n, int i) {
    if (!n) return;
    translate(ans, n/2, ++i);
    ans.push_back(n%2);
}

vector<int> RLE(bool*&b2, int size) {
    vector<int> arr;
    for (int i = 0; i < size;) {
        arr.push_back(0);
        if (b2[i] == 0) {
            do {
                i++;
                arr[arr.size()-1]++;
            } while(i < size && b2[i] == 0);
        }
        else if (b2[i] == 1) {
            do {
                i++;
                arr[arr.size()-1]++;
            } while(i < size && b2[i] == 1);
        }
    }
    return arr;
}

vector<bool> elias(vector<int> rleArr) {
    vector<bool> ans;
    for (int i = 0; i < rleArr.size(); i++) {
        int count = 0;
        for (int n = rleArr[i]; n != 1; n/=2) {
            count++;
        } 
        for (int i = 0; i < count; i++) {
            ans.push_back(0);
        }
        translate(ans, rleArr[i], ans.size()); // translate RLE number to 2 bit RLE Number

    }
    return ans;
}

int main() {
    string s;
    cout << "Text: ";
    getline(cin, s);

    // From 10 base to 2 base
    bool* b2 = new bool[s.length()*8];
    for (int i = 0; s[i]; i++) {
        translate(b2, int(s[i]), i*8, 256);
    }

    // From 2 base text to RLE
    vector<int> sRLE = RLE(b2, s.length()*8);
    cout << endl << "Text to RLE: ";
    for (int i = 0; i < sRLE.size(); i++) {
        cout << sRLE[i] << ' ';
    }
    delete[] b2;

    // From RLE to Elias gamma code
    vector<bool> sElias = elias(sRLE);
    cout << endl << endl << "RLE to Elias gamma code: ";
    cout << int(s[0]) / 128; // First bit (0 or 1)
    for (int i = 0; i < sElias.size(); i++) {
        cout << sElias[i];
    }
    cout << endl;
}