class MedianFinder {
   public:
    vector<int> v;
    priority_queue<int> pq;
    priority_queue<int, vector<int>, greater<int>> qp;

    MedianFinder() {}

    void addNum(int num) {
        if (v.size() == 0) {
            pq.push(num);
        } else if (v.size() == 1) {
            qp.push(num);
        }

        else if (qp.top() <= num) {
            qp.push(num);
        } else {
            pq.push(num);
        }
        if (pq.size() > qp.size() + 1) {
            int x = pq.top();
            pq.pop();
            qp.push(x);
        }
        if (qp.size() > pq.size() + 1) {
            int x = qp.top();
            qp.pop();
            pq.push(x);
        }
        if (!pq.empty() && !qp.empty() && pq.top() > qp.top()) {
            int a = pq.top();
            int b = qp.top();

            pq.pop();
            qp.pop();

            pq.push(b);
            qp.push(a);
        }
        v.push_back(num);
    }

    double findMedian() {
        if (v.size() == 0) return 0.0;

        if (v.size() % 2 == 0) {
            return (double)((pq.top() + qp.top()) / 2.0);
        }

        if (pq.size() > qp.size()) {
            return (double)(pq.top());
        }

        if (pq.size()) return (double)(qp.top());
    }
};
