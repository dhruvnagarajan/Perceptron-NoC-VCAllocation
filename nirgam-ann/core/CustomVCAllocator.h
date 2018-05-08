#include <bits/stdc++.h>
#include "flit.h"
#include "VCAllocator.h"
#include "CustomVCAllocatorHeader.h"
using namespace std;

void CVCA::get_w() {
    for (int i = 0; i < num_vcs; i++) {
        switch (i) {
            case 0: {
                for (int j = 0; j < input_size; j++) {
                    float __w;
                    ostringstream _input, _vc, _dir, _w;
                    _input << tileID;
                    _dir << dir;
                    _vc << i;
                    _w << j;
                    string filename = "ann.dat/w_" + _input.str() + "_" + _dir.str() + "_" + _w.str() + "_" + _vc.str() + ".dat";
                    ifstream stream (filename.c_str(), ios::binary | ios::in);
                    stream.read((char *) &__w, sizeof(__w));
                    stream.close();
                    w0.push_back(__w);
                }
                float bias;
                ostringstream _input, _vc, _dir;
                _input << tileID;
                _dir << dir;
                _vc << i;
                string filename = "ann.dat/w_" + _input.str() + "_" + _dir.str() + "_" + _vc.str() + "_b" + ".dat";
                ifstream stream (filename.c_str(), ios::binary | ios::in);
                stream.read((char *) &bias, sizeof(bias));
                stream.close();
                b0 = bias;
                break;
            }
            case 1: {
                for (int j = 0; j < input_size; j++) {
                    float __w;
                    ostringstream _input, _vc, _dir, _w;
                    _input << tileID;
                    _dir << dir;
                    _vc << i;
                    _w << j;
                    string filename = "ann.dat/w_" + _input.str() + "_" + _dir.str() + "_" + _w.str() + "_" + _vc.str() + ".dat";
                    ifstream stream (filename.c_str(), ios::binary | ios::in);
                    stream.read((char *) &__w, sizeof(__w));
                    stream.close();
                    w1.push_back(__w);
                }
                break;
            }
            case 2: {
                for (int j = 0; j < input_size; j++) {
                    float __w;
                    ostringstream _input, _vc, _dir, _w;
                    _input << tileID;
                    _dir << dir;
                    _vc << i;
                    _w << j;
                    string filename = "ann.dat/w_" + _input.str() + "_" + _dir.str() + "_" + _w.str() + "_" + _vc.str() + ".dat";
                    ifstream stream (filename.c_str(), ios::binary | ios::in);
                    stream.read((char *) &__w, sizeof(__w));
                    stream.close();
                    w2.push_back(__w);
                }
                break;
            }
            case 3: {
                for (int j = 0; j < input_size; j++) {
                    float __w;
                    ostringstream _input, _vc, _dir, _w;
                    _input << tileID;
                    _dir << dir;
                    _vc << i;
                    _w << j;
                    string filename = "ann.dat/w_" + _input.str() + "_" + _dir.str() + "_" + _w.str() + "_" + _vc.str() + ".dat";
                    ifstream stream (filename.c_str(), ios::binary | ios::in);
                    stream.read((char *) &__w, sizeof(__w));
                    stream.close();
                    w3.push_back(__w);
                }
                break;
            }
            case 4: {
                for (int j = 0; j < input_size; j++) {
                    float __w;
                    ostringstream _input, _vc, _dir, _w;
                    _input << tileID;
                    _dir << dir;
                    _vc << i;
                    _w << j;
                    string filename = "ann.dat/w_" + _input.str() + "_" + _dir.str() + "_" + _w.str() + "_" + _vc.str() + ".dat";
                    ifstream stream (filename.c_str(), ios::binary | ios::in);
                    stream.read((char *) &__w, sizeof(__w));
                    stream.close();
                    w4.push_back(__w);
                }
                break;
            }
            case 5: {
                for (int j = 0; j < input_size; j++) {
                    float __w;
                    ostringstream _input, _vc, _dir, _w;
                    _input << tileID;
                    _dir << dir;
                    _vc << i;
                    _w << j;
                    string filename = "ann.dat/w_" + _input.str() + "_" + _dir.str() + "_" + _w.str() + "_" + _vc.str() + ".dat";
                    ifstream stream (filename.c_str(), ios::binary | ios::in);
                    stream.read((char *) &__w, sizeof(__w));
                    stream.close();
                    w5.push_back(__w);
                }
                break;
            }
            case 6: {
                for (int j = 0; j < input_size; j++) {
                    float __w;
                    ostringstream _input, _vc, _dir, _w;
                    _input << tileID;
                    _dir << dir;
                    _vc << i;
                    _w << j;
                    string filename = "ann.dat/w_" + _input.str() + "_" + _dir.str() + "_" + _w.str() + "_" + _vc.str() + ".dat";
                    ifstream stream (filename.c_str(), ios::binary | ios::in);
                    stream.read((char *) &__w, sizeof(__w));
                    stream.close();
                    w6.push_back(__w);
                }
                break;
            }
            case 7: {
                for (int j = 0; j < input_size; j++) {
                    float __w;
                    ostringstream _input, _vc, _dir, _w;
                    _input << tileID;
                    _dir << dir;
                    _vc << i;
                    _w << j;
                    string filename = "ann.dat/w_" + _input.str() + "_" + _dir.str() + "_" + _w.str() + "_" + _vc.str() + ".dat";
                    ifstream stream (filename.c_str(), ios::binary | ios::in);
                    stream.read((char *) &__w, sizeof(__w));
                    stream.close();
                    w7.push_back(__w);
                }
                break;
            }
        }
    }
}

void CVCA::get_dw() {
    float mse = 0.0;
    for (int j = 0; j < input_size; j++) {
        mse += ((float(forwardPass[j]) - float(e)) * (float(forwardPass[j]) - float(e)));
    }
    mse = mse * 0.5 * 1/input_size;
    for(int i = 0; i < num_vcs; i++) {
        switch(i) {
            case 0: {
                for (int j = 0; j < input_size; j++) {
                    float _ = float(mse * float(input[j]));
                    dw0.push_back(_);
                }
                break;
            }
            case 1: {
                for (int j = 0; j < input_size; j++) {
                    float _ = float(mse * float(input[j]));
                    dw1.push_back(_);
                }
                break;
            }
            case 2: {
                for (int j = 0; j < input_size; j++) {
                    float _ = float(mse * float(input[j]));
                    dw2.push_back(_);
                }
                break;
            }
            case 3: {
                for (int j = 0; j < input_size; j++) {
                    float _ = float(mse * float(input[j]));
                    dw3.push_back(_);
                }
                break;
            }
            case 4: {
                for (int j = 0; j < input_size; j++) {
                    float _ = float(mse * w4[j] * float(input[j]));
                    dw4.push_back(_);
                }
                break;
            }
            case 5: {
                for (int j = 0; j < input_size; j++) {
                    float _ = float(mse * float(input[j]));
                    dw5.push_back(_);
                }
                break;
            }
            case 6: {
                for (int j = 0; j < input_size; j++) {
                    float _ = float(mse * float(input[j]));
                    dw6.push_back(_);
                }
                break;
            }
            case 7: {
                for (int j = 0; j < input_size; j++) {
                    float _ = float(mse * float(input[j]));
                    dw7.push_back(_);
                }
                break;
            }
        }
    }
    b0 -= b0 * mse;
}

void CVCA::update_w() {
    for(int i = 0; i < num_vcs; i++) {
        switch(i) {
            case 0: {
                for (int j = 0; j < input_size; j++) {
                    if (!isnan(dw0[j])) w0[j] -= dw0[j];
                }
                break;
            }
            case 1: {
                for (int j = 0; j < input_size; j++) {
                    if (!isnan(dw1[j])) w1[j] -= dw1[j];
                }
                break;
            }
            case 2: {
                for (int j = 0; j < input_size; j++) {
                    if (!isnan(dw2[j])) w2[j] -= dw2[j];
                }
                break;
            }
            case 3: {
                for (int j = 0; j < input_size; j++) {
                    if (!isnan(dw3[j])) w3[j] -= dw3[j];
                }
                break;
            }
            case 4: {
                for (int j = 0; j < input_size; j++) {
                    if (!isnan(dw4[j])) w4[j] -= dw4[j];
                }
                break;
            }
            case 5: {
                for (int j = 0; j < input_size; j++) {
                    if (!isnan(dw5[j])) w5[j] -= dw5[j];
                }
                break;
            }
            case 6: {
                for (int j = 0; j < input_size; j++) {
                    if (!isnan(dw6[j])) w6[j] -= dw6[j];
                }
                break;
            }
            case 7: {
                for (int j = 0; j < input_size; j++) {
                    if (!isnan(dw7[j])) w7[j] -= dw7[j];
                }
                break;
            }
        }
    }
    set_w();
}

void CVCA::set_w() {
    float bias = b0;
    ostringstream _input, _vc, _dir;
    _input << tileID;
    _dir << dir;
    _vc << 0;
    string filename = "ann.dat/w_" + _input.str() + "_" + _dir.str() + "_" + _vc.str() + "_b" + ".dat";
    ofstream stream (filename.c_str(), ios::binary | ios::out);
    stream.write((char *) &bias, sizeof(bias));
    stream.close();
    for (int i = 0; i < num_vcs; i++) {
        switch (i) {
            case 0: {
                for (int j = 0; j < input_size; j++) {
                    float __w = w0[j];
                    ostringstream _input, _vc, _dir, _w;
                    _input << tileID;
                    _dir << dir;
                    _vc << i;
                    _w << j;
                    string filename = "ann.dat/w_" + _input.str() + "_" + _dir.str() + "_" + _w.str() + "_" + _vc.str() + ".dat";
                    ofstream stream (filename.c_str(), ios::binary | ios::out);
                    stream.write((char *) &__w, sizeof(__w));
                    stream.close();
                }
                break;
            }
            case 1: {
                for (int j = 0; j < input_size; j++) {
                    float __w = w1[j];
                    ostringstream _input, _vc, _dir, _w;
                    _input << tileID;
                    _dir << dir;
                    _vc << i;
                    _w << j;
                    string filename = "ann.dat/w_" + _input.str() + "_" + _dir.str() + "_" + _w.str() + "_" + _vc.str() + ".dat";
                    ofstream stream (filename.c_str(), ios::binary | ios::out);
                    stream.write((char *) &__w, sizeof(__w));
                    stream.close();
                }
                break;
            }
            case 2: {
                for (int j = 0; j < input_size; j++) {
                    float __w = w2[j];
                    ostringstream _input, _vc, _dir, _w;
                    _input << tileID;
                    _dir << dir;
                    _vc << j;
                    _w << j;
                    string filename = "ann.dat/w_" + _input.str() + "_" + _dir.str() + "_" + _w.str() + "_" + _vc.str() + ".dat";
                    ofstream stream (filename.c_str(), ios::binary | ios::out);
                    stream.write((char *) &__w, sizeof(__w));
                    stream.close();
                }
                break;
            }
            case 3: {
                for (int j = 0; j < input_size; j++) {
                    float __w = w3[j];
                    ostringstream _input, _vc, _dir, _w;
                    _input << tileID;
                    _dir << dir;
                    _vc << i;
                    _w << j;
                    string filename = "ann.dat/w_" + _input.str() + "_" + _dir.str() + "_" + _w.str() + "_" + _vc.str() + ".dat";
                    ofstream stream (filename.c_str(), ios::binary | ios::out);
                    stream.write((char *) &__w, sizeof(__w));
                    stream.close();
                }
                break;
            }
            case 4: {
                for (int j = 0; j < input_size; j++) {
                    float __w = w4[j];
                    ostringstream _input, _vc, _dir, _w;
                    _input << tileID;
                    _dir << dir;
                    _vc << i;
                    _w << j;
                    string filename = "ann.dat/w_" + _input.str() + "_" + _dir.str() + "_" + _w.str() + "_" + _vc.str() + ".dat";
                    ofstream stream (filename.c_str(), ios::binary | ios::out);
                    stream.write((char *) &__w, sizeof(__w));
                    stream.close();
                }
                break;
            }
            case 5: {
                for (int j = 0; j < input_size; j++) {
                    float __w = w5[j];
                    ostringstream _input, _vc, _dir, _w;
                    _input << tileID;
                    _dir << dir;
                    _vc << i;
                    _w << j;
                    string filename = "ann.dat/w_" + _input.str() + "_" + _dir.str() + "_" + _w.str() + "_" + _vc.str() + ".dat";
                    ofstream stream (filename.c_str(), ios::binary | ios::out);
                    stream.write((char *) &__w, sizeof(__w));
                    stream.close();
                }
                break;
            }
            case 6: {
                for (int j = 0; j < input_size; j++) {
                    float __w = w6[j];
                    ostringstream _input, _vc, _dir, _w;
                    _input << tileID;
                    _dir << dir;
                    _vc << i;
                    _w << j;
                    string filename = "ann.dat/w_" + _input.str() + "_" + _dir.str() + "_" + _w.str() + "_" + _vc.str() + ".dat";
                    ofstream stream (filename.c_str(), ios::binary | ios::out);
                    stream.write((char *) &__w, sizeof(__w));
                    stream.close();
                }
                break;
            }
            case 7: {
                for (int j = 0; j < input_size; j++) {
                    float __w = w7[j];
                    ostringstream _input, _vc, _dir, _w;
                    _input << tileID;
                    _dir << dir;
                    _vc << i;
                    _w << j;
                    string filename = "ann.dat/w_" + _input.str() + "_" + _dir.str() + "_" + _w.str() + "_" + _vc.str() + ".dat";
                    ofstream stream (filename.c_str(), ios::binary | ios::out);
                    stream.write((char *) &__w, sizeof(__w));
                    stream.close();
                }
                break;
            }
        }
    }
}

void CVCA::backward_pass() {
    get_dw();
    update_w();
}

void CVCA::forward_pass() {
    for (int i = 0; i < num_vcs; i++) {
        forwardPass.push_back(b0);
        switch (i) {
            case 0: {
                for (int j = 0; j < input_size; j++) {
                    forwardPass[i] += w0[j] * input[j];
                }
                break;
            }
            case 1: {
                for (int j = 0; j < input_size; j++) {                    
                    forwardPass[i] += w1[j] * input[j];
                }
                break;
            }
            case 2: {
                for (int j = 0; j < input_size; j++) {                    
                    forwardPass[i] += w2[j] * input[j];
                }
                break;
            }
            case 3: {
                for (int j = 0; j < input_size; j++) {                    
                    forwardPass[i] += w3[j] * input[j];
                }
                break;
            }
            case 4: {
                for (int j = 0; j < input_size; j++) {                    
                    forwardPass[i] += w4[j] * input[j];
                }
                break;
            }
            case 5: {
                for (int j = 0; j < input_size; j++) {                    
                    forwardPass[i] += w5[j] * input[j];
                }
                break;
            }
            case 6: {
                for (int j = 0; j < input_size; j++) {                    
                    forwardPass[i] += w6[j] * input[j];
                }
                break;
            }
            case 7: {
                for (int j = 0; j < input_size; j++) {                    
                    forwardPass[i] += w7[j] * input[j];
                }
                break;
            }
        }
    }
}

void CVCA::softmax() {
    float sum_exp_i = 0;
    for (int i = 0; i < num_vcs; i++) {
        forwardPass[i] = exp(forwardPass[i]);
        sum_exp_i += forwardPass[i];
    }
    for (int i = 0; i < num_vcs; i++) {
        forwardPass[i] /= sum_exp_i;
    }
}

void CVCA::argmax() {
    float maxx = INT_MIN;
    int index = 0;
    for (int j = 0; j < num_vcs; j++) {
        if (maxx < forwardPass[j]) {
            maxx = forwardPass[j];
            index = j;
        }
    }
    c = index;
}

void CVCA::get_e() {
    for (int i = 0; i < num_vcs; i++) {
        if (vcs[i] == 1) {
            e = i;
            break;
        }
    }
}

void CVCA::get_vc_pref() {
    get_w();
    get_e();
    forward_pass();
    softmax();
    argmax();
    backward_pass();
}

void CVCA::process_input() {
    int flitSRC;
    ostringstream TILEID;
    TILEID << tileID;
    string filename = "io.dat/" + TILEID.str() + ".dat"; 
    ifstream stream (filename.c_str(), ios::binary | ios::out);
    stream.read((char *) &flitSRC, sizeof(flitSRC));
    stream.close();
    tileSRC = flitSRC;
    for (int i = 0; i < input_size; i++) {
        if (i == 0) {
            input.push_back(flitSRC);
        } else if (i == 1) {
            input.push_back(tileID);
        } else {
            input.push_back(vcs[i - 1]);
        }
    };
}

UI CVCA::vca(UI _tileID, UI _dir, VI _vcs) {
    ios::sync_with_stdio(false);
    LN = 0.1;
    tileID = _tileID;
    dir = _dir;
    input_size = 10;
    vcs = _vcs;
    num_vcs = NUM_VCS;
    process_input();
    get_vc_pref();
    if (vcs[c] == 0) {
        output = e;
    } else {
        output = c;
    }
    return output;
}