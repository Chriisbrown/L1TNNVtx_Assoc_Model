//Numpy array shape [4]
//Min 0.999500393867
//Max 0.999500393867
//Number of zeros 0

#ifndef S2_H_
#define S2_H_

namespace L1TNNVtx_Assoc_Model_v0 {
#ifdef __HLS4ML_LOAD_TXT_WEIGHTS__
norm_association_input_scale_t s2[4];
#else
norm_association_input_scale_t s2[4] = {0.9995003938675, 0.9995003938675, 0.9995003938675, 0.9995003938675};

#endif

#endif
}

