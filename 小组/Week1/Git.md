# Git

## 概述

#### 开发中的实际场景

备份、代码还原、协同开发、追溯问题代码的编写人和编写时间。

#### 版本控制器的方式

##### 集中式版本控制器

版本库集中存放在中央服务器，必须联网才能工作，个人修改后提交到中央版本库。

##### 分布式版本控制工具

每个人的电脑都有一个版本库，无需联网。多人协作只需要各自的修改推给对方，就能互相看到对方的修改。

如：Git

## 常用命令

s/ll    查看当前目录

cat      查看文件内容

touch  创建文件

vi        vi编辑器

##### Git GUI: Git提供的图形界面工具

##### Git Bash: Git提供的命令行工具

## 常用操作

###  设置签名

```
git config --global user.name
git config --global user.email
```

### 初始化本地库

```
git init
```

### 查看本地库状态

```
git status
```

文件夹中没有文件

![image-20240318230322923](C:\Users\72901\AppData\Roaming\Typora\typora-user-images\image-20240318230322923.png)

文件夹中有文件，但还在工作区

![image-20240318230739878](C:\Users\72901\AppData\Roaming\Typora\typora-user-images\image-20240318230739878.png)

添加到暂存区

![image-20240318231053812](C:\Users\72901\AppData\Roaming\Typora\typora-user-images\image-20240318231053812.png)

提交本地库

![image-20240319131616314](C:\Users\72901\AppData\Roaming\Typora\typora-user-images\image-20240319131616314.png)

### 添加暂存区

```
git add 文件名
git add .//当前文件夹内所有文件添加到暂存区
```

### 删除暂存区

```
git rm --cached 文件名
```

### 提交本地库

```
git commit -m"日志信息" （文件名）
```

### 修改文件

```
vim 文件名
```

### 查看历史版本

```
git reflog//查看版本信息；读取命令历史
git log//查看版本详细信息；查看提交日志
```

### 版本穿梭

```
git reset --hard 版本号
```

## 分支

在版本控制的过程中，同时推进多个任务，为多个任务，我们可以创建每个任务的单独分支。

分支同时并行推进多个功能开发，提高开发效率。

### 分支操作

```
git branch 分支名 //创建分支
git branch -v   //查看分支
git checkout 分支名 //切换分支
git merge 分支名   //把指定分支合并到当前分支上
```

产生冲突：

合并分支时，两个分支在同一个文件的同一个位置有两套完全不同的修改，Git无法决定使用哪一个，必须人为决定新代码内容。

解决方法：

1. 把需要的留下来，其余全部删除（包括====）
2. 添加到暂存区
3. 执行提交（git commit命令时不能带文件名）

## Git团队协作机制

### 团队内协作

![image-20240320091248098](C:\Users\72901\AppData\Roaming\Typora\typora-user-images\image-20240320091248098.png)

#### 邀请加入团队

打开远程仓库->settings->manage access->invite->复制邀请函（链接）

### 跨团队协作

![image-20240320092311696](C:\Users\72901\AppData\Roaming\Typora\typora-user-images\image-20240320092311696.png)

## GitHub操作

### 推送本地分支到远程仓库

```
git push 别名 分支
```

### 拉取远程库到本地库

```
git pull 别名 分支
```

### 克隆远程仓库到本地

```
git clone 远程地址
```

克隆会做如下操作：

1.拉取代码     2.初始化本地库     3.创建别名

