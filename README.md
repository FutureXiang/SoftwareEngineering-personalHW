# SoftwareEngineering-personalHW
项目功能及设计要求参见 [个人项目作业](https://edu.cnblogs.com/campus/buaa/BUAA_SE_2020_LJ/homework/10429)

## 运行
下载`bin/intersect.exe`。既可以直接运行使用标准输入输出，也可以追加以下命令行参数进行文件输入输出：
- `-i <path to input file>` （optional），重定向标准输入到文件输入
- `-o <path to output file>` （optional），重定向标准输出到文件输出

## 说明
本项目使用CLion开发，再使用Visual Studio Community 2019进行效能测试和代码分析。

为保证项目代码的跨平台性和通用性，`test/`下的单元测试文件使用[Google Test](https://github.com/google/googletest)而非VS2019自带的单元测试。
Google Test被CLion, Visual Studio等IDE兼容。
