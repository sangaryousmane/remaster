global main
extern printf

section .data
    format db 'Hello, Holberton', 10, 0

section .text
main:
    mov  edi, format  ; move the address of the format string to the edi register
    xor  eax, eax     ; set eax to 0
    call printf       ; call the printf function with the format string
    xor  eax, eax     ; set eax to 0 (the return value of the program)
    ret
