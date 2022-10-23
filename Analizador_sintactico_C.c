/*ansi.c*/
/*
* Analizador Sintactico		
 */
# incluir  " ansin.h "
ficha t;
ARCHIVO *archivo;
token array_tokens[TAMARRAY];
int numLinea = 1 ;
int con = - 1 ;
int tamano_actual = 0 ;
id de carácter [TAMLEX];
char cont_esp[TAMESP];
char mensaje1[ 41 ];
void  error ( const  char * mensaje)
{
    printf ( " Lin %d : Error Lexico. %s " , numLinea, mensaje);
}
vacío  sigLex ()
{
    int i = 0 ;
    prohibición int = 0 ;
    int acepto = 0 ;
    int estado = 0 ;
    carácter c = 0 ;
    char mensaje[ 41 ];
    char aux[TAMAUX] = "  " ;
    estafa = - 1 ;
    ficha e;
    while ((c = fgetc (archivo)) != EOF)
    {
        if (c == ' \n ' ) {
            numLinea++;
            continuar ;
        } else if (c == '  ' )
        {
            do 
            {
                con++;
                cont_esp[con] = '  ' ;
                c = fgetc (archivo);
            } while (c == '  ' );
            c = ungetc (c, archivo);
        } else if (c == ' \t ' )
        {
            while (c == ' \t ' )
            {
                printf ( " %c " , c);
                c = fgetc (archivo);
            }
        } else if ( isdigit (c))
        {
            yo = 0 ;
            estado = 0 ;
            acepto = 0 ;
            id[i] = c;
            while (!acepto)
            {
                 (estado)
                {
                    case  0 :
                        c = fgetc (archivo);
                        if ( es un dígito (c))
                        {
                            id[++i] = c;
                            estado = 0 ;
                        } else if (c == ' . ' )
                        {
                            id[++i] = c;
                            estado = 1 ;
                        } else if ( abajo (c) == ' e ' )
                        {
                            id[++i] = c;
                            estado = 3 ;
                        } else
                            estado = 6 ;
                        break ;
                    case  1 :
                        c = fgetc (archivo);
                        if ( es un dígito (c))
                        {
                            id[++i] = c;
                            estado = 2 ;
                        } else 
                        {
                            sprintf (msg, " No se esperaba ' %c ' despues del . " , c);
                            estado = - 1 ;
                        }
                        break ;
                    case  2 : 
                        c = fgetc (archivo);
                        if ( es un dígito (c))
                        {
                            id[++i] = c;
                            estado = 2 ;
                        } else if ( abajo (c) == ' e ' )
                        {
                            id[++i] = c;
                            estado = 3 ;
                        } else
                            estado = 6 ;
                        break ;
                    case  3 : 
                        c = fgetc (archivo);
                        if (c == ' + ' || c == ' - ' )
                        {
                            id[++i] = c;
                            estado = 4 ;
                        } else if ( isdigit (c))
                        {
                            id[++i] = c;
                            estado = 5 ;
                        } else 
                        {
                            sprintf (msg, " Se esperaba un signo o dígitos después del exponente " );
                            estado = - 1 ;
                        }
                        break ;
                    case  4 : 
                        c = fgetc (archivo);
                        if ( es un dígito (c))
                        {
                            id[++i] = c;
                            estado = 5 ;
                        } else 
                        {
                            sprintf (msg, " No se esperaba ' %c ' despues del signo " , c);
                            estado = - 1 ;
                        }
                        break ;
                    case  5 : 
                        c = fgetc (archivo);
                        if ( es un dígito (c))
                        {
                            id[++i] = c;
                            estado = 5 ;
                        } else
                            estado = 6 ;
                        break ;
                    case  6 : 
                        if (c != EOF)
                            ungetc (c, archivo);
                        else
							
                            c = 0 ;
                        id[++i] = ' \0 ' ;
                        acepto = 1 ;
                        t. compLex = NÚMERO;
                        t. linea =numLinea;
                        strcpy (t. lexema , id);
                        array_tokens[tamano_actual] = t;
                        tamano_real++;
                        break ;
                    case - 1 :
                        if (c == EOF)
                            error ( " No se esperaba el fin de archivo \n " );
                        else
                            error (mensaje);
                        acepto = 1 ;
                        t. compLex = VACIO;
                        t. linea =numLinea;
                        while (c != ' \n ' )
                            c = fgetc (archivo);
                        ungetc (c, archivo);
                        break ;
                }
            }
            break ;
        } else if (c == ' \" ' )
        {
            yo = 0 ;
            id[i] = c;
            yo++;
            do 
            {
                c = fgetc (archivo);
                if (c == ' \" ' )
                {
                    id[i] = c;
                    yo++;
                    prohibición = 1 ;
                    break ;
                } else if (c == EOF || c == ' , ' || c == ' \n ' || c == ' : ' )
                {
                    while (c != ' \n ' )
                    {
                        c = fgetc (archivo);
                        si (c == ' \" ' )
                        {
                            prohibición = 1 ;
                        }
                    }
                    if (prohibición == 0 )
                    {
                        sprintf (msg, " Se esperaba que finalizara el literal " );
                        error (mensaje);
                    }

                    ungetc (c, archivo);
                    estafa = - 1 ;
                    break ;
                } else
                {
                    id[i] = c;
                    yo++;
                }
            } while ( isascii (c) || ​​ban == 0 );
            id[i] = ' \0 ' ;
            strcpy (t. lexema , id);
            t. compLex = CADENA;
            t. linea =numLinea;
            array_tokens[tamano_actual] = t;
            tamano_real++;
            break ;
        } else if (c == ' : ' )
        {
            t. compLex = DOS_PUNTOS;
            t. linea =numLinea;
            strcpy (t. lexema , " : " );
            array_tokens[tamano_actual] = t;
            tamano_real++;
            break ;
        } else if (c == ' , ' )
        {
            t. compLex = COMA;
            t. linea =numLinea;
            strcpy (t. lexema , " , " );
            array_tokens[tamano_actual] = t;
            tamano_real++;
            break ;
        } else if (c == ' [ ' )
        {
            t. compLex = L_CORCHETE;
            t. linea =numLinea;
            strcpy (t. lexema , " [ " );
            array_tokens[tamano_actual] = t;
            tamano_real++;
            break ;
        } else if (c == ' ] ' )
        {
            t. compLex = R_CORCHETE;
            t. linea =numLinea;
            strcpy (t. lexema , " ] " );
            array_tokens[tamano_actual] = t;
            tamano_real++;
            break ;
        } else if (c == ' { ' )
        {
            t. compLex = L_LLAVE;
            t. linea =numLinea;
            strcpy (t. lexema , " { " );
            array_tokens[tamano_actual] = t;
            tamano_real++;
            break ;
        } else if (c == ' } ' )
        {
            t. compLex = R_LLAVE;
            t. linea =numLinea;
            strcpy (t. lexema , " } " );
            array_tokens[tamano_actual] = t;
            tamano_real++;
            break ;
        } else if (c == ' n ' || c == ' N ' )
        {
            ungetc (c, archivo);
            fgets (aux, 5 , archivo);
            if ( strcmp (auxiliar, " nulo " ) == 0 || strcmp (auxiliar, " NULL " ) == 0 )
            {
                t. compLex = PR_NULL;
                t. linea =numLinea;
                strcpy (t. lexema , aux);
                array_tokens[tamano_actual] = t;
                tamano_real++;
            } else 
            {
                sprintf (mensaje, " %c no esperado " , c);
                error (mensaje);

                while (c != ' \n ' )
                    c = fgetc (archivo);
                t. compLex = VACIO;
                t. linea =numLinea;
                ungetc (c, archivo);
            }
            break ;
        }
        else (c == ' f ' || c == ' F ' )
        {
            ungetc (c, archivo);
            fgets (aux, 6 , archivo);
            if ( strcmp (auxiliar, " falso " ) == 0 || strcmp (auxiliar, " FALSO " ) == 0 )
            {
                t. compLex = PR_FALSO;
                t. linea =numLinea;
                strcpy (t. lexema , aux);
                array_tokens[tamano_actual] = t;
            tamano_real++;
            } else 
            {
                sprintf (mensaje, " %c no esperado " , c);
                error (mensaje);

                while (c != ' \n ' )
                    c = fgetc (archivo);
                t. compLex = VACIO;
                t. linea =numLinea;
                ungetc (c, archivo);
            }
            break ;
        }
        else (c == ' t ' || c == ' T ' )
        {
            ungetc (c, archivo);
            fgets (aux, 5 , archivo);
            if ( strcmp (auxiliar, " verdadero " ) == 0 || strcmp (auxiliar, " VERDADERO " ) == 0 )
            {
                t. compLex = PR_TRUE;
                t. linea =numLinea;
                strcpy (t. lexema , aux);
                array_tokens[tamano_actual] = t;
                tamano_real++;
            } else 
            {
                sprintf (mensaje, " %c no esperado " , c);
                error (mensaje);

                while (c != ' \n ' )
                    c = fgetc (archivo);
                t. compLex = VACIO;
                t. linea =numLinea;
                ungetc (c, archivo);
            }
            break ;
        } else if (c != EOF)
        {
            sprintf (mensaje, " %c no esperado " , c);
            error (mensaje);
            while (c != ' \n ' )
                c = fgetc (archivo);
            strcpy (cont_esp, "  " );
            estafa = - 1 ;
            ungetc (c, archivo);
        }
    }
    if (c == EOF)
    {
        t. compLex = EOF;
        t. linea =numLinea;
        strcpy (t. lexema , " EOF " );
        sprintf (t. lexema , " EOF " );
        array_tokens[tamano_actual] = t;
        tamano_real++;
    }
}
//Analizador
ficha ficha1;
int setSync[TAMCONJ];
int posicion=- 1 ;
int errores= 0 ;

void  error_sintac ( const  char *mensaje)
{
    errores= 1 ;
   printf ( " Error sintactico. %s " , mensaje);

}

 coincidencia nula ( int t)
{
    si (t == token1. compLex )
    {
        obtenerToken ();
    } else
    {
        sprintf (msg1, " En la linea %d No se esperaba   %s \n " , token1. linea , token1. lexema );
        error_sintac (msg1);
    }
}

void  getToken ()
{
    posición++;
    token1 = array_tokens[posición];
}

 analizador vacío ()
{
    obtenerToken ();
    int con_sig []={EOF, 0 , 0 , 0 , 0 , 0 , 0 , 0 };
    json (con_sig);
}

void  json ( int setSync[])
{
    if (token1. compLex == L_LLAVE || token1. compLex == L_CORCHETE){
        elemento ();
    } más
    {
        sprintf (msg1, " En la linea %d Se esperaba L_LLAVE o L_CORCHETE \n " , token1. linea );
        error_sintac (msg1);
    }
}

 elemento vacío ()
{
    int con_primero[] = {L_LLAVE, L_CORCHETE, 0 , 0 , 0 , 0 , 0 , 0 };
    int con_sig []={EOF,COMA, R_CORCHETE, R_LLAVE, 0 , 0 , 0 , 0 };
    check_input (con_primero, con_sig);
    switch (token1. compLex )
    {
        case L_LLAVE:
            objeto (con_sig);
            break ;
        case L_CORCHETE:
            matriz (con_sig);
            break ;
        predeterminado :
            sprintf (msg1, " En la linea %d Se esperaba L_LLAVE o L_CORCHETE \n " , token1. linea );
            error_sintac (msg1);
            break ;
    }
    check_input (con_sig,con_primero);
}
 objeto vacío ( int setSync[])
{
    int con_primero[]={L_LLAVE, 0 , 0 , 0 , 0 , 0 , 0 , 0 };
    int con_sig[]={EOF,COMA, R_CORCHETE, R_LLAVE, 0 , 0 , 0 , 0 };
    check_input (con_primero,con_sig);
    switch	(token1. compLex )
    {
        case L_LLAVE:
            partido (L_LLAVE);        
            objetop (setSync);
            break ;
        predeterminado :
            sprintf (msg1, " En la linea %d Se esperaba L_LLAVE \n " , token1. linea );
            error_sintac (msg1);
            break ;
    }   
    check_input (con_sig,con_primero);
}

 matriz vacía ( int setSync[])
{
    int con_primero[]={L_CORCHETE, 0 , 0 , 0 , 0 , 0 , 0 , 0 };
    int con_si[] = {EOF,COMA, R_CORCHETE, R_LLAVE, 0 , 0 , 0 , 0 };
    check_input (con_primero,con_si);
    switch (token1. compLex )
    {
        case L_CORCHETE:
            partido (L_CORCHETE);        
            matrizp (setSync);
            break ;
        predeterminado :
            sprintf (msg1, " En la linea %d Se esperaba L_CORCHETE \n " , token1. linea );
            error_sintac (msg1);
            break ;
    }
    check_input (con_si,con_primero);
}

void  objectp ( int setSync[])
{
    int con_primero[]={STRING,R_LLAVE, 0 , 0 , 0 , 0 , 0 , 0 };
    int con_si[] = {EOF,COMA, R_CORCHETE, R_LLAVE, 0 , 0 , 0 , 0 };
    check_input (con_primero,con_si);
    switch (token1. compLex )
    {
        cadena de casos :
            lista_atributos ();
            partido (R_LLAVE);        
            break ;
        case R_LLAVE:
            partido (R_LLAVE);
            break ;
        predeterminado :
            sprintf (msg1, " En la linea %d Se esperaba STRING o R_LLAVE \n " , token1. linea );
            error_sintac (msg1);

            break ;
    }
    check_input (con_si,con_primero);
}

void  arrayp ( int setSync[])
{
    int con_primero[]={L_LLAVE, L_CORCHETE, R_CORCHETE, 0 , 0 , 0 , 0 , 0 };
    int con_si[] = {EOF,COMA, R_CORCHETE, R_LLAVE, 0 , 0 , 0 , 0 };
    check_input (con_primero,con_si);
    switch (token1. compLex )
    {
        case L_LLAVE:
            lista_elementos ();
            partido (R_CORCHETE);        
            break ;
        case L_CORCHETE:
            lista_elementos ();
            partido (R_CORCHETE);
            break ;
        case R_CORCHETE:
            partido (R_CORCHETE);
            break ;
        predeterminado :
            sprintf (msg1, " En la linea %d Se esperaba L_LLAVE, L_CORCHETE o R_CORCHETE \n " , token1. linea );
            error_sintac (msg1);
            break;
    }
    check_input (con_si,con_primero);
}

 lista_de_elementos vacía ()
{
    int con_primero[]={L_LLAVE,L_CORCHETE, 0 , 0 , 0 , 0 , 0 , 0 };
    int con_siguiente[]={R_CORCHETE, 0 , 0 , 0 , 0 , 0 , 0 , 0 };
    check_input (con_primero,con_siguiente);
    if (token1. compLex ==L_LLAVE || token1. compLex == L_CORCHETE){
        elemento ();
        element_listp (con_siguiente);
    } else {
        sprintf (msg1, " En la linea %d Se esperaba L_LLAVE, L_CORCHETE \n " , token1. linea );
        error_sintac (msg1);
        check_input (con_siguiente,con_primero);
    }
}


void  element_listp ( int setSync[])
{
    int con_primero[]={COMA, 0 , 0 , 0 , 0 , 0 , 0 , 0 };
    int con_sig[]={R_CORCHETE};
    if (token1. compLex ==R_CORCHETE){
        check_input (con_sig,con_primero);
    } else {
        check_input (con_primero,con_sig);
    }
    switch (token1. compLex )
    {
        case COMA:
            match (COMA);
            elemento ();
            lista_elementosp (con_sig);
            break ;
    }
   check_input (con_sig,con_primero);
}

 atributo nulo ()
{
    int con_primero[]={CADENA, 0 , 0 , 0 , 0 , 0 , 0 , 0 };
    int con_siguien[]={COMA,R_LLAVE, 0 , 0 , 0 , 0 , 0 , 0 };
    check_input (con_primero,con_siguien);
    switch	(token1. compLex )
    {
        case CADENA :
            nombre_atributo ();
            partido (DOS_PUNTOS);
            valor_atributo (con_siguien);
            break ;
        predeterminado :
            sprintf (msg1, " En la linea %d Se esperaba STRING \n " , token1. linea );
            error_sintac (msg1);
            break ;
    }
}

void  lista_atributos ()
{
    int con_primero[]={CADENA, 0 , 0 , 0 , 0 , 0 , 0 , 0 };
    int con_siguie[]={R_LLAVE, 0 , 0 , 0 , 0 , 0 , 0 , 0 };
    check_input (con_primero,con_siguiente);
    if (token1. compLex ==CADENA){
	 atributo ();
        atribute_listp (con_siguie);
    } else {
        sprintf (msg1, " En la linea %d Se esperaba STRING \n " , token1. linea );
        error_sintac (msg1);
    }
    check_input (con_siguiente,con_primero);
}

void  atribute_listp ( int setSync[])
{
    int con_primero[]={COMA, 0 , 0 , 0 , 0 , 0 , 0 , 0 };
    int con_s[]={R_LLAVE, 0 , 0 , 0 , 0 , 0 , 0 , 0 };
    
    if (token1. compLex == R_LLAVE){
        check_input (con_s,con_primero);
    } else {        
        check_input (con_primero,con_s);
    }
    switch (token1. compLex )
    {
        case COMA:
            match(COMA);
            atributo ();
            atributo_listp (con_s);
            break ;
    }
    check_input (con_s,con_primero);
}

void  nombre_atributo ()
{
    int con_primero[]={CADENA, 0 , 0 , 0 , 0 , 0 , 0 , 0 };
    int con_sigui[]={DOS_PUNTOS, 0 , 0 , 0 , 0 , 0 , 0 , 0 };
    check_input (con_primero,con_sigui);
    switch (token1. compLex )
    {
        case CADENA :
            match(CADENA);
            break ;
        predeterminado :
            sprintf (msg1, " En la linea %d Se esperaba STRING \n " , token1. linea );
            error_sintac (msg1);
            break;
    }
}

void  valor_atributo ( int setSync[])
{
    int con_primero[]={L_LLAVE, L_CORCHETE, STRING, NUMBER, PR_TRUE, PR_FALSE,PR_NULL, 0 };
    int con_siv[]={COMA,R_LLAVE, 0 , 0 , 0 , 0 , 0 , 0 };
    check_input (con_primero,con_siv);
    switch (token1. compLex )
    {
        CASE L_LLAVE:
            elemento ();
            break ;
        case L_CORCHETE:
            elemento ();
            break;
        case CADENA:
            partido (CADENA);
            break;
        case NUMERO:
            partido (NÚMERO);
            break;
        case PR_TRUE:
            coincidencia (PR_TRUE);
            break;
        case PR_FALSO:
            coincidencia (PR_FALSO);
            break;
        case PR_NULL:
            coincidencia (PR_NULL);
            break;
        predeterminado :
            error_sintac ( " Se esperaba L_LLAVE, L_CORCHETE, STRING, NUMBER, TRUE,FALSE O NULL \n " );
            break;
    }
}

void  scanto ( int setSync1[], int setSync2[])
{
    set sync[ 16 ];
    int i= 0 ;
    int = 0 ;
    int tam= 8 ;
    int tam1 = 16 ;
    int j ;   
    for (j= 0 ; j< 8 ;j++)
    {
        setSync[j] = setSync1[j];
    }
    int k ;
    int y= 0 ;
    for (k= 8 ; k< 16 ;k++){
        setSync[k] = setSync2[y];
        y++;
    }
    do {
        while (i<tam1)
        {
            if (token1. compLex != setSync[i] && token1. compLex != EOF)
            {
                prohibición = 1 ;
                yo++;
            } else {
                prohibición= 0 ;
                i= 16 ;
                break ;
            }
       }
       if (prohibición== 1 )
       {
           obtenerToken ();
           yo= 0 ;
       }
    } while (i<tam1);
}

void  check_input ( int con_primero[], int con_siguiente[])
{
    int tam= 8 ;
    int yo;
    int ban1= 0 ;     
    for (i = 0 ; i < tam; i++)
    {
        if (token1. compLex == con_primero[i])
        {
            prohibición1= 0 ;
            break ;
        } else {
            prohibición1 = 1 ; 
        }
    }    
    if (ban1== 1)
    {
        sprintf (msg1, " En la linea %d No se esperaba   %s \n " , token1. linea , token1. lexema );
        error_sintac (msg1);
        scanto (con_primero, con_siguiente);
    }
}
 
int  main ( int argc, char * args[])
{
    if (argc > 1 )
    {
        if (!(archivo = fopen (args[ 1 ], " rt " )))
        {
            printf ( " Archivo no encontrado. \n " );
            exit ( 1 );
        }
        while (t. compLex != EOF)
        {
            sigLex ();   
        }   
        fclose (archivo);
        analizador ();
        if (errores == 0 )
        {
            printf ( " Es Correctamente Sintactico \n " );
        } else {
            printf ( " No es correctamente sintactico \n " );
        }
    } else {
        printf ( " Debe pasar como parametro el camino al archivo fuente. \n " );
        salida ( 1 );
    }
    return 0 ;
}