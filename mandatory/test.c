#include <stdio.h>
#include <unistd.h>
#include <signal.h>

struct two_words { int a, b, c; } memory;

void handler(int signum) { printf ("%d %d %d\n", memory.a, memory.b, memory.c); }

int main (void)
{
	pid_t	pid;

	if (argc)
	static struct two_words zeros = {0, 0, 0}, ones = {1, 1, 1};
	signal(SIGUSR1, handler);
	memory = zeros;
	printf("pid : %d\n", getpid());
	while (1)
	{
		memory = zeros;
		memory = ones;
	}
	return (0);
}

//볼레틸
//valatile
//혼자서 돌 수 없는 던전?을 만드는 것. 2인 이상?. 이럴경우 투컴으로 돌리는것 고려해보기.
