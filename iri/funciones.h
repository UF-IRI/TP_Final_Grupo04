#pragma once
#include <iostream>
#include <ctime>
using namespace std;
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

typedef struct Pacientes {
	string DNI;
	string Nombre;
	string Apellido;
	char Sexo;
	tm Nacimiento;
	string Estado; //son 3: n/c,fallecio, internado
	string Obra_soc;
};