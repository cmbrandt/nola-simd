# C++ compiler, compiler flags, and include statements

CXX      := g++-10
CXXFLAGS := -Wall -Wpedantic -Wextra -std=c++20 -mavx2 -mavx512f
CXXINCLD := -I $(HOME)/projects/nola-simd/tests
STDINCLD := -I $(HOME)/projects/nola-simd/include
TESTOBJS := main.o avx2_float.o# test_functional.o test_iterator.o test_numeric.o test_utility.o


all: test.exe


test.exe: $(TESTOBJS)
	$(CXX) $(CXXFLAGS) $(CXXINCLD) $(STDINCLD) -o test.exe $(TESTOBJS)


main.o: main.cxx
	$(CXX) $(CXXFLAGS) $(CXXINCLD) $(STDINCLD) -c main.cxx

avx2_float.o: avx2_float.cxx
	$(CXX) $(CXXFLAGS) $(CXXINCLD) $(STDINCLD) -c avx2_float.cxx

#test_functional.o: test_functional.cxx
#	$(CXX) $(CXXFLAGS) $(CXXINCLD) $(STDINCLD) -c test_functional.cxx

#test_iterator.o: test_iterator.cxx
#	$(CXX) $(CXXFLAGS) $(CXXINCLD) $(STDINCLD) -c test_iterator.cxx

#test_numeric.o: test_numeric.cxx
#	$(CXX) $(CXXFLAGS) $(CXXINCLD) $(STDINCLD) -c test_numeric.cxx

#test_utility.o: test_utility.cxx
#	$(CXX) $(CXXFLAGS) $(CXXINCLD) $(STDINCLD) -c test_utility.cxx


run: test.exe
	./test.exe


clean:
	rm *.exe *.o
	clear