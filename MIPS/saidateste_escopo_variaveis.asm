# constante: 10
li $t0, 10
# atribuição para x
# sw $t0, 0($s0)  # salva $t0 na variável
# variável: x
# constante: 10
li $t0, 10
# variável: x
# constante: 99
li $t0, 99
# atribuição para x
# sw $t0, 0($s0)  # salva $t0 na variável
# variável: x
# constante: 99
li $t0, 99
# variável: x
move $a0, $t0
li $v0, 1
syscall
# variável: x
# variável: x
move $a0, $t0
li $v0, 1
syscall
# variável: x
