# my_header

> "이 프로젝트의 목적은 .c 파일들을 읽어서 함수들의 프로토타입을 파싱하여 자동으로 헤더파일을 생성해주는 프로그램을 만드는 것입니다."
>
> "The purpose of this project is to create a program that reads .c files, parses the prototypes of functions, and automatically generates header files."

## 🚀 Content

### 🥊 Mandatory part

| Program name     | my_header                                                |
| ---------------- | ------------------------------------------------------------ |
| Turn in files    | *.c, */*.c, *.h, */*.h, Makefile                             |
| Makefile         | all, clean, fclean, re, bonus                                |
| Description      | Write a library that contains ft_printf, a function that will mimic the real printf |

- 헤더파일에는 static을 제외한 프로토 타입만 포함되어야 한다.
- 헤더파일은 ifndef define 규칙으로 파일명을 대문자로 바꾸어 정의해야한다.
- 정해준 소스파일의 디렉토리
- 헤더파일은 42norminette 규칙에 맞게 생성해야한다.
- main 함수는 제외


| Top (#ifndef 넣기)               |
| ---------------- |
| Includes (#include 라이브러리)   |
| Define (#define 부분)   |
| Prototype (C파일에서 가져온 프로토타입) |
| Finish (#endif) |

### ✅ Study check list
