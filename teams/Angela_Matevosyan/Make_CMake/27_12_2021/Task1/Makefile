compiler_version=-std=c++11

main:
	$(MAKE) -C a;
	$(MAKE) -C a/b;
	$(MAKE) -C a/c;
	$(MAKE) -C a/c/d;
	$(MAKE) -C a/c/d/e;
	g++ $(compiler_version) a/asource.o b/bsourse.o c/csource.o d/dsource.o e/esource.o
	rm -rf a/asource.o b/bsource.o c/csourse.o d/dsource.o e/esource.o
