# variável: x
# variável: x
# constante: 39
li $t0, 39
# atribuição para x
# sw $t0, 0($s0)  # salva $t0 na variável
# variável: x
# constante: 39
li $t0, 39
# variável: x
move $a0, $t0
li $v0, 1
syscall
# variável: x
# constante: 0
li $t0, 0
# variável: x
# constante: 2
li $t0, 2
# atribuição para x
# sw $t0, 0($s0)  # salva $t0 na variável
# variável: x
# constante: 2
li $t0, 2
# variável: duplicado
# variável: x
