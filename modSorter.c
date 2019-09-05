       #include <stdlib.h>
      #include <stdio.h>
      #include <sys/wait.h>
      #include <sys/types.h>
      #include <unistd.h>
      #include <string.h>
      #include <errno.h>
      #include<pthread.h>
      #include <dirent.h>
      
      #include <limits.h>
      #include "sorter.h"
      #include "mergeSort.c"
      int filebuffer = 300;
      int counter=0;
      int csvcounter=0;
      pthread_t tid[1000];
      
      struct readThreadParams {
        const char * dir_name;
        char * col;
        char * out;
      };
      
      _Bool iscsv(char const *name)
      	{
          size_t len = strlen(name);
          return len > 4 && strcmp(name + len - 4, ".csv") == 0;
      	}
      
      void * fakesort(void * csvpath){
        csvcounter++;
        printf("csv file: %d \n%s \n", csvcounter, csvpath);
      }
      
      static void * list_dir (void * params){	
      //printf("listdir \n");
      struct readThreadParams *readParams = (struct readThreadParams*) params;
      const char * dir_name = readParams->dir_name;
      char * col = readParams->col;
      char * out = readParams->out;
      printf("1counter: %d\n", counter);
      printf("1dir_name: %s\n", dir_name);
      printf("1col: %s\n", col);
      printf("1out: %s\n", out);
      
      
      
          DIR * d;
          d = opendir (dir_name);
      
          //printf("test %s \n",dir_name);
          if (! d) {
              fprintf (stderr, "Cannot opens directory '%s': %s\n",
                       dir_name, strerror (errno));
              exit (EXIT_FAILURE);
          }
          
      while (1) {
      //printf("while  \n");
      int err;
              struct dirent * entry;
              const char * d_name;
      	
              entry = readdir (d);
               
              
              if (! entry) {
                
                  break;
              }
              d_name = entry->d_name;
               	
              //printf("%s  \n", d_name);
              
      
			  if (! (entry->d_type & DT_DIR)) {
			
					if(iscsv(d_name)){
						
						char csvpath[filebuffer];
					snprintf(csvpath,filebuffer,"%s/%s",dir_name,d_name);
						char *csv = csvpath;
						//char*d;
						//d = d_name;
            printf("1counter: %d\n", counter);  
            printf("dir_name: %s\n", dir_name);
            printf("csv\n");
            counter++;
            err = pthread_create(&(tid[counter]), NULL, &fakesort,(void *) csvpath);
            pthread_join(tid[counter], NULL);
						//fakesort(csvpath);
						//sorter(csvpath, d, col, out);
						//exit(0);		
					}	
				}
        if (entry->d_type & DT_DIR) {
      
                  
                if (strcmp (d_name, "..") != 0 && strcmp (d_name, ".") != 0) {
                    int path_length;
                    char path[filebuffer];
                    path_length = snprintf (path, filebuffer,"%s/%s", dir_name, d_name);
                    
      							if (path_length >= filebuffer) {
      							  fprintf (stderr, "Path length has got too long.\n");
      							  exit (EXIT_FAILURE);
      							}
                    
                     struct readThreadParams readParams;
                      readParams.dir_name = path;
                      readParams.col = col;
                      readParams.out = out;
                    printf("1counter: %d\n", counter);  
                    printf("dir_name: %s\n", dir_name);
                    printf("subdirectory\n");
                    counter++;
         				    err = pthread_create(&(tid[counter]), NULL, &list_dir, &readParams);	
                    
                    pthread_join(tid[counter], NULL);
                    
    								//list_dir (path, col, out);
				        }
        }
        
			}
        //printf("final count %d \n",counter);
          if (closedir (d)) {
              fprintf (stderr, "Could not close '%s': %s\n",
              dir_name, strerror (errno));
              exit (EXIT_FAILURE);
			}
      	return 0;
      }
      //
      /*
      int main (int argc, char* argv[])
      {	char * out;
      	
      	//printf("%d", argc);
      	if(argc >= 6 ){
      	//output current directory	
      	out = argv[6];
      	}
      	else{
      	out = argv[4];
      	}
      	//printf("argv[4] %s \n",argv[4]);
        //printf("argv[2] %s \n",argv[2]);
        //printf("out %s \n",out);
         struct readThreadParams readParams;
            readParams.dir_name = argv[2];
            readParams.col = argv[4];
            readParams.out = out;
          list_dir (&readParams);
          printf("final count %d \n",counter);
      	
      	return 0;
      }
      */