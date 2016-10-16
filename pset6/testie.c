/* strstr example */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main ()
{
    const char* line = "GET /hello.php HTTP/1.1";
    
    const int firstSP = strstr(line, " ") - line + 1;
    const int secondSP = strrchr(line, ' ') - line + 1;
    int q;
    if (strrchr(line, '?') == NULL)
        q = secondSP;
    else 
        q = strrchr(line, '?') - line + 1;
    
    char* method = malloc(firstSP);
    strncpy (method, line, firstSP - 1);

    char* request_target = malloc(secondSP - firstSP);
    strncpy (request_target, &line[firstSP], secondSP - firstSP - 1);
    char* absolute_path = malloc(q - firstSP);
    strncpy (absolute_path, &line[firstSP], q - firstSP - 1);
    char* query = malloc(secondSP - q);
    if (secondSP - q > 0)
        strncpy (query, &line[q], secondSP - q - 1);
    
    char* HTTP_version = malloc(strlen(line) - secondSP + 1);
    strncpy (HTTP_version, &line[secondSP], strlen(line) - secondSP);
    
    if (strncmp(line, "GET", 3) != 0)
    {
        printf("method error\n");
    }
    
    if (strncmp(&request_target[0], "/", 1) != 0)
    {
        printf("request error\n");
    }
    
    if (strstr(&request_target[0], "\"") != NULL)
    {
        printf("request error\n");
    }
    
    if (strcmp(&HTTP_version[0], "HTTP/1.1") != 0)
    {
        printf("version error\n");
    }

}