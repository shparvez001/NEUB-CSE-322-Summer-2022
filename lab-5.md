# NEUB CSE 322 Summer 2022 Lab 5

Find all Codes at  [Lab 5](https://github.com/shparvez001/NEUB-CSE-322-Summer-2022/tree/main/lab-5).


## Task 1
Introduction to logical instructions
```asm
.MODEL small
.STACK 100H
.DATA     
.CODE
MAIN PROC
    mov ax, @data  
    mov ds, ax

    mov ax, 01010101b
    mov bx, 10101010b

    mov cx, ax
    and cx, bx  

    mov cx, ax
    or cx, bx   

    mov ax, 01110111b         
    mov cx, ax
    xor cx, bx  

    mov cx, ax
    not cx       

    mov cx, ax
    test cx, bx   ;Same as logical AND operation. But does not change the value of the destination registers. But changes the flags.

    mov ax, 00001111b       
    and ax, 11110011b   ;ANDing a bit with 0 clears the bit
    or ax, 00110000b    ;ORing a bit with 1 sets the bit
    xor ax, 00001010b   ;XORing a bit with 1 flips the bit

exit:
    MOV AH, 4CH
    INT 21H

ENDP MAIN
END MAIN   
```

## Task 2
Use TEST instruction to check if the register AX has a value 0 or not. If AX contains 0 print 0 otherwise do nothing.

```asm
.MODEL small
.STACK 100H
.DATA  
str db 'Ax contains zero$'   
.CODE
MAIN PROC
    mov ax, @data  
    mov ds, ax

    mov ax, 0
    test ax, 0ffffh   
    jz zero
    jmp exit

zero:
    mov ah, 9
    lea dx, str
    int 21h    

exit:
    MOV AH, 4CH
    INT 21H

ENDP MAIN
END MAIN
```

## Task 3 [Odd Even Checker]
Use logical instructions to check if an input number is odd or even. If the number is odd print 'O' if even print 'E'.

```asm
.MODEL small
.STACK 100H
.DATA  
str db 0dh, 0ah, 'The number is even ', 0dh, 0ah,' $'   
odd db 0dh, 0ah, 'The number is odd ', 0dh, 0ah,' $'  
.CODE
MAIN PROC
    mov ax, @data  
    mov ds, ax
l1:    
    mov ah, 1
    int 21h

    test al, 1
    jz even

    mov ah, 9
    lea dx, odd
    int 21h      
    jmp l2       

even:
    mov ah, 9
    lea dx, str
    int 21h
l2:      
    jmp l1

exit:
    MOV AH, 4CH
    INT 21H

ENDP MAIN
END MAIN    
```

## Task 4 [Case conversion]
Use only logical instruction to convert characters from uppercase to lowercase
```asm
.MODEL small
.STACK 100H
.DATA  
.CODE
MAIN PROC
    mov ax, @data  
    mov ds, ax  
l1:    
    mov ah, 1
    int 21h

    mov bl, al
    or bl, 00100000b

    mov ah, 2
    mov dl, '-'
    int 21h
    mov dl, bl
    int 21h    
    mov dl, 0dh
    int 21h
    mov dl, 0ah
    int 21h
    jmp l1

exit:
    MOV AH, 4CH
    INT 21H

ENDP MAIN
END MAIN
```

## Task 5 [Case conversion]
Use only logical instruction to convert characters from lowercase to uppercase

```asm
.MODEL small
.STACK 100H
.DATA  
.CODE
MAIN PROC
    mov ax, @data  
    mov ds, ax  
l1:    
    mov ah, 1
    int 21h

    mov bl, al
    and bl, 11011111b

    mov ah, 2
    mov dl, '-'
    int 21h
    mov dl, bl
    int 21h    
    mov dl, 0dh
    int 21h
    mov dl, 0ah
    int 21h
    jmp l1

exit:
    MOV AH, 4CH
    INT 21H

ENDP MAIN
END MAIN   
```

## Task 6 [Case conversion]
Use logical instructions to do a case flip. If the input is uppercase convert to lowescase and 	if input is lowercase convert to uppercase.

```asm
.MODEL small
.STACK 100H
.DATA  
.CODE
MAIN PROC
    mov ax, @data  
    mov ds, ax  
l1:    
    mov ah, 1
    int 21h

    mov bl, al
    xor bl, 00100000b

    mov ah, 2
    mov dl, '-'
    int 21h
    mov dl, bl
    int 21h    
    mov dl, 0dh
    int 21h
    mov dl, 0ah
    int 21h
    jmp l1

exit:
    MOV AH, 4CH
    INT 21H

ENDP MAIN
END MAIN
```

## Task 7
Rotate and shift instructions

```asm
use of
    SHL
    SAL
    SHR
    SAR

    ROL
    RCL
    ROR
    RCR
```

## Task 8
Introduction to Stack

```asm
.MODEL small
.STACK 100H
.DATA  
.CODE
MAIN PROC
    mov ax, @data  
    mov ds, ax  

    mov ax, 1234h
    mov bx, 5678h
    push ax
    inc ax
    push ax
    push bx
    inc bx
    push bx

    pop cx     
    pop cx
    pop cx
    pop cx      

    pushf
    sub ax,ax
    popf


exit:
    MOV AH, 4CH
    INT 21H

ENDP MAIN
END MAIN   
```

## Task 9
Write a code to take an input string and print the string in reverse.

```asm
.MODEL small
.STACK 100H
.DATA  
.CODE
MAIN PROC
    mov ax, @data  
    mov ds, ax  

    mov ah, 2
    mov dl, '?'
    int 21h
    mov ah, 1
    mov cx, 0
label1:    
    int 21h
    cmp al, 0dh
    je label2
    push ax  
    inc cx
    jmp label1
label2:  
    mov ah, 2
    mov dl, 0dh
    int 21h
    mov dl, 0ah  
    int 21h
label3:
    pop dx
    int 21h
    loop label3    

exit:
    MOV AH, 4CH
    INT 21H

ENDP MAIN
END MAIN  
```

## Task 10
Introduction to procedure

```asm
.MODEL small
.STACK 100H
.DATA  
.CODE
MAIN PROC
    mov ax, @data  
    mov ds, ax  

    mov ax, 5
    mov bx, 3
    call a   
    call b

exit:
    MOV AH, 4CH
    INT 21H

ENDP MAIN   
a proc
    add ax, bx
    ret    
endp a     

b proc
    sub ax, bx
    ret
endp b

END MAIN  
```

## Task 11  
Write a code with a multiply procedure.
```asm
.MODEL small
.STACK 100H
.DATA  
.CODE
MAIN PROC
    mov ax, @data  
    mov ds, ax  

    mov ax, 5
    mov bx, 3  
    call multiply


exit:
    MOV AH, 4CH
    INT 21H

ENDP MAIN   
multiply proc ;Multiply values of ax and bx
    push ax
    push bx  
    xor dx, dx ;resets dx register

l1:
    test bx, 1
    jz endif    
    add dx, ax
endif:
    shl ax, 1
    shr bx, 1
    jnz l1   

    pop bx
    pop ax
    ret    
endp multiply    
END MAIN   
```

## Task 12
Multiplication procedure by addition

```asm
.MODEL small
.STACK 100H
.DATA  
.CODE
MAIN PROC
    mov ax, @data  
    mov ds, ax  

    mov ax, 5
    mov bx, 3  
    call multiply


exit:
    MOV AH, 4CH
    INT 21H

ENDP MAIN   
multiply proc ;Multiply values of ax and bx
    push ax
    push bx  
	push cx
	mov cx, bx
    xor dx, dx ;resets dx register

l1:
    add dx, ax
    loop l1  

    pop cx
	pop bx
    pop ax
    ret    
endp multiply    
END MAIN   
```

## Task 13
Multiply and division instruction

```asm
.MODEL small
.STACK 100H
.DATA  
.CODE
MAIN PROC
    mov ax, @data  
    mov ds, ax  

    mov ax, 8
    mov bx, 3  
    mul bx   ;mutiply bx with ax and store the result in ax
    mov bx,  3
    imul bx ;Signed multiplication

    mov ax, 2
    mov bx, 5
    div bx  ;unsigned division
    mov ax, 2
    idiv bx ;signed division


exit:
    MOV AH, 4CH
    INT 21H

ENDP MAIN
END MAIN   
```



## Tasks to be done by students
1. Marut example 7.1-7.13
2. Marut Section 7.4: Binary and HEX input output [Total 4 codes]
3. Marut Chapter 7 Exercise 8
4. Marut Chapter 7 Exercise 9
5. Marut Chapter 7 Exercise 10
6. Marut Chapter 7 Exercise 11
7. Marut Chapter 7 Exercise 12
8. Marut Chapter 7 Exercise 13
9. Marut Chapter 7 Exercise 14
