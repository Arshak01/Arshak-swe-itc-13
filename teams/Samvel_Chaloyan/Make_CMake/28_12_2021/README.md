# Homework 
## 28 Dec 2021

Complete the previous task using CMake.
Last task was:  
(Create some random subdirectories (e.g a, a->b, a->c, c->d, d->e) and Makefile in each folder,        
which creates object files for each directory and using the Makefile in the parent(a) folder          
calls the Makefiles from the subdirectories and creates the executable file.
You can use this hierarchy in some logical part of code(e.g write calculator where each file 
contains a single operation(e.g +,-,*,/), which can be class or function) and compiling them 
get the executable program. Also use HPP header files.)

Commands:  
	 cd taskCMake  
	 cd build  
	 cmake .. .  
	 make  
	 ./calc  
	 Follow to prompts.  

**Description**
*The given task is done. The executable file for calculator is made 
using object files from subdirectories with help of Cmake, shared 
libraries and so on.*

*Used sources.*
[Link1](https://www.softwaretestinghelp.com/cpp-errors/amp/?fbclid=IwAR2LiTznjCLsXWwHmMsfDr45_y7CSqeSXsZfqCwPXMM3oAx2m-_127zhIZs)
[Link2](https://cmake.org/cmake/help/latest/command/target_link_libraries.html?fbclid=IwAR1ubbIybjdJ2wWxHL0GWriz4r8YlgTfS7lR98TqQcgbUOIk9ictADdIaUE)
[Link3](https://cmake.org/cmake/help/latest/guide/tutorial/Adding%20a%20Library.html?fbclid=IwAR0pC95geVZjIwomf6vQflImOgDk_2do-JnrmWQmNLB49KDGWd3dWcSEm08)
