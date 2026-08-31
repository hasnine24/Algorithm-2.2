include emu8086.inc

.model small
.stack 100h

.code
main proc

    ; Take input
    CALL INDEC
    MOV BX, AX          ; BX = n

    MOV CX, AX          ; CX = number of rows

OUTER:
    MOV SI, CX          ; SI = number of numbers to print
    MOV DI, BX          ; DI = starting number (n)

INNER:
    MOV AX, DI
    CALL OUTDEC         ; print DI                         

    DEC DI              ; next number = DI - 1
    DEC SI

    CMP SI, 0
    JNZ INNER

    ; New line
    MOV DL, 13
    MOV AH, 2
    INT 21H

    MOV DL, 10
    MOV AH, 2
    INT 21H

    DEC CX              ; next row
    JNZ OUTER

    MOV AH, 4CH
    INT 21H

main endp
include indec.asm
include outdec.asm
end main