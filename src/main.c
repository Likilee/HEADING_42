#include "../include/main.h"
#include "../include/libft.h"
#include "../my_config.h"

char 	*get_header_path(const char *name)
{
	char	*header_path;
	char	*temp;

	header_path = ft_strjoin(HEADER_PATH, "/");
	temp = header_path;
	if (temp == NULL)
		printf("%s\n", ERR_HEADER_PATH);
	header_path = ft_strjoin(header_path, name);
	free(temp);
	return (header_path);
}

int		main(void)
{
	int		fd;
	char	*header_path;
	int		yes_struct;
	int		align_point;
	int		error_check;
/*
** 헤더파일 생성 및 파일 열기
*/
	header_path = get_header_path(HEADER_NAME);
	fd = open(TEMP_H, O_RDWR | O_CREAT | O_TRUNC, 0755);
	if (fd < 0)
	{
		printf("%s\n", ERR_HEADER_PATH);
		return (0);
	}

/* TEMP_H(before align temp file) 생성 */
	put_top(fd);
	put_include(fd);
	put_define(fd);
	yes_struct = put_struct(fd);
	put_prototype(fd);
	put_finish(fd);
	close(fd);

/* 정렬 실행! - 기준 점 가져오기 */
	fd = open(TEMP_H, O_RDWR);
	align_point = find_align_point(fd);
	close(fd);
/* 이제 여기서 정렬 실행 */
	fd = open(TEMP_H, O_RDONLY);
	error_check = do_align(fd, align_point);
	close(fd);
	if (error_check == 0)
		return (0);
	remove(TEMP_H);
	if (yes_struct == 1)
		printf("%s\n", SUCCESS_YES_STRUCT);
	else
		printf("%s\n", SUCCESS_NO_STRCUT);
	return (0);
}
