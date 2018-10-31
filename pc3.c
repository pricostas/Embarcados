#include <stdio.h>
#include <stdlib.h>

int opcao;

//to do list:
//identify pid of process: "gvfsd-gphoto2" and kill; (python to c converter?)
//create infinite loop for menu
//images to smartphone (pc4)

//comandos importantes:
//ps -A

void iniciando()
{
	//teste
}

void menu()
{
	while(1){
	printf("\nBem-vindo ao dispositivo Smart\n");
	printf("-----------------------------------------------------------------------\n");        
	printf("\nEscolha a opção desejada\n");
        printf("1- Tirar foto\n2- Calendário\n\n"); 
        scanf("%d", &opcao);
	printf("\n");
	printf("-----------------------------------------------------------------------\n"); 
        printf ("\nVocê escolheu a opção: %d\n", opcao);
	if (opcao<=2){        
	switch(opcao)
        {
                case 1:
                        system ("gphoto2 --trigger-capture");
                        printf("\nTirando foto\n");
                break;
		case 2: 
			printf("\n");
			system ("cal");
                        printf("\nMostrando calendário\n");
		break;
        }}
	else{
	printf("\n-----------------------------------------------------------------------\n");  
		printf("\nEsta opção é inválida. Escolha uma opção válida.\nOpções válidas:\n1- Tirar foto\n2- Calendário\n\n\n\n");
	}
    }
}


int main (int argc, char *argv[])
{
	iniciando();
	menu();
	
	return 0;
}
