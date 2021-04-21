Trabalho:
1. Nenhuma variável pode ser declarado em todo o programa, somente ponteiros. Todos os dados do programa devem ser guardados dentro do pBuffer.
    (a) Exemplo do que não pode: int c; char a; int v[10]. Nem mesmo como parâmetro de função. Só ponteiros que apontam para dentro do pBuffer.
2. Imprimir de forma ordenada usando uma fila ordenada
3. O usuário escolhe um parâmetro de ordenação e uma fila ordenada é criada
    (a) Depois o programa imprime na tela o conteúdo da fila
4. Implementar a base de dados da agenda usando lista duplamente ligada
    (a) Somente essa base de dados pode ficar fora do buffer principal, ou seja, pode usar um malloc para cada nodo.

Os exercicios foram realizados utilizando o seguinte SO: LINUX
    (a)Metodo de compilacao: gcc -g -Wall main.c agenda.c -o nome
    (b)Executando: ./nome