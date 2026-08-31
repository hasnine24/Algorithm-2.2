.model small
.stack 100h
.data 
arr1 db 11,12,13,14,15
arr db 100 dup(?)
nl  db 13,10,'$'
.code
main proc
    mov ax,@data
    mov ds,ax

    ; ---- input count ----
    xor ax,ax
    call indec
    mov cx,ax
    mov bx,ax          ; bx = n (keep a copy)
    lea dx,nl
    mov ah,9
    int 21h

    ; ---- input array ----
    mov si,0
input:
    call indec
    mov arr[si],al
    inc si
    loop input

    ; ---- reverse array using DIV ----
    mov ax,bx           ; ax = n
    xor dx,dx            ; dx = 0 (dividend high part must be cleared)
    mov cl,2
    div cl                 ; al = n/2 (quotient), ah = n%2 (remainder, ignored)
    xor cx,cx
    mov cl,al             ; cx = n/2  ? this many swaps needed

    mov si,0             ; si = left index, starts at 0
    mov di,bx              ; di = n
    dec di                   ; di = n-1 (right index, starts at last element)

reverse:
    mov al,arr[si]         ; swap arr[si] and arr[di]
    mov ah,arr[di]
    mov arr[si],ah
    mov arr[di],al

    inc si                  ; move left index forward
    dec di                    ; move right index backward
    loop reverse                ; repeat n/2 times

    ; ---- array is now reversed in arr[] ----

    mov ah,4ch
    int 21h
main endp
include indec.asm
end main