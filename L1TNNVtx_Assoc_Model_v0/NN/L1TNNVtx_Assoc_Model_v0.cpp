#include <iostream>

#include "L1TNNVtx_Assoc_Model_v0.h"
#include "parameters.h"


namespace hls4ml_L1TNNVtx_Assoc_Model_v0 {
void L1TNNVtx_Assoc_Model_v0(
    input_t NNvtx_track_association[N_INPUT_1_1],
    result_t layer10_out[N_LAYER_9]
) {

    // hls-fpga-machine-learning insert IO
    #pragma HLS ARRAY_RESHAPE variable=NNvtx_track_association complete dim=0
    #pragma HLS ARRAY_PARTITION variable=layer10_out complete dim=0
    #pragma HLS INTERFACE ap_vld port=NNvtx_track_association,layer10_out 
    #pragma HLS PIPELINE

    // hls-fpga-machine-learning insert load weights
#ifdef __HLS4ML_LOAD_TXT_WEIGHTS__
    static bool loaded_weights = false;
    if (!loaded_weights) {
        nnet::load_weights_from_txt<norm_association_input_scale_t, 4>(s2, "s2.txt");
        nnet::load_weights_from_txt<norm_association_input_bias_t, 4>(b2, "b2.txt");
        nnet::load_weights_from_txt<weight3_t, 80>(w3, "w3.txt");
        nnet::load_weights_from_txt<bias3_t, 20>(b3, "b3.txt");
        nnet::load_weights_from_txt<weight6_t, 400>(w6, "w6.txt");
        nnet::load_weights_from_txt<bias6_t, 20>(b6, "b6.txt");
        nnet::load_weights_from_txt<association_final_weight_t, 20>(w9, "w9.txt");
        nnet::load_weights_from_txt<association_final_bias_t, 1>(b9, "b9.txt");
        loaded_weights = true;    }
#endif
    // ****************************************
    // NETWORK INSTANTIATION
    // ****************************************

    // hls-fpga-machine-learning insert layers

    norm_association_input_result_t layer2_out[N_INPUT_1_1];
    #pragma HLS ARRAY_PARTITION variable=layer2_out complete dim=0
    nnet::normalize<input_t, norm_association_input_result_t, config2>(NNvtx_track_association, layer2_out, s2, b2); // norm_association_input

    association_1_result_t layer3_out[N_LAYER_3];
    #pragma HLS ARRAY_PARTITION variable=layer3_out complete dim=0
    nnet::dense<norm_association_input_result_t, association_1_result_t, config3>(layer2_out, layer3_out, w3, b3); // association_1
#ifdef __HLS4ML_LOAD_TXT_WEIGHTS__
    nnet::save_layer_output<association_1_result_t>(layer3_out, "association_1", N_LAYER_3);
#endif

    layer5_t layer5_out[N_LAYER_3];
    #pragma HLS ARRAY_PARTITION variable=layer5_out complete dim=0
    nnet::relu<association_1_result_t, layer5_t, relu_config5>(layer3_out, layer5_out); // association_1_relu
#ifdef __HLS4ML_LOAD_TXT_WEIGHTS__
    nnet::save_layer_output<layer5_t>(layer5_out, "association_1_relu", N_LAYER_3);
#endif

    association_2_result_t layer6_out[N_LAYER_6];
    #pragma HLS ARRAY_PARTITION variable=layer6_out complete dim=0
    nnet::dense<layer5_t, association_2_result_t, config6>(layer5_out, layer6_out, w6, b6); // association_2
#ifdef __HLS4ML_LOAD_TXT_WEIGHTS__
    nnet::save_layer_output<association_2_result_t>(layer6_out, "association_2", N_LAYER_6);
#endif

    layer8_t layer8_out[N_LAYER_6];
    #pragma HLS ARRAY_PARTITION variable=layer8_out complete dim=0
    nnet::relu<association_2_result_t, layer8_t, relu_config8>(layer6_out, layer8_out); // association_2_relu
#ifdef __HLS4ML_LOAD_TXT_WEIGHTS__
    nnet::save_layer_output<layer8_t>(layer8_out, "association_2_relu", N_LAYER_6);
#endif

    layer9_t layer9_out[N_LAYER_9];
    #pragma HLS ARRAY_PARTITION variable=layer9_out complete dim=0
    nnet::dense<layer8_t, layer9_t, config9>(layer8_out, layer9_out, w9, b9); // association_final
#ifdef __HLS4ML_LOAD_TXT_WEIGHTS__
    nnet::save_layer_output<layer9_t>(layer9_out, "association_final", N_LAYER_9);
#endif

    nnet::linear<layer9_t, result_t, linear_config10>(layer9_out, layer10_out); // association_final_linear

}

}
