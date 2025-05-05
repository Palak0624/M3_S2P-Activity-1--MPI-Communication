#include <mpi.h>
#include <iostream>
#include <cstring>
using namespace std;
int main(int argc, char** argv) {
  MPI_Init(&argc, &argv);
  int rank;
  char msg[100];
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  if (rank == 0) {
  strcpy(msg, "Broadcast message from Master to all!");
}
MPI_Bcast(msg, 100, MPI_CHAR, 0, MPI_COMM_WORLD);
cout << "Process " << rank << " received message: " << msg << endl;
MPI_Finalize();
return 0;
}
