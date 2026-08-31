.model small
.stack 100h
.data
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
    mov bx,ax          ; bx = n (keep a copy for later use)
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

    ; ---- bubble sort (ascending) ----
    ; bx = n  (outer loop runs n-1 times)
    dec bx              ; bx = n-1
    mov di,bx           ; di = outer loop counter

outer:
    mov cx,di           ; inner loop runs 'di' times (shrinks each pass)
    mov si,0
inner:
    mov al,arr[si]
    mov ah,arr[si+1]
    cmp al,ah
    jle no_swap         ; if arr[si] <= arr[si+1], already in order
    mov arr[si],ah       ; swap
    mov arr[si+1],al
no_swap:
    inc si
    loop inner

    dec di
    jnz outer            ; repeat outer pass until di = 0

    ; ---- array is now sorted in arr[] in ascending order ----
    ; nothing printed, sorted data just sits in the data segment

    mov ah,4ch
    int 21h
main endp
include indec.asm
end main