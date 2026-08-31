.model small
.stack 100h 

.data
stock dw 200
msg1 db 13,10,"Stock = $" 

.code
main proc
    mov ax,@data
    mov ds,ax
    
    mov ah,1
    int 21h
    
    cmp al,'A'
    je add_stock

    cmp al,'R'
    je remove_stock

    cmp al,'H'
    je hold

add_stock:
    add stock,50
    jmp print

remove_stock:
    sub stock,30
    jmp print

hold:
    
print:
    mov ah,9
    lea dx,msg1
    int 21h

    mov ax,stock
    call print_num

    mov ah,4ch
    int 21h

main endp

print_num proc

    xor cx,cx
    mov bx,10

next:
    xor dx,dx
    div bx
    push dx
    inc cx
    cmp ax,0
    jne next

display:
    pop dx
    add dl,'0'
    mov ah,2
    int 21h
    loop display

print_num endp 
end main