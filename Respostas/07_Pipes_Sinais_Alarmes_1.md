1. Quantos pipes ser�o criados ap�s as linhas de c�digo a seguir? Por qu�?
(a)
```C
int pid;
int fd[2];
pipe(fd);
pid = fork();
```
Nesse caso, o t�nel � aberto antes que aconte�a uma nova bifurca��o. Assim, � criado apenas um pipe.

(b)
```C
int pid;
int fd[2];
pid = fork();
pipe(fd);
```
Nesse c�digo o pipe � criado ap�s a ocorr�ncia do fork. Assim, s�o criados dois pipes, sendo que n�o ocorrer� comunica��o porque cada um criou seu pr�prio Pipe.

2. Apresente mais cinco sinais importantes do ambiente Unix, al�m do `SIGSEGV`, `SIGUSR1`, `SIGUSR2`, `SIGALRM` e `SIGINT`. Quais s�o suas caracter�sticas e utilidades?
`SIGSEGV`: Emitido em casi de viola��o de segmenta��o.
`SIGUSR1` e `SIGUSR2`: Sinais dispon�veis ao usu�rio para comunica��o interprocessual.
`SIGALRM`: Rel�gio: emitido quando o rel�gio de um processo p�ra. O rel�gio � colocado em fucionamento utilizando a primitiva alarm().
`SIGINT`: Sinal emitido aos processos do terminal quando as teclas de interrup��o do teclado s�o acionadas. 
`SIGHUP`: Sinal emitido aos processos associados a um terminal quando este se "desconecta" (corte).
`SIGQUIT`: Sinal emitido aos processos do terminal quando as teclas de abandono do teclado s�o acionadas.
`SIGKILL`: Sinal emitido para matar processos. N�o pode ser ignorado nem interceptado.
`SIGSYS`: Sinal emitido quando � colocado argumento incorreto de uma chamada de sistema.
`SIGPIPE`: Sinal emitido quando ocorre a escrita sobre um pipe n�o aberto em leitura.


3. Considere o c�digo a seguir:
```C
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void tratamento_alarme(int sig)
{
	system("date");
	alarm(1);
}

int main()
{
	signal(SIGALRM, tratamento_alarme);
	alarm(1);
	printf("Aperte CTRL+C para acabar:\n");
	while(1);
	return 0;
}
```
Sabendo que a fun��o `alarm()` tem como entrada a quantidade de segundos para terminar a contagem, qu�o precisos s�o os alarmes criados neste c�digo? De onde vem a imprecis�o? Este � um m�todo confi�vel para desenvolver aplica��es em tempo real?

Devido �s interrup��es em sua execu��o por outros processos paralelos no kernel, que dependem do processador da m�quina (dividido entre os processos), a precis�o da fun��o alarm() � na ordem de microsegundos. Logo pode-se afirmar que para algumas aplica��es em tempo real ela n�o � recomendada.