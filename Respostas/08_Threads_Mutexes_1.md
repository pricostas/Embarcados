1. Quais são as vantagens e desvantagens em utilizar:
(a) fork?
Vantagens: No fork ocorre a crianção do processo filho através de um processo pai, sendo que o processo criado possui seu próprio espaço de memória.
Desvantagens: Pode ter mais esforço computacional porque é necessário copiar as funções do processo pai para o processo filho.
Por ter uma memória diferente, é mais difícil estabeler comunicaçãoo interprocessual; deve-se utilizar pipes, sinais, etc.

(b) threads?
Vantagens: Através da memória compartilhada é mais simples estabelecer comunicação entre threads.
Desvantagens: Por ter memória compartilhada, pode ocorrer corrupção de dados.

2. Quantas threads serão criadas após as linhas de código a seguir? Quantas coexistirão? Por quê?

(a)
```C
void* funcao_thread_1(void *arg);
void* funcao_thread_2(void *arg);

int main (int argc, char** argv)
{
	pthread_t t1, t2;
	pthread_create(&t1, NULL, funcao_thread_1, NULL);
	pthread_create(&t2, NULL, funcao_thread_2, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return 0;
}
```
Serão criadas duas threads e elas serão executadas simultaneamente (as duas coexistirão).

(b)
```C
void* funcao_thread_1(void *arg);
void* funcao_thread_2(void *arg);

int main (int argc, char** argv)
{
	pthread_t t1, t2;
	pthread_create(&t1, NULL, funcao_thread_1, NULL);
	pthread_join(t1, NULL);
	pthread_create(&t2, NULL, funcao_thread_2, NULL);
	pthread_join(t2, NULL);
	return 0;
}
```
Serão criadas duas threads, porém a segunda thread só executa após o término da primeira (não coexistem).

3. Apresente as características e utilidades das seguintes funções:
(a) `pthread_setcancelstate()`
Define o estado de cancelabildiade da thread em questão para um valor dado em state. O estado de cancelabilidade anterior é retornado no ponteiro buffer para oldstate. O argumento state deve ser um dos seguintes:
	PTHREAD_CANCEL_ENABLE
              A thread é cancelável. Estado de cancelabilidade padrão em novas threads, incluindo a inicial.

	PTHREAD_CANCEL_DISABLE
             A thread não é cancelável. Se ocorrer um pedido de cancelamento, é bloqueado até que a cancelabilidade esteja setada. 
```C       
	int pthread_setcancelstate(int state, int *oldstate);
```

(b) pthread_setcanceltype()
Define o tipo de cancelabilidade da thread dado o valor de type. O tipo de cancelabilidade anterior é retornado no ponteiro buffer para oldtype. O argumento type deve ser um dos seguintes:
       PTHREAD_CANCEL_DEFERRED
              Um pedido de cancelamento é adiado até que a thread chame uma função que é um ponto de cancelamento. Tipo de cancelabilidade padrão em novas threads, incluindo a inicial.

       PTHREAD_CANCEL_ASYNCHRONOUS
              A thread pode ser cancelada a qualquer momento, geralmente quando recebe um pedido de cancelamento. No entanto, isso não é garantido pelo sistema.

Referência Bibliográfica: http://man7.org/linux/man-pages/man3/pthread_setcanceltype.3.html