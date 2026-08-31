.model small
.stack 100h

.data
arr dw 10, 20, 30, 40, 50
n   dw 5

.code
main proc
    mov ax, @data
    mov ds, ax

    ; SI = address of first element
    lea si, arr

    ; DI = address of last element
    lea di, arr
    add di, 8          ; last element offset = 4 × 2

    ; number of swaps = n/2
    mov cx, n
    shr cx, 1

reverse:

    ; swap [SI] and [DI]

    mov ax, [si]
    mov bx, [di]

    mov [si], bx
    mov [di], ax

    ; move pointers
    add si, 2
    sub di, 2

    loop reverse

    mov ah, 4ch
    int 21h

main endp
end mainmain
