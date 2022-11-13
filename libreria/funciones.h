#pragma once
#include<iostream>
#include<cstdlib>
#include<string>
#include<ctime>
#include<fstream>

using namespace std;
///*num Especialidad { hematologia,estomatologia, anestesiologia, nefrologia, psiquiatria, endocrinologia, reumatologia, genetica, hepatologia, pediatria,
// geriatria,cardiologia,gastroenterologia,medicina_intensiva,medicina_forence,toxicologia,nutrilogia,oncologia_medica,medicina_ionterna,alegologia, infectologia,
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
	string especialidad; 
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
	string Estado; //son 3:n/c,fallecio, internado
	string Obra_soc;
};
/// <summary>
/// funciones de archivos
/// </summary>
/// <param name="nombredearchivo"></param>
/// <param name="Lista_pacientes"></param>
/// <param name="tam"></param>
/// <returns></returns>
bool leer_pacientes(string nombredearchivo, Obra_Social* lista_os, Paciente*& Lista_pacientes, int* tam, int tam_os);//esta funcion lee archivo pacientes.csv y los guarda en lista
bool leer_Consultas(string nombredearchivo, Consulta*& Lista_consultas, int* tam);
bool leer_Obrasoc(string nombredearchivo, Obra_Social*& Lista_obrasoc, int* tam);
/// <summary>
/// funciones que  chequean datos
/// </summary>
/// <param name="dni"></param>
/// <returns></returns>
bool chequear_DNI(string dni);
bool chequeo_AyN(string AyN); // esta funcion chequea nombre y apellidos de pacientes
bool chequeo_telefono(string tel);
bool chequeo_celular(string cel);
bool chequeo_matricula(string matricula);
bool chequeo_direccion(string direc);
bool chequeo_Mail(string mail);
bool chequeargenero(char letra);
bool chequearfecha(int dia, int mes, int anio); //chequea que dia estre entre 0 y 31, mes entre  y 12,anio sean posit 
bool chequeoObra_social(string Obra_soc, Obra_Social *listaObra_soc, int tam);//mira lista de obras sociales creada a partir de obrassociales.csv

bool chequeo_especialidades(string e);
bool chequeoNacimiento(tm fecha);
bool chequeo_estado(string estado);
bool chequeofechasolicitado(tm fecha_solicitado, tm fecha_turno);//chequeo que la  fecha solicitado sea menor q la del turno
//hay que hace una funcion que chequee que la fecha_nacim sea menor que la actual
//idea de una funcion que se llame chequear datos, que llame a todos los chequear

///funciones de listas
bool agregar_paciente(Paciente aux, Paciente*& lista, int* tam);
int buscarpaciente(string dni, Paciente* lista, int tam);//busca al paciente en la lista si lo encuentra devuelv pos,-1 si no esta o error
bool redimensionarp(Paciente*& lista, int* tam, int cant_aumentar);//redimensiona una lista de pacientes
bool agregar_consulta(Consulta aux, Consulta*& lista, int* tam);//funcion para agregar consultas en una lista
bool redimensionarc(Consulta*& lista, int* tam, int cant_aumentar);//funcion para redimensionar lista de consultas
bool Agregar_obrasoc(Obra_Social*& lista, int* tam, Obra_Social dato);

void Rand_fecha(int* dia, int* mes, int* anio);//genera fechas random
bool leer_medicos(string nombre_archivos, Medicos*& lista, int* tam);
bool agregar_medico(Medicos aux, Medicos*& lista, int* tam);
int buscar_medico(string matricula, Medicos* lista, int tam);
bool redimensionar_medicos(Medicos*& lista, int cantidad_aumentar, int* tam);
bool Redimensionar_Consultas(Consultas*& list, int tam);
// funciones punto 1 
Paciente* chequeo_10_anios(Paciente* lista_pacientes, int tam_pacientes , Consulta* lista_consulta, int tam_consulta );
bool buscar_consultas_pacientes(string dni, Consulta* lista, int tam, int* tam_n, Consulta*& new_list); // busca la cantidad de consulta que tiene ese pasiente 
Consulta consulta_reciente(Consulta* lista, int tam);
