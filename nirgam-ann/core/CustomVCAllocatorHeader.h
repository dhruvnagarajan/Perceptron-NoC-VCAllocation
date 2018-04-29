#include <bits/stdc++.h>
#include "Log.h"
#include "flit.h"
using namespace std;

#define UI unsigned int
#define F float
#define VI vector<UI>
#define VF vector<F>
#define VVF vector<vector<F> >

class CVCA {
    
    UI  dir,
        tileID,
        num_vcs,
        num_flits,
        input_size;
    
    F LN;

    vector<int> c, e;
    
    vector<UI> vcs;

    vector<pair<UI, flit> > flits;

    vector<UI> w, w0, w1, w2, w3, w4, w5, w6, w7, dw, forwardPass; // FLOAT W

    UI wi, input, output, numvclive, numvcdead;

    vector<vector<UI> > vcper;

    int vcarr[NUM_VCS];

    bool isAnyVCDead;
    
    public:

    void get_c();
    
    void get_e();

    void get_dw();

    void get_w();

    void set_w();

    void update_w();

    void backward_pass();

    void backtrack(int arr[], int left, int right);

    void forward_pass();

    void softmax();

    void argmax();

    void process_input();

    void get_vc_pref();

    UI vca(UI _tileID, UI _dir, VI vcs);
};