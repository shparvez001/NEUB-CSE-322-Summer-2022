# NEUB CSE 322 Summer 2022 Lab 7

Find all Codes at  [Lab 7](https://github.com/shparvez001/NEUB-CSE-322-Summer-2022/tree/main/lab-7).


## Task 1
Basic XLAT usage
```asm
.MODEL small
.STACK 100H
.DATA  
array1 db 10,11,12,13,14,15,16,17,18,19,20    
.CODE
MAIN PROC
    mov ax, @data  
    mov ds, ax                            

    lea bx, array1       
    mov al, 2
    xlat   ;xlat uses the value of al, n, and returns the nth element of array whose location offset is stored in bx

exit:
    MOV AH, 4CH
    INT 21H

ENDP MAIN  
END MAIN
```

## Task 2
Encoding and decoding message using XLAT

```asm
.MODEL small
.STACK 100H
.DATA                   
;                          ABCDEFGHIJKLMNOPQRSTUVWXYZ
encodeKey db 65 dup(' '), 'XQPOGHZBCADEIJUVFMNKLRSTWY',
          db 37 dup(' ')
;                          ABCDEFGHIJKLMNOPQRSTUVWXYZ
decodeKey db 65 dup(' '), 'JHIKLQEFMNTURSDCBVWXOPYAZG',
          db 37 dup(' ')   
encodedMessage db 80 dup('$')  
decodedMessage db 80 dup('$')  
message db 'Enter a message to be encoded: $'
crlf db 0dh, 0ah, '$'
.CODE
MAIN PROC
    mov ax, @data  
    mov ds, ax  

    lea dx, message    
    mov ah, 9
    int 21h   

    mov ah, 1        

    lea bx, encodeKey
    lea di, encodedMessage
 while_:   
    int 21h
    cmp al, 0dh
    je endwhile  
    xlat    ;after xlat al contains the encoded character
    mov [di], al   
    inc di
    jmp while_
endwhile:    

    mov ah, 9
    lea dx, crlf
    int 21h

    lea dx, encodedMessage
    int 21h

    lea di, decodedMessage
    lea si, encodedMessage
    lea bx, decodeKey
while2:
    mov al, [si]
    cmp al, '$'
    je endwhile2   
    xlat
    mov [di], al   
    inc si
    inc di
    jmp while2                  
endwhile2:  

    mov ah, 9
    lea dx, crlf
    int 21h

    lea dx, decodedMessage
    int 21h  

exit:
    MOV AH, 4CH
    INT 21H

ENDP MAIN  
END MAIN  
```

## Task 3
Introduction to MOVSB instruction and REP prefix

```asm
.MODEL small
.STACK 100H
.DATA                   
string1 db 'HELLO'
string2 db 5 dup('?')
crlf db 0dh, 0ah, '$'
.CODE
MAIN PROC
    mov ax, @data  
    mov ds, ax  
    mov es, ax

    lea si, string1
    lea di, string2
    cld   

    mov cx, 5
    rep movsb

exit:
    MOV AH, 4CH
    INT 21H

ENDP MAIN  
END MAIN    
```

## Task 4
Write instructions to copy STRING 1 of the preceding task into STRING2 In reverse order.
```asm
.MODEL small
.STACK 100H
.DATA                   
string1 db 'HELLO'
string2 db 5 dup('?')
crlf db 0dh, 0ah, '$'
.CODE
MAIN PROC
    mov ax, @data  
    mov ds, ax  
    mov es, ax

    lea si, string1+4
    lea di, string2
    std   

    mov cx, 5
L1:
    MOVSB  
    ADD DI,2
    LOOP L1


exit:
    MOV AH, 4CH
    INT 21H

ENDP MAIN  
END MAIN       
```

## Task 5 (Program listing 11.1, 11.2, 11.3)
String read and print

```asm
.MODEL small
.STACK 100H
.DATA                   
string1 db 100 dup('$')
crlf db 0dh, 0ah, '$'
.CODE
MAIN PROC
    mov ax, @data  
    mov ds, ax  
    mov es, ax   

    lea di, string1
    call read_str   

    mov ah, 9    
    lea dx, crlf
    int 21h
    lea dx, string1
    int 21h      

    lea dx, crlf
    int 21h     

    lea si, string1
    add si, 4
    mov bx, 10
    call print_str

exit:
    MOV AH, 4CH
    INT 21H

ENDP MAIN  

read_str proc
    push ax
    push di
    cld ;df=0
    ;std ;df=1
    xor bx, bx
    mov ah,1
    int 21h
while1:    
    cmp al, 0dh  
    je endwhile1   
    cmp al, 08h
    je else1
    stosb
    inc bx  
    jmp if1  

 else1:
    dec di
    dec bx     
if1:    
    int 21h
    jmp while1

endwhile1:    

    pop di
    pop ax
    ret
read_str endp    

print_str proc  
    push ax
    push bx
    push cx
    push dx
    push si    

    mov cx, bx
    cmp cx, 0
    je p_exit ; also possible to use jcxz p_exit  

    cld ;df=0
    mov ah, 2
 l1:
    lodsb
    mov dl, al
    int 21h
    loop l1   

p_exit:
    pop si
    pop dx
    pop cx
    pop bx
    pop ax    
    ret
print_str endp    
END MAIN   
```

## Task 6
String reverse print using stosb and lodsb

```asm
.MODEL small
.STACK 100H
.DATA                   
string1 db 100 dup('$')
crlf db 0dh, 0ah, '$'
.CODE
MAIN PROC
    mov ax, @data  
    mov ds, ax  
    mov es, ax   

    lea di, string1
    call read_str   

    mov ah, 9    
    lea dx, crlf
    int 21h
    lea dx, string1
    int 21h      

    lea dx, crlf
    int 21h     

    lea si, string1
    call print_str_reverse

exit:
    MOV AH, 4CH
    INT 21H

ENDP MAIN  

read_str proc
    push ax
    push di
    cld ;df=0
    ;std ;df=1
    xor bx, bx
    mov ah,1
    int 21h
while1:    
    cmp al, 0dh  
    je endwhile1   
    cmp al, 08h
    je else1
    stosb
    inc bx  
    jmp if1  

 else1:
    dec di
    dec bx     
if1:    
    int 21h
    jmp while1

endwhile1:    

    pop di
    pop ax
    ret
read_str endp    

print_str proc  
    push ax
    push bx
    push cx
    push dx
    push si    

    mov cx, bx
    cmp cx, 0
    je p_exit ; also possible to use jcxz p_exit  

    cld ;df=0
    mov ah, 2
 l1:
    lodsb
    mov dl, al
    int 21h
    loop l1   

p_exit:
    pop si
    pop dx
    pop cx
    pop bx
    pop ax    
    ret
print_str endp    

print_str_reverse proc  
    push ax
    push bx
    push cx
    push dx
    push si    

    mov cx, bx
    cmp cx, 0
    je p_exit2 ; also possible to use jcxz p_exit  

    add si, bx
    sub si, 1
    std ;df=1
    mov ah, 2
 l2:
    lodsb
    mov dl, al
    int 21h
    loop l2   

p_exit2:
    pop si
    pop dx
    pop cx
    pop bx
    pop ax    
    ret
print_str_reverse endp   
END MAIN    
```

## Task 7
Use of SCASB instruction and REPNZ prefix.

```asm
.MODEL small
.STACK 100H
.DATA                   
string1 db 'ABCDE'
crlf db 0dh, 0ah, '$'
.CODE
MAIN PROC
    mov ax, @data  
    mov ds, ax  
    mov es, ax    

    cld
    lea di, string1
    mov al, 'C'
    scasb
    scasb      
    scasb
    scasb          


    lea di, string1
    mov al, 'C'
    REPNZ SCASB


exit:
    MOV AH, 4CH
    INT 21H

ENDP MAIN  
END MAIN    
```

## Task 8 (Program listing 11.4)
Counting vowels and consonants using scan string instruction

```asm
.MODEL small
.STACK 100H
.DATA      
str db 80 dup('$')             
vowels db 'AEIOUaeiou'
consonants db 'BCDFGHJKLMNPQRSTVWXYZbcdfghjklmnpqrstvwxyz'    
out1 db 0dh, 0ah, 'Vowels= $'      
out2 db '  Consonants= $'
crlf db 0dh, 0ah, '$'     
vowelcnt dw 0
consonantcnt dw 0
.CODE
MAIN PROC
    mov ax, @data  
    mov ds, ax  
    mov es, ax    

    lea di, str
    call read_str
    mov si, di
    cld   
until:    
    lodsb
    lea di, vowels
    mov cx, 10
    repne scasb
    jne ck_consonant
    inc vowelcnt
    jmp l3
ck_consonant:
    lea di, consonants
    mov cx, 42
    repne scasb   
    jne l3
    inc consonantcnt

l3:  
    dec bx
    jne until   

    mov ah, 9
    lea dx, out1
    int 21h
    mov ax, vowelcnt
    call outdec
    mov ah, 9
    lea dx, out2
    int 21h
    mov ax, consonantcnt
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

    or ax, ax      ;Check if ax is 0
    jge @end_if1

    push ax
    mov dl, '-'
    mov ah, 2
    int 21h
    pop ax
    neg ax
@end_if1:

    xor cx, cx
    mov bx, 10
@repeat1:    
    xor dx, dx
    div bx
    push dx
    inc cx

    cmp ax, 0
    jne @repeat1

    mov ah, 2
@print_loop:
    pop dx
    add dl, '0'
    int 21h
    loop @print_loop            

    pop dx
    pop cx
    pop bx
    pop ax
    ret     
outdec endp

read_str proc
    push ax
    push di
    cld ;df=0
    ;std ;df=1
    xor bx, bx
    mov ah,1
    int 21h
while1:    
    cmp al, 0dh  
    je endwhile1   
    cmp al, 08h
    je else1
    stosb
    inc bx  
    jmp if1  

 else1:
    dec di
    dec bx     
if1:    
    int 21h
    jmp while1

endwhile1:    

    pop di
    pop ax
    ret
read_str endp      
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
