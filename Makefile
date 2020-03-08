output: main.o calculateMines.o creation.o emptybuff.o randomfill.o
	gcc main.o calculateMines.o creation.o emptybuff.o randomfill.o -o minesweaper

main.o: main.c
	gcc -c main.c

calculateMines.o: calculateMines.h calculateMines.c
	gcc -c calculateMines.c

creation.o: creation.h creation.c
	gcc -c creation.c

emptybuff.o: emptybuff.h emptybuff.c
	gcc -c emptybuff.c

randomfill.o: randomfill.h randomfill.c
	gcc -c randomfill.c

clean:
	rm *.o minesweaper
