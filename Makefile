make:
	gcc arena.c -o arena

clean:
	rm arena

run:
	gcc arena.c -o arena && ./arena