# 0x11. C - printf

## **Requirements**
### **General**
- Allowed editors: <span color="red">vi, vim, emacs</span>
- All your files will be compiled on Ubuntu 20.04 LTS using <span color="red">gcc</span>, using the options <span color="red">-Wall -Werror -Wextra -pedantic -std=gnu89</span>
- All your files should end with a new line
- A <span color=="red">README.md</span>, at the root of the folder of the project is mandatory.
- Your code should use the <span color="red">Betty</span> sty;e. It will be checked using [betty-style.pl](https://github.com/alx-tools/Betty/blob/master/betty-style.pl) and [betty-doc.pl](https://github.com/alx-tools/Betty/blob/master/betty-doc.pl)
- You are not allowed to use global variables
- No more than 5 function per file
- In the following examples, the <span color="red">main.c</span> files are shown as examples. You can use them to test your functions, but you don't have to push them to your repo (if you do we won't take them into account). We will use our own <span color="red">main.c</span> files at compulation. Our <span color="red">main.c</span> files might be different from the one shown in the examples.
- The prototypes of all your functions should be included in your header file called <span color="red">main.h</span>
- Don't forget to push your header file
- All your header files should be include guarded
- Not that we will not provide the <span color="red">\_putchar</span> function for this project

### **Compilation**
- Your code will be compiled this way: $ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 \*.c
- As a consequence, be carefult not to push any c file containing a <span color="red">main</span> function in the root directory of your project (you could have a <span color="red">test</span> folder containing all your test files including <span color="red">main</span> functions).
- Our main files will include your main header file (<span color="red">main.h</span>):<span color="red">#include main.h</span>
- You might want to look at the gcc flag <span color="red">-Wno-format</span> when testing with your <span color="red">\_printf</span> and the standard <span color="red">printf</span>.
- We strongly encourage you to work all together on a set of tests
- If the task does not specify what to do with an edge case, do the same as <span color="red">printf</span>

### **Copyright - Plagiarism**
- You are tasked to come up with solutions for the tasks below yourself to meet with the above learning objectives.
- You will not be able to meet the objectives of this or any following project by copying and pasting someone else's work.
- You are not allowed to publish any content of this project.
- Any form of plagiarism i strictly forbidden and will result in removal from the program
