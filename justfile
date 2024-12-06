CC := 'gcc'
CFLAGS := '-Wall -g'

LDFLAGS := '-lcunit'

BUILD_DIR := './build/'
OUTPUT := 'tests'

build dir:
	rm -r {{ BUILD_DIR }} && mkdir {{ BUILD_DIR }} && {{ CC }} src/{{ dir }}/problems/*.c {{ CFLAGS }} {{ LDFLAGS }} -o {{ BUILD_DIR }}{{ OUTPUT }}

test:
    {{ BUILD_DIR }}{{ OUTPUT }}
mem-check:
	valgrind --leak-check=full --track-origins=yes {{ BUILD_DIR }}{{ OUTPUT }}
