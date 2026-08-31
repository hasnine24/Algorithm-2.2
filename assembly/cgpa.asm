.model small
.stack 100h
.data
n       dw 5

courses:
    db 'CS01'
    dw 35, 0          ; GPA (x10 scaled), padding
    dw 3, 0            ; Credit, padding

    db 'CS02'
    dw 38, 0
    dw 4, 0

    db 'CS03'
    dw 30, 0
    dw 3, 0

    db 'CS04'
    dw 40, 0
    dw 2, 0

    db 'CS05'
    dw 33, 0
    dw 3, 0

cgpa        dw ?
totalcredit dw ?
nl          db 13,10,'$'
.code
main proc
    mov ax,@data
    mov ds,ax

    mov cx, n                ; R0 = N
    lea si, courses            ; R1 = #I
    mov word ptr totalcredit,0  ; R3 = 0
    mov word ptr cgpa,0           ; R4 = 0 (temporarily using cgpa as accumulator R4)

loop_cgpa:
    mov ax, [si+4]                ; R2 = GPA
    mul word ptr [si+8]            ; R2 = GPA * Credit  (AX = result, ignoring DX overflow)
    add cgpa, ax                     ; R4 = R4 + R2

    mov bx, [si+8]                     ; Credit value
    add totalcredit, bx                  ; R3 = R3 + Credit

    add si, 12                             ; R1 = R1 + 12 (next record)
    loop loop_cgpa                           ; DEC R0, Branch>0 Loop

    ; ---- final division: CGPA = R4 / R3 ----
    mov ax, cgpa                               ; dividend (low)
    xor dx, dx                                   ; dividend (high) = 0
    div totalcredit                                ; AX = quotient = CGPA, DX = remainder

    mov cgpa, ax                                     ; store CGPA result
                                                        ; totalcredit already holds Total Credit

    ; ---- print results ----
    mov ax, cgpa
    call outdec
    lea dx, nl
    mov ah,9
    int 21h

    mov ax, totalcredit
    call outdec
    lea dx, nl
    mov ah,9
    int 21h

    mov ah,4ch
    int 21h
main endp
include outdec.asm
end main