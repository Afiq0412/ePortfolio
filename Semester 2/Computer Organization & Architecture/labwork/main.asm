TITLE lab1
;Author: Group 1
;Date: 10 April 2023

include Irvine32.inc

.data

message BYTE "Welcome to Assembly Programming", 0dh, 0ah, 0

.code
main proc

		call Clrscr
		mov edx, offset message
		call WriteString

exit
main ENDP
END main