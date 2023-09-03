section .data
hello_message db 'Hello, World!',10,0  ; null-terminated string to be displayed

section .text
global _start  ; Entry point for the program

_start:
    ; Write hello_message to stdout (file descriptor 1)
    mov eax, 4
    mov ebx, 1
    mov ecx, hello_message
    mov edx, 14
    int 0x80

    ; Exit program (exit code 0)
    mov eax, 1
    xor ebx, ebx  ; Return code 0
    int 0x80
