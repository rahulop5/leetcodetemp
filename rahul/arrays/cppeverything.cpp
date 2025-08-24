#include <bits/stdc++.h>
using namespace std;

int main() {
    // =========================
    // 1. SEQUENCE CONTAINERS
    // =========================
    cout << "\n=== ARRAY ===\n";
    array<int, 3> arr = {1, 2, 3};
    cout << "Size: " << arr.size() << "\n";
    cout << "First element: " << arr.front() << "\n";
    cout << "Last element: " << arr.back() << "\n";

    cout << "\n=== VECTOR ===\n";
    vector<int> vec = {1, 2, 3};
    vec.push_back(4); // insert at end
    vec.pop_back();   // remove last
    cout << "Element at index 1: " << vec[1] << "\n";
    cout << "Size: " << vec.size() << "\n";

    cout << "\n=== DEQUE ===\n";
    deque<int> dq = {1, 2};
    dq.push_front(0);
    dq.push_back(3);
    dq.pop_front();
    dq.pop_back();
    cout << "Size: " << dq.size() << "\n";

    cout << "\n=== LIST ===\n";
    list<int> lst = {1, 2, 3};
    lst.push_front(0);
    lst.push_back(4);
    lst.pop_front();
    lst.pop_back();
    cout << "Front: " << lst.front() << "\n";

    cout << "\n=== FORWARD_LIST ===\n";
    forward_list<int> flst = {1, 2, 3};
    flst.push_front(0);
    flst.pop_front();
    cout << "Front: " << flst.front() << "\n";

    // =========================
    // 2. ASSOCIATIVE CONTAINERS (Sorted)
    // =========================
    cout << "\n=== SET ===\n";
    set<int> s;
    s.insert(3);
    s.insert(1);
    s.insert(2);
    s.erase(2);
    cout << "Contains 1? " << (s.count(1) ? "Yes" : "No") << "\n";

    cout << "\n=== MULTISET ===\n";
    multiset<int> ms = {1, 1, 2};
    ms.insert(3);
    ms.erase(ms.find(1)); // erase one occurrence
    cout << "Count of 1: " << ms.count(1) << "\n";

    cout << "\n=== MAP ===\n";
    map<int, string> mp;
    mp[1] = "one";
    mp[2] = "two";
    mp.erase(1);
    cout << "Find key 2: " << mp[2] << "\n";

    cout << "\n=== MULTIMAP ===\n";
    multimap<int, string> mmp;
    mmp.insert({1, "one"});
    mmp.insert({1, "uno"});
    cout << "Count of key 1: " << mmp.count(1) << "\n";

    // =========================
    // 3. UNORDERED ASSOCIATIVE CONTAINERS (Hash Table)
    // =========================
    cout << "\n=== UNORDERED_SET ===\n";
    unordered_set<int> us;
    us.insert(3);
    us.insert(1);
    cout << "Contains 2? " << (us.count(2) ? "Yes" : "No") << "\n";

    cout << "\n=== UNORDERED_MAP ===\n";
    unordered_map<int, string> ump;
    ump[1] = "one";
    ump[2] = "two";
    ump.erase(2);
    cout << "Size: " << ump.size() << "\n";

    // =========================
    // 4. CONTAINER ADAPTORS
    // =========================
    cout << "\n=== STACK ===\n";
    stack<int> st;
    st.push(1);
    st.push(2);
    cout << "Top: " << st.top() << "\n";
    st.pop();

    cout << "\n=== QUEUE ===\n";
    queue<int> q;
    q.push(1);
    q.push(2);
    cout << "Front: " << q.front() << "\n";
    q.pop();

    cout << "\n=== PRIORITY_QUEUE (Max Heap) ===\n";
    priority_queue<int> pq;
    pq.push(3);
    pq.push(1);
    pq.push(2);
    cout << "Top: " << pq.top() << "\n";
    pq.pop();

    cout << "\n=== PRIORITY_QUEUE (Min Heap) ===\n";
    priority_queue<int, vector<int>, greater<int>> minpq;
    minpq.push(3);
    minpq.push(1);
    minpq.push(2);
    cout << "Top: " << minpq.top() << "\n";
    minpq.pop();

    // =========================
    // 5. OTHER USEFUL STRUCTURES
    // =========================
    cout << "\n=== PAIR ===\n";
    pair<int, string> pr = {1, "one"};
    cout << pr.first << ", " << pr.second << "\n";

    cout << "\n=== TUPLE ===\n";
    tuple<int, string, double> tp = {2, "two", 2.5};
    cout << get<0>(tp) << ", " << get<1>(tp) << ", " << get<2>(tp) << "\n";

    cout << "\n=== BITSET ===\n";
    bitset<8> bits(string("10101010"));
    cout << bits << " Count: " << bits.count() << "\n";

    cout << "\n=== STRING ===\n";
    string str = "Hello";
    str.append(" World");
    cout << str << "\n";

    // =========================
    // 6. ALGORITHMS QUICK DEMO
    // =========================
    cout << "\n=== ALGORITHMS ===\n";
    vector<int> a = {5, 2, 9, 1};
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    cout << "Max: " << *max_element(a.begin(), a.end()) << "\n";
    cout << "Min: " << *min_element(a.begin(), a.end()) << "\n";
    cout << "Find 9: " << (find(a.begin(), a.end(), 9) != a.end() ? "Yes" : "No") << "\n";

    return 0;
}
