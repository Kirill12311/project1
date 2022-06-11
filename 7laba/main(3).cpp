
#include "mbed.h" //Заголовочный файл для работы с Mbed
#include "mbedtls/sha256.h" //Заголовочный файл для работы с SHA-256
#include "mbedtls/platform.h" //Заголовочный файл для работы с функцией //вывода отладочной информации mbedtls_printf
#include <string.h> //Заголовочный файл для работы со строками
static const char hello_str[] = "Vodyankin_Kirill_748_Amletova_Elena_748"; //массив символов
static const unsigned char *hello_buffer = (const unsigned char *) hello_str; //указатель на массив символов
static const size_t hello_len = strlen(hello_str); //длинна массива //символов
static void print_hex(const unsigned char buf[], size_t len)
{
for (size_t i = 0; i < len; i++) {
if (buf[i] <= 0xF) {
mbedtls_printf("0%x", buf[i]);
} else {
mbedtls_printf("%x", buf[i]);
}
}
mbedtls_printf("\n");
}
int main() {
int exit_code = MBEDTLS_EXIT_FAILURE;
//Платформо-зависимая операция инициализации MbedTLS
if((exit_code = mbedtls_platform_setup(NULL)) != 0) {
printf("Platform initialization failed with error %d\n\n",
exit_code);
return MBEDTLS_EXIT_FAILURE;
}
mbedtls_aes_context ctx; //Контест, содержащий информацию о ключе
mbedtls_aes_init(&ctx);
static const char key[] = "secret key!qwert"; //Секретный ключи
static const char data[] = "Vodyankin_Kirill_748_Amletova_Elena_748" //Данные для шифрования
"\x10\x10\x10\x10"
"\x10\x10\x10\x10"
"\x10\x10\x10\x10"
"\x10\x10\x10\x10";
unsigned char data_encrypted[32]; //
unsigned char iv[16] = {'0', '0', '0', '0', //Вектор инициализации
'0', '0', '0', '0',
'0', '0', '0', '0',
'0', '0', '0', '0'};
exit_code = MBEDTLS_EXIT_FAILURE;
//Добавление 128-ми битного ключа в контекст
if ((exit_code = mbedtls_aes_setkey_enc(&ctx, (unsigned const char
*)key, 128)) != 0)
{
printf("Can\'t init aes encryption - error %d\n", exit_code);
return MBEDTLS_EXIT_FAILURE;
}
exit_code = MBEDTLS_EXIT_FAILURE;
//Шифрование строки data длиной 32 в data_encrypted
if ((exit_code = mbedtls_aes_crypt_cbc(&ctx, MBEDTLS_AES_ENCRYPT, 32,
iv, (unsigned const char *)data, data_encrypted)) != 0)
{
printf("Can\'t encrypt by aes cbc - error %d\n", exit_code);
return MBEDTLS_EXIT_FAILURE;
}
printf("Plaintext:\"%s\"\nCiphertext:", data); //Вывод текста
print_hex(data_encrypted, sizeof data_encrypted); //Вывод зашифрованных данных
mbedtls_aes_free(&ctx); //Освобождение контекста
//Отключение микроконтроллера
mbedtls_platform_teardown(NULL);
}
