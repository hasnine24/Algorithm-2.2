.model small
.stack 100h

.data
A DB ?
B DB 3
C DB 1

MSG1 DB 13,10,"ENTER THE VALUE OF A: $"
MSG2 DB 13,10,"B = $"

.code
main proc

MOV AX,@DATA
MOV DS,AX

; Display message
LEA DX,MSG1
MOV AH,9
INT 21H

; Input A
MOV AH,1
INT 21H
MOV A,AL

; Convert ASCII to number
SUB A,30H

; B = 3A - B + 2C

MOV AL,A

ADD AL,A       ; 2A
ADD AL,A       ; 3A

SUB AL,B       ; 3A - B

ADD AL,C       ; + C
ADD AL,C       ; + C

; Convert result to ASCII
ADD AL,30H
MOV B,AL

; Display "B = "
LEA DX,MSG2
MOV AH,9
INT 21H

; Display result
MOV AH,2
MOV DL,B
INT 21H

; Exit
MOV AH,4CH
INT 21H

main endp
end main