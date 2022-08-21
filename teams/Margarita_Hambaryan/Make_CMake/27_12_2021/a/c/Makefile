D:=$(~/Desktop/swe-itc-13-homeworks/Margarita_Hambaryan/Make_Cmake/27_12_2021/a/c/d)

subdir: $(D)
	$(MAKE) -c $(D)

sub: sub.o
	g++ sub.o -o sub

sub.o: sub.cpp
	g++ -c sub.cpp 

clean:
	rm -rf *.o sub
