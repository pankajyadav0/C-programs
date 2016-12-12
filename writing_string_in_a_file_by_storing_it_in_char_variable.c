#include<stdio.h>
#include<string.h>
main()
{
FILE *Q;
char name[50000] = "diffusivity of atoms towards or away from dislcoations, interfaces, grain boundaries and free surfaces was considered. In this section, diffusion along these defects will be discussed. All of thes defects are associsated with a more open structure and it has been shown experimentally that the jump frequency for atoms migrating along these defects is higher than that for diffusion in the lattics.It will become more apparaent that under certain circumsatnces diffusion along these defects can be a dominant";

//strcpy(name,"diffusivity of atoms towards or away from dislcoations, interfaces, grain boundaries and free surfaces was considered. In this section, diffusion along these defects will be discussed. All of thes defects are associsated with a more open structure and it has been shown experimentally that the jump frequency for atoms migrating along these defects is higher than that for diffusion in the lattics.It will become more apparaent that under certain circumsatnces diffusion along these defects can be a dominant");

//strcpy(name,"Easytuts4you");
Q = fopen("pankaj.txt","w");
fputs(name,Q);
fclose(Q);
Q = fopen("pankaj.txt","r");
fgets(name,5000,Q);
printf("text is %s",name);
fclose(Q);
}
