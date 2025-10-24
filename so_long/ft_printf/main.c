#include "ft_printf.h"

/**
 * 
 * va_start(ap, last_arg);:
 * Bu makro, ap (yani va_list değişkeniniz) içine, yığında last_arg'dan sonra gelen ilk variadic argümanın adresini yazar.
 * Assembly seviyesinde, last_arg'ın yığındaki adresini (genellikle EBP + ofset) alır ve üzerine last_arg'ın boyutunu ekleyerek ilk variadic argümanın adresine ulaşır.
 * Bu ofset, last_arg'ın kendisinin yığındaki konumu ve boyutu bilindiği için hesaplanabilir.

 * va_arg(ap, type);:
 * Bu makro, ap'nin şu anda işaret ettiği adresten, belirtilen type boyutunda veri okur.
 * Assembly seviyesinde:
 * ap'nin tuttuğu adresi alır.
 * Bu adresten sizeof(type) kadar bayt okur (veya tür yükseltmeleri nedeniyle daha büyük bir boyut, örneğin char ve short genellikle int olarak alınır).
 * ap'yi, okuduğu type'ın boyutunu bir sonraki argümanın başlangıcına işaret edecek şekilde artırır. (Yani ap = ap + sizeof(type); gibi basit bir ifade değil, çünkü mimarinin gerektirdiği hizalama kuralları da devreye girer.)
 * 
 * Hangi Parametreyi Alacağını Nereden Biliyor?

 * va_arg(ap, type) hangi parametreyi alacağını bilmez.
 * Sadece ap'nin şu an işaret ettiği yerden, senin belirttiğin type kadar bayt okur ve ap'yi ileri taşır.
 * Doğru parametreyi almak senin sorumluluğundadır.
 * Yani, printf format stringini parse ederek (%d gördüğünde int alması gerektiğini bilir)
 * va_arg'ı doğru type ile çağırmak zorundadır.
 * Yanlış tip belirtirsen, sonuç tanımsız davranış olur (yanlış sayıda bayt okur, yanlış yorumlar).
 * 
 * Linux x64'te (System V AMD64 ABI):

 * İlk 6 tam sayı veya pointer parametresi RDI, RSI, RDX, RCX, R8, R9 kaydedicilerine atanır.

 * İlk 8 kayan nokta parametresi XMM0 - XMM7 kaydedicilerine atanır.

 * Eğer daha fazla parametre varsa, bunlar yığına itilir.
 
 * reg_save_area: Bu, kaydedicilere atanmış ilk birkaç argümanın yedek kopyalarının tutulduğu bir bellek alanıdır. va_start bu alanı işaret eder.

 * gp_offset: Genel amaçlı kaydedicilerden (RDI, RSI vb.) kaç bayt ileride olduğunuzu tutar. va_arg her bir tam sayı/pointer argümanı aldığında bu ofseti günceller.

 * fp_offset: Kayan nokta kaydedicilerinden (XMM0 vb.) kaç bayt ileride olduğunuzu tutar. va_arg her bir kayan nokta argümanı aldığında bu ofseti günceller.

 * overflow_arg_area: Eğer parametreler kaydedicilere sığmaz ve yığına taşarsa, bu alan yığındaki taşan argümanların başlangıcını işaret eder.
 * 
// Örnek: Linux x64 ABI için
typedef struct
{
    unsigned int gp_offset;      // Offset for general purpose registers (RDI, RSI, RDX, RCX, R8, R9)
    unsigned int fp_offset;      // Offset for floating point registers (XMM0-7)
    void         *overflow_arg_area; // Pointer to the stack area for arguments that overflowed registers
    void         *reg_save_area; // Pointer to where the initial register arguments are saved on the stack
} va_list[1]; // va_list'in kendisi genellikle bir dizi (array of 1 element) olarak tanımlanır,
              // bu da onu bir pointer gibi davranmasını sağlar.
*/

int main(void)
{
	ft_printf("char: %c\n", 'A');                 // normal harf
ft_printf("null char: %c\n", '\0');           // null karakter (yazılamaz ama sayılır)
ft_printf("non-printable: %c\n", 7);          // '\a' gibi ascii
ft_printf("int cast: %c\n", 65);              // 'A'

ft_printf("str: %s\n", "hello world");
ft_printf("empty str: %s\n", "");             // boş string
ft_printf("NULL str: %s\n", NULL);            // null string — yazılımın çökmemeli, "(null)" yazman önerilir

int x = 42;
ft_printf("pointer: %p\n", &x);               // geçerli adres
ft_printf("null pointer: %p\n", NULL);        // NULL adres (0x0 olmalı)

ft_printf("pos: %d\n", 1234);
ft_printf("neg: %d\n", -1234);
ft_printf("zero: %d\n", 0);
ft_printf("INT_MAX: %d\n", 2147483647);       // INT_MAX
ft_printf("INT_MIN: %d\n", -2147483648);      // INT_MIN

ft_printf("unsigned: %u\n", 1234U);
ft_printf("zero: %u\n", 0U);
ft_printf("overflow: %u\n", -1);              // should print 4294967295 (unsigned wrap)

ft_printf("hex lower: %x\n", 3735928559U);    // 0xDEADBEEF
ft_printf("hex upper: %X\n", 3735928559U);
ft_printf("zero: %x\n", 0);
ft_printf("INT_MIN: %x\n", -2147483648);      // unsigned cast

ft_printf("just percent: %%\n");              // %
ft_printf("double percent: %%%%!\n");         // %%!

ft_printf("\n");                                // boş format
ft_printf("%\n");                               // sadece yüzde → UB olmasın
ft_printf("%%\n");                              // geçerli
ft_printf("%c %s %% %d\n", 'x', "y", 42);     // karışık format

ft_printf("bad: %d\n");                       // eksik argüman → segfault olabilir
ft_printf("bad: %d %d\n", 42);                // eksik argüman
ft_printf("too many: %d\n", 42, 43);          // fazla argüman
// ft_printf("wrong type: %s\n", 12345);         // int yerine string istiyor → UB

int ret = ft_printf("hello world\n");
printf("printed chars: %d\n", ret);           // 12 beklenir

// Sızıntı olmaması için şunları test et:
// for (int i = 0; i < 1000; ++i)
// 	ft_printf("loop %d: %d\n", i, i);

ft_printf("%s%c%i%d%u%x%X%%\n", "str", 'A', -42, 42, 4294967295U, 255, 255);
// strA-4242424294967295ffFF%

ft_printf("%p %p %p\n", NULL, (void *)1234, &ft_printf);
// pointer, null, function addr
}