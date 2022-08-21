main :  main.o ./b/divis.o ./c/mult.o ./c/d/sub.o ./c/d/e/sum.o
	g++ main.o ./b/divis.o ./c/mult.o ./c/d/sub.o ./c/d/e/sum.o -o main

main.o : main.cpp
	g++ -c main.cpp -o main.o

divis.o : ./b/makefile
	make -C ./b/

mult.o : ./c/makefile
	make -C ./c/

clean :
	rm main.o main