
#include"funciones.h"

bool chequear_DNI(string dni) {

    int tam = dni.length();//devuelvo el tamanio del string
    if (tam != 7 && tam != 8) {
        return false; //por si el paciente tiene en su DNI 8 a 7 cifras
    }
    for (int i = 0; i < tam; i++) {

        if (dni[i] < '0' || dni[i] > '9') {
            return false;
        }

    }

    return true;

}

bool chequeo_AyN(string& AyN) {


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
            return true;
        }

        return false;
    }
}

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

    //leeo el header

    //recorro el archivo
    while (archivo)
    {
        
    }
}