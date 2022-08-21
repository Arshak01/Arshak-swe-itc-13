export CC := g++
export EXE := calc
export SOURCE_FILES := $(wildcard *.cpp)
export OBJ_FILES := $(patsubst %.cpp, %.o, $(SOURCE_FILES))
export SUM := ./sum/
export SUB := ./sub/
export DIV := ./div/
export MOD := ./mod/
export PROD := ./prod/

$(EXE) : $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $(EXE)

$(OBJ_FILES) : $(SOURCE_FILES) 
	$(CC) -c $^ -o $@
	cd $(SUM) && $(make)
	cd $(SUB) && $(make)
	cd $(DIV) && $(make)
	cd $(MOD) && $(make)
	cd $(PROD) && $(make)

clean : 
	rm -f $(OBJ_FILES) $(EXE)


