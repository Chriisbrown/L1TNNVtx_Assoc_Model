.PHONY: clean

L1TNNVtx_Assoc_Model_v0.so: L1TNNVtx_Assoc_Model_emulator_v0.o L1TNNVtx_Assoc_Model_v0.o
	$(CXX) $(CXXFLAGS) $(LD_FLAGS) -shared $^ -o $@

%.o: NN/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm L1TNNVtx_Assoc_Model_emulator_v0.o L1TNNVtx_Assoc_Model_v0.o L1TNNVtx_Assoc_Model_v0.so
