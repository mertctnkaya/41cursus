#define _POSIX_C_SOURCE 201701L
#include <signal.h>
#include <unistd.h>

void signal_handler(int sig)
{
	static unsigned char c = 0;
	static int bit_index = 0;

	c <<= 1; // sola kaydır, boş bit aç
	if (sig == SIGUSR1)
	{
		c |= 1; // son bitten 1 yap
	}
	bit_index++;

	if (bit_index == 8)
	{
		write(1, &c, 1); // karakter tamamlandı, yaz
		c = 0;			 // sıfırla
		bit_index = 0;
	}
}
#include <stdio.h>
int main(void)
{
	struct sigaction sa;

	sa.sa_handler = signal_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART; // Sinyal işleyicisi sistem çağrılarını yeniden başlatabilir
	// SA_RESTART bayrağı, sinyal işleyicisi çağrıldığında
	// kesilen sistem çağrılarını otomatik olarak yeniden başlatır.
	sa.sa_flags |= SA_SIGINFO; // Gelişmiş sinyal bilgisi kullan

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	printf("PID: %d\n", getpid());
	while (1)
		pause(); // sinyal bekle
}