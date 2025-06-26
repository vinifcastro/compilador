# variável: x
# variável: y
# constante: 10
li $t0, 10
# atribuição para x
# sw $t0, 0($s0)  # salva $t0 na variável
# variável: x
# constante: 10
li $t0, 10
# constante: 39
li $t0, 39
# atribuição para y
# sw $t0, 0($s0)  # salva $t0 na variável
# variável: y
# constante: 39
li $t0, 39
# variável: x
move $a0, $t0
li $v0, 1
syscall
# variável: x
# variável: y
move $a0, $t0
li $v0, 1
syscall
# variável: y
