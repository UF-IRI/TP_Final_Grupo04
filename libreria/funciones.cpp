
#include"funciones.h"

bool chequear_DNI(string dni) {

    int tam = dni.length();//devuelvo el tamanio del string
    if (tam != 9) {
        return false; //por si el paciente tiene en su DNI 8 a 7 cifras
    }
    for (int i = 0; i < tam; i++) {

        if (dni[i] < '0' || dni[i] > '9') {
            return false;
        }

    }

    return true;

}

bool chequeo_AyN(string AyN) {


    int tam = AyN.length();
    for (int i = 0; i < tam; i++) {

        if ((AyN[i] >= 'a' && AyN[i] <= 'z') || (AyN[i] >= 'A' && AyN[i] <= 'Z') || (AyN[i] == ' ')) {

            AyN[i] = tolower(AyN[i]); // pasamos a minusculas
        }
        else {
            return false;
        }

    }
    return true;

}
bool chequeo_telefono(string tel) {

    int tam = tel.length();//devuelvo el tamanio del string

    if (tam!=13) {

        return false;
    }
    for (int i = 1; i < tam; i++) {

        if (tel[i] < '0' || tel[i] > '9' || tel[i] != '-') {
            return false;
        }

    }

    return true;
}
bool chequeo_matricula(string matricula) 
{
    int tam = matricula.length();//devuelvo el tamanio del string

    if (tam != 12) {

        return false;
    }
    for (int i = 1; i < tam; i++) {

        if (matricula[i] < '0' || matricula[i] > '9' || matricula[i] != '-') {
            return false;
        }

    }

    return true;
}
bool chequeo_celular(string cel) 
{//chequea numeros telefonicos que tengan el +, por ejem:+54 000 876 6543

    int tam = cel.length();//devuelvo el tamanio del string

    if (tam < 15 || tam>17) {

        return false;
    }
    else if (cel[0] != '+') { return false; }
    for (int i = 1; i < tam; i++) {

        if (cel[i] < '0' || cel[i] > '9' || cel[i] != ' ') {
            return false;
        }

    }

    return true;
}
bool chequeo_direccion(string direc)
{//chequea que las direcciones esten formada por letras, espacios o numeros
    int tam = direc.length();

    for (int i = 0; i < tam; i++) {
        if ((direc[i] >= 'a' && direc[i] <= 'z') || (direc[i] >= 'A' && direc[i] <= 'Z') || (direc[i] == ' ') || (direc[i] < '0' || direc[i] > '9')) {
           
        }
        else {
            return false;
        }

        return true;
    }
}
bool chequeoNacimiento(tm fecha) {
    time_t now;
    struct tm* fecha_actual = localtime(&now);
    int dia_ac = fecha_actual->tm_mday;
    int mes_ac = fecha_actual->tm_mon + 1;//devuelve entre 0-11
    int anio_ac = fecha_actual->tm_year + 1900;
    
    if (fecha.tm_year == anio_ac && fecha.tm_mon == mes_ac) {
        if (fecha.tm_mday < dia_ac)
            return true;
        else return false;
    }
    if (fecha.tm_year == anio_ac && fecha.tm_mon > mes_ac)
        return false;
    if (fecha.tm_year < anio_ac && fecha.tm_mon < mes_ac)
        return true;
};
bool chequeo_Mail(string mail)
{
    int cont_arr = 0;
    int cont_p = 0;
    int tam = mail.length();
    for (int i = 0; i < tam; i++) {
        if (mail[i] == '@') {
            cont_arr++;
        }
        else if (mail[i] == '.') { cont_p++; }

    }

    if (cont_arr == 1 && cont_p > 1) { return true; }

    return false;
}
bool chequeargenero(char letra)
{
    if (letra != 'M' && letra != 'F'&& letra!='m' && letra!='f')
    {//chequeamos mayusculas y min
        return false;//no es un genero q el hospital considera
    }

}
 bool chequeoObra_social(string Obra_soc, Obra_Social*listaObra_soc, int tam) {

     for (int i = 0; i < tam; i++) {

         if (Obra_soc == listaObra_soc[i].obra_soc) {
             return true;
         }

     }
     return false;


}
 bool chequeo_especialedad(string e) {

     int tam = e.length();
     for (int i = 0; i < tam; i++) {

         if ((e[i] >= 'a' && e[i] <= 'z') || (e[i] >= 'A' && e[i] <= 'Z') || (e[i] == ' ') ) {
             
         }
         else {
             return true;
         }

         return false;
     }
     
     


 }
//bool chequeo_especialedad(string e)
//{
//
//    switch (e)
//    {
//    case  "hematologia":
//        return true;
//        break;
//    case estomatologia:
//        break;
//    case anestesiologia:
//        break;
//    case nefrologia:
//        break;
//    case psiquiatria:
//        break;
//    case endocrinologia:
//        break;
//    case reumatologia:
//        break;
//    case genetica:
//        break;
//    case hepatologia:
//        break;
//    case pediatria:
//        break;
//    case geriatria:
//        break;
//    case cardiologia:
//        break;
//    case gastroenterologia:
//        break;
//    case medicina_intensiva:
//        break;
//    case medicina_forence:
//        break;
//    case toxicologia:
//        break;
//    case nutrilogia:
//        break;
//    case oncologia_medica:
//        break;
//    case medicina_ionterna:
//        break;
//    case alegologia:
//        break;
//    case infectologia:
//        break;
//    case neurologia:
//        break;
//    default:
//        break;
//    }
//
//
//    return false;
//}
 bool chequearfecha(int dia, int mes, int anio)
 {
     if (dia>0 && mes>0 && anio>0)
     {
         if (dia <= 31 && mes <= 12)
         {
             return true;
         }
         else
         {
             return false;//numeros incorrectos 
         }
     }
     else
     {
         return false;//no se permiten fechas negativas
     }
 
 }
 bool chequeo_estado(string estado) {

     if (estado == "n/c" || estado == "fallecido" || estado == "internado")
     {
         return true;
      }
     else { return false; }
 
 };
bool leer_pacientes(string nombredearchivo,Obra_Social* lista_os, Paciente*& Lista_pacientes, int* tam,int tam_os)
{//devuelve la lista carga y su tam por derecha
    fstream archivo;
    archivo.open(nombredearchivo, ios::in);//abro en modo escritura
    if (!(archivo.is_open()))
    {
        return false;//error
    }
    if (Lista_pacientes == NULL)
    {
        return false;
    }
    Paciente aux;//creo un paciente auxiliar
    string header;//creo el header
    char coma;
   
    //leeo el header
    getline(archivo, header);
    int dia = 0;
    int mes = 0;
    int anio = 0;
    char barra;
    //recorro el archivo
    while (archivo)
    { //dni,nombre,apellido,sexo,natalicio,estado,id_os
        //para leer la fecha >>barra>>mes>>dia>>anio
        archivo >> aux.DNI >> coma >> aux.Nombre >> coma >> aux.Apellido >> coma >> aux.Sexo >> coma >>mes>>barra>>dia>>barra>>anio>> coma >> aux.Estado >> coma >> aux.Obra_soc;
        bool aux6 = chequearfecha(dia, mes, anio);
        if (aux6 == true)
        {//chequeo todos los atributos que tiene el paciente
            aux.Nacimiento.tm_mday = dia;
            aux.Nacimiento.tm_mon = mes;
            aux.Nacimiento.tm_year = anio;
            bool aux1 = chequeoObra_social(aux.Obra_soc, lista_os, tam_os);
            bool aux2 = chequear_DNI(aux.DNI);
            bool aux3 = chequeo_AyN(aux.Nombre);
            bool aux4 = chequeo_AyN(aux.Apellido);
            bool aux5 = chequeargenero(aux.Sexo);
            bool aux7 = chequeoNacimiento(aux.Nacimiento);
            bool aux8 = chequeo_estado(aux.Estado);
            if (aux1 == true && aux2 == true && aux3 == true && aux4 == true && aux5 == true && aux7 == true && aux8 == true) 
            {
                
                bool aux_ = agregar_paciente(aux, Lista_pacientes, tam);
            }
                
        }
        
        

    }
  
    archivo.close(); // ver fecha
}


bool agregar_paciente(Paciente aux, Paciente*& lista, int* tam) {

    if (lista == false) {
        return false;
    }
   

    int pos = buscarpaciente(aux.DNI, lista, *tam);
    if (pos != -1)
    {
        return false;//dni ya se encuentra en la lista
    }
    //redimensiono 
    bool boleano = redimensionarp(lista, tam, 1);
    if (boleano == false) 
    {
        return false;//no se logro redimensionar 
    }
        //agrego
        lista[(*tam)] = aux;//agrego al paciente auxiliar
        return true;
    
}

//bool leer_obra_soci(string nombrearchivo, ); // fijarse archivo

int buscarpaciente(string dni, Paciente* lista, int tam)
{
    if (lista == NULL)
    {
        return -1;//error
    }
    int i;
    for(i=0;i<tam;i++)
    {
        if (lista[i].DNI == dni) 
        {
            return i;
        }
    
    }
    return -1;//no se encuentra en la lista
}
bool redimensionarp(Paciente*& lista, int* tam, int cant_aumentar)
{
    Paciente* listaaux = new Paciente[(*tam)+ cant_aumentar];
    //chequeo si se logro pedir memoria adecuadamente
    if (listaaux == NULL || lista == NULL)
    {
        return false;//error
    }
    for (int i=0;i<(*tam);i++)
    {
        listaaux[i]=lista[i];//me voy pasando el contenido
    }
    (*tam)= (*tam) +cant_aumentar;
    delete []lista;
    lista = listaaux;
    return true;
}

bool Leer_Obrasoc(string nombre_arc, Obra_Social*& obrasoc, int* tam)
{
    Obra_Social aux;
    string header;
    fstream archivo;
    archivo.open(nombre_arc, ios::in);
    if (!(archivo.is_open()))
        return false;
    getline(archivo, header);
    while (archivo) {
        
        archivo >> aux.id >> aux.obra_soc;
        *tam++;
        Agregar_obrasoc(obrasoc, tam, aux);
    }

    return false;
}

bool Agregar_obrasoc(Obra_Social*& lista, int* tam, Obra_Social dato) {

    Obra_Social* aux = new Obra_Social[*tam - 1];
    if (lista == NULL || aux == NULL)
        return false;
    bool auxiliar=chequeoObra_social(dato.obra_soc, lista,  *tam);
    if (auxiliar == true) 
    {
        return false;//la obra social ya se encontraba en la lista
    }
    for (int i = 0; i < *tam; i++) {
    
        aux[i] = lista[i];
    
    }
    aux[*tam - 1] = dato;
    delete[] lista;
    lista = aux;
}
bool agregar_consulta(Consulta aux, Consulta*& lista, int* tam)
{
    bool auxiliar = redimensionarc(lista, tam, 1);
    if (lista == NULL || auxiliar==false)
    {
        return false;
    }
    //la agrego 
    lista[*tam] = aux;//lo agrego
    return true;
}
bool redimensionarc(Consulta*& lista, int* tam, int cant_aumentar)
{
    Consulta* auxiliar = new Consulta[*tam + cant_aumentar];
    if (lista==NULL || auxiliar==NULL)
    {
        return false;
    }
    for (int i=0;i<*tam;i++) 
    {
        auxiliar[i]=lista[i];
    }
    delete []lista;
    lista = auxiliar;
    (*tam) = (*tam) + cant_aumentar;
    return true;
}//funcion para redimensionar lista de consultas
bool leer_Consultas(string nombredearchivo, Consulta*& Lista_consultas, int* tam)
{
    fstream archivo;
    archivo.open(nombredearchivo, ios::in);//abro modo lectura
    if (!(archivo.is_open())) 
    {
        return false;
    }
    string header;
    char coma;
    getline(archivo,header);
    Consulta aux;
    if (Lista_consultas == NULL)
    {
        return false;
    }
    int dia_s;//dia_solicitado
    int mes_s;
    int anio_s;
    int dia_t;//dia_turno
    int mes_t;
    int anio_t;
    char barra;
    while (archivo)
    {
        //dni_pac,fecha_solicitado,fecha_turno,presento,matricula_med
        archivo >> aux.DNI>>coma>>mes_s>>barra>>dia_s>>barra>>anio_s>>coma>>mes_t>>barra>>dia_t>>barra>>anio_t>>coma>>aux.Presento>>coma>>aux.Matricula_medica;
        bool aux2 = chequearfecha(dia_s,mes_s, anio_s);
        bool aux3 = chequearfecha(dia_t,mes_t, anio_t);
        if (aux2==true && aux3==true) 
        {//los copio en el auxiliar
            aux.Fecha_solicitado.tm_mday = dia_s;
            aux.Fecha_solicitado.tm_mon = mes_s;
            aux.Fecha_solicitado.tm_year = anio_s;
            aux.Fecha_turno.tm_mday = dia_t;
            aux.Fecha_turno.tm_mon = mes_t;
            aux.Fecha_turno.tm_year = anio_t;
            bool aux5 = chequeofechasolicitado(aux.Fecha_solicitado, aux.Fecha_turno);    //hay q hacer un chequeo q la fecha solicitado sea menor al turno
            bool aux1 = chequear_DNI(aux.DNI);
            bool aux4 = chequeo_matricula(aux.Matricula_medica);
            if (aux5 == true && aux1 == true && aux4 == true)
            {
                bool boleano = agregar_consulta(aux, Lista_consultas, tam);//voy agregando a la lista de consultas
            }
            
        }
       
    };
    archivo.close();
}
bool leer_Obrasoc(string nombredearchivo, Obra_Social*& Lista_obrasoc, int* tam)
{
    fstream archivo;
    archivo.open(nombredearchivo, ios::in);
    if (!(archivo.is_open()))
    {
        return false;
    }
    if (Lista_obrasoc == NULL)
    {
        return false;
    }
    string header;
    Obra_Social aux;
    getline(archivo, header);
    while (archivo)
    {
        //id_os,obra_social
        archivo >> aux.id >> aux.obra_soc;
        //agregar un chequeo de obra social, sea un string
        bool auxiliar = Agregar_obrasoc(Lista_obrasoc, tam, aux);//agrega a la lista de obra social
    };

    archivo.close();
}
bool chequeofechasolicitado(tm fecha_solicitado, tm fecha_turno)
{
    //long int = difftime();


}