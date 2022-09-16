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
1. Change the code in task 2 such that the encoding and decoding works for both small letter and capital letter.
2. Change the code in task 2 such that a letter is replaced by three letters ahead. For example, A becomes D and B becomes E
3. Change the code in hometask 2 to encode both capital and small letters
4. Chapter 9 Problem 9
5. Chapter 9 Problem 10
6. Chapter 9 Problem 11
7. Chapter 9 Problem 12
8. Chapter 10 Problem 7
9. Chapter 10 Problem 9
10. Chapter 10 Problem 10
11. Change the read_str and print_str procedures of problem 5 so that there is no necessity of counter of length of string. Simply add a $ at the end of string to identify end of string
12. Section 11.6 : Compare String (Program listing 11.5)
