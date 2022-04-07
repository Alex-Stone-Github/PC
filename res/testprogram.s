//My goal is simple  I want to create a way to multiply two numbers in the computer


// read from io 1 and 2 
// the put the inputs into registers a  and b
put 1;
write address;
step; // 0
read io;
write a;
step; // 1
put 2;
write address;
step; // 2
read io;
write a;
step; // 3

// while loop 
// run the following decrement code while the b register is not zero
read b;
write d;
step; // 4
if; // check if b/d is zero
// jmp past the loop code
put 13; // just happens to be instruction 13
write instruction_counter;
step; // 5

// decrement from the b address
read b;
write processor_a;
step; // 6
put 1;
write processor_b;
step; // 7
set sub;
read processor;
write b;
step; // 8
// add a to c
read c;
write processor_a;
step; // 9
read a;
write processor_b;
step; // 10
read processor;
write c;
step; // 11
// jump back to the beginning of the loop
put 4;
write instruction_counter;
step; // 12
// end of the loop
// write c to io
put 4;
write address;
step; // 13
write io;
read c;
step; // 14
