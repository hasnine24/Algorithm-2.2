.model small
.stack 100h
.data
n     dw 3
avec  dw 2, 3, 4      ; a1, a2, a3 -- ????? ???????? value ????
bvec  dw 5, 6, 7      ; b1, b2, b3 -- ????? ???????? value ????
result dw ?
nl    db 13,10,'$'
.code
main proc
    mov ax,@data
    mov ds,ax

    mov cx, n           ; R0 = N (loop counter)
    lea si, avec        ; R1 = pointer to AVEC
    lea di, bvec        ; R2 = pointer to BVEC
    xor bx, bx           ; R4 = 0 (CLEAR R4, accumulator/sum)

loop_dot:
    mov ax, [di]         ; R3 = (R2)+   -> load from BVEC, pointer auto-increments
    add di, 2               ; word size = 2 bytes, so manually increment pointer

    mov dx, [si]           ; temp = (R1)+  -> load from AVEC
    add si, 2                ; increment AVEC pointer

    mul dx                    ; MUL (R1)+, R3  ->  AX = AX * DX  (R3 = R3 * (R1))
                                ; result of MUL goes into DX:AX, we only need AX (low word)

    add bx, ax                  ; ADD R3, R4  -> R4 = R4 + R3 (accumulate sum)

    loop loop_dot                 ; DEC R0 + Branch>0 Loop (combined in one instruction)

    mov result, bx                  ; store final dot product

    ; ---- print result ----
    mov ax, result
    call outdec
    lea dx, nl
    mov ah,9
    int 21h

    mov ah,4ch
    int 21h
main endp
include outdec.asm
end main