ifeq ($(shell uname -s),Linux)
    ifneq ($(shell which xdg-open 2>/dev/null),)
        OPEN = xdg-open
    else
        OPEN = echo "xdg-open not found. Please install it or open manually:"
    endif
else ifeq ($(shell uname -s),Darwin)
    OPEN = open
else
    OPEN = echo "Unsupported OS. Please open manually:"
endif

build:
	gcc -Wall -Wextra -pedantic -o ./ray-tracing *.c -lm

debug:
	gcc -Wall -Wextra -pedantic -g -o ./ray-tracing *.c -lm

run: build
	./ray-tracing > ray-tracing.ppm && $(OPEN) ray-tracing.ppm

clean:
	rm -rf *.ppm ray-tracing*
