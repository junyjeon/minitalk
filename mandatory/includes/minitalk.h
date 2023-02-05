/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 22:12:46 by junyojeo          #+#    #+#             */
/*   Updated: 2023/02/05 07:47:15 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h> //kill, sigemptyset, sigaddset, sigaction
# include <unistd.h>

pid_t getpid(void);

unsigned int sleep(unsigned int seconds); // 설정된 만큼 대기 (초 단위)
int usleep(useconds_t microseconds);	  // 설정된 만큼 대기 (마이크로초 단위)
int pause(void);						  // 시그널이 올 때 까지 대기

int kill(pid_t pid, int sig); // 지정된 프로세스로 지정된 시그널 전송

int			sigemptyset(sigset_t *set);						// 시그널 집합에서 모든 시그널 제거 
int			sigaddset(sigset_t *set, int signo);	// 시그널 집합에서 특정 시그널 추가

typedef void	(*sig_t)(int);
void			(*signal(int sig, void (*func)(int)))(int);
sig_t			signal(int sig, sig_t func);

int			sigaction(int sig, const struct siaction *restrict act, \		// 새로운 시그널 정보 등록
			struct sigaction *restric oact);					// 기존의 시그널 정보 백업

typedef struct	s_data
{
	int	*bit;
	int	cnt;
}		t_data;

typedef int __sig_atomic_t;
typedef __sig_atomic_t sig_atomic_t;

struct  sigaction {
    union __sigaction_u __sigaction_u; /* signal handler */
    sigset_t sa_mask;                  /* signal mask to apply */
    int     sa_flags;                  /* see signal options below */
};

union __sigaction_u {
    void    (*__sa_handler)(int);
    void    (*__sa_sigaction)(int, siginfo_t *, void *);
};

#define sa_handler      __sigaction_u.__sa_handler
#define sa_sigaction    __sigaction_u.__sa_sigaction

int	sigaction(int sig, const struct sigaction *restrict act, struct sigaction *restrict oact);

void ft_handler(int sig, siginfo_t *info, void *ucontext) { ... }

siginfo_t {
		int      si_signo;     /* 시그널 번호*/
		int      si_errno;     /* 시그널 관련 오류번호 */
		int      si_code;      /* 시그널 발생 원인을 정의하는 코드 */
		int      si_trapno;    /* Trap number that caused hardware-generated signal
                             (unused on most architectures) */
		pid_t    si_pid;       /* Sending process ID */
		uid_t    si_uid;       /* Real user ID of sending process */
		int      si_status;    /* Exit value or signal */
		clock_t  si_utime;     /* User time consumed */
		clock_t  si_stime;     /* System time consumed */
		sigval_t si_value;     /* Signal value */
		int      si_int;       /* POSIX.1b signal */
		void    *si_ptr;       /* POSIX.1b signal */
		int      si_overrun;   /* Timer overrun count; POSIX.1b timers */
		int      si_timerid;   /* Timer ID; POSIX.1b timers */
		void    *si_addr;      /* Memory location which caused fault */
		long     si_band;      /* Band event (was int in glibc 2.3.2 and earlier) */
		int      si_fd;        /* File descriptor */
		short    si_addr_lsb;  /* Least significant bit of address (since Linux 2.6.32) */
		void    *si_lower;     /* Lower bound when address violation occurred (since Linux 3.19) */
		void    *si_upper;     /* Upper bound when address violation occurred (since Linux 3.19) */
		int      si_pkey;      /* Protection key on PTE that caused fault (since Linux 4.6) */
		void    *si_call_addr; /* Address of system call instruction (since Linux 3.5) */
		int      si_syscall;   /* Number of attempted system call (since Linux 3.5) */
		unsigned int si_arch;  /* Architecture of attempted system call (since Linux 3.5) */
}

// act : 시그널 발생 시 처리해주기위한 설정 값들이 존재하는 sigaction 구조체
// oldact : 이전에 등록되었던 sigaction 구조체 (필요하지않다면 NULL 또는 0)

#endif
