#include <bits/stdc++.h>
#include "flit.h"
#include "VCAllocator.h"
#include "CustomVCAllocatorHeader.h"
using namespace std;

void CVCA::get_c() {
    bool result = true;
    cout << "\n\tc:";
    ostringstream sw;
    sw << tileID;
    for (int i = 0; i < num_vcs; i++) {
        int latency;
        ostringstream vc;
        vc << i;
        string filename = "ann.dat/c_" + sw.str() + "_" + vc.str() + ".dat";
        ifstream stream(filename.c_str(), ios::binary | ios::in);
        stream.read((char *) &latency, sizeof(latency));
        c.push_back(latency);
        cout << latency << " ";
        stream.close();
    }
    cout << endl;
}

void CVCA::get_e() {
    ostringstream sw;
    sw << tileID;
    cout << "\n\te:";
    for (int i = 0; i < num_vcs; i++) {
        UI _e;
        ostringstream vc;
        vc << i;
        string filename = "ann.dat/e_" + sw.str() + "_" + vc.str() + ".dat";
        ifstream stream(filename.c_str(), ios::binary | ios::in);
        stream.read((char *) &_e, sizeof(_e));
        stream.close();
        e.push_back(int (_e));
        cout << _e << " ";
    }
    cout << endl;
}

void CVCA::get_w() {
    for (int i = 0; i < num_vcs; i++) {
        forwardPass.push_back(0.0);
        switch (i) {
            case 0: {
                // cout << "\n\tw0:";
                for (int j = 0; j < input_size; j++) {
                    int __w;
                    ostringstream _input, _vc, _dir, _w;
                    _input << tileID;
                    _dir << dir;
                    _vc << j;
                    _w << i;
                    string filename = "ann.dat/w_" + _input.str() + "_" + _dir.str() + "_" + _w.str() + "_" + _vc.str() + ".dat";
                    ifstream stream (filename.c_str(), ios::binary | ios::in);
                    stream.read((char *) &__w, sizeof(__w));
                    stream.close();
                    w0.push_back(__w);
                    // cout << w0[j] << " ";
                }
                // cout << endl;
                break;
            }
            case 1: {
                // cout << "\n\tw1:";
                for (int j = 0; j < input_size; j++) {
                    int __w;
                    ostringstream _input, _vc, _dir, _w;
                    _input << tileID;
                    _dir << dir;
                    _vc << j;
                    _w << i;
                    string filename = "ann.dat/w_" + _input.str() + "_" + _dir.str() + "_" + _w.str() + "_" + _vc.str() + ".dat";
                    ifstream stream (filename.c_str(), ios::binary | ios::in);
                    stream.read((char *) &__w, sizeof(__w));
                    stream.close();
                    w1.push_back(__w);
                    // cout << w1[j] << " ";
                }
                // cout << endl;
                break;
            }
            case 2: {
                // cout << "\n\tw2:";
                for (int j = 0; j < input_size; j++) {
                    int __w;
                    ostringstream _input, _vc, _dir, _w;
                    _input << tileID;
                    _dir << dir;
                    _vc << j;
                    _w << i;
                    string filename = "ann.dat/w_" + _input.str() + "_" + _dir.str() + "_" + _w.str() + "_" + _vc.str() + ".dat";
                    ifstream stream (filename.c_str(), ios::binary | ios::in);
                    stream.read((char *) &__w, sizeof(__w));
                    stream.close();
                    w2.push_back(__w);
                    // cout << w2[j] << " ";
                }
                // cout << endl;
                break;
            }
            case 3: {
                // cout << "\n\tw3:";
                for (int j = 0; j < input_size; j++) {
                    int __w;
                    ostringstream _input, _vc, _dir, _w;
                    _input << tileID;
                    _dir << dir;
                    _vc << j;
                    _w << i;
                    string filename = "ann.dat/w_" + _input.str() + "_" + _dir.str() + "_" + _w.str() + "_" + _vc.str() + ".dat";
                    ifstream stream (filename.c_str(), ios::binary | ios::in);
                    stream.read((char *) &__w, sizeof(__w));
                    stream.close();
                    w3.push_back(__w);
                    // cout << w3[j] << " ";
                }
                // cout << endl;
                break;
            }
            case 4: {
                // cout << "\n\tw4:";
                for (int j = 0; j < input_size; j++) {
                    int __w;
                    ostringstream _input, _vc, _dir, _w;
                    _input << tileID;
                    _dir << dir;
                    _vc << j;
                    _w << i;
                    string filename = "ann.dat/w_" + _input.str() + "_" + _dir.str() + "_" + _w.str() + "_" + _vc.str() + ".dat";
                    ifstream stream (filename.c_str(), ios::binary | ios::in);
                    stream.read((char *) &__w, sizeof(__w));
                    stream.close();
                    w4.push_back(__w);
                    // cout << w4[j] << " ";
                }
                // cout << endl;
                break;
            }
            case 5: {
                // cout << "\n\tw5:";
                for (int j = 0; j < input_size; j++) {
                    int __w;
                    ostringstream _input, _vc, _dir, _w;
                    _input << tileID;
                    _dir << dir;
                    _vc << j;
                    _w << i;
                    string filename = "ann.dat/w_" + _input.str() + "_" + _dir.str() + "_" + _w.str() + "_" + _vc.str() + ".dat";
                    ifstream stream (filename.c_str(), ios::binary | ios::in);
                    stream.read((char *) &__w, sizeof(__w));
                    stream.close();
                    w5.push_back(__w);
                    // cout << w5[j] << " ";
                }
                // cout << endl;
                break;
            }
            case 6: {
                // cout << "\n\tw6:";
                for (int j = 0; j < input_size; j++) {
                    int __w;
                    ostringstream _input, _vc, _dir, _w;
                    _input << tileID;
                    _dir << dir;
                    _vc << j;
                    _w << i;
                    string filename = "ann.dat/w_" + _input.str() + "_" + _dir.str() + "_" + _w.str() + "_" + _vc.str() + ".dat";
                    ifstream stream (filename.c_str(), ios::binary | ios::in);
                    stream.read((char *) &__w, sizeof(__w));
                    stream.close();
                    w6.push_back(__w);
                    // cout << w6[j] << " ";
                }
                // cout << endl;
                break;
            }
            case 7: {
                // cout << "\n\tw7:";
                for (int j = 0; j < input_size; j++) {
                    int __w;
                    ostringstream _input, _vc, _dir, _w;
                    _input << tileID;
                    _dir << dir;
                    _vc << j;
                    _w << i;
                    string filename = "ann.dat/w_" + _input.str() + "_" + _dir.str() + "_" + _w.str() + "_" + _vc.str() + ".dat";
                    ifstream stream (filename.c_str(), ios::binary | ios::in);
                    stream.read((char *) &__w, sizeof(__w));
                    stream.close();
                    w7.push_back(__w);
                    // cout << w7[j] << " ";
                }
                // cout << endl;
                break;
            }
        }
    }
}

void CVCA::set_w() {
    ostringstream sw;
    sw << tileID;
    for (int i = 0; i < num_vcs; i++) {
        ostringstream one, two;
        one << i;
        two << dir;
        string filename = "ann.dat/w_" + sw.str() + "_" + one.str() + "_" + two.str() + ".dat";
        ofstream stream(filename.c_str(), ios::binary | ios::out);
        float _ = w[i];
        stream.write((char *) &_, sizeof(_));
        stream.close();
    }
}

void CVCA::get_dw() {
    get_c();
    get_e();
    /*
    cout << "\n\tdw:";
    for(int i = 0; i < input_size; i++) {
        dw.push_back(0.0);
        for (int j = 0; j < num_vcs; j++) {
            // TODO: update to logistic error function
            dw[i] += (LN * (e[j] - c[j]) * (e[j] - c[j]) * w[j] * input[i]); // need bias?
            // dw.push_back(- (    ((input[i] * 1 / log10(output[i]))) + ((1 - input[i]) * 1 / (1 - log10(output[i])))    ));
        }
        cout << dw[i] << " ";
    }
    cout << endl;*/
}

void CVCA::update_w() {
    /*
    cout << "\n\tw_updated:";
    for(int i = 0; i < num_vcs; i++) {
        w[i] -= dw[i];
        cout << w[i] << " ";
    }
    cout << endl;
    set_w();*/
}

void CVCA::backward_pass() {
    get_w();
    // get_dw();
    // update_w();
}

void CVCA::forward_pass() {
    // cout << "\n\tforwardPass:";
    for (int i = 0; i < num_vcs; i++) {
        forwardPass.push_back(0.0);
        switch (i) {
            case 0: {
                for (int j = 0; j < input_size; j++) {
                    forwardPass[i] += w0[j] * input;
                }
                for (int j = 0; j < num_vcs; j++) {
                    forwardPass[i] += w0[j] * vcarr[j];
                }
                break;
            }
            case 1: {
                for (int j = 0; j < input_size; j++) {
                    forwardPass[i] += w1[j] * input;
                }
                for (int j = 0; j < num_vcs; j++) {
                    forwardPass[i] += w1[j] * vcarr[j];
                }
                break;
            }
            case 2: {
                for (int j = 0; j < input_size; j++) {
                    forwardPass[i] += w2[j] * input;
                }
                for (int j = 0; j < num_vcs; j++) {
                    forwardPass[i] += w2[j] * vcarr[j];
                }
                break;
            }
            case 3: {
                for (int j = 0; j < input_size; j++) {
                    forwardPass[i] += w3[j] * input;
                }
                for (int j = 0; j < num_vcs; j++) {
                    forwardPass[i] += w3[j] * vcarr[j];
                }
                break;
            }
            case 4: {
                for (int j = 0; j < input_size; j++) {
                    forwardPass[i] += w4[j] * input;
                }
                for (int j = 0; j < num_vcs; j++) {
                    forwardPass[i] += w4[j] * vcarr[j];
                }
                break;
            }
            case 5: {
                for (int j = 0; j < input_size; j++) {
                    forwardPass[i] += w5[j] * input;
                }
                for (int j = 0; j < num_vcs; j++) {
                    forwardPass[i] += w5[j] * vcarr[j];
                }
                break;
            }
            case 6: {
                for (int j = 0; j < input_size; j++) {
                    forwardPass[i] += w6[j] * input;
                }
                for (int j = 0; j < num_vcs; j++) {
                    forwardPass[i] += w6[j] * vcarr[j];
                }
                break;
            }
            case 7: {
                for (int j = 0; j < input_size; j++) {
                    forwardPass[i] += w7[j] * input;
                }
                for (int j = 0; j < num_vcs; j++) {
                    forwardPass[i] += w7[j] * vcarr[j];
                }
                break;
            }
        }
        // cout << forwardPass[i] << " ";
    }
    // cout << endl;
}

void CVCA::softmax() {
    cout << "\n\tsoftmax:";
    float sum_exp_i = 0;
    cout << "\n\t\tsoftmax exp:";
    for (int i = 0; i < num_vcs; i++) {
        sum_exp_i += exp(forwardPass[i]);
        cout << exp(forwardPass[i]) << " ";
    }
    cout << endl;
    cout << "\n\t\tsoftmax sum:" << sum_exp_i << endl;
    for (int i = 0; i < num_vcs; i++) {
        forwardPass[i] /= sum_exp_i;
        cout << forwardPass[i] << " ";
    }
    cout << endl;
}

void CVCA::argmax() {
    // cout << "\n\targmax:";
    float maxx = INT_MIN;
    int index = 0;
    for (int j = 0; j < num_vcs; j++) {
        if (maxx < forwardPass[j]) {
            maxx = forwardPass[j];
            index = j;
        }
    }
    output = index;
}

void CVCA::get_vc_pref() {
    backward_pass();
    forward_pass();
    // softmax();
    argmax();
}

void CVCA::backtrack(int vcarr[], int left, int right){
    if (left == right) {
        VI _vcper;
        for (int i = 0; i < num_vcs; i++) {
            _vcper.push_back(vcarr[i]);
        }
        vcper.push_back(_vcper);
    } else {
        for (int i = left; i <= right; i++) {
            vcarr[i] = vcarr[i] + vcarr[left] - (vcarr[left] = vcarr[i]);
            backtrack(vcarr, left + 1, right);
            vcarr[i] = vcarr[i] + vcarr[left] - (vcarr[left] = vcarr[i]);
        }
    }
}

void matches(bool isMatchedToALiveVC) {
    string filename = "matches.dat";
    ifstream stream (filename.c_str(), ios::binary | ios::in);
    int match = 0, notMatch = 0;
    stream.read((char *) &match, sizeof(match));
    stream.read((char *) &notMatch, sizeof(notMatch));
    stream.close();
    if (isMatchedToALiveVC) {
        match ++;
    } else {
        notMatch ++;
    }
    ofstream st (filename.c_str(), ios::binary | ios::out);
    st.write((char *) &match, sizeof(match));
    st.write((char *) &notMatch, sizeof(notMatch));
    st.close();
}

void CVCA::process_input() {
    // cout<< "\n\tinput:";
    /*
    for (int i = 0; i < input_size; i++) {
        input.push_back(0);
        if (i == tileID) {
            input[i] = 1;
        }
        // cout << input[i] << " ";
    }
    */
   input = tileID;
    for (int i = 0; i < num_vcs; i++) {
        // cout << vcs[i] << " ";
        vcarr[i] = vcs[i];
        if (vcarr[i] == 0) {
            isAnyVCDead = true;
            numvcdead ++;
        } else {
            numvclive ++;
        }
    }
    // cout << endl;
}

UI CVCA::vca(UI _tileID, UI _dir, VI _vcs) {
    // cout << "CVCA::vca()\t-\tann\n";

    ios::sync_with_stdio(false);
    
    LN = 0.01; // industry practice
    tileID = _tileID;
    dir = _dir;
    input_size = 9;
    vcs = _vcs;
    num_vcs = NUM_VCS;
    isAnyVCDead = false;
    numvcdead = 0;
    numvclive = 0;

    process_input();

   get_vc_pref();


   if (vcarr[output] == 0) {
    for (int i = 0; i < num_vcs; i++) {
        if (vcs[i] == 1) {
            return i;
        }
    }
   } else {
       return output;
   }
}