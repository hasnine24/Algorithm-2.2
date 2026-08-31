.model small
.stack 100h
.data
.code
main proc 
    
mov ax,8000h
neg ax ;NEG AX where AX contains 8000h

mov ax,7FFFH
mov bx,0001H
add ax,bx ;ADD AX, BX where AX contains 7FFFH and BX contains 0001H 

mov ax,0FFFFH
inc ax ;INC AX where AX contains FFFFh

mov ah,4ch
int 21h
main endp
end main