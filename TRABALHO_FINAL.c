#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

#define SAIR 5
#define CONFIRM 2 
#define SUBMENU 2
#define LIST 2

void buffer_clean();
void gotoxy(short x, short y);
void box(short x, short y);

typedef struct Sheet_Students { 
	int mat;
	char name[100];
	float not1; 
	float not2; 
	float average;
} turma;

void main() {
	char cantoec = 201, cantoeb = 200, cantodc = 187, cantodb = 188, cima = 205 , lado = 186, cruze = 204, cruzd = 185, auxname[100]; 
	int option = 0, i = 0, allst = 0, allid = 0, id = 0, error = 0, confirm = 0, submenu = 0, ok = 0, whati = 0, yorn = 0, x = 0, have = 0, list = 0, optionlist = 0, go = 0, j = 0;
	turma student[150];
	
	while (option != SAIR) {
		printf("%c", cantoec);	         
		for(i = 1; i < 40; i++){
			printf("%c", cima);
		}
		printf("%c\n", cantodc);
		printf("%c\t\t\t\t\t%c\n",lado,lado);
		printf("%c                M E N U                %c\n",lado,lado);
		printf("%c\t\t\t\t\t%c\n",lado,lado);
		printf("%c\t\t\t\t\t%c\n",lado,lado);
		printf("%c\t Alunos Cadastrados [%3d]       %c\n",lado, allst, lado);
		printf("%c\t\t\t\t\t%c\n",lado,lado);
		printf("%c\t [1].Incluir Alunos             %c\n",lado,lado);
		printf("%c\t [2].Excluir Alunos             %c\n",lado,lado);
		printf("%c\t [3].Listar Alunos              %c\n",lado,lado);
		printf("%c\t [4].Lancar Nota                %c\n",lado,lado);
		printf("%c\t [5].Sair                       %c\n",lado,lado);
		printf("%c\t\t\t\t\t%c\n",lado,lado);
		printf("%c\t O que deseja fazer?            %c\n",lado,lado);
		printf("%c\t\t\t\t\t%c\n",lado,lado);
		printf("%c\t\t\t\t\t%c\n",lado,lado);
		printf("%c", cantoeb);
		for(i = 1; i < 40; i++){
			printf("%c", cima);
		}
		printf("%c\n", cantodb);
		gotoxy(9, 14);
		scanf("%d", &option);
		
		if (option == 1) {
			option = 0;
			system("cls");
			while(submenu != SUBMENU) {
				
				printf("%c", cantoec);	         
				for(i = 1; i < 40; i++){
					printf("%c", cima);
				}
				printf("%c\n", cantodc);		
				for(i = 1; i < 16; i++){
					printf("%c\t\t\t\t\t%c\n",lado,lado);
				}
				printf("%c", cantoeb);
				for(i = 1; i < 40; i++){
					printf("%c", cima);
				}
				printf("%c\n", cantodb);
				gotoxy(0,2);
				printf("%c      I N C L U I R   A L U N O S      ", lado);
				
				while(confirm != CONFIRM) {
					buffer_clean();
					gotoxy(5,5);
					printf("Nome......: ");
					fgets(student[allid].name, 100, stdin);
					while(error == 0) {
						if (go > 0) {
							printf("%c", cantoec);	         
							for(i = 1; i < 40; i++){
								printf("%c", cima);
							}
							printf("%c\n", cantodc);		
							for(i = 1; i < 16; i++){
								printf("%c\t\t\t\t\t%c\n",lado,lado);
							}
							printf("%c", cantoeb);
							for(i = 1; i < 40; i++){
								printf("%c", cima);
							}
							printf("%c\n", cantodb);
							gotoxy(0,2);
							printf("%c      I N C L U I R   A L U N O S      ", lado);
							gotoxy(5,5);
							printf("Nome......: %s", student[allid].name);
						}
						gotoxy(5,6);
						printf("Matricula.: ");
						scanf("%d", &id);
						if (id != 98) {
							if (allid == 0) {
								student[allid].mat = id;
								have++;
							} else {
								for(i = 0; i <= allid; i++) {
									if(student[i].mat == id) {
										error++;
									}
								}
							}
						} else {
							error = 1;
						}
						if (error > 0) {
							gotoxy(5,14);
							printf("A matricula ja existe!");
							gotoxy(0,17);
							system("pause");
							system("cls");
							error = 0;
							go++;
						} else if (allst >= 100) {
							gotoxy(5,14);
							printf("Nao e possivel cadastrar mais alunos.");
							gotoxy(0,17);
							system("pause");
							system("cls");
							confirm = CONFIRM;
							error = 1;
						} else {
							student[allid].mat = id;
							error = 1;
						}
					}
					go = 0;
					error = 0;
					gotoxy(5,7);
					printf("Nota.1....: ");
					scanf("%f", &student[allid].not1);
					gotoxy(5,8);
					printf("Nota.2....: ");
					scanf("%f", &student[allid].not2);
					student[allid].average = (student[allid].not1 + student[allid].not2) / 2;
					gotoxy(5,9);
					printf("Media.....: %.2f\n\n", student[allid].average);
					gotoxy(5,12);
					printf("[1] Para confirmar"); 
					gotoxy(5,13);
					printf("[2] Para Cancelar");
					gotoxy(5,14);
					scanf("%d", &confirm);
					if (confirm == 2) {
						system("cls");
						if (allid == 0) {
							have = 0;
						}
					} else if (confirm == 1) {
						buffer_clean();
						allid++;
						allst++;
						system("cls");
						confirm = 2;
					}
				}
				confirm = 0;
				printf("%c", cantoec);	         
				for(i = 1; i < 40; i++){
					printf("%c", cima);
				}
				printf("%c\n", cantodc);		
				for(i = 1; i < 9; i++){
					printf("%c\t\t\t\t\t%c\n",lado,lado);
				}
				printf("%c", cantoeb);
				for(i = 1; i < 40; i++){
					printf("%c", cima);
				}
				printf("%c\n", cantodb);
				gotoxy(0,2);
				printf("%c      I N C L U I R   A L U N O S      ", lado);
				gotoxy(5,5);
				printf("[1] Incluir Aluno");
				gotoxy(5,6);
				printf("[2] Voltar ao Menu");
				gotoxy(5,7);
				scanf("%d", &submenu);
				if(submenu == 1) {
					submenu = 0;
					system("cls");
				} else if (submenu == 2) {
					submenu = 2;
					system("cls");
				}
			}	
			submenu = 0;
		}
		
		buffer_clean();
		
		if (option == 2) {
			option = 0;
			system("cls");
			while (submenu != SUBMENU) {
				
				printf("%c", cantoec);	         
				for(i = 1; i < 40; i++){
					printf("%c", cima);
				}
				printf("%c\n", cantodc);		
				for(i = 1; i < 16; i++){
					printf("%c\t\t\t\t\t%c\n",lado,lado);
				}
				printf("%c", cantoeb);
				for(i = 1; i < 40; i++){
					printf("%c", cima);
				}
				printf("%c\n", cantodb);
				gotoxy(0,2);
				printf("%c      E X C L U I R   A L U N O S      ", lado);
				
				gotoxy(5,4);
				printf("Para excluir um aluno,");
				gotoxy(5,5);
				printf("digite a matricula do mesmo:");
				gotoxy(5,6);
				scanf("%d", &id);
				for(i = 0; i < allid; i++) {
					if (student[i].mat == id) {
						ok++;
						whati = i;
					}
				} 
				if (ok == 1) {
					gotoxy(5,8);
					printf("Deseja excluir o aluno %s", student[whati].name); 
					gotoxy(5,9);
					printf("que possui a matricula %d?", student[whati].mat);
					gotoxy(5,11);
					printf("[1] Sim");
					gotoxy(5,12);
					printf("[2] Nao");
					gotoxy(5,13);
					scanf("%d", &yorn);
					if (yorn == 1) {
						if(allst == 1) {
							have = 0;
						}
						allst--;
						student[whati].average = 1999;
						student[whati].mat = 1576159159;
						gotoxy(5,14);
						printf("Aluno excluido com sucesso!\n");
						gotoxy(0,17);
						system("pause");
						system("cls");
					} 
				} else {
					gotoxy(5,14);
					printf("Erro! Essa matricula nao existe!\n");
					gotoxy(0,17);
					system("pause");
					system("cls");
				}
				ok = 0;
				yorn = 0;
				printf("%c", cantoec);	         
				for(i = 1; i < 40; i++){
					printf("%c", cima);
				}
				printf("%c\n", cantodc);		
				for(i = 1; i < 11; i++){
					printf("%c\t\t\t\t\t%c\n",lado,lado);
				}
				printf("%c", cantoeb);
				for(i = 1; i < 40; i++){
					printf("%c", cima);
				}
				printf("%c\n", cantodb);
				gotoxy(0,2);
				printf("%c      E X C L U I R   A L U N O S      ", lado);
				gotoxy(5,4);
				printf("Deseja excluir outro aluno ou");
				gotoxy(5,5);
				printf("voltar ao menu principal?");
				gotoxy(5,7);
				printf("[1] Excluir Aluno");
				gotoxy(5,8);
				printf("[2] Menu Principal");
				gotoxy(5,9);
				scanf("%d", &submenu);
				system("cls");
			}
			submenu = 0;
		}
		
		if(option == 3) {
			option = 0;
			system("cls");
			if(have <= 0) {
				printf("%c", cantoec);	         
				for(i = 1; i < 40; i++){
					printf("%c", cima);
				}
				printf("%c\n", cantodc);		
				for(i = 1; i < 7; i++){
					printf("%c\t\t\t\t\t%c\n",lado,lado);
				}
				printf("%c", cantoeb);
				for(i = 1; i < 40; i++){
					printf("%c", cima);
				}
				printf("%c\n", cantodb);
				gotoxy(0,2);
				printf("%c     L I S T A   D E   A L U N O S     ", lado);
				gotoxy(3,4);
				printf("Erro!");
				gotoxy(3,5);
				printf("Nao existe nenhum aluno cadastrado!");
				gotoxy(0,8);
				system("pause");
				system("cls");
			} 
			else {
				for(i = 0; i < allid; i++){
					for(x = 0; x < allid; x++){
						if(student[i].average < student[x].average){
							turma auxiliar = student[x];
							student[x] = student[i];
							student[i] = auxiliar;
						}			
					}
				}
				j = 0;
				while(list != LIST) {
					while(j <= allid) {
						if (student[j].average != 1999 && j != allid) {
							
							printf("%c", cantoec);	         
							for(i = 1; i < 40; i++){
								printf("%c", cima);
							}
							printf("%c\n", cantodc);		
							for(i = 1; i < 16; i++){
								printf("%c\t\t\t\t\t%c\n",lado,lado);
							}
							printf("%c", cantoeb);
							for(i = 1; i < 40; i++){
								printf("%c", cima);
							}
							printf("%c\n", cantodb);
							
							gotoxy(0,2);
							printf("%c     L I S T A   D E   A L U N O S     ", lado);
							gotoxy(5,5);
							printf("Nome.......: %s", student[j].name);
							gotoxy(5,6);
							printf("Nota.1.....: %.2f\n", student[j].not1);
							gotoxy(5,7);
							printf("Nota.2.....: %.2f\n", student[j].not2);
							gotoxy(5,8);
							printf("Matricula..: %d\n", student[j].mat);
							gotoxy(5,9);
							printf("Media......: %.2f\n\n", student[j].average);
							gotoxy(5,11);
							printf("[1] < Pagina Anterior");
							gotoxy(5,12);
							printf("[2] Menu");
							gotoxy(5,13);
							printf("[3] > Proxima Pagina");
							gotoxy(5,14);
							scanf("%d", &optionlist);
						}
						if (j == allid) {
							list = 2;
						}
						if (optionlist == 1 && j > 0) {
							j--;
						} else if (optionlist == 2) {
							j = allid + 1;
							list = 2;
						} else if (optionlist == 3 && j < allid) {
							j++;	
						} else if (optionlist == 3 && j == allid) {
							j = allid + 1;
							list = 2;
							gotoxy(0,17);
							system("pause");
						}
						if (j != allid) {
							system("cls");
						}
					}
					system("cls");
				}
				list = 0;
				j = 0;
			}
		}
		if(option == 4) {
			option = 0;
			system("cls");
			while (submenu != SUBMENU) {
				
				printf("%c", cantoec);
				for(i = 1; i < 40; i++){
					printf("%c", cima);
				}
				printf("%c\n", cantodc);		
				for(i = 1; i < 16; i++){
					printf("%c\t\t\t\t\t%c\n",lado,lado);
				}
				printf("%c", cantoeb);
				for(i = 1; i < 40; i++){
					printf("%c", cima);
				}
				printf("%c\n", cantodb);
				gotoxy(0,2);
				printf("%c         L A N C A   N O T A          ", lado);
				gotoxy(5,5);
				printf("Para lancar a nota do aluno,");
				gotoxy(5,6);
				printf("digite a matricula do mesmo:");
				gotoxy(5,14);
				printf("[98] Sair");
				gotoxy(5,8);
				scanf("%d", &id);
				if (id != 98) {
					for (i = 0; i <= allid; i++) {
						if (student[i].mat == id) {
							ok++;
							whati = i;
						}
					} 
					
					if (ok == 1) {
						gotoxy(5,10);
						printf("Digite a primeira nota: ");
						scanf("%f", &student[whati].not1);
						gotoxy(5,11);
						printf("Digite a segunda nota: ");
						scanf("%f", &student[whati].not2);
						student[whati].average = (student[whati].not1 + student[whati].not2) / 2;
						gotoxy(5,12);
						printf("Media: %.2f\n", student[whati].average);
						gotoxy(0,17);
						system("pause");
						system("cls");
						submenu = 2;
					} else {
						gotoxy(5,14);
						printf("Erro! Essa matricula nao existe!\n");
						gotoxy(0,17);
						system("pause");
						system("cls");
					}
					ok = 0;
				} else {
					submenu = 2;
					system("cls");
				}
			}
			submenu = 0;
		}
		if (option == 5) {
			system("cls");
		}
	}
}

void buffer_clean() { 
	char c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}

void gotoxy(short x, short y) {
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void box (short x, short y) {
	short i, j;
	char cec = 201, ceb = 200, cdc = 187, cdb = 188, c = 205 , l = 186;
	
	printf("%c", cec);
	for(i = 1; i <= x-2; i++){
		printf("%c", c);
	}
	printf("%c\n", cdc);
	for(i = 1; i <= y-2; i++){
		printf("%c",l);
		for(j = 1; j <= x-2; j++){
			printf(" ");
		}
		printf("%c\n",l);
	}
	printf("%c", ceb);
	for(i = 1; i <= x-2; i++){
		printf("%c", c);
	}	
	printf("%c\n", cdb);
}
