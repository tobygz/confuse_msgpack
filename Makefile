all:
	#g++ -g test.c -I. -I./include -L. -lagpack -o test0
	g++ -g test.c ./src/*.c -I. -I./include  -o test0

cpp:
	g++ -g test.cpp ./src/*.c -I. -I./include  -o test0


lib:
	cd ./src && gcc -c ./*.c -I.. -I../include && cd -
	ar rcs libagpack.a ./src/*.o
	ls -l *.a

clean:
	rm -rf ./src/*.o
	rm -rf ./test0
	rm -rf ./*.a
