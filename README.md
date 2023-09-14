Project 0x16. C - Simple Shell
 

Group work

Pair name  (Feven and Finan)


Simple shell

A shell is one of the unix architecture  commands that allows users to interact with the operating system and  run commands .shell accepts human readable commands from users and converts into something which the kernel can understand.
Shell starts when the user logs in or starts the terminal.

   There are different kinds of shell to mention some of them
 
a. bourne shell /bin/sh

b. bourne -shell again /bin/bash  and so on we will focus on the second one

  How shell works

1.Displaying the prompt.
2.Reading user input (ppid ,pid).
3.praising the command meaning splitting the command into tokens.
 
4.searching for a command.
5.creating a child process.
6.Executing command (exec)to replace its own program.
7.wait for command completion.
8.displaying output.
9.returning prompt.

10.existing the shell.
 
