#include "solution.h"

using namespace std;

string Solution::minWindow(string s, string t)
{
    unordered_map<char, int> t_map;
    unordered_map<char, int> t_aim_map;
    string res = "";

    for (auto &ch : t)
    {
        if (!t_aim_map.insert(make_pair(ch, 0)).second)
        {
            t_aim_map[ch]++;
        }
    }

    for (int front = 0, back = 0, flag = 0; flag == 1 || front < s.size();)
    {
        if (flag)
        {
            if (t_map.find(s[back]) != t_map.end() && t_map[s[back]] == t_aim_map[s[back]])
            {
                string t_temp = s.substr(back, front - back + 1);
                if (res.empty() || res.size() > t_temp.size())
                {
                    res = t_temp;
                }

                if(t_map[s[back]] == 0)
                    t_map.erase(s[back]);
                else
                    t_map[s[back]]--;
                back++;
                front++;
                flag = 0;
            }
            else
            {
                if (t_map.find(s[back]) != t_map.end())
                {
                    t_map[s[back]]--;
                }
                back++;
                if (back > front)
                {
                    flag = 0;
                    front++;
                }
            }
        }
        else
        {
            if (t_aim_map.find(s[front]) != t_aim_map.end() && !t_map.insert(make_pair(s[front], 0)).second)
            {
                t_map[s[front]]++;
            }
            front++;
            if (t_map.size() == t_aim_map.size())
            {
                bool temp_flag = true;

                for (auto &t : t_aim_map)
                {
                    if (t_map[t.first] < t.second)
                    {
                        temp_flag = false;
                        break;
                    }
                }

                if (temp_flag)
                {
                    front--;
                    flag = 1;
                }
            }
        }
    }

    return res;
}
