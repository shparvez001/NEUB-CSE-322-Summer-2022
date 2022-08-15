# NEUB CSE 322 Summer 2022 Lab 2
Start of assembly language lab before hardware are ready.

Find all Codes at  [Lab 2](https://github.com/shparvez001/NEUB-CSE-322-Fall-2021/tree/main/lab-2).

## Task 1
Basic Structure of 8086 Assembly code and printing characters.
```asm
.MODEL small
.STACK 100H
.DATA
.CODE
MAIN PROC
    MOV AH, 2
    MOV DL, 41H   ; A
    INT 21H   
    ;Print a new line      
    MOV DL, 0Ah
    INT 21H
    MOV DL, 0DH
    INT 21H
    MOV DL, 42H   ; B
    INT 21H       
    ;Print a new line      
    MOV DL, 0Ah
    INT 21H
    MOV DL, 0DH
    INT 21H
    MOV DL, 43H   ; C
    INT 21H   

    MOV DL, 'A'
    INT 21H

    MOV AH, 4CH
    INT 21H

ENDP MAIN
END MAIN
```

## Task 2
Input and output of characters
```asm
.MODEL small
.STACK 100H
.DATA
.CODE
MAIN PROC
    MOV AH, 1
    int 21h  ; The equivalent ascii of the input is stored in AL

    mov bl, al ; move the value of AL to BL

    mov ah, 2
    mov dl, 0dh
    int 21h
    mov dl, 0ah
    int 21h

    mov dl, bl
    int 21h

    MOV AH, 4CH
    INT 21H

ENDP MAIN
END MAIN
```

## Task 3
Printing a string (`HELLO THERE`) the hard way
```asm
.MODEL small
.STACK 100H
.DATA
.CODE
MAIN PROC
    MOV AH, 2
    MOV DL, 'H'
    int 21h
    MOV DL, 'E'
    int 21h
    MOV DL, 'L'
    int 21h  
    MOV DL, 'L'
    int 21h    
    MOV DL, 'O'
    int 21h
    MOV DL, ' '
    int 21h   
    MOV DL, 'T'
    int 21h   
    MOV DL, 'H'
    int 21h   
    MOV DL, 'E'
    int 21h  
    MOV DL, 'R'
    int 21h    
    MOV DL, 'E'
    int 21h

    ;Exit
    MOV AH, 4Ch
    int 21h


ENDP MAIN     
END MAIN
```


## Task 4
Printing a string the easy way
```asm
.MODEL small
.STACK 100H
.DATA   
msg db 'HELLO THERE!', 0dh, 0ah, '$'
.CODE
MAIN PROC
    mov ax, @data  
    mov ds, ax  

    mov ah, 9
    lea dx, msg      
    int 21h    

    MOV AH, 4CH
    INT 21H

ENDP MAIN
END MAIN
```


## Task 5
Uppercase to lower case
```asm
.MODEL small
.STACK 100H
.DATA   
msg db 'Enter a character in uppercase: $'
msg2 db 'In lowercase:  $'
crlf db 0dh, 0ah, '$'
.CODE
MAIN PROC
    mov ax, @data  
    mov ds, ax  

    mov ah, 9
    lea dx, msg      
    int 21h

    mov ah, 1
    int 21h
    mov bl, al

    mov ah, 9
    lea dx, crlf
    int 21h
    lea dx, msg2
    int 21h

    add bl, 20h
    mov ah, 2
    mov dl, bl
    int 21h   

    MOV AH, 4CH
    INT 21H

ENDP MAIN
END MAIN
```


## Task 6
Lowercase to uppercase
```asm
.MODEL small
.STACK 100H
.DATA   
msg db 'Enter a character in lowercase: $'
msg2 db 'In uppercase:  $'
crlf db 0dh, 0ah, '$'
.CODE
MAIN PROC
    mov ax, @data  
    mov ds, ax  

    mov ah, 9
    lea dx, msg      
    int 21h

    mov ah, 1
    int 21h
    mov bl, al

    mov ah, 9
    lea dx, crlf
    int 21h
    lea dx, msg2
    int 21h

    sub bl, 20h
    mov ah, 2
    mov dl, bl
    int 21h   

    MOV AH, 4CH
    INT 21H

ENDP MAIN
END MAIN
```


## Task 7
Take 2 input numbers from 0-4 and print the sum of the numbers in new line
```asm
Solution to be done by students
```
## Tasks to be done by students
1. Task 7: Take 2 input numbers from 0-4 and print the sum of the numbers in new line
