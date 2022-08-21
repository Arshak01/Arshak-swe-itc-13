export CC := g++
export EXE := sub
export SOURCE_FILES := $(wildcard *.cpp)
export OBJ_FILES := $(patsubst %.cpp, %.o, $(SOURCE_FILES))

$(EXE) : $(OBJ_FILES)
	$(CC) $^ -o $@
	
$(OBJ_FILES) : $(SOURCE_FILES) 
	$(CC) -c $^ -o $@

clean : 
	rm -f $(OBJ_FILES) $(EXE)

