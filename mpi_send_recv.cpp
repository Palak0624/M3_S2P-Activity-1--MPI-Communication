#include <mpi.h>
#include <iostream>
#include <cstring>
using namespace std;
int main(int argc, char** argv) {
MPI_Init(&argc, &argv);
int rank, size;
char msg[100];
MPI_Comm_rank(MPI_COMM_WORLD, &rank);
MPI_Comm_size(MPI_COMM_WORLD, &size);
if (rank == 0) {
for (int i = 1; i < size; i++) {
sprintf(msg, "Hello World from Master to Process %d!", i);
MPI_Send(msg, strlen(msg)+1, MPI_CHAR, i, 0, MPI_COMM_WORLD);
}
} else {
MPI_Recv(msg, 100, MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
cout << "Process " << rank << " received message: " << msg << endl;
}
MPI_Finalize();
return 0;
}
