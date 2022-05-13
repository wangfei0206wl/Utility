NSArray与NSSet的区别

NSSet
1、无序、不重复
2、通过anyObject来访问单个元素
3、遍历NSSet中的每个元素，通过for in来遍历
4、效率高
5、内存存储不连续

NSArray
1、有序、可重复
2、有序访问
3、内存存储连续

搜索元素时，NSSet比NSArray效率高
原因：NSSet采用的是hash算法，而NSArray采用的顺序存储

NSArray
线性表数据结构

NSMutableArray使用了环形缓冲区

NSSet的实现原理
struct __CFSet {
    CFRuntimeBase _base;
    CFIndex _count;        /* number of values */
    CFIndex _capacity;        /* maximum number of values */
    CFIndex _bucketsNum;    /* number of slots */
    uintptr_t _marker;
    void *_context;        /* private */
    CFIndex _deletes;
    CFOptionFlags _xflags;      /* bits for GC */
    const void **_keys;        /* can be NULL if not allocated yet */
};
当对象被添加到NSSet时，会调用对象的hash方法来获取保存的地址，在添加时会涉及到扩容问题
描述: NSSet添加key，key值会根据特定的hash函数计算hash值，作为新对象保存的下标，如果该下标已有数据，则使用开放
定址法移动插入，若数组达到阈值，则进入扩容，重新hash插入。


NSDictionary的实现原理
struct __CFDictionary {
    CFRuntimeBase _base;
    CFIndex _count;        /* number of values */
    CFIndex _capacity;        /* maximum number of values */
    CFIndex _bucketsNum;    /* number of slots */
    uintptr_t _marker;
    void *_context;        /* private */
    CFIndex _deletes;
    CFOptionFlags _xflags;      /* bits for GC */
    const void **_keys;        /* can be NULL if not allocated yet */
    const void **_values;    /* can be NULL if not allocated yet */
};
NSDictionary的key与value是分开存储的，扩容方式同NSSet。
描述：对象存储时，key值根据特定的hash函数计算hash值，获取对应的下票，若下标已有数据，则开放定址法后移动插入，若数组达到
阈值，则进入扩容，重新hash插入。

