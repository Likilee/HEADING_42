# HEADING_42

> "Heading_42는  .c 파일들을 읽어서 함수들의 프로토타입을 파싱하여 자동으로 헤더파일을 생성해주는 프로그램 입니다."
>
> "Heading_42 is a program that reads .c files, parses the types of functions, and automatically creates a header file."

## 🚀 Usage
### Download (다운로드)
> 작업 중인 디렉토리 안에 이 저장소를 클론 합니다.
>
> "Clone this repository into your working directory."
>
> `git clone https://github.com/Likilee/HEADING_42.git`

### Setting (설정)
>- [x] `my_config.h` 파일을 수정합니다.
>- [x] 구조체를 추가하려면  `my_strcut.h` 파일을 수정합니다.

### Run (실행)
>- `bash heading42.sh`

----

## Design
### 🥊 헤더파일 구조
| Top (#ifndef HEADER_NAME_H)               |
| ---------------- |
| Includes (#include lib)   |
| Define (#define mecro)   |
| Struct (Define struct)   |
| Prototype (Get prototype from C_files) |
| Finish (#endif) |

### 🥊 기능 명세

| Program name     | Heading_42                                              |
| ---------------- | ------------------------------------------------------------ |
| Turn in files    | *.c, */*.c, *.h, */*.h, Makefile                             |
| Makefile         | all, clean, fclean, re, bonus                                |
| Description      | Write a library that contains ft_printf, a function that will mimic the real printf |

- 헤더파일에는 static을 제외한 프로토 타입만 포함되어야 한다.
- 헤더파일은 ifndef define 규칙으로 파일명을 대문자로 바꾸어 정의해야한다.
- 정해준 소스파일의 디렉토리
- 헤더파일은 42norminette 규칙에 맞게 생성해야한다.
- main 함수는 제외


### ✅ Study check list
