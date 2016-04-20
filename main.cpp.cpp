#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
using namespace std;

void parse(char **parsed_cmd, char cstr[]){         //parse function

  char *single_cmd = strtok(cstr, " ");           //break up cstr using " " as delimiter
  int i = 0;                                      //counter
  while(single_cmd != NULL) {                     //push back tokens into array
    parsed_cmd[i] = single_cmd;
    i++;
    single_cmd = strtok(NULL, " ");
  }
  parsed_cmd[i] = NULL;                         //end array with null

  return;
}

bool execute(char **cstr){                    //execute function

  int status = 0;
  pid_t pid = fork();
  int e = 0;
  int ret = 1;

  if(pid < 0){                                 //for fork error
    perror("fork error");                        //output error
    // exit(-1);
    return false;
  }
  else if(pid == 0){
    //for child
    if (execvp(cstr[0],cstr) < 0) return false;
  }
  else
  {
    //for parent
    while (waitpid(pid,&status,0) != pid)
    ;

  }

  return true;

}


int main(){
  char token[256];
  int status = 0;
  //array to input command line
  while(true)
  {
    cout << "$ ";                           //command prompt
    cin.getline(token,256);                 //get user input

    string ex(token);                       //checks if exit
    if(ex == "exit"){
      cout << "Exiting shell" << endl;
      break;
    }
    int e = 0;
    bool ex_result;
    char **parsed = new char*[256];
    char **parsed2 = new char*[256];
    //create new array for parsed cmd

    parse(parsed,token);                    //commence parsing

    for (int i = 0; parsed[i] != NULL; i++)
    {

      if (*parsed[i] == ';'){
        ex_result = execute(parsed2);
        delete [] parsed2;
        parsed2 = new char*[256];
        e = 0;
      }
      else if (*parsed[i] == '&'){
        ex_result = execute(parsed2);
        delete [] parsed2;
        parsed2 = new char*[256];
        e = 0;
        if (!ex_result) break;
      }
      else if (*parsed[i] == '|' ){
        ex_result = execute(parsed2);
        delete [] parsed2;
        parsed2 = new char*[256];
        e = 0;
        if (ex_result) break;
      }
      else{
        parsed2[e] = parsed[i];
        e++;
        parsed2[e] = NULL;
      }
    }
    if (e > 0) execute(parsed2);  //if there's anything left in parse2 after the loop, execute it.

  }

  return 0;
}
