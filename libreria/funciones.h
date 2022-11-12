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
typedef struct Consulta {

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
/// <summary>
/// funciones de archivos
/// </summary>
/// <param name="nombredearchivo"></param>
/// <param name="Lista_pacientes"></param>
/// <param name="tam"></param>
/// <returns></returns>
bool leer_pacientes(string nombredearchivo,Paciente*& Lista_pacientes, int* tam );//esta funcion lee archivo pacientes.csv y los guarda en lista

/// <summary>
/// funciones que  chequean datos
/// </summary>
/// <param name="dni"></param>
/// <returns></returns>
bool chequear_DNI(string dni);
bool chequeo_AyN(string& AyN); // esta funcion chequea nombre y apellidos de pacientes
bool chequeo_telefono(string tel);
bool chequeo_celular(string cel);
bool chequeo_matricula(string matricula);
bool chequeo_direccion(string direc);
bool chequeo_Mail(string mail);
bool chequeargenero(char letra);
bool chequearfecha(int dia, int mes, int anio); //chequea que dia estre entre 0 y 31, mes entre  y 12,anio sean posit 
bool chequeoObra_social(string Obra_soc, string *listaObra_soc, int tam);//mira lista de obras sociales creada a partir de obrassociales.csv
bool chequeo_especialedad(string e);
//hay que hace una funcion que chequee que la fecha_nacim sea menor que la actual
//idea de una funcion que se llame chequear datos, que llame a todos los chequear

///funciones de listas
bool agregar_paciente(Paciente aux, Paciente*& lista, int* tam);
int buscarpaciente(string dni, Paciente* lista, int tam);//busca al paciente en la lista si lo encuentra devuelv pos,-1 si no esta o error
bool redimensionarp(Paciente*& lista, int* tam, int cant_aumentar);//redimensiona una lista de pacientes
bool agregar_consulta(Consulta aux, Consulta*& lista, int* tam);//funcion para agregar consultas en una lista
bool redimensionarc(Consulta*& lista, int* tam, int cant_aumentar);//funcion para redimensionar lista de consultas
