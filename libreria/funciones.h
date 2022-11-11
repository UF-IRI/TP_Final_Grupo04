#pragma once
#include<iostream>
#include<cstdlib>
#include<string>
#include<ctime>
#include<fstream>

using namespace std;
///*num Especialidad { hematologia,estomatologia, anestesiologia, nefrologia, psiquiatria, endocrinologia, reumatologia, genetica, hepatologia, pediatria,
//    geriatria,cardiologia,gastroenterologia,medicina_intensiva,medicina_forence,toxicologia,nutrilogia,oncologia_medica,medicina_ionterna,alegologia, infectologia,
//neurologia};*/
typedef struct Consultas {

	string DNI;
	tm Fecha_solicitado;
	tm Fecha_turno;
	bool Presento;
	string Matricula_medica;
};

typedef struct Contactos {
	string DNI_paciente;
	string Telefono;
	string Celular;
	string Direccion;
	string Mail;

};

typedef struct Medicos {

	string Matricula;
	string Nombre;
	string Apellido;
	string Telefono;
	//especialidad consultar a eze

	bool activo;
};

typedef struct Obra_Social {
	unsigned int id;
	string obra_soc;


};

typedef struct Paciente {
	string DNI;
	string Nombre;
	string Apellido;
	char Sexo;
	tm Nacimiento;
	string Estado; //son 3: n/c,fallecio, internado
	string Obra_soc;
};
bool leer_pacientes(string nombredearchivo,Paciente*& Lista_pacientes, int* tam );//esta funcion lee archivo pacientes.csv y los guarda en lista
bool chequear_DNI(string dni);
bool chequeo_AyN(string& AyN); // esta funcion chequea nombre y apellidos de pacientes
bool chequeo_telefono(string tel);
bool chequeo_celular(string cel);
bool chequeo_matricula(string matricula);
bool chequeo_direccion(string direc);
bool chequeo_Mail(string mail);
bool chequeargenero(char letra);
bool chequearfecha_nacimiento(string fecha); // rechequear 
bool chequeoObra_social(string Obra_soc, string *listaObra_soc, int tam);//mira lista de obras sociales creada a partir de obrassociales.csv
bool chequeo_especialedad(string e);
bool agregar_paciente(Paciente aux, Paciente*& lista, int* tam);