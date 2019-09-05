multiThreadedSorter: threadSorter.c
	gcc -g -o multiThreadedSorter threadSorter.c -pthread 
clean:
	rm - rf multiThreadedSorter
