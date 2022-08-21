# Homework
## 11 Jan 2022

**Task 1:**   
Write separate header file for vector and define vector class there  

**Description:**
*Here is implemented vector, stack, queue classes.  
The following functions are created.  
push()  
pushAtIndex()  
isEmpty()  
pop()  
topEl()  
getSize()  
displayStack()  
enQueue()  
deQueue()  
getHead()  
getTail()  

Hierarchy:  
cd classImp  
cd vector  
	vectorClass contains Vector class declaration and defination.  

Commands for creating executable file:  
into vector/  
cd build  
cmake .. .  
make  
./vectorImp*  


**Task 2:**     
Write a program to check if the provided expression has correct brackets or not.  
The brackets are correct if each opening bracket has its closing one in a correct place  
         e.g    - “{[]}({})[]” → correct  
         	- “{[}]” or “{[])” → not correct  

**Description:**  
*There ara two differet way for making executable file for the task.  
The first code is on the "bracketsCheck.cpp"  
The second way is made with CMakeLists.txt file:  
The commdans sequence:  
cd bracketsCheck  
cd build  
cmake .. .  
make*
