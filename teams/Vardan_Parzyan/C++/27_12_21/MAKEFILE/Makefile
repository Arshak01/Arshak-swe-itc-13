compiler_version=-std=c++11

main:
	$(MAKE) -C bajanac
	$(MAKE) -C bazmapatkac 
	$(MAKE) -C gumarac
	$(MAKE) -C hanac 
	$(MAKE) -C mainCalc	
	g++ $(compiler_version) bajanac/bajanac.o bazmapatkac/bazmapatkac.o gumarac/gumarac.o hanac/hanac.o mainCalc/mainCalc.o
	rm -rf bajanac/bajanac.o bazmapatkac/bazmapatkac.o gumarac/gumarac.o hanac/hanac.o mainCalc/mainCalc.o
