#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(2014);
    int num_input = 64, num_vcs = 8, num_dir = 5, num_weights = 9;
    vector<int> input, vcs, dir, w;
    int start = 1, end = start + num_vcs;
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
                    int nexxt = rand() % end + start;
                    ostringstream _input, _vc, _dir, _w;
                    _input << input[i];
                    _dir << dir[j];
                    _vc << vcs[k];
                    _w << w[l];
                    string filename = "ann.dat/w_" + _input.str() + "_" + _dir.str() + "_" + _vc.str() + "_" + _w.str() + ".dat";
                    ofstream stream (filename.c_str(), ios::binary | ios::out);
                    stream.write((char *) &nexxt, sizeof(nexxt));
                    stream.close();
                }
            }
        }
    }
    return 0;
}


// REQUIRE FLOAT VALUES
