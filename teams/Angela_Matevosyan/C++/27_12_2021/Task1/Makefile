compiler_version=-std=c++11

main:
	$(MAKE) -C e;
	$(MAKE) -C d;
	$(MAKE) -C c;
	$(MAKE) -C b;
	$(MAKE) -C a;
	g++ $(compiler_version) e/esource.o d/dsourse.o c/csource.o b/bsource.o a/asource.o
