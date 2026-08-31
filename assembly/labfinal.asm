.model small
.stack 100h

.data
msg1 db "Enter n: $"
msg2 db 13,10,"Sum = $"
msg3 db 13,10,"Odd$"
msg4 db 13,10,"Even$"

flag db ?

.code
main proc

    mov ax,@data
    mov ds,ax

    ; Input n
    lea dx,msg1
    mov ah,9
    int 21h

    call INDEC
    mov cx,ax          ; CX = n

    xor bp,bp          ; BP = sum
    mov bx,1           ; BX = current number

SUM_LOOP:

    ; Calculate BX^3

    mov ax,bx
    mul bx             ; AX = BX^2

    mov si,ax

    mov ax,si
    mul bx             ; AX = BX^3

    add bp,ax          ; sum = sum + cube

    inc bx
    loop SUM_LOOP

    ; Final sum
    mov ax,bp

    ; Check odd/even BEFORE OUTDEC
    mov si,ax

    ror al,1           ; LSB -> CF

    jc ODD

;----------------
; EVEN
;----------------
EVEN:
    mov flag,00h

    mov ax,si
    lea dx,msg2
    mov ah,9
    int 21h

    mov ax,si
    call OUTDEC

    lea dx,msg4
    mov ah,9
    int 21h

    jmp PROGRAM_END

;----------------
; ODD
;----------------
ODD:
    mov flag,01h

    mov ax,si
    lea dx,msg2
    mov ah,9
    int 21h

    mov ax,si
    call OUTDEC

    lea dx,msg3
    mov ah,9
    int 21h

PROGRAM_END:
    mov ah,4ch
    int 21h

main endp

include indec.asm
include outdec.asm

end main