CXXFLAGS = -std=c++20 -O2 -fPIC
CPPFLAGS = -DNDEBUG -I../include
LDFLAGS = -L. -Wl,-rpath=${PWD}
LIBS = 

.PHONY: all clean distclean

all: CrankNicolson

CrankNicolson: CrankNicolson.o newton_solver.so
	$(CXX) $(LDFLAGS) test.o -o test $(LIBS)

CrankNicolson.o: CrankNicolson.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c test.cpp

newton_solver.so: Utilities.o
	$(CXX) $(LDFLAGS) -shared -Wl,-soname,liblinearalgebra.so \
	Utilities.o -o liblinearalgebra.so

Utilities.o: Utilities.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c Utilities.cpp

clean:
	$(RM) *.o 

distclean: clean
	$(RM) liblinearalgebra.so test
