#ifndef MSG_H
# define MSG_H

/*
** Error message define
*/
# define ERR_MY_STRUCT "\n\
***************************************************\n\
** ERROR ******************************************\n\
** ERR_NAME : No my_struct.h file *****************\n\
***************************************************\n\
** ERR_MSG ****************************************\n\
** 'my_struct.h' MUST BE named 'my_struct.h' ******\n\
** 'my_struct.h' MUST BE in program's root dir ****\n\
***************************************************\n"

# define ERR_HEADER_PATH "\n\
***************************************************\n\
** ERROR ******************************************\n\
** ERR_NAME : Wrong header path *******************\n\
***************************************************\n\
** ERR_MSG ****************************************\n\
** Check HEADER_PATH in 'my_config.h' *************\n\
***************************************************\n"

# define ERR_WRONG_HEADER_PATH "\n\
***************************************************\n\
** ERROR ******************************************\n\
** ERR_NAME :  Wrong *****************\n\
***************************************************\n\
** ERR_MSG ****************************************\n\
** my_struct.h file -MUST BE named 'my_struct.h' **\n\
***************************************************\n"

# define NO_C_FILES "\n\
***************************************************\n\
** ERROR ******************************************\n\
** ERR_NAME : No_c_files **************************\n\
***************************************************\n\
** ERR_MSG ****************************************\n\
** There is no c_files ****************************\n\
***************************************************\n"

# define NO_TAB "\n\
***************************************************\n\
** ERROR ******************************************\n\
** ERR_NAME : NO_TAB ******************************\n\
***************************************************\n\
** ERR_MSG ****************************************\n\
** No tab beetween data type and argument *********\n\
***************************************************\n"

/*
** Other message define
*/
# define SUCCESS_YES_STRUCT "\
***************************************************\n\
** SUCCESS ****************************************\n\
***************************************************\n\
** Your header is made : HEADER_DIR ***************\n\
** Strcuts : YES **********************************\n\
***************************************************\n"

# define SUCCESS_NO_STRCUT "\
***************************************************\n\
** SUCCESS ****************************************\n\
***************************************************\n\
** Your header is made in HEADER_DIR **************\n\
** Structs : NO ***********************************\n\
** If you need struct, write it in 'my.struct.h' **\n\
***************************************************\n"

#endif