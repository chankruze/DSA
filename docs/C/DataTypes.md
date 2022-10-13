<!--
Author: chankruze (chankruze@gmail.com)
Created: Thu Oct 13 2022 18:31:45 GMT+0530 (India Standard Time)

Copyright (c) geekofia 2022 and beyond
-->

# Storage Classes in C

Storage Classes are used to describe the features of a variable/function that include the `storage location`, `scope`, `initial value` and `life-time` which help us to trace the existence of a particular variable during the runtime of a program.

| Class     | Specifier | Location              | Scope                  | Initial Value | Life Time               |
| :-------- | :-------- | :-------------------- | :--------------------- | :------------ | :---------------------- |
| automatic | auto      | memory (stack)         | within the block       | garbage       | end of block            |
| static    | static    | memory (data segment) | within the block       | 0             | till the end of program |
| external  | extern    | memory (data segment) | global, multiple files | 0             | till the end of program |
| register  | register  | CPU resisters         | within the block       | garbage       | end of block            |
