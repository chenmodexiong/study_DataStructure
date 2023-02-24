#define  _CRT_SECURE_NO_WARNINGS 1


//给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
//不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
//元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
//示例 1：
//输入：nums = [3, 2, 2, 3], val = 3
//输出：2, nums = [2, 2]
//示例 2：
//输入：nums = [0, 1, 2, 2, 3, 0, 4, 2], val = 2
//输出：5, nums = [0, 1, 4, 0, 3]


//int removeElement(int* nums, int numsSize, int val)
//{
//    int quick = 0;
//    int slow = 0;
//    while (quick < numsSize)
//    {
//        if (nums[quick] != val)
//        {
//            nums[slow++] = nums[quick++];
//        }
//        else
//        {
//            quick++;
//        }
//    }
//    return slow;
//}


//给你一个 升序排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，
//返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。
//由于在某些语言中不能改变数组的长度，所以必须将结果放在数组nums的第一部分。
//更规范地说，如果在删除重复项之后有 k 个元素，那么 nums 的前 k 个元素应该保存最终结果。
//将最终结果插入 nums 的前 k 个位置后返回 k 
//不要使用额外的空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
//示例 1：
//输入：nums = [1, 1, 2]
//输出：2, nums = [1, 2, _]
//解释：函数应该返回新的长度 2 ，并且原数组 nums 的前两个元素被修改为 1, 2 。
//不需要考虑数组中超出新长度后面的元素。
//示例 2：
//输入：nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]
//输出：5, nums = [0, 1, 2, 3, 4]


//int removeDuplicates(int* nums, int numsSize)
//{
//    int quick = 1;
//    int slow = 0;
//    while (quick < numsSize)
//    {
//        if (nums[quick] != nums[slow])
//        {
//            nums[++slow] = nums[quick++];
//        }
//        else
//        {
//            quick++;
//        }
//    }
//    return slow + 1;
//}

//给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，
//分别表示 nums1 和 nums2 中的元素数目。
//请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。
//注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。
//为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。
//nums2 的长度为 n 。

//示例 1：
//输入：nums1 = [1, 2, 3, 0, 0, 0], m = 3, nums2 = [2, 5, 6], n = 3
//输出：[1, 2, 2, 3, 5, 6]
//解释：需要合并[1, 2, 3] 和[2, 5, 6] 。
//合并结果是[1, 2, 2, 3, 5, 6] ，其中斜体加粗标注的为 nums1 中的元素。
//示例 2：
//输入：nums1 = [1], m = 1, nums2 = [], n = 0
//输出：[1]


void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    while (m > 0 && n > 0)
    {
        if (nums1[m - 1] >= nums2[n - 1])
        {
            nums1[m + n - 1] = nums1[m - 1];
            m--;
        }
        else
        {
            nums1[m + n - 1] = nums2[n - 1];
            n--;
        }
    }
    if (n == 0)
    {
        return;
    }
    if (m == 0)
    {
        for (int i = 0; i < n; i++)
        {
            nums1[i] = nums2[i];
        }
    }
}


