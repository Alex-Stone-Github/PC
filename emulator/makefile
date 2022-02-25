all: bin/emulator

bin/emulator: build/emulator.o build/cpu.o
	gcc $^ -o $@

build/%.o: src/%.c
	gcc -c $^ -o $@

run:
	./bin/emulator

clean:
	rm bin/* build/*
