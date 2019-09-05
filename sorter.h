#include <stdio.h>
#include <stdlib.h>

typedef struct record
{
	char *color;
	char *director;
	char *numCritic;
	char *duration;
	char *fbLikes;
	char *a3L;
	char *a2n;
	char *a1L;
	char *gross;
	char *genres;
	char *a1n;
	char *movietitle;
	char *numVote;
	char *castTotal;
	char *an3;
	char *fnInPic;
	char *plotWord;
	char *movieLink;
	char *numUserReview;
	char *language;
	char *country;
	char *rating;
	char *budget;
	char *titleYear;
	char *a2L;
	char *imdbScore;
	char *aspectRatio;
	char *MoviefbLikes;

	struct record *next;
} record;

void mergeSort(struct record records[], char* col, int l, int r);
void merge(struct record records[], char* col, int l, int m, int r);