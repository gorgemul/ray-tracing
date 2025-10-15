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
	gcc -Wall -Wextra -pedantic -lm -Iinclude -o bin/ray-tracing src/*.c

debug:
	gcc -Wall -Wextra -pedantic -g -lm -Iinclude -o bin/ray-tracing src/*.c

run: build
	bin/ray-tracing > assets/ray-tracing.ppm && $(OPEN) assets/ray-tracing.ppm

clean:
	rm -rf bin/* assets/ray-tracing.ppm
