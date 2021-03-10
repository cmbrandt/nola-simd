# C++ compiler, compiler flags, and include statements

CXX      := g++-10
CXXFLAGS := -Wall -Wpedantic -Wextra -std=c++20 -mavx2 -mavx512f
CXXINCLD := -I $(HOME)/projects/nola-simd/tests
STDINCLD := -I $(HOME)/projects/nola-simd/include
TESTOBJS := test_main.o test_avx2_float.o


all: test.exe


test.exe: $(TESTOBJS)
	$(CXX) $(CXXFLAGS) $(CXXINCLD) $(STDINCLD) -o test.exe $(TESTOBJS)


test_main.o: test_main.cxx
	$(CXX) $(CXXFLAGS) $(CXXINCLD) $(STDINCLD) -c test_main.cxx

test_avx2_float.o: test_avx2_float.cxx
	$(CXX) $(CXXFLAGS) $(CXXINCLD) $(STDINCLD) -c test_avx2_float.cxx

#test_avx2_double.o: test_avx2_double.cxx
#	$(CXX) $(CXXFLAGS) $(CXXINCLD) $(STDINCLD) -c test_avx2_double.cxx


run: test.exe
	./test.exe


clean:
	rm *.exe *.o
	clear