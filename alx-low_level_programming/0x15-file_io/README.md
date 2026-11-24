# **0x15. C - File I/O**

### **Learning Objectives**
#### At the end of this project, you are expected to be able to <span color="red">[explain to anyone](https://savanna.alxafrica.com/rltoken/kQg2-u-cAYxh6oJz2TWHWw)</span>, **without the help of Google**:
##### **General**
###### - Look for the right source of information online
###### - How to create, open, close, read, and write files
###### - What are file descriptors
###### - What are the 3 standard file descriptors, what are their purpose and what are their <span color="red">POSIX</span> names
###### - How to use the I/O system calls <span color="red">open, close, read</span> and <span color="red">write</span>
###### - What are and how to use the flags <span color="red">O_RDONLY, O_WRONLY, O_RDWR</span>
###### - What are file permissions, and how to set them when creating a file with the <span color="red">open</span> system call
###### - What is a system call
###### - What is the difference between a function and a system call
##### **Copyright - Plagiarism**
###### - You are tasked to come up with solutions for the tasks below yourself to meet with the above learning objectives
###### - You will not be able to meet the objectives of this or any following project by copying and pasting someone else's work
###### - You are nor allowed to publish any content of this project
###### - Any form of plagiarism is strictly forbidden and will result in removal from the program

### **Requirements**
##### **General**
###### - Allowed editors: <span color="red">vi, vim, emacs</span>
###### - All your files will be compiled on Ubuntu 20.04 LTS using <span color="red">gcc</span>, using the options <span color="red">-Wall -Werror -Wextra -pedantic -std=gnu89</span>
###### - All your files should end with a new line
###### - A <span color="red">README.md</span> file, at the root of the folder of the project is mandatory.
###### - Your code should use the <span color="red">Betty</span> style. It will be checked using <span color="red">[betty-style.pl](https://github.com/alx-tools/Betty/blob/master/betty-style.pl)</span> and <span color="red">[betty-doc.pl](https://github.com/alx-tools/Betty/blob/master/betty-doc.pl)</span>
###### - You are not allowed to use global variables
###### - No more than 5 functions per file
###### - The only C standard library functions allowed are <span color="red">malloc, free</span> and <span color="red">exit</span>. Any use of functions like <span color="red">printf, puts, calloc, realloc</span> etc... is forbidden
###### Allowed syscalls: <span color="red">read, write, open, close</span>
###### - You are allowed to use <span color="red">\_putchar</span>
###### - You don't have to push <span color="red">\_putchar.c</span>, we will use our file. If you do it won't be taken into account
###### - In the following examples, the <span color="red">main.c</span> files are shown as examples. You can use them to test your functions, but you don't have to push them to your repo (if you do we won't take them into account). We will use our own <span color="red">main.c</span> files at compilation. Our <span color="red">main.c</span> files might be different from the one shown in the examples
###### - The prototypes of all your functions and the prototype of the function <span color="red">\_putchar</span> should be inlcuded in your header file called <span color="red">main.h</span>
###### - Don't forget to push your header file
###### - All your header files should be include guarded
###### - Tip: Always prefer using symbolic constants (<span color="red">POSIX</span>) vs numbers when it makes sense. For instance <span color="red">read(STDIN_FILENO, ...</span> VS <span color="red">read(0, ...</span>
