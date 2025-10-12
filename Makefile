build:
	gcc -Wall -Wextra -pedantic -o ./ray-tracing *.c -lm

debug:
	gcc -Wall -Wextra -pedantic -g -o ./ray-tracing *.c -lm

run: build
	./ray-tracing > ray-tracing.ppm && open ray-tracing.ppm

clean:
	rm -rf *.ppm ray-tracing*
