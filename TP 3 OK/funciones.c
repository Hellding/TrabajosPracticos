#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void InicializarEstructura(eMovie *Peliculas, int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        (*(Peliculas+i)).estado=0;
    }
}

void AltaPeli(eMovie *Peliculas, int tam)
{
    int i;
    char auxtxt[3000];
    int auxnum;

    for(i=0; i<tam; i++)
    {
        system("cls");
        printf("\nIngrese el Titulo de la Pelicula, Rango[2 - 50]:\n");
        setbuf(stdin,NULL);
        scanf("%[^\n]",auxtxt);
        auxnum=strlen(auxtxt);
        if(auxnum<2||auxnum>50)
        {
            printf("\nERROR!!!El Titulo ingresado no esta en el rango permitido");
            printf("\nReingrese el Titulo de la Pelicula, Rango[2 - 20]:\n");
            setbuf(stdin,NULL);
            scanf("%[^\n]",auxtxt);
            auxnum=strlen(auxtxt);
        }
        else
        {
            strcpy((*(Peliculas+i)).titulo,auxtxt);
        }
        printf("\nIngrese el/los Genero/s de la Pelicula, Rango[2 - 50]:\n");
        setbuf(stdin,NULL);
        scanf("%[^\n]",(*(Peliculas+i)).genero);
        auxnum=strlen(auxtxt);
        if(auxnum<2||auxnum>50)
        {
            printf("\nERROR!!!El Genero no esta en rango permitido.");
            printf("\nReingrese el  de la Pelicula, Rango[2 - 20]:\n");
            setbuf(stdin,NULL);
            scanf("%[^\n]",auxtxt);
            auxnum=strlen(auxtxt);
        }
        else
        {
            strcpy((*(Peliculas+i)).titulo,auxtxt);
        }
        printf("\nIngrese el puntaje de la Pelicula, Rango[0 - 100]:\n");
        scanf("%d",&auxnum);
        if(auxnum<0||auxnum>100)
        {
            printf("\nERROR!!!El puntaje no esta en el rango permitido.");
            printf("\nReingrese el puntaje de la Pelicula, Rango[0 - 100]:\n");
            scanf("%d",&auxnum);
        }
        else
        {
            (*(Peliculas+i)).puntaje=auxnum;
        }
        printf("\nIngrese la Duracion de la Pelicula, Rango[5 min - 360 min]:\n");
        scanf("%d",&(*(Peliculas+i)).duracion);
        if(auxnum<5||auxnum>360)
        {
            printf("\nERROR!!!La Duracion no esta en el rango permitido.");
            printf("\nReingrese la Duracion de la Pelicula, Rango[5 min - 360 min]:\n");
            scanf("%d",&auxnum);
        }
        else
        {
            (*(Peliculas+i)).duracion=auxnum;
        }
        printf("\nIngrese la Descripcion de la Pelicula, Rango[2 - 2000]:\n");
        setbuf(stdin,NULL);
        scanf("%[^\n]",auxtxt);
        auxnum=strlen(auxtxt);
        if(auxnum<2||auxnum>2000)
        {
            printf("\nERROR!!!La Descripcion no esta en el rango permitido.");
            printf("\nReingrese la Descripcion de la Pelicula, Rango[2 - 2000]");
            setbuf(stdin,NULL);
            scanf("\n%[^\n]",auxtxt);
            auxnum=strlen(auxtxt);
        }
        else
        {
            strcpy((*(Peliculas+i)).descripcion,auxtxt);
        }
        printf("\nIngrese el Link de la Imagen de la Pelicula, Rango[20-500]\n");
        setbuf(stdin,NULL);
        scanf("%[^\n]",auxtxt);
        auxnum=strlen(auxtxt);
        if(auxnum<20||auxnum>500)
        {
            printf("\nERROR!!!El Link no esta en el rango permitido.");
            printf("\nReingrese el Link de la Imagen de la Pelicula, Rango[20-500]:\n");
            setbuf(stdin,NULL);
            scanf("%[^\n]",auxtxt);
            auxnum=strlen(auxtxt);
        }
        else
        {
            strcpy((*(Peliculas+i)).linkImagen,auxtxt);
        }
        (*(Peliculas+i)).estado=1;
    }
}

void BorrarPeli(eMovie *Peliculas, int tam)
{
    int i;
    int auxnro;
    int flag=0;

    printf("\nTitulos");
    for(i=0; i<tam; i++)
    {
        if((*(Peliculas+i)).estado==1)
        {
            printf("\n%d-%s",i+1,(*(Peliculas+i)).titulo);
        }

    }
    printf("\nIngrese el numero de la pelicula a eliminar:");
    scanf("%d",&auxnro);
    do
    {
        if(auxnro<0||auxnro>tam)
        {
            printf("ERROR!!!Laposicion no existe");
            printf("\nReingrese el numero de la pelicula a eliminar:");
            scanf("%d",&auxnro);
        }
        else
        {
            i=auxnro;
            flag=1;
        }
    }
    while(flag==0);

    printf("\nLink de la Imagen:%s\nTitulo:%s\nGenero:%s\nPuntaje:%d\nDuracion:%d min\nDescripcion:%s",(*(Peliculas+i)).linkImagen,(*(Peliculas+i)).titulo,(*(Peliculas+i)).genero,(*(Peliculas+i)).puntaje,(*(Peliculas+i)).duracion,(*(Peliculas+i)).descripcion);
    printf("\nDesea eliminar esta Pelicula\n 0-Si 1-No\n");
    scanf("%d",&auxnro);
    do
    {
        if(auxnro==0||auxnro==1)
        {
            if(auxnro==0)
            {
                (*(Peliculas+i)).estado=auxnro;
                printf("\nLa Pelicula se borro con exito");
                flag=1;
            }
            else if(auxnro==1)
            {
                printf("\nNo se borro la Pelicula");
                flag=1;
            }
        }
        else
        {
            printf("\nERROR!!!La respuesta no corresponde a ninguna de las Opciones Disponibles");
            printf("\nDesea eliminar esta Pelicula\n 0-Si 1-No\n");
            scanf("%d",&auxnro);
        }
    }
    while(flag==0);
}

void ModificarPeli(eMovie *Peliculas, int tam)
{
    int i;
    int auxnum;
    int flag=0;
    char auxtxt[40];

    printf("\nTitulos");
    for(i=0; i<tam; i++)
    {
        if((*(Peliculas+i)).estado==1)
        {
            printf("\n%d-%s",i,(*(Peliculas+i)).titulo);
        }
    }
    printf("\nIngrese el numero de la pelicula a modificar:");
    scanf("%d",&auxnum);
    while(flag == 0)
    {
        if(auxnum<0||auxnum>tam)
        {
            printf("ERROR!!!La posicion no existe");
            printf("\nReingrese el numero de la pelicula a modificar:");
            scanf("%d",&auxnum);
        }
        else
        {
            i=auxnum;
            flag=1;
        }
    }

    printf("\nLink de la Imagen:%s\nTitulo:%s\nGenero:%s\nPuntaje:%d\nDuracion:%d min\nDescripcion:%s",(*(Peliculas+i)).linkImagen,(*(Peliculas+i)).titulo,(*(Peliculas+i)).genero,(*(Peliculas+i)).puntaje,(*(Peliculas+i)).duracion,(*(Peliculas+i)).descripcion);
    printf("\nDesea modificar esta pelicula\n 1-Si 0-No\n");
    scanf("%d",&auxnum);

    if(auxnum==1||auxnum==0)
    {
        if(auxnum==1)
        {
            printf("\nIngrese el/los Genero/s de la Pelicula, Rango[2 - 50]:\n");
            setbuf(stdin,NULL);
            scanf("%[^\n]",(*(Peliculas+i)).genero);
            auxnum=strlen(auxtxt);
            do
            {
                if(auxnum<2||auxnum>50)
                {
                    printf("\nERROR!!!El Genero ingresado no alcaza el minimo o sobrepasa el maximo de espacio disponible");
                    printf("\nReingrese el  de la Pelicula, Rango[2 - 50]:\n");
                    setbuf(stdin,NULL);
                    scanf("%[^\n]",auxtxt);
                    auxnum=strlen(auxtxt);
                }
                else
                {
                    strcpy((*(Peliculas+i)).titulo,auxtxt);
                    flag=1;
                }
            }
            while(flag==0);

            printf("\nIngrese el puntaje de la Pelicula, Rango[0 - 100]:\n");
            scanf("%d",&auxnum);
            do
            {
                if(auxnum<0||auxnum>100)
                {
                    printf("\nERROR!!!El puntaje no esta en el rango permitido");
                    printf("\nReingrese el puntaje de la Pelicula, Rango[0 - 100]:\n");
                    scanf("%d",&auxnum);
                }
                else
                {
                    (*(Peliculas+i)).puntaje=auxnum;
                    flag=1;
                }
            }
            while(flag==0);

            printf("\nIngrese la Duracion de la Pelicula, Rango[5 min - 360 min]:\n");
            scanf("%d",&(*(Peliculas+i)).duracion);
            do
            {
                if(auxnum<5||auxnum>360)
                {
                    printf("\nERROR!!!La Duracion no esta en el rango permitido");
                    printf("\nReingrese la Duracion de la Pelicula, Rango[5 min - 360 min]:\n");
                    scanf("%d",&auxnum);
                }
                else
                {
                    (*(Peliculas+i)).duracion=auxnum;
                    flag=1;
                }
            }
            while(flag==0);

            printf("\nIngrese la Descripcion de la Pelicula, Rango[2 - 2000]:\n");
            setbuf(stdin,NULL);
            scanf("%[^\n]",auxtxt);
            auxnum=strlen(auxtxt);
            do
            {
                if(auxnum<2||auxnum>2000)
                {
                    printf("\nERROR!!!La Descripcion no esta en el rango permitido");
                    printf("\nReingrese la Descripcion de la Pelicula, Rango[2 - 2000]:\n");
                    setbuf(stdin,NULL);
                    scanf("%[^\n]",auxtxt);
                    auxnum=strlen(auxtxt);
                }
                else
                {
                    strcpy((*(Peliculas+i)).descripcion,auxtxt);
                    flag=1;
                }
            }
            while(flag==0);

            printf("\nIngrese el Link de la Imagen de la Pelicula, Rango[20-500]:\n");
            setbuf(stdin,NULL);
            scanf("%[^\n]",(*(Peliculas+i)).linkImagen);
            auxnum=strlen(auxtxt);
            do
            {
                if(auxnum<20||auxnum>500)
                {
                    printf("\nERROR!!!El Link no esta en el rango permitido");
                    printf("\nReingrese el Link de la Imagen de la Pelicula, Rango[20-500]:\n");
                    setbuf(stdin,NULL);
                    scanf("%[^\n]",auxtxt);
                    auxnum=strlen(auxtxt);
                }
                else
                {
                    strcpy((*(Peliculas+i)).linkImagen,auxtxt);
                    flag=1;
                }
            }
            while(flag==0);

        }
        if(auxnum==0)
        {
            printf("\nNo se Modificara la Pelicula");
        }
    }
    else
    {
        printf("\nERROR!!!La Respuesta no corresponde a ninguna de las opciones disponibles");
        printf("\nDesea modificar esta pelicula\n 1-Si 0-No\n");
        scanf("%d",&auxnum);
    }

}

int PermitirOpciones(eMovie *Peliculas, int tam)
{
    int i;
    int estcomp=0;

    for(i=0; i<tam; i++)
    {
        if((*(Peliculas+i)).estado==1)
        {
            estcomp++;
        }
    }

    return estcomp;
}

void GenerarWeb(eMovie* Peliculas, char name[], int tam)
{
    FILE* PelisHTML;
    int i,j,k;
    int auxent;
    char auxCadena[268];
    char segundoAuxiliarCadena[268];

    strcat(name,".html");
    PelisHTML=fopen(name,"w");
    if(PelisHTML==NULL)
    {
        printf("La pagina no se va a poder generar.");
    }
    else
    {
        fprintf(PelisHTML,"<!Doctype html><html><title>Agustin Veron 1ªA</title> <body>");
        fprintf(PelisHTML,"<h3><MARQUEE WIDTH=500% HEIGHT=300 >Trabajo Practico Cinema Puntero</MARQUEE></h3>");

        for(i=0; i<tam; i++)
        {
            fprintf(PelisHTML,"<img  src=%s alt='' style=width:200px;hight:200px>",(Peliculas+i)->linkImagen);
            fprintf(PelisHTML,"<h2><a href=#>%d)%s</a></h2>",i+1,(Peliculas+i)->titulo);
            fprintf(PelisHTML,"<h3><li> Genero: %s</li>   <li>Puntaje: %d </li>     <li>Duracion: %d </li>               </h3>",(Peliculas+i)->genero,(Peliculas+i)->puntaje,(Peliculas+i)->duracion);
            fprintf(PelisHTML,"<pre>");
            strcpy(auxCadena,(Peliculas+i)->descripcion);
            k=0;
            for(j=0; j<268; j++)
            {
                segundoAuxiliarCadena[j]=auxCadena[k];
                k++;
                if(j==60||j==124||j==188)
                {
                    j++;
                    segundoAuxiliarCadena[j]='<';
                    j++;
                    segundoAuxiliarCadena[j]='b';
                    j++;
                    segundoAuxiliarCadena[j]='r';
                    j++;
                    segundoAuxiliarCadena[j]='>';
                }
            }
            auxent=strlen(segundoAuxiliarCadena);
            fwrite(&segundoAuxiliarCadena,sizeof(char),auxent,PelisHTML);
            fprintf(PelisHTML,"</pre>");
        }
        fprintf(PelisHTML,"</html> </body>");
    }
    fclose(PelisHTML);
    printf("La paguina se genero correctamente.\n");
    printf("Abra el archivo %s que se encuentra en esta misma carpeta.\n",name);
}

