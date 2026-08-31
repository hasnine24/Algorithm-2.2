.model small
.stack 100h

.data

stock dw 200

msg1 db "Enter Choice (A/R/H): $"
msg2 db 13,10,"Current Stock = $"

.code
main proc

;==========================
; Initialize DS
;==========================

mov ax,@data
mov ds,ax

;==========================
; Print message
;==========================

lea dx,msg1
mov ah,9
int 21h

;==========================
; Take input
;==========================

mov ah,1
int 21h

; AL = user's character

;==========================
; Compare with A
;==========================

cmp al,'A'
je ADD

cmp al,'R'
je REMOVE

cmp al,'H'
je DISPLAY

jmp DISPLAY

;==========================
; Add 50
;==========================

ADD:

add stock,50
jmp DISPLAY

;==========================
; Remove 30
;==========================

REMOVE:

sub stock,30
jmp DISPLAY

;==========================
; Print Result
;==========================

DISPLAY:

lea dx,msg2
mov ah,9
int 21h

mov ax,stock

call PRINTNUM

mov ah,4ch
int 21h

main endp

;==========================
; Procedure to print number
;==========================

PRINTNUM proc

mov bx,10
xor cx,cx

L1:

xor dx,dx
div bx

push dx

inc cx

cmp ax,0
jne L1

L2:

pop dx

add dl,'0'

mov ah,2

int 21h

loop L2

ret

PRINTNUM endp

end main