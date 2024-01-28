INCLUDE=-Iinclude/opencv4
LIB=-Llib -lopencv_core -lopencv_imgcodecs -lopencv_imgproc -lopencv_highgui

build:
	cc -std=c++20 -lc++ -g -O0 src/main.cpp $(INCLUDE) $(LIB) -Wno-deprecated-anon-enum-enum-conversion -o main.o
run:
	./main.o
clean:
	rm -rf *.o*
