#include <stdio.h>
#include <string.h>
 
int main()
{
    char ID[10];
    char nombre[20];
    int stock= 0;
    int restock;
    float precio=0.0;
    int opc = 0, opc2 = 0;
    int len;
    int aux;
    int venta;
    int cant_nueva;
    float ganancias= 0.0;
    float descuento=0.0;
    do{
        printf("Seleccione una opcion: \n");
        printf("1.Registrar producto\n");
        printf("2.Vender producto\n");
        printf("3.Reabastecer producto\n");
        printf("4.Informacion producto\n");
        printf("5.Ganancias totales\n");
        printf("6.Salir\n");
        do{
            printf(">> ");
            aux = scanf("%d",&opc);
            if(aux != 1 || opc < 0){
                printf("Ingrese una opcion valida\n");
                while(getchar() != '\n');
            }
        }while (aux != 1 || opc < 0);
        
        switch(opc){
            case 1:
                printf("Ingresar el ID del producto: ");
                scanf("%s",&ID);
                printf("Ingresar el nombre del producto: ");
                getchar();
                fgets(nombre,20,stdin);
                len = strlen(nombre) - 1;
                nombre[len]='\0';

                printf("Ingresar el stock del producto: ");
                scanf("%d",&stock);
                printf("Ingresar el precio del producto: ");
                scanf("%f",&precio);
                break;
                case 2:
                 printf("Ingrese la cantidad a vender: ");
                scanf("%d", &venta);
  
                if (venta <= 0) {
                    printf("Error: La cantidad debe ser mayor a cero.\n");
                } else if (venta > stock) {
                    printf("Error: Stock insuficiente. Disponible: %d\n", stock);
                } else {
                  
                    printf("Ingrese porcentaje de descuento (0 si no aplica): ");
                    scanf("%f", &descuento);
                    
                    float precio_final = precio * (1 - (descuento / 100));
                    stock -= venta;
                    ganancias += (venta * precio_final);
                    
                    printf("Venta realizada con exito.\n");
                }
                break;
                case 3:
                printf("Ingrese cuantas nuevas unidades desea añadir: ");
                scanf("%S",&cant_nueva);
                 if (cant_nueva > 0) {
                    stock += cant_nueva;
                    printf("Stock actualizado.\n");
                } else {
                    printf("Error: Cantidad no valida.\n");
                }
                break;
            case 4:
                printf("Informacion del producto:\n");
                printf("ID: %s\n",ID);
                printf("Nombre: %s\n",nombre);
                printf("Stock: %d\n",stock);
                printf("Precio: %f\n",precio);
                break;
             case 5: 
                printf("\nGanancias totales acumuladas: $%.2f\n", ganancias);
                break;

            case 6: 
                printf("Saliendo del sistema\n");
                return 0;

        }

        printf("Desea seleccionar otra opcion: 1.Si/2.No: ");
        scanf("%d",&opc2);
    }while(opc2==1);


 
    return 0;
}