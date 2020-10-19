/* .c 소스파일이 있는 경로를 "" 사이에 적어주세요
ex) "../Srcs" */
#define SRC_DIR "./Test"

/* 헤더파일을 생성할 경로를 "" 사이에 적어주세요
ex) "../Includes" */
#define HEADER_PATH "./Includes"
/* 생성할 헤더파일의 이름을 적어주세요. */
#define HEADER_NAME "heading_42.h"

/* 사용할 헤더파일들을 "" 사이에 적어주세요 공백(space)로 구분하여 적어주세요.
** 사용자 헤더파일을 적을 때 쌍따옴표앞에 역슬래시를 붙여주세요 ( " -> \") */
#define LIB "<stdio.h> \"libft.h\""
/* 사용할 매크로를 적어주세요 여러개가 있다면 ',' 로 구분해 주세요
** ex) #define MECRO "BUFFER_SIZE 32, MAX 1024" */
#define MACRO "HEADING 42"

// 소스파일이 200개 이상일 경우만 수정해주세요~
#define MAX_SOURCE_FILE 200
