#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
typedef struct{
    char name[4];
    int age;
} people;
int main(int argc, char** argv)
{
    int shm_id,i;
    key_t key;
    people *p_map;
/*    char* name = "/dev/shm/myshm2";*/
	(void)close(open("shmseg", O_WRONLY | O_CREAT, 0));
    key = ftok("shmseg",1);
    if(key == -1)
        perror("ftok error");
    shm_id = shmget(key,4096,IPC_CREAT);    
    if(shm_id == -1)
    {
        perror("shmget error");
        return;
    }
    p_map = (people*)shmat(shm_id,NULL,0);
    for(i = 0;i<10;i++)
    {
        printf( "name:%s\n",(*(p_map+i)).name );
        printf( "age %d\n",(*(p_map+i)).age );
    }
    if(shmdt(p_map) == -1)
        perror(" detach error ");
    return 0;
}
