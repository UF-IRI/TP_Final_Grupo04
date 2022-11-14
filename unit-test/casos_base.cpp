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
