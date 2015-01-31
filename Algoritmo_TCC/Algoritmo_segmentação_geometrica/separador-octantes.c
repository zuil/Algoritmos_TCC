#include<stdio.h>
#include<stdlib.h>
//#define tam 48485

float* aloca_vetor(int tam);

int main(int argc, char* argv[]){

int i,tam; 
float *x=NULL, *y=NULL, *z=NULL;  
FILE *xyz_posr;
FILE * arquivo_pontos;
FILE *x_pos_yz_negr;
FILE* xy_pos_z_negr;
FILE* xz_pos_y_negr;
FILE* xyz_negr;
FILE* x_neg_yz_posr;
FILE* xz_neg_y_posr;
FILE* xy_neg_z_posr;
 
if(argc == 2){

tam = atoi(argv[1]);
printf("tam :%d", tam);

arquivo_pontos = fopen("arquivo_pontos.txt","r"); 
 xyz_negr = fopen("xyz_negr.ply", "w");
 x_neg_yz_posr = fopen("x_neg_yz_posr.ply","w");
 xz_neg_y_posr = fopen("xz_neg_y_posr.ply","w");
 xy_neg_z_posr = fopen("xy_neg_z_posr.ply","w");
 xyz_posr = fopen("xyz_posr.ply","w");
 x_pos_yz_negr = fopen("x_pos_yz_negr.ply", "w"); 
 xy_pos_z_negr = fopen("xy_pos_z_negr.ply", "w");
 xz_pos_y_negr = fopen("xz_pos_y_negr.ply","w");
 
 x = aloca_vetor(tam);
 y = aloca_vetor(tam);
 z = aloca_vetor(tam);
 
 
    
     for(i=0;i<tam;i++){
        
          fscanf(arquivo_pontos,"%f %f %f\n", &x[i],&y[i],&z[i]); 
			//printf("X[i]%f\n", x[i]);
            if(x[i]>0){
                  if(y[i]>0&&z[i]>0){
                      fprintf(xyz_posr,"%f %f %f\n",x[i],y[i], z[i]);     
                  }
                
                     else if(y[i]<0&&z[i]<0){
                         fprintf(x_pos_yz_negr,"%f %f %f\n",x[i],y[i],z[i]);
                     
                          }
                          
                          else if(y[i]>0&&z[i]<0){ 
                               fprintf(xy_pos_z_negr,"%f %f %f\n",x[i],y[i],z[i]);
                               
                               }
                                
                                 else{
                                 
                                      fprintf(xz_pos_y_negr,"%f %f %f\n",x[i],y[i],z[i]);
                              }
           }
           
           
           
           if(x[i]<0){
           
                  if(y[i]<0&&z[i]<0){
                      fprintf(xyz_negr,"%f %f %f\n",x[i],y[i],z[i]);     
                  }
                
                     else if(y[i]>0&&z[i]>0){
                         fprintf(x_neg_yz_posr,"%f %f %f\n",x[i],y[i],z[i]);
                     
                          }
                          
                          else if(y[i]>0&&z[i]<0){ 
                               fprintf(xz_neg_y_posr,"%f %f %f\n",x[i],y[i],z[i]);
                               
                               }
                                
                                 else{
                                 
                                      fprintf(xy_neg_z_posr,"%f %f %f\n",x[i],y[i],z[i]);
                              }
           }   
    } 
         
}

getch();
return 0;
}

float* aloca_vetor(int tam){
	
	float *vet = NULL;
	int i;
	//for(i=0;i<tam;i++){
        vet = (float*)malloc (tam*sizeof(float)) 	;
    //}
	    return vet;
}
