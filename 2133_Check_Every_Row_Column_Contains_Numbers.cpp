// My approach but chatGPT coded

class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 0; i < n; i++) {
            set<int> row, col;

            for (int j = 0; j < n; j++) {
                row.insert(matrix[i][j]); 
                col.insert(matrix[j][i]); 
            }

            if (row.size() != n || col.size() != n)
                return false;
        }

        return true;
    }
};








// Leetcode optimal solution 

class Bits
{
    unsigned long long a, b;

public:
    Bits(int n) { reset(n); }
    inline void set(int k) noexcept
    {
        if (k > 63)
        {
            k -= 64;
            b &= (~(1ULL << k));
            return;
        }
        a &= (~(1ULL << k));
    }
    inline void reset(int n) noexcept
    {
        if (n > 62)
        {
            n -= 63;
            a = ULLONG_MAX - 1;
            b = (1ULL << n) - 1;
            return;
        }

        a = (1ULL << (n + 1)) - 2;
        b = 0;
    }
    inline bool all_zeroes() noexcept { return (!a) && (!b); }
};

class Solution
{
public:
    bool checkValid(std::vector<std::vector<int>> &matrix)
    {
        int n = matrix.size();
        Bits t1(n), t2(n);

        for (int i = 0; i < n; ++i)
        {
            t1.reset(n), t2.reset(n);
            for (int j = 0; j < n; ++j)
            {
                t1.set(matrix[i][j]);
                t2.set(matrix[j][i]);
            }

            if (!(t1.all_zeroes() && t2.all_zeroes()))
                return false;
        }

        return true;
    }
};