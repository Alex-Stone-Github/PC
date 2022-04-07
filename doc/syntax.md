# Syntax
1. // COMMENTING                              = comment
2. /* COMMENTING */                           = comment
3. if;                                        = only execute this instruction if register d is 0 
4. write [some Writable];                     = output something on the bus
5. read [some Readable];                      = have some component read from the bus
6. put [some number to put on the bus];       = put a number on the bus
7. set [some setting]                         = change some setting on the processor for that instruction
7. step;                                      = wrap up the instruction and begin the next one

## Readables
* processer
* a
* b
* c
* d
* io
* ram
* address


## Writables
* io
* ram
* a
* b
* c
* d
* processor_a
* processor_b
* instruction_counter

## Settings
sub = setts the processor mode to subtraction

## Examples
```assembly
// write the number 3 to the first io port
put 0;
write address;
step;
put 3;
write io;
step;
```
```assembly 
// put the number 67 into all of the general purpose registers
put 67;
write a;
write b;
write c;
write d;
step;
```
