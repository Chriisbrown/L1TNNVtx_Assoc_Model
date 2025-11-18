#ifndef L1TNNVTX_ASSOC_MODEL_V0_H_
#define L1TNNVTX_ASSOC_MODEL_V0_H_

#include "ap_fixed.h"
#include "ap_int.h"
#include "hls_stream.h"

#include "defines.h"


// Prototype of top level function for C-synthesis
namespace L1TNNVtx_Assoc_Model_v0 {
void L1TNNVtx_Assoc_Model_v0(
    input_t NNvtx_track_association[N_INPUT_1_1],
    result_t layer10_out[N_LAYER_9]
);


}


#endif
