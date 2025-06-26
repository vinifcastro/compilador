# variável: n
# variável: n
# constante: 0
li $t0, 0
# constante: 1
li $t0, 1
# variável: n
move $t1, $t0
# variável: fatorial
# variável: n
move $t1, $t0
# constante: 1
li $t0, 1
sub $t0, $t1, $t0
# variável: n
# constante: 1
li $t0, 1
mul $t0, $t1, $t0
# variável: n
# variável: fatorial
# variável: n
move $t1, $t0
# constante: 1
li $t0, 1
sub $t0, $t1, $t0
# variável: n
# constante: 1
li $t0, 1
# variável: n
# constante: 1
li $t0, 1
move $t1, $t0
# constante: 0
li $t0, 0
sub $t0, $t1, $t0
# constante: 1
li $t0, 1
# constante: 0
li $t0, 0
# atribuição para n
# sw $t0, 0($s0)  # salva $t0 na variável
# variável: n
# constante: 1
li $t0, 1
move $t1, $t0
# constante: 0
li $t0, 0
sub $t0, $t1, $t0
# constante: 1
li $t0, 1
# constante: 0
li $t0, 0
# variável: n
# constante: 0
li $t0, 0
# variável: n
# variável: n
move $a0, $t0
li $v0, 1
syscall
# variável: n
# variável: fatorial
# variável: n
move $a0, $t0
li $v0, 1
syscall
# variável: fatorial
# variável: n
