#include "gmock/gmock.h"
#include "funciones.h"
namespace foobar::tests {
	TEST(ExampleTests, Example) {
        ASSERT_THAT(1, 1);
	}
}
TEST(leer_pacientes, abrir_paciente)
{
	int tam = 0;
	Paciente* lista=new Paciente[0];
	bool valor=leer_pacientes("C:/Users/Electro PC/Desktop/facultad/Redes e Internet/Final 2022/final/data_files/input/Pacientes.csv", lista,&tam);
	ASSERT_TRUE(valor);
	delete[]lista;
}

TEST(leer_Consultas, abrir_consulta)
{
	int tam = 0;
	Consulta* lista = new Consulta[0];
	bool valor = leer_Consultas("C:/Users/Electro PC/Desktop/facultad/Redes e Internet/Final 2022/final/data_files/input/Consultas.csv", lista, &tam);
	ASSERT_TRUE(valor);
	delete[]lista;
}
TEST(Leer_Contacto, abrir_contacto)
{
	int tam = 0;
	Contactos* lista = new Contactos[0];
	bool valor = Leer_Contacto("C:/Users/Electro PC/Desktop/facultad/Redes e Internet/Final 2022/final/data_files/input/Contactos.csv", lista, &tam);
	ASSERT_TRUE(valor);
	delete[]lista;
}

TEST(leer_medicos, abrir_medico)
{
	int tam = 0;
	Medicos* lista = new Medicos[0];
	bool valor = leer_medicos("C:/Users/Electro PC/Desktop/facultad/Redes e Internet/Final 2022/final/data_files/input/Medicos.csv", lista, &tam);
	ASSERT_TRUE(valor);
	delete[]lista;
}

TEST(Ordenar_Paciente,ordenar)
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
	ASSERT_TRUE(Ordenar_Paciente(lista,tam));
	delete[]lista;
}
