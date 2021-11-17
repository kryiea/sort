#include<stdio.h>
#include<string.h>



/////插入排序////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void InsrtSort(int* arry, int n) //插入排序
{
	/*时间复杂度：最坏情况下为O(N * N)，此时待排序列为逆序，或者说接近逆序
				  最好情况下为O(N)，此时待排序列为升序，或者说接近升序。
				  空间复杂度：O(1)*/

	for (int i = 0; i < n - 1; ++i)
	{
		//记录有序序列最后一个元素的下标
		int end = i;
		// 待插入的元素
		int temp = arry[end + 1];
		//单趟排
		while (end >= 0)
		{
			if (temp < arry[end]) //前一个比 待插入的数小 向后移
			{
				arry[end + 1] = arry[end];
				end--;
			}
			else//比待插入的数小，跳出循环
			{
				break;
			}
			arry[end + 1] = temp;//将 temp 插入正确的位置
		}
	}
}




/////冒泡排序////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void BubbleSort(int* arry, int n)//冒泡排序
{
	/*时间复杂度：最坏情况：O(N^2)
      	  最好情况：O(N)
				  空间复杂度：O(1) */

				  //两两对比 将大的向后移动 每趟把最大往后移动
	int cycle = n;//周期
	while (cycle) // 循环次数＞0
	{
		int flag = 0;
		for (int i = 1; i < cycle; i++) //cycle：①循环次数 ②避免再对比最后一个数值 i=1:①后一个与前一个比较 ②使周期为n-1
		{
			if (arry[i] < arry[i - 1])
			{
				int temp = arry[i];
				arry[i] = arry[i - 1];
				arry[i - 1] = temp;
			}
		}
		cycle--;//周期-1
	}
}



/////快速排序 hoare版 (左右指针法////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void swap(int* arry, int begin, int end)
{
	int temp = arry[end];
	arry[end] = arry[begin];
	arry[begin] = temp;
}
void QuickSort(int* arry, int begin, int end)//快速排序 hoare版 (左右指针法)
{
	/*     时间复杂度 O(N* log2 N)    */
	//只有一个数 或 区间不存在
	if (begin >= end) { return; }
	//区间>1
	int left = begin;
	int right = end;
	//选左1为key ,则end先走
	int keyi = begin;
	while (begin < end)
	{
		//右边选小 等号防止和key相等  防止begin 和 end 越界
		while (arry[end] >= arry[keyi] && begin < end)
		{
			end--;
		}
		//左边选大
		while (arry[begin] <= arry[keyi] && begin < end)
		{
			begin++;
		}
		//小的换在右边，大的换在左边
		swap(arry, begin, end);
	}
	swap(arry, keyi, end);//与end / begin交换都一样
	keyi = end;
	//一趟完成 : 小于 arry[keyi] 的全部移到左边，大的全部在右边

	//      [left,keyi-1]  keyi [keyi+1,right]
	//      再分别两个部分排序
	QuickSort(arry, left, keyi - 1);
	QuickSort(arry, keyi + 1, right);
}


int main()
{

	return 0;

}