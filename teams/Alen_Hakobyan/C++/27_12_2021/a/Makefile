sum:=./b
sub:=./c
mult:=./c/d
divide:=./c/d/e

main: calculator.o
	$(MAKE) -C $(sum)
	$(MAKE) -C $(sub)
	$(MAKE) -C $(mult)
	$(MAKE) -C $(divide)
	g++ calculator.o $(sum)/sum.o $(sub)/sub.o $(mult)/mult.o $(divide)/divide.o -o main
calculator.o: calculator.cpp 
	g++ -c calculator.cpp

clean:
	rm -rf *.o
