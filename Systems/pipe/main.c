#include <stdio.h> 
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
//#define MSGSIZE 16 
//char* msg1 = "hello, world #1"; 
//char* msg2 = "hello, world #2"; 
//char* msg3 = "hello, world #3"; 
void sizeSort(){

}

void timeSort(){

}
  // CODE FROM https://www.youtube.com/watch?v=j9yL30R6npk  
  void listFiles(const char* dirname){
    
    DIR* dir = opendir(dirname);
    if(dir == NULL){
      return 1; 
    }
    
    printf("Printing files in: %s\n", dirname);
    
    struct dirent* entity; 
    struct stat attr;
    struct stat *file; 
    struct stat size; 
    stat(dirname, &attr);
    entity = readdir(dir);
    while(entity != NULL){
      stat(dirname, file);
      printf("%hhd \t%.16s\t %s\n", entity->d_type, ctime(&attr.st_mtime), entity->d_name);
      if(entity->d_type == DT_DIR && strcmp(entity->d_name, ".") != 0 && strcmp(entity->d_name, "..")){
        char path[100] = { 0 };
        strcat(path, dirname);
        strcat(path, "/"); 
        strcat(path, entity->d_name);
        listFiles(path);
      }
      entity = readdir(dir);
    }
    closedir(dir);
  }

int main(int argc, char* argv[]){
  char * file_path;
  char * sort;
  //string fileInput;
  if(argc < 2){
  listFiles(".");
  }
  else {
    file_path = argv[2];
    listFiles(file_path);
  }
  if(argc < 3){
    printf("no sort chosen.\n");
  }
  else{
    sort = argv[3];
  }
  if(sort == "-s"){
    printf("size sort chosen\n");
    sizeSort(); 
  }
  else if(sort == "-t"){
    printf("time sort chosen \n");
    timeSort(); 
  }
  /* Code from https://www.geeksforgeeks.org/pipe-system-call/
    char inbuf[MSGSIZE]; 
    int p[2], i; 
  
    if (pipe(p) < 0) 
        exit(1); 
  
    /* continued */
    /* write pipe */
  /*
    write(p[1], msg1, MSGSIZE); 
    write(p[1], msg2, MSGSIZE); 
    write(p[1], msg3, MSGSIZE); 
  
    for (i = 0; i < 3; i++) { 
         //read pipe 
        read(p[0], inbuf, MSGSIZE); 
        printf("% s\n", inbuf); 
    }
  */
  
    return 0; 
} 
