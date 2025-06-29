.text
.globl main

.data
_nl: .asciiz "\n"

.text

main:
move $fp, $sp
addiu $sp, $sp, -4 # Aloca espaco para var
addiu $sp, $sp, -4
sw $t0, 0($sp)
addiu $sp, $sp, -4
sw $t0, 0($sp)
addiu $sp, $sp, -4
sw $t0, 0($sp)
li $t0, 50
lw $t1, 0($sp)
addiu $sp, $sp, 4
move $t2, $t0
move $t0, $t1
move $t1, $t2
lw $t1, 0($sp)
addiu $sp, $sp, 4
move $t2, $t0
move $t0, $t1
move $t1, $t2
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
move $a0, $t0
li $v0, 1
syscall
la $a0, _nl
li $v0, 4
syscall
addiu $sp, $sp, -4
sw $t0, 0($sp)
li $t0, 2
lw $t1, 0($sp)
addiu $sp, $sp, 4
move $t2, $t0
move $t0, $t1
move $t1, $t2
mul $t0, $t0, $t1
addiu $sp, $sp, -4
sw $t0, 0($sp)
addiu $sp, $sp, -4
sw $t0, 0($sp)
li $t0, 4
lw $t1, 0($sp)
addiu $sp, $sp, 4
move $t2, $t0
move $t0, $t1
move $t1, $t2
div $t0, $t0, $t1
lw $t1, 0($sp)
addiu $sp, $sp, 4
move $t2, $t0
move $t0, $t1
move $t1, $t2
sub $t0, $t0, $t1
move $a0, $t0
li $v0, 1
syscall

# Fim do programa (syscall 10)
li $v0, 10
syscall
