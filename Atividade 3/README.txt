Exercicio 3: Implemente uma árvore avl. O programa só pergunta 1 número para o
usuário 
	1. Primeiro cenário
		1. O programa pergunta quantos nós (n)
		2. O programa automaticamente gera n nós em sequência com valor aleatório e vai adicionando na árvore
			1.Use srand(time(0));
		3.Ao final, use um código de verificação (slide anterior) para validar a árvore e dar ok
	2.Segundo cenário
		1.Após a execução do primeiro cenário deve testar a árvore com os casos mostrado no seguinte link: https://stackoverflow.com/questions/3955680/how-to-check-if-my-avl-tree-implementation-is-correct

Os exercicios foram realizados utilizando o seguinte SO: LINUX
    (a)Metodo de compilacao: gcc -g -Wall randAVL.c treeAVL.c -o nome || gcc -g -Wall 	cenarioDois.c treeAVL.c -o nome 
    (b)Executando: ./nome