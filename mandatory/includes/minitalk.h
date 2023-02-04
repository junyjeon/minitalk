/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 22:12:46 by junyojeo          #+#    #+#             */
/*   Updated: 2023/02/05 02:41:48 by junyojeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <sys/types.h>
# include <uni.h>

void handler(int signo, siginfo_t *siginfo, ucontext_t *context);

// signo : 시그널 핸들러를 호출할 시그널
// siginfo : 시그널이 발생한 원인을 담은 siginfo_t 구조체 포인터
// context : 시그널이 전달될 때 시그널을 받는 프로세스의 내부 상태를 담은 ucontext_t 구조체 포인터

void (*sa_handler)(int);
void (*sa_sigaction)(int, siginfo_t *, void *);

siginfo_t {
	int      si_signo;  /* 시그널 넘버 */
	int      si_errno;  /* errno 값 */
	int      si_code;   /* 시그널 코드 */
	pid_t    si_pid;    /* 프로세스 ID 보내기 */
	uid_t    si_uid;    /* 프로세스를 전송하는 실제 사용자 ID */
	int      si_status; /* Exit 값 또는 시그널 */
	clock_t  si_utime;  /* 소모된 사용자 시간 */
	clock_t  si_stime;  /* 소모된 시스템 시간 */
	sigval_t si_value;  /* 시그널 값 */
	int      si_int;    /* POSIX.1b 시그널 */
	void *   si_ptr;    /* POSIX.1b 시그널 */
	void *   si_addr;   /* 실패를 초래한 메모리 위치 */
	int      si_band;   /* 밴드 이벤트 */
	int      si_fd;     /* 파일 기술자 */
}

typedef struct s_sigaction
{
	int sa_flags;
	int	sa_mask;
}		t_sigaction

struct sigaction	g_server_act;
struct sigaction	g_client_act;

typedef struct s_data
{
	pid_t	pid;
	char	*msg;
}		t_data;

// Server Handler


#endif
