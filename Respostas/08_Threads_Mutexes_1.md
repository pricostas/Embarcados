1. Quais s�o as vantagens e desvantagens em utilizar:
(a) fork?
Vantagens: No fork ocorre a crian��o do processo filho atrav�s de um processo pai, sendo que o processo criado possui seu pr�prio espa�o de mem�ria.
Desvantagens: Pode ter mais esfor�o computacional porque � necess�rio copiar as fun��es do processo pai para o processo filho.
Por ter uma mem�ria diferente, � mais dif�cil estabeler comunica��oo interprocessual; deve-se utilizar pipes, sinais, etc.

(b) threads?
Vantagens: Atrav�s da mem�ria compartilhada � mais simples estabelecer comunica��o entre threads.
Desvantagens: Por ter mem�ria compartilhada, pode ocorrer corrup��o de dados.

2. Quantas threads ser�o criadas ap�s as linhas de c�digo a seguir? Quantas coexistir�o? Por qu�?

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
Ser�o criadas duas threads e elas ser�o executadas simultaneamente (as duas coexistir�o).

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
Ser�o criadas duas threads, por�m a segunda thread s� executa ap�s o t�rmino da primeira (n�o coexistem).

3. Apresente as caracter�sticas e utilidades das seguintes fun��es:
(a) `pthread_setcancelstate()`
Define o estado de cancelabildiade da thread em quest�o para um valor dado em state. O estado de cancelabilidade anterior � retornado no ponteiro buffer para oldstate. O argumento state deve ser um dos seguintes:
	PTHREAD_CANCEL_ENABLE
              A thread � cancel�vel. Estado de cancelabilidade padr�o em novas threads, incluindo a inicial.

	PTHREAD_CANCEL_DISABLE
             A thread n�o � cancel�vel. Se ocorrer um pedido de cancelamento, � bloqueado at� que a cancelabilidade esteja setada. 
```C       
	int pthread_setcancelstate(int state, int *oldstate);
```

(b) pthread_setcanceltype()
Define o tipo de cancelabilidade da thread dado o valor de type. O tipo de cancelabilidade anterior � retornado no ponteiro buffer para oldtype. O argumento type deve ser um dos seguintes:
       PTHREAD_CANCEL_DEFERRED
              Um pedido de cancelamento � adiado at� que a thread chame uma fun��o que � um ponto de cancelamento. Tipo de cancelabilidade padr�o em novas threads, incluindo a inicial.

       PTHREAD_CANCEL_ASYNCHRONOUS
              A thread pode ser cancelada a qualquer momento, geralmente quando recebe um pedido de cancelamento. No entanto, isso n�o � garantido pelo sistema.

Refer�ncia Bibliogr�fica: http://man7.org/linux/man-pages/man3/pthread_setcanceltype.3.html