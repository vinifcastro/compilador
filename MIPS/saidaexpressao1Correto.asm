# variável: y
# variável: z
# variável: v
# constante: 50
li $t0, 50
# atribuição para x
# sw $t0, 0($s0)  # salva $t0 na variável
# variável: x
# constante: 50
li $t0, 50
# atribuição para y
# sw $t0, 0($s0)  # salva $t0 na variável
# variável: y
# constante: 50
li $t0, 50
# atribuição para x
# sw $t0, 0($s0)  # salva $t0 na variável
# variável: x
# constante: 50
li $t0, 50
# atribuição para z
# sw $t0, 0($s0)  # salva $t0 na variável
# variável: z
# constante: 50
li $t0, 50
# atribuição para x
# sw $t0, 0($s0)  # salva $t0 na variável
# variável: x
# constante: 50
li $t0, 50
# atribuição para y
# sw $t0, 0($s0)  # salva $t0 na variável
# variável: y
# constante: 50
li $t0, 50
# atribuição para x
# sw $t0, 0($s0)  # salva $t0 na variável
# variável: x
# constante: 50
li $t0, 50
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
# variável: z
move $a0, $t0
li $v0, 1
syscall
# variável: z
# variável: x
move $t1, $t0
# constante: 2
li $t0, 2
mul $t0, $t1, $t0
# variável: x
# constante: 2
li $t0, 2
move $t1, $t0
# variável: y
move $t1, $t0
# constante: 4
li $t0, 4
div $t0, $t1, $t0
# variável: y
# constante: 4
li $t0, 4
sub $t0, $t1, $t0
# variável: x
move $t1, $t0
# constante: 2
li $t0, 2
mul $t0, $t1, $t0
# variável: x
# constante: 2
li $t0, 2
# variável: y
move $t1, $t0
# constante: 4
li $t0, 4
div $t0, $t1, $t0
# variável: y
# constante: 4
li $t0, 4
move $a0, $t0
li $v0, 1
syscall
# variável: x
move $t1, $t0
# constante: 2
li $t0, 2
mul $t0, $t1, $t0
# variável: x
# constante: 2
li $t0, 2
move $t1, $t0
# variável: y
move $t1, $t0
# constante: 4
li $t0, 4
div $t0, $t1, $t0
# variável: y
# constante: 4
li $t0, 4
sub $t0, $t1, $t0
# variável: x
move $t1, $t0
# constante: 2
li $t0, 2
mul $t0, $t1, $t0
# variável: x
# constante: 2
li $t0, 2
# variável: y
move $t1, $t0
# constante: 4
li $t0, 4
div $t0, $t1, $t0
# variável: y
# constante: 4
li $t0, 4
