#include "gmock/gmock.h"
#include"funciones.h"
namespace Casos_Base::tests {
	TEST(Casos_Base, Test_Caso1) {
		ASSERT_THAT(1, 1);
	}

	TEST(Casos_Base, Test_Caso2) {
		ASSERT_THAT(1, 1);
	}

	TEST(Casos_Base, Test_Caso3) {
		ASSERT_THAT(1, 1);
	}
}
//bool redimensionarp(Paciente*& lista, int* tam, int cant_aumentar);
TEST(redimensionarp, redimensionarp_CORRECTO)
{
	Paciente* lista = new Paciente[1];
	int tam = 1;
	int cant_aumentar = 1;


	ASSERT_TRUE(redimensionarp(lista,&tam,cant_aumentar));
	delete[] lista;
}
TEST(redimensionarp, redimensionarp_INCORRECTO)
{
	Paciente* lista = new Paciente[1];
	lista = NULL;
	int tam = 1;
	int cant_aumentar = 1;


	ASSERT_FALSE(redimensionarp(lista, &tam, cant_aumentar));
	delete[] lista;
}

//bool redimensionar_medicos(Medicos*& lista, int cantidad_aumentar, int* tam);
//bool Redimensionar_Consultas(Consulta*& list, int tam);


TEST(redimensionar_medicos, redimensionar_medicos_CORRECTO)
{
	Medicos* lista = new Medicos[1];
	int tam = 1;
	int cant_aumentar = 1;


	ASSERT_TRUE(redimensionar_medicos(lista,cant_aumentar, &tam));
	delete[] lista;
}
TEST(redimensionar_medicos, redimensionar_medicos_INCORRECTO)
{
	Medicos* lista = new Medicos[1];
	lista = NULL;
	int tam = 1;
	int cant_aumentar = 1;


	ASSERT_FALSE(redimensionar_medicos(lista,cant_aumentar, &tam));
	delete[] lista;
}
TEST(Redimensionar_Consultas, Redimensionar_Consultas_CORRECTO)
{
	Consulta* lista = new Consulta[1];
	int tam = 1;
	


	ASSERT_TRUE(Redimensionar_Consultas(lista, tam));
	delete[] lista;
}
TEST(Redimensionar_Consultas, Redimensionar_Consultas_INCORRECTO)
{
	Consulta* lista = new Consulta[1];
	lista = NULL;
	int tam = 1;
	


	ASSERT_FALSE(Redimensionar_Consultas(lista, tam));
	delete[] lista;
}


//chequeo dni
TEST(chequear_DNI,DNI_letras)
{
	ASSERT_FALSE(chequear_DNI("4395815pl"));
}
TEST(chequear_DNI, DNI_simbolos)
{
	ASSERT_FALSE(chequear_DNI("4395/81%"));
}
TEST(chequear_DNI, DNI_espacios)
{
	ASSERT_FALSE(chequear_DNI("4395 81%"));
}
TEST(chequear_DNI, DNI_comun)
{
	ASSERT_TRUE(chequear_DNI("439581234"));
}
//bool chequeo_AyN(string AyN)
TEST(chequeo_AyN,nombre_numeros)
{
	ASSERT_FALSE(chequeo_AyN("marian3o"));
}
TEST(chequeo_AyN, nombre_numeros_esp)
{
	ASSERT_FALSE(chequeo_AyN("marianno 100"));
}
TEST(chequeo_AyN, nombre_simbolos)
{
	ASSERT_FALSE(chequeo_AyN("mari%ano !ariel"));
}

TEST(chequeo_AyN, nombre_comun_esp)
{
	ASSERT_TRUE(chequeo_AyN("mariano carlos"));
}
TEST(chequeo_AyN, nombre_comun_mayus)
{
	ASSERT_TRUE(chequeo_AyN("Mariano Carlos"));
}
////bool chequeo_Mail(string mail);
TEST(chequeo_Mail, mail_sin_punto)
{
	ASSERT_FALSE(chequeo_Mail("favaloroalumnos@gmailcom"));
}
TEST(chequeo_Mail, mail_sin_arroba)
{
	ASSERT_FALSE(chequeo_Mail("favaloroalumnosgmail.com"));
}
TEST(chequeo_Mail, mail_espacios)
{
	ASSERT_FALSE(chequeo_Mail("favaloroalumnos @gmail.com"));
}
TEST(chequeo_Mail, mail_simbolos)
{
	ASSERT_FALSE(chequeo_Mail("faval%oroa!lumno@gmail.com"));
}
TEST(chequeo_Mail, mail_comun1)
{
	ASSERT_TRUE(chequeo_Mail("favaloroalumnos@gmail.com"));
}
TEST(chequeo_Mail, mail_comun2)
{
	ASSERT_TRUE(chequeo_Mail("mariapereyra265@gmail.com"));
}
TEST(chequeo_Mail, mail_comun3)
{
	ASSERT_TRUE(chequeo_Mail("uf@gmail.com.ar"));
}
//bool chequeargenero(char letra);
TEST(chequeargenero, genero_M)
{
	ASSERT_TRUE(chequeargenero('M'));
}
TEST(chequeargenero, genero_F)
{
	ASSERT_TRUE(chequeargenero('F'));
}
TEST(chequeargenero, genero_f)
{
	ASSERT_TRUE(chequeargenero('f'));
}
TEST(chequeargenero, genero_x)
{
	ASSERT_FALSE(chequeargenero('x'));
}
TEST(chequeargenero, genero_simbolos)
{
	ASSERT_FALSE(chequeargenero('%'));
}
TEST(chequeargenero, genero_numeros)
{
	ASSERT_FALSE(chequeargenero('2'));
}
//bool chequeo_direccion(string direc);
TEST(chequeo_direccion,direc_simbolos)
{
	ASSERT_FALSE(chequeo_direccion("centr!o a(sturiano"));
}
TEST(chequeo_direccion, direc_may)
{
	ASSERT_TRUE(chequeo_direccion("Centro Asturiano"));
}
TEST(chequeo_direccion, direc_puntos)
{
	ASSERT_FALSE(chequeo_direccion("centro asturian.o"));
}
TEST(chequeo_direccion, direc_comun1)
{
	ASSERT_TRUE(chequeo_direccion("centro asturiano"));
}
TEST(chequeo_direccion, direc_comun2)
{
	ASSERT_TRUE(chequeo_direccion("centro asturiano 1234"));
}
TEST(chequeo_celular, cel_simbolos)
{
	ASSERT_FALSE(chequeo_celular("2*$,55"));
}
TEST(chequeo_celular, cel_letras)
{
	ASSERT_FALSE(chequeo_celular("2abbbbc"));
}
TEST(chequeo_celular, cel_comun)
{
	ASSERT_TRUE(chequeo_celular("+57 722 907 7201"));
}
TEST(chequearfecha, fecha_negativa )
{
	ASSERT_FALSE(chequearfecha(-2, -6, -2020));
}
TEST(chequearfecha, fecha_larga)
{
	ASSERT_FALSE(chequearfecha(222, 500, 22020));
}
TEST(chequearfecha, fecha_mesmal)
{
	ASSERT_FALSE(chequearfecha(2, 16, 2020));
}
TEST(chequearfecha, fecha_comun)
{
	ASSERT_TRUE(chequearfecha(15, 11, 2022));
}
TEST(chequeo_especialidades,especialidad_numero )
{
	ASSERT_FALSE(chequeo_especialidades("55555"));
}
TEST(chequeo_especialidades, especialidad_simbolos)
{
	ASSERT_FALSE(chequeo_especialidades("¿?-¨´"));
}
TEST(chequeo_especialidades, especialidad_mayuscula)
{
	ASSERT_TRUE(chequeo_especialidades("medico Clinico"));
}
TEST(chequeo_especialidades, especialidad_minuscula)
{
	ASSERT_TRUE(chequeo_especialidades("medico pediatra"));
}
  // bool chequeoNacimiento(tm fecha) 
TEST(chequeoNacimiento, fecha_negativa)
{
	tm fecha; // creamos un estructura fecha
	fecha.tm_year = 2020;
	fecha.tm_mon = 7;
	fecha.tm_mday = -8;

	ASSERT_FALSE(chequeoNacimiento(fecha));
}
TEST(chequeoNacimiento, fecha_comun) // ver error, unit test no dio bien 
{
	tm fecha; // creamos un estructura fecha
	fecha.tm_year = 2020;
	fecha.tm_mon = 7;
	fecha.tm_mday = 10;

	ASSERT_TRUE(chequeoNacimiento(fecha));
}
TEST(chequeoNacimiento, fecha_mayor_actual) // fecha mayor a la actual	
{
	tm fecha; // creamos un estructura fecha
	fecha.tm_year = 2027;
	fecha.tm_mon = 11;
	fecha.tm_mday = 9;

	ASSERT_FALSE(chequeoNacimiento(fecha));
}
 //bool chequeo_estado(string estado);

TEST(chequeo_estado, estado_incorrecto ) 
{
	
	ASSERT_FALSE(chequeo_estado("de_alta"));
}
TEST(chequeo_estado, estado_con_simbolo)
{

	ASSERT_FALSE(chequeo_estado("@ "));
}
TEST(chequeo_estado, estado_CORRECTO)
{

	ASSERT_TRUE(chequeo_estado("fallecido"));
}
TEST(chequeo_estado, estado_MAYUSCULA)
{

	ASSERT_FALSE(chequeo_estado("FALLECIDO"));
}
 //bool chequeofechasolicitado(tm fecha_solicitado, tm fecha_turno);
TEST(chequeofechasolicitado, fecha_solicitado_mayor_a_fecha_turno)
{

	tm fecha_s; // fecha solicitado
	fecha_s.tm_year = 2020;
	fecha_s.tm_mon = 11;
	fecha_s.tm_mday = 8;

	tm fecha_t; //fecha turno
	fecha_t.tm_year = 2018;
	fecha_t.tm_mon = 11;
	fecha_t.tm_mday = 9;


	ASSERT_FALSE(chequeofechasolicitado(fecha_s, fecha_t)); 
	
}
TEST(chequeofechasolicitado, fecha_solicitado_menor_a_fecha_turno)
{

	tm fecha_s; // fecha solicitado
	fecha_s.tm_year = 2010;
	fecha_s.tm_mon = 11;
	fecha_s.tm_mday = 8;

	tm fecha_t; //fecha turno
	fecha_t.tm_year = 2019;
	fecha_t.tm_mon = 11;
	fecha_t.tm_mday = 9;


	ASSERT_TRUE(chequeofechasolicitado(fecha_s, fecha_t));
}
TEST(chequeofechasolicitado, fecha_solicitado_negativo_a_fecha_turno)
{

	tm fecha_s; // fecha solicitado
	fecha_s.tm_year = -2020;
	fecha_s.tm_mon = 11;
	fecha_s.tm_mday = 8;

	tm fecha_t; //fecha turno
	fecha_t.tm_year = 2017;
	fecha_t.tm_mon = 11;
	fecha_t.tm_mday = 9;


	ASSERT_FALSE(chequeofechasolicitado(fecha_s, fecha_t));
}
TEST(chequeofechasolicitado, fecha_solicitado_igual_a_fecha_turno)
{

	tm fecha_s; // fecha solicitado
	fecha_s.tm_year = 2020;
	fecha_s.tm_mon = 11;
	fecha_s.tm_mday = 8;

	tm fecha_t; //fecha turno
	fecha_t.tm_year = 2020;
	fecha_t.tm_mon = 11;
	fecha_t.tm_mday = 8;


	ASSERT_FALSE(chequeofechasolicitado(fecha_s, fecha_t)); // chequear si las fechas al ser iguales tiene que dar verdadero o falso
}
 // bool chequeoObra_social(string Obra_soc, Obra_Social* listaObra_soc, int tam)


TEST(chequeoObra_social, chequeoObra_social_incorrecta)
{
	int tam = 6;
	Obra_Social* chequeo = new Obra_Social[tam];
	chequeo[0].obra_soc = "Medicus";
	chequeo[1].obra_soc = " OSDE";
	chequeo[2].obra_soc = "IOSFA";
	chequeo[3].obra_soc = "Italiano";
	chequeo[4].obra_soc = "Aleman";
	chequeo[5].obra_soc = "Espanyol";

	ASSERT_FALSE(chequeoObra_social("pami",chequeo,tam)); 
	delete[] chequeo;
}
TEST(chequeoObra_social, chequeoObra_social_correcta)
{
	int tam = 6;
	Obra_Social* chequeo = new Obra_Social[tam];
	chequeo[0].obra_soc = "Medicus";
	chequeo[1].obra_soc = " OSDE";
	chequeo[2].obra_soc = "IOSFA";
	chequeo[3].obra_soc = "Italiano";
	chequeo[4].obra_soc = "Aleman";
	chequeo[5].obra_soc = "Espanyol";

	ASSERT_TRUE(chequeoObra_social("Medicus", chequeo, tam));
	delete[] chequeo;
}

TEST(chequeoObra_social, chequeoObra_social_MAYUSCULA)
{
	int tam = 6;
	Obra_Social* chequeo = new Obra_Social[tam];
	chequeo[0].obra_soc = "Medicus";
	chequeo[1].obra_soc = " OSDE";
	chequeo[2].obra_soc = "IOSFA";
	chequeo[3].obra_soc = "Italiano";
	chequeo[4].obra_soc = "Aleman";
	chequeo[5].obra_soc = "Espanyol";

	ASSERT_FALSE(chequeoObra_social("MEDICUS", chequeo, tam));
	delete[] chequeo;
}
//bool agregar_paciente(Paciente aux, Paciente*& lista, int* tam);

TEST(agregar_paciente, agregar_paciente_correcto)
{

	Paciente aux;
	aux.DNI = "412345597";
	aux.Apellido = "pepito";
	aux.Estado = "fallecido";
	aux.Nacimiento.tm_year = 1998;
	aux.Nacimiento.tm_mon = 11;
	aux.Nacimiento.tm_mday = 8;
	aux.Nombre = "juan";
	aux.Obra_soc = "OSDE";
	aux.Sexo = 'M';
	int tam = 1;

	Paciente* lista = new Paciente[1];


	ASSERT_TRUE(agregar_paciente(aux, lista ,&tam));
	delete[] lista;
}
TEST(agregar_paciente, agregar_paciente_incorrecto)
{

	Paciente aux;
	aux.DNI = "41235597";
	aux.Apellido = "pepito";
	aux.Estado = "civil";
	aux.Nacimiento.tm_year = 1998;
	aux.Nacimiento.tm_mon = 11;
	aux.Nacimiento.tm_mday = 8;
	aux.Nombre = "juan";
	aux.Obra_soc = "pami";
	aux.Sexo = 'j';
	int tam = 1;
	Paciente* lista = new Paciente[1];
	
	ASSERT_FALSE(agregar_paciente(aux, lista, &tam));
	delete[] lista;
}
TEST(agregar_consulta, agregar_consulta_correcto)
{
	Consulta aux;
	aux.DNI = "42819027";
	aux.Fecha_solicitado.tm_mday = 25;
	aux.Fecha_solicitado.tm_mon = 04;
	aux.Fecha_solicitado.tm_year = 2022;
	aux.Fecha_turno.tm_mday = 18;
	aux.Fecha_turno.tm_mon = 12;
	aux.Fecha_turno.tm_year = 2022;
	Consulta* lista = new Consulta[1];
	int tam = 1;

	ASSERT_TRUE(agregar_consulta(aux, lista, &tam));
	delete[] lista;
}
//int buscarpaciente(string dni, Paciente* lista, int tam);

TEST(buscarpaciente, BUSCARPACIENTE_correcto)
{
	Paciente aux1;
	Paciente aux2;
	Paciente aux3;
	aux1.DNI = "40235559";
	aux1.Apellido = "pepito";
	aux1.Estado = "civil";
	aux1.Nacimiento.tm_year = 1997;
	aux1.Nacimiento.tm_mon = 11;
	aux1.Nacimiento.tm_mday = 8;
	aux1.Nombre = "carlos";
	aux1.Obra_soc = "OSDE";
	aux1.Sexo = 'M';

	aux2.DNI = "44235597";
	aux2.Apellido = "alberto";
	aux2.Estado = "civil";
	aux2.Nacimiento.tm_year = 1948;
	aux2.Nacimiento.tm_mon = 11;
	aux2.Nacimiento.tm_mday = 8;
	aux2.Nombre = "fernanadfes";
	aux2.Obra_soc = "Aleman";
	aux2.Sexo = 'M';

	aux3.DNI = "41235957";
	aux3.Apellido = "pepita";
	aux3.Estado = "civil";
	aux3.Nacimiento.tm_year = 1968;
	aux3.Nacimiento.tm_mon = 12;
	aux3.Nacimiento.tm_mday = 8;
	aux3.Nombre = "perez";
	aux3.Obra_soc = "Aleman";
	aux3.Sexo = 'M';
	int tam = 3;
	Paciente* lista = new Paciente[3];
	lista[0] = aux1;
	lista[1] = aux2;
	lista[2] = aux3;

	ASSERT_THAT(buscarpaciente("41235957", lista, tam), 2);
	delete[] lista;
}
TEST(buscarpaciente, BUSCARPACIENTE_incorrecto)
{
	Paciente aux1;
	Paciente aux2;
	Paciente aux3;
	aux1.DNI = "40235559";
	aux1.Apellido = "pepito";
	aux1.Estado = "civil";
	aux1.Nacimiento.tm_year = 1997;
	aux1.Nacimiento.tm_mon = 11;
	aux1.Nacimiento.tm_mday = 8;
	aux1.Nombre = "carlos";
	aux1.Obra_soc = "OSDE";
	aux1.Sexo = 'M';

	aux2.DNI = "44235597";
	aux2.Apellido = "alberto";
	aux2.Estado = "civil";
	aux2.Nacimiento.tm_year = 1948;
	aux2.Nacimiento.tm_mon = 11;
	aux2.Nacimiento.tm_mday = 8;
	aux2.Nombre = "fernanadfes";
	aux2.Obra_soc = "Aleman";
	aux2.Sexo = 'M';

	aux3.DNI = "41235957";
	aux3.Apellido = "pepita";
	aux3.Estado = "civil";
	aux3.Nacimiento.tm_year = 1968;
	aux3.Nacimiento.tm_mon = 12;
	aux3.Nacimiento.tm_mday = 8;
	aux3.Nombre = "perez";
	aux3.Obra_soc = "Aleman";
	aux3.Sexo = 'M';
	int tam = 3;
	Paciente* lista = new Paciente[3];
	lista[0] = aux1;
	lista[1] = aux2;
	lista[2] = aux3;

	ASSERT_FALSE(buscarpaciente("40502265", lista, tam),-1);
	delete[] lista;
}

//bool Agregar_obrasoc(Obra_Social*& lista, int* tam, Obra_Social dato);
TEST(Agregar_obrasoc, Agregar_obrasoc_correcto)
{

	Obra_Social aux;
	aux.id = 8;
	aux.obra_soc = "pami";
	int tam = 0;
	Obra_Social* lista = new Obra_Social[0];


	ASSERT_TRUE(Agregar_obrasoc(lista, &tam, aux));
	delete[] lista;
}
TEST(Agregar_obrasoc, Agregar_obrasoc_incorrecto)
{

	Obra_Social aux;
	aux.id = 8;
	aux.obra_soc = "pami";
	int tam = 0;
	Obra_Social* lista = new Obra_Social[0];
	lista = NULL;


	ASSERT_FALSE(Agregar_obrasoc(lista, &tam, aux));
	delete[] lista;
}
//string buscartelefono(string dni, Contactos* lista, int tam);
TEST(buscartelefono, buscartelefono_correcto)
{

	Contactos aux1;
	Contactos aux2;
	Contactos* lista = new Contactos[2];
	aux1.Celular = "+41 203 339 0504";
	aux1.Direccion ="callefalse 123";
	aux1.DNI_paciente= "67597385";
	aux1.Mail ="pepito@hotmail.com";
	aux1.Telefono = "+57 722 907 7201";
	aux2.Celular = "+40 203 339 0504";
	aux2.Direccion = "callefalse 123";
	aux2.DNI_paciente = "69597385";
	aux2.Mail = "pepito@hotmail.com";
	aux2.Telefono = "+57 725 906 7201";
	lista[0] = aux1;
	lista[1] = aux2;
	int tam = 2;

	ASSERT_EQ(buscartelefono(aux1.DNI_paciente, lista, tam),"+57 722 907 7201");
	delete[] lista;
}
TEST(buscartelefono, buscartelefono_incorrecto)
{

	Contactos aux1;
	Contactos aux2;
	Contactos* lista = new Contactos[2];
	aux1.Celular = "+41 203 339 0504";
	aux1.Direccion = "callefalse 123";
	aux1.DNI_paciente = "67597385";
	aux1.Mail = "pepito@hotmail.com";
	aux1.Telefono = "+57 722 907 7201";
	aux2.Celular = "+40 203 339 0504";
	aux2.Direccion = "callefalse 123";
	aux2.DNI_paciente = "69597385";
	aux2.Mail = "pepito@hotmail.com";
	aux2.Telefono = "+57 725 906 7201";
	lista[0] = aux1;
	lista[1] = aux2;
	int tam = 2;

	ASSERT_NE(buscartelefono(aux1.DNI_paciente, lista, tam), "+58 721 907 7201");
	delete[] lista;
}
// bool agregar_medico(Medicos aux, Medicos*& lista, int* tam);
TEST(agregar_medico, agregar_medico_incorrecto)
{
	Medicos aux;
	Medicos* lista = new Medicos[0];
	int tam = 0;
	aux.activo = true;
	aux.Apellido= "Grafom";
	aux.especialidad = "farmacologia clinica";
	aux.Matricula = "04 - 723 - 0907";
	aux.Nombre= " Araldo";
	aux.Telefono = "58 721 907 7201"; // porque le galta el +

	ASSERT_FALSE(agregar_medico(aux, lista,&tam));	
	delete[]lista;
}
TEST(agregar_medico, agregar_medico_correcto)
{
	Medicos aux;
	Medicos* lista = new Medicos[0];
	int tam = 0;
	aux.activo = true;
	aux.Apellido = "Grafom";
	aux.especialidad = "farmacologia clinica";
	aux.Matricula = "04 - 723 - 0907";
	aux.Nombre = " Araldo";
	aux.Telefono = "+58 721 907 7201";

	ASSERT_TRUE(agregar_medico(aux, lista, &tam));
	delete []lista;
}
//int buscar_medico(string matricula, Medicos* lista, int tam);

TEST(buscar_medico, buscar_medico_incorrecto)
{
	Medicos aux;
	Medicos* lista = new Medicos[1];
	int tam = 1;
	aux.activo = true;
	aux.Apellido = "Grafom";
	aux.especialidad = "farmacologia clinica";
	aux.Matricula = "04 - 723 - 0907";
	aux.Nombre = " Araldo";
	aux.Telefono = "+58 721 907 7201";
	lista[0] = aux;

	ASSERT_FALSE(buscar_medico("03 - 723 - 0907", lista, tam),-1);
	delete[]lista;
}
TEST(buscar_medico, buscar_medico_correcto)
{
	Medicos aux;
	Medicos* lista = new Medicos[1];
	int tam = 1;
	aux.activo = true;
	aux.Apellido = "Grafom";
	aux.especialidad = "farmacologia clinica";
	aux.Matricula = "04 - 723 - 0907";
	aux.Nombre = " Araldo";
	aux.Telefono = "+58 721 907 7201";
	lista[0] = aux;

	ASSERT_THAT(buscar_medico(aux.Matricula, lista, tam),0);
	delete[]lista;
}
//Consulta consulta_reciente(Consulta* lista, int tam);

TEST(consulta_reciente, consulta_reciente_correcto)
{
	Consulta aux1;
	Consulta aux2;
	Consulta* lista = new Consulta[2];
	int tam = 2;
	aux1.DNI = "86758484";
	aux1.Fecha_solicitado.tm_mday = 01;
	aux1.Fecha_solicitado.tm_mon = 11;
	aux1.Fecha_solicitado.tm_year = 2001;
	aux1.Fecha_turno.tm_mday  = 19;
	aux1.Fecha_turno.tm_mon = 12;
	aux1.Fecha_turno.tm_year = 2001;
	aux1.Matricula_medica = "00 - 334 - 0838";
	aux1.Presento = true;

	aux2.DNI = "86758484";
	aux2.Fecha_solicitado.tm_mday = 02;
	aux2.Fecha_solicitado.tm_mon = 11;
	aux2.Fecha_solicitado.tm_year = 2001;
	aux2.Fecha_turno.tm_mday = 18;
	aux2.Fecha_turno.tm_mon = 8;
	aux2.Fecha_turno.tm_year = 2002;
	aux2.Matricula_medica = "00 - 334 - 0838";
	aux2.Presento = true;
	Consulta n = consulta_reciente(lista, tam);
	ASSERT_THAT(n.Fecha_turno.tm_mday, aux2.Fecha_turno.tm_mday);
	ASSERT_THAT(n.Fecha_turno.tm_mon, aux2.Fecha_turno.tm_mon);
	ASSERT_THAT(n.Fecha_turno.tm_year, aux2.Fecha_turno.tm_year);
	
	delete[]lista;
}
TEST(consulta_reciente, consulta_reciente_incorrecto)
{
	Consulta aux1;
	Consulta aux2;
	Consulta* lista = new Consulta[2];
	int tam = 2;
	aux1.DNI = "86758484";
	aux1.Fecha_solicitado.tm_mday = 01;
	aux1.Fecha_solicitado.tm_mon = 11;
	aux1.Fecha_solicitado.tm_year = 2001;
	aux1.Fecha_turno.tm_mday = 19;
	aux1.Fecha_turno.tm_mon = 12;
	aux1.Fecha_turno.tm_year = 2001;
	aux1.Matricula_medica = "00 - 334 - 0838";
	aux1.Presento = true;

	aux2.DNI = "86758484";
	aux2.Fecha_solicitado.tm_mday = 02;
	aux2.Fecha_solicitado.tm_mon = 11;
	aux2.Fecha_solicitado.tm_year = 2001;
	aux2.Fecha_turno.tm_mday = 18;
	aux2.Fecha_turno.tm_mon = 8;
	aux2.Fecha_turno.tm_year = 2002;
	aux2.Matricula_medica = "00 - 334 - 0838";
	aux2.Presento = true;
	Consulta n = consulta_reciente(lista, tam);
	ASSERT_FALSE(n.Fecha_turno.tm_mday, aux1.Fecha_turno.tm_mday);
	ASSERT_FALSE(n.Fecha_turno.tm_mon, aux1.Fecha_turno.tm_mon);
	ASSERT_FALSE(n.Fecha_turno.tm_year, aux1.Fecha_turno.tm_year);

	delete[]lista;
}
 

TEST(cambiar_os, cambiar_os_correcto) {

	string obra_social;

	ASSERT_TRUE(cambiar_os(&obra_social));


}
TEST(buscar_consultas_pacientes, buscar_consultas_pacientes_correcto) {

	Consulta* lista = new Consulta [2];
	Consulta* sub_lista = new Consulta [0];
	int tam = 2;
	int tam_Sub = 0;
	Consulta aux1;
	Consulta aux2;
	aux1.DNI = "86758484";
	aux1.Fecha_solicitado.tm_mday = 01;
	aux1.Fecha_solicitado.tm_mon = 11;
	aux1.Fecha_solicitado.tm_year = 2001;
	aux1.Fecha_turno.tm_mday = 19;
	aux1.Fecha_turno.tm_mon = 12;
	aux1.Fecha_turno.tm_year = 2001;
	aux1.Matricula_medica = "00 - 334 - 0838";
	aux1.Presento = true;

	aux2.DNI = "87758484";
	aux2.Fecha_solicitado.tm_mday = 02;
	aux2.Fecha_solicitado.tm_mon = 11;
	aux2.Fecha_solicitado.tm_year = 2001;
	aux2.Fecha_turno.tm_mday = 18;
	aux2.Fecha_turno.tm_mon = 8;
	aux2.Fecha_turno.tm_year = 2002;
	aux2.Matricula_medica = "00 - 334 - 0838";
	aux2.Presento = true;


	

	ASSERT_TRUE(buscar_consultas_pacientes(aux1.DNI,lista, tam,&tam_Sub,sub_lista));

	delete[]lista;
    delete[]sub_lista;
}
TEST(buscar_consultas_pacientes, buscar_consultas_pacientes_incorrecto) {

	Consulta* lista = new Consulta[2];
	Consulta* sub_lista = new Consulta[0];
	int tam = 2;
	int tam_Sub = 0;
	Consulta aux1;
	Consulta aux2;
	aux1.DNI = "86758484";
	aux1.Fecha_solicitado.tm_mday = 01;
	aux1.Fecha_solicitado.tm_mon = 11;
	aux1.Fecha_solicitado.tm_year = 2001;
	aux1.Fecha_turno.tm_mday = 19;
	aux1.Fecha_turno.tm_mon = 12;
	aux1.Fecha_turno.tm_year = 2001;
	aux1.Matricula_medica = "00 - 334 - 0838";
	aux1.Presento = true;

	aux2.DNI = "87758484";
	aux2.Fecha_solicitado.tm_mday = 02;
	aux2.Fecha_solicitado.tm_mon = 11;
	aux2.Fecha_solicitado.tm_year = 2001;
	aux2.Fecha_turno.tm_mday = 18;
	aux2.Fecha_turno.tm_mon = 8;
	aux2.Fecha_turno.tm_year = 2002;
	aux2.Matricula_medica = "00 - 334 - 0838";
	aux2.Presento = true;




	ASSERT_TRUE(buscar_consultas_pacientes("89558484", lista, tam, &tam_Sub, sub_lista));

	delete[]lista;
	delete[]sub_lista;
}