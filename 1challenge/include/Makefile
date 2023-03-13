.PHONY: all clean distclean

all: newton_solver.so

newton_solver.so: newton_solver.o
	g++ newton_solver.o -o newton_solver.so -shared

newton_solver.o: NewtonSolver/*.cpp
	g++ NewtonSolver/*.cpp -c -I${mkEigenInc} -fPIC

clean:
	$(RM) *.o

distclean: clean
	$(RM) newton_solver.so

