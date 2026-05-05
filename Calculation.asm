; Implementation for shape calculation functions

section .data
TRUE equ 1
FALSE equ 0
NULL equ 0
LF equ 10
NEWLINE equ 10
MAXWORDLENGTH equ 20
PI dt 3.14159265359


SYS_read	equ	0			; system call code for read
SYS_write	equ	1			; system call code for write
SYS_open	equ	2			; system call code for file open
SYS_close	equ	3			; system call code for file close
SYS_fork	equ	57			; system call code for fork
SYS_exit	equ	60			; system call code for terminate
SYS_creat	equ	85			; system call code for file open/create
SYS_time	equ	201			; system call code for get time

O_RDONLY	equ	000000q			; file permission - read only
O_WRONLY	equ	000001q			; file permission - write only
O_RDWR		equ	000002q			; file permission - read and write

STDIN		equ	0			; standard input
STDOUT		equ	1			; standard output
STDERR		equ	2			; standard error

O_CREAT		equ	0x40
O_TRUNC		equ	0x200
O_APPEND	equ	0x400



section .bss

section .text

; 
;
;
; returns missing variable in rax \theta => [adj] => [opp] => [hyp]
