#include <bits/stdc++.h>

using namespace std;

int main() {
    string filename = "matches.dat";
    /*
    ofstream stream (filename.c_str(), ios::binary | ios::out);
    int val = 0;
    stream.write((char *) &val, sizeof(val));
    stream.write((char *) &val, sizeof(val));
    stream.close();
    */
    ifstream st (filename.c_str(), ios::binary | ios::in);
    int one, two;
    st.read((char *) &one, sizeof(one));
    st.read((char *) &two, sizeof(two));
    st.close();
    cout << one << " " << two << endl;
    return 0;
}