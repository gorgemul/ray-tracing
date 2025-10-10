build:
	gcc -Wall -Wextra -pedantic -o ./ray-tracing *.c -lm

debug:
	gcc -Wall -Wextra -pedantic -g -o ./ray-tracing *.c -lm

run: build
	./ray-tracing

clean:
	rm -rf *.ppm ray-tracing*
