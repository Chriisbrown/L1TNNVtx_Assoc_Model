//Numpy array shape [20]
//Min -0.015625000000
//Max 0.375000000000
//Number of zeros 8

#ifndef B3_H_
#define B3_H_

namespace hls4ml_L1TNNVtx_Assoc_Model_v0 {
#ifdef __HLS4ML_LOAD_TXT_WEIGHTS__
bias3_t b3[20];
#else
bias3_t b3[20] = {0.000000, 0.359375, 0.375000, 0.046875, 0.000000, 0.015625, 0.000000, 0.343750, 0.031250, 0.000000, 0.000000, 0.000000, -0.015625, -0.015625, -0.015625, 0.000000, -0.015625, -0.015625, 0.000000, 0.156250};

#endif

#endif
}
