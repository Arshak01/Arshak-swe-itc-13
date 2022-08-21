
export EXE := d
export SOURCE_FILES := $(wildcard %.cpp)
export OBJ_FILES := $(patsubst %.cpp, %.o, $(SOURCE_FILES))

$(EXE) : $(OBJ_FILES)
	g++ $^ -o $@
	
%.o : $(SOURCE_FILES)
	g++ -c $^ -o $@

clean : 
	rm -rf $(OBJ_FILES) $(EXE)

