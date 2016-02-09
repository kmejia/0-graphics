all: pix.c
	gcc pix.c
run: a.out
	./a.out
	display pic.ppm
clean:
	rm -r pic.ppm
	rm -r a.out
