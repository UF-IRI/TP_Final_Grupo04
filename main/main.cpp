#include "iri.cpp"
#include "funciones.cpp"
#include <iostream>
#include <fstream>


using namespace std;
int main() {
    int tam_consulta = 0;
    int tam_paciente = 0;
    int tam_medico = 0;
    int tam_contacto = 0;
    int tam_sublista = 0;
    Consulta* Lista_Consultas = new Consulta[0];
    Paciente* Lista_Pacientes = new Paciente[0];
    Medicos* Lista_Medicos = new Medicos[0];
    Contactos* Lista_Contactos = new Contactos[0];
    Paciente* sub_lista = new Paciente[0];
    Abrir_Archivado("C:/Users/Electro PC/Desktop/facultad/Redes e Internet/Final 2022/final/data_files/input/Archivados.csv");
    leer_medicos("C:/Users/Electro PC/Desktop/facultad/Redes e Internet/Final 2022/final/data_files/input/Medicos.csv", Lista_Medicos, &tam_medico);
    leer_Consultas("C:/Users/Electro PC/Desktop/facultad/Redes e Internet/Final 2022/final/data_files/input/Consultas.csv", Lista_Consultas, &tam_consulta);
    leer_pacientes("C:/Users/Electro PC/Desktop/facultad/Redes e Internet/Final 2022/final/data_files/input/Pacientes.csv", Lista_Pacientes, &tam_paciente);
    Leer_Contacto("C:/Users/Electro PC/Desktop/facultad/Redes e Internet/Final 2022/final/data_files/input/Contactos.csv", Lista_Contactos, &tam_contacto);
    Ordenar_Paciente(Lista_Pacientes, tam_paciente);
    sub_lista = chequeo_10_anios(Lista_Pacientes, tam_paciente, Lista_Consultas, tam_consulta, &tam_sublista);
    archivo_secretaria(sub_lista, tam_sublista, Lista_Consultas, tam_consulta, Lista_Medicos, tam_medico, Lista_Contactos, tam_contacto, "C:/Users/Electro PC/Desktop/facultad/Redes e Internet/Final 2022/final/data_files/input/Secretaria.csv");
   
   pasar_archivo_secretaria("C:/Users/Electro PC/Desktop/facultad/Redes e Internet/Final 2022/final/data_files/input/Secretaria.csv", Lista_Consultas, &tam_consulta);
   escribir_consulta("C:/Users/Electro PC/Desktop/facultad/Redes e Internet/Final 2022/final/data_files/input/Consultas.csv", Lista_Consultas, &tam_consulta);
    //funciones que utlizan consulta, leer consultas(ver cuantas consultas lee), chequeo 10 anios, pasar archivo secretaria,escribir archivo secretaria,

   //ver si agregamos los chequeos adentro de la funcion agregar?

    delete[] Lista_Consultas;
    delete[]  Lista_Contactos;
    delete[] Lista_Medicos;   
    delete[] Lista_Pacientes;
    delete[] sub_lista;
    return EXIT_SUCCESS;
}
