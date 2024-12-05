# add your source files here:
SRC := src/lexer_preprocessor.c src/program_runner.c src/operations.c src/stack.c src/stackdata.c src/list.c src/tests.c

# add your header files here
INC := inc/lexer_preprocessor.h inc/program_runner.h inc/operations.h inc/stack.h inc/stackdata.h inc/list.h inc/tests.h
# FLAGS := -g

8inf: 8inf.c $(SRC) $(INC)
	gcc $(FLAGS) -Iinc 8inf.c $(SRC) -o 8inf

clean:
	rm 8inf
	rm 8inf_tests

.PHONY: clean

# Script shorcuts
hello: 8inf
	./8inf scripts/hello_world.8f

comp: 8inf
	./8inf scripts/comparisons_and_logicals.8f

int: 8inf
	./8inf scripts/integer_ops.8f

loop: 8inf
	./8inf scripts/loop.8f

goto: 8inf
	./8inf scripts/goto.8f

# Test
test: 8inf_tests.c $(SRC) $(INC) 
	gcc $(FLAGS) -Iinc 8inf_tests.c $(SRC) -o 8inf_tests 
	./8inf_tests 