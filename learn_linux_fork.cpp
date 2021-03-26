#include <iostream>
#include <unistd.h>
#include "learn_linux_fork.h"
#include <sys/wait.h>

void simple_fork(){
    pid_t pid = fork();

    if(pid == -1){
        std::cout<< "error"<<std::endl;
        exit(-1);
    }

    if(pid == 0){
        //child process
        std::cout<<"Child pid: "<<getpid()<<std::endl;
    }

    if(pid > 0){
        //Parent process
        std::cout<<"Parent pid: "<<getpid()<<std::endl;
    }
}

void fork_with_wait(){
    pid_t pid = fork();
    int exit_status;

    if(pid == -1){
        std::cerr<<"Error when fork"<<std::endl;
        exit(-1);
    }

    if(pid == 0){
        std::cout<<"[Child]: "<<getpid()<<std::endl;
        std::cin>> exit_status;
    }
    if(pid > 0 ){
        std::cout<<"[Parent]: "<<getpid()<<std::endl;
        wait(&exit_status);
        std::cout<<"[Parent]: "<<WEXITSTATUS(exit_status)<<std::endl;
    }
};

static void sig_handler(int sig){
    int retval;
    
    if ( sig == SIGCHLD ){ 
        // 等待子程序的結束狀態
        wait(&retval);
        
        printf("CATCH SIGNAL PID=%d\n",getpid());
    }
}

void process_with_sig(){
    int exit_status;

    signal(SIGCHLD, sig_handler);

    pid_t pid = fork();

    if(pid == -1){
        std::cerr<<"Error when fork"<<std::endl;
        exit(-1);
    }

    if(pid == 0){
        std::cout<<"[Child]: "<<getpid()<<std::endl;
        std::cin>> exit_status;
    }
    if(pid > 0 ){
        std::cout<<"[Parent]: "<<getpid()<<std::endl;
        wait(&exit_status);
        std::cout<<"[Parent]: "<<WEXITSTATUS(exit_status)<<std::endl;
    }

}

int main(){
    //fork_with_wait();
    process_with_sig();
}