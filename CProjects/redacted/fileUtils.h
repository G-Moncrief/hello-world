#ifndef FILEUTILS_H
#define FILEUTILS_H

#define MAX_CHAR_COUNT 3000

//Output file open modes
#define OVERWRITE_FILE 0
#define APPEND_FILE 1

//File operation return codes
#define FILE_OK 0
#define FILE_OPEN_ERROR  -1
#define FILE_READ_ERROR  -2
#define FILE_WRITE_ERROR -3
#define FILE_WRITE_INVALID_MODE -4

/* ReadFromFile() - Reads the contents of a file into a string
 * Inputs:
 *      char* contents - String where the contents of file are store. 
 *          This string is assumed to have a maximum length of MAX_CHAR_COUNT
 *      char* filename - String containing the filename to open for reading
 *      
 * Returns an int specifying the success or failure of the operation. 
 * See return codes defined above
 */
int readFromFile(char* contents, char* filename);


/* WriteToFile() - Writes a string to a file
 * Inputs:
 *      char* contents - String to be written to a file 
 *      char* filename - String containing the filename to open for writing
 *      int mode - Specifies how to open file for write. OVERWRITE_FILE will
            cause previous writes to be deleted. APPEND_FILE will write contents
            to the end of the file, preserving previous writes.
 *      
 * Returns an int specifying the success or failure of the operation. 
 * See return codes defined above.
 */
int writeToFile(char* contents, char* filename, int mode);

#endif //FILEUTILS_H