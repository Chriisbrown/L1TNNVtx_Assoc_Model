#ifndef DEFINES_H_
#define DEFINES_H_

#include "ap_fixed.h"
#include "ap_int.h"
#include "nnet_utils/nnet_types.h"
#include <cstddef>
#include <cstdio>

namespace hls4ml_L1TNNVtx_Assoc_Model_v0 {

// hls-fpga-machine-learning insert numbers
#define N_INPUT_1_1 4
#define N_LAYER_3 20
#define N_LAYER_6 20
#define N_LAYER_9 1


// hls-fpga-machine-learning insert layer-precision
typedef ap_ufixed<22,9> input_t;
typedef ap_fixed<45,19> norm_association_input_result_t;
typedef ap_fixed<22,9> norm_association_input_scale_t;
typedef ap_fixed<22,9> norm_association_input_bias_t;
typedef ap_fixed<22,9> model_default_t;
typedef ap_fixed<56,24> association_1_result_t;
typedef ap_fixed<8,2> weight3_t;
typedef ap_fixed<8,2> bias3_t;
typedef ap_uint<1> layer3_index;
typedef ap_ufixed<8,1,AP_RND_CONV,AP_SAT,0> layer5_t;
typedef ap_fixed<18,8> association_1_relu_table_t;
typedef ap_fixed<22,9> association_2_result_t;
typedef ap_fixed<8,2> weight6_t;
typedef ap_fixed<8,2> bias6_t;
typedef ap_uint<1> layer6_index;
typedef ap_ufixed<8,1,AP_RND_CONV,AP_SAT,0> layer8_t;
typedef ap_fixed<18,8> association_2_relu_table_t;
typedef ap_fixed<12,4> layer9_t;
typedef ap_fixed<32,1> association_final_weight_t;
typedef ap_fixed<6,1> association_final_bias_t;
typedef ap_uint<1> layer9_index;
typedef ap_fixed<22,9> result_t;
typedef ap_fixed<18,8> association_final_linear_table_t;


#endif
}
