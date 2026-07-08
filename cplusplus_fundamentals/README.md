# C++ Fundamentals for Embedded
- Smart Pointers (unique_ptr, shared_ptr)
- Memory Management
- RAII Pattern
- Standard Template Library (STL) Optimization for Embedded

---

# C++学习笔记

## 1 基础部分

* sizeof 关键字 语法 sizeof(数据类型/变量)；

* float f = 3.14f，得加上一个f，不然编辑器认为是double型；

* a 对应的ASCILL编码 97；A 对应的ASCILL编码 65；

* 反斜杠\  转义字符 如 \n 换行符\t水平制表符 \输出/；

* 斜杠/    如 注释；

* 用C++风格的字符串string时要包含头文件#include <string>；

* 系统生成随机数：

* srand((unsigned int)time(NULL));//添加随机数种子 作用利用当前系统时间生成随机数，防止每次生成的随机数都一样。使用这个时得添加头文件#include <ctime>

* int num = rand()%100+1;//rand()%100表示0到99的随机数

* 对两位数以上的数字取模10能得到个位数，所有的数字除以他的位数都相当于个位数；

* 冒泡排序外层排序轮数是元素个数-1，因为是有相邻8组；内层对比次数是元素个数-轮数-1，也就是相邻元素个数-轮数；只内层交换，因为是只内层对比；

* 二维数组更推荐这种定义方式，直观
<img width="305" height="195" alt="屏幕截图 2026-06-28 164657" src="https://github.com/user-attachments/assets/8468edf0-4eaa-410a-b39f-3b6738b123b9" />

* 值传递的时候，实参是不影响的   ；地址传递的时候，实参是受影响的

<img width="1045" height="480" alt="屏幕截图 2026-06-28 170758" src="https://github.com/user-attachments/assets/805487eb-ed98-4827-96d4-9e9c8e0ca911" />

<img width="982" height="569" alt="屏幕截图 2026-06-28 224103" src="https://github.com/user-attachments/assets/415a4a22-208a-43d1-ba05-91156feb4008" />


* 指针常量 常量指针

<img width="1091" height="631" alt="屏幕截图 2026-06-28 214413" src="https://github.com/user-attachments/assets/a8086fef-f150-4752-ad01-0565c7441ea6" />

<img width="1074" height="601" alt="屏幕截图 2026-06-28 214545" src="https://github.com/user-attachments/assets/88e8a106-76b4-40e3-adb9-41f39c528e2e" />

<img width="1109" height="566" alt="屏幕截图 2026-06-28 214701" src="https://github.com/user-attachments/assets/0853c020-019b-4d68-8b21-07ad2e6c8def" />

* 静态成员（static）

* 所有对象都共享同一份数据

* 编译阶段就分配内存

* 类内声明类外初始化

* 静态成员函数

* 只能访问静态的成员变量

* 所有的对象共享同一份函数实例

* 静态成员和成员变量函数有两种访问方式：

* 对象实例化

* 直接访问类名

## 2 核心部分

* C++程序在执行时，将内存大方向划分为4个区域

* 代码区：存放函数体的二进制代码

* 全局区：存放全局变量和静态变量以及常量

* 栈区：存放函数的参数值，局部变量，由编译器自动分配释放

* 堆区：由程序员分配和释放，在C++中主要利用new在堆区开辟  int *a = new int(10);

* 引用的语法

<img width="1398" height="645" alt="e7feaec202164edc3424bd00961e6864" src="https://github.com/user-attachments/assets/f8c74253-52d9-4d65-a7e2-cd4314967819" />

* 引用的本质就是一个指针常量

<img width="1398" height="645" alt="32f84a7c4695867a2fb77a8df64dafce" src="https://github.com/user-attachments/assets/fb4675d0-eb34-4a6b-91a5-269f279cb197" />

* 函数重载：同一个作用域；函数名相同；函数参数类型或者个数或者顺利不同。提高复用性。

* 类和对象的访问权限：public protected private

<img width="995" height="148" alt="1783144094535" src="https://github.com/user-attachments/assets/389afc40-0325-496f-b337-988c63b63928" />

* 类和结构体的区别只有一点：class默认权限是私有；struct默认权限是公共。

* 构造函数的调用规则：创建一个类时，C++编译器会给每个类都添加至少四个函数

* 默认构造（空实现）：例如：Person(){}     Person(int a){}（有参构造）

* 构析函数（空实现）：例如：~Person(){}

* 拷贝函数（值拷贝）：例如：Person(const Person &p){} 

* 赋值运算符（值拷贝）：operator=

<img width="611" height="69" alt="1783238338676" src="https://github.com/user-attachments/assets/82d437af-72a9-48db-9d5c-8b7e85554cf5" />

* 深拷贝和浅拷贝：深拷贝就是在堆区new空间，进行拷贝操作，浅拷贝就是简单的赋值（系统默认的拷贝构造函数）

* 类的传统初始化和初始化列表

<img width="495" height="490" alt="1783240309904" src="https://github.com/user-attachments/assets/f09871a4-8d1d-4f9c-8604-e40d92dfaadc" />

* this指针：this指针指向被调用的成员函数所属的对象

<img width="460" height="59" alt="1783250068974" src="https://github.com/user-attachments/assets/353626f2-f61e-4137-8455-b4ad436109c0" />

* 前置递增函数返回引用；后置递增返回值。

* 继承的语法：class 子类（派生类） : 继承方式（public protected private）父类（基类） 

* 继承好处：减少重复代码

<img width="726" height="544" alt="1783408073916" src="https://github.com/user-attachments/assets/913da016-1128-415e-81f7-540207b0772e" />

* 菱形继承：虚继承（底层是虚基类指针加上相对应的偏移量）

<img width="643" height="398" alt="1783475703858" src="https://github.com/user-attachments/assets/73da0c99-be26-4a3a-898d-6136d9bcc5a9" />

<img width="998" height="500" alt="1783475643994" src="https://github.com/user-attachments/assets/5cff920f-21e7-4a2e-8441-eb83b872d57b" />

* 多态分为两类

* 静态多态：函数重载和运算符重载（地址早绑定（编译阶段））

* 动态多态：派生类和虚函数（函数前面加上virtual关键字）（地址晚绑定（运行阶段））

* 纯虚函数：virtual void func() = 0;这是语法；只要有一个纯虚函数，这个类称为抽象类。

* 抽象类的特点：

<img width="802" height="641" alt="1783498062262" src="https://github.com/user-attachments/assets/7ef98cb5-ed82-49f7-957b-5ca9a5d17dd6" />

* 无法实例化对象
