global _start

section .data
arr1 dw 10, -2, 3, 3, 2, -7, 4, -6, 0, 0
ans dw 0

section .bss
arr2 resw 10

section .text
_start:
	mov ecx, 10
	mov esi, arr1
	mov edi, arr2
	xor eax, eax
loop1:
	lodsw
	bt eax, 15
	jae loop2
	not eax
	add eax, 1
loop2:
	stosw
	loop loop1
loop3:
	mov ecx, 10
	mov esi, arr2
	xor ebx, ebx
loop4:
	lodsw
	add ebx, eax
	loop loop4

end:
	mov eax, 4
	mov ebx, 1
	mov ecx, edi
	int 0x80

	mov eax, 1
	mov ebx, 0
	int 0x80
