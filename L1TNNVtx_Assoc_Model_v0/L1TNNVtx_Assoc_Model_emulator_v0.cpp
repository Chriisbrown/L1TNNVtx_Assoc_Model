#include "NN/L1TNNVtx_Assoc_Model_v0.h" //include of the top level of HLS model
#include "emulator.h" //include of emulator modeling
#include "NN/nnet_utils/nnet_common.h"
#include <any>
#include <array>
#include <utility>
#include "ap_fixed.h"
#include "ap_int.h"

using namespace hls4ml_L1TNNVtx_Assoc_Model_v0;

class L1TNNVtx_Assoc_Model_emulator_v0 : public hls4mlEmulator::Model{
    private:
        input_t _input[N_INPUT_1_1];
        result_t _result[N_LAYER_9]; // reg out
    public:


        virtual void prepare_input(std::any input)
        {
            input_t* input_p = std::any_cast<input_t*>(input);
            for(int i = 0; i < N_INPUT_1_1; ++i){
               _input[i] = std::any_cast<input_t>(input_p[i]);
            }
        }

        virtual void predict()
        {
            L1TNNVtx_Assoc_Model_v0(_input, _result);
            
        }

        virtual void read_result(std::any result)
        { 
            result_t *result_p = std::any_cast<result_t*>(result);
            for (int i = 0; i < N_LAYER_9; ++i){
                result_p[i] = _result[i];
            }
        }

};

extern "C" hls4mlEmulator::Model* create_model()
{
    return new L1TNNVtx_Assoc_Model_emulator_v0;
}

extern "C" void destroy_model(hls4mlEmulator::Model* m)
{
    delete m;
}
