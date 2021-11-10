/*
* 如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shu-ju-liu-zhong-de-zhong-wei-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class MedianFinder {
    struct list
    {
        int val;
        list* next;
    };
public:
    /** initialize your data structure here. */
    MedianFinder() :head_(NULL), size_(0) {

    }
    ~MedianFinder() {
        while (head_)
        {
            auto temp = head_;
            head_ = head_->next;
            delete temp;

        }
    }
    void addNum(int num) {
        ++size_;

        list* cur = new list;
        cur->val = num;
        cur->next = NULL;

        if (head_)
        {
            list* p = head_, * pre = NULL;
            while (p)
            {
                if (p->val > num)
                {
                    if (NULL == pre)
                    {
                        cur->next = head_;
                        head_ = cur;
                    }
                    else
                    {
                        cur->next = p;
                        pre->next = cur;
                    }
                    break;
                }
                
                pre = p;
                p = p->next;
            }
            if (NULL == p)
            {
                //尾部加上
                pre->next = cur;
            }
        }
        else
        {
            head_ = cur;
        }
    }

    double findMedian() {
        if (size_ == 1)
            return head_->val;

        int mind = size_ / 2-1;
        list* p = head_;
        for (int i = 0; i < mind; ++i)
            p = p->next;

        if (p)
        {
            if (size_ % 2 == 1)
                return p->next->val;
            else
                return (double(p->val) + double(p->next->val)) / 2;
        }
        return 0;
    }
private:
    list* head_;
    int size_;
};

class MedianFinder2 {

public:
    /** initialize your data structure here. */
    MedianFinder2() {

    }
    ~MedianFinder2() {

    }
    void addNum(int num) {
        datas.push_back(num);
        sort(datas.begin(), datas.end());
    }

    double findMedian() {
        if (datas.size() <= 1)
            return datas[0];

        int index = datas.size() / 2 - 1;
        if (datas.size() % 2 == 1)//奇数
        {
            return datas[index + 1];
        }
        else
        {
            return (double(datas[index ]) / 2 + double(datas[index + 1]) / 2);
        }
    }
private:
    vector<int>datas;
};
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
int main(int argc, char* argv[])
{
    MedianFinder* obj = new MedianFinder();
    obj->addNum(1);
    obj->addNum(2);
    printf("ret=%lf\n", obj->findMedian());
    obj->addNum(3);
    printf("ret=%lf\n", obj->findMedian());
    delete obj;
    return 0;

}