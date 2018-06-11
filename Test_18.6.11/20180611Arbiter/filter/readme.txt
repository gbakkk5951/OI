network_e.c ：全文只比较可打印字符，过滤其它所有字符

简单插件:

1. fulltext_e.c   ：全文完全直接比较，不过滤
2. slss_filterspace_e.c   ：单行单字符串比较,过滤行内空格
   slss_nofilterspace_e.c   ：单行单字符串比较,不过滤行内空格

3. slsn_int_e.c     ：单行单个数字比较, 整数
   slsn_float.c     ：单行单个数字比较,浮点数 (带有 %FLOAT_MACRO% 宏)

4. slmn_int_e.c     ：单行多个数字比较, 整数
   slmn_float.c     ：单行多个数字比较,浮点数 (带有 %FLOAT_MACRO% 宏)

高级插件:
1. mlss_filterspace_e.c   ：多行单字符串比较,过滤行内空格 
   mlss_nofilterspace_e.c   ：多行单字符串比较, 不过滤行内空格

2. mlsn_int_e.c     ：多行单个数字比较, 整数
   mlsn_float.c     ：多行单个数字比较,浮点数 (带有 %FLOAT_MACRO% 宏)

3. mlmn_int_e.c     ：多行多个数字比较, 整数
   mlmn_float.c     ：多行多个数字比较,浮点数 (带有 %FLOAT_MACRO% 宏)
