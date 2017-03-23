;
; Track5.asm
;
; Created: 16-3-2017 09:25:58
; Author : Stefan
;

loop: 	
	LDI R18, $08
	LDI R16, $01

	
	Left:
		OUT PORTA, R16
		
		LSL R16

		DEC R18	
	brne left

	LDI R18, $08
	LDI R16, $80

	right:
		OUT PORTA, R16
		
		LSR R16

		DEC R18
	brne right

rjmp loop