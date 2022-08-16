1、10G数据，1G内存，如何排序
    --外部排序问题、归并、最小堆（或败者数）
    处理过程:
    1)根据内存1G，数据10G，先将数据切分成10份，通过内存调用磁盘的方式，每1G进行排序，排序结束后，得到10个有序的数据数组。
    2)归并：内存开辟一个大小为10的最小堆，和一个缓冲区（小于1G，不能太小），取10份排序好的数据的首位进入最小堆，则最小堆堆顶
    为最小的数，移除堆顶元素写入缓冲区中，然后从移除元素所在的数据数组中取出下一位进入最小堆，再次移除最小堆堆顶，以此类推，直
    到缓冲区写满，将缓冲区写入磁盘并清空缓冲区，再次按上面方面将数据置入最小堆，以此类推，直到10份数据全部写完，最后将最小堆的
    元素按顺序写入磁盘缓存，即完成10G数据的排序。
    来源：https://www.jianshu.com/p/2445cd4c1233
