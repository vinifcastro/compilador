.text
.globl main

.data
_nl: .asciiz "\n"

.text

main:
move $fp, $sp
addiu $sp, $sp, -4 # Aloca espaco para var
addiu $sp, $sp, -4 # Aloca espaco para var
addiu $sp, $sp, -4
sw $t0, 0($sp)
li $t0, 10
lw $t1, 0($sp)
addiu $sp, $sp, 4
move $t2, $t0
move $t0, $t1
move $t1, $t2
addiu $sp, $sp, -4
sw $t0, 0($sp)
li $t0, 39
lw $t1, 0($sp)
addiu $sp, $sp, 4
move $t2, $t0
move $t0, $t1
move $t1, $t2
move $a0, $t0
li $v0, 1
syscall
move $a0, $t0
li $v0, 1
syscall
la $a0, _nl
li $v0, 4
syscall

# Fim do programa (syscall 10)
li $v0, 10
syscall
