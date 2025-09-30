build:
	gcc -Wall -Wextra -pedantic -o ./ray-tracing main.c color.c vec3.c

run: build
	./ray-tracing

clean:
	rm *.ppm ray-tracing
