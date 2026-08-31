include emu8086.inc

.model small
.stack 100h

.data
    msg1 db "Enter a lowercase letter: $"
    msg2 db 13,10,"The uppercase letter: $"

.code
main proc

    mov ax, @data
    mov ds, ax

    ; Show input message
    lea dx, msg1
    mov ah, 9
    int 21h

    ; Take input
    mov ah, 1
    int 21h
    mov bl, al

    ; Convert lowercase to uppercase
    sub bl, 20h

    ; Show output message
    lea dx, msg2
    mov ah, 9
    int 21h

    ; Print uppercase letter
    mov dl, bl
    mov ah, 2
    int 21h

    ; Exit
    mov ah, 4ch
    int 21h

main endp
end main