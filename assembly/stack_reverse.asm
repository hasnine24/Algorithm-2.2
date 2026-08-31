.MODEL SMALL
.STACK 100H
.CODE
MAIN PROC
   
    MOV AH,2
    MOV DL,'?'
    INT 21H              
    ;initialize character count
    XOR CX,CX
    ;read a character
    MOV AH,1
    INT 21H
    ;while character is not a carriage return do
    WHILE_:
    CMP AL,13
    JE END_WHILE
    ;save character on the stack and increment
    PUSH AX
    INC CX
    ;read a character
    INT 21H
    JMP WHILE_
    END_WHILE:
    ;go to a new line
    MOV AH,2
    MOV DL,13
    INT 21H
    MOV DL,10
    INT 21H
    JCXZ EXIT
    ;for count times do
    TOP:
    ;pop a character from the stack
    POP DX
    ;display it
    mov ah,2
    INT 21H
    LOOP TOP
    ;end for
    EXIT:
    MOV AH,4CH
    INT 21H
    MAIN ENDP
    END    MAIN 
 
