//Numpy array shape [4]
//Min 0.000000000000
//Max 0.000000000000
//Number of zeros 4

#ifndef B2_H_
#define B2_H_

namespace L1TNNVtx_Assoc_Model_v0 {
#ifdef __HLS4ML_LOAD_TXT_WEIGHTS__
norm_association_input_bias_t b2[4];
#else
norm_association_input_bias_t b2[4] = {0.0000000000000, 0.0000000000000, 0.0000000000000, 0.0000000000000};

#endif

#endif
}

