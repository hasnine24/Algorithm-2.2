.model small
.stack 100h

.data
msg1 db "Enter Text: $"
msg2 db 13,10,"Vowels: $"
msg3 db 13,10,"Special Characters: $"
vowel db 0
special db 0 

.code
main proc

    mov ax,@data
    mov ds,ax

    mov ah,9
    lea dx,msg1
    int 21h

READ:
    mov ah,1
    int 21h

    cmp al,13
    je SHOW 
    
    ; Check vowels
    cmp al,'A'
    je VOWEL
    cmp al,'E'
    je VOWEL
    cmp al,'I'
    je VOWEL
    cmp al,'O'
    je VOWEL
    cmp al,'U'
    je VOWEL
    cmp al,'a'
    je VOWEL
    cmp al,'e'
    je VOWEL
    cmp al,'i'
    je VOWEL
    cmp al,'o'
    je VOWEL
    cmp al,'u'
    je VOWEL
    
    ; Check A-Z
    cmp al,'A'
    jb CHECKDIGIT
    cmp al,'Z'
    jbe READ

    ; Check a-z
    cmp al,'a'
    jb CHECKDIGIT
    cmp al,'z'
    jbe READ

CHECKDIGIT:
    cmp al,'0'
    jb SPECIAL
    cmp al,'9'
    jbe READ
    jmp SPECIAL

SPECIAL:
    inc special
    jmp READ

VOWEL:
    inc vowel
    jmp READ

SHOW:
    ; Print vowel count
    mov ah,9
    lea dx,msg2
    int 21h

    mov dl,vowel
    add dl,'0'
    mov ah,2
    int 21h

    ; Print special count
    mov ah,9
    lea dx,msg3
    int 21h

    mov dl,special
    add dl,'0'
    mov ah,2
    int 21h

    mov ah,4Ch
    int 21h

main endp
end main