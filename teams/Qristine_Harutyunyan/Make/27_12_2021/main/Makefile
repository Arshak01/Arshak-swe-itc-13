main:  main.o ./sum_sub/sub/sub.o ./sum_sub/sum.o ./mult_div/div/div.o ./mult_div/mult.o
	g++ main.o ./sum_sub/sub/sub.o ./sum_sub/sum.o ./mult_div/div/div.o ./mult_div/mult.o -o main

main.o: main.cpp
	g++ -c main.cpp -o main.o

sub.o: ./sum_sub/sub/Makefile
	make -C ./sum_sub/sub/

sum.o: ./sum_sub/Makefile
	make -C ./sum_sub/

div.o: ./mult_div/div/Makefile
	make -C ./mult_div/div/

mult.o: ./mult_div/Makefile
	make -C ./mult_div/		
