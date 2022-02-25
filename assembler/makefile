bin/asem: build/asem.o build/lexer.o
	gcc $^ -o $@

build/%.o: src/%.c
	gcc -c $^ -o $@

run:
	./bin/asem

clean:
	rm bin/* build/*

