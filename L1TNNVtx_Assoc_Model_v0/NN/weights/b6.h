//Numpy array shape [20]
//Min -0.031250000000
//Max 0.281250000000
//Number of zeros 3

#ifndef B6_H_
#define B6_H_

namespace L1TNNVtx_Assoc_Model_v0 {
#ifdef __HLS4ML_LOAD_TXT_WEIGHTS__
bias6_t b6[20];
#else
bias6_t b6[20] = {0.250000, 0.000000, 0.281250, 0.218750, 0.218750, 0.000000, 0.218750, -0.031250, -0.015625, -0.015625, 0.203125, 0.218750, 0.203125, 0.156250, -0.031250, 0.031250, 0.000000, 0.203125, 0.187500, 0.015625};

#endif

#endif
}

