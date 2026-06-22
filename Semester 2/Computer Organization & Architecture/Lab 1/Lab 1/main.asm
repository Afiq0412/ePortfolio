TITLE Example Call Irvine Libraryand Loop
; Author: Dr Foad
; Date: 15 Jun 2024

include Irvine32.inc

.data
message1 BYTE "Welcome to Exercise Call Irvine Lib and Loop ", 0dh, 0ah, 0dh, 0ah
BYTE "This program is to Add 2 input student's Age : ", 0
message2 BYTE "Input Age of Student 1 and 2 : ", 0dh, 0ah, 0
message3 BYTE "Result Addition: ", 0
promptBad BYTE "Invalid input, please enter again", 0
age dword 2 dup(0)
sum_age dword ?
stryn BYTE "Press 'y' to Main Menu or 'n' to Exit Program : ", 0
charIn BYTE ?
charY db 'y'
strbye BYTE "Thank you ... BYE!!", 0dh, 0ah, 0

.code
main proc
		startProg :
		call Clrscr
		mov edx, offset message1
		call WriteString
		call crlf
		call crlf
		mov edx, offset message2
		call WriteString

		; read input Age Students
		mov ECX, 2
		mov EBX, 0
loop_Age:
		read_inOption:
		call ReadDec
		jnc goodInOption
		mov edx, OFFSET promptBad
		call WriteString
		jmp read_inOption; go input again
		goodInOption :
		mov age[EBX], eax; store good value
		add EBX, 4
		loop loop_Age
		; to add students age
		mov ECX, 2
		mov EBX, 0
		mov eax, 0
		loopAdd:
		add eax, age[EBX]
		add ebx, 4
		loop loopAdd

		; store result add
		mov sum_age, eax

		; display result
		call crlf
		mov edx, offset message3
		call WriteString
		mov eax, sum_age
		call WriteDec
		call crlf
		call crlf

		; ask either to continue ('y') or Exit program('n')
		mov edx, OFFSET stryn
		call WriteString
		call ReadChar
		mov charIn, AL
		call WriteChar
		call Crlf
		call Crlf
		mov BL, charY
		cmp BL, charIn
		JE startProg
		mov edx, OFFSET strbye
		call WriteString

exit

main ENDP
END main