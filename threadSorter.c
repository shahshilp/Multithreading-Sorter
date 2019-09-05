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
      
      pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
      int filebuffer = 300;
      int counter=0;
      int csvcounter=0;
      pthread_t tid[1000];
      record *gds;
      void init(){
      gds = (record*)malloc(sizeof(record) * 0);
      }
      int gdsl=0;
      
      
      struct list_dirParams {
        const char * dir_name;
        char * col;
      };
      struct makearrayParams {
        char * csv;
        char * col;
      }; 
      
      
      void mergeSort(struct record records[], char* col, int l, int r);
      void merge(struct record records[], char* col, int l, int m, int r);
      void addgarr(struct record curr[],int hi);
      //void fileoutput(char *out, char*col);
      // strtok new
      char *strtok_new(char *c, char *d) 
      { 
        static char *sc = NULL;
      	char *p;
      	int n;
        
      	if(c != NULL){
      		sc = c;
      	}
        
      	if(sc == NULL)  {
          //printf("strtok is returning null \n");
      		return(NULL);
      	}
        
        /* THIS CODE SEG FAULTS
        if (*sc == '\0'){
         return(NULL);
        }
        */
       
        //printf("inside strtok_new function with: %s \n", sc);
        
      	n = strcspn(sc,d);   
      	p = sc; 					
      	sc += n;					
        
        
        
      	if(*sc != '\0'){
      		*sc++ = '\0';
      	}
      	return(p);
      }
      
      void * sortFiles(void * params){
        
        
        
      	struct makearrayParams *readParams = (struct makearrayParams*) params;
        char * csv = readParams->csv;
        char * col = readParams->col;
        // printf("macsv: %s\n", csv);  
         //printf("macol: %s\n", col);
         //printf("\n");
       	//printf("%s \n", csv);
        
        if( strcmp(col,"color") != 0 && 
      		strcmp(col,"director_name") != 0 &&
      		strcmp(col,"num_critic_for_reviews") != 0 &&
      		strcmp(col,"duration") != 0 &&
      		strcmp(col,"director_facebook_likes") != 0 &&
      		strcmp(col,"actor_3_facebook_likes") != 0 &&
      		strcmp(col,"actor_2_name") != 0 &&
      		strcmp(col,"actor_1_facebook_likes") != 0 &&
      		strcmp(col,"gross") != 0 &&
      		strcmp(col,"genres") != 0 &&
      		strcmp(col,"actor_1_name") != 0 &&
      		strcmp(col,"movie_title") != 0 &&
      		strcmp(col,"num_voted_users") != 0 &&
      		strcmp(col,"cast_total_facebook_likes") != 0 &&
      		strcmp(col,"actor_3_name") != 0 &&
      		strcmp(col,"facenumber_in_poster") != 0 &&
      		strcmp(col,"plot_keywords") != 0 &&
      		strcmp(col,"movie_imdb_link") != 0 &&
      		strcmp(col,"num_user_for_reviews") != 0 &&
      		strcmp(col,"language") != 0 &&
      		strcmp(col,"country") != 0 &&
      		strcmp(col,"content_rating") != 0 &&
      		strcmp(col,"budget") != 0 &&
      		strcmp(col,"title_year") != 0 &&
      		strcmp(col,"actor_2_facebook_likes") != 0 &&
      		strcmp(col,"imdb_score") != 0 &&
      		strcmp(col,"aspect_ratio") != 0 &&
      		strcmp(col,"movie_facebook_likes") != 0)
      	{
      		printf("Invalid column\n");
      		return;
      	}
        
        
        
        
      	char buff[5000];
      	size_t linesize=5000;
      	char * line;
      	FILE * fd;
      	FILE * fp;
        FILE * fe;
        int size;
      	int hi = 0;
      	int c;
      
      	//record records[10000];
      	fd = fopen(csv,"r");
      	fp = fopen(csv,"r");
        fe = fopen(csv,"r"); 
        if (NULL != fe) {
          fseek (fe, 0, SEEK_END);
          size = ftell(fe);
        
          if (0 == size) {
              printf("file is empty\n");
              return;
          }
        }
        fclose(fe);
        
        
        	
      	while(EOF != getline(&line, &linesize, fd)){
       
      	hi++;
      	}
      	fclose(fd);
         
     	
        
      	//printf("HI %d \n",hi);
       
      	record* records = (record*)malloc(sizeof(record) * hi);
      	//getline(&line, &linesize, fp); //skip first
      	int a = 0;
      //printf("test \n");
      	int z=0;
      	record first;
      
      	while(z==0){
      	
       
       
      	getline(&line, &linesize, fp);
        
        size_t length = strlen(line);
        line[length-1] = '\0';
        line[length-2] = '\0';
        
      	strcpy(buff, line);
       
      	char *token = strtok_new(buff, ",");
        
        
          
      		if(token[0] == ' ')
      		{
      			token++;
      		}
      		
      	first.color = strdup(token);
      
      	token = strtok_new(NULL, ","); 
      	first.director = strdup(token);      	
       
        token = strtok_new(NULL, ",");
      	first.numCritic = strdup(token);
      
      	token = strtok_new(NULL , ",");
      	first.duration = strdup(token);
      
      	token = strtok_new(NULL, ",");
      	first.fbLikes = strdup(token);
      
      	token = strtok_new(NULL, ",");
      	first.a3L = strdup(token);
      
      	token = strtok_new(NULL, ",");
      	first.a2n = strdup(token);
      
      	token = strtok_new(NULL, ",");
      	first.a1L = strdup(token);
      
      	token = strtok_new(NULL, ",");
      	first.gross = strdup(token);
      
      	token = strtok_new(NULL, ",");
      	first.genres = strdup(token);
      
      	token = strtok_new(NULL, ",");
      	first.a1n = strdup(token);
      
      	token = strtok_new(NULL, ",");
      		if (token[0]=='"'){
      			strcat(token,strtok_new(NULL, "\""));
      			token++;
      			first.movietitle = strdup(token);
      			strtok_new(NULL, ",");
      		}
      		else
      		{
      			first.movietitle = strdup(token);
      		}
      
      	token = strtok_new(NULL, ",");
      	first.numVote = strdup(token);
      
      	token = strtok_new(NULL, ",");
      	first.castTotal = strdup(token);
      
      	token = strtok_new(NULL, ",");
      	first.an3 = strdup(token);
      
      	token = strtok_new(NULL, ",");
      	first.fnInPic = strdup(token);
      
      	token = strtok_new(NULL, ",");
      	first.plotWord = strdup(token);
      
      	token = strtok_new(NULL, ",");
      	first.movieLink = strdup(token);
      
      	token = strtok_new(NULL, ",");
      	first.numUserReview = strdup(token);
      
      	token = strtok_new(NULL, ",");
      	first.language = strdup(token);
      
      	token = strtok_new(NULL, ",");
      	first.country = strdup(token);
      
      	token = strtok_new(NULL, ",");
      	first.rating = strdup(token);
      
      	token=strtok_new(NULL, ",");
      	first.budget = strdup(token);
      
      	token=strtok_new(NULL, ",");
      	first.titleYear = strdup(token);
      
      	token=strtok_new(NULL, ",");
      	first.a2L = strdup(token);	
      
      	token=strtok_new(NULL, ",");
      	first.imdbScore = strdup(token);
      
      	token=strtok_new(NULL, ",");
      	first.aspectRatio = strdup(token);
        
        
      	token=strtok_new(NULL, ",");
        //printf("%s\n", token); //Seg fault happens here
        
      	first.MoviefbLikes = strdup(token);
      	
        
        
        
      	z++;
      	}
      	 
      	if( strcmp(first.color,"color") != 0 && 
      		strcmp(first.director,"director_name") != 0 &&
      		strcmp(first.numCritic,"num_critic_for_reviews") != 0 &&
      		strcmp(first.duration,"duration") != 0 &&
      		strcmp(first.fbLikes,"director_facebook_likes") != 0 &&
      		strcmp(first.a3L,"actor_3_facebook_likes") != 0 &&
      		strcmp(first.a2n,"actor_2_name") != 0 &&
      		strcmp(first.a1L,"actor_1_facebook_likes") != 0 &&
      		strcmp(first.gross,"gross") != 0 &&
      		strcmp(first.genres,"genres") != 0 &&
      		strcmp(first.a1n,"actor_1_name") != 0 &&
      		strcmp(first.movietitle,"movie_title") != 0 &&
      		strcmp(first.numVote,"num_voted_users") != 0 &&
      		strcmp(first.castTotal,"cast_total_facebook_likes") != 0 &&
      		strcmp(first.an3,"actor_3_name") != 0 &&
      		strcmp(first.fnInPic,"facenumber_in_poster") != 0 &&
      		strcmp(first.plotWord,"plot_keywords") != 0 &&
      		strcmp(first.movieLink,"movie_imdb_link") != 0 &&
      		strcmp(first.numUserReview,"num_user_for_reviews") != 0 &&
      		strcmp(first.language,"language") != 0 &&
      		strcmp(first.country,"country") != 0 &&
      		strcmp(first.rating,"content_rating") != 0 &&
      		strcmp(first.budget,"budget") != 0 &&
      		strcmp(first.titleYear,"title_year") != 0 &&
      		strcmp(first.a2L,"actor_2_facebook_likes") != 0 &&
      		strcmp(first.imdbScore,"imdb_score") != 0 &&
      		strcmp(first.aspectRatio,"aspect_ratio") != 0 &&
      		strcmp(first.MoviefbLikes,"movie_facebook_likes") != 0)
      	{//do nothing
      printf("Invalid csv\n");
      		return;
      	}
      
      	while((hi-1) > a){
      	getline(&line, &linesize, fp);
       
        size_t length = strlen(line);
        line[length-1] = '\0';
        line[length-2] = '\0';
        
      	strcpy(buff, line);
      		//printf(line);
      		//printf("%s",buff);
      	record curr;
      	char *token = strtok_new(buff, ",");
      
      		if(token[0] == ' ')
      		{
      			token++;
      		}
      		//printf("%s", curr.director);
      	curr.color = strdup(token);
      
      	token = strtok_new(NULL, ","); 
      	curr.director = strdup(token);
        
      	token = strtok_new(NULL, ",");
      	curr.numCritic = strdup(token);
      
      	token = strtok_new(NULL , ",");
      	curr.duration = strdup(token);
      
      	token = strtok_new(NULL, ",");
      	curr.fbLikes = strdup(token);
      
      	token = strtok_new(NULL, ",");
      	curr.a3L = strdup(token);
      
      	token = strtok_new(NULL, ",");
      	curr.a2n = strdup(token);
      
      	token = strtok_new(NULL, ",");
      	curr.a1L = strdup(token);
      
      	token = strtok_new(NULL, ",");
      	curr.gross = strdup(token);
      
      	token = strtok_new(NULL, ",");
      	curr.genres = strdup(token);
      
      	token = strtok_new(NULL, ",");
      	curr.a1n = strdup(token);
      
      	token = strtok_new(NULL, ",");
      		if (token[0]=='"'){
      			strcat(token,strtok_new(NULL, "\""));
      			token++;
      			curr.movietitle = strdup(token);
      			strtok_new(NULL, ",");
      		}
      		else
      		{
      			curr.movietitle = strdup(token);
      		}
      
      	token = strtok_new(NULL, ",");
      	curr.numVote = strdup(token);
      
      	token = strtok_new(NULL, ",");
      	curr.castTotal = strdup(token);
      
      	token = strtok_new(NULL, ",");
      	curr.an3 = strdup(token);
      
      	token = strtok_new(NULL, ",");
      	curr.fnInPic = strdup(token);
      
      	token = strtok_new(NULL, ",");
      	curr.plotWord = strdup(token);
      
      	token = strtok_new(NULL, ",");
      	curr.movieLink = strdup(token);
      
      	token = strtok_new(NULL, ",");
      	curr.numUserReview = strdup(token);
      
      	token = strtok_new(NULL, ",");
      	curr.language = strdup(token);
      
      	token = strtok_new(NULL, ",");
      	curr.country = strdup(token);
      
      	token = strtok_new(NULL, ",");
      	curr.rating = strdup(token);
      
      	token=strtok_new(NULL, ",");
      	curr.budget = strdup(token);
      
      	token=strtok_new(NULL, ",");
      	curr.titleYear = strdup(token);
      
      	token=strtok_new(NULL, ",");
      	curr.a2L = strdup(token);	
      
      	token=strtok_new(NULL, ",");
      	curr.imdbScore = strdup(token);
      
      	token=strtok_new(NULL, ",");
      	curr.aspectRatio = strdup(token);
      
      	token=strtok_new(NULL, ",");
      	curr.MoviefbLikes = strdup(token);
      		
      	records[a]=curr;
      	//printf("%s \n",records[a].movietitle);
      	a++;
      
      
      	}
      	fclose(fp);
       
      int lo = 0;
    
//        int g=0;
//      	while(g<(hi-1)){
//      		printf("test %s\n", records[g].numCritic);
//      		g++;
//      	} 
//        printf("TEST\n");
      mergeSort(records, col, lo, hi-2);
//      printf("TEST\n");
//      int k=0;
//      	while(k<(hi-1)){
//      		printf("test %s\n", records[k].numCritic);
//      		k++;
//      	} 
     //pthread_mutex_lock(&mutex);
     addgarr(records, hi-1);
     //pthread_mutex_unlock(&mutex);
         
         //add function
         
      	free(records);
      }
      void addgarr(struct record curr[],int hi){
      pthread_mutex_lock(&mutex);
      
     
       
       
        int ogdsl=gdsl;
        gdsl= gdsl+hi;
       int lo=0;
        gds = realloc(gds, sizeof(record) * gdsl);
//         printf("ogdsl %d\n",ogdsl);
          while(ogdsl!=gdsl){
        		gds[ogdsl]= curr[lo];
           lo++;
        		ogdsl++;
          }
         
//          
//          printf("gdsl %d\n",gdsl);
//          printf("hi %d\n",hi);
          pthread_mutex_unlock(&mutex);
              
//                int k=0;
//      	while(k<(gdsl)){
//      		printf("test %s\n", gds[k].numCritic);
//      		k++;
      	} 
        
     
      
      
      _Bool iscsv(char const *name)
      	{
          size_t len = strlen(name);
          return len > 4 && strcmp(name + len - 4, ".csv") == 0;
      	}
      
//      void * fakesort(void * csvpath){
//        csvcounter++;
//        printf("csv file: %d \n%s \n", csvcounter, csvpath);
//      }
      
      void * notCsvFile()
      {
        return;
      }
      
      static void * list_dir (void * params){	
      //printf("listdir \n");
      struct list_dirParams *readParams = (struct list_dirParams*) params;
      const char * dir_name = readParams->dir_name;
      char * col = readParams->col;
//      printf("1counter: %d\n", counter);
//      printf("1dir_name: %s\n", dir_name);
//      printf("1col: %s\n", col);
//      printf("\n");
      
      
      
          DIR * d;
          d = opendir (dir_name);
      
          //printf("test %s \n",dir_name);
          if (! d) {
              fprintf (stderr, "Cannot open directory '%s': %s\n",
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
			
					if(iscsv(d_name))
          {
						if(strstr(d_name, "-sorted-"))
            {
              counter++;
              err = pthread_create(&(tid[counter]),NULL, &notCsvFile,NULL);
              pthread_join(tid[counter],NULL);
            }
            else
            {
            char csvpath[filebuffer];
					  snprintf(csvpath,filebuffer,"%s/%s",dir_name,d_name);
						char *csv = csvpath;
						//char*d;
						//d = d_name;
            struct makearrayParams maparams;
                maparams.csv = csv;
                maparams.col = col;
   
            counter++;
            err = pthread_create(&(tid[counter]), NULL, &sortFiles, &maparams);
            pthread_join(tid[counter], NULL);		
            }
						
					}
          else
          {
            counter++;
            err = pthread_create(&(tid[counter]),NULL, &notCsvFile,NULL);
            pthread_join(tid[counter],NULL);
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
                    
                     struct list_dirParams ldparams;
                      ldparams.dir_name = path;
                      ldparams.col = col;
                    
//                    printf("dir_name: %s\n", dir_name);
//                    printf("subdirectory\n");
                    counter++;
                    
         				    err = pthread_create(&(tid[counter]), NULL, &list_dir, &ldparams);	
//                    printf("counter: %d\n", counter); 
//                    printf("\n"); 
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
      void fileoutput(char *out, char*col){
      //printf("TEST\n");
       //char name[300];
      //snprintf (name, 300, "%s/", out);
      //FILE * fe;
      //fe = fopen(name,"w");
      char entry[300];
      
      snprintf(entry,300,"AllFiles-sorted-<%s>.csv", col);
      //getcwd(name,sizeof(name));
      //printf("name %s\n%s",name);
      //printf("entry %s\n%s",entry);
      if(strcmp(".",out)==0){
      //chdir
      }
      else{
      chdir(out);
      }
      freopen(entry, "w", stdout);
      	printf("%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",
      			"color",
      			"director_name",
      			"num_critic_for_reviews",
      			"duration",
      			"director_facebook_likes",
      			"actor_3_facebook_likes",
      			"actor_2_name",
      			"actor_1_facebook_likes",
      			"gross",
      			"genres",
      			"actor_1_name",
      			"movie_title",
      			"num_voted_users",
      			"cast_total_facebook_likes",
      			"actor_3_name",
      			"facenumber_in_poster",
      			"plot_keywords",
      			"movie_imdb_link",
      			"num_user_for_reviews",
      			"language",
      			"country",
      			"content_rating",
            "budget",
      			"title_year",
      			"actor_2_facebook_likes",
      			"imdb_score",
      			"aspect_ratio",
      			"movie_facebook_likes"); 
      			//fwrite(entry,sizeof(entry),hi,fe);
      	 //print out
      
      
      
           int k =0;
      	 while(k < (gdsl-1)) 
      	{
      	//char entry[5000];
      	
    		  printf("%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s",
      			gds[k].color,
      			gds[k].director,  
      			gds[k].numCritic,
      			gds[k].duration,
      			gds[k].fbLikes,
      			gds[k].a3L,
      			gds[k].a2n,
      			gds[k].a1L,
      			gds[k].gross,
      			gds[k].genres,
      			gds[k].a1n,
      			gds[k].movietitle,
      			gds[k].numVote,
      			gds[k].castTotal,
      			gds[k].an3,
      			gds[k].fnInPic,
      			gds[k].plotWord,
      			gds[k].movieLink,
      			gds[k].numUserReview,
      			gds[k].language,
      			gds[k].country,
      			gds[k].rating,
      			gds[k].budget,
      			gds[k].titleYear,
      			gds[k].a2L,
      			gds[k].imdbScore,
      			gds[k].aspectRatio,
      			gds[k].MoviefbLikes);
      		//fwrite(entry,sizeof(final[k]),hi,fe);
         
         char * ret;
         
         ret=strchr(gds[k].MoviefbLikes,'\n');
         if(ret==NULL){
            printf("\n");
          }
      		k++;
      
      	}
         
      	fclose(stdout);
      //chdir(name);
      }
      //
      int main (int argc, char* argv[])
      {	//init();
        char *dir=".";
        char *col="";
        char *out=".";
        int f = 0 ;
//        printf("dir %s \n",dir);
//        printf("out %s \n",out);
//        printf("col %s \n",col);
//        printf("argc %d \n",argc);
        while(f < argc-1){
//          printf("argv %s \n",argv[f]);
          if(strcmp(argv[f],"-d")==0){
            dir = argv[f+1];
          }
          if(strcmp(argv[f],"-o")==0){
            out = argv[f+1];
          }
          if(strcmp(argv[f],"-c")==0){
            col = argv[f+1];
          }
          
        f++;
        }
//        printf("dir %s \n",dir);
//        printf("out %s \n",out);
//        printf("col %s \n",col);
        if(strcmp(col,"")==0){
          printf("Error no column input \n");
          return 0;
        }
        
        
      	//printf("argv[4] %s \n",argv[4]);
        //printf("argv[2] %s \n",argv[2]);
        //printf("out %s \n",out);
         struct list_dirParams firstldparams;
            firstldparams.dir_name = dir;
            firstldparams.col = col;
          list_dir (&firstldparams);
          printf("Initial PID: %d\n",getpid());
          printf("\n");
          printf("TIDS of all child threads: ");
          
          int j= 0;
          while(j!=counter)
          {
            j++;
            printf("%d, ",tid[j]);
            
          }
          printf("\n");
          printf("\n");
          printf("Total number of threads: %d \n",counter);
          int lo=0;
          mergeSort(gds,col,lo,gdsl-1);
//          
//                          int k=0;
////      	while(k<(gdsl)){
////      		printf("test %s\n", gds[k].numCritic);
////      		k++;}
         fileoutput(out, col);
//         
//      	return 0;
      }