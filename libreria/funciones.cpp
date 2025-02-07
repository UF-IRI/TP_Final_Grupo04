
#include"funciones.h"

bool chequear_DNI(string dni) {

    int tam = dni.length();//devuelvo el tamanio del string
    if (tam != 8) {
        return false; //por si el paciente no tiene en su DNI 8 cifras 
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
/*
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
*/
bool chequeo_matricula(string matricula) 
{
    int tam = matricula.length();//devuelvo el tamanio del string

    if (tam != 11) {

        return false;
    }
    for (int i = 1; i < tam; i++) {

        if ((matricula[i] < '0' || matricula[i] > '9') && matricula[i] != '-') {
            return false;
        }

    }

    return true;
}
bool chequeo_celular(string cel) 
{//chequea numeros telefonicos que tengan el +, por ejem:+54 000 876 6543

    int tam = cel.length();//devuelvo el tamanio del string

    if (tam!=16) {

        return false;
    }
    if (cel[0] != '+') { return false; }
    for (int i = 1; i < tam; i++) {

        if ((cel[i] < '0' || cel[i] > '9') && cel[i]!='(' && cel[i] != ')') {
            return false;
        }

    }

    return true;
}
bool chequeo_direccion(string direc)
{//chequea que las direcciones esten formada por letras, espacios o numeros
    int tam = direc.length();

    for (int i = 0; i < tam; i++) {
        if (direc[i]>' '&& direc[i]<'0') {
            return false;
        } 
    }
    return true;
}
bool chequeoNacimiento(tm fecha) {
    if (fecha.tm_year < 0 || fecha.tm_mon < 0 || fecha.tm_mday < 0)
        return false;
    
    time_t now=time(0);
    tm* fecha_actual = localtime(&now);

    if (fecha_actual == nullptr) {
        return false;
    }

    int dia_ac = fecha_actual->tm_mday;
    int mes_ac = fecha_actual->tm_mon + 1;//devuelve entre 0-11
    int anio_ac = fecha_actual->tm_year + 1900;
    
    double fecha_hoy = anio_ac * 10000 + mes_ac * 100 + dia_ac;
    double nacimiento = fecha.tm_year * 10000 + fecha.tm_mon * 100 + fecha.tm_mday;
    if (nacimiento < fecha_hoy)
        return true;
    else return false;
    /*if (fecha.tm_year == anio_ac && fecha.tm_mon == mes_ac) {
        if (fecha.tm_mday < dia_ac)
            return true;
        else return false;
    }
    if (fecha.tm_year == anio_ac && fecha.tm_mon > mes_ac)
        return false;
    if (fecha.tm_year < anio_ac && fecha.tm_mon < mes_ac)
        return true;*/
};
bool chequeo_Mail(string mail)
{
    int cont_arr = 0;
    int cont_p = 0;
    int tam = mail.length();
    for (int i = 0; i < tam; i++) {
        if (mail[i] >= ' ' && mail[i] < '0'&&mail[i]!= '.') {
            return false;
        }
        if (mail[i] == '@') {
            cont_arr++;
        }
        if (mail[i] == '.') { cont_p++; }

    }

    if (cont_arr == 1 && cont_p >= 1) { return true; }

    return false;
}
bool chequeargenero(char letra)
{
    if (letra != 'M' && letra != 'F' && letra != 'm' && letra != 'f')
    {//chequeamos mayusculas y min
        return false;//no es un genero q el hospital considera
    }
    else return true;
}


 bool chequeo_especialidades(string e) { // cambie el nombre de la funcion

     int tam = e.length();
     for (int i = 0; i < tam; i++) {

         if ((e[i] >= 'a' && e[i] <= 'z') || (e[i] >= 'A' && e[i] <= 'Z') || (e[i] == '_') ) {
             
         }
         else {
             return false;
         }

         
     }
     
       return true;


 }


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
bool leer_pacientes(string nombredearchivo, Paciente*& Lista_pacientes, int* tam)
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
        archivo >> aux.DNI >> coma >> aux.Nombre >> coma >> aux.Apellido >> coma >> aux.Sexo >> coma >>dia>>barra>>mes>>barra>>anio>> coma >> aux.Estado >> coma >> aux.Obra_soc;
        bool aux6 = chequearfecha(dia, mes, anio);
        if (aux6 == true)
        {//chequeo todos los atributos que tiene el paciente
            aux.Nacimiento.tm_mday = dia;
            aux.Nacimiento.tm_mon = mes;
            aux.Nacimiento.tm_year = anio;
            bool aux2 = chequear_DNI(aux.DNI);
            bool aux3 = chequeo_AyN(aux.Nombre);
            bool aux4 = chequeo_AyN(aux.Apellido);
            bool aux5 = chequeargenero(aux.Sexo);
            bool aux7 = chequeoNacimiento(aux.Nacimiento);
            bool aux8 = chequeo_estado(aux.Estado);
            if (aux2 == true && aux3 == true && aux4 == true && aux5 == true && aux7 == true && aux8 == true)
            {
                
                bool aux_ = agregar_paciente(aux, Lista_pacientes, tam);
            }
                
        }
        
        

    }
  
    archivo.close(); // ver fecha
}


bool agregar_paciente(Paciente aux, Paciente*& lista, int* tam) {

    if (lista == nullptr) {
        return false;
    }
    if (*tam != 0)
    {
        int pos = buscarpaciente(aux.DNI, lista, *(tam));
        if (pos != -1)
        {
            return false;//dni ya se encuentra en la lista
        }
   }
    //redimensiono 
    bool boleano = redimensionarp(lista, tam, 1);
    if (boleano == false) 
    {
        return false;//no se logro redimensionar 
    }
        //agrego
        lista[(*tam-1)] = aux;//agrego al paciente auxiliar
        return true;
    
}


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
    if (listaaux == nullptr || lista == nullptr)
    {
        return false;//error
    }
    for (int i=0;i<(*tam);i++)
    {
        *(listaaux+i)=lista[i];//me voy pasando el contenido
    }
    (*tam)= (*tam) +cant_aumentar;
    delete []lista;
    lista = listaaux;
    return true;
}
void Rand_fecha(int* dia, int* mes, int* anio)
{
    srand(time(NULL));
    *(dia) = rand() % (31 - 1) + 1;//numeros del 30 al 1
    *(mes)= rand() % (13 - 1) + 1;//numeros del 12 al 1
    *(anio) = 2023; //rand() % (2026 - 2023) +2023 ; numeros entre 2025 y 2023 (ya se termina el anio)


}
bool agregar_consulta(Consulta aux, Consulta*& lista, int* tam)
{
    bool auxiliar = redimensionarc(lista, tam, 1);
    if (lista == NULL || auxiliar==false)
    {
        return false;
    }
    //la agrego 
    lista[*tam-1] = aux;//lo agrego
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
        *(auxiliar+i)=lista[i];
    }
    delete []lista;
    lista = auxiliar;
    (*tam) = (*tam) + cant_aumentar;
    return true;
}
bool Ordenar_Paciente(Paciente*& lista, int tam)
{
    if (lista == NULL)
        return false;
   
    Paciente aux;
    
    for (int i = 0; i < tam-1; i++)
    {
        int cont = 0;
        for (int j = 0; j < tam - 1 - i; j++) {
            if (lista[j].Apellido > lista[j + i].Apellido)
            {
                aux = lista[j];
                lista[j] = lista[j + i];
                lista[j + i] = aux;
                cont++;
            }
        }
        if (cont == 0)
            return true;
    }

    return true;
}
//funcion para redimensionar lista de consultas
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
    //getline(archivo,header);
    archivo >> header>>coma>>header>>coma>>header>>coma>>header>>coma>>header;
    Consulta aux;
    if (Lista_consultas == NULL)
    {
        return false;
    }
    int dia_s=0;//dia_solicitado
    int mes_s=0;
    int anio_s=0;
    int dia_t=0;//dia_turno
    int mes_t=0;
    int anio_t=0;
    char barra;
    while (archivo)
    {
        //dni_pac,fecha_solicitado,fecha_turno,presento,matricula_med
        archivo >> aux.DNI>>coma>>dia_s>>barra>>mes_s>>barra>>anio_s>>coma>>dia_t>>barra>>mes_t>>barra>>anio_t>>coma>>aux.Presento>>coma>>aux.Matricula_medica;
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
bool chequeofechasolicitado(tm fecha_solicitado, tm fecha_turno)
{

    if (fecha_solicitado.tm_year < 0 || fecha_solicitado.tm_mon < 0 || fecha_solicitado.tm_mday < 0 || fecha_turno.tm_year < 0 || fecha_turno.tm_mon < 0 || fecha_turno.tm_mday < 0)
        return false;

    double fecha1 = (fecha_solicitado.tm_year * 10000) + (fecha_solicitado.tm_mon * 100) + (fecha_solicitado.tm_mday);
    double fecha2 = (fecha_turno.tm_year * 10000) + (fecha_turno.tm_mon * 100)+ (fecha_turno.tm_mday);

    if (fecha1 < fecha2)
    {
        return true;
    }
    else
    {
        return false;
    }

    
}
bool leer_medicos(string nombre_archivos, Medicos*& lista, int* tam) {

    fstream archivo;

    archivo.open(nombre_archivos, ios::in);

    if (!(archivo.is_open())) {

        return false;
    }

    Medicos aux;
    string header;
    char coma;
  
    getline(archivo, header);

    while (archivo) {
        archivo >> aux.Matricula >> coma >> aux.Nombre >> coma >> aux.Apellido >> coma >> aux.Telefono >> coma >> aux.especialidad >> coma >> aux.activo;

        bool aux1 = chequeo_matricula(aux.Matricula);
        bool aux2 = chequeo_AyN(aux.Nombre);
        bool aux3 = chequeo_AyN(aux.Apellido);
        bool aux4 = chequeo_celular(aux.Telefono);
        bool aux5 = chequeo_especialidades(aux.especialidad);
        if (aux1 == true && aux2 == true && aux3 == true && aux4 == true && aux5 == true) {

            bool aux6 = agregar_medico(aux, lista,  tam); // si todo los chequeos dan bien, agrego medico 
           
        }

    }
    
    archivo.close();
    return true; // lo pudo leer 
}

bool agregar_medico(Medicos aux, Medicos*& lista, int* tam) {

    if (lista == NULL) {
        return false;
    }
    int aux1 = buscar_medico(aux.Matricula, lista, *tam);
    
    if (aux1 != -1) {

        return false; // ya esta en la lista el medico
    }

    bool aux2 = redimensionar_medicos(lista, 1, tam);
    if (aux2 == false) {
        return false;
    }
    else {
        lista[*tam-1] = aux; // guardo el nuevo medico en la lista 
        return true;
    }

}
bool redimensionar_medicos(Medicos*& lista, int cantidad_aumentar, int* tam) {

    Medicos* aux = new Medicos[*(tam) + cantidad_aumentar];
    
    if (lista == NULL || aux == NULL) {
        return false;
    }

    for (int i = 0; i < (*tam); i++) {
        *(aux+i) = lista[i];
    }
      
    delete[] lista;
    lista = aux; 
    *tam = *tam + cantidad_aumentar;

    return true; 
}
bool Redimensionar_Consultas(Consulta*& list, int tam) {
    Consulta* aux = new Consulta[tam];
    if (list == NULL || aux == NULL) {
        return false;
    }
    for (int i = 0; i < tam; i++) {
        aux[i] = list[i];
    }
    delete[] list;
    list = aux;
    return true;
}
int buscar_medico(string matricula, Medicos* lista, int tam) {

    if (lista == NULL) {

        return false;

    }
    for (int i = 0; i < tam; i++) {

        if (lista[i].Matricula == matricula) {

            return i;
         }
    }
    return -1;
}

// funciones del punto 1

Paciente* chequeo_10_anios(Paciente* lista_pacientes, int tam_pacientes, Consulta* lista_consulta, int tam_consulta,int* tam_sublista1) {

    if (lista_pacientes == NULL || tam_pacientes == NULL) {

        return NULL; // no devuelve nada o se produjo un error
    }

    Paciente* sub_lista = new Paciente[tam_pacientes];
    int cont_lista = 0;
    Consulta* sublista = new Consulta[0];//lista para la funcion buscar consultas
    int tam_sublista = 0;//tam de la sublista
    time_t now;
    time(&now);
    struct tm* aux = localtime(&now);//se utiliza para ver si pasaron 10 anios
    Paciente* p = new Paciente[0];//lista que se devuelve
    *tam_sublista1 = 0;//tam de la lista q se devuelve
    if (p == NULL) {
        return NULL;
    }
    for (int i = 0; i < tam_pacientes; i++) {
       bool aux1=buscar_consultas_pacientes(lista_pacientes[i].DNI, lista_consulta, tam_consulta, &tam_sublista, sublista);
       if (aux1 == true && sublista !=NULL && tam_sublista!=0)
       {
           Consulta aux2 = consulta_reciente(sublista, tam_sublista);
          
              if ((aux->tm_year+1900)- aux2.Fecha_turno.tm_year >= 10) {
                   if (aux2.Presento == false && lista_pacientes[i].Estado == "fallecido") {
                       bool auxa = archivar_paciente(lista_pacientes[i]);
                   }
               }
               else {
                   if (aux2.Presento == false) {
                       if (lista_pacientes[i].Estado == "fallecido") {
                           bool aux4 = archivar_paciente(lista_pacientes[i]);
                       }
                       if (lista_pacientes[i].Estado != "internado") {
                           agregar_paciente(lista_pacientes[i], p, tam_sublista1);
                       }
                   }
               }
           
       }
    }
    return p; //devuelve los paceintes para contactar

}
bool archivo_secretaria(Paciente* lista, int tam_paciente, Consulta* lista_c, int tam_c, Medicos* lista_m, int tam_m, Contactos* lista_contacto, int tam_contacto, string nombre_archivo) {
    Consulta* consulta_aux = new Consulta[0];
    int tam_n = 0;
    Consulta ultima_consulta;
    fstream archivo;
    archivo.open(nombre_archivo, ios::out | ios::app);// nombre del archivo, pasarlo por el main C/:...
    if (!(archivo.is_open()))
    {
        return false;
    }
    char coma = ',';
    char barra = '/';
    int pos = 0;
    //escribo el header
    archivo << "DNI" <<coma << "nombre" << coma << "apellido" << coma << "telefo de contacto" << coma << "fecha ultima consulta" << coma << "matricula medico" << coma << "apellido medico" << coma << "telefono medico" << coma << "especialidad medico" << coma << "obra social" << endl;
        for (int i = 0; i < tam_paciente; i++)
        {
            buscar_consultas_pacientes(lista[i].DNI, lista_c, tam_c, &tam_n, consulta_aux);

            ultima_consulta = consulta_reciente(consulta_aux, tam_n);// devuelve la ultima consulta del paciente[i]
            //hay que ver que el medico sea el de la ultima consulta
            pos= buscar_medico(ultima_consulta.Matricula_medica, lista_m,tam_m);//le paso la lista de medicos
            string telefono = buscartelefono(lista[i].DNI,lista_contacto , tam_contacto);
            if (pos != -1 && telefono!="-1")
            {
                archivo << lista[i].DNI << coma << lista[i].Nombre << coma << lista[i].Apellido << coma << telefono << coma << ultima_consulta.Fecha_turno.tm_mon<<barra<<ultima_consulta.Fecha_turno.tm_mday<<barra<<ultima_consulta.Fecha_turno.tm_year<<coma<<lista_m[pos].Matricula << coma << lista_m[pos].Apellido << coma << lista_m[pos].Telefono << coma << lista_m[pos].especialidad << coma << lista[i].Obra_soc<<endl;
            }
           
        }
        
        archivo.close();
        delete[] consulta_aux;
        return true;
}
bool archivar_paciente(Paciente aux) {
    fstream archivo;
    char coma = ',';
    char barra = '/';
    archivo.open("C:/Users/Electro PC/Desktop/facultad/Redes e Internet/Final 2022/final/data_files/input/Archivados.csv", ios::app);
    if (!(archivo.is_open())) {
        return false;
    }
    archivo << aux.DNI << coma << aux.Nombre << coma << aux.Apellido << coma << aux.Sexo << coma << aux.Nacimiento.tm_mday << barra << aux.Nacimiento.tm_mon << barra << aux.Nacimiento.tm_year << coma << aux.Estado << coma << aux.Obra_soc << endl;
    archivo.close();
    return true;
}
bool buscar_consultas_pacientes(string dni, Consulta* lista, int tam, int* tam_n, Consulta*& new_list) {
    if (lista == NULL || new_list == NULL)
        return false;
    Consulta* lista_aux = new Consulta[tam];

    int contador_lista = 0;

    for (int i = 0; i < tam; i++) {

        if (lista[i].DNI == dni) {

            lista_aux[contador_lista] = lista[i];
            contador_lista++;

        }
    }
    *(tam_n) = contador_lista;
    Redimensionar_Consultas(lista_aux, contador_lista);
    delete[] new_list;
    new_list = lista_aux;
    return true;

}
Consulta consulta_reciente(Consulta* lista,int tam) {//devuelve la ultima consulta 
    double fecha1, fecha2;
    int pos=0;
    fecha1 = lista[0].Fecha_turno.tm_year*10000+lista[0].Fecha_turno.tm_mon*100 + lista[0].Fecha_turno.tm_mday;
    for (int i = 1; i < tam; i++) {
        fecha2 = lista[i].Fecha_turno.tm_year * 10000 + lista[i].Fecha_turno.tm_mon * 100 + lista[i].Fecha_turno.tm_mday;
        if (fecha2>fecha1) {
            fecha1 = fecha2;
            pos = i;
        }
    }
    return lista[pos];
}
string buscartelefono(string dni, Contactos* lista, int tam)
{
    if (lista == NULL)
    {
        return "-1";
    }
    for (int i = 0; i < tam; i++)
    {
        if (lista[i].DNI_paciente == dni)
        {
            return lista[i].Telefono;//devuelvo el telefono del paciente
        }

    }
    //si sale del for es porque no hay contacto con ese dni
    return "-1";
}
bool pasar_archivo_secretaria(string archivo_secretaria, Consulta*& lista_c, int* tam_consulta) {

    fstream archivo_secre;

    archivo_secre.open (archivo_secretaria, ios::in);

    if (!(archivo_secre.is_open())) {
        return false;
    }

    string header;
    char coma;
    Secretaria aux;
    char barra;
    getline(archivo_secre, header);
    bool reprogra;
    Consulta aux1;
    bool fecha_soli;
  

    while (archivo_secre) {

        archivo_secre >> aux.DNI >> coma >> aux.Nombre >> aux.Apellido >> coma >> aux.Telefono >> coma >> aux.Fecha_turno.tm_mon >> barra >> aux.Fecha_turno.tm_mday >> barra >> aux.Fecha_turno.tm_year >> coma >> aux.Matricula_medica >> coma >> aux.apellido_medico >> coma >> aux.Telofono_medico >> coma >> aux.especialidad_medico >> coma >> aux.Obra_soc;


        reprogra = reprogramar();
        aux.Obra_soc = cambiar_os(aux.Obra_soc);// si quiere cambiar la obra social pisa el dato anterior
        if (reprogra == true) {

            Rand_fecha(&aux1.Fecha_turno.tm_mday, &aux1.Fecha_turno.tm_mon, &aux1.Fecha_turno.tm_year);

            Rand_fecha(&aux1.Fecha_solicitado.tm_mday, &aux1.Fecha_solicitado.tm_mon, &aux1.Fecha_solicitado.tm_year);

            aux1.DNI = aux.DNI;
            aux1.Presento = false;
            aux1.Matricula_medica = aux.Matricula_medica; // relleno el aux1 


            fecha_soli = chequeofechasolicitado(aux1.Fecha_solicitado, aux1.Fecha_turno);

            if (fecha_soli == true) {

                agregar_consulta(aux1, lista_c, tam_consulta);

            }


        }

    }
          archivo_secre.close();
          return true;
}

bool reprogramar() {
    int aux;
    
    srand(time(NULL));
    aux = rand () % 2; // me devuelve entre 0 y 1
    if (aux == 0) {
        return true; // reprogramo 
    }
    else {
        return false; // no reprogramo 
    }
}

bool escribir_consulta(string archivo, Consulta*& lista, int* tam) {

    fstream archivo_esc;

    archivo_esc.open(archivo, ios::out);

    if (!(archivo_esc.is_open())) {
        return false;
    }
    char coma = ',';
    char barra = '/';
    archivo_esc << "dni_pac" << coma << "fecha_solicitado" << coma << "fecha_turno" << coma << "presento" << coma << "matricula_med" << endl;
    for (int i = 0; i < *tam; i++) {

        archivo_esc << lista[i].DNI << coma << lista[i].Fecha_solicitado.tm_mday << barra << lista[i].Fecha_solicitado.tm_mon << barra << lista[i].Fecha_solicitado.tm_year << coma << lista[i].Fecha_turno.tm_mday << barra << lista[i].Fecha_turno.tm_mon << barra << lista[i].Fecha_turno.tm_year << coma << lista[i].Presento << coma << lista[i].Matricula_medica << endl;
            

    }
    archivo_esc.close();
    return true;
}
bool Leer_Contacto(string archivo, Contactos*& lista, int* tam)
{
    fstream archivo_con;
    archivo_con.open(archivo, ios::in);
    if (!(archivo_con.is_open())) 
    return false;
    Contactos aux;
    string header;
    char coma;

    getline(archivo_con, header);

    while (archivo_con) {
    
        archivo_con >> aux.DNI_paciente >> coma >> aux.Telefono >> coma >> aux.Celular >> coma >> aux.Direccion >> coma >> aux.Mail;
        bool aux1 = chequear_DNI(aux.DNI_paciente);
        bool aux2 = chequeo_celular(aux.Telefono);
        bool aux3 = chequeo_celular(aux.Celular);
        bool aux4 = chequeo_direccion(aux.Direccion);
        bool aux5 = chequeo_Mail(aux.Mail);
        if (aux1 == true && aux2 == true && aux3 == true && aux4 == true && aux5 == true)
            Agregar_Contacto(aux, lista, tam);
    }



    return true;
}
bool Redimencionar_c(Contactos*& list, int* tam)
{
    Contactos* lista_aux = new Contactos[*(tam)+1];
    
    if (list == NULL || lista_aux == NULL) {
        return false;
    }
    for (int i = 0; i < *tam; i++) {
        lista_aux[i] = list[i];
    }
    delete[] list;
    list = lista_aux;
    (*tam) = (*tam) + 1;
    return true;

   
}
bool Agregar_Contacto(Contactos aux, Contactos*& list, int* tam)
{
    if (list == NULL ) {
        return false;
    }
    bool var = Redimencionar_c(list, tam);
    
    if (var == true)
    {
        list[*tam - 1] = aux;
        return true;
    }
    else return false;
}
bool Abrir_Archivado(string nombre_arc)
{
    fstream archivo;
    char coma = ',';
    char barra = '/';
    archivo.open(nombre_arc, ios::out);
    if (!(archivo.is_open())) {
        return false;
    }
    archivo << "DNI" << coma << "nombre" << coma << "apellido" << coma << "sexo" << coma << "natalicio" << coma << "estado" << coma << "id_os" << endl;
    
    archivo.close();
    return true;
}
string cambiar_os(string obrasoc) {
    srand(time(NULL));
    int aux=rand()%2;
    if (aux == 0) {
        aux = rand() % 6;
        switch (aux)
        {
        case 0:
            return "OSDE";
        case 1:
            return "Italiano";
        case 2:
            return "Espanyol";
        case 3:
            return "ALemen";
        case 4:
            return "IOSFA";
        case 5:
            return "Medicus";
        default:
            break;
        }

    }
    else return obrasoc;

}



//bool chequeo_celular(string cel);
