#ifndef NNVTX_ASSOC_H_
#define NNVTX_ASSOC_H_

#include "ap_fixed.h"
#include "ap_int.h"
#include "hls_stream.h"

#include "defines.h"

namespace L1TNNVtx_Assoc_Model_v0 {
// Prototype of top level function for C-synthesis
void NNvtx_assoc(
    input_t NNvtx_track_association[N_INPUT_1_1],
    result_t layer10_out[N_LAYER_9]
);

}
#endif
