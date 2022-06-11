#include "mbed.h" //Заголовочный файл для работы с Mbed
#include "mbedtls/sha256.h" //Заголовочный файл для работы с SHA-256
#include "mbedtls/platform.h" //Заголовочный файл для работы с функцией //вывода отладочной информации mbedtls_printf
#include <string.h> //Заголовочный файл для работы со строками

static const char hello_str[] = "Vodyankin_Kirill_748_Amletova_Elena_748"; //массив символов
static const unsigned char *hello_buffer = (const unsigned char *)
hello_str; //указатель на массив символов
static const size_t hello_len = strlen(hello_str); //длинна массива
//символов

static void print_hex(const unsigned char buf[], size_t len)
{
    for (size_t i = 0; i < len; i++) 
    {
        if (buf[i] <= 0xF) 
        {
            mbedtls_printf("0%x", buf[i]);
        } 
        else 
        {
            mbedtls_printf("%x", buf[i]);
        }
    }
    mbedtls_printf("\n");
}

// main() runs in its own thread in the OS
int main() 
{
    int exit_code = MBEDTLS_EXIT_FAILURE; //Платформо-зависимая операция инициализации MbedTLS
    if((exit_code = mbedtls_platform_setup(NULL)) != 0) 
    {
        printf("Platform initialization failed with error %d\n\n",exit_code);
        return MBEDTLS_EXIT_FAILURE;
    }
    unsigned char hash_output[32]; //Буфер для сохранения хеша
    mbedtls_sha256(hello_buffer, hello_len, hash_output, 0); //Вычисление //хеша переменной hello_buffer длиной hello_len в переменную hash_output
    mbedtls_printf("Text:\"%s\"\nHash:\"", hello_str); //Вывод строки с исходным текстом
    print_hex(hash_output, sizeof hash_output); //Вывод хеша
}

