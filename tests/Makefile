# C++ compiler, compiler flags, and include statements

CXX      := g++-10
CXXFLAGS := -Wall -Wpedantic -Wextra -std=c++20 -mavx2 -mavx512f -mfma
CXXTESTS := -I $(HOME)/projects/nola-simd/tests
CXXINCLD := -I $(HOME)/projects/nola-simd/include
CXXOBJTS := test_main.o test_avx2_float.o


all: test.exe


test.exe: $(CXXOBJTS)
	$(CXX) $(CXXFLAGS) $(CXXTESTS) $(CXXINCLD) -o test.exe $(CXXOBJTS)


test_main.o: test_main.cxx
	$(CXX) $(CXXFLAGS) $(CXXTESTS) $(CXXINCLD) -c test_main.cxx

test_avx2_float.o: test_avx2_float.cxx
	$(CXX) $(CXXFLAGS) $(CXXTESTS) $(CXXINCLD) -c test_avx2_float.cxx


run: test.exe
	./test.exe


clean:
	rm *.exe *.o
	clear