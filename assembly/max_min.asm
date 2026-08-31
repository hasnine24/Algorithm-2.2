.model small
.stack 100h
.data
arr db 100 dup(?)
nl db 13,10,'$'
.code
main proc
mov ax,@data
mov ds,ax

xor ax,ax
call indec
mov cx,ax
mov bx,ax

lea dx,nl
mov ah,9
int 21h
 
mov si,0
input:
call indec
mov arr[si],al
inc si
loop input  

;maximum
MOV SI, 0
MOV AL, arr[SI]
dec bx
MOV CX, bx
NEXT:
INC SI
CMP AL, arr[SI]
jge SKIP
MOV AL, arr[SI]
SKIP:
LOOP NEXT 

mov bx,ax
lea dx,nl
mov ah,9
int 21h
mov ax,bx                                 
call outdec

mov ah,4ch
int 21h
main endp 
include indec.asm
include outdec.asm
end main
