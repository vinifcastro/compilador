.text
.globl main

.data
_nl: .asciiz "\n"

.text

main:
move $fp, $sp

# Fim do programa (syscall 10)
li $v0, 10
syscall
