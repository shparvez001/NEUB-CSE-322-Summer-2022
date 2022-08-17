# NEUB CSE 322 Summer 2022 Lab 4

Find all Codes at  [Lab 4](https://github.com/shparvez001/NEUB-CSE-322-Summer-2022/tree/main/lab-4).


## Task 1 (Example 6.3)
Suppose AL and BL contain extended ASCII characters. Display the one that comes first in the character sequence.
```asm
.MODEL small
.STACK 100H
.DATA     
.CODE
MAIN PROC
    mov ax, @data  
    mov ds, ax

    mov ah, 1
    int 21h
    mov bl, al
    int 21h
    mov bh, al  ; 2 ASCII are stored in bh and bl

    mov ah, 2
    mov dl, 0dh
    int 21h
    mov dl, 0ah
    int 21h

    cmp bl, bh
    jg print2
    jl print1

print1:
    mov dl, bl
    int 21h  
    jmp exit
print2:    
    mov dl, bh
    int 21h

exit:
    MOV AH, 4CH
    INT 21H

ENDP MAIN
END MAIN
```
Alternative Solution
```asm
.MODEL small
.STACK 100H
.DATA     
.CODE
MAIN PROC
    mov ax, @data  
    mov ds, ax

    mov ah, 1
    int 21h
    mov bl, al
    int 21h
    mov bh, al  ; 2 ASCII are stored in bh and bl

    mov ah, 2
    mov dl, 0dh
    int 21h
    mov dl, 0ah
    int 21h

    cmp bl, bh
    jg print

    mov dl, bl
    int 21h  
    jmp exit
print:    
    mov dl, bh
    int 21h

exit:
    MOV AH, 4CH
    INT 21H

ENDP MAIN
END MAIN   
```

## Task 2 (Example 6.4) [Case structure]
If AX contains a negative number, put -1 In BX; if AX contains 0, put 0 In BX; if AX contains a positive number, put 1 In BX.

```asm
.MODEL small
.STACK 100H
.DATA     
.CODE
MAIN PROC
    mov ax, @data  
    mov ds, ax
;ax=+ve, bx=1
;ax=-ve, bx=-1
;ax=0, bx, 0   

    mov ax, 50

    cmp ax, 0
    jg greater
    jl less
    je equal

greater:
    mov bx, 1   
    jmp exit
less:        
    mov bx, -1   
    jmp exit
equal:        
    mov bx, 0   

exit:
    MOV AH, 4CH
    INT 21H

ENDP MAIN
END MAIN
```

## Task 3(Example 6.5) [Another Case structure]
If AL contains 1 or 3, display "o"; if AL contains 2 or 4,display "e".

```asm
.MODEL small
.STACK 100H
.DATA     
.CODE
MAIN PROC
    mov ax, @data  
    mov ds, ax  

    mov al, 2    

    cmp al, 1
    je odd      
    cmp al, 3
    je odd    
    cmp al, 2
    je even
    cmp al, 4
    je even

odd:
    mov ah, 2
    mov dl, 'o'
    int 21h
    jmp exit
even:
    mov ah, 2
    mov dl, 'e'
    int 21h       

exit:
    MOV AH, 4CH
    INT 21H

ENDP MAIN
END MAIN   
```

## Task 4
Take a number from 0-9 as input and print if it is odd or even.
```asm
.MODEL small
.STACK 100H
.DATA      
o db 'Number is odd', 0dh, 0ah, '$'    
e db 'Number is even', 0dh, 0ah, '$'
.CODE
MAIN PROC
    mov ax, @data  
    mov ds, ax  

    mov ah, 1
    int 21h

    mov bl, al
    sub bl, '0'   

    mov ah, 2
    mov dl, 0dh
    int 21h
    mov dl, 0ah
    int 21h

    cmp bl, 0
    je even   
    cmp bl, 1
    je odd
    cmp bl, 2
    je even
    cmp bl, 3
    je odd
    cmp bl, 4
    je even
    cmp bl, 5
    je odd
    cmp bl, 6
    je even
    cmp bl, 7
    je odd
    cmp bl, 8
    je even
    cmp bl, 9
    je odd        


odd:         
    mov ah, 9
    lea dx, o
    int 21h
    jmp exit
even:
    mov ah, 9
    lea dx, e
    int 21h       

exit:
    MOV AH, 4CH
    INT 21H

ENDP MAIN
END MAIN  
```

## Task 5 (Example 6.6) [AND condition]
Read a character, and if it's an uppercase letter, display it.

```asm
.MODEL small
.STACK 100H
.DATA      
.CODE
MAIN PROC
    mov ax, @data  
    mov ds, ax  

    mov ah, 1
    int 21h
    mov bl, al

    cmp bl, 'A'   
    jl noPrint
    cmp bl, 'Z'
    jg noPrint    

    mov ah, 2
    mov dl, bl
    int 21h

noPrint:           

exit:
    MOV AH, 4CH
    INT 21H

ENDP MAIN
END MAIN    
```

## Task 6 (Example 6.7) [OR condition]
Read a character. If it's "y" or "Y", display it; otherwise, terminate the program.

```asm
.MODEL small
.STACK 100H
.DATA      
.CODE
MAIN PROC
    mov ax, @data  
    mov ds, ax  

    mov ah, 1
    int 21h
    mov bl, al

    cmp bl, 'y'
    je print
    cmp bl, 'Y'   
    je print  
    jmp exit

print:
    mov ah, 2
    mov dl, bl
    int 21h             

exit:
    MOV AH, 4CH
    INT 21H

ENDP MAIN
END MAIN
```

## Task 7 (Example 6.9) [While structure]
Write some code to count the number of characters In an input line.

```asm
.MODEL small
.STACK 100H
.DATA      
.CODE
MAIN PROC
    mov ax, @data  
    mov ds, ax  

    mov cx, 0
    mov ah, 1

a:    
    int 21h
    cmp al, 0dh
    je exit
    inc cx
    jmp a

exit:
    MOV AH, 4CH
    INT 21H

ENDP MAIN
END MAIN   
```

## Task 8 (Example 6.10) [Repeat Structure]
Write some code to read characters until a blank is read.

```asm
.MODEL small
.STACK 100H
.DATA      
.CODE
MAIN PROC
    mov ax, @data  
    mov ds, ax  

    mov ah, 1
a:
    int 21h
    cmp al, ' '
    jne a    


exit:
    MOV AH, 4CH
    INT 21H

ENDP MAIN
END MAIN   
```

## Task 9 (Chapter 6 Exercise 9)
Write a program to display the extended ASCII characters (ASCII codes 80h to FFh). Display 10 characters per line, separated by blanks. Stop after the extended characters have been displayed once.

```asm
.MODEL small
.STACK 100H
.DATA      
.CODE
MAIN PROC
    mov ax, @data  
    mov ds, ax  

    mov bl, 80h     
    mov ah, 2
a:    
    mov cx, 10
b:    
    mov dl, bl
    int 21h        
    cmp bl, 0ffh
    je exit
    inc bl          
    mov dl, ' '
    int 21h
    loop b

    mov dl, 0dh
    int 21h
    mov dl, 0ah
    int 21h
    jmp a    

exit:
    MOV AH, 4CH
    INT 21H

ENDP MAIN
END MAIN   
```

## Task 10 (Chapter 6 Exercise 10)
Write a program that will prompt the user to enter a hex digit character ("0"·... "9" or "A" ... "F"), display it on in decimal. If the user enters an illegal character, display 'i' to indicate invalid input and allow to enter new hex number.

Sample execution
```
0-0
1-1
2-2
A-10
B-11
C-12
D-13
X-i
z-i
a-i
E-14
F-15
8-8
```
```asm
.MODEL small
.STACK 100H
.DATA      
.CODE
MAIN PROC
    mov ax, @data  
    mov ds, ax  


a:   
    mov ah, 1
    int 21h  
    mov bl, al    
    mov ah, 2  
    mov dl, '-'
    int 21h
    cmp bl, '0'   
    jl invalid
    cmp bl, '9'
    jg check2     

    mov dl, bl
    int 21h   
    jmp loopend

check2:
    cmp bl, 'A'
    jl invalid   
    cmp bl, 'F'
    jg invalid

    mov dl, '1'
    int 21h
    mov dl, bl
    sub dl, 'A'
    add dl, '0'
    int 21h  
    jmp loopend  
 invalid:   
    mov dl, 'i'
    int 21h
 loopend:    
    mov dl, 0dh
    int 21h
    mov dl, 0ah
    int 21h
    jmp a

exit:
    MOV AH, 4CH
    INT 21H

ENDP MAIN
END MAIN   
```

## Task 11   (Chapter 6 Exercise 11)
Do task 10 but if three invalid input is given, terminate the program
```asm
Solution to be done by students
```

## Task 12 (Exercise 6.8)
Write a program to display a "?", read two capital letters, and display them on the next line in alphabetical order.

```asm
Solution to be done by students
```

## Task 13
Write a code to take a string input and print the first and last capital letters in the string as appeared in the string


Sample Execution
```
input:
Hello this is a test A
output:
First capital = H Last capital = A
```
```asm
Solution to be done by students
```

## Tasks to be done by students
1. Section 6.5: Programming with High-Level Structures
2. Task 11: Do task 10 but if three invalid input is given, terminate the program
3. Task 12: Write a program to display a "?", read two capital letters, and display them on the next line in alphabetical order.
4. Task 13: Write a code to take a string input and print the first and last capital letters in the string as appeared in the string
