<div align="center">
  <h1>📡 minitalk</h1>
  <p>UNIX Signal 기반 클라이언트-서버 통신 프로그램</p>

  <img src="assets/minitalk_review.jpg" alt="Minitalk" width="800"/>
  
  <div>
    <img src="https://img.shields.io/badge/Score-125%2F100-success?style=flat-square&logo=42" alt="42 Score"/>
    <img src="https://img.shields.io/badge/Norminette-passing-brightgreen?style=flat-square" alt="Norminette"/>
    <img src="https://img.shields.io/badge/Language-C-00599C?style=flat-square&logo=c" alt="Language"/>
    <img src="https://img.shields.io/badge/Signal-UNIX-FCC624?style=flat-square&logo=linux" alt="Signal"/>
  </div>

  ### 주요 기능
  - UNIX 시그널을 통한 프로세스 간 통신
  - 비트 단위 문자열 전송
  - 서버-클라이언트 양방향 통신
  - 유니코드 문자 지원

  ### 사용 기술
  - UNIX 시그널 (SIGUSR1, SIGUSR2)
  - 비트 연산
  - 프로세스 관리
  - 시그널 핸들링
</div>
```

## 🚀 Quick Start
```bash
# 1. 저장소 클론
git clone https://github.com/username/minitalk.git && cd minitalk

# 2. 컴파일
make

# 3. 서버 실행 (새 터미널)
./server
# Server PID: 12345

# 4. 클라이언트로 메시지 전송 (다른 터미널)
./client 12345 "Hello, World!"
```

## 📋 목차
1. [프로젝트 소개](#-프로젝트-소개)
2. [필수 요구사항](#-필수-요구사항)
3. [설치 및 실행](#-설치-및-실행)
4. [구현 가이드](#-구현-가이드)
5. [시그널 처리](#-시그널-처리)
6. [보너스 기능](#-보너스-기능)
7. [트러블슈팅](#-트러블슈팅)
8. [테스트 케이스](#-테스트-케이스)
9. [디버깅 가이드](#-디버깅-가이드)
10. [참고 자료](#-참고-자료)

## 🎯 프로젝트 소개
minitalk은 UNIX 시그널을 사용하여 두 프로그램(클라이언트와 서버) 간에 데이터를 교환하는 프로젝트입니다. SIGUSR1과 SIGUSR2 시그널만을 사용하여 문자열을 전송합니다.

## 📃 필수 요구사항

### 1. 프로그램 규칙
- 서버와 클라이언트 프로그램 구현
- SIGUSR1, SIGUSR2 시그널만 사용
- 문자열 데이터 전송
- 에러 처리 및 안정성 확보

### 2. 서버
```c
// 서버 실행 예시
$> ./server
PID: 4295
```

- 실행 시 PID 출력
- 문자열 수신 후 출력
- 안정적으로 실행되어야 함

### 3. 클라이언트
```c
// 클라이언트 실행 예시
$> ./client 4295 "Hello World!"
```

- 서버 PID와 전송할 문자열을 인자로 받음
- 문자열을 서버로 전송
- 전송 완료 확인

## 🔨 설치 및 실행

### 1. 컴파일
```makefile
NAME		= server client
SERVER		= server
CLIENT		= client
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

LIBFT		= libft
LIBFT_LIB	= libft.a

SRCS_SERVER	= server.c
SRCS_CLIENT	= client.c
OBJS_SERVER	= $(SRCS_SERVER:.c=.o)
OBJS_CLIENT	= $(SRCS_CLIENT:.c=.o)

all: $(NAME)

$(SERVER): $(OBJS_SERVER)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) -o $(SERVER) $(OBJS_SERVER) -L$(LIBFT) -lft

$(CLIENT): $(OBJS_CLIENT)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) -o $(CLIENT) $(OBJS_CLIENT) -L$(LIBFT) -lft

clean:
	make -C $(LIBFT) clean
	$(RM) $(OBJS_SERVER) $(OBJS_CLIENT)

fclean: clean
	make -C $(LIBFT) fclean
	$(RM) $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re
```

### 2. 실행
```bash
# 터미널 1
./server

# 터미널 2
./client [서버PID] "전송할 메시지"
```

## 🛠 구현 가이드

### 1. 기본 구조체
```c
// 서버 구조체
typedef struct s_server
{
    int     received_bits;
    char    current_char;
    pid_t   client_pid;
} t_server;

// 클라이언트 구조체
typedef struct s_client
{
    pid_t   server_pid;
    char    *message;
    size_t  msg_len;
    size_t  current_byte;
    int     current_bit;
} t_client;
```

### 2. 시그널 핸들러
```c
// 서버 시그널 핸들러
void server_handler(int signum, siginfo_t *info, void *context)
{
    static t_server server;
    
    (void)context;
    if (!server.client_pid)
        server.client_pid = info->si_pid;
        
    if (signum == SIGUSR1)
        server.current_char |= (1 << server.received_bits);
    server.received_bits++;
    
    if (server.received_bits == 8)
    {
        ft_putchar_fd(server.current_char, 1);
        server.current_char = 0;
        server.received_bits = 0;
    }
}

// 클라이언트 시그널 핸들러
void client_handler(int signum)
{
    if (signum == SIGUSR1)
        ft_putstr_fd("Bit received by server\n", 1);
    else if (signum == SIGUSR2)
        ft_putstr_fd("Message fully received\n", 1);
}
```

### 3. 비트 단위 전송
```c
void send_char(pid_t pid, char c)
{
    int bit;
    
    bit = 0;
    while (bit < 8)
    {
        if (c & (1 << bit))
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        usleep(100);  // 시그널 안정성을 위한 대기
        bit++;
    }
}
```

## 📡 시그널 처리

### 1. 시그널 설정
```c
// sigaction 구조체 설정
void setup_signals(void)
{
    struct sigaction sa;
    
    sa.sa_sigaction = server_handler;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    
    // SIGUSR1, SIGUSR2 시그널 핸들러 등록
    if (sigaction(SIGUSR1, &sa, NULL) == -1)
        error_exit("Signal setup failed");
    if (sigaction(SIGUSR2, &sa, NULL) == -1)
        error_exit("Signal setup failed");
}
```

## 🧪 테스트 케이스

### 1. 기본 테스트
```bash
# 1. 일반 문자열 전송
./client $(./server) "Hello, World!"

# 2. 긴 문자열 전송
./client $(./server) "$(cat long_text.txt)"

# 3. 특수 문자 전송
./client $(./server) "!@#$%^&*()"

# 4. 유니코드 문자 전송
./client $(./server) "한글 테스트 🚀 emoji test"
```

### 2. 에러 케이스
```bash
# 1. 잘못된 PID
./client 99999 "test"

# 2. 빈 문자열
./client $(./server) ""

# 3. 매우 큰 데이터
./client $(./server) "$(head -c 100000 /dev/urandom)"
```

### 3. 성능 테스트
```bash
# 전송 속도 측정
time ./client $(./server) "$(cat large_file.txt)"
```

## 🔧 디버깅 가이드

### 1. 시그널 모니터링
```bash
# strace로 시그널 추적
strace -e trace=signal ./server
```

### 2. 일반적인 문제 해결
- 시그널 유실: usleep 값 조정 (100 → 200)
- 메모리 누수: valgrind 사용
- 동기화 문제: volatile 변수 사용 확인

### 3. 디버깅 매크로
```c
#ifdef DEBUG
# define DBG(x) printf("DEBUG: %s\n", x)
#else
# define DBG(x)
#endif
```

## 📚 참고 자료

### 1. 필수 문서
```c
man signal
man sigaction
man kill
man pid_t
man sigemptyset
man usleep
```

### 2. 시그널 관련 주요 함수
```c
// kill(): 프로세스에 시그널 전송
int kill(pid_t pid, int sig);

// sigaction(): 시그널 핸들러 등록
int sigaction(int signum, const struct sigaction *act, 
             struct sigaction *oldact);

// sigemptyset(): 시그널 집합 초기화
int sigemptyset(sigset_t *set);
```

### 3. 체크리스트
- [x] 서버 실행 및 PID 출력
- [x] 클라이언트-서버 간 통신
- [x] 문자열 정상 전송
- [x] 시그널 핸들링
- [x] 메모리 누수 없음
- [x] 에러 처리
- [x] 유니코드 지원 (보너스)
- [x] 전송 확인 시스템 (보너스)
