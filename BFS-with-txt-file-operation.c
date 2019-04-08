#include<stdio.h>
#include<conio.h>
int a[20][20], q[20], visited[20],n,i,j,f=0,r=-1;
FILE *input,*output;
void bfs(int v) {
	for (i=1;i<=n;i++)
	  if(a[v][i] && !visited[i])
	   q[++r]=i;
	if(f<=r) {
		visited[q[f]]=1;
		bfs(q[f++]);
	}
}
void main() {
	int v;
 input=fopen("BFSinput.txt","w");
 output=fopen("BFS Output.txt","w");
	printf("\n Enter the number of vertices:");
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		q[i]=0;
		visited[i]=0;
	}
	printf("\n Enter graph data in matrix form:\n");
	for (i=1;i<=n;i++)
	  for (j=1;j<=n;j++)
	   scanf("%d",&a[i][j]);

	for (i=1;i<=n;i++){
	  for (j=1;j<=n;j++)
	  {

	   fprintf(input,"%d\t",a[i][j]);

	  }
	  fprintf(input,"\n");
	}
	fclose(input);
	printf("\n Enter the starting vertex:");
	scanf("%d",&v);
	bfs(v);
	printf("\n The node which are reachable are:\n");
	fprintf(output,"\n The node which are reachable are:\n");
	for (i=1;i<=n;i++)
	  if(visited[i])
	  {

	  printf("%d\t",i);
	   fprintf(output,"%d\t",i);

	  }
   else
	  {
	      printf("\n Bfs is not possible for node %d\n",i);
	      fprintf(output,"\n Bfs is not possible for node %d\n",i);

	  }
	  fclose(output);
	getch();
	}
