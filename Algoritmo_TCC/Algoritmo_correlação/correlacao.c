#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float** aloca_matriz(int lin, int col);
float* aloca_vetor(int tam);
float calc_numerador(float*, float*,float, float, int);
float calc_denominador(float*, float*,float, float, int);

int main(int argc, char* argv[]){


int lin, col,i,j;
float** malha1 = NULL, **malha2 = NULL;
float* malha1_x = NULL, *malha1_y = NULL, *malha2_x = NULL, *malha2_y = NULL, *malha1_z = NULL, *malha2_z = NULL;
float cont_x_1 = 0.0, cont_y_1 = 0.0, cont_x_2 = 0.0, cont_y_2 = 0.0, cont_z_1 = 0.0, cont_z_2 = 0.0;
float media_x_1 = 0.0, media_y_1 = 0.0, media_x_2 = 0.0, media_y_2 = 0.0, media_z_1 = 0.0, media_z_2 = 0.0;
float numerador_x, denominador_x, correlacao_x, numerador_y, denominador_y, correlacao_y, numerador_z, denominador_z, correlacao_z;

FILE* arq_malha1;
FILE* arq_malha2;

if(argc == 3){
        
lin = atoi(argv[1]);
col = atoi(argv[2]);

arq_malha1 = fopen("arq_malha1.txt","r");
arq_malha2 = fopen("arq_malha2.txt","r");

malha1 = aloca_matriz(lin,col);
malha2 = aloca_matriz(lin,col);
malha1_x = aloca_vetor(lin);
malha1_y = aloca_vetor(lin);
malha1_z = aloca_vetor(lin);
malha2_x = aloca_vetor(lin);
malha2_y = aloca_vetor(lin);
malha2_z = aloca_vetor(lin);

for(i=0;i<lin;i++){
   for(j=0;j<col;j++){
      fscanf(arq_malha1,"%f", &malha1[i][j]); 
	  fscanf(arq_malha2,"%f", &malha2[i][j]); 
   }
}
/*
for(i=0;i<lin;i++){
   for(j=0;j<col;j++){
     //printf("malha1 : %f\n", malha1[i][j]);
	  //printf("malha2 : %f\n", malha2[i][j]);
   }
   printf("\n");
}
*/

// coloca os valores de x e y das malhas em vetores diferentes.

for(i=0;i<lin;i++){
   for(j=0;j<col;j++){
      
	  malha1_x[i] = malha1[i][0];	  	  
	  malha1_y[i] = malha1[i][1];	  
	  malha1_z[i] = malha1[i][2];	  
	  malha2_x[i] = malha2[i][0];	  
	  malha2_y[i] = malha2[i][1];
	  malha2_z[i] = malha2[i][2];
	  
   }
}

for(i=0;i<lin;i++){

      cont_x_1 += malha1_x[i];	  
	  cont_y_1 += malha1_y[i];	  
	  cont_z_1 += malha1_z[i];	  
	  cont_x_2 += malha2_x[i];	  	  
	  cont_y_2 += malha2_y[i];
	  cont_z_2 += malha2_z[i];
	  //printf("malha2_y : %f\n", malha2_y[i]);

}

media_x_1 = (cont_x_1/lin);
printf("media_x_1 : %f", media_x_1);
media_y_1 = (cont_y_1/lin);
media_z_1 = (cont_z_1/lin);
media_x_2 = (cont_x_2/lin);
printf("media_x_2 : %f\n", media_x_2);
media_y_2 = (cont_y_2/lin);
media_z_2 = (cont_z_2/lin);

numerador_x = calc_numerador(malha1_x, malha2_x, media_x_1, media_x_2, lin);
denominador_x = calc_denominador(malha1_x, malha2_x, media_x_1, media_x_2, lin);

correlacao_x = (numerador_x/denominador_x);

numerador_y = calc_numerador(malha1_y, malha2_y, media_y_1, media_y_2, lin);
denominador_y = calc_denominador(malha1_y, malha2_y, media_y_1, media_y_2, lin);

correlacao_y = (numerador_y/denominador_y);

numerador_z = calc_numerador(malha1_z, malha2_z, media_z_1, media_z_2, lin);
denominador_z = calc_denominador(malha1_z, malha2_z, media_z_1, media_z_2, lin);

correlacao_z = (numerador_z/denominador_z);


//printf("numerador_x : %f\n", numerador_x);
//printf("denominador_x : %f\n", denominador_x);
printf("\ncorrelacao em x : %f\n\n", correlacao_x);
printf("correlacao em y : %f\n\n", correlacao_y);
printf("correlacao em z : %f\n\n", correlacao_z);


}

else{

 printf("\n\tParametros incorretos!!!\n");
 printf("\nOs parametros corretos sao: Nome do executavel + quantidade de linhas + quantidade de colunas\n");

}

return 0;
}

float* aloca_vetor(int tam){
	
	float *vet = NULL;
	int i;
	for(i=0;i<tam;i++){
        vet = (float*)malloc(tam*sizeof(float));
    }
	    return vet;
}


float** aloca_matriz(int lin, int col){
	float **aux = NULL;
	
	aux = (float **) malloc (lin * sizeof(float *));
	if(!aux){
		printf("Erro ao alocar memoria\n\n");
		exit(1);
	}else{
		int i;
		for(i = 0; i < lin; i++){
			aux[i] = (float *) malloc(col * sizeof(float));
			if(!aux[i]){
				printf("Erro ao alocar memoria\n\n");
				exit(1);
			}
		}
	}
	
	return aux;
}


float calc_numerador(float* malha1, float* malha2,float media1, float media2, int lin){

int i;
float soma = 0.0;

for(i=0;i<lin;i++){
  
  soma += ((malha1[i] - media1) * (malha2[i] - media2));  
 // printf("soma_numerador : %f\n", soma);
  //getch();
  
}
//printf("soma_numerador : %f\n", soma);
return soma;
}

float calc_denominador(float* malha1, float* malha2, float media1, float media2, int lin){

int i;
float result;

float soma1 = 0.0, soma2 = 0.0;

for(i=0;i<lin;i++){
 
   soma1 += pow((malha1[i] - media1), 2);
   soma2 += pow((malha2[i] - media2), 2);
}

  soma1 = sqrt(soma1);
  soma2 = sqrt(soma2);

result = soma1 * soma2;

return result;
}