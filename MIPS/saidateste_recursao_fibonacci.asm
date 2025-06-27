.text
.globl main

.data
_nl: .asciiz "\n"

.text

fib:
sw $ra, -4($sp)
sw $fp, -8($sp)
move $fp, $sp
addiu $sp, $sp, -8
addiu $sp, $sp, -4
sw $t0, 0($sp)
li $t0, 1
lw $t1, 0($sp)
addiu $sp, $sp, 4
move $t2, $t0
move $t0, $t1
move $t1, $t2
sle $t0, $t0, $t1
move $v0, $t0
j fib_exit
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
sub $t0, $t0, $t1
lw $t1, 0($sp)
addiu $sp, $sp, 4
move $t2, $t0
move $t0, $t1
move $t1, $t2
addiu $sp, $sp, -4
sw $t0, 0($sp)
addiu $sp, $sp, -4
sw $t0, 0($sp)
addiu $sp, $sp, -4
sw $t0, 0($sp)
li $t0, 2
lw $t1, 0($sp)
addiu $sp, $sp, 4
move $t2, $t0
move $t0, $t1
move $t1, $t2
sub $t0, $t0, $t1
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
add $t0, $t0, $t1
move $v0, $t0
j fib_exit
fib_exit:
move $sp, $fp
lw $ra, -4($sp)
lw $fp, -8($sp)
jr $ra

main:
move $fp, $sp
addiu $sp, $sp, -4 # Aloca espaco para var
addiu $sp, $sp, -4
sw $t0, 0($sp)
li $t0, 8
lw $t1, 0($sp)
addiu $sp, $sp, 4
move $t2, $t0
move $t0, $t1
move $t1, $t2
move $a0, $t0
li $v0, 1
syscall
addiu $sp, $sp, -4
sw $t0, 0($sp)
lw $t1, 0($sp)
addiu $sp, $sp, 4
move $t2, $t0
move $t0, $t1
move $t1, $t2
move $a0, $t0
li $v0, 1
syscall
la $a0, _nl
li $v0, 4
syscall

# Fim do programa (syscall 10)
li $v0, 10
syscall
