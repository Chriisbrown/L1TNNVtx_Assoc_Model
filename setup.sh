TARGET=L1TNNVtx_Assoc_Model_v0/NN
mkdir -p $TARGET
SRC=firmware

cp -r $SRC/defines.h ${TARGET}
sed -i "s/#include <cstdio>/#include <cstdio>\n\nnamespace hls4ml_L1TNNVtx_Assoc_Model_v0 {/" ${TARGET}/defines.h
echo '}' >> ${TARGET}/defines.h

cp $SRC/L1TNNVtx_Assoc_Model_v0.cpp   ${TARGET}/L1TNNVtx_Assoc_Model_v0.cpp
sed -i "s/void L1TNNVtx_Assoc_Model_v0(/namespace hls4ml_L1TNNVtx_Assoc_Model_v0 {\nvoid L1TNNVtx_Assoc_Model_v0(/" ${TARGET}/L1TNNVtx_Assoc_Model_v0.cpp
echo '}' >> ${TARGET}/L1TNNVtx_Assoc_Model_v0.cpp

cp    $SRC/L1TNNVtx_Assoc_Model_v0.h   ${TARGET}/L1TNNVtx_Assoc_Model_v0.h
sed -i "s/void L1TNNVtx_Assoc_Model_v0(/namespace hls4ml_L1TNNVtx_Assoc_Model_v0 {\nvoid L1TNNVtx_Assoc_Model_v0(/" ${TARGET}/L1TNNVtx_Assoc_Model_v0.h
sed -i "s/#endif/}\n\n#endif/" ${TARGET}/L1TNNVtx_Assoc_Model_v0.h

cp -r $SRC/nnet_utils ${TARGET}

cp    $SRC/parameters.h ${TARGET}
sed -i "s,// hls-fpga-machine-learning insert layer-config,namespace hls4ml_L1TNNVtx_Assoc_Model_v0 {\n// hls-fpga-machine-learning insert layer-config," ${TARGET}/parameters.h
sed -i "s/#endif/}\n\n#endif/" ${TARGET}/parameters.h

cp -r $SRC/weights ${TARGET}
for filename in ${TARGET}/weights/*.h; do
    echo $filename
    sed -i '8 a namespace hls4ml_L1TNNVtx_Assoc_Model_v0 {' $filename
    echo '}' >> $filename
done

rm ${TARGET}/weights/*.txt

# change the way the weights are read
find ./${TARGET} \( -type d -name .git -prune \) -o -type f -print0 | xargs -0 sed -i 's/#ifndef __SYNTHESIS__/#ifdef __HLS4ML_LOAD_TXT_WEIGHTS__/'
