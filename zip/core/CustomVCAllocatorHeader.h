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
    
    UI  c, e, dir,
        tileID,
        tileSRC,
        num_vcs,
        num_flits,
        input_size;
    
    vector<UI> vcs, input;

    vector<F> w0, w1, w2, w3, w4, w5, w6, w7,
        dw0, dw1, dw2, dw3, dw4, dw5, dw6, dw7, forwardPass;
    
    F b0, LN;

    int output;
    
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