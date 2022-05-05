#include <iostream>
#include <conio.h>

void asm_main
(
	unsigned char source_byte_arg
)
{
	unsigned char source_byte = source_byte_arg;
	int result = 0;

	_asm
	{
		; init_prog:
	xor eax, eax
		mov al, source_byte
		; start_prog:

	; exp_1:
	and al, 200; 0b11001000
		cmp al, 200
		jne exp_2
		mov result, 1

		exp_2:
	and al, 86; 0b01010110
		cmp al, 86
		jne exp_3
		mov result, 1

		exp_3:
	and al, 197; 0b11000101
		cmp al, 197
		jne end_prog
		mov result, 1

		end_prog:

	}

	std::cout << result << std::endl;
}

int main()
{
	unsigned char source_byte = 0x00;

	while (true)	
	{
		asm_main(source_byte);
		if (std::cin.get() == 113)
		{
			break;
		}
	}
}
