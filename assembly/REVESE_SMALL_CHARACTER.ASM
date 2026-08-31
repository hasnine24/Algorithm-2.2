.model small
.stack 100h

.data
    msg1 db "Enter characters: $"
    msg2 db 13,10,"Reverse uppercase: $"

.code
main proc

    mov ax, @data
    mov ds, ax

    ; Display message
    lea dx, msg1
    mov ah, 9
    int 21h

    ; Take 5 characters
    mov cx, 10

input:
    mov ah, 1
    int 21h             ; input -> AL

    sub al, 20h         ; lowercase -> uppercase

    mov ah, 0
    push ax             ; push character into stack

    loop input

    ; Display message
    lea dx, msg2
    mov ah, 9
    int 21h

    ; Pop and print
    mov cx, 10

output:
    pop dx              ; DL = character
    mov ah, 2
    int 21h

    loop output

    ; Exit
    mov ah, 4ch
    int 21h

main endp
end main