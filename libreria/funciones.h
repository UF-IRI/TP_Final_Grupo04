#pragma once
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include <regex>
#include<fstream>

using namespace std;
///*num Especialidad { hematologia,estomatologia, anestesiologia, nefrologia, psiquiatria, endocrinologia, reumatologia, genetica, hepatologia, pediatria,
// geriatria,cardiologia,gastroenterologia,medicina_intensiva,medicina_forence,toxicologia,nutrilogia,oncologia_medica,medicina_ionterna,alegologia, infectologia,
//neurologia};*/
 struct Consulta {

	string DNI;
	tm Fecha_solicitado;
	tm Fecha_turno;
	bool Presento;
	string Matricula_medica;
};

 struct Contactos {
	string DNI_paciente;
	string Telefono;
	string Celular;
	string Direccion;
	string Mail;

};

 struct Medicos {

	string Matricula;
	string Nombre;
	string Apellido;
	string Telefono;
	string especialidad; 
	bool activo;
};

 /*struct Obra_Social {
	unsigned int id;
	string obra_soc;
};*/

 struct Paciente {
	string DNI;
	string Nombre;
	string Apellido;
	char Sexo;
	tm Nacimiento;
	string Estado; //son 3:n/c,fallecio, internado
	string Obra_soc;
};

// estructura secretaria con nuevos de pacientes 
 struct Secretaria {
	string DNI;
	string Nombre;
	string Apellido;
	string Obra_soc;
	tm Fecha_turno;
	string Telefono;
	string Matricula_medica;
	string Telofono_medico;
	string apellido_medico;
	string especialidad_medico;
};




/// <summary>
/// funciones de archivos
/// </summary>
/// <param name="nombredearchivo"></param>
/// <param name="Lista_pacientes"></param>
/// <param name="tam"></param>
/// <returns></returns>
bool leer_pacientes(string nombredearchivo, Paciente*& Lista_pacientes, int* tam);//esta funcion lee archivo pacientes.csv y los guarda en lista
bool leer_Consultas(string nombredearchivo, Consulta*& Lista_consultas, int* tam);
//bool leer_Obrasoc(string nombredearchivo, Obra_Social*& Lista_obrasoc, int* tam);
/// <summary>
/// funciones que  chequean datos
/// </summary>
/// <param name="dni"></param>
/// <returns></returns>
bool chequear_DNI(string dni);
bool chequeo_AyN(string AyN); // esta funcion chequea nombre y apellidos de pacientes
//bool chequeo_telefono(string tel);
bool chequeo_celular(string cel);
bool chequeo_matricula(string matricula);
bool chequeo_direccion(string direc);
bool chequeo_Mail(string mail);
bool chequeargenero(char letra);
bool chequearfecha(int dia, int mes, int anio); //chequea que dia estre entre 0 y 31, mes entre  y 12,anio sean posit 
//bool chequeoObra_social(string Obra_soc, Obra_Social *listaObra_soc, int tam);//mira lista de obras sociales creada a partir de obrassociales.csv

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
bool Ordenar_Paciente(Paciente*& lista, int tam);

string buscartelefono(string dni, Contactos* lista, int tam);

void Rand_fecha(int* dia, int* mes, int* anio);//genera fechas random
bool leer_medicos(string nombre_archivos, Medicos*& lista, int* tam);
bool agregar_medico(Medicos aux, Medicos*& lista, int* tam);
int buscar_medico(string matricula, Medicos* lista, int tam);
bool redimensionar_medicos(Medicos*& lista, int cantidad_aumentar, int* tam);
bool Redimensionar_Consultas(Consulta*& list, int tam);
// funciones punto 1 
Paciente* chequeo_10_anios(Paciente* lista_pacientes, int tam_pacientes , Consulta* lista_consulta, int tam_consulta, int* tam_sublista1);
bool buscar_consultas_pacientes(string dni, Consulta* lista, int tam, int* tam_n, Consulta*& new_list); // busca la cantidad de consulta que tiene ese pasiente 
Consulta consulta_reciente(Consulta* lista, int tam);
bool archivar_paciente(Paciente aux);
bool archivo_secretaria(Paciente* lista, int tam_paciente,Consulta* lista_c,int tam_c,Medicos* lista_m,int tam_m,Contactos* lista_contacto, int tam_contacto, string nombre_archivo);//crea el archivo que luego va utilizar la secretaria
bool pasar_archivo_secretaria(string archivo_secretaria, Consulta*& lista_c, int * tam_consulta );
bool reprogramar();
bool escribir_consulta(string archivo, Consulta*& lista, int* tam);
bool Leer_Contacto(string archivo, Contactos*& lista, int* tam);
bool Redimencionar_c(Contactos*& list, int* tam);
bool Agregar_Contacto(Contactos aux, Contactos*& list, int* tam);
bool Abrir_Archivado(string nombre_arc);
string cambiar_os(string obrasoc);