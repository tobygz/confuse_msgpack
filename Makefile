all:
	gcc test.c -I. -I./include -L. -lagpack -o test0

lib:
	cd ./src && gcc -c ./*.c -I.. -I../include && cd -
	ar rcs libagpack.a ./src/*.o
	ls -l *.a

clean:
	rm -rf ./src/*.o
	rm -rf ./test0
	rm -rf ./*.a
