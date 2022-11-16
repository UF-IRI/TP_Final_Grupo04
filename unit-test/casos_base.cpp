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
	int tam = 0;
	Paciente *lista = new Paciente [0];



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
	int tam = 0;
	Paciente* lista = new Paciente[0];



	ASSERT_FALSE(agregar_paciente(aux, lista, &tam));
	delete[] lista;
}
