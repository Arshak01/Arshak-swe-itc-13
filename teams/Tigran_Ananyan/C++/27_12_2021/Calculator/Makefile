export EXECUTABLE := main
export SOURCE_FILES := $(wildcard *.cpp)
export OP_SOURCE_FILES := $(wildcard **/*.cpp)
export NUM_SOURCE_FILES := $(wildcard **/**/*.cpp)
export CALC_SOURCE_FILES := $(wildcard **/**/**/*.cpp)
export OBJ_FILES := $(patsubst %.cpp, %.o, $(SOURCE_FILES))
export OP_OBJ_FILES := $(patsubst %.cpp, %.o, $(OP_SOURCE_FILES))
export NUM_OBJ_FILES := $(patsubst %.cpp, %.o, $(NUM_SOURCE_FILES))
export CALC_OBJ_FILES := $(patsubst %.cpp, %.o, $(CALC_SOURCE_FILES))

$(EXECUTABLE) : $(OBJ_FILES) $(OP_OBJ_FILES) $(NUM_OBJ_FILES) $(CALC_OBJ_FILES)

	$(CXX) $^ -o $@

%.o : %.cpp
	$(CXX) -c $^ -o $@

clean :
	$(RM) $(EXECUTABLE) $(OBJ_FILES) $(OP_OBJ_FILES) $(NUM_OBJ_FILES) $(CALC_OBJ_FILES)
