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
li $t0, 0
lw $t1, 0($sp)
addiu $sp, $sp, 4
move $t2, $t0
move $t0, $t1
move $t1, $t2
L0:
addiu $sp, $sp, -4
sw $t0, 0($sp)
li $t0, 3
lw $t1, 0($sp)
addiu $sp, $sp, 4
move $t2, $t0
move $t0, $t1
move $t1, $t2
slt $t0, $t0, $t1
beq $t0, $zero, L1
addiu $sp, $sp, -4
sw $t0, 0($sp)
li $t0, 1
lw $t1, 0($sp)
addiu $sp, $sp, 4
move $t2, $t0
move $t0, $t1
move $t1, $t2
seq $t0, $t0, $t1
addiu $sp, $sp, -4
sw $t0, 0($sp)
addiu $sp, $sp, -4
sw $t0, 0($sp)
li $t0, 1
lw $t1, 0($sp)
addiu $sp, $sp, 4
move $t2, $t0
move $t0, $t1
move $t1, $t2
add $t0, $t0, $t1
lw $t1, 0($sp)
addiu $sp, $sp, 4
move $t2, $t0
move $t0, $t1
move $t1, $t2
j L0
L1:

# Fim do programa (syscall 10)
li $v0, 10
syscall
