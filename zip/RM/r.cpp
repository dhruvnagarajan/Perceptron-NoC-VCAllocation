#include <bits/stdc++.h>
using namespace std;

int main() {
    int num_input = 64, num_vcs = 8, num_dir = 5, num_weights = 10;
    vector<int> input, vcs, dir, w;
    int flag = 0;
    for (int i = 0; i < num_input; i++) {
        input.push_back(i);
    }
    for (int i = 0; i < num_vcs; i++) {
        vcs.push_back(i);
    }
    for (int i = 0; i <= num_dir; i++) {
        dir.push_back(i);
    }
    for (int i = 0; i <= num_weights; i++) {
        w.push_back(i);
    }
    for (int i = 0; i < num_input; i++) {
        for (int j = 0; j <= num_dir; j++) {
            for (int k = 0; k < num_vcs; k++) {
                for (int l = 0; l < num_weights; l++) {
                    float nexxt;
                    ostringstream _input, _vc, _dir, _w;
                    _input << input[i];
                    _dir << dir[j];
                    _vc << vcs[k];
                    _w << w[l];
                    string filename = "ann.dat/w_" + _input.str() + "_" + _dir.str() + "_" + _vc.str() + "_" + _w.str() + ".dat";
                    ifstream stream (filename.c_str(), ios::binary | ios::in);
                    stream.read((char *) &nexxt, sizeof(nexxt));
                    stream.close();
                    cout << nexxt << " ";
                }
                float bias;
                ostringstream _input, _vc, _dir;
                _input << input[i];
                _dir << dir[j];
                _vc << vcs[k];
                string filename = "ann.dat/w_" + _input.str() + "_" + _dir.str() + "_" + _vc.str() + "_b" + ".dat";
                ifstream stream (filename.c_str(), ios::binary | ios::in);
                stream.read((char *) &bias, sizeof(bias));
                stream.close();
                cout << "\tb:" << bias << endl;
            }
        }
        flag ++;
        // if (flag > 1) return 0;
    }
    return 0;
}
