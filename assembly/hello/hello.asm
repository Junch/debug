; Listing: asm functions.asm

.code

; int FindSmallest(int* arr, int count)
FindSmallest proc
	mov eax, 7fffffffh ; Assume the smallest is maxium int
	cmp edx, 0         ; Is the count <= 0 ?
	jle Finished       ; If yes get out of here

MainLoop:
	cmp dword ptr[rcx], eax
	cmovl eax, dword ptr[rcx] ; If the new int is smaller update our smallest
	add rcx, 4                ; Mov RCX to point to the next int

	dec edx      ; Decrement the counter
	jnz MainLoop ; Loop if there's more

Finished:
	ret
FindSmallest endp

end