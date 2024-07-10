#include <chrono>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;
/*
 * CUSTOM hash function which avoids collisions and hence makes unordered maps / sets faster
 */
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
#define gc getchar_unlocked
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, false, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define forv(it, a) for (auto it : a)
#define PI 3.1415926535897932384626
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)

template <class T = int>
void customPrint(const T& t)
{
    cout << t << " ";
}

template <class T = int>
void customPrint(const std::vector<T>& vec)
{
    cout << "[";
    for (auto&& i : vec)
    {
        customPrint(i);
    }
    cout << "]\n";
}

template <class T = int>
void customPrint(const std::vector<std::vector<T>>& vec)
{
    cout << "[";
    for (auto&& i : vec)
    {
        customPrint(i);
    }
    cout << "]\n";
}

template <class T = int, class U = int>
void customPrint(const std::unordered_map<T, U>& mp)
{
    cout << "[";
    for (auto& i : mp)
    {
        cout << "{" << i.first << ":";
        customPrint(i.second);
        cout << "}\n";
    }
    cout << "]\n";
}

template <class T = int, class U = int>
void customPrint(const std::map<T, U>& mp)
{
    cout << "[";
    for (auto& i : mp)
    {
        cout << "{" << i.first << ":";
        customPrint(i.second);
        cout << "}\n";
    }
    cout << "]\n";
}

template <class T = int>
void customPrint(const std::multiset<T>& mp)
{
    cout << "[";
    for (auto& i : mp)
    {
        customPrint(i);
    }
    cout << "]\n";
}

template <class T = int>
void customPrint(const std::set<T>& mp)
{
    cout << "[";
    for (auto& i : mp)
    {
        customPrint(i);
    }
    cout << "]\n";
}

template <class T = int>
void customPrint(const std::unordered_set<T>& mp)
{
    cout << "[";
    for (auto& i : mp)
    {
        customPrint(i);
    }
    cout << "]\n";
}

template <class T = int>
void customPrint(std::priority_queue<T> pq)
{
    cout << "[";
    while (!pq.empty())
    {
        customPrint(pq.top());
        pq.pop();
    }
    cout << "]\n";
}

template <class T = int>
void customPrint(std::stack<T> st)
{
    cout << "[";
    while (!st.empty())
    {
        customPrint(st.top());
        st.pop();
    }
    cout << "]\n";
}

template <class T = int>
void customPrint(std::queue<T> q)
{
    cout << "[";
    while (!q.empty())
    {
        customPrint(q.front());
        q.pop();
    }
    cout << "]\n";
}

template <class T = int>
void customPrint(std::deque<T> dq)
{
    cout << "[";
    for (auto& i : dq)
    {
        customPrint(i);
    }
    cout << "]\n";
}

template <class T = int, class U = int>
void customPrint(const std::unordered_multimap<T, U>& mp)
{
    cout << "[";
    for (auto& i : mp)
    {
        cout << "{" << i.first << ":";
        customPrint(i.second);
        cout << "}\n";
    }
    cout << "]\n";
}

template <class T = int>
void customPrint(const std::unordered_multiset<T>& mp)
{
    cout << "[";
    for (auto& i : mp)
    {
        customPrint(i);
    }
    cout << "]\n";
}
void printBitRepresentation(long long n)
{
    std::string binary = std::bitset<64>(n).to_string(); // converts to binary
    std::cout << "Binary representation: " << binary << "\n";
}
bool isPrime_sqrt(ll n)
{
    if (n == 1)
        return false;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
long long binaryExponentiation(long long base, long long exponent, long long mod)
{
    long long res = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
        {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exponent >>= 1;
    }
    return res;
}
long long getModularMultiplicativeInverse(long long num, long long mod)
{
    // multiplicative inverse only exists if num and mod are relatively prime (coprime) i.e gcd(num, mod) = 1
    //if (__gcd(num, mod) != 1)
    //{
    //    return -1;
    //}
    return binaryExponentiation(num, mod - 2, mod);
}

class TrieNode
{
private:
    struct Node
    {
        Node* links[26];
        int cntEndWith = 0;
        int cntPrefix = 0;

        bool containsKey(char ch)
        {
            return (links[ch - 'a'] != nullptr);
        }

        Node* get(char ch)
        {
            return links[ch - 'a'];
        }

        void put(char ch, Node* node)
        {
            links[ch - 'a'] = node;
        }

        void increaseEnd()
        {
            cntEndWith++;
        }

        void increasePrefix()
        {
            cntPrefix++;
        }

        void deleteEnd()
        {
            cntEndWith--;
        }

        void reducePrefix()
        {
            cntPrefix--;
        }

        int getEnd()
        {
            return cntEndWith;
        }

        int getPrefix()
        {
            return cntPrefix;
        }
    };

    Node* root;

public:
    TrieNode()
    {
        root = new Node();
    }

    void insert(std::string word)
    {
        Node* node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(std::string& word)
    {
        Node* node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
            }
            else
            {
                return 0;
            }
        }
        return node->getEnd();
    }

    int countWordsStartingWith(std::string& word)
    {
        Node* node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
            }
            else
            {
                return 0;
            }
        }
        return node->getPrefix();
    }

    void erase(std::string& word)
    {
        Node* node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
                node->reducePrefix();
            }
            else
            {
                return;
            }
        }
        node->deleteEnd();
    }
};
class DisjointSet
{
public:
    std::vector<int> rank, parent, size;
    DisjointSet(int n)
    {
        rank.resize(n + 1);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i < n + 1; i++)
        {
            parent.at(i) = i;
            size.at(i) = 1;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ultimateParentU = findUPar(u);
        int ultimateParentV = findUPar(v);
        if (ultimateParentU == ultimateParentV)
            return;
        if (rank.at(ultimateParentU) < rank.at(ultimateParentV))
        {
            parent.at(ultimateParentU) = ultimateParentV;
        }
        else if (rank.at(ultimateParentV) < rank.at(ultimateParentU))
        {
            parent.at(ultimateParentV) = ultimateParentU;
        }
        else
        {
            parent.at(ultimateParentV) = parent.at(ultimateParentU);
            rank.at(ultimateParentU)++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ultimateParentU = findUPar(u);
        int ultimateParentV = findUPar(v);
        if (ultimateParentU == ultimateParentV)
            return;
        if (size.at(ultimateParentU) < size.at(ultimateParentV))
        {
            parent.at(ultimateParentU) = ultimateParentV;
            size.at(ultimateParentV) += size.at(ultimateParentU);
        }
        else
        {
            parent.at(ultimateParentV) = ultimateParentU;
            size.at(ultimateParentU) += size.at(ultimateParentV);
        }
    }
};

class Solution
{
private:
    /*
There is a restaurant with a single chef. You are given an array customers, where customers[i] = [arrivali, timei]:

    arrivali is the arrival time of the ith customer. The arrival times are sorted in non-decreasing order.
    timei is the time needed to prepare the order of the ith customer.

When a customer arrives, he gives the chef his order, and the chef starts preparing it once he is idle. The customer waits till the chef finishes preparing his order. The chef does not prepare food for more than one customer at a time. The chef prepares food for customers in the order they were given in the input.

Return the average waiting time of all customers. Solutions within 10-5 from the actual answer are considered accepted.



Example 1:

Input: customers = [[1,2],[2,5],[4,3]]
Output: 5.00000
Explanation:
1) The first customer arrives at time 1, the chef takes his order and starts preparing it immediately at time 1, and finishes at time 3, so the waiting time of the first customer is 3 - 1 = 2.
2) The second customer arrives at time 2, the chef takes his order and starts preparing it at time 3, and finishes at time 8, so the waiting time of the second customer is 8 - 2 = 6.
3) The third customer arrives at time 4, the chef takes his order and starts preparing it at time 8, and finishes at time 11, so the waiting time of the third customer is 11 - 4 = 7.
So the average waiting time = (2 + 6 + 7) / 3 = 5.

     */
public:
    const int mod = 1e9 + 7;
    Solution()
    {
    }
    double averageWaitingTime(std::vector<std::vector<int>> customers)
    {
        // basically finding average turn around time in FCFS algorithm

        int n = customers.size();
        int timer = customers[0][0] + customers[0][1];
        std::vector<int> completionTime(n);
        completionTime[0] = customers[0][0] + customers[0][1];
        forsn(i, 1, n)
        {
            if (customers[i][0] <= timer)
            {
                timer += customers[i][1];
                completionTime[i] = timer;
            }
            else
            {
                int additionalTime = customers[i][0] - timer;
                timer += additionalTime + customers[i][1];
                completionTime[i] = timer;
            }
        }

        double turnArountTimeAverage = 0;
        forn(i, n)
        {
            turnArountTimeAverage += completionTime[i] - customers[i][0];
        }
        double answer = turnArountTimeAverage * 1.0 / n;
        return answer;
    }
};

