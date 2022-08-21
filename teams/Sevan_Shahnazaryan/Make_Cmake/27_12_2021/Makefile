all: main

main: main.o
	$(MAKE) -C */sum;
	$(MAKE) -C prod;
	$(MAKE) -C */sub;
	$(MAKE) -C div;
	g++ -o main -I . prod/sum/sum.o prod/prod.o div/divi.o div/sub/sub.o main.o

main.o:
	g++ main.cpp -c

clean:
	rm -rf *.o
