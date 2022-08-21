E:=$(~/Desktop/swe-itc-13-homeworks/Margarita_Hambaryan/Make_Cmake/27_12_2021/a/c/d/e)

subdir: $(E)
	$(MAKE) -c $(E)


mult: mult.o
	g++ mult.o -o mult

mult.o: mult.cpp
	g++ -c mult.cpp

clean:
	rm -rf *.o mult
