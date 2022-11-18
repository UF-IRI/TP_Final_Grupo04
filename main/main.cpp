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

    Consulta* Lista_Consultas = new Consulta[0];
    Paciente* Lista_Pacientes = new Paciente[0];
    Medicos* Lista_Medicos = new Medicos[0];
    Contactos* Lista_Contactos = new Contactos[0];
    
    
   //leer_medicos("C:/Users/Electro PC/Desktop/facultad/Redes e Internet/Final 2022/final/data_files/input/Medicos.csv",Lista_Medicos,&tam_medico);
    //leer_Consultas("C:/Users/Electro PC/Desktop/facultad/Redes e Internet/Final 2022/final/data_files/input/Consultas.csv", Lista_Consultas, &tam_consulta);
    leer_pacientes("C:/Users/Usuario/source/repo/sTP_Final_Grupo04/data_files/input/Pacientes.csv",Lista_Pacientes,&tam_paciente);
    
    //leer_Consultas("")
    

    delete[] Lista_Consultas;
    delete[]  Lista_Contactos;
    delete[] Lista_Medicos;   
    delete[] Lista_Pacientes;
    return EXIT_SUCCESS;
}
