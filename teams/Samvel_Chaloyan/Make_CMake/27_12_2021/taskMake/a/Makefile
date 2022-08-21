export CC := g++
export EXE := ./b/:./c/:./c/d/
export SOURCE_FILES := $(wildcard %.cpp)
export OBJ_FILES := $(patsubst %.cpp, %.o, $(SOURCE_FILES))

all: $(EXE) 

$(EXE) : $(OBJ_FILES)
	$(CC) $^ -o $@
	
%.o : $(SOURCE_FILES)
	$(CC) -c $^ -o $@

clean : 
	rm -rf $(OBJ_FILES) $(EXE)

