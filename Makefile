all: comp

comp: main.c stackArray.c stackList.c
	gcc main.c stackArray.c -o mainArray -std=c99
	gcc main.c stackList.c -o mainList -std=c99

runList: comp
	./mainList

runArray: comp
	./mainArray

valList: mainList
	valgrind --leak-check=full ./mainList

valArray: mainArray
	valgrind --leak-check=full ./mainArray