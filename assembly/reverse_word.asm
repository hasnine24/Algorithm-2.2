.model small
.stack 100h

.data
arr dw 100 dup(?)
nl  db 13,10,'$'

.code
main proc
    mov ax,@data
    mov ds,ax

    ; ---- input count ----
    xor ax,ax
    call indec
    mov cx,ax
    mov bx,ax              ; BX = n

    lea dx,nl
    mov ah,9
    int 21h

    ; ---- input array ----
    mov si,0

input:
    call indec
    mov arr[si],ax         ; WORD -> AX
    add si,2               ; next word
    loop input


    ; ---- n/2 ----
    mov ax,bx              ; AX = n
    xor dx,dx
    mov cl,2
    div cl                 ; AL = n/2

    xor cx,cx
    mov cl,al              ; CX = n/2


    ; ---- reverse ----
    mov si,0               ; left index = 0

    mov di,bx              ; DI = n
    dec di                 ; DI = n-1

    add di,di              ; DI = (n-1)*2
                            ; because WORD = 2 bytes

reverse:

    ; swap arr[SI] and arr[DI]

    mov ax,arr[si]
    mov dx,arr[di]

    mov arr[si],dx
    mov arr[di],ax

    add si,2               ; next word from left
    sub di,2               ; previous word from right

    loop reverse
    
    mov cx,bx
    mov si,0
    print:
    mov ax,arr[si] 
    call outdec
    inc si
    inc si
    loop print

    mov ah,4ch
    int 21h

main endp

include indec.asm 
include outdec.asm
end main