sum:=./c
sub:=./c/d
mul:=./c/d/e
divv:=./b


main: main.o
	$(MAKE) -C $(sum)
	$(MAKE) -C $(sub)
	$(MAKE) -C $(mul)
	$(MAKE) -C $(divv)
	g++ main.o $(sum)/sum.o $(sub)/sub.o $(mul)/mul.o $(divv)/divv.o -o main
main.o: main.cpp
	g++ -c main.cpp
clean:
	rm -rf *.o
