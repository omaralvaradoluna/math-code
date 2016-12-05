/* 
Algoritmo de Warshall para el cálculo de la Cerradura Transitiva de una relacion 
Omar Alonso Alvarado Luna 
Estructuras Discretas 
Semestre 2007-2 
Facultad de Ingenieria, UNAM 
21 de Marzo de 2007 
*/ 
#include  
#include  
#define SIZE 20 
// FUNCION PARA UNA SUMA BINARIA 
int sumabin(int sba, int sbb){ 
  int res=0; 
  if(sba==1||sbb==1) res=1; 
  return res; 
} 
int main(){ 
/* 
SE CREAN LAS MATRICES AUXILIARES Y LA MATRIZ TRIDIMENSIONAL DONDE  
EL PRIMER VALOR ES PARA M_k 
EL SEGUNDO VALOR ES PARA EL NUMERO DE RENGLONES 
EL TERCER VALOR ES PARA EL NUMERO DE COLUMNAS 
*/ 
 int Matriz[SIZE][SIZE][SIZE]; 
 int temp_1[SIZE][SIZE]; 
 int temp_2[SIZE][SIZE]; 
 int a, i, j, k; 
 printf("Algoritmo de Warshall - Cerradura Transitivann"); 
//la cardinalidad del conjunto de relacion nos define una matriz cuadrada 
//tambien nos define el numero de iteraciones ya que a partir de M_k+1 
//la operacion nos dara la misma matriz hasta el infinito 
 printf("Introduzca la cardinalidad del Conjunto: "); 
 do{ 
                     
   scanf("%d", &a); 
   if(a20) printf("Introduzca un valor entre 1 y 20: "); 
 }while(a20); 
 printf("n"); 
 //ENTRADA DE DATOS DE LA MATRIZ DE RELACION M_0 
 for(i=0;i<a;i++){ 
    for(j=0;j<a;j++){ 
      printf("Valor de A_%d_%d: ", i+1, j+1); 
      do{ 
        scanf("%d", &Matriz[0][i][j]); 
        if(Matriz[0][i][j]!=0&&Matriz[0][i][j]!=1) printf("Introduzca solo UNO o 
CERO para Valor de A_%d_%d: ", i+1, j+1); 
      }while(Matriz[0][i][j]!=0&&Matriz[0][i][j]!=1); 
    } 
 } 

//CALCULA M A LA INFINITO, SE DETIENE EN K= AL TAMAÑO YA QUE LA SIGUIENTES 
OPERACIONES 
 //NOS DARAN LA MISMA MATRIZ COMO SE DIJO ANTERIORMENTE 
 for(k=0;k<=a;k++){  
    
   //nos apoyamos de la matriz temp_2 para hacer la multiplicacion M_i_k * M_k_j 
   for(i=0;i<a;i++){ 
      for(j=0;j<a;j++){ 
        temp_2[i][j] = Matriz[k][i][j]; 
         
      } 
   } 
     //CALCULAMOS LA MATRIZ K 
     for(i=0;i<a;i++){ 
        for(j=0;j<a;j++){ 
           //multiplicamos M_i_k * M_k_j 
           temp_1[i][j]=temp_2[i][k]*temp_2[k][j]; 
           //Se hace la suma binaria para obterner la matriz k 
           Matriz[k+1][i][j]=sumabin(Matriz[k][i][j],temp_1[i][j]); 
        } 
     } 
   if(k!=a) printf("nnMatriz_%dn", k); 
   else printf("nnMatriz_%d FINAL: nn", k); 
   //imprime la matriz_k 
   for(i=0;i<a;i++){ 
       
      printf("n"); 
      for(j=0;j<a;j++){ 
        printf(" %d ", Matriz[k][i][j]); 
         
      } 
   } 
     
 }//TERMINA CALCULA M A LA INFINITO 
  
getch(); 
} 
