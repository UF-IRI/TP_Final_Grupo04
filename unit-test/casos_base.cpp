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

TEST(redimensionarp, redimensionarp_CORRECTO)
{
	Paciente* lista = new Paciente[1];
	int tam = 1;
	int cant_aumentar = 1;

	ASSERT_TRUE(redimensionarp(lista,&tam,cant_aumentar));
	delete[] lista;
}

TEST(redimensionar_medicos, redimensionar_medicos_CORRECTO)
{
	Medicos* lista = new Medicos[0];
	int tam = 0;
	int cant_aumentar = 1;


	ASSERT_TRUE(redimensionar_medicos(lista,cant_aumentar, &tam));
	delete[] lista;
}
TEST(Redimensionar_Consultas, Redimensionar_Consultas_CORRECTO)
{
	Consulta* lista = new Consulta[0];
	int tam = 0;
	ASSERT_TRUE(Redimensionar_Consultas(lista, tam));
	delete[] lista;
}

////chequeo dni
TEST(chequear_DNI,DNI_letras)
{
	ASSERT_FALSE(chequear_DNI("4395815l"));
}
TEST(chequear_DNI, DNI_simbolos)
{
	ASSERT_FALSE(chequear_DNI("4395/81%"));
}
TEST(chequear_DNI, DNI_espacios)
{
	ASSERT_FALSE(chequear_DNI("4395 822"));
}
TEST(chequear_DNI, DNI_comun)
{
	ASSERT_TRUE(chequear_DNI("43958124"));
}
////bool chequeo_AyN(string AyN)
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
//////bool chequeo_Mail(string mail);
TEST(chequeo_Mail, mail_sin_punto)
{	ASSERT_FALSE(chequeo_Mail("favaloroalumnos@gmailcom"));

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
////bool chequeargenero(char letra);
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
////bool chequeo_direccion(string direc);
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
{	ASSERT_TRUE(chequeo_direccion("centro asturiano"));
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
	ASSERT_TRUE(chequeo_celular("+54(801)04193744"));
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
	ASSERT_TRUE(chequeo_especialidades("medico_Clinico"));
}
TEST(chequeo_especialidades, especialidad_minuscula)
{
	ASSERT_TRUE(chequeo_especialidades("medico_pediatra"));
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
// //bool chequeo_estado(string estado);
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

////bool agregar_paciente(Paciente aux, Paciente*& lista, int* tam);

TEST(agregar_paciente, agregar_paciente_correcto)
{
	Paciente aux;
	aux.DNI = "41234597";
	aux.Apellido = "pepito";
    aux.Estado = "fallecido";
	aux.Nacimiento.tm_year = 1998;
	aux.Nacimiento.tm_mon = 11;
	aux.Nacimiento.tm_mday = 8;
	aux.Nombre = "juan";
	aux.Obra_soc = "OSDE";
	aux.Sexo = 'M';
	int tam = 0;
	Paciente* lista = new Paciente[0];
    ASSERT_TRUE(agregar_paciente(aux, lista ,&tam));
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
	int tam = 0;

	ASSERT_TRUE(agregar_consulta(aux, lista, &tam));
delete[] lista;
}

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
	ASSERT_FALSE(buscarpaciente("40502265", lista, tam), -1);
	delete[] lista;
}

TEST(buscartelefono, buscartelefono_correcto)
{

	Contactos aux1;	Contactos aux2;
	Contactos* lista = new Contactos[2];
	aux1.Celular = "+54(801)04193744";
	aux1.Direccion ="callefalse 123";
	aux1.DNI_paciente= "67597385";
	aux1.Mail ="pepito@hotmail.com";
	aux1.Telefono = "+54(426)84659920";
	aux2.Celular = "+54(316)12652502";
	aux2.Direccion = "calle 125";
	aux2.DNI_paciente = "69597385";
	aux2.Mail = "pepito@hotmail.com";
	aux2.Telefono = "+54(176)68420326";
	lista[0] = aux1;
	lista[1] = aux2;
	int tam = 2;
	ASSERT_EQ(buscartelefono(aux1.DNI_paciente, lista, tam),"+54(426)84659920");
	delete[] lista;
}
TEST(buscartelefono, buscartelefono_incorrecto)
{

	Contactos aux1;
	Contactos aux2;
	Contactos* lista = new Contactos[2];	
	aux1.Celular = "+54(801)04193744";
	aux1.Direccion = "callefalse 123";
	aux1.DNI_paciente = "67597385";
	aux1.Mail = "pepito@hotmail.com";
	aux1.Telefono = "+54(426)84659920";
	aux2.Celular = "+54(316)12652502";
	aux2.Direccion = "callefalse 123";
	aux2.DNI_paciente = "69597385";
	aux2.Mail = "pepito@hotmail.com";
	aux2.Telefono = "+54(176)68420326";
	lista[0] = aux1;
	lista[1] = aux2;
	int tam = 2;

	ASSERT_NE(buscartelefono(aux1.DNI_paciente, lista, tam), "+54(176)68420326");
	delete[] lista;
}
TEST(agregar_medico, agregar_medico_correcto)
{
	Medicos aux;
	Medicos* lista = new Medicos[0];
	int tam = 0;
	aux.activo = true;
	aux.Apellido = "Grafom";
	aux.especialidad = "farmacologia_clinica";
	aux.Matricula = "03-957-5455";
	aux.Nombre = " Araldo";
	aux.Telefono = "+54(929)89112253";

	ASSERT_TRUE(agregar_medico(aux, lista, &tam));
	delete []lista;
}
TEST(buscar_medico, buscar_medico_correcto)
{
	Medicos aux;
	Medicos* lista = new Medicos[1];
	int tam = 1;
	aux.activo = true;
   aux.Apellido = "Grafom";
	aux.especialidad = "farmacologia_clinica";
	aux.Matricula = "03-957-5455";
	aux.Nombre = " Araldo";
	aux.Telefono = "+54(929)89112253";
	lista[0] = aux;
	ASSERT_THAT(buscar_medico(aux.Matricula, lista, tam),0);
	delete[]lista;
}
//TEST(consulta_reciente, consulta_reciente_correcto)
//{
//	Consulta aux1;
//	Consulta aux2;
//	Consulta* lista = new Consulta[2];
//	int tam = 2;
//	aux1.DNI = "86758484";
//	aux1.Fecha_solicitado.tm_mday = 01;
//	aux1.Fecha_solicitado.tm_mon = 11;
//	aux1.Fecha_solicitado.tm_year = 2001;
//	aux1.Fecha_turno.tm_mday  = 19;
//	aux1.Fecha_turno.tm_mon = 12;
//	aux1.Fecha_turno.tm_year = 2001;
//	aux1.Matricula_medica = "00 - 334 - 0838";
//	aux1.Presento = true;
//
//	aux2.DNI = "86758484";
//	aux2.Fecha_solicitado.tm_mday = 02;
//	aux2.Fecha_solicitado.tm_mon = 11;
//	aux2.Fecha_solicitado.tm_year = 2001;
//	aux2.Fecha_turno.tm_mday = 18;
//	aux2.Fecha_turno.tm_mon = 8;
//	aux2.Fecha_turno.tm_year = 2002;
//	aux2.Matricula_medica = "00 - 334 - 0838";
//	aux2.Presento = true;
//	Consulta n = consulta_reciente(lista, tam);
//	ASSERT_THAT(n.Fecha_turno.tm_mday, aux2.Fecha_turno.tm_mday);
//	ASSERT_THAT(n.Fecha_turno.tm_mon, aux2.Fecha_turno.tm_mon);
//	ASSERT_THAT(n.Fecha_turno.tm_year, aux2.Fecha_turno.tm_year);
//	
//	delete[]lista;
//}
//TEST(consulta_reciente, consulta_reciente_incorrecto)
//{
//	Consulta aux1;
//	Consulta aux2;
//	Consulta* lista = new Consulta[2];
//	int tam = 2;
//	aux1.DNI = "86758484";
//	aux1.Fecha_solicitado.tm_mday = 01;
//	aux1.Fecha_solicitado.tm_mon = 11;
//	aux1.Fecha_solicitado.tm_year = 2001;
//	aux1.Fecha_turno.tm_mday = 19;
//	aux1.Fecha_turno.tm_mon = 12;
//	aux1.Fecha_turno.tm_year = 2001;
//	aux1.Matricula_medica = "00 - 334 - 0838";
//	aux1.Presento = true;
//
//	aux2.DNI = "86758484";
//	aux2.Fecha_solicitado.tm_mday = 02;
//	aux2.Fecha_solicitado.tm_mon = 11;
//	aux2.Fecha_solicitado.tm_year = 2001;
//	aux2.Fecha_turno.tm_mday = 18;
//	aux2.Fecha_turno.tm_mon = 8;
//	aux2.Fecha_turno.tm_year = 2002;
//	aux2.Matricula_medica = "00 - 334 - 0838";
//	aux2.Presento = true;
//	Consulta n = consulta_reciente(lista, tam);
//	ASSERT_FALSE(n.Fecha_turno.tm_mday, aux1.Fecha_turno.tm_mday);
//	ASSERT_FALSE(n.Fecha_turno.tm_mon, aux1.Fecha_turno.tm_mon);
//	ASSERT_FALSE(n.Fecha_turno.tm_year, aux1.Fecha_turno.tm_year);
//
//	delete[]lista;
//}
// 
//
//TEST(cambiar_os, cambiar_os_correcto) {
//
//	string obra_social;
//
//	ASSERT_TRUE(cambiar_os(&obra_social));
//
//
//}
//TEST(buscar_consultas_pacientes, buscar_consultas_pacientes_correcto) {
//
//	Consulta* lista = new Consulta [2];
//	Consulta* sub_lista = new Consulta [0];
//	int tam = 2;
//	int tam_Sub = 0;
//	Consulta aux1;
//	Consulta aux2;
//	aux1.DNI = "86758484";
//	aux1.Fecha_solicitado.tm_mday = 01;
//	aux1.Fecha_solicitado.tm_mon = 11;
//	aux1.Fecha_solicitado.tm_year = 2001;
//	aux1.Fecha_turno.tm_mday = 19;
//	aux1.Fecha_turno.tm_mon = 12;
//	aux1.Fecha_turno.tm_year = 2001;
//	aux1.Matricula_medica = "00 - 334 - 0838";
//	aux1.Presento = true;
//
//	aux2.DNI = "87758484";
//	aux2.Fecha_solicitado.tm_mday = 02;
//	aux2.Fecha_solicitado.tm_mon = 11;
//	aux2.Fecha_solicitado.tm_year = 2001;
//	aux2.Fecha_turno.tm_mday = 18;
//	aux2.Fecha_turno.tm_mon = 8;
//	aux2.Fecha_turno.tm_year = 2002;
//	aux2.Matricula_medica = "00 - 334 - 0838";
//	aux2.Presento = true;
//
//
//	
//
//	ASSERT_TRUE(buscar_consultas_pacientes(aux1.DNI,lista, tam,&tam_Sub,sub_lista));
//
//	delete[]lista;
//    delete[]sub_lista;
//}
//TEST(buscar_consultas_pacientes, buscar_consultas_pacientes_incorrecto) {
//
//	Consulta* lista = new Consulta[2];
//	Consulta* sub_lista = new Consulta[0];
//	int tam = 2;
//	int tam_Sub = 0;
//	Consulta aux1;
//	Consulta aux2;
//	aux1.DNI = "86758484";
//	aux1.Fecha_solicitado.tm_mday = 01;
//	aux1.Fecha_solicitado.tm_mon = 11;
//	aux1.Fecha_solicitado.tm_year = 2001;
//	aux1.Fecha_turno.tm_mday = 19;
//	aux1.Fecha_turno.tm_mon = 12;
//	aux1.Fecha_turno.tm_year = 2001;
//	aux1.Matricula_medica = "00 - 334 - 0838";
//	aux1.Presento = true;
//
//	aux2.DNI = "87758484";
//	aux2.Fecha_solicitado.tm_mday = 02;
//	aux2.Fecha_solicitado.tm_mon = 11;
//	aux2.Fecha_solicitado.tm_year = 2001;
//	aux2.Fecha_turno.tm_mday = 18;
//	aux2.Fecha_turno.tm_mon = 8;
//	aux2.Fecha_turno.tm_year = 2002;
//	aux2.Matricula_medica = "00 - 334 - 0838";
//	aux2.Presento = true;
//
//
//
//
//	ASSERT_TRUE(buscar_consultas_pacientes("89558484", lista, tam, &tam_Sub, sub_lista));
//
//	delete[]lista;
//	delete[]sub_lista;
//}