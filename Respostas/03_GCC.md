Para todas as questões, compile-as com o gcc e execute-as via terminal.

1. Crie um "Olá mundo!" em C.
```C
    #include <stdio.h>
    
     int main(int argc, const char *argv[])
     {
             printf("Ola Mundo! \n"); 
             return 0;
     }
``` 

2. Crie um código em C que pergunta ao usuário o seu nome, e imprime no terminal "Ola " e o nome do usuário. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_1':
	$ ./ola_usuario_1
	$ Digite o seu nome: Eu
	$ Ola Eu

```C
#include <stdio.h>
    #include <stdlib.h>

    char name[20];
    
    int main(int argc, const char *argv[])
    {
        printf("Digite seu name: ");
        scanf("%s", name);
        printf("Olá %s \n", name);
        return 0;
    }
    ``` 

3. Apresente os comportamentos do código anterior nos seguintes casos:
	(a) Se o usuário insere mais de um nome.
		$ ./ola_usuario_1 Eu Mesmo

	$ ./ola_usuario
        $Digite seu nome: Priscilla Costa
        $Olá Priscilla

	(b) Se o usuário insere mais de um nome entre parênteses. Por exemplo:
		$ ./ola_usuario_1 "Eu Mesmo"

	$ ./ola_usuario
        $Digite seu nome: "Priscilla Costa"
        $Olá "Priscilla

	(c) Se é usado um pipe. Por exemplo:
		$ echo Eu | ./ola_usuario_1

        echo Oi | ./ola_usuario
        Digite seu nome: Olá Oi

	(d) Se é usado um pipe com mais de um nome. Por exemplo:
		$ echo Eu Mesmo | ./ola_usuario_1

        echo Oi Olá | ./ola_usuario
        Digite seu nome: Olá Oi

	(e) Se é usado um pipe com mais de um nome entre parênteses. Por exemplo:
		$ echo Eu Mesmo | ./ola_usuario_1

        echo "Oi Olá" | ./ola_usuario
        Digite seu nome: Olá Oi

	(f) Se é usado o redirecionamento de arquivo. Por exemplo:
		$ echo Ola mundo cruel! > ola.txt
		$ ./ola_usuario_1 < ola.txt

        echo Ola mundo cruel! > ola.txt
        ./ola_usuario < ola.txt 
        Digite seu nome: Olá Ola 


4. Crie um código em C que recebe o nome do usuário como um argumento de entrada (usando as variáveis argc e *argv[]), e imprime no terminal "Ola " e o nome do usuário. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_2':
	$ ./ola_usuario_2 Eu
	$ Ola Eu
	$

    código:
    ```C
    #include <stdio.h>
    #include <stdlib.h>
    
    int main(int argc, const char *argv[])
    {
            printf("Ola %s \n", argv[argc - 1]);
            return 0;
    }
    ```
    
    terminal:
    gcc argumento_ent.c -o argumento

    resultado:
    ./argumento Priscilla
    Ola Priscilla

5. Apresente os comportamentos do código anterior nos seguintes casos:
	(a) Se o usuário insere mais de um nome.
		$ ./ola_usuario_2 Eu Mesmo

        ./argumento Priscilla COsta
        Ola Costa

	(b) Se o usuário insere mais de um nome entre parênteses. Por exemplo:
		$ ./ola_usuario_2 "Eu Mesmo"

        ./argumento "Priscilla Costa"
        Ola Priscilla Costa

	(c) Se é usado um pipe. Por exemplo:
		$ echo Eu | ./ola_usuario_2

        echo Oi | ./argumento
        Ola ./argumento

	(d) Se é usado um pipe com mais de um nome. Por exemplo:
		$ echo Eu Mesmo | ./ola_usuario_2

        echo Oi Olá | ./argumento
        Ola ./argumento

	(e) Se é usado um pipe com mais de um nome entre parênteses. Por exemplo:
		$ echo Eu Mesmo | ./ola_usuario_2

        echo "Oi Olá" | ./argumento
        Ola ./argumento

	(f) Se é usado o redirecionamento de arquivo. Por exemplo:
		$ echo Ola mundo cruel! > ola.txt
		$ ./ola_usuario_2 < ola.txt

        ./argumento < ola.txt 
        Ola ./argumento>

6. Crie um código em C que faz o mesmo que o código da questão 4, e em seguida imprime no terminal quantos valores de entrada foram fornecidos pelo usuário. Por exemplo, considerando que o código criado recebeu o nome de 'ola_usuario_3':
	$ ./ola_usuario_3 Eu
	$ Ola Eu
	$ Numero de entradas = 2
	$

    código:
    ```C
    #include <stdio.h>
    #include <stdlib.h>
    
    int main(int argc, const char *argv[])
    {
            printf("Ola %s \n", argv[1]);
                printf("Numero de entradas = %d \n", argc);
                    return 0;
    }
    ```

    terminal:
    gcc valores.c -o valores

    resultado:
    ./valores Priscilla
    Ola Priscilla
    Numero de entradas = 2 


7. Crie um código em C que imprime todos os argumentos de entrada fornecidos pelo usuário. Por exemplo, considerando que o código criado recebeu o nome de 'ola_argumentos':
	$ ./ola_argumentos Eu Mesmo e Minha Pessoa
	$ Argumentos: Eu Mesmo e Minha Pessoa
	$
    
    ```C
#include <stdio.h>
#include <stdlib.h>
    int i;
    
    int main(int argc, const char *argv[])
    {
            printf("Argumentos: "); 
                for (i = 1; i < argc; i++) {
                    printf("%s ", argv[i]);
                }
            printf("\n");
            return 0;
    }```

8. Crie uma função que retorna a quantidade de caracteres em uma string, usando o seguinte protótipo: int Num_Caracs(char *string);
Salve-a em um arquivo separado chamado 'num_caracs.c'. Salve o protótipo em um arquivo chamado 'num_caracs.h'. Compile 'num_caracs.c' para gerar o objeto 'num_caracs.o'.

    questao8.c(main):

```C
    #include <stdio.h>
    #include "num_caracs.h"
    
    char nome[] = "Testando String";
    
    int main(int argc, const char *argv[])
    {
            printf("O tamanho da string e: %d", Num_Caracs(nome));
            return 0;
    }```

    Num_Caracs.c

```C
#include <stdio.h>
#include <stdlib.h>
#include "num_caracs.h"

int Num_Caracs(char *nome){
    
    int contador = 1;
    int i = 0;
    int tamanho_da_string;
    
    while(contador){
            if(nome[i] == '\0'){
                   contador = !contador;
                   tamanho_da_string = i;
            }
         i++;
    }
    return tamanho_da_string;
}```

    num_caracs.h

```C    // Arquivo num_caracs.h

    int Num_Caracs(char *nome);)```

    terminal:

    gcc -c questao8.c
    gcc -c Num_Caracs.c
    gcc -o questao8 questao8.o Num_Caracs.o
    ./questao8
    O tamanho da string e: 15

9. Re-utilize o objeto criado na questão 8 para criar um código que imprime cada argumento de entrada e a quantidade de caracteres de cada um desses argumentos. Por exemplo, considerando que o código criado recebeu o nome de 'ola_num_caracs_1':
	$ ./ola_num_caracs_1 Eu Mesmo
	$ Argumento: ./ola_num_caracs_1 / Numero de caracteres: 18
	$ Argumento: Eu / Numero de caracteres: 2
	$ Argumento: Mesmo / Numero de caracteres: 5
	$

    questao9.c (main)
    
```C
    #include <stdlib.h>
    #include "num_caracs.h"
    
    int main(int argc, char *argv[])
    {
            int i = 0;
            while (i < argc){
                   printf("%s / Numero de caracteres: %d \n",argv[i], Num_Caracs(argv[i]));
                   i++;
    }
    return 0;
    }```

        Num_Caracs.c

```C
    #include <stdio.h>
    #include <stdlib.h>
    #include "num_caracs.h"

    int Num_Caracs(char *nome){
    
    int contador = 1;
    int i = 0;
    int tamanho_da_string;
    
    while(contador){
            if(nome[i] == '\0'){
                   contador = !contador;
                   tamanho_da_string = i;
            }
         i++;
    }
    return tamanho_da_string;
    }```

    num_caracs.h

```C    // Arquivo num_caracs.h

    int Num_Caracs(char *nome);)```

    terminal:

    gcc -c questao9.c
    gcc -c Num_Caracs.c
    gcc -o questao9 questao9.o Num_Caracs.o

    ./questao9 Eu Mesmo
    ./questao9 / Numero de caracteres: 10 
    Eu / Numero de caracteres: 2 
    Mesmo / Numero de caracteres: 5

10. Crie um Makefile para a questão anterior.
    
    #Makefile

    questao9.o: questao9.c num_caracs.h
        gcc $(CFLAGS) -c questao9uestao9.c
    Num_Caracs.o: Num_Caracs.c num_caracs.h
        gcc $(CFLAGS) -c Num_Caracs_Caracs.c
    questao9: questao9.o Num_Caracs.o
        gcc $(CFLAGS) -o questao9   questao9.o Num_Caracs.o
    clean:
        rm -f *.o 

11. Re-utilize o objeto criado na questão 8 para criar um código que imprime o total de caracteres nos argumentos de entrada. Por exemplo, considerando que o código criado recebeu o nome de 'ola_num_caracs_2':
	$ ./ola_num_caracs_2 Eu Mesmo
	$ Total de caracteres de entrada: 25
	$

    questao11.c (main):

```C
    #include <stdio.h>
    #include <stdlib.h>
    #include "num_caracs.h"
    
    
    int main(int argc, char *argv[])
    {
        int i = 0;
        int  total = 0;
            while (i < argc){
                   total += Num_Caracs(argv[i]);
                   i++;
            }
        printf("Total de caracteres de entrada: %d", total);
        return 0;
    }```

    Num_Caracs.c:

```C
    #include <stdio.h>
    #include <stdlib.h>
    #include "num_caracs.h"

    int Num_Caracs(char *nome){
    
    int contador = 1;
    int i = 0;
    int tamanho_da_string;
    
    while(contador){
            if(nome[i] == '\0'){
                   contador = !contador;
                   tamanho_da_string = i;
            }
         i++;
    }
    return tamanho_da_string;
    }```

    num_caracs.h:

    // Arquivo num_caracs.h

 ```C   int Num_Caracs(char *nome);)```

    terminal:

    gcc -c questao11.c
    gcc -c Num_Caracs.c
    gcc -o questao11 questao11.o Num_Caracs.o

    resultado:

    ./questao11 Testando
    Total de caracteres de entrada: 19

12. Crie um Makefile para a questão anterior.

#Makefile

questao11.o: questao11.c num_caracs.h
	gcc $(CFLAGS) -c questao11.c
Num_Caracs.o: Num_Caracs.c num_caracs.h
	gcc $(CFLAGS) -c Num_Caracs.c
questao11: questao11.o Num_Caracs.o
	gcc $(CFLAGS) -o questao11 questao11.o Num_Caracs.o
clean:
rm -f *.o 
