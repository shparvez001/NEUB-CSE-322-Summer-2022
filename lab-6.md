# NEUB CSE 322 Summer 2022 Lab 6

Find all Codes at  [Lab 6](https://github.com/shparvez001/NEUB-CSE-322-Summer-2022/tree/main/lab-6).


## Task 1 (Program listing 9.2, 9.3, 9.4)
Decimal input output procedure
```asm
.MODEL small
.STACK 100H
.DATA     
.CODE
MAIN PROC
    mov ax, @data  
    mov ds, ax


    call indec
    mov bx, ax        

    mov ah, 2
    mov dl, 0dh
    int 21h
    mov dl, 0ah
    int 21h     
    mov ax, bx      

    call outdec

exit:
    MOV AH, 4CH
    INT 21H

ENDP MAIN  

outdec proc  
    push ax
    push bx
    push cx
    push dx  

    or ax, ax
    jge endif1  
    push ax
    mov ah, 2
    mov dl, '-'
    int 21h
    pop ax
    neg ax

endif1:
    ;Applicable for both positive and negative nnumbers
    xor cx, cx ;clear cx
    mov bx, 10       

repeat1:    
    xor dx, dx ; clear dx
    div bx               
    push dx
    inc cx
    cmp ax, 0
    jne repeat1

    mov ah, 2
 printloop1:
    pop dx
    add dl, '0'
    int 21h
    loop printloop1   

    pop dx
    pop cx
    pop bx
    pop ax
    ret
outdec endp

indec proc   
    push bx
    push cx
    push dx
begin2:
    mov ah, 2
    mov dl, '?'
    int 21h

    mov bx, 0
    mov cx, 0

    mov ah, 1
    int 21h

    cmp al, '-'
    je minus
    cmp al, '+'
    je plus    
    jmp repeat2
minus:
    mov cx, 1    
plus:
    int 21h     
repeat2:    
    cmp al, '0'
    jl notdigit         
    cmp al, '9'
    jg notdigit     

    mov ah, 0
    sub al, '0'     ; Also and ax, 000Fh    
    push ax

    mov ax, 10
    mul bx
    pop bx   
    add bx, ax

    mov ah, 1
    int 21h
    cmp al, 0dh
    jne repeat2  

    mov ax, bx  
    ;check if the input was negative
    cmp cx, 0
    je exitproc
    neg ax
    jmp exitproc

notdigit:   
    mov ah, 2
    mov dl, 0dh
    int 21h
    mov dl, 0ah
    int 21h
    jmp begin2

exitproc:  
    pop dx
    pop cx
    pop bx
    ret
indec endp
END MAIN   
```

## Task 2
Write a procedure to find the factorial of a number stored in cx.

```asm
.MODEL small
.STACK 100H
.DATA     
.CODE
MAIN PROC
    mov ax, @data  
    mov ds, ax


    call indec
    mov bx, ax        

    mov ah, 2
    mov dl, 0dh
    int 21h
    mov dl, 0ah
    int 21h     
    mov ax, bx      
    call factorial
    call outdec

exit:
    MOV AH, 4CH
    INT 21H

ENDP MAIN  
factorial proc ;Returns the factorial of ax in ax
    push cx
    mov cx, ax
    mov ax, 1
label3:
    mul cx
    loop label3    

    pop cx
    ret   
factorial endp    

outdec proc  
    push ax
    push bx
    push cx
    push dx  

    or ax, ax
    jge endif1  
    push ax
    mov ah, 2
    mov dl, '-'
    int 21h
    pop ax
    neg ax

endif1:
    ;Applicable for both positive and negative nnumbers
    xor cx, cx ;clear cx
    mov bx, 10       

repeat1:    
    xor dx, dx ; clear dx
    div bx               
    push dx
    inc cx
    cmp ax, 0
    jne repeat1

    mov ah, 2
 printloop1:
    pop dx
    add dl, '0'
    int 21h
    loop printloop1   

    pop dx
    pop cx
    pop bx
    pop ax
    ret
outdec endp

indec proc   
    push bx
    push cx
    push dx
begin2:
    mov ah, 2
    mov dl, '?'
    int 21h

    mov bx, 0
    mov cx, 0

    mov ah, 1
    int 21h

    cmp al, '-'
    je minus
    cmp al, '+'
    je plus    
    jmp repeat2
minus:
    mov cx, 1    
plus:
    int 21h     
repeat2:    
    cmp al, '0'
    jl notdigit         
    cmp al, '9'
    jg notdigit     

    mov ah, 0
    sub al, '0'     ; Also and ax, 000Fh    
    push ax

    mov ax, 10
    mul bx
    pop bx   
    add bx, ax

    mov ah, 1
    int 21h
    cmp al, 0dh
    jne repeat2  

    mov ax, bx  
    ;check if the input was negative
    cmp cx, 0
    je exitproc
    neg ax
    jmp exitproc

notdigit:   
    mov ah, 2
    mov dl, 0dh
    int 21h
    mov dl, 0ah
    int 21h
    jmp begin2

exitproc:  
    pop dx
    pop cx
    pop bx
    ret
indec endp
END MAIN  
```

## Task 3
Take 2 decimal numbers greater than 10 as inputs and print their sum,  difference, and product afterwards.

Sample execution
```
?120
?5

Sum is 125
Difference is 115
product is 600
```
```asm
Solution to be done by students   
```

## Task 4 (Example 10.3)
Sum of 10 elements in array
```asm
.MODEL small
.STACK 100H
.DATA   
W DW 10, 20, 30, 40, 50, 60, 70, 80, 90, 100
x dw 100 dup(10)
.CODE
MAIN PROC
    mov ax, @data  
    mov ds, ax

    mov ax, 0  
    lea si, w  ;lea si, x  

    mov cx, 10
label1:
    add ax, [si]  
    add si, 2
    loop label1  


exit:
    MOV AH, 4CH
    INT 21H

ENDP MAIN  
END MAIN  
```

## Task 5 [Case conversion]
Sum of elements in array ending with $

```asm
.MODEL small
.STACK 100H
.DATA   
W DW 10, 20, 30, 40, 50, 60, 70, 80, '$'
x dw 100 dup(10)
.CODE
MAIN PROC
    mov ax, @data  
    mov ds, ax

    mov bx, 0  
    lea si, w  

label1:  
    cmp [si], '$'
    je endloop
    add bx, [si]  
    add si, 2
    jmp label1
endloop:

exit:
    MOV AH, 4CH
    INT 21H

ENDP MAIN  
END MAIN    
```

## Task 6 (Example 10.4, program listing 10.1)
Array (Each element is 16 bit) Reverse Procedure

```asm
.MODEL small
.STACK 100H
.DATA   
W DW 10, 20, 30, 40, 50, 60, 70, 80
.CODE
MAIN PROC
    mov ax, @data  
    mov ds, ax

    lea si, w
    mov bx, 8
    call reverse


exit:
    MOV AH, 4CH
    INT 21H

ENDP MAIN  
;si contains start of array
;bx contains length of array
reverse proc   
    push ax
    push bx
    push cx
    push dx
    push si
    push di

    mov di, si
    mov cx, bx   

    dec bx
    shl bx, 1
    add di, bx     
    shr cx, 1
exchangeloop:        
    mov ax, [si]
    xchg ax, [di]  
    mov [si], ax
    add si, 2
    sub di, 2   
    loop exchangeloop        

    pop di
    pop si
    pop dx
    pop cx
    pop bx
    pop ax
    ret    
reverse endp
END MAIN   
```

## Task 7 (Two dimensional array usage)
Finding the average of different tests

```asm
.MODEL small
.STACK 100H
.DATA   
five dw 5
scores  dw 67, 45, 98, 33
        dw 70, 56, 87, 44
        dw 82, 72, 89, 40
        dw 80, 67, 95, 50
        dw 78, 76, 92, 62
 average dw 5 dup(0)       
.CODE
MAIN PROC
    mov ax, @data  
    mov ds, ax

    mov si, 6
repeat:
    mov cx, 5
    mov bx, 0
    mov ax, 0   
l1:    
    add ax, scores[bx,si]
    add bx, 8
    loop l1

    mov dx, 0
    div five
    mov average[si], ax  
    sub si, 2
    jnl repeat   

    mov si, average
    mov bx, average[6]



exit:
    MOV AH, 4CH
    INT 21H

ENDP MAIN  
END MAIN     
```

## Tasks to be done by students
1. Task 3: Take 2 decimal numbers greater than 10 as inputs and print their sum,  difference, and product afterwards.
2. Add hex input output  and binary input output procedure to the decimal input out put procedure and do the following tasks.
  a. put the last 5 digit of your registration number in ax (Treat the number as decimal) and print their equivalent binary and hexadecimal number.
  b.  put the last 5 digit of your registration number in ax (Treat the number as hexadecimal) and print their equivalent binary and decimal number.
  c. put 100010101010 in ax and print the equivalent decimal and hexadecimal number.  
  d. take hexadecimal input, binary input, decimal input
3. Chapter 8 problem 8
4. Chapter 8 problem 10
5. Change the code in task 6 to work for array of 8-bit elements, which can be used to reverse string.
6. Section 10.3: Application of sorting. Program listing 10.2,10.3
7. Change the code in task 8 to find the average test score of each students.
