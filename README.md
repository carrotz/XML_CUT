# XML_CUT
xml cut tool


#简述

在处理数据的时候，经常拿到一些巨大的xml（10GB或更大），用java读取的时候就非常困难，所以考虑把大的cml切割成小份的。
这个写的比较早，思路很简单，按行读入，找tag，要求xml的格式规范。
功能单一也比较弱，考虑用python重新写一版更好用的ing

源码（C++）：[XML_CUT_Common](\XML_CUT_Common.cpp)


#使用说明

按照屏幕提示，依次输入：

1. Please Input Filename (without '.xml'):
   输入文件名（不包含后缀“.xml”部分）
   
2. Please Input Cut Tag (like '</***>'):
   输入切分的结束标志（格式为“</***>”，例如"</ClinVarSet>"）

3. Please Input Head Field's Row Number:   
   输入文件头部行数
   
4. Please Input End Field (like '</***>'):
   输入文件尾部内容（格式为“</***>”，例如"</ReleaseSet>"）
   
5. Please Choose Cut Way (1.by number  2.by length):
   选择切分方式（1为按照条数切，2为按照文件长度切）
   
6. Please Input Cut Number:  /  Please Input Cut length (approximate 1000000 at 1M):
   输入切割分界条数   		/   输入切割文件长度（1000000约为1M）
   
   
   
#注意：

1. 结果保存在 文件名_ByNum_res（按条数切） / 文件名_ByLen_res （按文件长度切） 当中

2. 将切割文件放在本程序同级文件夹下
