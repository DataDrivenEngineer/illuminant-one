INCLUDE=-Iinclude/opencv4
LIB=-Llib -lopencv_core -lopencv_imgcodecs

build:
	cc -std=c++20 -lc++ -g -O0 src/main.cpp $(INCLUDE) $(LIB) -o main.o
run:
	./main.o
clean:
	rm -rf *.o*
