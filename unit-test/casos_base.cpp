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