# variável: n
# variável: n
# constante: 1
li $t0, 1
# variável: n
# variável: fib
# variável: n
move $t1, $t0
# constante: 1
li $t0, 1
sub $t0, $t1, $t0
# variável: n
# constante: 1
li $t0, 1
move $t1, $t0
# variável: fib
# variável: n
move $t1, $t0
# constante: 2
li $t0, 2
sub $t0, $t1, $t0
# variável: n
# constante: 2
li $t0, 2
add $t0, $t1, $t0
# variável: fib
# variável: n
move $t1, $t0
# constante: 1
li $t0, 1
sub $t0, $t1, $t0
# variável: n
# constante: 1
li $t0, 1
# variável: fib
# variável: n
move $t1, $t0
# constante: 2
li $t0, 2
sub $t0, $t1, $t0
# variável: n
# constante: 2
li $t0, 2
# variável: valor
# constante: 8
li $t0, 8
# atribuição para valor
# sw $t0, 0($s0)  # salva $t0 na variável
# variável: valor
# constante: 8
li $t0, 8
# variável: valor
move $a0, $t0
li $v0, 1
syscall
# variável: valor
# variável: fib
# variável: valor
move $a0, $t0
li $v0, 1
syscall
# variável: fib
# variável: valor
