#include<stdlib.h>
#include<mpi.h>

int main(int argc, char *argv[])
{
    char msg[3][32]={"HELLO","CSE","RVCE"};
    char buffer[32];
    int rank,size;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    if(!rank){
        for(int i=1;i<size;i++){
            MPI_Recv(buffer,32,MPI_CHAR,i,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
            printf("Process %d recieved \'%s\' from process %d\n",rank,buffer,i);
        }
    }else{
        MPI_Send(msg[(rank-1)%3],32,MPI_CHAR,0,0,MPI_COMM_WORLD);
    }
    MPI_Finalize();
    return 0;
}
