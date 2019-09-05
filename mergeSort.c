void merge(struct record records[], char* col, int l, int m, int r)
{	
	int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    struct record L[n1];
	struct record R[n2];
	//printf("array set\n");
	//printf("n1 %i\n", n1);
	//printf("n2 %i\n", n2);
    for (i = 0; i < n1; i++)
        L[i] = records[l + i];
    for (j = 0; j < n2; j++)
        R[j] = records[m + 1+ j];
	
	////printf("test %s\n", L[0].director);
	////printf("test %s\n", R[0].director);
	
	//printf("test %i\n", sizeof(L) / sizeof(L[0]));
/* 	int g=0;
	while(g<n1){
		//printf("test %s\n", L[g].director);
		g++;
	}
	//printf("test %i\n", sizeof(R) / sizeof(R[0]));
	int y=0;
	while(y<n2){
		//printf("test %s\n", R[y].director);
		y++;
	} */
	

    i = 0;
    j = 0; 
    k = l; 
    while (i < n1 && j < n2)
    {	
		if(strcmp(col,"color")==0)
		{
			if (strcmp(L[i].color,R[j].color) <= 0)
			{
				records[k] = L[i];
				i++;
			}
			else
			{
				records[k] = R[j];
				j++;
			}
		}
		if(strcmp(col,"director_name")==0)
		{
			if (strcmp(L[i].director,R[j].director) <= 0)
			{
				records[k] = L[i];
				i++;
			}
			else
			{
				records[k] = R[j];
				j++;
			}	
		}
		if(strcmp(col,"num_critic_for_reviews")==0)
		{
			if (strcmp(L[i].numCritic,R[j].numCritic) <= 0)
			{
				records[k] = L[i];
				i++;
			}
			else
			{
				records[k] = R[j];
				j++;
			}
			
		}
		if(strcmp(col,"duration")==0)
		{
			if (strcmp(L[i].duration,R[j].duration) <= 0)
			{
				records[k] = L[i];
				i++;
			}
			else
			{
				records[k] = R[j];
				j++;
			}
			
		}
		if(strcmp(col,"director_facebook_likes")==0)
		{
			if (strcmp(L[i].fbLikes,R[j].fbLikes) <= 0)
			{
				records[k] = L[i];
				i++;
			}
			else
			{
				records[k] = R[j];
				j++;
			}
			
		}
		if(strcmp(col,"actor_3_facebook_likes")==0)
		{
			if (strcmp(L[i].a3L,R[j].a3L) <= 0)
			{
				records[k] = L[i];
				i++;
			}
			else
			{
				records[k] = R[j];
				j++;
			}
			
		}if(strcmp(col,"actor_2_name")==0)
		{
			if (strcmp(L[i].a2n,R[j].a2n) <= 0)
			{
				records[k] = L[i];
				i++;
			}
			else
			{
				records[k] = R[j];
				j++;
			}
			
		}
		if(strcmp(col,"actor_1_facebook_likes")==0)
		{
			if (strcmp(L[i].a1L,R[j].a1L) <= 0)
			{
				records[k] = L[i];
				i++;
			}
			else
			{
				records[k] = R[j];
				j++;
			}
			
		}if(strcmp(col,"gross")==0)
		{
			if (strcmp(L[i].gross,R[j].gross) <= 0)
			{
				records[k] = L[i];
				i++;
			}
			else
			{
				records[k] = R[j];
				j++;
			}
			
		}if(strcmp(col,"genres")==0)
		{
			if (strcmp(L[i].genres,R[j].genres) <= 0)
			{
				records[k] = L[i];
				i++;
			}
			else
			{
				records[k] = R[j];
				j++;
			}
			
		}
		if(strcmp(col,"actor_1_name")==0)
		{
			if (strcmp(L[i].a1n,R[j].a1n) <= 0)
			{
				records[k] = L[i];
				i++;
			}
			else
			{
				records[k] = R[j];
				j++;
			}
			
		}
		if(strcmp(col,"movie_title")==0)
		{
			if (strcmp(L[i].movietitle,R[j].movietitle) <= 0)
			{
				records[k] = L[i];
				i++;
			}
			else
			{
				records[k] = R[j];
				j++;
			}
			
		}
		if(strcmp(col,"num_voted_users")==0)
		{
			if (strcmp(L[i].numVote,R[j].numVote) <= 0)
			{
				records[k] = L[i];
				i++;
			}
			else
			{
				records[k] = R[j];
				j++;
			}
			
		}
		if(strcmp(col,"cast_total_facebook_likes")==0)
		{
			if (strcmp(L[i].castTotal,R[j].castTotal) <= 0)
			{
				records[k] = L[i];
				i++;
			}
			else
			{
				records[k] = R[j];
				j++;
			}
			
		}
		if(strcmp(col,"actor_3_name")==0)
		{
			if (strcmp(L[i].an3,R[j].an3) <= 0)
			{
				records[k] = L[i];
				i++;
			}
			else
			{
				records[k] = R[j];
				j++;
			}
			
		}
		if(strcmp(col,"facenumber_in_poster")==0)
		{
			if (strcmp(L[i].fnInPic,R[j].fnInPic) <= 0)
			{
				records[k] = L[i];
				i++;
			}
			else
			{
				records[k] = R[j];
				j++;
			}
			
		}
		if(strcmp(col,"plot_keywords")==0)
		{
			if (strcmp(L[i].plotWord,R[j].plotWord) <= 0)
			{
				records[k] = L[i];
				i++;
			}
			else
			{
				records[k] = R[j];
				j++;
			}
			
		}
		if(strcmp(col,"movie_imdb_link")==0)
		{
			if (strcmp(L[i].movieLink,R[j].movieLink) <= 0)
			{
				records[k] = L[i];
				i++;
			}
			else
			{
				records[k] = R[j];
				j++;
			}
			
		}
		if(strcmp(col,"num_user_for_reviews")==0)
		{
			if (strcmp(L[i].numUserReview,R[j].numUserReview) <= 0)
			{
				records[k] = L[i];
				i++;
			}
			else
			{
				records[k] = R[j];
				j++;
			}
			
		}
		if(strcmp(col,"language")==0)
		{
			if (strcmp(L[i].language,R[j].language) <= 0)
			{
				records[k] = L[i];
				i++;
			}
			else
			{
				records[k] = R[j];
				j++;
			}
			
		} 
		if(strcmp(col,"country")==0)
		{
			if (strcmp(L[i].country,R[j].country) <= 0)
			{
				records[k] = L[i];
				i++;
			}
			else
			{
				records[k] = R[j];
				j++;
			}
			
		} 
		if(strcmp(col,"content_rating")==0)
		{
			if (strcmp(L[i].rating,R[j].rating) <= 0)
			{
				records[k] = L[i];
				i++;
			}
			else
			{
				records[k] = R[j];
				j++;
			}
			
		} 
		if(strcmp(col,"budget")==0)
		{
			if (strcmp(L[i].budget,R[j].budget) <= 0)
			{
				records[k] = L[i];
				i++;
			}
			else
			{
				records[k] = R[j];
				j++;
			}
			
		} if(strcmp(col,"title_year")==0)
		{
			if (strcmp(L[i].titleYear,R[j].titleYear) <= 0)
			{
				records[k] = L[i];
				i++;
			}
			else
			{
				records[k] = R[j];
				j++;
			}
			
		} 
		if(strcmp(col,"actor_2_facebook_likes")==0)
		{
			if (strcmp(L[i].a2L,R[j].a2L) <= 0)
			{
				records[k] = L[i];
				i++;
			}
			else
			{
				records[k] = R[j];
				j++;
			}
			
		} 
		if(strcmp(col,"imdb_score")==0)
		{
			if (strcmp(L[i].imdbScore,R[j].imdbScore) <= 0)
			{
				records[k] = L[i];
				i++;
			}
			else
			{
				records[k] = R[j];
				j++;
			}
			
		} 
		if(strcmp(col,"aspect_ratio")==0)
		{
			if (strcmp(L[i].aspectRatio,R[j].aspectRatio) <= 0)
			{
				records[k] = L[i];
				i++;
			}
			else
			{
				records[k] = R[j];
				j++;
			}
			
		} 
		if(strcmp(col,"movie_facebook_likes")==0)
		{
			if (strcmp(L[i].MoviefbLikes,R[j].MoviefbLikes) <= 0)
			{
				records[k] = L[i];
				i++;
			}
			else
			{
				records[k] = R[j];
				j++;
			}
			
		} 
		
        k++;
    } 
	
	
    while (i < n1)
    {
        records[k] = L[i];
        i++;
        k++;
    }
    //printf("activ %i\n",k);
    while (j < n2)
    {
        records[k] = R[j];
        j++;
        k++;
    }
	/* int o=0;
	while(o<k){
		//printf("test %s\n", records[o].director);
		o++;
	} */
}
 
void mergeSort(struct record records[], char* col, int l, int r)
{   
    if (l<r)
    {
        
        int m = l+(r-l)/2;
		//printf("l %i\n", l);
		//printf("m %i\n", m);
		//printf("r %i\n", r);
		
        mergeSort(records, col, l, m);
        mergeSort(records, col, m+1, r);
 
        merge(records, col, l, m, r);
    }
}