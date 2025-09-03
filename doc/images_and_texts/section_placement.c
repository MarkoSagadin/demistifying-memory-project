#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/* Copied from FLASH to RAM at startup */
/* (Initialized global variable stored in .data section) */
uint8_t data_section = 42;

/* Stored in FLASH (read-only memory) */
/* (Constant global variable in .rodata section) */
const uint8_t rodata_section = 42;

/* Zero-initialized global variable stored in RAM */
/* (Uninitialized globals go to .bss section) */
uint8_t bss_section;

int main(int argc, char *argv[])
{
	/* Allocated on stack at runtime */
	/* (Local automatic variable inside main's stack frame) */
	uint8_t stack_var = 42;

	/* Allocated dynamically on heap at runtime */
	uint8_t *heap_section = malloc(sizeof(uint8_t));

	/* String literal stored in FLASH (.rodata section) */
	printf("Hello World\n");

	return 0;
}
